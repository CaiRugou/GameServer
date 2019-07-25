#include "mission_manager.h"
#include <game_service/player/player.h>
#include <game_service/player/player_manager.h>
#include <server_share/time_value/time_value.h>

GSE_NAMESPACE_BEGIN_DECL

void CMissionManager::UpdateMission( ROLE_ID RoleID , MISSION_ID MissionID )
{
    this->UpdateMission( RoleID , MissionID , 1 );
}

void CMissionManager::UpdateMission( ROLE_ID RoleID , MISSION_ID MissionID , uint32 MissionCount )
{
    CPlayerPtr PlayerPtr = PlayerManager.GetPlayer( RoleID );
    if ( nullptr == PlayerPtr ) { return; }
    CJsonMissionCell* pMissionCell = JsonMissionConfig.GetJsonCell< CJsonMissionCell >( MissionID );
    if ( NULL == pMissionCell ) { return; }

    /// ����Ƿ���Ч����;
    if ( IsInValidMission( MissionID ) ) { return; }
    /// �����Ƿ����;
    if ( IsDoneMission( RoleID , MissionID) )     { return; }
    /// ����������Ϣ;
    this->ResetMissionInfo( RoleID , MissionID );

    /// ˢ��������Ϣ;
    CRecordMission* pRecordMission = GetMissionInfo( RoleID , MissionID , true );
    if ( nullptr == pRecordMission ) { return; }
    pRecordMission->SetMissionTarGet( pRecordMission->GetMissionTarGet() + MissionCount );

    /// ��������Ƿ����;

    pRecordMission->SaveDB();
}

void CMissionManager::ResetMissionInfo( ROLE_ID RoleID , MISSION_ID MissionID )
{
    CPlayerPtr PlayerPtr = PlayerManager.GetPlayer( RoleID );
    if ( nullptr == PlayerPtr )    { return; }
    CJsonMissionCell* pMissionCell = JsonMissionConfig.GetJsonCell< CJsonMissionCell >( MissionID );
    if ( nullptr == pMissionCell ) { return; }

    /// �Ƿ�ÿ����������;
    if ( !pMissionCell->GetMissionIsDayRefresh() ) { return; }

    /// ����������Ϣ;
    CRecordMission* pRecordMission = GetMissionInfo( RoleID , MissionID );
    if ( nullptr == pRecordMission ) { return; }

    /// ����Ƿ����;
    uint32 Time = NLMISC::CTime::getSecondsSince1970();
    CTimeValue LastTime( pRecordMission->GetMissionReceiveTime() );
    CTimeValue CurrTime( Time );
    if ( !IsSameDay( LastTime , CurrTime ) ) { return; }

    /// �������ݿ�;
    pRecordMission->SetUpdate();
    pRecordMission->SetMissionTarGet( 0 );
    pRecordMission->SetMissionReceiveTime( Time );
    pRecordMission->SetMissionState( MISSION_STATE_ACCEPT );
    pRecordMission->SaveDB();
}

bool CMissionManager::IsInValidMission( MISSION_ID MissionID )
{
    CJsonMissionCell* pMissionCell = JsonMissionConfig.GetJsonCell< CJsonMissionCell >( MissionID );
    if ( NULL == pMissionCell )
        return true;

    // �������ʱ��;
    uint32 CurrTime = NLMISC::CTime::getSecondsSince1970();
    if ( CurrTime < pMissionCell->GetMissionStartTime() ) return true;
    if ( CurrTime > pMissionCell->GetMissionEndTime()   ) return true;
    return false;
}

bool CMissionManager::IsDoneMission( ROLE_ID RoleID , MISSION_ID MissionID )
{
    CPlayerPtr PlayerPtr = PlayerManager.GetPlayer( RoleID );
    if ( nullptr == PlayerPtr )      { return false; }
    CRecordMission* pRecordMission = GetMissionInfo( RoleID , MissionID );
    if ( nullptr == pRecordMission ) { return false; }

    /// �������״̬�Ƿ����;
    if ( pRecordMission->GetMissionState() == MISSION_STATE_DONE ) { return true; }
    return false;
}

CRecordMission* CMissionManager::GetMissionInfo( ROLE_ID RoleID , MISSION_ID MissionID , bool IsAdd )
{
    CPlayerPtr PlayerPtr = PlayerManager.GetPlayer( RoleID );
    if ( nullptr == PlayerPtr ) { return nullptr; }

    TRecordMission& TRecordData = PlayerPtr->GetRecordPlayer().GetRecordMission();
    auto It = TRecordData.find( MissionID );
    if ( It != TRecordData.end() )
    {
        It->second.SetUpdate();
        return &It->second;
    }

    if ( !IsAdd ) return nullptr;
    CRecordMission MissionData;
    MissionData.SetInsert();
    MissionData.SetRoleID( RoleID );
    MissionData.SetMissionID( MissionID );
    auto Res = TRecordData.insert( std::make_pair(MissionID , MissionData) );
    return &Res.first->second;
}

GSE_NAMESPACE_END_DECL
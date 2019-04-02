#include "room_base.h"
#include "room_timer.h"
#include <game_service/player/player.h>
#include <game_service/player/player_manager.h>
#include <game_service/event/event_define.h>

GSE_NAMESPACE_BEGIN_DECL

CRoomBase::CRoomBase( TCtorParam& CreateRoomData , uint32 FrameMoveTime ) : m_FrameMoveTime( 0 )
                                                                          , m_GameStart( false )
                                                                          , m_RoomName( "" )
                                                                          , m_RoomID( 0 )
                                                                          , m_OwnerID( 0 )
{
    CJsonRoomCell* pRoomCell = JsonRoomConfig.GetJsonCell< CJsonRoomCell >( CreateRoomData.room_name() );
    if ( NULL == pRoomCell )
        return;

    m_CreateRoomData = CreateRoomData;
    m_RoomID         = CreateRoomData.room_id();
    m_FrameMoveTime  = FrameMoveTime;
    m_RoomName       = pRoomCell->GetRoomName();
    m_RoomPlayer.clear();
    m_RoomPlayer.resize( pRoomCell->GetRoomMin() );
    m_FrameMoveTimer.setRemaining( m_FrameMoveTime , new CRoomFrameMoveTimer(this) );
}

CRoomBase::~CRoomBase( void )
{
    EventDefine.EventDeleteRoom( m_RoomID , m_RoomPlayer );
    ROOM_PLAYER_TABLE::iterator it = m_RoomPlayer.begin();
    for ( ; it != m_RoomPlayer.end(); ++it )
    {
        LeaveGameRoom( *it );
    }
}

bool CRoomBase::JoinGameRoom( ROLE_ID RoleID )
{
    // �Ƿ���Խ���;
    if ( IsRoomFull() )            return false;
    if ( IsRoomRole( RoleID ) )    return false;

    // ������;
    if ( AddRoomPlayer( RoleID ) ) return false;
    // �����¼�;
    EventDefine.EventJoinRoom( RoleID , GetRoomID() );

    return true;
}

void CRoomBase::LeaveGameRoom( ROLE_ID RoleID )
{
    // �Ƿ�����뿪;
    if ( !IsRoomRole( RoleID ) )    return;

    // �뿪����;
    PB_LeaveRoom PBLeaveRoom;
    PBLeaveRoom.set_role_id( RoleID );
    RoomBroadCasts( "MSG_LEAVE_ROOM" , &PBLeaveRoom );

    // ɾ�����;
    if ( !DelRoomPlayer( RoleID ) ) return;
    // �����¼�;
    EventDefine.EventLeaveRoom( RoleID , GetRoomID() );
}

void CRoomBase::GameStart( void )
{
    // �����¼�;
    EventDefine.EventGameStart( GetRoomID() );
}

void CRoomBase::GameOwer( void )
{
    // �����¼�;
    EventDefine.EventGameOwer( GetRoomID() );
}

bool CRoomBase::IsRoomFull( void )
{
    CJsonRoomCell* pRoomCell = JsonRoomConfig.GetJsonCell< CJsonRoomCell >( m_CreateRoomData.room_name() );
    if ( NULL == pRoomCell ) return true;
    return ( GetPlayerCount() >= pRoomCell->GetRoomMin() );
}

void CRoomBase::UserOffline( ROLE_ID RoleID )
{
    PB_UserOffline PBUserOffline;
    PBUserOffline.set_role_id( RoleID );
    RoomBroadCasts( "MSG_USER_OFFLINE" , &PBUserOffline );
}

void CRoomBase::UserOnline( ROLE_ID RoleID )
{
    PB_UserOnline PBUserOnline;
    PBUserOnline.set_role_id( RoleID );
    RoomBroadCasts( "MSG_USER_ONLINE" , &PBUserOnline );
}

void CRoomBase::RoomBroadCasts( NLMISC::CSString MessageName , google::protobuf::Message* pMessage , ROLE_ID RoleID )
{
    for ( ROOM_PLAYER_TABLE::iterator it = m_RoomPlayer.begin() ; it != m_RoomPlayer.end(); ++it )
    {
        if ( *it == RoleID ) { continue; }
        CPlayer* pPlayer = PlayerManager.GetPlayer( *it );
        if ( NULL == pPlayer ) { continue; }
        NLNET::TServiceId FroentendServiceId = pPlayer->GetFrontendServiceId();
        SendToClient( *it , FroentendServiceId , MessageName , pMessage );
    }
}

bool CRoomBase::IsRoomRole( ROLE_ID RoleID )
{
    for ( ROOM_PLAYER_TABLE::iterator it = m_RoomPlayer.begin(); it != m_RoomPlayer.end(); ++it )
    {
        if ( *it != RoleID ){ continue; }
        return true;
    }
    return false;
}

bool CRoomBase::AddRoomPlayer( ROLE_ID RoleID )
{
    for ( ROOM_PLAYER_TABLE::iterator it = m_RoomPlayer.begin(); it != m_RoomPlayer.end(); ++it )
    {
        if ( *it > 0 ) { continue; }
        *it = RoleID;
        return true;
    }
    return false;
}

bool CRoomBase::DelRoomPlayer( ROLE_ID RoleID )
{
    for ( ROOM_PLAYER_TABLE::iterator it = m_RoomPlayer.begin(); it != m_RoomPlayer.end(); ++it )
    {
        if ( *it != RoleID ) { continue; }
        *it = 0;
        return true;
    }
    return false;
}

uint32 CRoomBase::GetPlayerCount( void )
{
    sint32 Count = 0;
    for ( ROOM_PLAYER_TABLE::iterator it = m_RoomPlayer.begin(); it != m_RoomPlayer.end(); ++it )
    {
        if ( *it <= 0 ) { continue; }
        Count++;
    }
    return Count;
}


GSE_NAMESPACE_END_DECL
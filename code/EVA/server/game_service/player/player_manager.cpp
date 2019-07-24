#include "player_manager.h"

GSE_NAMESPACE_BEGIN_DECL

CPlayerManager::CPlayerManager( void )
{
    m_PlayerTable.clear();
}

CPlayerManager::~CPlayerManager( void )
{
    m_PlayerTable.clear();
}

CPlayerPtr CPlayerManager::AllocPlayer( CRecordPlayer& RecordPlayer )
{
    CPlayerPtr PlayerPtr = AllocPlayer( RecordPlayer.GetRecordBasePlayer().GetRoleID() );
    if ( nullptr == PlayerPtr ) {
        return nullptr;
    }
    PlayerPtr->SetRecordPlayer( RecordPlayer );
    return PlayerPtr;
}

CPlayerPtr CPlayerManager::AllocPlayer( ROLE_ID RoleID )
{
    CPlayerPtr PlayerPtr = std::make_shared< CPlayer >();
    if ( nullptr == PlayerPtr ) {
        return nullptr;
    }
    auto res = m_PlayerTable.insert( std::make_pair( RoleID , PlayerPtr ) );
    return res.first->second;
}

CPlayerPtr CPlayerManager::GetPlayer( ROLE_ID RoleID )
{
    auto It = m_PlayerTable.find( RoleID );
    if ( It == m_PlayerTable.end() ) {
        return nullptr;
    }
    return It->second;
}

void CPlayerManager::DeletePlayer( ROLE_ID RoleID )
{
    auto It = m_PlayerTable.find( RoleID );
    if ( It == m_PlayerTable.end() ) {
        return;
    }
    m_PlayerTable.erase( It );
}

bool CPlayerManager::ChangeScenes( ROLE_ID RoleID , TServiceId& ServiceID )
{
    CPlayerPtr PlayerPtr = this->GetPlayer( RoleID );
    if ( nullptr == PlayerPtr ) {
        return false;
    }

    /// ���Ŀ������Ƿ�����;
    if ( !SS_NETWORK->isConnectionConnected( ServiceID ) ) {
        return false;
    }

    /// ����Ͷ�ݵ�Ŀ�������;
    NLNET::CMessage SendMessage( "MSG_CHANGE_SCENES" );
    SendMessage.serial( *PlayerPtr );
    SS_NETWORK->send  ( ServiceID , SendMessage );

    /// ɾ���������;
    this->DeletePlayer( RoleID );
    return true;
}

GSE_NAMESPACE_END_DECL
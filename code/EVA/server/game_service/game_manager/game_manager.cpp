#include "game_manager.h"
#include <game_service/player/player.h>
#include <game_service/player/player_manager.h>
#include <game_service/game_manager/game_register.h>

GSE_NAMESPACE_BEGIN_DECL

bool CGameManager::CreateGame( ROLE_ID RoleID , PB_CreateGame& GameData )
{
    CPlayerPtr PlayerPtr = PlayerManager.GetPlayer( RoleID );
    if ( nullptr == PlayerPtr ) {
        return false;
    }

    /// �����Ϸ��̬����;
    CJsonGameCell* pGameCell = JsonGameConfig.GetJsonCell< CJsonGameCell >( GameData.game_name() );
    if ( nullptr == pGameCell ) {
        return false;
    }

    /// �����ת������;
    if( CreateGame2Scenes( RoleID , GameData ) ) {
        return true;
    }

    /// ������Ϸʵ��;
    CGameBasePtr GameBasePtr( NLMISC_GET_FACTORY( CGameBase , NLMISC::CSString ).createObject( pGameCell->GetGameName() , GameData ) );
    if ( nullptr == GameBasePtr ) {
        return false;
    }

    /// ������Ϸʵ��;
    auto Res = m_GameList.insert( std::make_pair( GameData.game_id() , GameBasePtr ));
    if ( !Res.second ) {
        return false;
    }

    /// ������Ϸ;
    GameBasePtr->SetOwnerID( RoleID );
    GameBasePtr->GameJoin( RoleID );

    /// ������Ϸ����;
    GameRegister.UpdateGameInfo( GameData.game_name() , 1 );
    return true;
}

bool CGameManager::CreateGame2Scenes( ROLE_ID RoleID , PB_CreateGame& GameData )
{
    /// ����Ƿ���Ҫ�з�����;
    uint16 LocalServiceID = NLNET::IService::getInstance()->getServiceId().get();
    if ( LocalServiceID == GameData.service_id() ) {
        return false;
    }

    /// Ŀ��������Ƿ��������;
    if ( !SS_NETWORK->isConnectionConnected( TServiceId( GameData.service_id() ))) {
        return true;
    }

    bool Res = false;
    Res = PlayerManager.ChangeScenes( RoleID , TServiceId( GameData.service_id() ));
    if ( !Res ) return true;

    /// ͬ����Ϸ����;
    CMessage SendMessage( "MSG_CREATE_ROOM" );
    SendMessage.serial( RoleID );
    SendMessage.serial( &GameData );
    SS_NETWORK->send( TServiceId( GameData.service_id()) , SendMessage );
    return true;
}

bool CGameManager::JoinGame( ROLE_ID RoleID , ROOM_ID RoomID )
{
    CGameBasePtr GameBasePtr = GetGameBasePtr( RoomID );
    if ( nullptr == GameBasePtr ) { return false; }

    /// ������Ϸ;
    return GameBasePtr->GameJoin( RoleID );
}

bool CGameManager::LeaveGame( ROLE_ID RoleID )
{
    CPlayerPtr PlayerPtr = PlayerManager.GetPlayer( RoleID );
    if ( nullptr == PlayerPtr )   { return false; }
    CGameBasePtr GameBasePtr = GetGameBasePtr( PlayerPtr->GetRoomID() );
    if ( nullptr == GameBasePtr ) { return false; }

    /// �뿪��Ϸ;
    return GameBasePtr->GameLeave( RoleID );
}

bool CGameManager::DeleteGame( ROOM_ID RoomID )
{
    auto It = m_GameList.find( RoomID );
    if ( It == m_GameList.end() ) { return false; }

    /// ������Ϸ����;
    NLMISC::CSString GameName = (*It->second).GetCreateGameData().game_name();
    GameRegister.UpdateGameInfo( GameName , -1 );

    /// ɾ����Ϸʵ��;
    m_GameList.erase( It );
    return true;
}

CGameBasePtr CGameManager::GetGameBasePtr( ROOM_ID RoomID )
{
    auto It = m_GameList.find( RoomID );
    if ( It == m_GameList.end() ) { return nullptr; }
    return It->second;
}

GSE_NAMESPACE_END_DECL
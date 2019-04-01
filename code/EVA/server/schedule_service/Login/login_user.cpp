#include "login_user.h"
#include <schedule_service/player/player.h>
#include <schedule_service/player/player_manager.h>
#include <schedule_service/room/room_manager.h>

SSE_NAMESPACE_BEGIN_DECL

void CLoginUser::CallBackUserLogin( NLNET::CMessage& Message )
{
    PB_UserLogin UserLogin;
    Message.serial( &UserLogin );

    // �ڴ��¼;
    if ( this->UserLoginMemory( UserLogin ) )   return;
    // ���ݿ��¼;
    if ( this->UserLoginDBCache( UserLogin ) )  return;

    // ��ӡ��־;
    nlinfo( " user login fail %d" , UserLogin.role_id() );
}

void CLoginUser::CallBackUserLoginSucceed( NLNET::CMessage& Message )
{
    ROLE_ID RoleID = 0;
    NLNET::TServiceId GameServiceId     = NLNET::TServiceId::InvalidId;
    NLNET::TServiceId FrontendServiceId = NLNET::TServiceId::InvalidId;
    Message.serial( RoleID );
    Message.serial( GameServiceId );
    Message.serial( FrontendServiceId );

    CPlayer* pPlayer = PlayerManager.GetPlayer( RoleID );
    if ( NULL == pPlayer ) return;
    pPlayer->SetFrontendServiceId( FrontendServiceId );
    pPlayer->SetGameServiceId( GameServiceId );
}

bool CLoginUser::UserLoginMemory( PB_UserLogin& UserLogin )
{
    CPlayer* pPlayer = PlayerManager.AllocPlayer( UserLogin.role_id() );
    if ( NULL == pPlayer )
        return false;

    // �鿴����״̬;
    if ( pPlayer->GetFrontendServiceId() == NLNET::TServiceId::InvalidId )  return false;
    if ( pPlayer->GetGameServiceId()     == NLNET::TServiceId::InvalidId )  return false;

    // ͬ���߼�����������;
    NLNET::CMessage SendMessage("MSG_LOGIN");
    SendMessage.serial( &UserLogin );
    return SS_NETWORK->send( pPlayer->GetGameServiceId() , SendMessage );
}

bool CLoginUser::UserLoginDBCache( PB_UserLogin& UserLogin )
{
    CPlayer* pPlayer = PlayerManager.AllocPlayer( UserLogin.role_id() );
    if ( NULL == pPlayer ) return false;

    // ������Ϸ������ID;
    NLNET::TServiceId GameServiceId = RoomManager.GetLoginGamaService();
    if ( GameServiceId == NLNET::TServiceId::InvalidId )
        return false;

    UserLogin.set_game_service_id( GameServiceId.get() );
    NLNET::CMessage SendMessage("MSG_LOGIN");
    SendMessage.serial( &UserLogin );
    return SS_NETWORK->send( "PSE" , SendMessage );
}

SSE_NAMESPACE_END_DECL
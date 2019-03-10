#include "login_user.h"
#include "../player/player.h"
#include "../player/player_manager.h"

SSE_NAMESPACE_BEGIN_DECL

void CLoginUser::UserLoginCallBack( NLNET::CMessage& Message )
{
    PB_UserLogin UserLogin;
    Message.serial( &UserLogin );

    // �ڴ��¼;
    if ( this->UserLoginMemory( UserLogin ) )  return;
    // ���ݿ��¼;
    if ( this->UserLoginDBCache( UserLogin ) ) return;
    // ��ӡ��־;
    nlinfo( " user login fail %d" , UserLogin.role_id() );
}

bool CLoginUser::UserLoginMemory( PB_UserLogin& UserLogin )
{
    CPlayer* pPlayer = PlayerManager.AllocPlayer( UserLogin.role_id() );
    if ( NULL == pPlayer ) return false;

    // �鿴����״̬;
    if ( pPlayer->GetFesServiceID() == NLNET::TServiceId::InvalidId ) return false;
    if ( pPlayer->GetPlsServiceID() == NLNET::TServiceId::InvalidId ) return false;

    // ͬ���߼�����������;
    NLNET::CMessage SendMessage;
    SendMessage.serial( &UserLogin );
    return SS_NETWORK->send( pPlayer->GetPlsServiceID() , SendMessage );
}

bool CLoginUser::UserLoginDBCache( PB_UserLogin& UserLogin )
{
    CPlayer* pPlayer = PlayerManager.AllocPlayer( UserLogin.role_id() );
    if ( NULL == pPlayer ) return false;

    if ( pPlayer->GetFesServiceID() == NLNET::TServiceId::InvalidId ) return false;
    if ( pPlayer->GetPlsServiceID() == NLNET::TServiceId::InvalidId ) return false;

    // ������Ϸ�߼�;
    NLNET::CMessage SendMessage;
    SendMessage.serial( &UserLogin );
    return SS_NETWORK->send( "PDS" , SendMessage );
}

SSE_NAMESPACE_END_DECL
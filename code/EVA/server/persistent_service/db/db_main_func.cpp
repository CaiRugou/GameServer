#include "db_main_func.h"
#include "db_manager.h"
#include <persistent_service/login/login_user.h>

PSE_NAMESPACE_BEGIN_DECL

void MainLoadPlayerEntity( void* data )
{
    LoadUserData* pRecord = ( LoadUserData* )data;
    if ( NULL == pRecord ) return;

    // �����û���Ϣ;
    DBManager.SavePlayerInfo( pRecord );

    // �û���¼;
    PB_UserLogin UserLogin;
    UserLogin.set_role_id( pRecord->GetRoleID() );
    UserLogin.set_client_host( pRecord->GetClientHost() );
    UserLogin.set_frontend_service_id( pRecord->GetFrontendServiceID().get() );
    UserLogin.set_game_service_id( pRecord->GetGameServiceID().get() );
    LoginUser.UserLoginCallBack( UserLogin);
}

void MainCreateRole( void* data )
{
    LoadUserData* pRecord = ( LoadUserData* )data;
    if ( NULL == pRecord ) return;

    // �����û�;
    if ( !DBManager.CreatePlayer( pRecord ) ) return;

    // �û���¼;
    PB_UserLogin UserLogin;
    UserLogin.set_role_id( pRecord->GetRoleID() );
    UserLogin.set_client_host( pRecord->GetClientHost() );
    UserLogin.set_frontend_service_id( pRecord->GetFrontendServiceID().get() );
    UserLogin.set_game_service_id( pRecord->GetGameServiceID().get() );
    LoginUser.UserLoginCallBack( UserLogin);
}

PSE_NAMESPACE_END_DECL


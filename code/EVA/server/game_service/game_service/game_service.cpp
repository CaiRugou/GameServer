#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "game_service.h"
#include "game_service_command.h"
#include <game_service/event/event_register.h>
#include <game_service/redis/redis.h>

using namespace NLMISC;
using namespace NLNET;
using namespace GSE;

// admin modules;
extern void admin_modules_forceLink();
void foo()
{
    admin_modules_forceLink();
}

void CGameService::init( void )
{
    // ����REDIS;
    NLMISC::CSString RedisHost      = ConfigFile.getVar("RedisHost").asString();
    NLMISC::CSString RedisPort      = ConfigFile.getVar("RedisPort").asString();
    NLMISC::CSString RedisTimeOut   = ConfigFile.getVar("RedisTimeOut").asString();
    NLMISC::CSString RedisPassword  = ConfigFile.getVar("RedisPassword").asString();
    nlinfo( "RedisHost     %s" , RedisHost.c_str()     );
    nlinfo( "RedisPort     %d" , RedisPort.atosi()     );
    nlinfo( "RedisTimeOut  %d" , RedisTimeOut.atosi()  );
    nlinfo( "RedisPassword %s" , RedisPassword.c_str() );
    GameRedis.Connect( RedisHost.c_str() , RedisPort.atoui() , RedisTimeOut.atoui() , RedisPassword.c_str() );

    // ע����Ϣ;
    NLNET::CUnifiedNetwork::getInstance()->addCallbackArray( GSE_LOGIN_CallBackItems , SS_ARRAYSIZE( GSE_LOGIN_CallBackItems ) );
    NLNET::CUnifiedNetwork::getInstance()->addCallbackArray( SSE_ROOM_CallBackItems  , SS_ARRAYSIZE( SSE_ROOM_CallBackItems  ) );

    // ע��Ͽ�����;
    SS_NETWORK->setServiceDownCallback( "GSE" , CallBack_GSEDisconnection );
    SS_NETWORK->setServiceDownCallback( "FES" , CallBack_FESDisconnection );
    SS_NETWORK->setServiceDownCallback( "PSD" , CallBack_PSEDisconnection );
    SS_NETWORK->setServiceDownCallback( "SSE" , CallBack_SSEDisconnection );

    // ע���¼�;
    EventRegister.getInstance();
    // ��ʼ����ʱ��;
    TimerManager->init();
    // ���ض�����;
    CI18N::load( ConfigFile.getVar("Language").asString() );

    // ִ�б�������;
    NLMISC::ICommand::execute( "load_room" , *InfoLog );
    NLMISC::ICommand::execute( "load_json" , *InfoLog );
}

bool CGameService::update( void )
{
    // ���¶�ʱ��;
    TimerManager->tickUpdate();
    return true;
}

void CGameService::release( void )
{
    // �ͷŶ�ʱ��;
    TimerManager->release();
    // �ر�REDIS;
    GameRedis.Close();
}

NLNET_SERVICE_MAIN( CGameService, "GSE", "game_service", 0  , "", "")



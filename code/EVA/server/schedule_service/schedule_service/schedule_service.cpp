#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "schedule_service.h"

#ifdef NL_OS_WINDOWS
#include <Windows.h>
#endif

using namespace NLMISC;
using namespace NLNET;
using namespace SSE;

// admin modules;
extern void admin_modules_forceLink();
void foo()
{
    admin_modules_forceLink();
}

void CScheduleService::init()
{
    // ע����Ϣ;
    NLNET::CUnifiedNetwork::getInstance()->addCallbackArray( SSE_LOGIN_CallBackItems , SS_ARRAYSIZE( SSE_LOGIN_CallBackItems ) );
    NLNET::CUnifiedNetwork::getInstance()->addCallbackArray( SSE_ROOM_CallBackItems  , SS_ARRAYSIZE( SSE_ROOM_CallBackItems  ) );

    // ע��������Ͽ�;
    SS_NETWORK->setServiceDownCallback( "SSE" , CallBack_GSEDisconnection );
    SS_NETWORK->setServiceDownCallback( "PSE" , CallBack_PSEDisconnection );
    SS_NETWORK->setServiceDownCallback( "FES" , CallBack_FESDisconnection );
    // ��ʼ����ʱ��;
    TimerManager->init();
    // ���ض�����;
    CI18N::load( ConfigFile.getVar("Language").asString() );

    // ִ�б�������;
    NLMISC::ICommand::execute( "load_json" , *InfoLog );
}

bool CScheduleService::update( void )
{
    // ���¶�ʱ��;
    TimerManager->tickUpdate();
    return true;
}

void CScheduleService::release( void )
{
    // �ͷŶ�ʱ��;
    TimerManager->release();
}

NLNET_SERVICE_MAIN( CScheduleService, "SSE", "schedule_service", 49971 , "", "")


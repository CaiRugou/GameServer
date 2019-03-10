#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "schedule_service.h"

#ifdef NL_OS_WINDOWS
#include <Windows.h>
#endif

// Reister Main;
using namespace NLNET;
using namespace SSE;

// variable value;
NLMISC::CVariable< uint32 > VAR_SSE_MAX_USERCOUNT("SSE" , "MaxPlayer" , "" , 0 , 0 , true );

// admin modules;
extern void admin_modules_forceLink();
void foo()
{
    admin_modules_forceLink();
}

void CScheduleService::init()
{
    // ע����Ϣ;
    REGISTER_MAIN_FUNCITEM( SSE_LOGIN_CallBackItems );
    // ��ʼ����ʱ��;
    TimerManager->init();
    // �������ñ�;
    JsonLoad.JsonLoadTable();
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

NLNET_SERVICE_MAIN( CScheduleService, "SSE", "schedule_service", 49971 , CallBackFunItems , "", "")


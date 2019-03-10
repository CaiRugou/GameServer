#include "CRobotServer.h"
#include "CCommonLine.h"
#include <server_share/script_mgr.h>
#include <server_share/client_msg_desc.h>
#include "CClientMgr.h"
#include "CRobotName.h"
#include <game_share/timer.h>
#include <game_share/static_table/static_table_mgr.h>

using namespace std;
using namespace NLMISC;
using namespace NLNET;

extern int  tolua_lua_function_open( lua_State* tolua_S );
extern void admin_modules_forceLink();

void foo()
{
    admin_modules_forceLink();
}

void cbLoadPlayer(NLNET::CMessage &msgin, const std::string &serviceName, NLNET::TServiceId sid)
{

}

CRobotServer::CRobotServer( void )
{
}

CRobotServer::~CRobotServer( void )
{
}

void CRobotServer::init()
{
    // �������ñ�;
    StaticTableMgr.init();
    // ��ʼ���ű�;
    ScriptMgr.init( tolua_lua_function_open );
    // �������ֱ�;
    RobotName->LoadRandomName();
    // ��ʼ����ʱ��;
    TimerManager->init();
    // ����������;
    CommonLine->AnalysisCommonLine( getArgs() );
    // 
    ClientMgr->CreateTimer();
    ClientMgr->AutoLogin();
    // 
    ClientMgr->CreateTimerSendTMail();
    ClientMgr->CreateMsgTimer();
}

bool CRobotServer::update()
{
    CommonLine->Update();
    // �����߼�;
    ClientMgr->OnUpdate();
    // ���¼�ʱ��;
    TimerManager->tickUpdate();

    return true;
}

void CRobotServer::release()
{
    TimerManager->release();
}

NLNET_SERVICE_MAIN ( CRobotServer , "Robot" , "robot_service", 0, EmptyCallbackArray , "", "");


NLMISC_COMMAND (info, "service information.", "")
{
    if(args.size() == 0) return false;

    NLMISC::CSString param( args[0] );
    CommonLine->m_RobotUID =  param.atoui();

    return true;
}
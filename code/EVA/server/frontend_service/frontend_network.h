#ifndef FRONTEND_SERVICE_NETHANDLER_H_
#define FRONTEND_SERVICE_NETHANDLER_H_

#include "frontend_def.h"
#include "client.h"
#include "client_manager.h"

FES_NAMESPACE_BEGIN_DECL

typedef std::map< std::string , TWEBCallback >  WEBCALLBACKTABLE;
typedef std::map< std::string , TRUDPCallback>  RUDPCALLBACKTABLE;

class CClient;

class CFrontendNetWork : public NLMISC::CSingleton< CFrontendNetWork >
{
public:
    CFrontendNetWork( void );
   ~CFrontendNetWork( void ){ };

    // ��ʼ�������;
    void InitNetHandler( uint16 , uint16 );
    // ���������;
    void UpdateNetHandler( void );
    // �ͷ������;
    void DestroyNetHandler( void );
    // �رտͻ�������;
    void CloseClientNet( NLNET::TSockId SocketID ) { m_WebCallBackNetBase->disconnect( SocketID ); }
    void CloseClientNet( SOCKET_ID SocketID )      { ERROR_SEND_OBJ()->push( SocketID ); }

    // ��ȡWEB����ʵ��;
    NLNET::CCallbackNetBase* GetWebNetBase( void ) { return m_WebCallBackNetBase; }

    /**************************************WEB���Ӵ���*****************************************/;
private:
    // ��������;
    static void CallBackWebConnection( NLNET::TSockId, void* );
    // ������Ϣ;
    static void CallBackWebMessage( NLNET::CMessage&, NLNET::TSockId , NLNET::CCallbackNetBase& );
    // ����Ͽ�;
    static void CallBackWebDisConnection( NLNET::TSockId , void* );

    /**************************************UDP���Ӵ���*****************************************/;
private:
    // ��������;
    void CallBackRUDPConnection( void ) { };
    // ������Ϣ;
    void CallBackRUDPMessage( void );


private:
    // ת����Ϣ;
    static void HandlerForwardMessage( NLNET::CMessage& , CClientPtr );

private:
    NLNET::CCallbackNetBase*    m_WebCallBackNetBase;       // WEB�ӿ�;
    static WEBCALLBACKTABLE     m_WebCallBackFuncTable;     // WEB������Ϣ�ص�;
    static RUDPCALLBACKTABLE    m_RUDPCallBackFuncTable;    // RUDP������Ϣ�ص�;
};

#define FrontendNetWork FES::CFrontendNetWork::instance()

FES_NAMESPACE_END_DECL

#endif // FRONTEND_SERVICE_NETHANDLER_H_
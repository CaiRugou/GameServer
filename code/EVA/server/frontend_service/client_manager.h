#ifndef FRONTEND_SERVICE_CLIENTMANAGER_H_
#define FRONTEND_SERVICE_CLIENTMANAGER_H_

#include "frontend_def.h"
#include "client.h"

FES_NAMESPACE_BEGIN_DECL

class CClientManager : public NLMISC::CSingleton<CClientManager>
{
public:
    typedef std::map< ROLE_ID   , CClientPtr > ROLECLIENT;
    typedef std::map< SOCKET_ID , ROLE_ID    > UDPCLIENT;
    typedef std::map< TSockId   , ROLE_ID    > WEBCLIENT;

    CClientManager( void );
   ~CClientManager( void ) { };

    /// ����ͻ���ʵ��;
    CClientPtr AllocUDPClient( ROLE_ID , SOCKET_ID );
    CClientPtr AllocWebClient( ROLE_ID , TSockId   );

    /// ���ҿͻ�����Ϣ;
    CClientPtr FindClientRole( ROLE_ID );
    CClientPtr FindClientWEB ( TSockId );
    CClientPtr FindClientUDP ( SOCKET_ID );

    /// ɾ���ͻ�����Ϣ;
    void DeleteClient    ( CClientPtr );
    void DeleteClientRole( ROLE_ID   );
    void DeleteClientWEB ( TSockId   );
    void DeleteClientUDP ( SOCKET_ID );

    /// ��ȡ�ͻ�������;
    uint32 GetClientCount( void ) { return m_RoleClientTable.size(); }

    /// �ͻ��˻Ự�б�;
    SS_PROPERTY( ROLECLIENT , RoleClientTable , private );
    SS_PROPERTY( UDPCLIENT  , UDPClientTable  , private );
    SS_PROPERTY( WEBCLIENT  , WEBClientTable  , private );

private:
    // ���ӳ�ʱ�䳬;
    CTimer m_ConnectionTimer;
};

FES_NAMESPACE_END_DECL

#define ClientManager FES::CClientManager::instance()

#endif // FRONTEND_SERVICE_CLIENTMANAGER_H_
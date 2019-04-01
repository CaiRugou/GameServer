#ifndef FRONTEND_SERVICE_CLIENTMANAGER_H_
#define FRONTEND_SERVICE_CLIENTMANAGER_H_

#include "frontend_def.h"

FES_NAMESPACE_BEGIN_DECL

class CClient;
class CClientManager : public NLMISC::CSingleton<CClientManager>
{
public:
    typedef std::map< SOCKET_ID , CClient* >        RUDPSOCKETTABLE;
    typedef std::map< NLNET::TSockId , CClient* >   WEBSOCKETTABLE;
    typedef std::map< ROLE_ID , CClient* >          CLIENTTABLE;

    CClientManager( void );
   ~CClientManager( void ) { };

    // ����һ���ͻ���;
    CClient* AllocClient( ROLE_ID , SOCKET_ID );
    CClient* AllocClient( NLNET::TSockId );

    // ����һ���ͻ���;
    CClient* FindClient( SOCKET_ID );
    CClient* FindClient( NLNET::TSockId& );

    // �˺Ų�ѯһ���ͻ���;
    CClient* FindClientRoleID( ROLE_ID );

    // ɾ��һ���ͻ���;
    void DeleteClient( CClient* );
    void DeleteClient( SOCKET_ID );
    void DeleteClient( NLNET::TSockId& );

    // ��ȡ�ͻ�������;
    uint32 GetClientCount     ( void ) { return GetRUDPClientCount() + GetWEBClientCount(); }
    uint32 GetRUDPClientCount ( void ) { return m_RUDPSocketTable.size(); }
    uint32 GetWEBClientCount  ( void ) { return m_WEBSocketTable.size();  }

    // RUDP�ͻ����б�;
    SS_PROPERTY( RUDPSOCKETTABLE , RUDPSocketTable , private );
    // WEB �ͻ����б�;
    SS_PROPERTY( WEBSOCKETTABLE  , WEBSocketTable  , private );
    // �˺ſͻ����б�;
    SS_PROPERTY( CLIENTTABLE     , ClientTable     , private );

private:
    // ���ӳ�ʱ�䳬;
    CTimer m_ConnectionTimer;
};

FES_NAMESPACE_END_DECL

#define ClientManager FES::CClientManager::instance()

#endif // FRONTEND_SERVICE_CLIENTMANAGER_H_
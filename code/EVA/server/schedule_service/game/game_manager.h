#ifndef SSE_GAME_MANAGER_H_
#define SSE_GAME_MANAGER_H_

#include <schedule_service/schedule_service/schedule_service_def.h>

SSE_NAMESPACE_BEGIN_DECL

class CGameManager : public NLMISC::CSingleton< CGameManager >
{
public:
    CGameManager( void ){ m_GameList.clear(); }
   ~CGameManager( void ){ };

    ///  ������Ϸ�б�;
    void UpdateGameList( TServiceId , RecordGameList& );
    ///  ɾ����Ϸ�б�;
    void DeleteGameList( TServiceId& );

    ///  ��ȡ��������Ϣ;
    TServiceId GetGoodServiceID( CSString& );

    ///  ��Ϸ�б�;
    SS_PROPERTY( RecordGameTable , GameList , private );
};

SSE_NAMESPACE_END_DECL

#define GameManager CGameManager::instance()

#endif// SSE_GAME_MANAGER_H_
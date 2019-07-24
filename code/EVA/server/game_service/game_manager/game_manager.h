#ifndef GSE_GAME_MANAGER_H_
#define GSE_GAME_MANAGER_H_

#include <game_service/game_service/game_service_def.h>
#include "game_base.h"

GSE_NAMESPACE_BEGIN_DECL

class CGameManager : public CSingleton< CGameManager >
{
public:
    CGameManager( void );
   ~CGameManager( void );

    ///  ������Ϸ;
    bool JoinGame( ROLE_ID , ROOM_ID );
    ///  �뿪��Ϸ;
    bool LeaveGame( ROLE_ID );
    ///  ɾ����Ϸ;
    bool DeleteGame( ROOM_ID );

    ///  ������Ϸ;
    bool CreateGame( ROLE_ID , PB_CreateRoom& );
    bool CreateGameChangeScenes( ROLE_ID , PB_CreateRoom& );

    /// ��ȡ��Ϸʵ��;
    CGameBasePtr GetGameBasePtr( ROOM_ID );

    /// �����б�;
    SS_PROPERTY( GameList , GameList , private );
};

#define GameManager CGameManager::getInstance()

GSE_NAMESPACE_END_DECL

#endif//GSE_GAME_MANAGER_H_
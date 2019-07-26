#ifndef SSE_GAME_MANAGER_H_
#define SSE_GAME_MANAGER_H_

#include <schedule_service/schedule_service/schedule_service_def.h>
#include "game.h"

SSE_NAMESPACE_BEGIN_DECL

class CGameManager : public NLMISC::CSingleton< CGameManager >
{
public:
    CGameManager( void );
   ~CGameManager( void );

    ///  ������Ϸ����;
    void LoadGameInfo( TServiceId& );
    void LoadHallInfo( void );

    ///  ɾ����Ϸ����;
    void RemoveGameInfo( TServiceId& );
    void RemoveHallInfo( TServiceId& );

    //   ������Ϸ��Ϣ;
    void UpdateGameInfo( TServiceId& , CSString& , uint32 GameCount );
    void UpdateHallInfo( TServiceId& , CSString& , uint32 RoleCount );

    ///  ��ȡ��Ϸ������Ϣ;
    CGameInfoPtr GetGameInfoPtr( CSString );
    CHallInfoPtr GetHallInfoPtr( void );

private:
    SS_PROPERTY( GAMETABLE , GameTable , private );
    SS_PROPERTY( HALLTABLE , HallTable , private );
};

SSE_NAMESPACE_END_DECL

#define GameManager CGameManager::instance()

#endif// SSE_GAME_MANAGER_H_
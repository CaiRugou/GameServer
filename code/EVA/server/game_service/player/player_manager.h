#ifndef GES_PLAYER_MANAGER_H_
#define GES_PLAYER_MANAGER_H_

#include <game_service/game_service/game_service_def.h>
#include "player.h"

GSE_NAMESPACE_BEGIN_DECL

class CPlayerManager : public NLMISC::CSingleton< CPlayerManager >
{
public:
    CPlayerManager( void );
   ~CPlayerManager( void );

    ///  �������ʵ��;
    CPlayerPtr AllocPlayer( ROLE_ID );
    CPlayerPtr AllocPlayer( CRecordPlayer& );

    ///  ��ȡ�������;
    CPlayerPtr GetPlayer( ROLE_ID );
    CPlayerPtr GetPlayer( CRecordPlayer& );

    ///  ɾ�����;
    void DeletePlayer( ROLE_ID );
    void DeletePlayer( CRecordPlayer& );

    ///  �л�����;
    bool ChangeScenes( ROLE_ID , TServiceId );

private:
    SS_PROPERTY( PLAYER_TABLE , PlayerTable , private );
};

#define PlayerManager CPlayerManager::instance()

GSE_NAMESPACE_END_DECL

#endif// GES_PLAYER_MANAGER_H_
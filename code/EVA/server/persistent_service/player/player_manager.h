#ifndef PSE_PLAYER_MANAGER_H_
#define PSE_PLAYER_MANAGER_H_

#include <persistent_service/persistent_service/persistent_service_def.h>
#include "player.h"

PSE_NAMESPACE_BEGIN_DECL

class CPlayerManager : public NLMISC::CSingleton< CPlayerManager >
{
public:
    CPlayerManager( void );
   ~CPlayerManager( void );

    SS_PROPERTY( PLAYER_TABLE , PlayerTable , private );

    /// �������ʵ��;
    CPlayerPtr AllocPlayer( ROLE_ID );
   /// ��ȡ�������;
    CPlayerPtr GetPlayer  ( ROLE_ID );

    /// ��ȡȫ�����;
    PLAYER_TABLE& GetPlayerList( void ) { return m_PlayerTable; }
};

#define PlayerManager CPlayerManager::getInstance()

PSE_NAMESPACE_END_DECL

#endif//PSE_PLAYER_MANAGER_H_
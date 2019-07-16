#ifndef SSE_PLAYER_MANAGER_H_
#define SSE_PLAYER_MANAGER_H_

#include <schedule_service/schedule_service/schedule_service_def.h>

SSE_NAMESPACE_BEGIN_DECL

class CPlayer;

class CPlayerManager : public NLMISC::CSingleton< CPlayerManager >
{
public:
    CPlayerManager( void ){ };
   ~CPlayerManager( void ){ };

    // �������ʵ��;
    CPlayer* AllocPlayer( ROLE_ID );
    // ��ȡ�������;
    CPlayer* GetPlayer  ( ROLE_ID );

    // ����б�;
    SS_PROPERTY( PLAYER_TABLE , PlayerTable , private );
};

SSE_NAMESPACE_END_DECL

#define PlayerManager SSE::CPlayerManager::instance()

#endif // SSE_PLAYER_MANAGER_H_;
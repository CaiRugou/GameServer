#ifndef GES_PLAYER_MANAGER_H_
#define GES_PLAYER_MANAGER_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CPlayer;

class CPlayerManager : public NLMISC::CSingleton< CPlayerManager >
{
public:
    CPlayerManager( void ) { };
   ~CPlayerManager( void ) { };

public:
    //       �����ɫʵ��;
    CPlayer* AllocPlayer( CRecordPlayer& RecordPlayer );
    CPlayer* AllocPlayer( ROLE_ID );

    //       ��ȡ��ɫʵ��;
    CPlayer* GetPlayer( ROLE_ID );
    //       ɾ�����ʵ��;
    void     DeletePlayer( ROLE_ID );
    //       ��ȡʵ������;
    uint32   GetPlayerCount( void );
    //       �л�����;
    bool     ChangeScenes( ROLE_ID , NLNET::TServiceId );

private:
    PLAYER_TABLE m_RoleTable;
};

#define PlayerManager CPlayerManager::instance()

GSE_NAMESPACE_END_DECL

#endif// GES_PLAYER_MANAGER_H_
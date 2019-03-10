#ifndef CPlayerInfo_h__
#define CPlayerInfo_h__
#include <game_share/game_def.h>
#include <server_share/database/record_player.h>
#include "../CRobotHelper.h"

class CPlayerInfo
{
public:
    CPlayerInfo( void );
    virtual ~CPlayerInfo( void );


    // ��ȡ���UID;
    DEF::UID    GetRoleUID( void ){ return m_PlayerData.uid ; }
    // ��ȡ���ID;
    DEF::PID    GetRoleID( void ){ return m_PlayerData.pid ; }
    // ��ȡ�������;
    std::string GetName( void ){ return m_PlayerData.player_name; }
    // ��ȡ��ҵȼ�;
    uint32 GetLevel( void ){ return m_PlayerData.level; }
    // ��ȡ��Ǯ;
    DEF::MONEY GetMoney( void ) { return m_PlayerData.money ; }

    // ���µȼ�;
    void SetLevel( uint32 value )    { m_PlayerData.level = value; }
    // ��ӽ�Ǯ;
    void AddMoney( DEF::MONEY value ){ m_PlayerData.money += value ; }
    // ���RMB;
    void AddRMB( DEF::RMB value ) { m_PlayerData.bind += value; }

    // ���������Ϣ;
    void OnSavePlayerInfo( MsgPlayerInfo& data );


protected:

    // ��ɫ������Ϣ;
    DB_RECORD::CRecordPlayer m_PlayerData;

};

#endif // CPlayerInfo_h__
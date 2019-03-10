#ifndef CClient_h__
#define CClient_h__

#include "CConnect.h"
#include "CRobotHelper.h"

#include "role/CPlayerInfo.h"
#include "role/CPlayerMail.h"
#include "role/CPlayerFriend.h"
#include "role/CPlayerAchievement.h"
#include "role/CPlayerMahjong.h"
#include "role/CPlayerItem.h"
#include "role/CPlayerMission.h"
#include "role/CPlayerStatistics.h"

#include <game_share/game_def.h>
#include <server_share/database/db_logic_chunk.h>

class CClient : public CConnect 
              , public CPlayerInfo
              , public CPlayerMailInfo
              , public CPlayerFriendInfo
              , public CPlayerAchievementInfo
              , public CPlayerMahjong
              , public CPlayerItem
              , public CPlayerMission
              , public CPlayerStatistics
{
public:
    CClient( void );
    virtual ~CClient( void );

    // ���ú���;
    void OnReset( void );
    // ���º���;
    void OnUpdate( void );
    // ������ʱ��;
    void OnCreateTimer( const char* lua_usename , const char* lua_funname , int time , bool flag = false );
    // ���ÿͻ���״̬;
    void SetClientState( ClientState State ){ m_ClientState = State ;}
    // ��֤�˺���;
    bool IsAuthAccountState( void ){ return ( m_ClientState == client_state_authaccount ) ; }
    // ��½��;
    bool IsLoginState( void ){ return ( m_ClientState == client_state_login ) ; }
    // ������ɫ;
    bool IsCreateRoleState( void ){ return ( m_ClientState == client_state_createrole ) ; }
    // �������״̬;
    bool IsLoadPlayerState( void ) { return ( m_ClientState == client_state_createrole ) ; }
    // ��½�ɹ�;
    bool IsOnlineState( void ) { return ( m_ClientState == client_state_online ) ; }

    // ���RCR32����;
    uint32 GetBufferLenght( google::protobuf::Message* Message );
    // ����ͬ��״̬;
    void SetSyncCleintState( uint32 unSyncValue );
    // ȡ��ͬ��״̬;
    void CleSyncClientState( uint32 unSyncValue );
    // �Ƿ�ͬ�����;
    bool IsSyncSucceed( void );
    
    // ���뷿������;
    void SetRoomType( std::string value ) { m_strRoomType = value; }
    std::string GetRoomType( ) { return m_strRoomType; }

    void ClearTimer();

    void SetMountLuaType( MountLuaType type ) { m_MountLuaType = type; }
    bool IsInBlackJack() { return m_MountLuaType == MountLua_BlackJack; }
    bool IsInTexasPoker() { return m_MountLuaType == MountLua_TexasPoker; }
    bool IsInSlots() { return m_MountLuaType == MountLua_Slots; }
    bool IsInHall() { return m_MountLuaType == MountLua_Hall; }
    bool IsInMahJong() { return m_MountLuaType == MountLua_MahJong; }
   
    // ��ȡ�ɾ�CRC����;
    DEF::CHECK_SUM GetCRC32Achievement( void );
    // ��ȡ����CRC����;
    DEF::CHECK_SUM GetCRC32Item( void );
    // ��ȡ����CRC����;
    DEF::CHECK_SUM GetCRC32Mission( void );
private:
    // ���ؽű�;
    MountLuaType             m_MountLuaType;
    // ���뷿������;
    std::string              m_strRoomType;
    // �󶨼�ʱ������;
    std::deque< CTimer* >    m_TimerQueue;
    // �ͻ���״̬;
    ClientState              m_ClientState;
    // �첽��½״̬;
    uint32                   m_SyncLoginState;
};

#endif // CClient_h__
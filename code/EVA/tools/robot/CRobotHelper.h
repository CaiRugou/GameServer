#ifndef MyRobotHelper_h__
#define MyRobotHelper_h__
#include <nel/net/callback_net_base.h>
#include "msg/recv_logic.h"
#include <game_share/game_def.h>

//class CClient;
#define PLAYER_COMMON                  "CMD"               // GMָ��;
#define PLAYER_ERROR                   "ERR"               // ������;
#define PLAYER_INFO                    "SyncData"          // �����ɫ��Ϣ;
#define LOGIN                          "LOGIN"             // ��½;
#define PLAYER_SYNCLOGINPLAYER         "LPLY"              // ͬ����һ�����Ϣ;
#define PLAYER_CREATE                  "CT_PLY"            // ��ɫ����;
#define PLAYER_NULL                    "PLY_NULL"          // ��Ҫ������ɫ;
#define PLAYER_ENTER_GAME              "EG"                // ���뷿��;
#define PLAYER_BLACKJACKROOMINFO       "BJ_GI"             // ��������Լ���������;
#define PLAYER_LEAVE_ROOM              "LR"                // �뿪����;
#define PLAYER_SYNCPLAYERINFO          "SPLY"              // ����ͬ�������Ϣ;
#define PLAYER_RANKINGMONEYOP10        "RMT"               // Ranking Money Top 10;
#define PLAYER_BLACKJACKADDPOUR        "BJ_P"              // ������ע;
#define PLAYER_BLACKJACKASKCARD        "BJ_AC"             // ����Ҫ��;
#define PLAYER_BLACKJACKSPLITCARD      "BJ_SC"             // ����Ҫ��;
#define PLAYER_BLACKJACKSTANDCARD      "BJ_STD"            // ����ͣ��;
#define PLAYER_BLACKJACKBUYSURRENDER   "BJ_BS"             // ������;
#define PLAYER_BLACKJACKSKIPSURRENDER  "BJ_BSC"            // ��������;
#define PLAYER_BLACKJACKDOUBLECARD     "BJ_DB"             // ˫��;
#define PLAYER_BROADCAST_PLY_INFO      "BJ_PI"             // �㲥�����Ϣ;
#define PLAYER_BLACKJACKCLEARPOUR      "BJ_CL"             // �����ע;
#define PLAYER_ADDMONEY                "AM"                // ��ӽ�Ǯ;
#define PLAYER_SUBMONEY                "SM"                // ���ٽ�Ǯ;
#define PLAYER_GETREWARD               "TRD"               // ��ȡ����;
#define PLAYER_GETCHAMPIONSHIP         "SC"                // �����ȡ��������;
#define PLAYER_REQUESTPRIZEPOOL        "RP"                // �����������;
#define PLAYER_RANKINGROOMTOP          "RRT"               // ranking room top;
#define PLAYER_RANKINGMYDATA           "RMy"               // �����Լ������а�����;
#define PLAYER_SENDCOMMMONMAIL         "SCM"               // ��������ͨ�ʼ�;
#define PLAYER_REQUESTMAILDATA         "RMAIL"             // �����ʼ�����;
#define PLAYER_RECEIVECOMMONMAIL       "RCM"               // �յ���ͨ�ʼ�;
#define PLAYER_SYSTEM_REWARD           "SRAD"              // ����ϵͳ�ʼ�����;
#define PLAYER_COMMON_REWARD           "CRAD"              // ������ͨ�ʼ�����;
#define PLAYER_DELETE_SYSTEMMAIL       "DSM"               // ����ɾ��ϵͳ�ʼ�;
#define PLAYER_DELETE_COMMONMAIL       "DCM"               // ����ɾ����ͨ�ʼ�;
#define PLAYER_LOOK_COMMONMAIL         "LCM"               // ����鿴��ͨ�ʼ�;
#define PLAYER_SYNCHFRIENDLIST         "FL"                // ����ͬ�������б�;
#define PLAYER_SYNCHAPPLYLIST          "AL"                // ����ͬ�����������б�;
#define PLAYER_ADDFRIENDAPPLY          "APF"               // ��������;
#define PLAYER_ADDFRIEND               "AF"                // �������;
#define PLAYER_DELETEFRIEND            "DF"                // ɾ������;
#define PLAYER_DELETEAPPLYFRIEND       "DA"                // ɾ����������;
#define PLAYER_FRIENDDETAIL            "FD"                // ���������ϸ��Ϣ;
#define PLAYER_APPLYDETAIL             "AD"                // �������������ϸ��Ϣ;
#define PLAYER_REWARDFRIEND            "GF"                // ����������;
#define PLAYER_CHAT_ROOM               "CR"                // ����������;
#define PLAYER_RKPI                    "RKPI"              // �������ͳ������
#define PLAYER_GIVETIP                 "BJ_Tip"            // �����ϴ���;
#define PLAYER_ROOMPLAYERINFO          "RPI"               // ����ͬ�����������ϸ��Ϣ;
#define PLAYER_INVITEFRIEND            "IVF"               // ��������;
#define PLAYER_INVITEENTER             "IVE"               // �������;
#define PLAYER_SENDTEMPLATEMAIL        "SSM"               // ����ϵͳģ���ʼ�;
#define PLAYER_BIND_FACEBOOK           "BF"                // ��Facebook;
#define PLAYER_PULLROULETTEMONEY       "PRM"               // ��ת��;
#define PLAYER_PULLROULETTERATE        "PRR"               // ת����;
#define PLAYER_PULLROULETTERATERMB     "PRRR"              // ����ת����;
#define PLAYER_ROULETTEGETMONEY        "RGM"               // ��ȡת�̽���;
#define PLAYER_REQUESTSHOPINFO         "SHOP"              // �����̵���Ϣ;
#define PLAYER_SHOPBUYMONEY            "SBUY"              // �̵깺����;
#define PLAYER_REQUESTRENAME           "RN"                // ��������;
#define PLAYER_REQOTHERPLAYERINFO      "ROPI"              // �������������ϸ��Ϣ;
#define PLAYER_REQSELFPLAYERINFO       "RSPI"              // �����Լ���ϸ��Ϣ;
#define PLAYER_REQPLAYERKPI            "DRKPI"             // �����������ͳ����Ϣ;
#define PLAYER_HALLADSDRAWAWARD        "HALL_ADS"          // �����������ȡ����;
#define PLAYER_ROOMADSDRAWAWARD        "ROOM_ADS"          // ���俴�����ȡ����;
#define PLAYER_TP_CALLPOUR             "TP_CP"             // ��Ҹ�ע;
#define PLAYER_TP_RAISEPOUR            "TP_RP"             // ��Ҽ�ע;
#define PLAYER_TP_FOLDCARD             "TP_AD"             // �������;
#define PLAYER_TP_CHECKCARD            "TP_CC"             // �������;
#define PLAYER_TP_RESETCOINS           "TP_RC"             // ���ó���;
#define PLAYER_GOBACKGAME              "GoBackGame"        // ������Ϸ;
#define PLAYER_SLOTSSPIN               "SL_SP"             // �ϻ�������;
#define PLAYER_CHECKMAILSTATE          "MFG"               // ����鿴�ʼ�״̬;
#define PLAYER_RANKPLAYERNUM           "RF"                // ���������������;
#define PLAYER_SYNCHACHIEVEMENT        "SAD"               // ����ɾ���Ϣ;
#define PLAYER_SYNCHCOMACHIEVEMENT     "SCAD"              // ��������ɳɾ���Ϣ;
#define PLAYER_ACHIEVEMENTDRAWREWARD   "ADR"               // ������ȡ�ɾͽ���;
#define PLAYER_BLACKJACKRESETPOUR      "BJ_RP"             // 21��������ע;
#define PLAYER_SLOTSBONUSGAMESELECT    "SL_BGS"            // �ϻ���С��Ϸ;
#define PLAYER_RECOMMENDFRIEND         "RDF"               // �����Ƽ�����;
#define PLAYER_SYNCHSTATISTICSDATA     "SSD"               // ����ͬ��ͳ����Ϣ;
#define PLAYER_BROAD_JOINTEXASPOKER    "TP_GI"             // �����˿˹㲥���뷿����Ϣ;
#define PLAYER_UPDATEDYNAMICMSG        "UDM"               // ���¸���ǩ��;
#define PLAYER_REHEADPORTRAIT          "RHP"               // �޸�ͷ��;
#define PLAYER_SLOTSJACKPOTS           "SL_JP"             // Slots���󽱳�����;
#define PLAYER_SLOTSBROADCASTGAMEINFO  "SL_GI"             // Slots���뷿�䣬�㲥������Ϣ;
#define PLAYER_TPCHALLAPPLYGAME        "TP_CAG"            // ���ݾ���������;
#define PLAYER_TPCHALLCANCELAPPLYGAME  "TP_CCG"            // ȡ�����ݾ���������;
#define PLAYER_TPCHALLROOMDATA         "TP_RDG"            // ���ݾ�����������Ϣ;
#define PLAYER_TPCHALLREQUESTQUIT      "TP_RQ"             // ���ݾ����������˳�;
#define PLAYER_GETBONUSMONEY           "GB"                // ��ȡbonus money;
#define PLAYER_VIEWPIGINFO             "VPig"              // ��ѯС���Ǯ����Ϣ;
#define PLAYER_PRIVATECHAT             "PC"                // ���˽��;
#define PLAYER_MAHJONGGAMEINFO         "MJ_GI"             // �Ͼ��齫��Ϸ��Ϣ;
#define PLAYER_MAHJONGUSEROPERATE      "MJ_SP"             // �Ͼ��齫��Ҳ���Ȩ��;
#define PLAYER_MAHJONGOUTCARD          "MJ_OC"             // �Ͼ��齫��ҳ���;
#define PLAYER_MAHJONGSTARTREADY       "MJ_SR"             // �Ͼ��齫�û���ʼ׼��;
#define PLAYER_MAHJONGCANCEREADY       "MJ_CR"             // �Ͼ��齫�û�ȡ��׼��;
#define PLAYER_MAHJONGSHOWDOWN         "MJ_SD"             // �Ͼ��齫����;
#define PLAYER_SYNCHITEMDATA           "SICU"              // ͬ����������;
#define PLAYER_USE_ITEM                "UseItem"           // ʹ�õ���;
#define PLAYER_SELL_ITEM               "SellItem"          // ���۵���;
#define PLAYER_STOREBUYITEM            "BSI"               // �����̳ǵ���;
#define PLAYER_BINDMOBILENUMBER        "BMNC"              // Bind Mobile Number Check Random Code.;
#define PLAYER_CHATPAOMADENG           "CPMD"              // ����ƺ���;
#define PLAYER_SEARCHPID               "SPID"              // ����PID;
#define PLAYER_GETSENDMONEYLIMIT       "SML"               // ��ȡSend Money Limit;
#define PLAYER_SYNCBLACKLIST           "SBL"               // ͬ�������б�����;
#define PLAYER_DELETEBLACKLIST         "DBL"               // �Ƴ������б�;
#define PLAYER_ADDBLACKLIST            "ABL"               // ��������б�;
#define PLAYER_SYNCHMISSIONDATA        "SMD"               // ͬ����������;
#define PLAYER_RESTORESCOREDATA        "RSD"               // ���ͳ�ƻ�������;
#define PLAYER_MISSIONREWARD           "MDR"               // ������ȡ����;


#define ROBOT_UDP_TIME   1000
#define ITEM_RANDOM_NUM 50
#define ROBOT_START_MISSION 16001001
#define ROBOT_START_ACHIEVEMENT 7000001
#define CLIENT_RANDOM_NUM 10
#define LIMIT_SEND_TIME 1
#define USERNAMELENGTH 20
#define SENDMSGLIMITTIME (LIMIT_SEND_TIME + 2)
#define MOBILENUMBERSIZE  14          

#define DYNAMIC_CLIENT( data ) \
    if( !data ) \
    return; \
    CClient* pClient = dynamic_cast< CClient* >( data ); \
    if( !pClient )\
    return;

enum ClientState
{
    client_state_null  ,        
    client_state_authaccount,   // ��֤�˺�;
    client_state_login ,        // ��½��;
    client_state_createrole,    // ������ɫ;
    client_state_loadplayer,    // �����������;
    client_state_online,        // ��½�ɹ�;
};

enum SyncLoginFlag
{
    login_sync_succeed      = 0x0000,
    login_sync_item_can_use = 0x0001,
    login_sync_item_stuff   = 0x0002,
    login_sync_item_guard   = 0x0004,
    login_sync_item_limit   = 0x0008,
    login_sync_dup          = 0x0010,
    login_sync_guard        = 0x0020,
    login_sync_hero         = 0x0040,
    login_sync_castle       = 0x0080,
    login_sync_achievement  = 0x0100,
	login_sync_mission      = 0x0200,
};

enum PlayerState
{
    InTheHallState = 0,
    InTheRoomState = 1,

};

enum MountLuaType
{
    MountLua_Invalid    = 0,
    MountLua_Hall       = 1,
    MountLua_BlackJack  = 2,
    MountLua_TexasPoker = 3,
    MountLua_Slots      = 4,
    MountLua_MahJong    = 5,
};

// bytes to int'
inline uint bytesTouint( uint8* ArrBytes )
{
    uint resVal  = ( uint )ArrBytes[ 0 ] & 0xff;
    resVal      |= ( ( ( uint )ArrBytes[ 1 ] << 8) & 0xff00 );
    resVal      |= ( ( ( uint )ArrBytes[ 2 ] << 16 & 0xff0000 ) );
    resVal      |= ( ( ( uint )ArrBytes[ 3 ] << 24 & 0xff000000 ) );

    return resVal;
}

// int to bytes;
inline void uintTobytes( uint Value , uint8* ArrBytes )
{
    memset( ArrBytes , 0 , sizeof( uint8 ) * 4 );
    ArrBytes[ 0 ] = ( uint8 )( Value & 0xff );
    ArrBytes[ 1 ] = ( uint8 )( ( Value >> 8 )  & 0xff00 );
    ArrBytes[ 2 ] = ( uint8 )( ( Value >> 16 ) & 0xff0000 );
    ArrBytes[ 3 ] = ( uint8 )( ( Value >> 24 ) & 0xff000000 );
}

// long long to byte;
inline void llongtobyte( uint64 Value , uint8* ArrBytes )
{
    memset( ArrBytes , 0 , sizeof( uint8 ) * 8 );
    ArrBytes[ 0 ] = ( uint8 )( Value & 0xff );
    ArrBytes[ 1 ] = ( uint8 )( ( Value >> 8 ) & 0xff00 );
    ArrBytes[ 2 ] = ( uint8 )( ( Value >> 16 ) & 0xff0000 );
    ArrBytes[ 3 ] = ( uint8 )( ( Value >> 24 ) & 0xff000000 );
    ArrBytes[ 4 ] = ( uint8 )( ( Value >> 32 ) & 0xff00000000 );
    ArrBytes[ 5 ] = ( uint8 )( ( Value >> 40 ) & 0xff0000000000 );
    ArrBytes[ 6 ] = ( uint8 )( ( Value >> 48 ) & 0xff000000000000 );
    ArrBytes[ 7 ] = ( uint8 )( ( Value >> 56 ) & 0xff00000000000000 );
}

// byte to long long 
inline uint64 byteTolonglong( uint8* ArrBytes )
{
    uint64 resVal = ( uint64 )ArrBytes[ 0 ] & 0xff;
    resVal |= ( ( ( uint64 )ArrBytes[ 1 ] << 8 ) & 0xff00 );
    resVal |= ( ( ( uint64 )ArrBytes[ 2 ] << 16 ) & 0xff0000 );
    resVal |= ( ( ( uint64 )ArrBytes[ 3 ] << 24 ) & 0xff000000 );
    resVal |= ( ( ( uint64 )ArrBytes[ 4 ] << 32 ) & 0xff00000000 );
    resVal |= ( ( ( uint64 )ArrBytes[ 5 ] << 40 ) & 0xff000000000 );
    resVal |= ( ( ( uint64 )ArrBytes[ 6 ] << 48 ) & 0xff00000000000 );
    resVal |= ( ( ( uint64 )ArrBytes[ 7 ] << 56 ) & 0xff0000000000000 );

	return resVal;
}

static const char UserNameTable[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

#endif // MyRobotHelper_h__
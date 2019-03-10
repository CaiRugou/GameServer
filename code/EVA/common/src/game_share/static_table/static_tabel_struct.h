#ifndef static_tabel_struct_h__
#define static_tabel_struct_h__

#include <vector>
#include <nel/misc/sstring.h>
#include <game_share/game_def.h>
#include "static_field.h"
struct IconSet
{
    uint32 icon_id;
    uint32 weight;

    IconSet()
        : icon_id(0)
        , weight(0)
    {
    }
};

struct RoomConfigXml
{
    uint32              template_id;
    std::string         room_type;
    std::string         game_type;
    uint32              min_ver;
    std::string         game_name;
    std::string         app_name;
    std::string         challenge_type;
    std::string         robot;
    uint32              room_max;
    uint32              room_min;
    uint32              viewer_max;
    DEF::MONEY          enter_score;
    uint32              icon_progress;
    bool                is_goback;
    bool                auto_return;    // �������ڷ����ڣ��Զ����ط��䡣
    uint32              delete_room_time;
    bool                check_limit;    // �Ƿ���ͬһ��IP

    std::map<uint32,IconSet> icon_set_map;

    RoomConfigXml()
        : template_id(0)
        , room_max(1)
        , room_min(1)
        , enter_score(0)
        , viewer_max(0)
        , icon_progress(0)
        , is_goback( false )
        , auto_return( false )
        , delete_room_time( 0 )
        , min_ver( 0 )
        , check_limit( false )
    {
        icon_set_map.clear();
    }
};

struct ItemEntity
{
    uint32      item_tid;
    uint32      item_num;
};

struct SignInSevenXml
{
    uint32					which_day;
    sint64					template_id;
    sint64					gold;
    sint64					intergral;
    sint64					diamond;
    sint64					item_num;			

    SignInSevenXml() : which_day(1),
        template_id(0),
        gold(0),
        intergral(0),
        diamond(0),
        item_num(0)
    {}
};

typedef std::map<std::string,std::vector<SignInSevenXml> >		TSignInSevenMap;

struct VIPConfigXml
{
    uint32              level;
    uint32              level_up_exp;
    double              buy_money;
    double              bonus;
    uint32              buy_back_add_num;

    VIPConfigXml()
    {}
};

struct PigOnSaleInfo
{
    DEF::MONEY      on_sale_condition;
    uint32          duration_minute;
    std::string     pop_picture;
    uint32          on_sale_item_id;
};

struct PigConfigXml
{
    double              in_rate;
    DEF::MONEY          max_return;
    DEF::MONEY          replace_min;
    DEF::MONEY          replace_max;
    uint32              shop_item_id;
    DEF::MONEY          pop_condition;
    std::string         pop_picture;
    std::list<PigOnSaleInfo> on_sale_list;
};

struct BlackjackStateWaitConfig
{
    uint32              wait_finish;
    uint32              wait_pour;
    uint32              wait_determine;
    uint32              wait_player_action;
    uint32              wait_split;

    BlackjackStateWaitConfig() : wait_finish(1), wait_pour(1), wait_determine(1), wait_player_action(1), wait_split(1)
    {}
};

struct BlackjackShuffle
{
    uint32              deck_of_cards;
    uint32              shuffle_limit_cards;
    uint32              take_out_10;
    uint32              give_banker_10_rate;

    BlackjackShuffle() : deck_of_cards(3), shuffle_limit_cards(50), take_out_10(0), give_banker_10_rate(0)
    {}
};

struct BlackJackCoinVal
{
    uint64 coin_1;
    uint64 coin_2;
    uint64 coin_3;
    uint64 coin_4;
    BlackJackCoinVal(): coin_1(0),coin_2(0),coin_3(0),coin_4(0)
    {}
};

struct HorseStateWaitConfig
{
    uint32              wait_pour;
    uint32              wait_finish;

    HorseStateWaitConfig() : wait_finish(1), wait_pour(1)
    {}
};

struct HorsePlayerUpdateConfig
{
    sint32              time;

    HorsePlayerUpdateConfig() : time(1)
    {}
};

struct HorseCoinVal
{
    uint64 coin_1;
    uint64 coin_2;
    uint64 coin_3;
    uint64 coin_4;
    uint64 coin_5;
    HorseCoinVal(): coin_1(0),coin_2(0),coin_3(0),coin_4(0),coin_5(0)
    {}
};

struct FishRoomVal
{
    double return_money_rate;
    uint32 gun_rate;
    uint32 gun_min_limit;
    uint32 gun_max_limit;
    uint32 exfish_need_count;
    DEF::MONEY exfish_need_money;
    uint32 exfish_probability; /// �ٷֱ�;
    std::vector<uint32> exfish_list;

    FishRoomVal():return_money_rate(0),gun_rate(0),gun_min_limit(0),gun_max_limit(0),exfish_need_count(0),exfish_need_money(0),exfish_probability(0)
    {}
};

struct FishSkillVal
{
    uint32     weight;            //ת��ת������;
    bool       is_roulette;       //�Ƿ���������ת����ת��;
    bool       is_change_gun;     //true�Ļ������ʱ���ڲ�ҪǮ;
    uint32     continue_time;     //����ʱ��;
    uint32     up_rate;           //������ߵĸ���;
    uint32     item_template_id;  //���ܶ�Ӧ��Ʒ��ID;
    uint32     kill_now_level;    //�ñ������µ���ֱ������;

    FishSkillVal():weight(0),is_roulette(false),up_rate(0),item_template_id(0),kill_now_level(99)
    {}
};

struct HorseBetRateVal
{
    double          win_rate;
    double          place_rate;
    double          show_rate;
    HorseBetRateVal(): win_rate(1),place_rate(1),show_rate(1)
    {}
};

struct HorseVal
{
    std::string                 name;
    uint32                      weight;
    std::vector<HorseBetRateVal>  bet_rate_list;
    HorseVal(): name("")
    {}
};

//����ţţ��Ϸ����������Ϣ

struct NiuNiuStateWaitConfig
{
    uint32 WaitTime;           // �ȴ�ʱ��;
    uint32 WaitTimeOut;        // �ȴ���ʱʱ��;
    uint32 CheckGameTime;      // �����Ϸ��ʼ��ʱ��;
    uint32 StartTime;          // ��ʼʱ��;
    uint32 BrandTime;          // ��������ʱ��;
    uint32 AddPourTime;        // ��עʱ��;
    uint32 SelectHandTime;     // ѡ�����Ƹ���ʱ��;
    uint32 ShowHandTime;       // ̯��ʱ��;
    uint32 RelieveTime;        // ��ɢ����ʱ��;
    uint32 ShowDownTime;       // ����ʱ��;
    std::map <uint32, uint32> m_CardType_Multi;  // ���ͱ���

    NiuNiuStateWaitConfig() : WaitTime(0), WaitTimeOut(0), CheckGameTime(0), StartTime(0), BrandTime(0),
        AddPourTime(0), SelectHandTime(0), ShowHandTime(0), RelieveTime(0), ShowDownTime(0)
    {}
};

//ƴ������Ϸ����ʱ������
struct PinSanZhangStateWaitConfig
{
    uint32 WaitTime;           // �ȴ�ʱ��;
    uint32 WaitTimeOut;        // �ȴ���ʱʱ��;
    uint32 CheckGameTime;      // �����Ϸ��ʼ��ʱ��;
    uint32 StartTime;          // ��ʼʱ��;
    uint32 BrandTime;          // ��������ʱ��;
    uint32 CompareCardTime;    // ����ʱ��;
    uint32 RelieveTime;        // ��ɢ����ʱ��;
    uint32 ShowDownTime;       // ����ʱ��;
    uint32 WaitNextTime;      // ���֮��ļ�Ъʱ��

    PinSanZhangStateWaitConfig() : WaitTime(0), WaitTimeOut(0), CheckGameTime(0), StartTime(0), BrandTime(0), CompareCardTime(0), RelieveTime(0), ShowDownTime(0), WaitNextTime(0)
    {}
};

// ������Ϸ����ʱ������
struct ChessStateWaitConfig
{
    uint32 WaitTime;           // �ȴ�ʱ��;
    uint32 WaitTimeOut;        // �ȴ���ʱʱ��;
    uint32 CheckGameTime;      // �����Ϸ��ʼ��ʱ��;
    uint32 StartTime;          // ��ʼʱ��;
    uint32 ActionTimeOne;      // ��Ҳ���ʱ��1
    uint32 ActionTimeTwo;      // ��Ҳ���ʱ��2
    uint32 RelieveTime;        // ��ɢ����ʱ��;
    uint32 ShowDownTime;       // ����ʱ��;
    uint32 RegretChessTime;    // ����ʱ��;
    uint32 AskPeaceTime;       // ���ʱ��;
    uint32 InningsTime;        // ��ʱ;
	uint32 ViolationTime;	   // ˼��Υ��ʱ��;
	uint32 ThinkOutTime;	   // ˼����ʱʱ��;
    ChessStateWaitConfig() 
    {
        memset(this, 0, sizeof(ChessStateWaitConfig));
    }
};

struct GanDengYanStateWaitConfig
{
	uint32 WaitTime;           // �ȴ�ʱ��;
	uint32 WaitTimeOut;        // �ȴ���ʱʱ��;
	uint32 CheckGameTime;      // �����Ϸ��ʼ��ʱ��;
	uint32 StartTime;          // ��ʼʱ��;
	uint32 BrandTime;          // ��������ʱ��;
	uint32 AddPourTime;        // ��עʱ��;
	uint32 SelectHandTime;     // ѡ�����Ƹ���ʱ��;
	uint32 ShowHandTime;       // ̯��ʱ��;
	uint32 RelieveTime;        // ��ɢ����ʱ��;
	uint32 ShowDownTime;       // ����ʱ��;
	std::map <uint32, uint32> m_CardType_Multi;  // ���ͱ���

	uint32 TestCardPoolOpen;
	std::string PoolCardStr;
	std::vector<uint8> PoolCards;

	GanDengYanStateWaitConfig() : WaitTime(0), WaitTimeOut(0), CheckGameTime(0), StartTime(0), BrandTime(0),
		AddPourTime(0), SelectHandTime(0), ShowHandTime(0), RelieveTime(0), ShowDownTime(0),TestCardPoolOpen(0)
	{}
};


struct Reward
{
    uint32                  time;
    uint32                  bind_facebook;
    uint32                  tips_max;
    uint32                  roulette_money_time;
    uint32                  roulette_rate_cost; // ת�����������Ż�ȯ;
};


struct GameRecordConfigInfo
{
    uint32 RecordCount;
    uint32 RecordTimeOut;
    uint32 RecordTimer;
};

struct FreeMoneyConfigXml
{
    uint32                  count;
    uint32                  money;
    uint32                  limit_give_out;
    uint32                  bonus_money;
    uint32                  bonus_time;
    uint32                  bonus_day_max_cnt;

    FreeMoneyConfigXml( void ) 
        : count ( 0 )
        , money ( 0 )
        , limit_give_out( 0 )
        , bonus_money ( 0 )
        , bonus_time( 0 )
        , bonus_day_max_cnt( 0 )
    {

    }
};

struct ShareRewardConfigXml
{
    uint32                   share_reward_time;
    uint32                   share_reward_day_max_cnt;
    std::vector<ItemEntity>  share_reward_item_list;

    ShareRewardConfigXml( void ) 
        : share_reward_time ( 0 )
        , share_reward_day_max_cnt ( 0 )
    {
        share_reward_item_list.clear();
    }
};

struct BindFriendConfig
{
    uint32              bind_src_reward;
    uint32              play_src_reward;
    uint32              bind_max;
    uint32              dst_bind_reward;
    uint32              dst_need_play_count;
    uint32              dst_play_reward;
    uint32              reward_item_id;
    uint32              reward_need_create_time;

    BindFriendConfig( void )
        : bind_src_reward( 0 )
        , play_src_reward( 0 )
        , bind_max( 0 )
        , dst_bind_reward( 0 )
        , dst_need_play_count( 0 )
        , dst_play_reward( 0 )
        , reward_item_id( 0 )
        , reward_need_create_time( 0 )
    {

    }
};

struct FriendTissueConfigXml
{
    uint32                   normal_create_limit;
    uint32                   vip_create_limit;
    uint32                   join_limit;
    uint64                   vip_default_money;
    uint64                   vip_default_limit;
    uint32                   name_limit;
    uint32                   infinit_limit_num;
    ItemEntity               create_normal_cost_item;
    ItemEntity               create_vip_cost_item;

    FriendTissueConfigXml( void ) 
        : normal_create_limit ( 0 )
        , vip_create_limit ( 0 )
        , join_limit ( 0 )
        , vip_default_money ( 0 )
        , vip_default_limit ( 0 )
        , name_limit ( 0 )
        , infinit_limit_num ( 0 )
    {
        create_normal_cost_item.item_tid = 0;
        create_normal_cost_item.item_num = 0;
        create_vip_cost_item.item_tid = 0;
        create_vip_cost_item.item_num = 0;
    }

    uint32 GetCostItem( bool State )
    {
        return State ? create_vip_cost_item.item_tid : create_normal_cost_item.item_num;
    }
    uint32 GetCostItemNum( bool State )
    {
        return State ? create_vip_cost_item.item_num : create_normal_cost_item.item_num;
    }
};

//   �ܵÿ� ���ñ��е����ݽṹ begin
struct RunFastStateWaitConfig
{
    RunFastStateWaitConfig()
    {
        memset( this , 0 , sizeof( RunFastStateWaitConfig ) );
    }

    uint32 WaitTime;           // �ȴ�ʱ��;
    uint32 WaitTimeOut;        // �ȴ���ʱʱ��;
    uint32 CheckGameTime;      // �����Ϸ��ʼ��ʱ��;
    uint32 StartTime;          // ��ʼʱ��;
    uint32 BrandTime;          // ��������ʱ��;
    uint32 ActionTime;         // ���ɻʱ��;
    uint32 OutCardTime;        // ����ʱ��;
    uint32 ShowDwonTime;       // ��Ϸ��ʼ����ʱ��;
    uint32 Relievetime;        // ��ɢ����ʱ��;
    uint32 TrustTime;          // �й�ʱ��;
    uint32 Integral;           // ���������;
    uint32 MachineTime;        // ����һ���ʱ��
    uint32 MSGRoomMaxTime;     // �����˶��᷿�������ʱ��
};

//   ������ ���ñ��е����ݽṹ 
struct DDZStateWaitConfig
{
    DDZStateWaitConfig() : WaitTime(0), WaitTimeOut(0), CheckGameTime(0), StartTime(0), BrandTime(0), ActionTime(0), OutCardTime(0)
        ,ShowDwonTime(0), Relievetime(0), TrustTime(0), QiangDiZhuAdd(0), MingPaiStartAdd(0), DiZhuMingPaiAdd(0), ZhaDanAdd(0), ChunTianAdd(0)
        , AddTimes(0),Integral(0), BaseScore(0)
    {
        DiPaiAddTime.clear();
    }

    uint32 WaitTime;           // �ȴ�ʱ��;
    uint32 WaitTimeOut;        // �ȴ���ʱʱ��;
    uint32 CheckGameTime;      // �����Ϸ��ʼ��ʱ��;
    uint32 StartTime;          // ��ʼʱ��;
    uint32 BrandTime;          // ��������ʱ��;
    uint32 ActionTime;         // ���ɻʱ��;
    uint32 OutCardTime;        // ����ʱ��;
    uint32 ShowDwonTime;       // ��Ϸ��ʼ����ʱ��;
    uint32 Relievetime;        // ��ɢ����ʱ��;
    uint32 TrustTime;          // �й�ʱ��;
    uint32 QiangDiZhuAdd;      // ����������
    uint32 MingPaiStartAdd;    // ���ƿ�ʼ����
    uint32 DiZhuMingPaiAdd;    // �������Ʊ���
    uint32 ZhaDanAdd;          // ը������
    uint32 ChunTianAdd;        // ���챶��
    uint32 AddTimes;           // �ӱ�����
    uint32 Integral;           // ���������;

    DEF::SCORE BaseScore;          // ������
    std::map<uint32, uint32> DiPaiAddTime;   // ���ƶ�Ӧ�ı���
};

//   ��ʮ�� ���ñ��е����ݽṹ;
struct DouSiSiStateWaitConfig
{
    DouSiSiStateWaitConfig()
    {
        memset( this , 0 , sizeof( DouSiSiStateWaitConfig ) );
    }

    uint32 WaitTime;           // �ȴ�ʱ��;
    uint32 WaitTimeOut;        // �ȴ���ʱʱ��;
    uint32 CheckGameTime;      // �����Ϸ��ʼ��ʱ��;
    uint32 StartTime;          // ��ʼʱ��;
    uint32 BrandTime;          // ��������ʱ��;
    uint32 ActionTime;         // ���ɻʱ��;
    uint32 OutCardTime;        // ����ʱ��;
    uint32 ShowDwonTime;       // ��Ϸ��ʼ����ʱ��;
    uint32 Relievetime;        // ��ɢ����ʱ��;
    uint32 TrustTime;          // �й�ʱ��;
    uint32 HandMendFlowerTime; // ���Ʋ���;
    uint32 AholdMendFlowerTime;// ץ�Ʋ���;
    uint32 FanCardTime;        // ����;
};

//   ��ʮ�� ���ñ��е����ݽṹ;
struct PengHuStateWaitConfig
{
    PengHuStateWaitConfig()
    {
        memset( this , 0 , sizeof( PengHuStateWaitConfig ) );
    }

    uint32 WaitTime;           // �ȴ�ʱ��;
    uint32 WaitTimeOut;        // �ȴ���ʱʱ��;
    uint32 CheckGameTime;      // �����Ϸ��ʼ��ʱ��;
    uint32 StartTime;          // ��ʼʱ��;
    uint32 BrandTime;          // ��������ʱ��;
    uint32 ActionTime;         // ���ɻʱ��;
    uint32 OutCardTime;        // ����ʱ��;
    uint32 ShowDwonTime;       // ��Ϸ��ʼ����ʱ��;
    uint32 Relievetime;        // ��ɢ����ʱ��;
    uint32 TrustTime;          // �й�ʱ��;
    uint32 FanCardTime;        // ����;
};
// end
struct ChallengeTime
{
    uint32                  id;                 ///     ��������+ʱ��ΨһID
    uint32                  open;				///     ��������ʱ��
    uint32                  close;              ///     ��������ʱ��
    uint32                  clear_rnk;          ///     ������а�ʱ��
    uint32                  limit_enter;        ///     ���ƽ�����Ϸʱ��;
};

struct ChallengeReward
{
    DEF::RANKING            ranking_left;			///     ���� left - right ֮������
    DEF::RANKING            ranking_right;
    float					prize_pool;             ///		���ر���
    float                   score_return_rate;      ///     ���������Ļ��ַ�����
    std::string             mail_title;
    std::string             mail_content;
    std::string             base_money;             ///     �������𣬹�ʽ 
};

struct ChallengeBuyBack
{
    uint32      buy_num;            /// ����ڼ���
    uint32      cost_money;         /// ��Ҫ���ѽ��
    uint32      buy_coin;           /// ����ĳ���
};

struct ChallengeConfig
{
    DEF::RANKING                                  m_MaxRewardRanking;
    uint32                                        m_CostMoney;
    uint32                                        m_MaxBuyBackNumber;
    uint32										  m_MaxRound;
    std::vector<ChallengeTime>                    m_ChallengeTime;
    std::vector<ChallengeReward>                  m_ChallengeReward;
    std::vector<ChallengeBuyBack>                 m_BuyBack;

    ChallengeConfig() : m_MaxRewardRanking(0), m_CostMoney(0), m_MaxBuyBackNumber(0), m_MaxRound(0)
    {}

    ChallengeTime*      GetChallengeTime( uint32 get_time );
    ChallengeTime*      GetChallengeNotClearing( uint32 get_time );
    ChallengeTime*      GetTimeConfig( uint32 cfg_id );
    ChallengeReward*    GetChallengeReward( DEF::RANKING );
    ChallengeBuyBack*   GetBuyBack( uint32 buy_num );
};

struct WatchAdsConfig
{
    uint32 ads_number;        // ���ÿ��ۿ�����;
    uint32 interval_minute;   // ÿ�ιۿ�ʱ����(����);
    uint32 money;             // �ۿ����õĽ�Ǯ;

    WatchAdsConfig():ads_number(0),interval_minute(0),money(0)
    {}
};

struct SafeboxConfigXml
{
    uint32 self_money_min;
    uint32 free_save_rate_money;
    uint32 max_save_rate_money;
    double save_rate;
};

struct InitConfigXml
{
    uint32  player_init_money;
    uint32  player_inti_rmb;
    uint32  player_head_random;
    uint32  player_fb_head;
    uint32  player_init_weapon_id;
    uint32  player_init_bullet;
    uint16  player_sex;
    std::vector<ItemEntity> player_item_list;

    InitConfigXml():player_init_money(0),
        player_head_random(0),
        player_fb_head(0),
        player_sex(0),
        player_inti_rmb(0),
        player_init_weapon_id(0),
        player_init_bullet(0)
    {
        player_item_list.clear();
    }
};

struct MailConfigXml
{
    uint32 ShowMailMaxNum;
    uint32 MailSaveTime;
    uint32 RewardMailSaveTime;
    MailConfigXml( void )
        : ShowMailMaxNum( 0 )
        , MailSaveTime(0)
        , RewardMailSaveTime(0)
    {

    }
};

struct TexaspokerRoomData
{
    std::string room_type;
    int  smallPour;
    int  largePour;
    int  autoStand;
    int  double_poll;
    int  double_time;
    int  double_time_inc;
    int  multiple;
    int  basePour;
    bool isSelfCoins;
    uint reward1;
    uint reward2;
    uint reward3;
    DEF::MONEY  possess_score;
    uint chall_min_num;
    uint chall_max_num;
    bool isRankin;

    TexaspokerRoomData( void )
        : room_type("")
        , smallPour( 0 )
        , largePour( 0 )
        , autoStand( 0 )
        , double_poll( 0 )
        , double_time( 0 )
        , double_time_inc( 0 )
        , reward1( 0 )
        , reward2( 0 )
        , reward3( 0 )
        , basePour( 0 )
        , possess_score( 0 )
        , isSelfCoins( false )
        , chall_min_num(0)
        , chall_max_num(0)
        , isRankin( false )
    {
    }

    uint rewrad( int rankin )
    {
        if      ( rankin == 1 ) return reward1;
        else if ( rankin == 2 ) return reward2;
        else if ( rankin == 3 ) return reward3;
        else                    return 0;
    }
};

struct CDKeyConfigXml
{
    uint32      id;
    DEF::MONEY  money;
    std::vector< std::pair< DEF::TEMPLATE_ID, uint32 > >     items;

    CDKeyConfigXml():id(0),money(0)
    {}
};

struct SlotsBonusItem
{
    uint32      type;
    double      value;
};

//struct SlotsBonusGameSplit
//{
//    EnumBonusGameEndType            end_type;
//    std::vector<SlotsBonusItem>     items;
//    double                          calc_score_rate;
//    std::vector<sint32>             select_count;       ///  ��ѡ�����
//    std::vector<sint32>             select_multiplier;  ///  ������Bonusͼ��������ӳ����շ�����
//};
//
//struct SlotsBonusGame
//{
//    std::vector<SlotsBonusGameSplit>    game_splits;
//};

struct GiftConfigXml
{
    uint32 tip_max;
    uint32 duration_hour;
    uint64 target_tip_max;

    GiftConfigXml():tip_max(0),duration_hour(0),target_tip_max(0)
    {}

};

struct RedEvelopeConfig
{
    DEF::MONEY money_max;
    uint32 count;
    DEF::MONEY money_min;

    RedEvelopeConfig():money_max(0),count(0),money_min(0)
    {}

};

struct ViewPlayersConfigXml
{
    uint32 view_player_num;

    ViewPlayersConfigXml( void ):view_player_num( 0 )
    {}
};

struct RenameTimeLimitConfigXml
{
    uint32 rename_time_limit;

    RenameTimeLimitConfigXml( void ):rename_time_limit( 0 )
    {}
};

struct FriendConfigXml
{
    uint32 friend_init_num;
    uint32 friend_max_num;
    FriendConfigXml( void ):friend_init_num(0),friend_max_num(0)
    {}
};

struct BindPhoneConfigXml  
{
    uint32 reward_id;
    uint32 reward_value;
    BindPhoneConfigXml( void ):reward_id(0),reward_value(0)
    {}
};

struct RankingConfigXml
{
    uint32 win_money_refresh;

    RankingConfigXml( void ) : win_money_refresh( 0 )
    {}
};

struct PushMsgData
{
    uint RandomFriendNum;
    uint PushMsgNum;
    uint MinMoney;
    uint MaxMoney;
    PushMsgData( void ) : RandomFriendNum( 0 )
        , PushMsgNum( 0 )
        , MinMoney( 0 )
        , MaxMoney( 0 )
    {
    }
};

struct FriendExpandConfig
{
    uint32                     num;
    DEF::MONEY                 need_money;
    DEF::RMB                   need_rmb;
    StaticData::FieldNeedMeta  need_items;
    FriendExpandConfig():num(0),need_money(0),need_rmb(0)
    {}
};

struct UseItemConfigData
{
    uint32    score_clear_id;  //  ��������;
    uint32    horn_id;         //  ������;

    UseItemConfigData():score_clear_id(0),horn_id(0)
    {

    }
};

struct VIPTimePlus
{
    double  shop_plus;
    double  bonus_plus;
    double  signin_plus;

    VIPTimePlus( void ) : shop_plus(1), bonus_plus(1), signin_plus(1)
    {
    }
};

struct SaleVipConfig
{
    double      shop_plus;
    double      bonus_plus;
    DEF::MONEY  reward_money;

    SaleVipConfig() : shop_plus(1), bonus_plus(1), reward_money(0)
    {
    }
};

struct BindRewardConfig  
{
    uint32 item_id;
    uint32 mobile_reward;
    uint32 idcard_reward;
    uint32 bankcard_reward;
    BindRewardConfig( void ):item_id(0),mobile_reward(0),idcard_reward(0),bankcard_reward(0)
    {}
};


struct BackRewardRegion 
{
    std::string appname;
    uint32 item_id;
    uint32 item_count;
    BackRewardRegion( void ):item_id(0),item_count(0)
    {
        appname.clear();
    }
};

struct BackRewardConfig  
{
    uint32 start;
    uint32 end;
    uint32 last;
    uint32 itemid;
    uint32 count;
    std::vector< BackRewardRegion > region_list;
    BackRewardConfig( void ):start(0),end(0),last(0),itemid(0),count(0)
    {
        region_list.clear();
    }
};

struct HttpConfigXml  
{
	uint32 type;
	HttpConfigXml( void ):type(0){}
};

struct JuHeConfigXml  
{
	std::string app_key;
	JuHeConfigXml( void )
	{
		app_key.clear();
	}
};



typedef std::map<std::string, RoomConfigXml>                            TRoomConfigXml;
typedef std::map<std::string, ChallengeConfig>                          TChallengeConfigXml;
typedef std::vector<VIPConfigXml>                                       TVIPConfigXml;
typedef std::map<uint32, CDKeyConfigXml>                                TCDKeyConfigXml;
typedef std::map<uint32, uint32>                                        TTips;
typedef std::map<std::string, BlackjackShuffle>                         TBlackjackShuffle;
typedef std::map<std::string, BlackJackCoinVal>                         TBlackJackCoinVal;

typedef std::map<std::string, HorseCoinVal>                             THorseCoinVal;
typedef std::map<std::string, FishRoomVal>                              TFishRoomVal;
typedef std::map<uint32, FishSkillVal>                                  TFishSkillVal;
typedef std::map<uint32, HorseVal>                                      THorsesVal;
//typedef std::map<DEF::ACHIEVE_ID, AchievementConfigXml>               TAchievementConfig;
typedef std::map<std::string,TexaspokerRoomData>                        TTexasPokerRoomData;
//typedef std::map<std::string, SlotsBonusGame>                           TSlotsBonusGames;
typedef std::map<std::string, std::string>                              TFormulas;
typedef std::map<uint32, PigConfigXml>                                  TPigConfigXml;
typedef std::map<std::string,std::vector<std::string> >                 TChallType;
typedef std::map<uint32,SaleVipConfig >                                 TSaleVip;
typedef std::map<std::string,std::string>                               THttpAPIXml;

struct GameConfig
{
    TRoomConfigXml                  rooms;
    TVIPConfigXml                   vip;
    BlackjackStateWaitConfig        BlackjackStateWait;
    NiuNiuStateWaitConfig           NiuNiuStateWaitTime;
    PinSanZhangStateWaitConfig      PinSanZhangStateWaitTime;
	GanDengYanStateWaitConfig       GanDengYanStateWaitTime;
	ChessStateWaitConfig            ChessWaitTime;

    TChallengeConfigXml             Challenge;
    HorseStateWaitConfig            HorseStateWait;
    HorsePlayerUpdateConfig         HorsePlayerUpdateTime;
    Reward                          timingReward;
    RunFastStateWaitConfig          RunFastStateWaite;
    DDZStateWaitConfig              DDZStateWaite;
    DouSiSiStateWaitConfig			DouShiSiStateWait;
    PengHuStateWaitConfig			PengHuStateWait;
    //TTips                           tips;
    WatchAdsConfig                  AdsConfig;
    InitConfigXml                   InitConfig;
    FreeMoneyConfigXml              FreeMoney;
    ShareRewardConfigXml            ShareReward;
    BindFriendConfig                BindFriendReward;
    FriendTissueConfigXml           FriendTissueConfig;
    TCDKeyConfigXml                 CDKey;
    MailConfigXml                   MailConfig;
    GiftConfigXml                   GiftConfig;
    RedEvelopeConfig                EvelopeConfig;
    ViewPlayersConfigXml            ViewPlayersConfig;
    RenameTimeLimitConfigXml        RenameTimeLimitConfig;
    FriendConfigXml                 FriendConfig;
    BindPhoneConfigXml				BindPhoneConfig;
    SafeboxConfigXml                Safebox;
    RankingConfigXml                Ranking;
    PushMsgData                     PushMailMsg;
    UseItemConfigData               UseItemConfig;
    VIPTimePlus                     VIPTimeMoneyPlus;
    TSaleVip                        SaleVipsConfig;
    GameRecordConfigInfo            GameRecordConfig;
    BindRewardConfig                BindReward;
    BackRewardConfig                BackReward;
    THttpAPIXml                     HttpTestAPIConfig;      // ��������;
	THttpAPIXml                     HttpWWangAPIConfig;     // ����;
	HttpConfigXml                   HttpConfig;				// Http����;
	JuHeConfigXml                   JuHeConfig;				// �ۺ���������;
};


struct TexaspokerStateTime
{
    int actionTime;
    int startPer;
    int endPer;
    int startFlop;
    int endFlop;
    int startTurn;
    int endTurn;
    int startRiver;
    int endRiver;
    int interim;
    int showDown;
    int cleanJunk;
    int closeRoom;
};

struct TexaspokerRoleData
{
    int maxNum;
    int minNum;
};

struct TexaspokerConfig
{
    TexaspokerStateTime  TexaspokerStateWait;
    TTexasPokerRoomData  TexaspokerRoom;
};

struct CollectEvent
{
    struct CollectItem
    {
        uint32      item_tid;
        uint32      item_num;
    };

    struct RndItem
    {
        uint32      weight;
        uint32      item_tid;
        uint32      item_num;
    };

    struct OutputItems
    {
        //std::string                             tri_event;
        uint32                                  cool_down;      /// ����CD
        uint32                                  out_prob;       /// ���伸��
        std::vector<RndItem>				    rnd_items;
    };

    uint32      id;
    uint32      next_id;
    uint32      duration;
    DEF::MONEY  reward_money;
    DEF::MONEY  reward_rmb;

    std::vector<CollectItem>            need_items;
    std::vector<CollectItem>            reward_items;
    std::vector<OutputItems>			out_items;

    CollectEvent() : id(0), next_id(0), duration(0), reward_money(0), reward_rmb(0)
    {}
};

typedef std::map<uint32, CollectEvent>          TCollectEvents;




#endif // static_tabel_struct_h__

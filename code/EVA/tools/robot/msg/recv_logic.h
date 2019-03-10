#ifndef recv_logic_h__
#define recv_logic_h__
#include <nel/net/message.h>
#include <nel/net/buf_net_base.h>
#include <nel/net/callback_net_base.h>
#include <nel/misc/random.h>

class CConnect;
class CClient;

typedef void (*SystemHandle)( NLNET::CMessage& );

class RecvLogic
{
public:
    typedef std::map< std::string , SystemHandle > HandleTable;

    RecvLogic( CConnect* );
    ~RecvLogic( void );

    // ������Ϣ;
    void HandleMessage( NLNET::CMessage& );

private:

    // ���������Ϣ;
    void HandleCommonError( NLNET::CMessage& );

    // �����½��Ϣ;
    void HandleLogin( NLNET::CMessage& );
    // ��������ɫ;
    void HandleCreatePlayer( NLNET::CMessage& );
    // ���������Ϣ;
    void HandlePlayerInfo( NLNET::CMessage& );
    // ����������;
    void HandleBlackJackRoomInfo( NLNET::CMessage& );
    // �����뿪����;
    void HandleLeaveRoom( NLNET::CMessage& );
    // ����ˢ�������Ϣ;
    void HandleSyncPlayerInfo( NLNET::CMessage& );
    // ������Ϸ�����а�;
    void HandleMoneyTanking( NLNET::CMessage& );
    // ����㲥��ע;
    void HandleBlackJackAddPour( NLNET::CMessage& );
    // ����㲥Ҫ��;
    void HandleBlackJackAskForCatds( NLNET::CMessage& );
    // ����㲥����;
    void HandleBlackJackSplitCard( NLNET::CMessage& ); 
    // ����㲥�����Ϣ;
    void HandleBroadcastPlyInfo( NLNET::CMessage& );
    // ������ӽ�Ǯ;
    void HandleAddMoney( NLNET::CMessage& );
    // ������ٽ�Ǯ;
    void HandleSubMoney( NLNET::CMessage& );
    // ������ȡ����;
    void HandleGetReward( NLNET::CMessage& );
    // �����������;
    void HandleChampionship( NLNET::CMessage& );
    // �����������;
    void HandlePrizePool( NLNET::CMessage& );
    // ����Ranking Room Top;
    void HandleRankingRoomTop( NLNET::CMessage& );
    // �����Լ������а�����;
    void HandleRankingMyData( NLNET::CMessage& );
    // �����յ���ͨ�ʼ�;
    void HandleReceiveCommonMail( NLNET::CMessage& );
    // ���������ʼ���������;
    void HandleRecviveRequestMail( NLNET::CMessage& );
    // ������ȡϵͳ�ʼ�����;
    void HandleSystemMailReward( NLNET::CMessage& );
    // ������ȡ��ͨ�н�����;
    void HandleCommonMailReward( NLNET::CMessage& );
    // ����ɾ����ͨ�ʼ�;
    void HandleDeleteCommonMail( NLNET::CMessage& );
    // ����ɾ��ϵͳ�ʼ�;
    void HandleDeleteSystemMail( NLNET::CMessage& );
    // ����鿴��ͨ�ʼ�;
    void HandleLookCommonMail( NLNET::CMessage& );
    // ��������б�;
    void HandleSynchFriendList( NLNET::CMessage& );
    // ������������б�;
    void HandleSynchApplyList( NLNET::CMessage& );
    // ������Ӻ���;
    void HandleAddFriend( NLNET::CMessage& );
    // ����ɾ������;
    void HandleDeleteFriend( NLNET::CMessage& );
    // ����ɾ����������;
    void HandleDeleteApplyFriend( NLNET::CMessage& );
    // ���������ϸ��Ϣ;
    void HandleFriendDetail( NLNET::CMessage& );
    // �������������ϸ��Ϣ;
    void HandleApplyDetail( NLNET::CMessage& );
    // ����������;
    void HandleRewardFriend( NLNET::CMessage& );
    // ��������;
    void HandleChatRoom( NLNET::CMessage& );
    // ���������ڴ���;
    void HandleGiveTip( NLNET::CMessage& );
    // ����ͬ�������ϸ��Ϣ;
    void HandleRoomPlayerInfo( NLNET::CMessage& );
    // �������ͳ������;
    void HandlePlayerStatisticData( NLNET::CMessage& );
    // �����������;
    void HandleInviteFriend( NLNET::CMessage& );
    // �����Facebook;
    void HandleBindFacebook( NLNET::CMessage& );
    // �����ת��;
    void HandlePullRouletteMoney( NLNET::CMessage& );
    // ����ת����;
    void HandlePullRouletteRate( NLNET::CMessage& );
    // ��������ת����;
    void HandlePullRouletteRateRMB( NLNET::CMessage& );
    // ����ת�̽���;
    void HandleRouletteGetMoney( NLNET::CMessage& );
    // �����̵���Ϣ;
    void HandleShopInfo( NLNET::CMessage& );
    // �����̵깺����;
    void HandleBuyMoney( NLNET::CMessage& );
    // �����޸�����;
    void HandlePlayerRename( NLNET::CMessage& );
    // �������������ϸ��Ϣ;
    void HandleOtherReqPlayerInfo( NLNET::CMessage& );
    // �����Լ���ϸ��Ϣ;
    void HandleSelfReqPlayerInfo( NLNET::CMessage& );
    // �����������ͳ����Ϣ;
    void HandleReqPlayerKPI( NLNET::CMessage& );
    // ��������������ȡ����;
    void HandleHallAdsDrawAward( NLNET::CMessage& );
    // �����俴�����ȡ����;
    void HandleRoomAdsDrawAward( NLNET::CMessage& );
    // ������ݸ�ע;
    void HandleCallPour( NLNET::CMessage& );
    // ������ݼ�ע;
    void HandleRaisePour( NLNET::CMessage& );
    // �����������;
    void HandleFoldCard( NLNET::CMessage& );
    // �����������;
    void HandleCheckCard( NLNET::CMessage& );
    // ������ݳ�ֵ����;
    void HandleResetCoins( NLNET::CMessage& );
    // ������ݷ�����Ϸ;
    void HandleGoBackGame( NLNET::CMessage& );
    // �����ϻ�������;
    void HandleSlotsSpin( NLNET::CMessage& );
    // �����ʼ��鿴״̬;
    void HandleCheckMailState( NLNET::CMessage& );
    // ����鿴������������;
    void HandleSynchRoomRankPlayerNum( NLNET::CMessage& );
    // ����ɾ���Ϣ;
    void HandleSynchAchievementData( NLNET::CMessage& );
    // ��������ɳɾ���Ϣ;
    void HandleSynchCompleteAchievementData( NLNET::CMessage& );
    // ����������ȡ�ɾͽ���;
    void HandleDrawAchievementReward( NLNET::CMessage& );
    // ����21��������ע;
    void HandleBlackJackResetPour( NLNET::CMessage& );
    // �����ϻ���С��Ϸ;
    void HandleSlotsBonusGameSelect( NLNET::CMessage& );
    // �����Ƽ�����;
    void HandleRecommendFriend( NLNET::CMessage& );
    // ������ݷ���㲥��Ϣ;
    void HandleTexasPokersBroadCastGameInfo( NLNET::CMessage& );
    // Slots���뷿�䣬�㲥������Ϣ;
    void HandleSlotsBroadCastGameInfo( NLNET::CMessage& );
    // ����ͬ���Ͼ��齫��Ϸ��Ϣ;
    void HandleMahjongGameInfo( NLNET::CMessage& );
    // �����Ͼ��齫����;
    void HandleMahjongOutCard( NLNET::CMessage& );
    // �����Ͼ��齫����;
    void HandleMahjongShowDown( NLNET::CMessage& );
    // ����ͬ����������;
    void HandleSynchItemData( NLNET::CMessage& );
    // ����ʹ�õ���;
    void HandleUseItem( NLNET::CMessage& );
    // ������۵���;
    void HandleSellItem( NLNET::CMessage& );
    // �����̳ǹ������;
    void HandleStoreBuyItem( NLNET::CMessage& );
    // ͬ�������б�;
    void HandleSynchBlackList( NLNET::CMessage& );
    // ������������б�;
    void HandleAddBlackList( NLNET::CMessage& );
    // �����Ƴ������б�;
    void HandleDeleteBlackList( NLNET::CMessage& );
    // ����ͬ��ͳ����Ϣ;
    void HandleSynchStatisticsData( NLNET::CMessage& );
    // ����������;
    void HandleMissionReward( NLNET::CMessage& );

private:
    HandleTable m_HandleFun;
    CConnect*   m_Connect;
    NLMISC::CRandom m_Random;
};


#endif // recv_logic_h__
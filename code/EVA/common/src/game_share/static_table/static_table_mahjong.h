#ifndef GAME_SHARE_STATIC_TABLE_MAHJONG_H
#define GAME_SHARE_STATIC_TABLE_MAHJONG_H

#include <game_share/game_def.h>

// ���״̬����ʱ��;
struct StateTimeBase
{
    uint32 WaitTime;                  // �ȴ���Ϸ;
    uint32 WaitTimeOut;               // �ȴ���Ϸ��ʱ;
    uint32 CheckStartGameTime;        // �����Ϸ��ʼ;
    uint32 StartGameTime;             // ��ʼ��Ϸ;
    uint32 ActionTime;                // ����Լ��ʱ��;
    uint32 ActionListenTime;          // ������Ʋ���ʱ��;
    uint32 ActionTrustTime;           // ����йܲ���ʱ��;
    uint32 ShowDownTime;              // ����ʱ��;
    uint32 WaitGameOver;              // ��Ϸ����;

    StateTimeBase( void )
        : StartGameTime ( 0 )
        , CheckStartGameTime( 0 )
        , WaitTime( 0 )
        , WaitTimeOut( 0 )
        , ActionTime ( 0 )
        , ActionListenTime( 0 )
        , ActionTrustTime( 0 )
        , ShowDownTime ( 0 )
        , WaitGameOver( 0 )
    {
    }
};

// �Ͼ��齫״̬ʱ��;
struct MahJongNanJingStateTime : public StateTimeBase
{
    uint32 CheckTianDiChoiceTime;     // ����û�Ȩ��;
    uint32 HandMendFlowerTime;        // ���Ʋ���ʱ��;
    uint32 AholdMendFlowerTime;       // ץ�Ʋ���ʱ��;
    uint32 MakeMoundTime;             // ҡɫ�ӱ���ƶ�;
    uint32 MakeBankerTime;            // ҡɫ�ӱ��ׯ��ʱ��;
    uint32 FirstBrandTime;            // ������ʱ��;
    uint32 WaitUserChoiceTime;        // �ȴ���Ҳ���;
    uint32 WaitSelfChoiceTime;        // �ȴ��Լ�����;
    uint32 WaitUserTrustChoiceTime;   // �ȴ��й���Ҳ���;
    uint32 WaitSelfTrustChoiceTime;   // �ȴ��й��Լ�����;
    uint32 WaitQiangGangChoiceTime;   // �ȴ��û����ܺ�����;
    uint32 WaitOutCardTime;           // �ȴ��������;
    uint32 WaitTouchCardTime;         // �ȴ��������;
    uint32 WaitBarCardTime;           // �ȴ��������;
    uint32 WaitEatCardTime;           // �ȴ��������;
    uint32 WaitAmerceTime;            // �ȴ���Ǯ���;
    uint32 WaitTouchFinishTime;       // �������;
    uint32 WaitBarFinishTime;         // �������;
    uint32 WaitEatFinishTime;         // �������;
    uint32 WaitAmerceFinishTime;      // ��Ǯ���;
    uint32 WaitRelieveTime;           // ��ɢ����;
    uint32 WaitRelieveFinishTime;     // ��ɢ�������;
    uint32 WaitZiMoHuTime;            // ��������;
    uint32 WaitDianPaoHuTime;         // ���ں���;
    uint32 WaitLiuJuHuTime;           // ���ֺ���;
    uint32 WaitQiangGangHuTime;       // ���ܺ���;
    uint32 WaitDaBarKaiHuaHuTime;     // ��ܿ�������;
    uint32 WaitPengDuiHuTime;         // ���Ժ���;
    uint32 WaitZiMoMengTime;          // ��������;
    uint32 WaitCathenTime;            // ��עˢ��;
    uint32 WaitContract;			  // �а�ˢ��;
    uint32 WaitAutoOutCardTime;		  // �Ԅӳ��ƕr�g;
    uint32 WaitVirtualTime;           // ������ʱ��;

    MahJongNanJingStateTime()
    : CheckTianDiChoiceTime(0)
    , MakeBankerTime( 0 )
    , FirstBrandTime( 0 )
    , WaitUserChoiceTime( 0 )
    , WaitSelfChoiceTime( 0 )
    , WaitUserTrustChoiceTime( 0 )
    , WaitSelfTrustChoiceTime( 0 )
    , WaitQiangGangChoiceTime( 0 )
    , WaitOutCardTime( 0 )
    , WaitTouchCardTime( 0 )
    , WaitBarCardTime( 0 )
    , WaitEatCardTime( 0 )
    , WaitAmerceTime( 0 )
    , WaitTouchFinishTime( 0 )
    , WaitBarFinishTime( 0 )
    , WaitEatFinishTime( 0 )
    , WaitAmerceFinishTime( 0 )
    , WaitRelieveTime( 0 )
    , WaitRelieveFinishTime( 0 )
    , WaitZiMoHuTime( 0 )
    , WaitDianPaoHuTime( 0 )
    , WaitLiuJuHuTime( 0 )
    , WaitQiangGangHuTime( 0 )
    , WaitDaBarKaiHuaHuTime( 0 )
    , WaitPengDuiHuTime( 0 )
    , WaitZiMoMengTime( 0 )
	, WaitContract( 0 )
	, WaitAutoOutCardTime( 0 )
    , WaitVirtualTime( 0 )
    {

    }
};

//  �Ͼ��齫��������;
struct MahJongRoomData
{
    TGameRoomKind Kind;    // ��Ϸ����;
    uint32 FlowerNum;        // ����Ӳ����;
    uint32 DaGangKaiHua;     // ��ܿ���;
    uint32 FlowerScoreMoney; // Ӳ���һ�����;
    uint32 BaseFlower;       // �׻�;
    uint32 BaseScore;        // �׷�
    int    WinScore;         // ʤ������;
    int    LostScore;        // ʧ�ܻ���;
    int    FlatScore;        // ƽ����;
    int    LeiBaoTaCount;    // �ݱ�������;
    int    LeiBaoTaScore;    // �ݱ�������;
    MahJongRoomData( void ) : FlowerNum( 0 )
                            , DaGangKaiHua( 0 )
                            , FlowerScoreMoney( 0 )
                            , BaseFlower( 0 )
                            , WinScore( 0 )
                            , LostScore( 0 )
                            , FlatScore( 0 )
                            , LeiBaoTaCount( 0 )
                            , LeiBaoTaScore( 0 )
                            , BaseScore(0)
                            , Kind( TGD_NORMAL )
    {

    }
};

// �Ͼ�������;
struct MahJongMildFlowerScore
{
    uint32 RateValue;
    uint32 SidesPeng;
    uint32 SidesMingGang;
    uint32 SidesAnGang;
    uint32 NormalMingGang;
    uint32 NormalAnGang;
    uint32 QueYiMen;
    uint32 YaDang;
    uint32 DuDiao;
    uint32 HandFengTou;
    MahJongMildFlowerScore( void ) : RateValue( 0 )
                                   , SidesPeng( 0 )
                                   , SidesMingGang( 0 )
                                   , SidesAnGang( 0 )
                                   , NormalMingGang( 0 )
                                   , NormalAnGang( 0 )
                                   , QueYiMen( 0 )
                                   , YaDang( 0 )
                                   , DuDiao( 0 )
                                   , HandFengTou( 0 )
    {
        memset( this , 0 , sizeof( MahJongMildFlowerScore ) );
    }
};

// ���ƻ���;
struct MahJongHuScore
{
    uint32 FlowerValue;
    std::vector<uint> FlowerList;
    MahJongHuScore( void ) : FlowerValue( 0 )
    {
        FlowerList.clear();
        FlowerList.resize( 3 );
    }
};

// ���ܻ���;
struct MahJongKaiGangScore
{
    uint32 MingGangScore;
    uint32 AnGangScore;
    uint32 FlowerGangScore;
    uint32 HuiPiMBarScore;
    uint32 HuiPiABarScore;
	uint32 HuiABarScore;
	uint32 HuiMBarScore;
    MahJongKaiGangScore( void )
    {
        memset( this , 0 , sizeof( MahJongKaiGangScore ) );
    }
};

// ��������;
struct MahJongOtherScoreData
{
    uint32 Param1;
    uint32 Param2;
    MahJongOtherScoreData( void )
    {
        memset( this , 0 , sizeof( MahJongOtherScoreData ) );
    }
};

// �������;
struct MahJongAmerceScore
{
    uint OutCardScore;
    uint WithCardScore;
    uint SeriesCardScore;
    MahJongAmerceScore( void )
    {
        memset( this , 0 , sizeof( MahJongAmerceScore ) );
    }
};

// ������;
struct FlowerSubsection
{
    uint        ID;
    uint        FlowerNum;
    DEF::MONEY  MinMoney;
    DEF::MONEY  MaxMoney;
    FlowerSubsection( void )
    {
        memset( this , 0 , sizeof( FlowerSubsection ) );
    }
};

// �����������ĵ���;
struct CreatePrivateConsumeItem
{
    uint32              ID;
    uint32              GameCount;
    uint32              ConsumeItemNum;
    DEF::TEMPLATE_ID    GoldItemID;
    DEF::TEMPLATE_ID    SilverItemID;
    uint32              RatioValue;
    uint32              AllIntegral;
    uint32              OwnerIntegral;
    CreatePrivateConsumeItem( void )
    {
        memset( this , 0 , sizeof( CreatePrivateConsumeItem ) );
    }

    DEF::TEMPLATE_ID GetConsumeItemID( TGameConsumePay Kind )
    {
        return ( Kind == TGC_GOLD ) ? GoldItemID : SilverItemID;
    }
};

// �������;
struct PakcCardScore
{
    int Score;
};

struct WinIntegral
{
    uint32 Integral;
};

// ״ִ̬�д���;
struct MahJongStateCount
{
	int CheckStartGame;
    int CheckShowDownEochGame;
    int CheckGameOverEochGame;

    MahJongStateCount( void )
        : CheckStartGame( 0 )
        , CheckShowDownEochGame( 0 )
        , CheckGameOverEochGame( 0 )
    {

    }
};

struct MahJongCardPool
{
    std::vector< std::vector<uint8> > HandCardPool;
    std::vector< uint8 >              CardPool;
    MahJongCardPool( void )
    {
        ResetData();
    }
    void ResetData( void )
    {
        HandCardPool.clear();
        HandCardPool.resize(4);
        CardPool.clear();
    }
    uint8 SwitchToCard( uint8 Value )
    {
        // ������;
        if ( Value >= 1 && Value <= 9 )     { return Value; }
        // ������;
        if ( Value >= 21 && Value <= 29 )   { return ( Value - 4 ); }
        // Ͱ����;
        if ( Value >= 11 && Value <= 19 )   { return ( Value + 22 ); }
        // ��������;
        if ( Value >= 31 && Value <= 34 )   { return ( Value + 18 ); }
        // �з���;
        if ( Value >= 35 && Value <= 37 )   { return ( Value + 18 ); }
        // �����ﶬ÷�����;
        if ( Value >= 41 && Value <= 48 )   { return ( Value + 24 ); }
        return 0;
    }
}; 

class MahJongConfig : public NLMISC::CSingleton<MahJongConfig>
{
public:
    MahJongConfig( void );
   ~MahJongConfig( void );

    //   ��������;
    void ResetData( void );
    //   ���ر�;
    bool LoadConfig( void );
    //   �����齫����;
    bool LoadMahJongPool( void );
    //   ���ػ�����;
    bool LoadFlowerSubsection( void );

    ///                            ��ȡ������;
    uint                           GetFlowerSubsection( DEF::MONEY );
    ///                            ��ȡ��С��;
    uint                           GetMinFlowerMoney( void );
    ///                            ��ȡ��������;
    MahJongRoomData*               GetMahJongRoomData( std::string );
    ///                            ��ȡ�齫���ػ���;
    MahJongCardPool&               GetMahJongCardPool( void ) { return mNanJingCardPool; }
    ///                            �����;
    MahJongAmerceScore*            GetMahJongAmerceScore( TGameRoomKind Kind );
    ///                            ��;
    MahJongMildFlowerScore*        GetMildFlowerScore( TGameRoomKind Kind );
    ///                            �ܻ�;
    MahJongKaiGangScore*           GetMahJongKaiGangScore( TGameRoomKind Kind );
    ///                            ��ȡ�Ͼ��齫״̬ʱ��;
    MahJongNanJingStateTime*       GetMahJongNanJingStateTime( TGameRoomKind Kind );
    ///                            ��ȡ�齫��������;
    MahJongOtherScoreData*         GetMahJongOtherScore( TGameRoomKind Kind );
    ///                            ���ƻ���;
    std::map<uint,MahJongHuScore>& GetHuScoreData( void ) { return mMahJongHuData; }
    ///                            ��ȡ����˽�˷���������;
    //CreatePrivateConsumeItem*      GetCreateConsumeItem( uint );
    ///                            ���ƻ���;
    PakcCardScore&                 GetPackCardScore( void ) { return m_PackCardScore; }
    ///                            ״ִ̬�д���;
    MahJongStateCount&             GetStateCount( void )    { return m_MahJongStateCount; }
    ///                            ��Ӯ�Ҽӻ���;
    WinIntegral&                   GetWinIntegral( void ) { return m_WinIntegral; }
private:
    MahJongCardPool         mNanJingCardPool;
    std::map<std::string,MahJongRoomData>               mMahJongRoomData;
    std::map<uint,MahJongHuScore >                      mMahJongHuData;
    std::vector<FlowerSubsection>                       mFlowerSubsection;
    std::map<TGameRoomKind , MahJongAmerceScore  >      m_MahJongAmerceScore;
    std::map<TGameRoomKind , MahJongKaiGangScore >      m_MahJongKaiGangScore;
    std::map<TGameRoomKind , MahJongMildFlowerScore>    m_MahJongMildFlowerScore;
    std::map<TGameRoomKind , MahJongNanJingStateTime >  m_MahJongStateTime;
    std::map<TGameRoomKind , MahJongOtherScoreData   >  m_MahJongOtherScore;
    //std::map<uint,CreatePrivateConsumeItem>             m_CreatePrivateConsumeItem;
    PakcCardScore                                       m_PackCardScore;
    MahJongStateCount                                   m_MahJongStateCount;
    WinIntegral                                         m_WinIntegral;
};

#define MahJongData            MahJongConfig::instance()
#define MahJongRoom(rhs)       MahJongData.GetMahJongRoomData( rhs )
#define MahJongAmerce( rhs )   MahJongData.GetMahJongAmerceScore( rhs )
#define MahJongMildFlower(rhs) MahJongData.GetMildFlowerScore( rhs )
#define MahJongGang( rhs )     MahJongData.GetMahJongKaiGangScore( rhs )
#define MahJongCardPoolData    MahJongData.GetMahJongCardPool()
#define MahJongFlower(rhs)     MahJongData.GetFlowerSubsection(rhs)
#define MahJongStateTime(rhs)  MahJongData.GetMahJongNanJingStateTime(rhs)
#define MahJongOtherScore(rhs) MahJongData.GetMahJongOtherScore(rhs)

#endif //GAME_SHARE_STATIC_TABLE_MAHJONG_H;
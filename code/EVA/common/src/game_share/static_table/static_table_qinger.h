#ifndef GAME_SHARE_STATIC_TABLE_QINGER_H
#define GAME_SHARE_STATIC_TABLE_QINGER_H

#include <game_share/game_def.h>

// ���״̬����ʱ��;
struct QingErStateTimeBase
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

    QingErStateTimeBase( void )
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

// ���״̬ʱ��;
struct QingErStateTime : public QingErStateTimeBase
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

    QingErStateTime()
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

//  �����������;
struct QingErRoomData
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
    QingErRoomData( void ) : FlowerNum( 0 )
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

// ���������;
struct QingErMildFlowerScore
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
    QingErMildFlowerScore( void ) : RateValue( 0 )
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
        memset( this , 0 , sizeof( QingErMildFlowerScore ) );
    }
};

// ���ƻ���;
struct QingErHuScore
{
    uint32 FlowerValue;
    std::vector<uint> FlowerList;
    QingErHuScore( void ) : FlowerValue( 0 )
    {
        FlowerList.clear();
        FlowerList.resize( 3 );
    }
};

// �����ƿ�;
struct QingErTestPool
{
	uint32 TestCardPoolOpen;
	uint32 TestJianZhang;
	std::string PoolCardStr;
	std::vector<uint8> PoolCards;
	QingErTestPool( void ) : TestJianZhang( 0 ) ,TestCardPoolOpen( 0 )
	{
		PoolCards.clear();
	}
};

// ���ܻ���;
struct QingErKaiGangScore
{
    uint32 MingGangScore;
    uint32 AnGangScore;
    uint32 FlowerGangScore;
    uint32 HuiPiMBarScore;
    uint32 HuiPiABarScore;
	uint32 HuiABarScore;
	uint32 HuiMBarScore;
    QingErKaiGangScore( void )
    {
        memset( this , 0 , sizeof( QingErKaiGangScore ) );
    }
};

// ��������;
struct QingErOtherScoreData
{
    uint32 Param1;
    uint32 Param2;
    QingErOtherScoreData( void )
    {
        memset( this , 0 , sizeof( QingErOtherScoreData ) );
    }
};

// �������;
struct QingErJieSuanScore
{
    uint OutCardScore;
    //std::string ScoreName;
    QingErJieSuanScore( void )
    {
        OutCardScore = 0;
    }
};

// ������;
struct QingErFlowerSubsection
{
    uint        ID;
    uint        FlowerNum;
    DEF::MONEY  MinMoney;
    DEF::MONEY  MaxMoney;
    QingErFlowerSubsection( void )
    {
        memset( this , 0 , sizeof( QingErFlowerSubsection ) );
    }
};

// �����������ĵ���;
struct QingErCreatePrivateConsumeItem
{
    uint32              ID;
    uint32              GameCount;
    uint32              ConsumeItemNum;
    DEF::TEMPLATE_ID    GoldItemID;
    DEF::TEMPLATE_ID    SilverItemID;
    uint32              RatioValue;
    uint32              AllIntegral;
    uint32              OwnerIntegral;
    QingErCreatePrivateConsumeItem( void )
    {
        memset( this , 0 , sizeof( QingErCreatePrivateConsumeItem ) );
    }

    DEF::TEMPLATE_ID GetConsumeItemID( TGameConsumePay Kind )
    {
        return ( Kind == TGC_GOLD ) ? GoldItemID : SilverItemID;
    }
};

// �������;
struct QingErPakcCardScore
{
    int Score;
};

struct QingErWinIntegral
{
    uint32 Integral;
};

// ״ִ̬�д���;
struct QingErStateCount
{
	int CheckStartGame;
    int CheckShowDownEochGame;
    int CheckGameOverEochGame;

    QingErStateCount( void )
        : CheckStartGame( 0 )
        , CheckShowDownEochGame( 0 )
        , CheckGameOverEochGame( 0 )
    {

    }
};

struct QingErCardPool
{
    std::vector< std::vector<uint8> > HandCardPool;
    std::vector< uint8 >              CardPool;
    QingErCardPool( void )
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

class QingErConfig : public NLMISC::CSingleton<QingErConfig>
{
public:
    QingErConfig( void );
   ~QingErConfig( void );

    //   ��������;
    void ResetData( void );
    //   ���ر�;
    bool LoadConfig( void );
    //   �����齫����;
    bool LoadQingErPool( void );
    //   ���ػ�����;
    bool LoadFlowerSubsection( void );

    ///                            ��ȡ������;
    uint                           GetQEFlowerSubsection( DEF::MONEY );
    ///                            ��ȡ��С��;
    uint                           GetMinFlowerMoney( void );
	///                            ��ȡ�����ƿ�����;
	QingErTestPool&                GetQingErTestPool();
	///                            ��ȡ�������;
	std::map<uint32 , QingErJieSuanScore >     GetQingErScore();
    ///                            ��ȡ�齫���ػ���;
    QingErCardPool&                GetQingErCardPool( void ) { return mQingErCardPool; }
    ///                            ��;
    QingErMildFlowerScore*         GetQEMildFlowerScore( TGameRoomKind Kind );
    ///                            ��ȡ���״̬ʱ��;
    QingErStateTime*               GetQingErStateTime( TGameRoomKind Kind );
    ///                            ��ȡ�齫��������;
    QingErOtherScoreData*          GetMahJongOtherScore( TGameRoomKind Kind );
    ///                            ״ִ̬�д���;
    QingErStateCount&              GetStateCount( void )    { return m_QingErStateCount; }
private:
    QingErCardPool         mQingErCardPool;
    std::vector<QingErFlowerSubsection>                mFlowerSubsection;
    std::map<TGameRoomKind , QingErKaiGangScore >      m_QingErKaiGangScore;
    std::map<TGameRoomKind , QingErStateTime >         m_QingErStateTime;
    QingErStateCount                                   m_QingErStateCount;
	QingErTestPool                                     m_QingErTestPool;
	std::map<uint32 , QingErJieSuanScore >             m_QingErScore;
};

#define QingErData            QingErConfig::instance()
#define QingErMildFlower(rhs) QingErData.GetQEMildFlowerScore( rhs )
#define QingErStateTime(rhs)  QingErData.GetQingErStateTime(rhs)
#define QingErTestPool()      QingErData.GetQingErTestPool()
#define QingErStaticScore()         QingErData.GetQingErScore()


#endif //GAME_SHARE_STATIC_TABLE_QINGER_H;
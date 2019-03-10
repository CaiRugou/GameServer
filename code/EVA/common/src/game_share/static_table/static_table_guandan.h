#ifndef GAME_SHARE_STATIC_TABLE_GUANDAN_H
#define GAME_SHARE_STATIC_TABLE_GUANDAN_H

#include "static_tabel_struct.h"
// �走״̬ʱ��;
struct GuanDanStateTime
{
    uint32 WaitTime;           // �ȴ�ʱ��;
    uint32 WaitTimeOut;        // �ȴ���ʱʱ��;
    uint32 StartTime;          // ��ʼʱ��;
    uint32 CheckStartTime;     // ��鿪ʼʱ��;
    uint32 BankerTime;         // ���ׯ��ʱ��;
    uint32 BrandTime;          // ��������ʱ��;
    uint32 SendGiftTime;       // ����ʱ��;
    uint32 RecvGiftTime;       // �ع�ʱ��;
    uint32 SendGiftFinishTime; // �������ʱ��;
    uint32 RecvGiftFinishTime; // �ع����ʱ��;
    uint32 ActionTime;         // ���ɻʱ��;
    uint32 OutCardTime;        // ����ʱ��;
    uint32 ShowDwonTime;       // ��Ϸ��ʼ����ʱ��;
    uint32 EndTime;            // �˳���Ϸ����ʾ����㣩ʱ��
    uint32 RelieveTime;        // ��ɢ����ʱ��
    uint32 AutoCardTime;       // �Զ�����ʱ��
    uint32 TrustTime;          // �����й�ʱ��
    uint32 AutoSendGiftTime;   // �Զ�����ʱ��
    uint32 AutoPassCardTime;   // �Զ�����ʱ��
    uint32 MSGGameMaxTime;     // �����˶�����Ϸ���ʱ�䣬�������ʱ����Ϸ�����
    uint32 MSGRoleMachineTime; // �����˶��ᣬ����йܽ���һ�״̬ʱ�䣬�����һ����ҽ������״̬����Ϸ����������Ҳ��ӷ�

    GuanDanStateTime( void )
    {
        memset( this , 0 , sizeof( GuanDanStateTime ) );
    }
};

// ��������;
struct GuanDanResistInfo
{
    uint32 CardValue;
    uint32 CardCount;
    GuanDanResistInfo( void )
    {
        memset( this , 0 , sizeof( GuanDanResistInfo ) );
    }
};

// ��ɽ���;
struct GuanDanRewardRole
{
    uint32 GameCount;
    uint32 RewardMoney;
    uint32 RewardRmb;
    std::vector< ItemEntity > RewardItem;
    GuanDanRewardRole( void )
        : GameCount( 0 )
        , RewardMoney( 0 )
        , RewardRmb( 0 )
    {
        RewardItem.clear();
    }
};

// �走����
struct GuanDanCardPool 
{
    std::vector< std::vector<uint8> > HandCardPool;		// �����б�һ�����ĸ�����������ĸ���Ϊ�Ƿ�

    GuanDanCardPool( void )
    {
        ResetData();
    }

    void ResetData( void )
    {
        HandCardPool.clear();
    }

    // ת�����߻���д���Ʋ���CardList�е�ֵ
    uint8 SwitchToCardValue( NLMISC::CSString& );

    // ��������
    bool LoadCardConfig( void );

    // �ж��Ƿ��ǺϷ�������
    bool IsValidConfig( void ) const;
};

// ��������
struct GuanDanReduceSeries
{
    uint32 ReduceSeries;

    GuanDanReduceSeries()
    {
        memset( this , 0 , sizeof( GuanDanReduceSeries ) );
    }
};

// ״ִ̬�д���;
struct GuandanStateCount
{
    int CheckStartGame;
    int CheckShowDownEochGame;
    int CheckGameOverEochGame;
    
    GuandanStateCount( void )
        : CheckStartGame( 0 )
        , CheckShowDownEochGame( 0 )
        , CheckGameOverEochGame( 0 )
    {

    }
};


class CGuanDanConfig : public NLMISC::CSingleton<CGuanDanConfig>
{
public:
     CGuanDanConfig( void );
    ~CGuanDanConfig( void );

    //   ��������;
    void ResetData( void );
    //   ���ر�;
    bool LoadConfig( void );

    //   ��ȡ״̬����ʱ��;
    const GuanDanStateTime&  GetStateTime( void ) const  { return mGuanDanStateTime; }
    //   ��ȡ������Ϣ;
    const GuanDanResistInfo& GetResistInfo( void ) const { return mGuanDanResistInfo; }
    //   ��ȡʮ������;
    const GuanDanRewardRole& GetRewardRole( void ) const { return mGuanDanRewardRole; }

    const GuanDanCardPool& GetGuanDanCardPool( void )    { return mGuanDanCardPool; }

    const GuandanStateCount& GetStateCount()             { return mGuandanStateCount;}
    //   ��ȡ������Ϣ
    const GuanDanReduceSeries& GetReduceSeries( void )   { return mGuandanReduceSeries; }

    //   ��ȡ��ʦ��

private:
    GuanDanStateTime        mGuanDanStateTime;
    GuanDanResistInfo       mGuanDanResistInfo;
    GuanDanRewardRole       mGuanDanRewardRole;
    GuanDanCardPool         mGuanDanCardPool;
    GuandanStateCount       mGuandanStateCount;
    GuanDanReduceSeries     mGuandanReduceSeries;
};

#define GuanDanConfig  CGuanDanConfig::instance()

#endif // GAME_SHARE_STATIC_TABLE_GUANDAN_H;
#ifndef CPlayerItem_h__
#define CPlayerItem_h__

#include <game_share/game_def.h>
#include <server_share/database/db_logic_chunk.h>
#include <game_share/proto_msg/mail_pro.pb.h>
#include <nel/misc/random.h>

class CPlayerItem
{
public:
    CPlayerItem( void );
    virtual ~CPlayerItem( void );

    // �����������;
    void OnSavePlayerItem( MsgItemCont& );

    // ɾ������;
    void OnDeleteItem( DEF::ITEM_ID );

    // ɾ������;
    void OnDeleteItem( DEF::TEMPLATE_ID );

    // �����۳�����;
    void OnUpdateSellItem( MsgSellItemUpdate& );

    // �������ĵ���;
    void OnUpdateUseItem( MsgUseItemUpdate& );

    // �����̳ǹ������;
    void OnUpdateBuyItem( MsgStoreBuyItemInfo& );

    // �����ʼ�����;
    void OnUpdateMailItem( MsgGainReward& );

    // ��������������;
    void OnUpdateMissionRewardItem( MsgMissionReward& );

    // ����ǩ������;
    //void OnUpdatCheckinItem( MsgReward& );

    //// ����Ӣ����������;
    //void OnUpdateHeroUpLevelItem( MsgUpdateHero& );
    //// ����Ӣ�۾�����������;
    //void OnUpdateHeroExpUp( MsgUseExpUpdate& );
    //// ����Ӣ��װ������;
    //void OnUpdateHeroEquip( MsgUpdateMeta& );
    //// ����Ӣ�ۼ�����������;
    //void OnUpdateHeroSkillLevel( MsgHeroSkillUpRes& );
    //// ��������̵����;
    //void OnUpdateRandomShopItem( MsgBuyItemResult& );
    //// ���������Ƭ����;
    //void OnUpdateRandomCardItem( MsgCardAward& );
    //// ����PVE��������;
    //void OnUpdateItemPvE( MsgPvELeaveRes& );
    //// ����PVP��������;
    //void OnUpdateItemPvP( MsgPvPLeaveRes& );
    //// ���¸����������;
    //void OnUpdateDupDropItem( MsgBattleEndRes& );

    // ��ȡ����;
    DB_RECORD::CRecordItem* GetItem( DEF::TEMPLATE_ID );

    // ��ȡ�������;
    DB_RECORD::CRecordItem* GetRandomItem( void );
    // ��ȡ�۳�����;
    DB_RECORD::CRecordItem* GetSellItem( void );
    // ��ȡ���ĵ���;
    //DB_RECORD::CRecordItem* GetConsumeItem( void );
    // ��ȡ�������;
    //DB_RECORD::CRecordItem* GetUseExpItem( void );

    // ���µ���;
    void OnUpdateItem( std::vector< MsgItem >& data );
private:

protected:
    // ��������;
    DB_RECORD::TRecordItem   m_ItemData;
    // ���;
    NLMISC::CRandom          m_Random;
};

#endif // CPlayerItem_h__
#ifndef GSE_ITEM_MANAGER_H_
#define GSE_ITEM_MANAGER_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CItemManager : public NLMISC::CSingleton< CItemManager >
{
public:
    ///  ��ӵ���;
    bool AddItem( ROLE_ID , ITEM_ID , uint32 , PB_DotItem );
    ///  �۳�����;
    bool SubItem( ROLE_ID , ITEM_ID , uint32 , PB_DotItem );

    ///  ��ȡ��������;
    uint32  GetItemCount( ROLE_ID , ITEM_ID );

private:
    ///  ��ȡ������Ϣ;
    CRecordItem* GetItemInfo( ROLE_ID , ITEM_ID , bool IsAdd = false );
};

#define ItemManager CItemManager::getInstance();

GSE_NAMESPACE_END_DECL

#endif//GSE_ITEM_MANAGER_H_
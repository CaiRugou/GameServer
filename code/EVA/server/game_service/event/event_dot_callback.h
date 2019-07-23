#ifndef GSE_EVENT_DOT_CALLBACK_H_
#define GSE_EVENT_DOT_CALLBACK_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CEventDotCallBack : public sigslot::has_slots<> , public NLMISC::CSingleton< CEventDotCallBack >
{
public:
    void InitEventCallBack( void );

private:
    void CallBackPlyaerLoginFinish  ( PB_UserLogin& );                                      // �û���¼�¼�;
    void CallBackPlayerOffline      ( ROLE_ID );                                            // �û������¼�;
    void CallBackAddItem            ( ROLE_ID , ITEM_ID , uint32 , uint32 , PB_DotItem );   // �û���ӵ���;
    void CallBackSubItem            ( ROLE_ID , ITEM_ID , uint32 , uint32 , PB_DotItem );   // �û��ۼ�����;
};

#define EventDotCallBack CEventDotCallBack::getInstance()

GSE_NAMESPACE_END_DECL

#endif//GSE_EVENT_DOT_CALLBACK_H_
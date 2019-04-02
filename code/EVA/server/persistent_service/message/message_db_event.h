#ifndef PSE_MESSAGE_DB_EVENT_H_
#define PSE_MESSAGE_DB_EVENT_H_

#include <persistent_service/persistent_service/persistent_service_def.h>

PSE_NAMESPACE_BEGIN_DECL

// ���½�ɫ����;
void CallBack_Event_Player( NLNET::CMessage&, const std::string&, NLNET::TServiceId );
// ���µ�������;
void CallBack_Event_Item( NLNET::CMessage&, const std::string&, NLNET::TServiceId  );
// ����ͳ������;
void CallBack_Event_Statistics( NLNET::CMessage& , const std::string& , NLNET::TServiceId );
// ������������;
void CallBack_Event_Mission( NLNET::CMessage& , const std::string& , NLNET::TServiceId );

// ע����Ϣ;
static NLNET::TUnifiedCallbackItem PSE_DB_CallBackItems[] =
{
    { "MSG_DB_PLAYER"       ,         CallBack_Event_Player         },
    { "MSG_DB_ITEM"         ,         CallBack_Event_Item           },
    { "MSG_DB_STATISTICS"   ,         CallBack_Event_Statistics     },
    { "MSG_DB_MISSION"      ,         CallBack_Event_Mission        },
};

PSE_NAMESPACE_END_DECL

#endif //PSE_MESSAGE_DB_EVENT_H_
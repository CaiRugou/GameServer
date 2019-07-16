#ifndef SSE_MESSAGE_ROOM_H_
#define SSE_MESSAGE_ROOM_H_

#include <schedule_service/schedule_service/schedule_service_def.h>

SSE_NAMESPACE_BEGIN_DECL

//   ͳ�Ʒ�����Ϣ;
void CallBack_RegisterRoomInfo( NLNET::CMessage&, const std::string&, NLNET::TServiceId );
//   �û���������;
void CallBack_CreateRoom( NLNET::CMessage& , const std::string& , NLNET::TServiceId );

// ע����Ϣ;
static NLNET::TUnifiedCallbackItem SSE_ROOM_CallBackItems[] =
{
    { "MSG_REGISTER_ROOM" ,                 CallBack_RegisterRoomInfo   },
    { "MSG_CREATE_ROOM"   ,                 CallBack_CreateRoom         },

};
SSE_NAMESPACE_END_DECL

#endif //SSE_MESSAGE_ROOM_H_
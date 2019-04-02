#ifndef GSE_MESSAGE_ROOM_H_
#define GSE_MESSAGE_ROOM_H_

#include <game_service/game_service/game_service.h>

GSE_NAMESPACE_BEGIN_DECL

//   �û���������;
void CallBack_CreateRoom( NLNET::CMessage& , const std::string& , NLNET::TServiceId );

//   ע����Ϣ;
static NLNET::TUnifiedCallbackItem SSE_ROOM_CallBackItems[] =
{
    { "MSG_CREATE_ROOM"   ,                 CallBack_CreateRoom         },
};

GSE_NAMESPACE_END_DECL

#endif //GSE_MESSAGE_ROOM_H_
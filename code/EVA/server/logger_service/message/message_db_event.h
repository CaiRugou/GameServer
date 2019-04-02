#ifndef LSE_MESSAGE_DB_EVENT_H_
#define LSE_MESSAGE_DB_EVENT_H_

#include <logger_service/logger_service/logger_service_def.h>

LSE_NAMESPACE_BEGIN_DECL

//   �����־;
void CallBack_DotMssage( NLNET::CMessage& , const std::string& , NLNET::TServiceId );

//   ע����Ϣ;
static NLNET::TUnifiedCallbackItem LSE_DOT_CallBackItems[] =
{
    { "MSG_DOT"        , CallBack_DotMssage     }
};

LSE_NAMESPACE_END_DECL

#endif//LSE_MESSAGE_DB_EVENT_H_
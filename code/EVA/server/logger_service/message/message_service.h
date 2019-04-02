#ifndef LSE_MESSAGE_SERVICE_H_
#define LSE_MESSAGE_SERVICE_H_

#include <logger_service/logger_service/logger_service_def.h>

LSE_NAMESPACE_BEGIN_DECL

//   ��Ϸ�������Ͽ�;
void CallBack_GSEDisconnection( const std::string& , NLNET::TServiceId , void* );
//   ���ط������Ͽ�;
void CallBack_FESDisconnection( const std::string& , NLNET::TServiceId , void* );
//   ���ȷ������Ͽ�;
void CallBack_SSEDisconnection( const std::string& , NLNET::TServiceId , void* );
//   ���ݷ������Ͽ�;
void CallBack_PSEDisconnection( const std::string& , NLNET::TServiceId , void* );

LSE_NAMESPACE_END_DECL

#endif//LSE_MESSAGE_SERVICE_H_
#ifndef PSE_MESSAGE_SERVICE_H_
#define PSE_MESSAGE_SERVICE_H_

#include <persistent_service/persistent_service/persistent_service_def.h>

PSE_NAMESPACE_BEGIN_DECL

//   ��Ϸ�������Ͽ�;
void CallBack_GSEDisconnection( const std::string& , NLNET::TServiceId , void* );
//   ���ط������Ͽ�;
void CallBack_FESDisconnection( const std::string& , NLNET::TServiceId , void* );
//   ���ȷ������Ͽ�;
void CallBack_SSEDisconnection( const std::string& , NLNET::TServiceId , void* );

PSE_NAMESPACE_END_DECL

#endif // PSE_MESSAGE_SERVICE_H_;
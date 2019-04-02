#ifndef GSE_MESSAGE_SERVICE_H_
#define GSE_MESSAGE_SERVICE_H_

#include <game_service/game_service/game_service.h>

GSE_NAMESPACE_BEGIN_DECL

//   ��Ϸ�������Ͽ�;
void CallBack_GSEDisconnection( const std::string& , NLNET::TServiceId , void* );
//   ���ط������Ͽ�;
void CallBack_FESDisconnection( const std::string& , NLNET::TServiceId , void* );
//   �洢�������Ͽ�;
void CallBack_PSEDisconnection( const std::string& , NLNET::TServiceId , void* );
//   ���ȷ������Ͽ�;
void CallBack_SSEDisconnection( const std::string& , NLNET::TServiceId , void* );

GSE_NAMESPACE_END_DECL

#endif//GSE_MESSAGE_SERVICE_H_
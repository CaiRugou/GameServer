#ifndef PSE_MESSAGE_LOGIN_H_
#define PSE_MESSAGE_LOGIN_H_

#include <persistent_service/persistent_service/persistent_service_def.h>

PSE_NAMESPACE_BEGIN_DECL

// �û���¼;
void CallBack_UserLogin( NLNET::CMessage&, const std::string&, NLNET::TServiceId  );

// ע����Ϣ;
static NLNET::TUnifiedCallbackItem PSE_LOGIN_CallBackItems[] =
{
    { "MSG_LOGIN" ,                       CallBack_UserLogin    },  // �û���¼;
};

PSE_NAMESPACE_END_DECL

#endif // PSE_MESSAGE_LOGIN_H_;
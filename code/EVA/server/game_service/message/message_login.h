#ifndef GSE_MESSAGE_LOGIN_H_
#define GSE_MESSAGE_LOGIN_H_

#include <game_service/game_service/game_service.h>

GSE_NAMESPACE_BEGIN_DECL

//   ͬ����������;
void CallBack_UserLoad( NLNET::CMessage& , const std::string& , NLNET::TServiceId );
//   �û���¼;
void CallBack_UserLogin( NLNET::CMessage&, const std::string&, NLNET::TServiceId );
//   �û�����;
void CallBack_UserOffline( NLNET::CMessage&, const std::string& , NLNET::TServiceId );
//   �л�����;
void CallBack_ChangeScenes( NLNET::CMessage&, const std::string& , NLNET::TServiceId );

//   ע����Ϣ;
static NLNET::TUnifiedCallbackItem GSE_LOGIN_CallBackItems[] =
{
    { "MSG_LOADROLE"        , CallBack_UserLoad     },      // �û�����;
    { "MSG_LOGIN"           , CallBack_UserLogin    },      // �û���¼;
    { "MSG_OFFLINE"         , CallBack_UserOffline  },      // �û�����;
    { "MSG_CHANGE_SCENES"   , CallBack_ChangeScenes },      // �л�����;
};

GSE_NAMESPACE_END_DECL

#endif //GSE_MESSAGE_LOGIN_H_
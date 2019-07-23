#ifndef GSE_MESSAGE_LOGIN_H_
#define GSE_MESSAGE_LOGIN_H_

#include <game_service/game_service/game_service.h>

GSE_NAMESPACE_BEGIN_DECL

///  ͬ����������;
void CallBack_PlayerLoadFinish( NLNET::CMessage& , const std::string& , NLNET::TServiceId );
///  �û���¼;
void CallBack_PlayerLoginFinish( NLNET::CMessage&, const std::string&, NLNET::TServiceId );
///  �û�����;
void CallBack_PlayerOffline( NLNET::CMessage&, const std::string& , NLNET::TServiceId );
///  �л�����;
void CallBack_ChangeScenes( NLNET::CMessage&, const std::string& , NLNET::TServiceId );


static NLNET::TUnifiedCallbackItem GSE_LOGIN_CallBackItems[] =
{
    { "MSG_LOADROLE"        , CallBack_PlayerLoadFinish   },    /// �û��������;
    { "MSG_LOGIN"           , CallBack_PlayerLoginFinish  },    /// �û���¼;
    { "MSG_OFFLINE"         , CallBack_PlayerOffline      },    /// �û�����;
    { "MSG_CHANGE_SCENES"   , CallBack_ChangeScenes       },    /// �л�����;
};

GSE_NAMESPACE_END_DECL

#endif //GSE_MESSAGE_LOGIN_H_
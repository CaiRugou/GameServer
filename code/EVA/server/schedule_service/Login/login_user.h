#ifndef SSE_USER_LOGIN_H_
#define SSE_USER_LOGIN_H_

#include <schedule_service/schedule_service/schedule_service_def.h>

SSE_NAMESPACE_BEGIN_DECL

class CLoginUser : public NLMISC::CSingleton< CLoginUser >
{
public:
    CLoginUser( void ){ }
   ~CLoginUser( void ){ }

    //   �û���¼;
    void CallBackUserLogin( NLNET::CMessage& );
    //   �û���¼�ɹ�;
    void CallBackUserLoginSucceed( NLNET::CMessage& );

private:
    //   �û��ڴ��¼;
    bool UserLoginMemory( PB_UserLogin& );
    //   �û����ݿ��¼;
    bool UserLoginDBCache( PB_UserLogin& );
};

#define LoginUser CLoginUser::instance()

SSE_NAMESPACE_END_DECL

#endif //SSE_USER_LOGIN_H_;
#ifndef GSE_EVENT_PLAYER_CALLBACK_H_
#define GSE_EVENT_PLAYER_CALLBACK_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CEventPlayerCallBack : public sigslot::has_slots<> , public NLMISC::CSingleton< CEventPlayerCallBack>
{
public:
    void InitEventCallBack( void );

private:
    void CallBackUserLoad( CRecordPlayer& );        //   �û����ݼ���;
    void CallBackUserLogin( PB_UserLogin& );        //   �û���¼�¼�;
    void CallBackUserOffline( ROLE_ID );            //   �û������¼�;
    void CallBackChangeScenes( CPlayer& );          //   �û��л�����;
};

#define EventPlayerCallBack CEventPlayerCallBack::getInstance()

GSE_NAMESPACE_END_DECL

#endif// GSE_EVENT_PLAYER_CALLBACK_H_
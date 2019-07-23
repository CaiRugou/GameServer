#ifndef GSE_EVENT_ROOM_CALLBACK_H_
#define GSE_EVENT_ROOM_CALLBACK_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CEventRoomCallBack : public sigslot::has_slots<> , public NLMISC::CSingleton< CEventRoomCallBack >
{
public:
    void InitEventCallBack( void );

private:
    //   �û���¼;
    void CallBackPlyaerLoginFinish( PB_UserLogin& );
    //   �û�����;
    void CallBackPlayerOffline( ROLE_ID );
    //   ���뷿��;
    void CallBackJoinRoom ( ROLE_ID , ROOM_ID );
    //   �뿪����;
    void CallBackLeaveRoom( ROLE_ID , ROOM_ID );
    //   ɾ������;
    void CallBackDeleteRoom( ROOM_ID , std::vector<ROLE_ID>& );
    //   ��Ϸ��ʼ;
    void CallBackGameStart( ROOM_ID );
    //   ��Ϸ����;
    void CallBackGameOwer ( ROOM_ID );
};

#define EventRoomCallBack CEventRoomCallBack::getInstance()

GSE_NAMESPACE_END_DECL


#endif//GSE_EVENT_ROOM_CALLBACK_H_
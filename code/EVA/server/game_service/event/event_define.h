#ifndef GSE_EVENT_DEF_H_
#define GSE_EVENT_DEF_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CEventDefine : public NLMISC::CSingleton< CEventDefine >
{
public:
    sigslot::signal1< CRecordPlayer& >                                          EventUserLoad;      // �û����ݼ���;
    sigslot::signal1< PB_UserLogin& >                                           EventUserLogin;     // �û���¼;
    sigslot::signal1< ROLE_ID >                                                 EventUserOffline;   // �û�����;
    sigslot::signal1< CPlayer& >                                                EventChangeScenes;  // �л�����;
    sigslot::signal2< ROLE_ID , ROOM_ID >                                       EventJoinRoom;      // ���뷿��;
    sigslot::signal2< ROLE_ID , ROOM_ID >                                       EventLeaveRoom;     // �뿪����;
    sigslot::signal2< ROOM_ID , std::vector<ROLE_ID>& >                         EventDeleteRoom;    // ɾ������;
    sigslot::signal1< ROOM_ID >                                                 EventGameStart;     // ��Ϸ��ʼ;
    sigslot::signal1< ROOM_ID >                                                 EventGameOwer;      // ��Ϸ����;
    sigslot::signal5< ROLE_ID , ITEM_ID , uint32 , uint32 , PB_DotItem >        EventAddItem;       // ��ӵ���;
    sigslot::signal5< ROLE_ID , ITEM_ID , uint32 , uint32 , PB_DotItem >        EventSubItem;       // �ۼ�����;
};

#define EventDefine CEventDefine::instance()

GSE_NAMESPACE_END_DECL

#endif //GSE_EVENT_DEF_H_
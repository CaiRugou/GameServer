#ifndef GSE_EVENT_DEF_H_
#define GSE_EVENT_DEF_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CEventDefine : public NLMISC::CSingleton< CEventDefine >
{
public:
    sigslot::signal1< CRecordPlayer& >                                          PlayerLoadFinish;  /// ��ɫ���ݼ������;
    sigslot::signal1< PB_UserLogin& >                                           PlayerLoginFinish; /// ��ɫ��¼���;
    sigslot::signal1< ROLE_ID >                                                 PlayerOffline;     /// ��ɫ����;
    sigslot::signal1< CPlayerPtr >                                              ChangeScenes;      /// �л�����;
    sigslot::signal2< ROLE_ID , ROOM_ID >                                       JoinGame;          /// ������Ϸ;
    sigslot::signal2< ROLE_ID , ROOM_ID >                                       LeaveRoom;         /// �뿪����;
    sigslot::signal2< ROOM_ID , std::vector<ROLE_ID>& >                         DeleteRoom;        /// ɾ������;
    sigslot::signal2< ROLE_ID , ROOM_ID >                                       GameStart;         /// ��Ϸ��ʼ;
    sigslot::signal2< ROLE_ID , ROOM_ID >                                       GameOwer;          /// ��Ϸ����;
    sigslot::signal5< ROLE_ID , ITEM_ID , uint32 , uint32 , PB_DotItem >        AddItem;           /// ��ӵ���;
    sigslot::signal5< ROLE_ID , ITEM_ID , uint32 , uint32 , PB_DotItem >        SubItem;           /// �ۼ�����;
};

#define EventDefine CEventDefine::instance()

GSE_NAMESPACE_END_DECL

#endif //GSE_EVENT_DEF_H_
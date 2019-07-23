#ifndef GSE_EVENT_PLAYER_CALLBACK_H_
#define GSE_EVENT_PLAYER_CALLBACK_H_

#include <game_service/game_service/game_service_def.h>
#include <game_service/player/player.h>
#include <game_service/player/player_manager.h>

GSE_NAMESPACE_BEGIN_DECL

class CEventPlayerCallBack : public sigslot::has_slots<> , public NLMISC::CSingleton< CEventPlayerCallBack>
{
public:
    void InitEventCallBack( void );

private:
    void CallBackPlayerLoadFinish( CRecordPlayer& );    /// ������ݼ������;
    void CallBackPlyaerLoginFinish( PB_UserLogin& );    /// ��ҵ�½���;
    void CallBackPlayerOffline( ROLE_ID );              /// ��������¼�;
    void CallBackChangeScenes( CPlayerPtr );            /// ����л�����;
};

#define EventPlayerCallBack CEventPlayerCallBack::getInstance()

GSE_NAMESPACE_END_DECL

#endif// GSE_EVENT_PLAYER_CALLBACK_H_
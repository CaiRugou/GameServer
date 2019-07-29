#ifndef GSE_GAME_TIMER_H_
#define GSE_GAME_TIMER_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

/// ��Ϸ֡�ʶ�ʱ��;
class CGameFrameMoveTimer : public CTimerEvent
{
    NL_INSTANCE_COUNTER_DECL( CGameFrameMoveTimer );
public:
    CGameFrameMoveTimer( ROOM_ID GameID ) : m_GameID( GameID ) {};
    void timerCallback( CTimer* );
    SS_PROPERTY( ROOM_ID , GameID , private );
};

/// ͬ����Ϸ��Ϣ;
class CRefreshGameInfo : public CTimerEvent
{
    NL_INSTANCE_COUNTER_DECL( CRefreshGameInfo );
public:
    CRefreshGameInfo( void ) { };
    void timerCallback( CTimer* );
};


GSE_NAMESPACE_END_DECL

#endif//GSE_GAME_TIMER_H_
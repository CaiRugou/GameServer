#ifndef GSE_ROOM_REGISTER_H_
#define GSE_ROOM_REGISTER_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CRoomRegister : public NLMISC::CSingleton< CRoomRegister >
{
public:
    CRoomRegister( void );

    //   ��������;
    void LoadRoomInfo( void );
    //   ͬ��������Ϣ;
    void UpdateRoomInfo( void );

    SS_PROPERTY( PB_RoomInfoList , Roomlist     , private );

private:
    CTimer m_RoomInfoTimer;
};

#define RoomRegister CRoomRegister::instance()

GSE_NAMESPACE_END_DECL

#endif//GSE_ROOM_REGISTER_H_
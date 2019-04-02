#ifndef GSE_ROOM_MANAGER_H_
#define GSE_ROOM_MANAGER_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CRoomBase;

class CRoomManager : public NLMISC::CSingleton< CRoomManager >
{
public:
    typedef std::map< ROOM_ID , CRoomBase* >              ROOM_TABLE;
    CRoomManager( void );
   ~CRoomManager( void );

    //   ��������;
    bool CreateRoom( ROLE_ID , PB_CreateRoom& );
    bool CreateRoomToScenes( ROLE_ID , PB_CreateRoom& );

    //   ���뷿��;
    bool JoinRoom( ROLE_ID , ROOM_ID );
    //   ɾ������;
    bool DeleteRoom( ROOM_ID );

    //   ���ҷ���;
    CRoomBase* GetRoomInfo( ROOM_ID );
    //   ��������;
    uint32 GetRoomCount( NLMISC::CSString );

    SS_PROPERTY( ROOM_TABLE     , RoomTable     , private );
};

#define RoomManager CRoomManager::instance()

GSE_NAMESPACE_END_DECL

#endif//GSE_ROOM_MANAGER_H_
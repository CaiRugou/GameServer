#ifndef SSE_ROOM_MANAGER_H_
#define SSE_ROOM_MANAGER_H_

#include <schedule_service/schedule_service/schedule_service_def.h>
#include <server_share/id_allocate/id_allocate.h>

SSE_NAMESPACE_BEGIN_DECL

class CRoomManager : public NLMISC::CSingleton< CRoomManager >
{
public:
    typedef std::map< uint32 , PB_RoomInfoList > ROOM_INFO_TABLE;
    CRoomManager( void );
   ~CRoomManager( void ){ };

    //   �û�˽����Ϣ;
    void CreateRoom( NLNET::CMessage& );
    //   ɾ��������Ϣ;
    void DeleteRoomInfo( NLNET::TServiceId& );
    //   ע�᷿����Ϣ;
    void RegisterRoomInfo( NLNET::CMessage& );

    //   ��¼��ȡ��Ч������;
    NLNET::TServiceId GetLoginGamaService( void );
    //   ����������Ч������;
    NLNET::TServiceId GetRoomGameService( NLMISC::CSString );

    SS_PROPERTY( ROOM_INFO_TABLE    , RoomInfo      , private );
    SS_PROPERTY( CRandomIDAlloc*    , RandomIdAlloc , private );
};

#define RoomManager CRoomManager::instance()

SSE_NAMESPACE_END_DECL

#endif// SSE_ROOM_MANAGER_H_
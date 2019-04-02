#ifndef GSE_ROOM_BASE_H_
#define GSE_ROOM_BASE_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CRoomBase
{
public:
    typedef PB_CreateRoom TCtorParam;
    typedef std::vector< ROOM_ID > ROOM_PLAYER_TABLE;

    CRoomBase( TCtorParam& , uint32 );
    virtual ~CRoomBase( void );

    // ���뷿��;
    virtual bool JoinGameRoom( ROLE_ID );
    // �뿪����;
    virtual void LeaveGameRoom( ROLE_ID );
    // ��Ϸ��ʼ;
    virtual void GameStart( void );
    // ��Ϸ����;
    virtual void GameOwer( void );
    // ��Ϸ֡��;
    virtual void FrameMove( void ) = 0;

    // ��������;
    virtual bool IsRoomFull( void );
    virtual bool IsRoomRole( ROLE_ID );
    // �û�����;
    virtual void UserOffline( ROLE_ID );
    virtual void UserOnline ( ROLE_ID );

    // �㲥������Ϣ;
    virtual void RoomBroadCasts( NLMISC::CSString , google::protobuf::Message* , ROLE_ID RemoveId = 0 );

private:
    // ������;
    bool AddRoomPlayer( ROLE_ID );
    bool DelRoomPlayer( ROLE_ID );

    // ��ȡ�������;
    uint32 GetPlayerCount( void );

    SS_PROPERTY( ROOM_ID          , RoomID          , protected );   // ��ͨ����ID;
    SS_PROPERTY( NLMISC::CSString , RoomName        , protected );   // ��������;
    SS_PROPERTY( ROLE_ID          , OwnerID         , protected );   // ����ID;
    SS_PROPERTY( ROOM_PLAYER_TABLE, RoomPlayer      , protected );   // �����б�;
    SS_PROPERTY( bool             , GameStart       , protected );   // ��Ϸ��ʼ;
    SS_PROPERTY( uint32           , FrameMoveTime   , protected );   // ������֡��;
    SS_PROPERTY( TCtorParam       , CreateRoomData  , protected );   // ��ȡ��������;

private:
    CTimer m_FrameMoveTimer;
};

GSE_NAMESPACE_END_DECL

#endif // GSE_ROOM_BASE_H_

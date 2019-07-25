#ifndef GSE_GAME_BASE_H_
#define GSE_GAME_BASE_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CGameBase
{
public:
    typedef PB_CreateRoom        TCtorParam;
    typedef std::vector<ROLE_ID> GameRoleList;

    CGameBase( TCtorParam& , uint32 );
    virtual ~CGameBase( void );

    /// ������Ϸ;
    virtual bool JoinGame( ROLE_ID );
    /// �뿪��Ϸ;
    virtual bool LeaveGame( ROLE_ID );

    /// ��Ϸ��ʼ;
    virtual void StartGame( void ){ };
    /// ��Ϸ����;
    virtual void OwerGame( void ) { };

    /// ���ߴ���;
    virtual void UserOffline( ROLE_ID );
    /// ���ߴ���;
    virtual void UserOnline( ROLE_ID );

    /// ��Ϸ֡��;
    virtual void FraveMove( void ) = 0;
    /// ��Ϸ�㲥��Ϣ;
    virtual void BroadCasts( CSString , google::protobuf::Message* , ROLE_ID RemoveID = 0 );

    /// ��ȡ�������;
    uint32 GetRoleCount( void );

private:
    /// �Ƿ���Ϸ����;
    bool IsGameFull( void );
    /// �Ƿ���Ϸ���;
    bool IsGameRole( ROLE_ID RoleID );

private:
    SS_PROPERTY( ROOM_ID            , RoomID         , protected ); /// ����ID;
    SS_PROPERTY( ROLE_ID            , OwnerID        , protected ); /// ����ID;
    SS_PROPERTY( GameRoleList       , RoleList       , protected ); /// ��ɫ�б�;
    SS_PROPERTY( TCtorParam         , CreateGameData , protected ); /// ������Ϸ����;
    SS_PROPERTY( uint32             , FrameMoveTime  , protected ); /// ��Ϸ֡��;
};

typedef std::shared_ptr< CGameBase >       CGameBasePtr;
typedef std::map< ROOM_ID , CGameBasePtr > GameList;

GSE_NAMESPACE_END_DECL

#endif//GSE_GAME_BASE_H_
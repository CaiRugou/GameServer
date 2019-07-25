#ifndef SERVER_SHARED_RECORDPLAYERINFO_H_
#define SERVER_SHARED_RECORDPLAYERINFO_H_

#include "db_record_base.h"

SS_NAMESPACE_BEGIN_DECL

class CRecordPlayerInfo : public CRecordBase
{
public:
    CRecordPlayerInfo( void );
    virtual ~CRecordPlayerInfo( void );

    SS_PROPERTY( ROLE_ID            , RoleID            , private );    // ��ɫID;
    SS_PROPERTY( uint8              , RoleKind          , private );    // ��ɫ����;
    SS_PROPERTY( NLMISC::CSString   , LastHost          , private );    // �����¼IP;
    SS_PROPERTY( uint32             , LastLoginTime     , private );    // �ϴε�¼ʱ��;
    SS_PROPERTY( uint32             , LastOfflineTime   , private );    // �ϴ�����ʱ��;
    SS_PROPERTY( uint64             , GameTime          , private );    // ��Ϸʱ��;
    SS_PROPERTY( uint32             , CreateTime        , private );    // ��ɫ����ʱ��;
    SS_PROPERTY( NLMISC::CSString   , NickName          , private );    // ��ɫ����;
    SS_PROPERTY( uint16             , HeadID            , private );    // ��ɫͷ��ID;

    // serial stream;
    void serial( NLMISC::IStream& s )
    {
        s.serial( m_DBState );
        s.serial( m_RoleID );
        s.serial( m_RoleKind );
        s.serial( m_LastHost );
        s.serial( m_GameTime );
        s.serial( m_LastOfflineTime );
        s.serial( m_LastLoginTime );
        s.serial( m_CreateTime );
        s.serial( m_NickName );
        s.serial( m_HeadID );
    }

    // serial protobuf;
    void serial( PB_Player& s )
    {
        s.set_role_id( this->m_RoleID );
        s.set_last_host( this->m_LastHost );
        s.set_nick_name( this->m_NickName );
        s.set_head_id( this->m_HeadID );
    }

    // save to database;
    void SaveDB( void )
    {
        CRecordPlayerInfo& RecordPlayer( *this );
        NLNET::CMessage SendMessage("MSG_DB_PLAYER");
        SendMessage.serial( RecordPlayer );
        SS_NETWORK->send( "PSE" , SendMessage );
    }

public:
    void AddRoleState( PB_TRoleState );
    void DelRoleState( PB_TRoleState );
    void SetRoleState( PB_TRoleState );

private:
    NLMISC::CEnumBitset< PB_TRoleState , uint32 >  m_RoleState;     // ��ɫ״̬;
};

SS_NAMESPACE_END_DECL

#endif // SERVER_SHARED_RECORDPLAYERINFO_H_;
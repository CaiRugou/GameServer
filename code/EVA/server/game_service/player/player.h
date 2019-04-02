#ifndef GES_PLAYER_H_
#define GES_PLAYER_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CPlayer
{
public:
    CPlayer( void ) { };
    CPlayer( CRecordPlayer& );
   ~CPlayer( void );

    // serial;
    void serial( NLMISC::IStream& s )
    {
        s.serial    ( m_FrontendServiceId );
        s.serial    ( m_RecordPlayer.RecordPlayerInfo );
        s.serialCont( m_RecordPlayer.RecordItem );
        s.serialCont( m_RecordPlayer.RecordStatisics );
        s.serialCont( m_RecordPlayer.RecordStatisics );
    }

    // ��ȡ��һ�������;
    CRecordPlayerInfo& GetRecordPlayerInfo( void )  { return m_RecordPlayer.RecordPlayerInfo; }
    // ��ȡ��ҵ�������;
    TRecordItem&       GetRecordItemInfo( void )   { return m_RecordPlayer.RecordItem; }
    // ��ȡ���ͳ������;
    TRecordStatisics&  GetRecordStatisics( void )   { return m_RecordPlayer.RecordStatisics; }
    // ��ȡ�����������;
    TRecordMission&    GetRecordMission( void )    { return m_RecordPlayer.RecordMission; }

    SS_PROPERTY( NLNET::TServiceId  , FrontendServiceId , private ); // ��ϢƵ��;
    SS_PROPERTY( ROOM_ID            , RoomID            , private ); // ����ID;

private:
    CRecordPlayer m_RecordPlayer;
};

GSE_NAMESPACE_END_DECL

#endif//GES_PLAYER_H_
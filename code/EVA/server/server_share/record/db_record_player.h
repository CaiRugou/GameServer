#ifndef SERVER_SHARED_RECORDPLAYER_H_
#define SERVER_SHARED_RECORDPLAYER_H_

#include "db_record_base.h"
#include "db_record_player_info.h"
#include "db_record_item.h"
#include "db_record_mission.h"
#include "db_record_statistics.h"

SS_NAMESPACE_BEGIN_DECL

class CRecordPlayer : public CRecordBase
{
public:
    CRecordPlayer( void ) { };
    virtual ~CRecordPlayer( void ) { };

    /// ��һ�����Ϣ;
    SS_PROPERTY_QUOTE( CRecordPlayerInfo , RecordBasePlayer , private );
    /// ��ҵ�����Ϣ;
    SS_PROPERTY_QUOTE( TRecordItem       , RecordItem       , private );
    /// ���������Ϣ;
    SS_PROPERTY_QUOTE( TRecordMission    , RecordMission    , private );
    /// ���ͳ����Ϣ;
    SS_PROPERTY_QUOTE( TRecordStatisics  , RecordStatisics  , private );

    /// serial;
    void serial( NLMISC::IStream& s )
    {
        s.serial    ( m_DBState );
        s.serial    ( m_RecordBasePlayer );
        s.serialCont( m_RecordItem );
        s.serialCont( m_RecordMission );
        s.serialCont( m_RecordStatisics );
    }
};


SS_NAMESPACE_END_DECL

#endif // SERVER_SHARED_DBRECORDPLAYER_H_
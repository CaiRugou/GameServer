#ifndef SERVER_SHARED_DBRECORDBASE_H_
#define SERVER_SHARED_DBRECORDBASE_H_

#include "db_record_def.h"

SS_NAMESPACE_BEGIN_DECL

class CRecordBase
{
public:
    CRecordBase( void );
    virtual ~CRecordBase( void );

    //   serial;
    virtual void serial(NLMISC::IStream &s)
    {
        s.serial( m_DBState );
    }

    //   ���ñ��;
    void ResetState( void )     { m_DBState.resetEnumValue( DB_EVENT_NULL ); }

    //   ������;
    void SetInsert ( void )     { m_DBState.resetEnumValue( DB_EVENT_INSERT ); }
    //   ���±��;
    void SetUpdate ( void )     { m_DBState.resetEnumValue( DB_EVENT_DELETE ); }
    //   ɾ�����;
    void SetDelete ( void )     { m_DBState.resetEnumValue( DB_EVENT_DELETE ); }

    //   �Ƿ���ڲ���;
    bool IsInsertState( void )  { return ( m_DBState.checkEnumValue( DB_EVENT_INSERT ) ); }
    //   �Ƿ���ڸ���;
    bool IsUpdateState( void )  { return ( m_DBState.checkEnumValue( DB_EVENT_UPDATE ) );  }
    //   �Ƿ����ɾ��;
    bool IsDeleteState( void )  { return ( m_DBState.checkEnumValue( DB_EVENT_DELETE ) );  }

public:
    NLMISC::CEnumBitset< DBEventEnum , uint32 >  m_DBState;
};

SS_NAMESPACE_END_DECL

#endif // SERVER_SHARED_DBRECORDBASE_H_;
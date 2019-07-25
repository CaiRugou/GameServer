#ifndef LSE_DB_CONNECT_H_
#define LSE_DB_CONNECT_H_

#include <logger_service/logger_service/logger_service_def.h>

LSE_NAMESPACE_BEGIN_DECL

class CDBConnect : public NLMISC::CSingleton< CDBConnect >
{
public:
    typedef std::vector< CDBMysql > DB_MYSQL_TABLE;

    CDBConnect( void );
   ~CDBConnect( void );

    ///  �������ݿ�;
    void InitDBConnect( NLMISC::CSString , NLMISC::CSString , NLMISC::CSString , NLMISC::CSString , uint16 , uint16 );
    ///  �������ݿ��߳�;
    void StartDBThreads( void );
    ///  �ر����ݿ��߳�;
    void CloseDBThreads( void );
    ///  �������߳�;
    void FrameMove( void );

    ///  ��ȡDB;
    CDBMysql& GetDBMysql( sint8 idx ) { return m_DBThreads[idx]; }
    ///  ��ȡ�߳�ID;
    sint8 GetThreadsIdx( void );

    SS_PROPERTY( DB_MYSQL_TABLE , DBThreads     , public  );    /// �̳߳�;
    SS_PROPERTY( CRandom        , Random        , private );
};

#define DBConnect    CDBConnect::getInstance()

LSE_NAMESPACE_END_DECL

#endif//LSE_DB_CONNECT_H_
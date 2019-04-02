#ifndef LSE_DB_CONNECT_H_
#define LSE_DB_CONNECT_H_

#include <logger_service/logger_service/logger_service_def.h>

LSE_NAMESPACE_BEGIN_DECL

class CDBConnect : public NLMISC::CSingleton< CDBConnect >
{
public:
    //   �������ݿ�;
    void InitDBConnect( NLMISC::CSString , NLMISC::CSString , NLMISC::CSString , NLMISC::CSString , uint16 );
    //   �������ݿ��߳�;
    void StartDBThreads( void );
    //   �ر����ݿ��߳�;
    void CloseDBThreads( void );
    //   �������߳�;
    void FrameMove( void );

    //  �̳߳�;
    SS_PROPERTY( CDBMysql , DBThreads , public );
};

#define DBConnect    CDBConnect::getInstance()
#define DBThreads    DBConnect.m_DBThreads

LSE_NAMESPACE_END_DECL

#endif//LSE_DB_CONNECT_H_
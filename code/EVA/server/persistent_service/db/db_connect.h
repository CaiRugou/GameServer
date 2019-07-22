#ifndef PSE_DB_CONNECT_H_
#define PSE_DB_CONNECT_H_

#include <persistent_service/persistent_service/persistent_service_def.h>

PSE_NAMESPACE_BEGIN_DECL

class CDBConnect : public NLMISC::CSingleton< CDBConnect >
{
public:
    ///  �������ݿ�;
    void InitDBConnect( NLMISC::CSString , NLMISC::CSString , NLMISC::CSString , NLMISC::CSString , uint16 );
    ///  �������ݿ��߳�;
    void StartDBThreads( void );
    ///  �ر����ݿ��߳�;
    void CloseDBThreads( void );
    ///  �������߳�����;
    void FrameMove( void );

    SS_PROPERTY( CDBMysql , ThreadsLoadPlayer   , public );    /// �������ʵ���߳�;( select )
    SS_PROPERTY( CDBMysql , ThreadsPlayerInfo   , public );    /// ��һ��������߳�;( insert update delete )
    SS_PROPERTY( CDBMysql , ThreadsItem         , public );    /// �����߳�;        ( insert update delete )
    SS_PROPERTY( CDBMysql , ThreadsMission      , public );    /// �����߳�;        ( insert update delete )
    SS_PROPERTY( CDBMysql , ThreadsStatistics   , public );    /// ͳ���߳�;        ( insert update delete )
};

#define DBConnect           PSE::CDBConnect::instance()

#define ThreadsLoadPlayer   DBConnect.m_ThreadsLoadPlayer
#define ThreadsPlayerInfo   DBConnect.m_ThreadsPlayerInfo
#define ThreadsMission      DBConnect.m_ThreadsMission
#define ThreadsItem         DBConnect.m_ThreadsItem
#define ThreadsStatistics   DBConnect.m_ThreadsStatistics

PSE_NAMESPACE_END_DECL

#endif // PSE_DBCONNECT_H_
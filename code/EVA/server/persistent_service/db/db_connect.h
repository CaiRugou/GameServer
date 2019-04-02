#ifndef PSE_DBCONNECT_H_
#define PSE_DBCONNECT_H_

#include <persistent_service/persistent_service/persistent_service_def.h>

PSE_NAMESPACE_BEGIN_DECL

class CDBConnect : public NLMISC::CSingleton< CDBConnect >
{
public:
    //    �������ݿ�;
    void InitDBConnect( NLMISC::CSString , NLMISC::CSString , NLMISC::CSString , NLMISC::CSString , uint16 );
    //   �������ݿ��߳�;
    void StartDBThreads( void );
    //   �ر����ݿ��߳�;
    void CloseDBThreads( void );
    //   �������߳�����;
    void FrameMove( void );

    SS_PROPERTY( CDBMysql , ThreadsLoadPlayer   , public );    // �������ʵ���߳�;
    SS_PROPERTY( CDBMysql , ThreadsPlayerInfo   , public );    // ��������߳�;
    SS_PROPERTY( CDBMysql , ThreadsItem         , public );    // ���������߳�;
    SS_PROPERTY( CDBMysql , ThreadsMission      , public );    // ���������߳�;
    SS_PROPERTY( CDBMysql , ThreadsStatistics   , public );    // ����ͳ���߳�;
};

#define DBConnect           PSE::CDBConnect::instance()
#define ThreadsLoadPlayer   DBConnect.m_ThreadsLoadPlayer
#define ThreadsPlayerInfo   DBConnect.m_ThreadsPlayerInfo
#define ThreadsMission      DBConnect.m_ThreadsMission
#define ThreadsItem         DBConnect.m_ThreadsItem
#define ThreadsStatistics   DBConnect.m_ThreadsStatistics

PSE_NAMESPACE_END_DECL

#endif // PSE_DBCONNECT_H_
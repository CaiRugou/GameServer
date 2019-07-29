#ifndef PSE_DB_MANAGER_H_
#define PSE_DB_MANAGER_H_

#include <persistent_service/persistent_service/persistent_service_def.h>

PSE_NAMESPACE_BEGIN_DECL

class CDBManager : public NLMISC::CSingleton< CDBManager >
{
public:

    ///  ���½�ɫ������Ϣ;
    void RefreshDBPlayer ( CRecordPlayerInfo& );

    ///  ���µ�����Ϣ;
    void RefreshDBItem   ( TRecordItem& );
    void RefreshDBItem   ( CRecordItem& );

    ///  ����������Ϣ;
    void RefreshDBMission( TRecordMission& );
    void RefreshDBMission( CRecordMission& );

    ///  ����ͳ����Ϣ;
    void RefreshDBStatistics( TRecordStatisics& );
    void RefreshDBStatistics( CRecordStatistics& );

    ///  �رշ�����;
    void CloseService( void );
};

#define DBManager CDBManager::instance()

PSE_NAMESPACE_END_DECL

#endif// PSE_DBMANAGER_H_
#ifndef PSE_DBMANAGER_H_
#define PSE_DBMANAGER_H_

#include <persistent_service/persistent_service/persistent_service_def.h>

PSE_NAMESPACE_BEGIN_DECL

class CDBManager : public NLMISC::CSingleton< CDBManager >
{
public:
    //   ������ɫ;
    bool CreatePlayer( LoadUserData* );
    //   �����ɫ;
    void SavePlayerInfo( LoadUserData* );

    //   ���½�ɫ������Ϣ;
    void UpdateDBPlayer ( CRecordPlayerInfo& );
    //   ���½�ɫ������Ϣ;
    void UpdateDBItem   ( TRecordItem& );
    void UpdateDBItem   ( CRecordItem& );
    //   ���½�ɫ������Ϣ;
    void UpdateDBMission( TRecordMission& );
    void UpdateDBMission( CRecordMission& );
    //   ���½�ɫͳ����Ϣ;
    void UpdateDBStatistics( TRecordStatisics& );
    void UpdateDBStatistics( CRecordStatistics& );

    //   ��ȡ���ʵ��;
    CRecordPlayer* GetPlayerInfo( ROLE_ID );
    //   ȫ���洢;
    void CloseServiceSaveDBData( void );

    SS_PROPERTY( PLAYER_TABLE , PlayerTable , private );
};

#define DBManager CDBManager::instance()

PSE_NAMESPACE_END_DECL

#endif// PSE_DBMANAGER_H_
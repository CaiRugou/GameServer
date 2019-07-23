#ifndef GSE_MISSION_MANAGER_H_
#define GSE_MISSION_MANAGER_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CMissionManager : public NLMISC::CSingleton< CMissionManager >
{
public:
    ///   ��������;
    void UpdateMission( ROLE_ID , MISSION_ID );
    void UpdateMission( ROLE_ID , MISSION_ID , uint32 );

private:
    ///  ��������Ƿ���Ч;
    bool IsInValidMission( MISSION_ID );
    ///  ��������Ƿ����;
    bool IsDoneMission ( ROLE_ID , MISSION_ID );
    ///  ��������;
    void ResetMissionInfo( ROLE_ID , MISSION_ID );
    ///  ��ȡ������Ϣ;
    CRecordMission* GetMissionInfo( ROLE_ID , MISSION_ID , bool IsAdd = false );
};

#define MissionManager CMissionManager::getInstance();

GSE_NAMESPACE_END_DECL

#endif//GSE_MISSION_MANAGER_H_
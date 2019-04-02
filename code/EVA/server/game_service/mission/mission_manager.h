#ifndef GSE_MISSION_MANAGER_H_
#define GSE_MISSION_MANAGER_H_

#include <server_share/common/common.h>

GSE_NAMESPACE_BEGIN_DECL

class CMissionManager : public NLMISC::CSingleton< CMissionManager >
{
public:
    //   ��������;
    void UpdateMission( ROLE_ID , MISSION_ID );
    void UpdateMission( ROLE_ID , MISSION_ID , uint32 );

    //   ��ȡ����;
    void RewardMission( ROLE_ID , MISSION_ID ){ };

private:
    //   ��������Ƿ���Ч;
    bool IsInValidMission( MISSION_ID );
    //   ��������Ƿ����;
    bool IsDoneMission ( MISSION_ID );
    //   ��������;
    void ResetMission( ROLE_ID , MISSION_ID );
};

#define MissionManager CMissionManager::getInstance();

GSE_NAMESPACE_END_DECL

#endif//GSE_MISSION_MANAGER_H_
#ifndef CPlayerMission_h
#define CPlayerMission_h

#include <game_share/game_def.h>
#include <server_share/database/db_logic_chunk.h>
#include <nel/misc/random.h>
#include "../CRobotHelper.h"

class CPlayerMission
{
public:

    CPlayerMission( void );
    virtual ~CPlayerMission( void );

    // ��������;
    void OnSavePlayerMission( MsgMissionList& data );

    // ������ȡ�꽱��;
    void MissionReward( MsgMissionReward& );
private:

protected:
    // ��ȡ����;
    DB_RECORD::TRecordMission        m_AcceptMission;
    // �����;
    NLMISC::CRandom                  m_Random;
};

#endif // CPlayerMail_h__
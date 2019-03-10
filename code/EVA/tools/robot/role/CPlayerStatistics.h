#ifndef CPlayerStatistics_h
#define CPlayerStatistics_h

#include <game_share/game_def.h>
#include <server_share/database/db_logic_chunk.h>
#include <nel/misc/random.h>
#include "../CRobotHelper.h"

class CPlayerStatistics
{
public:

    CPlayerStatistics( void );
    virtual ~CPlayerStatistics( void );

    // ��������;
    void OnSaveStatisticsData( MsgStatisticsList& data );

    // ������ȡ�꽱��;
    uint32 GetRandomStatisticsID( void );
private:

protected:
    // ͳ����Ϣ;
    DB_RECORD::TRecordStatistics     m_Statistics;
    // �����;
    NLMISC::CRandom                  m_Random;
};

#endif // CPlayerStatistics_h
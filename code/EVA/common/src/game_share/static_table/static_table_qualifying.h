#ifndef STATIC_TABLE_QUALIFYING_H
#define STATIC_TABLE_QUALIFYING_H

#include <vector>
#include <string>
#include <game_share/game_def.h>
#include <nel/misc/singleton.h>


// ��λ����;
struct PiecewiseData
{
    uint32          DanWeiID;            // ��λID;
    uint32          RisingStar;          // ��������;
    uint32          RisingStarScore;     // ���ǻ���ֵ;
    uint32          ProtectScore;        // ������ֵ;
    uint32          BaseScore;           // ������ֵ;
    uint32          CreditPenalty;       // ���÷ֳͷ�;
    uint32          CreditLimit;         // ���÷�����;
    std::string     RoomType;            // ��������;

    PiecewiseData() : DanWeiID( 0 )
                    , RisingStar( 0 )
                    , RisingStarScore( 0 )
                    , ProtectScore( 0 )
                    , BaseScore( 0 )
                    , CreditPenalty( 0 )
                    , CreditLimit( 0 )
    {
        RoomType.clear();
    }
};

// ��λ���ݱ�;
typedef std::vector<PiecewiseData>          Piecewise;
typedef std::map< std::string , Piecewise > PiecewiseTable;

class CQualifyingConfiger : public NLMISC::CSingleton<CQualifyingConfiger>
{
public:
    CQualifyingConfiger( void );
   ~CQualifyingConfiger( void );

    //                  ���������ļ�;
    void                LoadQualifyingXml( void );
    //                  �Ƿ���ڱ���;
    bool                IsExist( std::string& );
    //                  ��ȡ��λ����;
    PiecewiseData*      GetPiecewiseData( std::string& , uint32 );
    //                  ��ȡ��С��λ;
    PiecewiseData*      GetMinPiecewiseData( std::string& );
    //                  ��ȡ����λ;
    PiecewiseData*      GetMaxPiecewiseData( std::string& );

private:
    //   ���ض�λ���ݱ�;
    void LoadPiecewiseXml( void );

private:
    PiecewiseTable      m_PiecwiseTable;
};

#define QualifyingConfiger CQualifyingConfiger::instance()


#endif // STATIC_TABLE_QUALIFYING_H

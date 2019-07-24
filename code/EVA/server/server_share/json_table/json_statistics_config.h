#ifndef SS_JSON_STATISTICS_CONFIG_H_
#define SS_JSON_STATISTICS_CONFIG_H_

#include <server_share/common/common.h>
#include <server_share/json/json_base.h>

SS_NAMESPACE_BEGIN_DECL

class CJsonStatisticsCell;
typedef std::shared_ptr< CJsonStatisticsCell > CJsonStatisticsCellPtr;

/// ͳ�����Բ���;
class CJsonStatisticsCell : public CJsonBase
{
    SS_PROPERTY( STATISTICS_ID    , StatisticsID       , private );  /// ͳ��ID;
    SS_PROPERTY( NLMISC::CSString , StatisticsContent  , private );  /// ͳ������;

    void ParseJson( const Value& JsonValue )
    {
        JsonParseBegin   ( JsonValue );
        JsonParseToUInt  ( m_StatisticsID );
        JsonParseToString( m_StatisticsContent );
        JsonParseEnd( );
    }
};


class CJsonStatisticsConfig : public CJsonBase
{
    void ParseJsonArray( const GenericValue< UTF8<> >& JsonValue )
    {
        JsonParseArrayBegin( JsonValue );
        CJsonStatisticsCellPtr StatisticsCellPtr = std::make_shared< CJsonStatisticsCell >();
        StatisticsCellPtr->ParseJson( Values );
        m_JsonUint32Array.insert(std::make_pair( StatisticsCellPtr->GetStatisticsID() , StatisticsCellPtr ) );
        JsonParseArrayEnd();
    }
};

SS_NAMESPACE_END_DECL

#endif//SS_JSON_STATISTICS_CONFIG_H_
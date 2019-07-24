#ifndef SS_JSON_MISSION_CONFIG_H_
#define SS_JSON_MISSION_CONFIG_H_

#include <server_share/common/common.h>
#include <server_share/json/json_base.h>

SS_NAMESPACE_BEGIN_DECL

/// �������Բ���;
class CJsonMissionCell : public CJsonBase
{
    SS_PROPERTY( MISSION_ID         , MissionID             , private );    // ����ID;
    SS_PROPERTY( NLMISC::CSString   , MissionIcon           , private );    // ����ͼ��;
    SS_PROPERTY( NLMISC::CSString   , MissionContent        , private );    // ��������;
    SS_PROPERTY( NLMISC::CSString   , MissionRewardContent  , private );    // ����������;
    SS_PROPERTY( uint32             , MissionCount          , private );    // �������;
    SS_PROPERTY( uint32             , MissionRewardID       , private );    // ������ID;
    SS_PROPERTY( uint32             , MissionIsDayRefresh   , private );    // �����Ƿ����ˢ��;
    SS_PROPERTY( uint32             , MissionStartTime      , private );    // ����ʼʱ��;
    SS_PROPERTY( uint32             , MissionEndTime        , private );    // �������ʱ��;

    void ParseJson( const Value& JsonValue )
    {
        JsonParseBegin   ( JsonValue );
        JsonParseToUInt  ( m_MissionID );
        JsonParseToString( m_MissionIcon );
        JsonParseToString( m_MissionContent );
        JsonParseToString( m_MissionRewardContent );
        JsonParseToUInt  ( m_MissionCount );
        JsonParseToUInt  ( m_MissionRewardID );
        JsonParseToUInt  ( m_MissionIsDayRefresh );
        JsonParseToUInt  ( m_MissionStartTime );
        JsonParseToUInt  ( m_MissionEndTime );
        JsonParseEnd();
    }
};
typedef std::shared_ptr< CJsonMissionCell > CJsonMissionCellPtr;

class CJsonMissionConfig : public CJsonBase
{
    void ParseJsonArray( const GenericValue< UTF8<> >& JsonValue )
    {
        JsonParseArrayBegin( JsonValue );
        CJsonMissionCellPtr MissionCellPtr = std::make_shared< CJsonMissionCell >();
        MissionCellPtr->ParseJson( Values );
        m_JsonStringArray.insert(std::make_pair( MissionCellPtr->GetMissionID() , MissionCellPtr ) );
        JsonParseArrayEnd();
    }
};

SS_NAMESPACE_END_DECL

#endif//SS_JSON_MISSION_CONFIG_H_

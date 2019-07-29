#ifndef SS_JSON_MISSION_CONFIG_H_
#define SS_JSON_MISSION_CONFIG_H_

#include <server_share/common/common.h>
#include <server_share/json/json_base.h>

SS_NAMESPACE_BEGIN_DECL

class CMissionCell : public CJsonBase
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

    PARSE_VALUE_BEGIN

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

    PARSE_VALUE_END
};

class CMissionConfig : public CJsonBase
{
    PARSE_VALUE_ARRAY_BEGIN

    JsonParseArrayBegin( JsonValue );
    CMissionCell* pMissionCell = new CMissionCell();
    pMissionCell->ParseJson( Values );
    m_JsonStringArray.insert(std::make_pair( pMissionCell->GetMissionID() , pMissionCell ) );
    JsonParseArrayEnd();

    PARSE_VALUE_ARRAY_END
};

SS_NAMESPACE_END_DECL

#endif//SS_JSON_MISSION_CONFIG_H_

#ifndef SS_JSON_ROOM_CONFIG_H_
#define SS_JSON_ROOM_CONFIG_H_

#include <server_share/common/common.h>
#include <server_share/json/json_base.h>

SS_NAMESPACE_BEGIN_DECL

class CJsonGameCell;
typedef std::shared_ptr< CJsonGameCell > CJsonGameCellPtr;

/// ��Ϸ���Բ���;
class CJsonGameCell : public CJsonBase
{
    SS_PROPERTY( NLMISC::CSString , GameName        , private );    // ��Ϸ����;
    SS_PROPERTY( uint32           , GameMax         , private );    // ��Ϸ����;
    SS_PROPERTY( uint32           , GameMin         , private );    // ��Ϸ����;
    SS_PROPERTY( uint32           , GameDeleteTime  , private );    // ��Ϸɾ��ʱ��;
    SS_PROPERTY( NLMISC::CSString , GameIcon        , private );    // ��Ϸͼ��;
    SS_PROPERTY( NLMISC::CSString , GameDesc        , private );    // ��Ϸ����;


    PARSE_VALUE_BEGIN

    JsonParseBegin   ( JsonValue );
    JsonParseToString( m_GameName );
    JsonParseToUInt  ( m_GameMax  );
    JsonParseToUInt  ( m_GameMin  );
    JsonParseToUInt  ( m_GameDeleteTime );
    JsonParseToString( m_GameIcon );
    JsonParseToString( m_GameDesc );
    JsonParseEnd();

    PARSE_VALUE_END
};


class CJsonGameConfig : public CJsonBase
{
    PARSE_VALUE_BEGIN

    JsonParseBegin( JsonValue );
    CJsonGameCellPtr GameCellPtr = std::make_shared< CJsonGameCell >();
    GameCellPtr->ParseJson( Values );
    m_JsonStringArray.insert(std::make_pair( GameCellPtr->GetGameName() , GameCellPtr ) );
    JsonParseEnd();

    PARSE_VALUE_END
};

SS_NAMESPACE_END_DECL

#endif //SS_JSON_ROOM_CONFIG_H_
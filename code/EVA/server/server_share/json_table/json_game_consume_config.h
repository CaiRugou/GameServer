#ifndef SS_JSON_ROOM_CONSUME_CONFIG_H_
#define SS_JSON_ROOM_CONSUME_CONFIG_H_

#include <server_share/common/common.h>
#include <server_share/json/json_base.h>

SS_NAMESPACE_BEGIN_DECL

class CJsonRoomConsumeCell;
typedef std::shared_ptr< CJsonRoomConsumeCell > CJsonRoomConsumeCellPtr;

/// ��Ϸ��������;
class CJsonRoomConsumeCell : public CJsonBase
{
    SS_PROPERTY( uint32           , ConsumeID   , private );    // ����ID;
    SS_PROPERTY( NLMISC::CSString , GameName    , private );    // ��Ϸ����;
    SS_PROPERTY( ITEM_ID          , ConsumeItem , private );    // ���ĵ���ID;
    SS_PROPERTY( uint32           , ConsumeCount, private );    // ��������;
    SS_PROPERTY( uint32           , GameCount   , private );    // ��Ϸ����;
    SS_PROPERTY( NLMISC::CSString , ConsumeDesc , private );    // ��������;

    void ParseJson( const Value& JsonValue )
    {
        JsonParseBegin   ( JsonValue );
        JsonParseToUInt  ( m_ConsumeID );
        JsonParseToString( m_GameName );
        JsonParseToUInt  ( m_ConsumeItem );
        JsonParseToUInt  ( m_ConsumeCount );
        JsonParseToUInt  ( m_GameCount );
        JsonParseToString( m_ConsumeDesc );
        JsonParseEnd( );
    }
};

class CJsonGameConsumeConfig : public CJsonBase
{
    void ParseJsonArray( const Value& JsonValue )
    {
        JsonParseArrayBegin( JsonValue );
        CJsonRoomConsumeCellPtr ConsumeCellPtr = std::make_shared< CJsonRoomConsumeCell >();
        ConsumeCellPtr->ParseJson( Values );
        m_JsonUint32Array.insert(std::make_pair( ConsumeCellPtr->GetConsumeID() , ConsumeCellPtr ) );
        JsonParseArrayEnd();
    }
};

SS_NAMESPACE_END_DECL

#endif //SS_JSON_ROOM_CONSUME_CONFIG_H_;
#ifndef SS_JSON_ITEM_CONFIG_H_
#define SS_JSON_ITEM_CONFIG_H_

#include <server_share/common/common.h>
#include <server_share/json/json_base.h>

SS_NAMESPACE_BEGIN_DECL

class CItemCell : public CJsonBase
{
    SS_PROPERTY( ITEM_ID            , ItemID    , private );    // 道具ID;
    SS_PROPERTY( uint32             , ItemKind  , private );    // 道具种类;
    SS_PROPERTY( NLMISC::CSString   , ItemName  , private );    // 道具名字;
    SS_PROPERTY( NLMISC::CSString   , ItemIcon  , private );    // 道具图标;

    PARSE_VALUE_BEGIN

    JsonParseBegin   ( JsonValue );
    JsonParseToUInt  ( m_ItemID );
    JsonParseToString( m_ItemName );
    JsonParseToUInt  ( m_ItemKind  );
    JsonParseToString( m_ItemIcon  );
    JsonParseEnd();

    PARSE_VALUE_END
};

class CItemConfig : public CJsonBase
{
    PARSE_VALUE_ARRAY_BEGIN

    JsonParseArrayBegin( JsonValue );
    CItemCell* pItemCell = new CItemCell();
    pItemCell->ParseJson( Values );
    m_JsonUint32Array.insert(std::make_pair( pItemCell->GetItemID() , pItemCell ) );
    JsonParseArrayEnd();

    PARSE_VALUE_ARRAY_END
};

SS_NAMESPACE_END_DECL

#endif//SS_JSON_ITEM_CONFIG_H_
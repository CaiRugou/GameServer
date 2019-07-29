#ifndef SS_JSON_GAME_GOLD_H_
#define SS_JSON_GAME_GOLD_H_

#include <server_share/common/common.h>
#include <server_share/json/json_base.h>

SS_NAMESPACE_BEGIN_DECL

class CGameGoldCell : public CJsonBase
{
    SS_PROPERTY( GAME_ID          , GameID          , private );    /// ��Ϸ����ID;
    SS_PROPERTY( NLMISC::CSString , GameName        , private );    /// ��Ϸ����;
    SS_PROPERTY( NLMISC::CSString , GameIconUrl     , private );    /// ��Ϸͼ���ַ;
    SS_PROPERTY( uint32           , BaseGold        , private );    /// ��Ϸ���;
    SS_PROPERTY( uint32           , EnterMinGold    , private );    /// ��Ϸ����������;
    SS_PROPERTY( uint32           , RobotID         , private );    /// ��Ϸ������ID;
    PARSE_VALUE_BEGIN

    JsonParseBegin   ( JsonValue );
    JsonParseToInt   ( m_GameID );
    JsonParseToString( m_GameName );
    JsonParseToString( m_GameIconUrl );
    JsonParseToInt   ( m_BaseGold );
    JsonParseToInt   ( m_EnterMinGold );
    JsonParseToInt   ( m_RobotID );
    JsonParseEnd();

    PARSE_VALUE_END
};

class CGameGold : public CJsonBase
{
    PARSE_VALUE_BEGIN
    JsonParseBegin( JsonValue );
    CGameGoldCell* pGameCell = new CGameGoldCell();
    pGameCell->ParseJson( JsonValue );
    m_JsonUint32Array.insert( std::make_pair( pGameCell->GetGameID() , pGameCell ));
    JsonParseEnd( );
    PARSE_VALUE_END
};

SS_NAMESPACE_END_DECL

#endif//SS_JSON_GAME_GOLD_H_
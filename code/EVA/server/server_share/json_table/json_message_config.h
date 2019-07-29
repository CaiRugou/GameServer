#ifndef SS_JSON_MESSAGE_CONFIG_H_
#define SS_JSON_MESSAGE_CONFIG_H_

#include <server_share/common/common.h>
#include <server_share/json/json_base.h>

SS_NAMESPACE_BEGIN_DECL

class CMessageCell : public CJsonBase
{
    SS_PROPERTY( NLMISC::CSString               , Name          , private );    /// ��Ϣ����;
    SS_PROPERTY( NLMISC::CSString               , Desc          , private );    /// ��Ϣ����;
    SS_PROPERTY( CJsonArray<NLMISC::CSString>   , Format        , public  );    /// ��Ϣ�ֶ�;
    SS_PROPERTY( CJsonArray<NLMISC::CSString>   , SendToService , public  );    /// ת������;

    PARSE_VALUE_BEGIN

    JsonParseBegin   ( JsonValue );
    JsonParseToString( m_Name );
    JsonParseToString( m_Desc );
    JsonParseToClass ( m_Format );
    JsonParseToClass ( m_SendToService );
    JsonParseEnd();

    PARSE_VALUE_END
};

class CMessageConfig : public CJsonBase
{
    PARSE_VALUE_BEGIN

    JsonParseBegin( JsonValue );
    CMessageCell* pMessageCell = new CMessageCell();
    pMessageCell->ParseJson( Values );
    m_JsonStringArray.insert(std::make_pair( pMessageCell->GetName() , pMessageCell ) );
    JsonParseEnd();

    PARSE_VALUE_END
};

SS_NAMESPACE_END_DECL

#endif // SS_JSON_FES_MESSAGE_H_;
#ifndef SS_DBREDIS_INTERFACE_H_
#define SS_DBREDIS_INTERFACE_H_

#include <server_share/common/common.h>

SS_NAMESPACE_BEGIN_DECL

class CDBRedisInterface : public NLMISC::CSingleton< CDBRedisInterface >
{
    SS_PROPERTY_QUOTE( CDBRedis , DBRedisLogin        , private );
    SS_PROPERTY_QUOTE( CDBRedis , DBRedisPlayer       , private );
    SS_PROPERTY_QUOTE( CDBRedis , DBRedisGame         , private );
    SS_PROPERTY_QUOTE( CDBRedis , DBRedisMatch        , private );
    SS_PROPERTY_QUOTE( CDBRedis , DBRedisGameRecord   , private );
};

#define DBRedisLogin      CDBRedisInterface::getInstance().GetDBRedisLogin()        /// ��¼���;
#define DBRedisPlayer     CDBRedisInterface::getInstance().GetDBRedisPlayer()       /// ������;
#define DBRedisGame       CDBRedisInterface::getInstance().GetDBRedisGame()         /// ��Ϸ���;
#define DBRedisMatch      CDBRedisInterface::getInstance().GetDBRedisMatch()        /// �������;
#define DBRedisGameRecord CDBRedisInterface::getInstance().GetDBRedisGameRecord()   /// ��Ϸ�ط�;

SS_NAMESPACE_END_DECL

#endif//SS_DBREDIS_INTERFACE_H_
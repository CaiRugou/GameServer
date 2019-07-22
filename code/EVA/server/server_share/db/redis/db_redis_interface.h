#ifndef SS_DBREDIS_INTERFACE_H_
#define SS_DBREDIS_INTERFACE_H_

#include <server_share/common/common.h>

SS_NAMESPACE_BEGIN_DECL

class CDBRedisInterface : public NLMISC::CSingleton< CDBRedisInterface >
{
    SS_PROPERTY( CDBRedis , DBRedisLogin  , public );
    SS_PROPERTY( CDBRedis , DBRedisPlayer , public );
    SS_PROPERTY( CDBRedis , DBRedisGame   , public );
    SS_PROPERTY( CDBRedis , DBRedisMatch  , public );
};

SS_NAMESPACE_END_DECL

#define DBRedisInterface CDBRedisInterface::getInstance()

#define DBRedisLogin     DBRedisInterface.m_DBRedisLogin        /// ��¼���;
#define DBRedisPlayer    DBRedisInterface.m_DBRedisPlayer       /// ������;
#define DBRedisGame      DBRedisInterface.m_DBRedisGame         /// ��Ϸ���;
#define DBRedisMatch     DBRedisInterface.m_DBRedisMatch        /// �������;
#endif//SS_DBREDIS_INTERFACE_H_
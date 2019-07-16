#ifndef SS_DBREDIS_H_
#define SS_DBREDIS_H_

#include <server_share/db/redis/db_redis_def.h>
#include <server_share/common/common.h>
#include <hiredis/hiredis.h>

SS_NAMESPACE_BEGIN_DECL

class CDBRedis
{
public:
    CDBRedis( void );

    enum ERedis
    {
        NormalError     = -101,     // REDIS�������˵���õĲ���;
        NetError        = -102,     // �������Ӵ���;
        SpaceNotEnough  = -103,     // �洢�ռ䲻��;
    };

    //   ���ӷ�����;
    bool Connect( const char* , sint32 , uint32 , const char* password = NULL );
    //   �Ͽ�������;
    void Close( void );

private:
    /*
    ** ����: REDISԭʼ�ӿ� ��ִ��ʧ�ܳ���һ����������;
    ** ����: ��ʽ������,���տɱ����;
    ** ����: ִ�н��һ��ΪRedisReply*;
    */
    void* Command( const char* format , ... );
    void* CommandArgv( const std::vector< NLMISC::CSString >& , const std::vector< NLMISC::CSString >& );
    void* ExecCommand( const char* , sint32 );

public:
    /****************************************<< STRING���� >>****************************************/
    /*
    ** ����: ����һ��KEY,VALUE ���Ѿ�����ֱ�Ӹ���;
    ** ����: Lifetime ����ʱ��( �� ) 0��������ɾ��;
    ** ����: �ɹ�����0;
    */
    sint32 SetRedisKey( const char* pRedisKey , sint32 RedisKeyLen , const char* pRedisValue , sint32 RedisValueLen , uint32 RedisLifeTime = 0 );
    sint32 SetRedisKey( NLMISC::CSString RedisKey , NLMISC::CSString RedisValue , uint32 RedisLifeTime = 0 );
    sint32 SetRedisKey( NLMISC::CSString RedisKey , uint32 RedisValue , uint32 RedisLifeTime = 0 );
    sint32 SetRedisKey( NLMISC::CSString RedisKey , uint64 RedisValue , uint32 RedisLifeTime = 0 );

    /*
    ** ����: ��ԭ�е�KEY׷��,��KEY������ֱ��д�� SetRedisKey;
    ** ����: �޸ĺ�VALUE����;
    */
    sint32 SetRedisAppend( const char* pRedisKey , sint32 RedisKeyLen , const char* pRedisValue , sint32 pRedisValueLen );

    /*
    ** ����: ����KEY������ʱ��;
    ** ����: Lifetime ��λ��,0��������ɾ��;
    ** ����: �ɹ�����0;
    */
    sint32 SetRedisKeyLifeTime( const char* pRedisKey , sint32 RedisKeyLen , uint32 RedisLifeTime = 0 );

    /*
    ** ����: ��ȡKEY��Ӧ��VALUE;
    ** ����: ���س��� 0��ʾ������;
    */
    sint32 GetRedisKey( const char* pRedisKey , sint32 RedisKeyLen , char* pRedisValue , sint32 RedisValueLen );
    sint32 GetRedisKey( NLMISC::CSString RedisKey , char* pRedisValue , sint32 RedisValueLen );
    sint32 GetRedisKey( NLMISC::CSString RedisKey , NLMISC::CSString& RedisValue );

    /*
    ** ����: ��ȡKEY��Ӧ��VALUE����;
    ** ����: ���س��� 0��ʾ������;
    */
    sint32 GetRedisLen( const char* pRedisKey , sint32 RedisKeyLen );

    /*
    ** ����: ��ȡKEYʣ��ʱ��;
    ** ����: -2 KEY������,-1����,��������ʣ��ʱ��(��);
    */
    sint32 GetRedisKeyLifeTime( const char* pRedisKey , sint32 RedisKeyLen );

    /*
    ** ����: ��ȡKEY����;
    ** ����: -2 KEY������,-1����,��������ʣ��ʱ��(��);
    */
    sint32 GetRedisKeyKind( const char* pRedisKey , sint32 RedisKeyLen ) { return 0; }

    /*
    ** ����: ɾ��KEY;
    ** ����: ɾ���ɹ�����1 , �����ڷ���0;
    */
    sint32 DeleteRedisKey( const char* pRedisKey , sint32 RedisKeyLen );

    /*
    ** ����: ���KEY�Ƿ����;
    ** ����: KEY���ڷ���1,�����ڷ���0;
    */
    sint32 HasRedisKey( const char* pRedisKey , sint32 RedisKeyLen );

    /*
    ** ����:  �������KEY;
    */
    sint32 SetRedisMultiKey( const std::vector<NLMISC::CSString>& RedisKeyValue );
    sint32 GetRedisMultiKey( const std::vector<NLMISC::CSString>& RedisKey , std::vector<NLMISC::CSString>& RedisValue );
    sint32 DelRedisMultiKey( const std::vector<NLMISC::CSString>& RedisKey );


    /****************************************<< HASH���� >>****************************************/
    sint32 SetRedisHashField( const char* pRedisKey , sint32 RedisLen , const char* pRedisField , sint32 RedisFieldLen , const char* pRedisValue , sint32 RedisValueLen );
    sint32 GetRedisHashField( const char* pRedisKey , sint32 RedisLen , const char* pRedisField , sint32 RedisFieldLen , char* pRedisValue , sint32 RedisValueLen );
    sint32 DelRedisHashField( const char* pRedisKey , sint32 RedisLen , const char* pRedisField , sint32 RedisFieldLen );

    /*
    ** ����: HASH������������;
    */
    sint32 HasRedisHashKey( const char* pRedisKey , sint32 RedisKeyLen , const char* pRedisField , sint32 RedisFieldLen );
    sint32 GetRedisHaskAll( const char* pRedisKey , sint32 RedisKeyLen , std::vector< NLMISC::CSString >& );
    sint32 GetRedisHashFieldCount( const char* pRedisKey , sint32 RedisKeyLen );

    sint32 SetMultiHashField( const char* pRedisKey , sint32 RedisKeyLen , const std::vector< NLMISC::CSString >& );
    sint32 GetMultiHashField( const char* pRedisKey , sint32 RedisKeyLen , const std::vector< NLMISC::CSString >& , std::vector< NLMISC::CSString >& );
    sint32 DelMultiHashField( const char* pRedisKey , sint32 RedisKeyLen , const std::vector< NLMISC::CSString >& );


    /****************************************<< LIST���� >>****************************************/

    /*
    ** ����: �б�ͷ����� ���;
    */
    sint32 LPushRedisList( const char* pRedisKey , sint32 RedisKeyLen , const char* pRedisValue , sint32 RedisValueLen );
    sint32 LPoPRedisList ( const char* pRedisKey , sint32 RedisKeyLen , char* pRedisValue , sint32 RedisValueLen );
    sint32 LPoPRedisList ( const char* pRedisKey , sint32 RedisKeyLen , NLMISC::CSString& );

    /*
    ** ����: �б�β����� �ұ�;
    */
    sint32 RPushRedisList( const char* pRedisKey , sint32 RedisKeyLen , const char* pRedisValue , sint32 RedisValueLen );
    sint32 RPoPRedisList ( const char* pRedisKey , sint32 RedisKeyLen , char* pRedisValue , sint32 RedisValueLen );
    sint32 RPoPRedisList ( const char* pRedisKey , sint32 RedisKeyLen , NLMISC::CSString& );

    /*
    ** ����: ���б�����޼� ����Start End ��������;
    ** �±�Ϊ 0  ��ʾ�б��һ��Ԫ�� 1 ��ʾ�б�ڶ���Ԫ��;
    ** �±�Ϊ -1 ��ʾ�б����һ��Ԫ�� -2 ��ʾ�б����ڶ���Ԫ��;
    */
    sint32 DelRedisListRange( const char* pRedisKey , sint32 RedisKeyLen , sint32 RedisStart , sint32 RedisEnd );

    sint32 GetRedisIndexList( const char* pRedisKey , sint32 RedisKeyLen , sint32 Index , char* pRedisValue , sint32 RedisValueLen );
    sint32 GetRedisListLen  ( const char* pRedisKey , sint32 RedisKeyLen );
    sint32 GetRedisRangeList( const char* pRedisKey , sint32 RedisKeyLen , sint32 Start , sint32 End , std::vector<NLMISC::CSString>& );
    sint32 SetRedisList     ( const char* pRedisKey , sint32 RedisKeyLen , sint32 Index , const char* pRedisValue , sint32 RedisValueLen );

    SS_PROPERTY( redisContext*      , RedisContext  , private );
    SS_PROPERTY( NLMISC::CSString   , Host          , private );
    SS_PROPERTY( sint32             , Port          , private );
    SS_PROPERTY( uint32             , TimeOut       , private );
};

SS_NAMESPACE_END_DECL

#endif // SS_DBREDIS_H_

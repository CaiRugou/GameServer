#ifndef SSE_PLAYER_H_
#define SSE_PLAYER_H_

#include <schedule_service/schedule_service/schedule_service_def.h>

SSE_NAMESPACE_BEGIN_DECL

class CPlayer
{
public:
    CPlayer( void );
   ~CPlayer( void );

    ///  �Ƿ���Ҫ�����û�;
    bool IsDBCacheLoadUser( void );

    ///  ���ط�����;
    SS_PROPERTY( NLNET::TServiceId , FrontendServiceId , private );
    ///  ��Ϸ������;
    SS_PROPERTY( NLNET::TServiceId , GameServiceId     , private );
};

typedef std::shared_ptr< CPlayer >       CPlayerPtr;
typedef std::map< ROLE_ID , CPlayerPtr > PLAYER_TABLE;

SSE_NAMESPACE_END_DECL

#endif //SSE_PLAYER_H_;
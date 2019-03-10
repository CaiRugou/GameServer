#ifndef SSE_PLAYER_H_
#define SSE_PLAYER_H_

#include "../schedule_def.h"

SSE_NAMESPACE_BEGIN_DECL

class CPlayer
{
public:
    CPlayer( void );
   ~CPlayer( void );

    SS_PROPERTY( NLNET::TServiceId , FesServiceID , private );  // ���ط�����;
    SS_PROPERTY( NLNET::TServiceId , PlsServiceID , private );  // ��Ϸ������;
};

SSE_NAMESPACE_END_DECL

#endif //SSE_PLAYER_H_; 
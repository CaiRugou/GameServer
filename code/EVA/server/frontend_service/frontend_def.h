#ifndef FRONTEND_SERVICE_DEF_H_
#define FRONTEND_SERVICE_DEF_H_

#include "rudp/rudp_wrapper.h"
#include <server_share/timer/timer.h>
#include <server_share/common/common.h>
#include <server_share/json_table/json_load.h>

FES_NAMESPACE_BEGIN_DECL

using namespace NLNET;
using namespace FES;

// SOCKET����������;
typedef uint32 SOCKET_ID;

// ��ϢƵ��;
enum TChannelNet
{
    RUDP_CHANNEL = 1 ,
    WEB_CHANNEL  = 2
};

// �ͻ���״̬;
enum TClientState
{
    CLIENT_CONNECTION_ABNORMAL = 1 ,
    CLIENT_CONNECTION_NORMAL   = 2
};

// RUDP CALLBACK FUNC;
typedef void ( *TRUDPCallback ) ( NLNET::CMessage&, uint32 );
typedef struct
{
    const char*     KeyName;
    TRUDPCallback   CallBack;
}
TRUDPCallbackItem;

// WEB CALLBACK FUNC;
typedef void ( *TWEBCallback ) ( NLNET::CMessage& , NLNET::TSockId , NLNET::CCallbackNetBase& );
typedef struct
{
    const char*     KeyName;
    TWEBCallback    CallBack;
}
TWEBCallbackItem;

// ת������;
enum EFormatKind
{
    ROLEID ,
    INVALID
};

// to format kind;
EFormatKind   ToForMatEnum( const std::string& );
// to fromat string;
const std::string& ToForMatString( EFormatKind );

FES_NAMESPACE_END_DECL

#endif //FRONTEND_SERVICE_DEF_H_ 
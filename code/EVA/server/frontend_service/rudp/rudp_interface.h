#ifndef __RUDP_INTERFACE_H_
#define __RUDP_INTERFACE_H_

#include "rudp_listen_handler.h"
#include "udp_handler.h"
#include "reciver_thread.h"
#include "revolver/base_reactor_instance.h"
#include "rudp_msg_processor.h"
#include "rudp/rudp_interface.h"

void RUDPInitNet( uint32_t port )
{
    init_socket();

    REACTOR_CREATE();
    REACTOR_INSTANCE()->open_reactor( 20000 );

    // ����RUDP�׽���;
    init_rudp_socket();

    // ���������߳�;
    CREATE_RECV_THREAD();
    CREATE_RECV_UDP();

    Inet_Addr local_addr(INADDR_ANY, port);
    RECV_UDP()->open(local_addr);

    // ����һ������;
    CREATE_RUDP_LISTEN();
    RUDP()->attach_listener(RUDP_LISTEN());

    // ע�ᷢ���¼�����;
    CREATE_SEND_OBJ();
    REACTOR_INSTANCE()->set_message_processor( SEND_OBJ() );

    // ע������¼�����;
    CREATE_RECV_OBJ();
    CREATE_SEND_ERROR_OBJ();
    CREATE_RECV_ERROR_OBJ();

    RECV_THREAD()->start();
}

void RUDPDestoryNet( void )
{
    
}




#endif // __RUDP_INTERFACE_H_
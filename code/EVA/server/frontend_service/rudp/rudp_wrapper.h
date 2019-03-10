#ifndef __RUDP_WRAPPER_H_
#define __RUDP_WRAPPER_H_

#include "rudp_listen_handler.h"
#include "udp_handler.h"
#include "reciver_thread.h"
#include "revolver/base_reactor_instance.h"
#include "rudp_msg_processor.h"

static void RUDPInitNet( uint16_t port )
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

static void RUDPDestoryNet( void )
{
    // �ر��߳�;
    RECV_THREAD()->terminate();

    RUDP()->attach_listener( NULL );
    RUDP()->destroy();

    RECV_UDP()->close();

    REACTOR_INSTANCE()->close_reactor();

    DESTROY_RECV_UDP();
    DESTROY_RUDP_LISTEN();

    destroy_rudp_socket();

    DESTROY_RECV_THREAD();
    REACTOR_DESTROY();

    destroy_socket();

    DESTROY_SEND_OBJ();
    DESTROY_RECV_OBJ();
    DESTROY_SEND_ERRRO_OBJ();
    DESTROY_RECV_ERROR_OBJ();
}

#endif // __RUDP_WRAPPER_H_;
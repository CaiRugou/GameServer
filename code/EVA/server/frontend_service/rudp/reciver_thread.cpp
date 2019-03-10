#include "revolver/base_reactor_instance.h"
#include "reciver_thread.h"

RecvThread::RecvThread( void )
{

}
RecvThread::~RecvThread( void )
{

}

void RecvThread::execute( void )
{
    while ( !get_terminated() )
    {
        REACTOR_INSTANCE()->event_loop();
    }

    // ֹͣ�߳�����;
    REACTOR_INSTANCE()->stop_event_loop();
    // �ر��߳�;
    clear_thread();
}
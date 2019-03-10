#include "revolver/base_reactor_instance.h"
#include "rudp_connection.h"
#include "rudp/rudp_interface.h"
#include "rudp/rudp_socket.h"
#include "rudp_msg_processor.h"
#include <math.h>
#include "rudp/rudp_log_macro.h"
#include "reciver_thread.h"
#include "udp_handler.h"
#include "rudp_listen_handler.h"


RUDPConnection::RUDPConnection()
{
    timer_id_ = 0;
}

RUDPConnection::~RUDPConnection( void )
{
    reset();
}

void RUDPConnection::reset( void )
{
    cancel_timer();
    state_ = RUDP_CONN_IDLE;

    rbuffer_.reset();
    sbuffer_.reset();

    istrm_.rewind( true );
    RUDP()->bind_event_handle( rudp_sock_.get_handler() , NULL );
    rudp_sock_.close();
}

void RUDPConnection::set_timer( uint32_t delay )
{
    if ( timer_id_ == 0 ) 
         timer_id_ = REACTOR_INSTANCE()->set_timer( this , NULL , delay );
}

void RUDPConnection::cancel_timer( void )
{
    if ( timer_id_ != 0 )
    {
        const void* act = NULL;
        REACTOR_INSTANCE()->cancel_timer(timer_id_, &act);
        timer_id_ = 0;
    }
}

int32_t RUDPConnection::connect( const Inet_Addr& scr_addr , const Inet_Addr& dst_addr )
{
    if ( rudp_sock_.open( scr_addr ) != 0 )
    {
        return -1;
    }

    RUDP_DEBUG( " RUDPConnection::connect 1 " );

    rudp_setoption( rudp_sock_.get_handler() , RUDP_NAGLE , 0 );
    if ( rudp_sock_.connect( dst_addr ) != 0 )
    {
        this->close();
        return -1;
    }

    RUDP_DEBUG( " RUDPConnection::connect 2 " );

    rudp_sock_.set_option( 4 , RUDP_SEND_BUFFER );
    // ��һ���¼���;
    RUDP()->bind_event_handle( rudp_sock_.get_handler() , this );

    // ���ý�ɫ״̬;
    set_state( state_ );
    set_timer( 23000 );

    RUDP_DEBUG( " RUDPConnection::connect 3 " );

    return 0;
}

void RUDPConnection::close( void )
{
    RUDP()->bind_event_handle( rudp_sock_.get_handler() , NULL );
    rudp_close_event( rudp_sock_.get_handler() );
}

int32_t RUDPConnection::send( const uint8_t *data, uint32_t data_len )
{
    int32_t res = -1;
    BinStream* bin_strm = STREAMPOOL.pop_obj();
    bin_strm->rewind( true );
    bin_strm->push_data( data , data_len );
    if ( sbuffer_.put( *bin_strm ) )
    {
        RUDP()->register_event( rudp_sock_.get_handler() , MASK_WRITE );
        res = 0;
    }
    bin_strm->rewind( true );
    STREAMPOOL.push_obj( bin_strm );
    return res;
}


int32_t RUDPConnection::rudp_accept_event( int32_t rudp_id )
{
    return 0;
}

int32_t RUDPConnection::rudp_input_event( int32_t rudp_id )
{
    if ( get_state() == RUDP_CONN_CONNECTING )
    {
        return 0;
    }

    while ( true )
    {
        if ( rbuffer_.remaining_length() == 0 )
        {
            if ( rbuffer_.length() >= MAX_BUFFER_SIZE ) { return -1; }
            // ������ܻ�����,��ֹ������̫С����հ��쳣;
            rbuffer_.realloc_buffer( rbuffer_.length() -1 );
        }

        int32_t rc = rbuffer_.recv( rudp_sock_ );
        if ( rc <= 0 ) { return -1; }

        // �жϱ����Ƿ�����;
        bool split_flag = true;
        while ( split_flag )
        {
            int32_t split = rbuffer_.split( istrm_ );
            if ( split == 0 )
            {
                Inet_Addr remote_addr_;
                rudp_sock_.get_peer_addr( remote_addr_ );
                uint32_t len = istrm_.pop_data( (uint8_t*)istrm_.get_data_ptr() , istrm_.data_size() );
                if ( 0 == len )
                {
                    this->close();
                    return -2;
                }
                RECV_OBJ()->push( istrm_.get_data_ptr() , len , rudp_id , remote_addr_.get_ip() );
            }
            else if ( split < 0 ) // �Ƿ�����;
            {
                this->close();
                return -2;
            }
            else                  // ���ĳ��Ȳ���;
            {
                split_flag = false;
            }
        }
    }
}

int32_t RUDPConnection::rudp_output_event( int32_t rudp_id )
{
    if ( get_state() == RUDP_CONN_CONNECTING )
    {
        cancel_timer();
        set_state( RUDP_CONN_CONNECTED );
    }

    if ( sbuffer_.data_length() > 0 )
    {
        sbuffer_.send( rudp_sock_ );
    }
    return 0;
}

int32_t RUDPConnection::rudp_close_event( int32_t rudp_id )
{
    if ( get_state() != RUDP_CONN_IDLE )
    {
        ERROR_RECV_OBJ()->push( rudp_id );
        reset();
        delete this;
    }
    return 0;
}

int32_t RUDPConnection::rudp_exception_event( int32_t rudp_id )
{
    if ( get_state() != RUDP_CONN_IDLE )
    {
        ERROR_RECV_OBJ()->push( rudp_id );
        reset();
        delete this;
    }
    return 0;
}

int32_t RUDPConnection::handle_timeout( const void* act , uint32_t timer_id )
{
    if ( timer_id_ != timer_id ) { return 0; }

    timer_id_ = 0;
    switch ( state_ )
    {
    case RUDP_CONN_CONNECTING:
        set_state( RUDP_CONN_IDLE );
        this->close();
        break;
    default:
        break;
    }
    return 0;
}
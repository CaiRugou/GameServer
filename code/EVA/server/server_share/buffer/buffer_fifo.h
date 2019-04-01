#ifndef SERVICE_SHARED_BUFFERFIFO_RING_H_
#define SERVICE_SHARED_BUFFERFIFO_RING_H_

#include <server_share/common/common.h>

SS_NAMESPACE_BEGIN_DECL

// ���ζ���;
template< typename T >
class CBufferFifoAnnular
{
public:
    CBufferFifoAnnular( void ) : m_Reads( 0 )
                               , m_Writer( 0 )
                               , m_MaxSize( 1 )
                               , m_Mask( 0 )
    {
        m_Data.clear();
    }

   ~CBufferFifoAnnular( void ){ };

    //   ��ʼ�����ζ���;
    void InitPool( uint32 size );
    //   ���Ԫ��;
    bool PushBack( T* data );
    //   ��ȡԪ��;
    T*   BackFront( void );
    //   ���ζ����Ƿ�Ϊ��;
    bool IsEmpty( void );
    //   ��ȡ���д�С;
    uint32 GetSize( void );

    SS_PROPERTY( NLMISC::CMutex  , Mutex      , private );
    SS_PROPERTY( uint32          , Reads      , private  );
    SS_PROPERTY( uint32          , Writer     , private  );
    SS_PROPERTY( uint32          , MaxSize    , private  );
    SS_PROPERTY( uint32          , Mask       , private  );
    SS_PROPERTY( std::vector<T*> , Data       , private  );
};

// ˫�������;
template< typename T >
class CDoubleBufferFifo
{
public:
    CDoubleBufferFifo( void ) : m_ReadsCount ( 0 )
                              , m_WriterCount( 0 )
    {
        
    }

   ~CDoubleBufferFifo( void ) { }

    //   ���Ԫ��;
    bool PushBack( T* data );
    //   ��ȡԪ��;
    T*   BackFront( void );

    //   Ԫ������;
    uint32 Size( void ) { return m_ReadsCount + m_WriterCount ;}

private:
    //   ��������;
    void ExchangeQueue( void );

    SS_PROPERTY( volatile uint32  , ReadsCount      , private );
    SS_PROPERTY( volatile uint32  , WriterCount     , private );

    SS_PROPERTY( NLMISC::CMutex   , WriterMutex     , private );
    SS_PROPERTY( NLMISC::CMutex   , ReadsMutex      , private );

    SS_PROPERTY( std::queue<T*>   , WriterQueue     , private );
    SS_PROPERTY( std::queue<T*>   , ReadsQueue      , private );
};

#include "buffer_fifo.inl"

SS_NAMESPACE_END_DECL

#endif // SERVICE_SHARED_BUFFERFIFO_RING_H_;
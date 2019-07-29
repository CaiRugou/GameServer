#include "player.h"

SSE_NAMESPACE_BEGIN_DECL

CPlayer::CPlayer( void ) : m_GameServiceId( NLNET::TServiceId::InvalidId )
                         , m_FrontendServiceId( NLNET::TServiceId::InvalidId )
{
    
}

CPlayer::~CPlayer( void )
{
    
}

bool CPlayer::IsLoadDBCache( void )
{
    if ( m_FrontendServiceId == NLNET::TServiceId::InvalidId ) return true;
    if ( m_GameServiceId     == NLNET::TServiceId::InvalidId ) return true;

    /// ���FES�����Ƿ����;
    if ( !SS_NETWORK->isConnectionConnected( m_FrontendServiceId ) ) return true;
    /// ���GSE�����Ƿ����;
    if ( !SS_NETWORK->isConnectionConnected( m_GameServiceId ) ) return true;

    return false;
}

SSE_NAMESPACE_END_DECL
#ifndef CClientMgr_h__
#define CClientMgr_h__
#include <game_share/game_def.h>
#include <nel/misc/random.h>
#include <deque>
class CClient;

class CClientMgr
{
public:
    typedef std::deque< CClient* >                     ClientMgrQueue;
    typedef std::map< DEF::CLIENT_SESSION , CClient* > ClientMgrTab;
    CClientMgr( void );
   ~CClientMgr( void );

    // 
    CClient* AllocClient( void );
    // 
    bool    InsertClient( DEF::RPC_SESSION , CClient* );
    // 
    CClient* FindClient( DEF::RPC_SESSION );
    // 
    void     RemoveClient( DEF::RPC_SESSION );
    //
    void     ClearClient( void );
    // 
    void     OnUpdate( void );
    //
    CClient* GetRandomClient( void );

    void     CreateTimer( void );

    void     AutoLogin( void );

    uint32   GetLimitTime( void ) { return m_unLoginLimitTime; }
    uint32   GetSendTMailLimitTime( void ) { return m_unSendTMailLimitTime; }
    

    void     CreateTimerSendTMail( void );
    void     AutoSendTMail( void );

    void     CreateMsgTimer( void );
    void     SetSecondSendMsgCount( bool bClear=false );

    static CClientMgr* GetInstance( void )
    {
        static CClientMgr _inst;
        return &( _inst );
    }

private:

    ClientMgrQueue      m_ClientQueueMgr;
    ClientMgrTab        m_ClientTabMgr;
    NLMISC::CRandom     m_Random;
    uint32              m_unLoginLimitTime;         // ÿ�����µ�¼������ʱ������;
    uint                m_unCurrLoginCountMax;      // ��ǰ�����˵�¼����˺���;
    uint                m_unLoginCountMax;          // ���������ɵ�¼�˺�;
    uint                m_EveryTimeLoginCount;      // ÿ��������¼�����˸���;
    uint                m_LoginStartAccount;     
    uint32              m_unSendTMailLimitTime;

    CClientMgr( const CClientMgr& rhs );
    CClientMgr &operator = ( const CClientMgr& rhs );
};

#define ClientMgr CClientMgr::GetInstance()

#endif // CClientMgr_h__
#ifndef CConnect_h__
#define CConnect_h__
#include <game_share/game_def.h>
#include <game_share/udp_msg.h>
#include <game_share/timer.h>
#include <nel/net/callback_client.h>
#include <nel/net/udp_sim_sock.h>
#include <nel/misc/random.h>

class RecvLogic;
class SendLogic;

class CConnect
{
public:
    CConnect( void );
    virtual ~CConnect( void );

    // ������Ϣ;
    virtual bool SendMsg( std::string Name , google::protobuf::Message* Msg = NULL );

    // �����������;
    virtual void SendHeartbeatMsg( void );

    // ��ȡTCP����;
    //NLNET::CCallbackClient& GetTCPConnect( void ) {
    //    return m_TcpConnect;
    //}

    // ��ȡUDP����;
     NLNET::CUdpSimSock&   GetUDPConnect( void ) {
         return m_UdpConnect;
     }

    // ���ܶ�;
    RecvLogic* GetRecvLogic( void ){
        return m_RecvLogic;
    }

    // ���Ͷ�;
    SendLogic* GetSendLogic( void ){
        return m_SendLogic;
    }

    // �Ͽ�TCP;
    void TCPDisconnect( void );

    // �ػ�ID;
    PROPERTY( DEF::CLIENT_SESSION , session );

    // ����;
    void SetRandomSeed( uint seed );


    uint GetBuffIndex(){
        return m_BuffIndex++;
    }

    uint32 GetSendMsgLimitTime() { return m_Limitiem; }

protected:
    // ����UDP;
    void OnUDPUpdate( void );
    // ����TCP;
    void OnTCPUpdate( void );

private:
    bool TCPConnect( void );
    bool TCPConnect( std::string , short );
    bool IsTCPProtocol( std::string& name );
    bool IsUDPProtocol( std::string& name );

private:
    //NLNET::CCallbackClient m_TcpConnect;
    NLNET::CUdpSimSock     m_UdpConnect;
    RecvLogic*             m_RecvLogic;
    SendLogic*             m_SendLogic;
    std::deque< uint32 >   m_AckPool;
    CTimer                 m_HeartBeat;
    uint32                 m_MsgCountTime;
    uint                   m_BuffIndex;
    uint32                 m_Limitiem;
    NLMISC::CRandom        m_Random;

};

#endif // CConnect_h__
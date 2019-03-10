#ifndef CPlayerMailInfo_h__
#define CPlayerMailInfo_h__
#include <game_share/game_def.h>
#include <server_share/database/record_player.h>
#include <game_share/proto_msg/mail_pro.pb.h>
#include <nel/misc/random.h>

struct MailData
{
    DEF::PID          roleID;   // �Լ�ID;
    DEF::MAIL_ID      mailID;   // �ʼ�ID;
    DEF::PID          sendid;   // �������ID;
    std::string       sendname; // �����������;
    std::string       title;    // ����;
    std::string       content;  // ����;
    uint32            sendtime; // ����ʱ��;
    uint64            reward;   // ����;
    TMailType         type;     // �ʼ�����;
    bool              isLook;   // �鿴���;
};

typedef std::map< DEF::MAIL_ID, MailData > TCommonMailMap;
typedef std::map< DEF::MAIL_ID, MailData > TSystemMailMap;

class CPlayerMailInfo
{
public:
    CPlayerMailInfo( void );
    virtual ~CPlayerMailInfo( void );

    void OnSaveCommonMail( MsgCommonMail& );
    void RecviveRequestMail( MsgMailList& );

    DEF::MAIL_ID OnGetRandomSystemMailID();
    DEF::MAIL_ID OnGetRandomCommonMailID();

    void RemoveSystemMail( DEF::MAIL_ID );
    void RemoveCommonMail( DEF::MAIL_ID );

    std::map< DEF::MAIL_ID, MailData >& GetCommonMailMap() { return m_CommonMailMap; }
    std::map< DEF::MAIL_ID, MailData >& GetSystemMailMap() { return m_SystemMailMap; }



private:
    TCommonMailMap   m_CommonMailMap;
    TSystemMailMap   m_SystemMailMap;

    // ���;
    NLMISC::CRandom m_Random;
};

#endif // CPlayerMailInfo_h__
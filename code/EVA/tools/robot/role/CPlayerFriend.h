#ifndef CPlayerFriendInfo_h__
#define CPlayerFriendInfo_h__
#include <game_share/game_def.h>
#include <server_share/database/record_player.h>
#include <game_share/proto_msg/friend_pro.pb.h>
#include <nel/misc/random.h>

struct CFriend
{
    DEF::PID unRoleID;
    std::string strPortrait;
    std::string strName;
    bool bOnlineState;
    CFriend( void ):unRoleID(0),bOnlineState(false)
    {
        strPortrait = "";
        strName = "";
    }
    ~CFriend() {}
};

typedef std::map<DEF::PID,CFriend>       TApplyFriendList;

class CPlayerFriendInfo
{
public:
    CPlayerFriendInfo( void );
    virtual ~CPlayerFriendInfo( void );

    void OnSaveFriendList( MsgFriendList& );
    void OnSaveApplyFriendList( MsgFriendList& );
    // ����������б�;
    void OnSaveBlackList( MsgBlackListCont& );

    void AddFriend( MsgFriendBase& );
    void DeleteFriend( DEF::PID );
    void DeleteApplyFriend( DEF::PID );

    void DeleteBlackList( DEF::PID );

    DEF::PID OnGetRandomApplyFriendID();
    DEF::PID OnGetRandomFriendID();
    DEF::PID OnGetRandomBlackListPID();

    void AddFriendList( MsgFriendBase& );

    // ��ȡ��������;
    size_t OnGetFriendListNum( void ){ return m_FriendList.size(); }
    // �����б�����;
    size_t OnGetApplyListNum( void ){ return m_ApplyFriendList.size(); }
    // ��ȡ����������;
    size_t OnGetBlackListNum( void ) { return m_BlackList.size() ; }

private:
    // ��������;
    std::set< DEF::PID >    m_FriendList;
    // ����������;
    std::set< DEF::PID >    m_BlackList;
    // �����б�;
    std::set< DEF::PID >    m_ApplyFriendList;
    // ���;
    NLMISC::CRandom m_Random;
};

#endif // CPlayerFriendInfo_h__
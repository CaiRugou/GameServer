regster_blackjack_event = {}

RegScriptEvent( "regster_blackjack_event", ROBOT_EVENT_BLACKJACK )

--CreateTimer
--@param1 �ͻ���ΨһID
--@param2 ��ʱ��ִ�нű��¼�
--@param3 ִ�нű�����
--@param4 ִ�нű�����

--------------------------------------------------BlackJack--------------------------------------------------

-- �����ڻ�����Ϣ;
local MsgRoomBaseTimeMin = 10 * 1000;
local MsgRoomBaseTimeMax = 60 * 1000;

-- ��ע;
local MsgPourTimeMin = 5 * 1000;
local MsgPourTimeMax = 10 * 1000;

-- Ҫ�ơ�ͣ�ơ�����;
local MsgCardTimeMin = 10 * 1000;
local MsgCardTimeMax = 50 * 1000;

-- ���ա�˫��;
local MsgSurrenderTimeMin = 30 * 1000;
local MsgSurrenderTimeMax = 60 * 1000;

-- �뿪����;
local MsgLeaveRoomMin = 10 * 60 * 1000;
local MsgLeaveRoomMax = 20 * 60 * 1000;

regster_blackjack_event.OnEvent = function( eventID, ID )
 	
	-- �������������ϸ��Ϣ;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_player" , "ReqPlayerInfo" );
	-- �����������ͳ������;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_player" , "ReqPlayerKPI" );
	-- �뿪����;
	CreateTimer( ID , math.random( MsgLeaveRoomMin , MsgLeaveRoomMax ) , "event_player" , "LeaveRoom" );
	-- ������ע;
	CreateTimer( ID , math.random( MsgPourTimeMin , MsgPourTimeMax ) , "event_blackjack" , "BlackJackAddPour" );
	-- ����Ҫ��;
	CreateTimer( ID , math.random( MsgCardTimeMin , MsgCardTimeMax ) , "event_blackjack" , "BlackJackAskCard" );
	-- �������;
	CreateTimer( ID , math.random( MsgCardTimeMin , MsgCardTimeMax ) , "event_blackjack" , "BlackJackSplitCard" );
	-- ����ͣ��;
	CreateTimer( ID , math.random( MsgCardTimeMin , MsgCardTimeMax ) , "event_blackjack" , "BlackJackStandCard" );
	-- ������
	CreateTimer( ID , math.random( MsgSurrenderTimeMin , MsgSurrenderTimeMax ) , "event_blackjack" , "BlackJackBuySurrender" );
	-- ��������
	CreateTimer( ID , math.random( MsgSurrenderTimeMin , MsgSurrenderTimeMax ) , "event_blackjack" , "BlackJackSkipSurrender" );
	-- ˫��;
	CreateTimer( ID , math.random( MsgSurrenderTimeMin , MsgSurrenderTimeMax ) , "event_blackjack" , "BlackJackDoubleCard" );
	-- �����ע;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_blackjack" , "BlackJackClearPour" );
	-- Ranking Room Top;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_blackjack" , "RankingRoomTop" );
	-- �����ϴ���;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_blackjack" , "GiveTips" );
	-- ����ͬ�����������ϸ��Ϣ;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_blackjack" , "RoomPlayerInfo" );
	-- ���ö�ע(Bet, Bet*2, Betall);
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_blackjack" , "BlackJackResetPour" );
	-- ����ͬ�������б�;	
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_friend" , "SynchFriendList" );
	-- ����������;	
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_friend" , "RequestRewardFriend" );
	-- ��������;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_friend" , "InviteFriend" );
	-- ��������;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_common" , "ChatRoom" );
	
	
end





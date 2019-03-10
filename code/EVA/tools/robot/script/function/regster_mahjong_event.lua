regster_mahjong_event = {}

RegScriptEvent( "regster_mahjong_event", ROBOT_EVENT_MAHJONG )

--CreateTimer
--@param1 �ͻ���ΨһID
--@param2 ��ʱ��ִ�нű��¼�
--@param3 ִ�нű�����
--@param4 ִ�нű�����

--------------------------------------------------Mahjong--------------------------------------------------

-- �����ڻ�����Ϣ;
local MsgRoomBaseTimeMin = 2 * 1000;
local MsgRoomBaseTimeMax = 5 * 1000;


-- �뿪����;
local MsgLeaveRoomMin = 10 * 60 * 1000;
local MsgLeaveRoomMax = 20 * 60 * 1000;

regster_mahjong_event.OnEvent = function( eventID, ID )
 	
	-- �Ͼ��齫����Ȩ��;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_mahjong" , "MahjongUserOperate" );
	-- �Ͼ��齫����;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_mahjong" , "MahjongOutCard" );
	-- �Ͼ��齫�û���ʼ׼��;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_mahjong" , "MahjongStartReady" );
	-- �Ͼ��齫�û�ȡ��׼��;
	CreateTimer( ID , math.random( MsgRoomBaseTimeMin , MsgRoomBaseTimeMax ) , "event_mahjong" , "MahjongCancelReady" );

	
	
end





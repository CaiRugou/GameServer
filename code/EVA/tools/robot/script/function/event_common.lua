event_common = {}


-- �����������;
event_common.RequestPrizePool = function(id)
	RequestPrizePool(id);
end

-- �����������;
event_common.GetRankingMyData = function(id)
	GetRankingMyData(id);
end

-- ���������������; 
event_common.SynchRoomRankPlayerNum = function(id)
	SynchRoomRankPlayerNum(id);
end

-- �����������;
event_common.GetChampionship = function(id)
	GetChampionship(id);
end

-- Ranking Room Top;
event_common.RankingRoomTop = function(id)
	RankingRoomTop(id);
end

-- chat room;
event_common.ChatRoom = function(id)
	ChatRoom(id,math.random(1,100))
end

-- ����鿴С���Ǯ����Ϣ;
event_common.ViewPigInfo = function(id)
	ViewPigInfo(id);
end

-- ����У������ֻ���;
event_player.BindMobileNumberCheck = function(id)
	BindMobileNumberCheck(id);
end

-- ����ƺ���;
event_player.ChatPaoMaDeng = function(id)
	ChatPaoMaDeng(id);
end

-- ��ȡ Send Money Limit;
event_player.GetSendMoneyLimit = function(id)
	GetSendMoneyLimit(id);
end

event_friend = {}

local RFRandomMoneyTab = {
	[0] = 50,
	[1] = 100,
	[2] = 500,
	[3] = 1000,
	[4] = 5000
}  

-- ����ͬ�������б�;
event_friend.SynchFriendList = function(id)	
	SynchFriendList(id);
end

-- ����ͬ�����������б�;
event_friend.SynchApplyList = function(id)
	SynchApplyList(id);
end

-- ͬ�������б�;
event_friend.SyncBlackList = function(id)
	SyncBlackList(id);
end

-- ��������;
event_friend.AddFriendApply = function(id)
	AddFriendApply(id);
end

-- �������;
event_friend.AddFriend = function(id)
	AddFriend(id);
end

-- ɾ������;
event_friend.DeleteFriend = function(id)
	DeleteFriend(id);
end

-- ɾ����������;
event_friend.DeleteApplyFriend = function(id)
	DeleteApplyFriend(id);
end

-- ���������ϸ��Ϣ;
event_friend.RequestFriendDetail = function(id)
	RequestFriendDetail(id);
end

-- �������������ϸ��Ϣ;
event_friend.RequestApplyDetail = function(id)
	RequestApplyDetail(id);
end

-- ����������;
event_friend.RequestRewardFriend = function(id)
	-- local rand_index  = math.random(1);
	-- local rand_money = RFRandomMoneyTab[rand_index];
	RequestRewardFriend(id,1);
end

-- �Ƽ�����;
event_friend.RequestRecommendFriend = function(id)
	RequestRecommendFriend(id);
end

-- ��������;
event_friend.InviteFriend = function(id)
	InviteFriend(id);
end

-- ����˽��;
event_friend.PrivateChat = function(id)
	PrivateChat(id);
end

-- ����˽��;
event_friend.SearchPID = function(id)
	SearchPID(id);
end

-- �Ƴ������б�;
event_friend.DeleteBlackList = function(id)
	DeleteBlackList(id);
end

-- ��������б�;
event_friend.AddBlackList = function(id)
	AddBlackList(id);
end
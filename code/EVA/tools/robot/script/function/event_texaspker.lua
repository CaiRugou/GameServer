event_texaspker = {}

-- ��Ҹ�ע;
event_texaspker.CallPour = function(id)
	CallPour(id);
end

-- ��Ҽ�ע;
event_texaspker.RaisePour = function(id)
	RaisePour(id);
end

-- �������;
event_texaspker.FoldCard = function(id)
	FoldCard(id);
end

-- �������;
event_texaspker.CheckCard = function(id)
    CheckCard(id);
end

-- ���ó���;
event_texaspker.ResetCoins = function(id)
	ResetCoins(id);
end

-- ������Ϸ;
event_texaspker.GoBackGame = function(id)
	GoBackGame(id);
end

-- ���ݾ���������;
event_texaspker.TPChallApplyGame = function(id)
    TPChallApplyGame(id);
end

-- ���ݾ�����ȡ������;
event_texaspker.TPChallCancelApplyGame = function(id)
    TPChallCancelApplyGame(id);
end

-- ���ݾ�����������Ϣ;
event_texaspker.TPChallRoomData = function(id)
    TPChallRoomData(id);
end

-- ���ݾ����������˳�;
event_texaspker.TPChallRequestQuit = function(id)
    TPChallRequestQuit(id);
end

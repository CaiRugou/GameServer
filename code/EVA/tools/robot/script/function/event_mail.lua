event_mail = {}


-- ��������ͨ�ʼ�;
event_mail.RequestSendCommmonMail = function(id)	
	RequestSendCommmonMail(id, math.random(1,10) , math.random(1,100) );
end

-- �����ʼ�����;
event_mail.RequestMailData = function(id)	
	RequestMailData(id);
end

-- ����ϵͳ�ʼ�����;
event_mail.RequestSystemMailReward = function(id)
	RequestSystemMailReward(id);
end

-- ������ͨ�ʼ�����;
event_mail.RequestCommonMailReward = function(id)
	RequestCommonMailReward(id);
end

-- ����ɾ����ͨ�ʼ�;
event_mail.RequestDeleteCommonMail = function(id)
	RequestDeleteCommonMail(id);
end

-- ����ɾ��ϵͳ�ʼ�;
event_mail.RequestDeleteSystemMail = function(id)
	RequestDeleteSystemMail(id);
end

--����鿴��ͨ�ʼ�;
event_mail.RequestLookCommonMail = function(id)
	RequestLookCommonMail(id);
end 

-- �����ʼ�״̬;
event_mail.CheckMailState = function(id)
	CheckMailState(id);
end
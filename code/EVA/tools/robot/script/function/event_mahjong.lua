event_mahjong = {}

local PourNumTab = {
	[0] = 0x00,					--// û������;
	[1] = 0x01,					--// �������;
	[2] = 0x02,					--// �г�����;
	[3] = 0x04,					--// �ҳ�����;
	[4] = 0x08,					--// ��������;
	[5] = 0x10,					--// ��������;
	[6] = 0x20,					--// ����������;
	[7] = 0x40,					--// �Ժ�����;
	[8] = 0x80					--// ��֤Ȩ��;
}  

-- �û�ѡ��Ȩ��;
event_mahjong.MahjongUserOperate = function(id)
	MahjongUserOperate( id, math.random(0,8) );
end

-- �Ͼ��齫����;
event_mahjong.MahjongOutCard = function(id)
    MahjongOutCard(id);
end

-- �Ͼ��齫�û���ʼ׼��;
event_mahjong.MahjongStartReady = function(id)
    MahjongStartReady(id);
end

-- �Ͼ��齫�û�ȡ��׼��;
event_mahjong.MahjongCancelReady = function(id)
    MahjongCancelReady(id);
end
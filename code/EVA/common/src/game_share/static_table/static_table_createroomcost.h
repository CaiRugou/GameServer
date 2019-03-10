/********************************************************************
	created:	2016/12/30
	created:	30:12:2016   13:36
	file base:	static_table_createroomcost
	file ext:	h
	author:		WHJ
	
	purpose:	����˽�����ı�֮ǰ�Ƿŵ��齫�������еģ����������õĵط��Ƚ�
				�࣬����˵�����ó�����һ��xml	
*********************************************************************/
#ifndef GAME_SHARE_STATIC_TABLE_CREATEROOMCOST_H
#define GAME_SHARE_STATIC_TABLE_CREATEROOMCOST_H

#include <game_share/game_def.h>
#include "static_table_mahjong.h"
class CreateRoomCostConfig : public NLMISC::CSingleton<CreateRoomCostConfig>
{
public:
	CreateRoomCostConfig( void );
	~CreateRoomCostConfig( void );
	//   ��������;
	void ResetData( void );
	//   ���ر�;
	bool LoadConfig( void );
	///                            ��ȡ����˽�˷���������;
	CreatePrivateConsumeItem*      GetCreateConsumeItem( uint );


private:
	std::map<uint,CreatePrivateConsumeItem>             m_CreatePrivateConsumeItem;
};

#define CreateRoomCostData CreateRoomCostConfig::instance()

#endif //GAME_SHARE_STATIC_TABLE_CREATEROOMCOST_H;
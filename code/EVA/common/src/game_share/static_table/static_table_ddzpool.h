/********************************************************************
	created:	2017/09/19
	created:	19:9:2017   19:39
	file base:	static_table_ddzpool
	file ext:	h
	author:		WHJ
	
	purpose:	����������
*********************************************************************/
#ifndef GAME_SHARE_DDZPOOL_H
#define GAME_SHARE_DDZPOOL_H

#include "static_tabel_struct.h"

// ����������
class DDZPoolConFig : public NLMISC::CSingleton<DDZPoolConFig>
{
public:

	DDZPoolConFig( void )
	{
		ResetData();
	}
    ~DDZPoolConFig(){}

	void ResetData( void )
	{
		m_HandCardPool.clear();
	}
    typedef std::vector< std::vector<uint8> > TCardPools;
	// ת�����߻���д���Ʋ���CardList�е�ֵ
	uint8 SwitchToCardValue( NLMISC::CSString& );

	// ��������
	bool LoadCardConfig( void );

	// �ж��Ƿ��ǺϷ�������
	bool IsValidConfig( void ) const;

    // ��ȡ����
    TCardPools& GetCard(){ return m_HandCardPool;}

private:
    TCardPools m_HandCardPool;		// �����б�
};

#define DDZPoolConfig  DDZPoolConFig::instance()

#endif // GAME_SHARE_DDZPOOL_H;
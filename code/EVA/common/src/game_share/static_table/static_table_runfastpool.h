#ifndef GAME_SHARE_RUNFASTPOOL_H
#define GAME_SHARE_RUNFASTPOOL_H

#include "static_tabel_struct.h"

// �ܵÿ�����
class RunFastPoolConFig : public NLMISC::CSingleton<RunFastPoolConFig>
{
public:

	RunFastPoolConFig( void )
	{
		ResetData();
	}
    ~RunFastPoolConFig(){}

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

#define RunFastPoolConfig  RunFastPoolConFig::instance()

#endif // GAME_SHARE_RUNFASTPOOL_H;
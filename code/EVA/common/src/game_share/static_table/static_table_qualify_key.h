
#ifndef GAME_SHARE_STATIC_TABLE_VERI_H
#define GAME_SHARE_STATIC_TABLE_VERI_H

#include <game_share/game_def.h>

struct QyNormalkeyData
{
	uint32 unIndex;
    std::string strOwnKey;
    std::string strUpKey;
	QyNormalkeyData()
	{
		unIndex=0;
		strOwnKey="";
		strUpKey="";
	}
};

struct QyUpkeyData
{
	uint32 unIndex;
	NLMISC::CSString strOwnKey;
	NLMISC::CSString strUpKey;
	uint32 totalRelation;  //  �ܷ�������ֵĹ�ϵ(1�ǻ�0�ǲ�)  
	uint32 totalScore; //  ��ʦ�ֵ�����
	uint32 scoreRelation; //  �����ֵĹ�ϵ(1�ǻ�0�ǲ�)
	uint32 goldScore; //  ���
	uint32 silverScore; //  ����
	uint32 redScore; //  ���
	uint32 blueScore; //  ����
	uint32 rankCondition;

	QyUpkeyData()
	{
		unIndex=0;
		strOwnKey="0";
		strUpKey="0";
		totalRelation=1; //  Ĭ�ϻ�Ĺ�ϵ
		totalScore=0;
		scoreRelation=1;
		goldScore=0;
		silverScore=0;
		redScore=0;
		blueScore=0;
		rankCondition=100;
	}
};

class CQualifyKeyConfig : public NLMISC::CSingleton<CQualifyKeyConfig>
{
public:
	CQualifyKeyConfig( void );
	~CQualifyKeyConfig( void );
	//   ��������;
	void ResetData( void );
	//   ���ر�;
	bool LoadConfig( void );
	//  ��ȡ��ͨ��Ժ��
	QyNormalkeyData* GetQyNormalKey( uint32 );
	//  ��ȡ������Ժ��
	QyUpkeyData*         GetQyUpKeyDataByIndex( uint32 );
	QyUpkeyData*          GetQyUpKeyDataByKey(NLMISC::CSString& strKey);
	uint32  GetQyRankCondition(NLMISC::CSString& strContent);
	bool CheckQyScoreCondition(NLMISC::CSString& strKey,uint32 unGoldeScore,uint32 unSilverScore,uint32 unRedScore,uint32 unBlueScore);
	typedef   std::map<uint32, QyNormalkeyData >    TNormalMapData;
	typedef   std::map<uint32, QyUpkeyData >           TUpMapData;

private:
	TNormalMapData             m_QyNomalKey;
	TUpMapData                    m_QyUpKey;
};

#define QualifyKeyConfig CQualifyKeyConfig::instance()

#endif
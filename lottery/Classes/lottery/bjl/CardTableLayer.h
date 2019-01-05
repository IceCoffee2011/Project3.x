//  [3/26/2014 xieyi]
#ifndef __CARDTABLE_LAYER__
#define __CARDTABLE_LAYER__

// add by hxh 20160706
//#define USE_PRINTTEST
//#define USE_PRINTTEST2

#define MAX_RECORD_NUM (17)   // ��ʾ��¼��Ŀ

#include "cocos2d.h"
#include "DDZRes.h"
#include "SceneData.h"
#include "MyTimer.h"
#include "User.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CardTableLayer : public Node
{
public:

	CardTableLayer();
	~CardTableLayer();
	CREATE_FUNC(CardTableLayer);
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	void waitingMatching(bool isWaiting);			//�ȴ��Ŷ�

	void upHaiou(float ft);
	void haiouCall(Object* _obj);
	
	// �û���ׯ
	void setUserIsOnline(WORD wBankerUser,LONGLONG lBankerScore,LONGLONG lBankerWinScore, WORD	wBankerTime);

	/*
	**	@brief				����ׯ����Ϣ
	**	@wBankerUser		��ǰׯ��
	**	@szBankerNickName	ׯ���ǳ�
	**	@lBankerChip		ׯ�ҳ���
	**	@lBankerWinScore	ׯ�ҳɼ�
	**	@cbBankerTime		ׯ�Ҿ���
	**	@bSystemBanker		ϵͳ��ׯ
	*/
	void updateBankerInfo(WORD wBankerUser, TCHART szBankerNickName[], LONGLONG lBankerChip, LONGLONG lBankerWinScore, WORD cbBankerTime);

	// ����ׯ��ͷ����Ϣ
	void setUserIcon(int userId,int gender,char* name,int gold,char* huafeidian );
	//����ׯ�ҵ��ǳ�<by hxh>
	bool setBankerName(WORD wBankerUser);
	//����ׯ�ҵĽ��
	void setBankerScore(LONGLONG Score);
	//��ȡׯ�ҵĽ��
	LONGLONG getBankerScore();
	//����ׯ�ҵĳɼ��;���
	void setBankUsedChengjiORrJuNumber(LONGLONG Chengji,LONGLONG JuNumber);

	// ��������Լ����ǳ�
	void setNickName(const char * nikeName);
	//������ҵķ����ɼ�
	void setPlayAllScoreORchengji(LONGLONG Chengji);

	//�û���ע���»���
	void UpdatePlacelBankScore(LONGLONG llValue);

	// add by hxh 20160706
#ifdef USE_PRINTTEST
	void PrintTest(Object *obj);
	void PrintTest_callback_once(float t);
#endif

	// add by hxh 20160706
#ifdef USE_PRINTTEST2
	void PrintTest2(Object *obj);
	void PrintTest2_callback_once(float t);
#endif

	void initScrollView(BYTE m_cbPlayerCount ,BYTE m_cbBankerCount);
	void AddWinLostResult(int ZXP);//<by hxh>
	void SetWinLostResult(int i,int ZXP);//<by hxh>
	void SetUpdate();
public:
	cocos2d::extension::ScrollView      *m_pScrollView;
	LONGLONG m_llScore;//<by hxh>
	cocos2d::Size size;// ��Ʒֱ���<by hxh>
private:
	CC_SYNTHESIZE(int,m_coinNumber,CoinNum); 	//�������
	CC_SYNTHESIZE(int,m_hhdNumber,HhdNumber);		//���ѵ�����
	CC_SYNTHESIZE(int,m_times,Times);			//����

	SpriteBatchNode * m_pWinLostRecordBatch;	// ��Ӯ��¼�����<by hxh>
	SpriteBatchNode * m_cardTableBatchNode;		//����batchnode
	SpriteBatchNode * m_pdNode;						//�ŶӶ���
	String getDateNow();						//���ϵͳ��ǰʱ��

	Sprite *SpriteGameRecord;             //��Ϸ��¼

	// ׯ��UI�����Ϊ˽�г�Ա����<by hxh>
#if 1
	Sprite *FinUsedSprite;
	LabelTTF* laberName;   //����
	LabelTTF* goldname;        //���
	LabelTTF* ChengjiScore;  //�ɼ�
	LabelTTF *JiNumber;   //����
#endif

	// ����Լ�UI����<by hxh>
#if 1
	LabelTTF * m_coinNumberAtlas;				//�������
	Sprite *SpriteMyUsed;                        //�û�ͷ��
	//	LabelAtlas * m_hhdAtlas;						//���ѵ���
	LabelTTF * m_nikeName;						//����ǳ�
	LabelTTF *m_Chengji;                          //�û��ɼ�
#endif

public:
	// add by hxh 20160706
#ifdef USE_PRINTTEST
	LabelTTF *Test;
#endif

	// add by hxh 20160706
#ifdef USE_PRINTTEST2
	LabelTTF *Test2;
#endif

	bool hnnnnnnn;
	deque<int> m_vWinLostRecord;// ��Ϸ��¼<by hxh>
};

#endif

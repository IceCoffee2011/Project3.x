#ifndef __CARDTABLE_LAYER__
#define __CARDTABLE_LAYER__

//#define USE_PRINTTEST
//#define USE_PRINTTEST2

#define MAX_RECORD_NUM (17)   // ��ʾ��¼��Ŀ

#include "cocos2d.h"
#include "BJLRes.h"
#include "CMD_BJL.h"
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
	// ����ׯ��ͷ����Ϣ
	void setUserIcon(int userId,int gender,char* name,int gold,char* huafeidian );
	//����ׯ�ҵ��ǳ�<>
	bool setBankerName(WORD wBankerUser);
	//����ׯ�ҵĽ��
	void setBankerScore(LONGLONG Score);
	//����ׯ�ҵĳɼ��;���
	void setBankUsedChengjiORrJuNumber(LONGLONG Chengji,LONGLONG JuNumber);

	// ��������Լ����ǳ�
	void setNickName(const char * nikeName);
	//������ҵķ����ɼ�
	void setPlayAllScoreORchengji(LONGLONG Chengji);

	//�û���ע���»���
	void SetPlaceLandScore(Object *obj);

    //��Ϸ��¼����
	void AddGameRecord(Object *obj);

#ifdef USE_PRINTTEST
	void PrintTest(Object *obj);
	void PrintTest_callback_once(float t);
#endif

#ifdef USE_PRINTTEST2
	void PrintTest2(Object *obj);
	void PrintTest2_callback_once(float t);
#endif

	void initScrollView(BYTE m_cbPlayerCount ,BYTE m_cbBankerCount);
	void AddWinLostResult(int ZXP);
	void SetWinLostResult(int i,int ZXP);
	void SetUpdate();
public:
	cocos2d::extension::ScrollView      *m_pScrollView;
	LONGLONG szText0;
	cocos2d::Size size;// ��Ʒֱ���
private:
	CC_SYNTHESIZE(int,m_coinNumber,CoinNum); 	//�������
	CC_SYNTHESIZE(int,m_hhdNumber,HhdNumber);		//���ѵ�����
	CC_SYNTHESIZE(int,m_times,Times);			//����

	SpriteBatchNode * m_pWinLostRecordBatch;	// ��Ӯ��¼�����
	SpriteBatchNode * m_cardTableBatchNode;		//����batchnode
	SpriteBatchNode * m_pdNode;						//�ŶӶ���
	Sprite *SpriteGameRecord;             //��Ϸ��¼

	// ׯ��UI�����Ϊ˽�г�Ա����
	Sprite *FinUsedSprite;
	LabelTTF* laberName;   //����
	LabelTTF* goldname;        //���
	LabelTTF* ChengjiScore;  //��ַ
	LabelTTF *JiNumber;   //����

	// ����Լ�UI����
	LabelTTF * m_coinNumberAtlas;				//�������
	Sprite *SpriteMyUsed;                        //�û�ͷ��
	LabelTTF * m_nikeName;						//����ǳ�
	LabelTTF *m_Chengji;                          //�û��ɼ�

public:
#ifdef USE_PRINTTEST
	LabelTTF *Test;
#endif

#ifdef USE_PRINTTEST2
	LabelTTF *Test2;
#endif

	bool hnnnnnnn;
	deque<int> m_vWinLostRecord;// ��Ϸ��¼
};

#endif

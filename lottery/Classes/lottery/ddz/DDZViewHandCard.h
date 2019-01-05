//  [3/25/2014 wucan]

#ifndef	DDZ___VIEW_HANDCARD__
#define	DDZ___VIEW_HANDCARD__
#include "cocos2d.h"
#include "DDZViewTask.h"
#include <cmath>
USING_NS_CC;
#define  CARD_SPACE  52
#define  SMALLCARD_SPACE 20

//	��������ͼ����
enum DDZViewChair
{
	DDZViewChair_Last = 0,	//	�ϼ�
	DDZViewChair_Self,		//	�Լ�
	DDZViewChair_Next		//	�¼�
};

class DDZViewHandCard :public Layer
{
public:
	DDZViewHandCard();
	~DDZViewHandCard();
	CREATE_FUNC(DDZViewHandCard);
	virtual bool init();
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);

public:
// 	void setHardCard(DDZCCsendCard* pCardData);	
	void setHardCard(WORD _charID,BYTE _data[],int _num,bool _effect,bool _open);			//��������Լ�����
	void setOutCard(WORD _charID,BYTE* _data,int _num,WORD BankUserID=1000);
	bool UserOutCard(bool isOut);				//--�û�����
	void UserAutoCard();																//--�Զ�����
	void showDiPai(BYTE * _data,int _num,int _lastTask,bool isNew=true);										//--��ʾ����
	void showDipaiEffect(Node* _node);
	void showDipaiSpt(Node* _node);
	bool setHintCard();																	//--������ʾ��
	bool isNoCardout();
	void setUnallowTouch();	//��Ϸ���������˿��Ʋ��ܱ�������
	void removeHintCard();	//�Ƴ����µ��˿���
	void setCardRecover();													//--���Ƹ�ԭ
	void setCardUp(BYTE * _data,int _num);						//--���Ƶ���
	void newRound();

	//	��Ϸ׼������߼�����
	void dealGameReady();

	//	��Ϸ��ʼ����߼�����
	void dealGameStart();

	//	��Ϸ��������߼�����
	void dealGameOver();

	//	����������
	void clearOutCard(DDZViewChair eChair);

	//add by zengxin 20160926  �ڵ�����������ʾ�����Ǳ�
	void showLoadIconOnPokers(bool isLord);

private:
	void showMeUserHardCard(BYTE* _data,int _num,bool _open);		//��ʾ�Լ����е��˿���
	void showhardCardEffect(float deley);
	void showLeftUserHardCard(BYTE* _data,int _num);	//��ʾ�ϼ�����
	void showRightUserHardCard(BYTE* _data,int _num);	//��ʾ�¼�����
	void showLeftHintCard(int _num);					//��ʾ�ϼ��˿��Ƹ��ŵ�����
	void showRightHintCard(int _num);					//��ʾ�¼��˿��Ƹ��ŵ�����

	

	int m_leftCardNum[20];								//�����xλ��
	int m_rightCardNum[20];								//�ұ���xλ��
	bool m_unallowToucn;		//��Ϸ�������˿��Ʋ�������
	Node * m_handCardNode;		//�Լ�����node					--SpriteBatchNode��д�ֻ���֧��̫��
	SpriteBatchNode * m_hintLeftCardNode;	//�ϼҸ��ŵ��˿���node
	SpriteBatchNode * m_hintRightCardNode; //�¼Ҹ��ŵ��˿���node
	Node * m_outCardNodeM;		//�Լ�������
	Node * m_outCardNodeL;		//�ϼҳ�����
	Node * m_outCardNodeR;		//�¼ҳ�����
	Node * m_diPaiNode;			//�����ƣ����ƣ�node
	//	�ϼ�����������ʾ
	Label* m_pDDZLeftCardNum;

	//	�¼�����������ʾ
	Label* m_pDDZRightCardNum;

	// add by zengxin 20160926   �Ƿ�Ϊ������־
	bool m_isLord;

public:
	Sprite* getCardSprite(char _data,int _type,bool isBigCard);
	int			getCardData(BYTE* _data);							//--�õ�����
	int			getCardUpData(BYTE* _data);						//--�õ�up��־����
	bool OnShunziWidom( BYTE cbCardData[], BYTE cbCardCount ,BYTE wisCard[], int& index );
	bool OnLianduiWidom( BYTE cbCardData[], BYTE cbCardCount,BYTE wisCard[], int& index  );
private:
	//����ѡ�������ж�
	//ͨ������ı仯�ж����ƣ����m_distance>m_maxDistance,��ʾ��ɢ�����ƣ���֮��Ϊ��������
	float m_distance; //ǰһ����x��ԭ��ľ���
	float m_maxDistance; //��һ����x��ԭ��ľ���  
	float m_origin;	//ԭ��xλ��
	bool m_isRay;			//�����Ƿ�Ϊ��ɢ
	bool m_isSelect;	//�Ƿ�ѡ�����˿���

	SpriteBatchNode * m_leftCardNode;		//�ϼ�����node
	SpriteBatchNode * m_rightCardNode;		//�¼�����node
	int m_dt[20];					//�˿���ƫ����
	DDZViewTask*				m_viewTask;

	//--����������
	BYTE		m_outCardData[20];
	WORD	m_outCardNum;
	//--����Ч�����
	int        m_effectNum;
	bool     m_isOpenCard;
	//--��������
	BYTE   m_BackData[3];
	int	  m_lastTaskKey;
};

#endif
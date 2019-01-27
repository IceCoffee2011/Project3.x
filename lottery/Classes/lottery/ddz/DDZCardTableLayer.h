//  [3/26/2014 xieyi]
#ifndef DDZ___CARDTABLE_LAYER__
#define DDZ___CARDTABLE_LAYER__

#include "cocos2d.h"
#include "DDZRes.h"
#include "DDZSceneData.h"
#include "DDZTimer.h"
#include "DDZUser.h"
USING_NS_CC;

class DDZCardTableLayer : public Layer
{
public:

	DDZCardTableLayer();
	~DDZCardTableLayer();
	CREATE_FUNC(DDZCardTableLayer);
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	void setMultiplyingPower(int base,int add);		//���ñ���
	void setCoinNumber(int coinNum);				//���ý������
	void waitingMatching(bool isWaiting);			//�ȴ��Ŷ�
	void setUserIsOnline(int userId,bool userIsOnline);		//�����û�����״̬
	void setUserInfor(DDZCCuserInfor* pInfor);										//�����û���ͨͷ����Ϣ
	void setLordIcon(int userId);										//�����û���������
	void setNickName(const char * nikeName);				//�����ǳ�
	void setDiFen(int num);							//���õ׷�

	//	��Ϸ׼������߼�����
	void dealGameReady();

	//	��Ϸ��������߼�����
	void dealGameOver();

	//	ͨ���û�ID��ȡ�û���Ϣ��
	DDZUser* getUserByUserID(long int lnUserID);

	DDZUser * m_userRight;								//�¼�
	DDZUser * m_userLeft;								//�ϼ�
	DDZUser * m_userSelf;								//�ϼ�
	Sprite* m_pImgMiddleReady;						//	ͼƬ�����Լ�׼��

private:

	CC_SYNTHESIZE(int,m_coinNumber,CoinNum); 		//�������
	CC_SYNTHESIZE(int,m_hhdNumber,HhdNumber);		//���ѵ�����
	CC_SYNTHESIZE(int,m_times,Times);				//����
	Label* m_pLabNumGold;							//	�������
	Label* m_pLabNumDiFen;							//	�׷�����
	Label* m_pLabNumMultiple;						//	��������
	LabelTTF * m_nikeName;							//����ǳ�
	SpriteBatchNode * m_pdNode;						//�ŶӶ���

	int m_diFen;										//�׷�
};

#endif

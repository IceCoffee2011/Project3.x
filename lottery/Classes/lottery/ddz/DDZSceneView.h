//  [3/19/2014 wucan]
#ifndef  DDZ___CC_SCENEVIEW_WUCAN_
#define DDZ___CC_SCENEVIEW_WUCAN_
#include "cocos2d.h"
#include "DDZSceneData.h"
#include "DDZViewHandCard.h"
#include "DDZCardTableLayer.h"
#include "DDZViewCardEffect.h"
#include "DDZSettlement.h"
#include "DDZViewTask.h"
#include "DDZSetUpLayer.h"
#include "DDZVoiceAndFace.h"
#include "DDZDialogLayer.h"
#include "DDZSoundControl.h"
#include "DDZGameTaskCommon.h"
USING_NS_CC;

class DDZSceneLogic;
class DDZViewMenuLayer;

class DDZSceneView:public Node
{
public:
	DDZSceneView(void);
	virtual ~DDZSceneView(void);
	CREATE_FUNC(DDZSceneView);
	virtual bool init();
	virtual void onExit();//add by hxh 20160819
	void LoadRes();//add by hxh 20160818
	void OnMessage(Object* obj);
	void receiveMenuClickCallfunc(Object * obj);	//--�˵���ť�����Ļص�
	void onBankrupt(Object * obj);							//--��Ϸ�Ʋ����ش���
	void onLlinkOFF(float ft);							//--����Ͽ����ش���
	void wangZha(Object *obj);
	bool						m_isLandLord;					//--��һ�νе���

	//add by zengxin �����Ƿ��һ�ν��не���
	void setIsFistLandLord(bool first);

	CC_SYNTHESIZE(int, m_bankId, BankId);//��ǰ����λ�ú�,  1��ʱ��Ϊ��ǰ��ң�0��2����
	//--���ܺ���
private:
	void userInforDeal(Integer* _data);
	void dealSitDown(Integer* _data);
	void startGameDeal();
	void startGameViewDeal(Integer* _data);
	void onBackTaskDeal(Integer* _data);
	void addViewDeal(Integer* _data);
	void sendCardDeal(Integer* _data);
	void openCardDeal(Integer* _data);
	void landLordDeal(Integer* _data);
	void timeConreolDral(Integer* _data);
	void outCardDeal(Integer* _data);
	void passCardDeal(Integer* _data);
	void gameOverDeal(Integer* _data);
	void timeCallBackDeal(Integer* _data);
	void timeAgencyDeal(float ft);
	//	����ʧ��
	void onSitFaild(Object* obj);

	//	�����¼ʧ��
	void onLoginFaild(Object* obj);

	//	��Ϸ��������߼�����
	void dealGameOver();

	//	����ȴ�״̬
	DWORD dealWaitingState();

private:
	DDZViewHandCard*     m_handCardView;
	DDZViewCardEffect*    m_effectView;
	CC_SYNTHESIZE(DDZViewMenuLayer *,m_menuLayer,MenuLayer);
	Layer * m_dialogLayer;
	CC_SYNTHESIZE(DDZCardTableLayer*,m_cardTableLayer,DDZCardTableLayer);
	DDZSceneLogic* m_pSceneLogic;

	int						m_AgencyNum;				//--���û������
	bool						m_isAgency;						//--�����˴���

	//--������Ϸ�й�
	DDZGame_State			m_gameStae;					//--��Ϸ״̬
	int						m_timeKey;
	unsigned int m_userOutCardState;				//�û�����״̬��//���������Ҳ������ƣ��������ֳ��������ƣ�������󷽣����ڵ�һ�ֳ��ƣ�
	unsigned int g_tableConsume;					//��������

};
#endif

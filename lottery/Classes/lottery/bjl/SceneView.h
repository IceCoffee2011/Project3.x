//  [3/19/2014 wucan]
#ifndef  __CC_SCENEVIEW_WUCAN_
#define __CC_SCENEVIEW_WUCAN_
#include "cocos2d.h"
#include "SceneData.h"
#include "ViewHandCard.h"
#include "CardTableLayer.h"
#include "ViewMenuLayer.h"
#include "ViewCardEffect.h"
#include "Settlement.h"
#include "ViewTask.h"
#include "SetUpLayer.h"
#include "VoiceAndFace.h"
#include "DialogLayer.h"
#include "SoundControl.h"
#include "GameTaskCommon.h"
#include "SceneLogic.h"

USING_NS_CC;

class SceneView:public Node
{
public:
	// �л�������<add by hxh 20160702>
	static void ToPortrait();
	// �л�������<add by hxh 20160702>
	static void ToLandscape();
public:
	SceneView(void);
	~SceneView(void);
	CREATE_FUNC(SceneView);
	virtual bool init();
	virtual void onExit();//add by hxh 20160819
	void LoadRes();//add by hxh 20160617
	void OnMessage(Object* obj);
	void receiveMenuClickCallfunc(Object * obj);	//--�˵���ť�����Ļص�
	void onBankrupt(Object * obj);							//--��Ϸ�Ʋ����ش���
	void onLlinkOFF(float ft);							//--����Ͽ����ش���
	void onLoginFaild(Object* obj);					//��¼ʧ��<by hxh>
	void onSitFaild(Object* obj);					    //����ʧ��<by hxh>
    void CloseNetWorkShut(Object *obj);
	void OnBankerListAdd(Object *obj);// ��ׯ�б�����һ����¼<by hxh>
	void OnBankerListDelete(Object *obj);// ��ׯ�б�ɾ��һ����¼<by hxh>
	void OnMeApplyBankerSuc(Object *obj);//�Լ�������ׯ�ɹ�<by hxh>
	void OnMeUpBankerSuc(Object *obj);//�Լ���ׯ�ɹ�<by hxh>
	void OnMeCancelUpBanker(Object *obj);//�Լ�ȡ��������<by hxh>
	void OnMeDownBanker(Object *obj);//�Լ���ׯ<by hxh>
	void SetCloseCall( Object *obj );
	void OnUpBanker( Object *obj );//��ׯ<by hxh>
	void OnCancelUpBanker( Object *obj );//ȡ������<by hxh>
	void OnDownBanker( Object *obj );//��ׯ<by hxh>
	void OnBankerList( Object *obj );//��ׯ�б�<by hxh>

	//--���ܺ���
	void ShowCurrentMenu(int j);//<by hxh>

	SceneLogic* m_pSceneLogic;
private:
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
	
	void Strameobjet(Object *obj);
	void StrameNumberbjet(Object *obj);

	WORD m_wBankerUser;						//��ǰׯ��
private:
	ViewCardEffect*    m_effectView;
	CC_SYNTHESIZE(ViewMenuLayer *,m_menuLayer,MenuLayer);
    CC_SYNTHESIZE(int,m_currentMenu,CurrentMenu);//1������ׯ��2ȡ�����룬3��Ҫ��ׯ<by hxh>
	//Settlement * m_settlementNode;
	//VoiceAndFace*     m_face;
	GameTaskCommon* m_gameTask;
	Layer * m_dialogLayer;

	Menu * m_Menu1;
	Menu * m_Menu2;
	Menu * m_Menu3;
	cocos2d::Size winSize;// ��Ʒֱ��ʴ�С<by hxh>
	int  cAddScoreUseid;   //ׯ��id
	bool ScoreUseidbool;
	int						m_AgencyNum;				//--���û������
	bool						m_isAgency;						//--�����˴���

	//--������Ϸ�й�
	Game_State			m_gameStae;					//--��Ϸ״̬
	int						m_timeKey;
	bool						m_isLandLord;					//--��һ�νе���
	unsigned int m_userOutCardState;				//�û�����״̬��//���������Ҳ������ƣ��������ֳ��������ƣ�������󷽣����ڵ�һ�ֳ��ƣ�
	unsigned int g_tableConsume;					//��������

};
#endif

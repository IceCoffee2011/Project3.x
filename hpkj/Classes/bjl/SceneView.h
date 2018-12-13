#ifndef  __CC_SCENEVIEW_WUCAN_
#define __CC_SCENEVIEW_WUCAN_
#include "cocos2d.h"
#include "CardTableLayer.h"
#include "ViewMenuLayer.h"
#include "SetUpLayer.h"
#include "DialogLayer.h"
#include "SoundControl.h"

#include "UpBankerList.h"

USING_NS_CC;

class SceneView:public Node
{
public:
	// �л�������
	static void ToPortrait();
	// �л�������
	static void ToLandscape();
public:
	SceneView(void);
	~SceneView(void);
	CREATE_FUNC(SceneView);
	virtual bool init();
	void LoadRes();
	void OnMessage(Object* obj);
	void receiveMenuClickCallfunc(Object * obj);	//--�˵���ť�����Ļص�
	void onBankrupt(Object * obj);							//--��Ϸ�Ʋ����ش���
	void onLlinkOFF(float ft);							//--����Ͽ����ش���
	void onLoginFaild(Object* obj);					//��¼ʧ��
	void onSitFaild(Object* obj);					    //����ʧ��
    void CloseNetWorkShut(Object *obj);
	void OnBankerListAdd(Object *obj);// ��ׯ�б�����һ����¼
	void OnBankerListDelete(Object *obj);// ��ׯ�б�ɾ��һ����¼
	void OnMeApplyBankerSuc(Object *obj);//�Լ�������ׯ�ɹ�
	void OnMeUpBankerSuc(Object *obj);//�Լ���ׯ�ɹ�
	void OnMeCancelUpBanker(Object *obj);//�Լ�ȡ��������
	void OnMeDownBanker(Object *obj);//�Լ���ׯ
	void SetCloseCall( Object *obj );
	void OnUpBanker( Object *obj );//��ׯ
	void OnCancelUpBanker( Object *obj );//ȡ������
	void OnDownBanker( Object *obj );//��ׯ
	void OnBankerList( Object *obj );//��ׯ�б�

	//--���ܺ���
	void ShowCurrentMenu(int j);
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

	int longNumberuserInforID;   //ׯ��Id
private:
	CC_SYNTHESIZE(ViewMenuLayer *,m_menuLayer,MenuLayer);
    CC_SYNTHESIZE(int,m_currentMenu,CurrentMenu);//1������ׯ��2ȡ�����룬3��Ҫ��ׯ
	UpBankerList* m_UpBankerList;
	Layer * m_dialogLayer;

	Menu * m_Menu1;
	Menu * m_Menu2;
	Menu * m_Menu3;
	cocos2d::Size winSize;
	int  cAddScoreUseid;   //ׯ��id
	bool ScoreUseidbool;
	int						m_AgencyNum;				//--���û������
	bool						m_isAgency;						//--�����˴���

	//--������Ϸ�й�
	int			            m_gameStae;					//--��Ϸ״̬
	int						m_timeKey;
	bool						m_isLandLord;					//--��һ�νе���
	unsigned int m_userOutCardState;				//�û�����״̬��//���������Ҳ������ƣ��������ֳ��������ƣ�������󷽣����ڵ�һ�ֳ��ƣ�
	unsigned int g_tableConsume;					//��������

};
#endif

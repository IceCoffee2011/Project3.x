#ifndef __DZPKLAYER_SCENE_H__
#define __DZPKLAYER_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "EntityMgr.h"
#include "DZPKOperaLayer.h"
#include "RoomLight.h"//by hxh
#include "trusteeship.h"
#include "RoyalFlush.h"
#include "CMD_DZPK.h"
#include "UserDZPK.h"
#include "DZPKChipPot.h"

// add by hxh 20160919
// #define USE_PRINTTEST
#define USE_PRINTSCORE
#define MAX_TEST_NUM (2)
#define MAX_SCORE_NUM (5)

USING_NS_CC;

enum MyTage
{
	StartTag=0,                                      //��ʼ
	LeaveTag=1,                                      //�뿪
	ExitTag=2,                                       //�˳�
	ApTage_03,
	ApTage_04,
    DZPKLayerTag=10,                                 //��Ϸ������<by hxh>
};

/*
    ��Ϸ������
*/
class DZPKLayer : public cocos2d::Layer
{
public:
	DZPKLayer();
	~DZPKLayer();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	static cocos2d::Scene* scene();
	CREATE_FUNC(DZPKLayer);
public:
	void LoadRes();//dzpk-jhy
	static void dzpk_ToPortrait();//dzpk-jhy
	static void dzpk_ToLandscape();//dzpk-jhy
	static void ExitDZPK();

	// ���Ӻ�ת��
	static unsigned int switchViewChairID(unsigned int nChairID);

	//	��λ��ר��
	static void studioUI(Node* pParent, Node* pChild);

	//	������ʾ������
	static void showDebugTips(string sText);

	//	��ʼ������
	void initData();

	//	��ʼ�������ͼ
	void initPlayerView();

	//	��������
	void resetData();

	//	ˢ�������Ϣ
	void upDatePlayer(tagUserData sData);

	//  ������ҽ��<by hxh>
	void updatePlayerGold(WORD iViewID,LONGLONG lAddScore);

	//	��ʾD���
	void showDPlayer(int nViewID);

	//	��ʾäע���
	void showBlindPlayer(EDZPKBlindType eType, int nViewID);

	//	����äע���
	void hideBlindPlayer();

	//	��ʾ����ж���ʶ
	void onPlayerBehavior(int nViewID, int nType);

	//	ȡ������ʱ
	void cancelCountdown(int nViewID);

	//	��ע
	void dealBet(int nViewID, LONGLONG llValue);

	//	����
	void dealCollect(int nViewID);

	//	�ַ�
	void dealDistribute(int nViewID, LONGLONG llValue);

	/*
	**	@brief	��ȡ�����Ϣ
	**	@lnUserID	���ID
	**	@return	���ظ������Ϣ�����û���ҵ��򷵻�NULL
	*/	
	UserDZPK* getPlayer(LONGLONG llUserID);

	//	���ƶ���
	void aniSendCard();

	//	��ʾ�����������
	void showAllPlayerCard(char cHandCard[][2]);

	//	���������п��Ʊ�Ұ�
	void setAllCardDark(char cHandCard[][2]);

	//	��ʾӮ�Ҹ�������
	void showCardHighLight(int nViewID, char cLastCard[]);

	//	�������׼���׶α���
	void dealPlayerReady();

	void AddObject();
	void RemoveObject();
	void winAnimate(int iViewID,BYTE cardtype);
	void onUserStart(Object *pSender);//<add by hxh 20160825>
	void onLoginConnectFaild(Object* obj);
	void onShutNetwork(Object* obj);
	void OtherStarya(Object *obj);
	void onUpdateTable(Object* obj);
	void onMessageGame(Object* obj);
	void onMessageScene(Object* obj);
	void onMessageMatchPlayer(Object* obj);
	void onLoginRoomFailed(Object* obj);
	void onSitFaild(Object* obj);					    //����ʧ��<by hxh>
	bool onSceneMessage(unsigned char cbStation,const void* pBuffer,unsigned short wDataSize);
	bool onGameMessage(unsigned short wSubCmdID, const void* pBuffer, unsigned short wDataSize);

	//��Ϣ����
protected:
	//����״̬<by hxh>
	bool OnGameSceneFree(const void *pBuffer, WORD wDataSize);
	//��Ϸ״̬<by hxh>
	bool OnGameScenePlay(const void *pBuffer, WORD wDataSize);
	//��Ϸ��ʼ
	bool OnSubGameStart(const void * pBuffer, WORD wDataSize);
	//�û���ע
	bool OnSubAddScore(const void * pBuffer, WORD wDataSize);
	//�û�����
	bool OnSubGiveUp(const void * pBuffer, WORD wDataSize);
	//������Ϣ
	bool OnSubSendCard(const void * pBuffer, WORD wDataSize);
	//��Ϸ����
	bool OnSubGameEnd(const void * pBuffer, WORD wDataSize);
	//������Ϣ
	bool OnSubOpenCard(const void * pBuffer, WORD wDataSize);
	
	Menu * createExitMenu();// ���˳���<by hxh>
	Menu * createStartLeaveMenu();// ����ʼ�������뿪��<by hxh>

	void OnActionThink(int iViewID);		//�����ע��...<by hxh>

	void updateTest(Object* obj);		    //<by hxh>
    void setScore1(LONGLONG lCellScore);		//����äע<by hxh>
    void setScore2(LONGLONG lTurnMaxScore);		//���������ע<by hxh>
    void setScore3(LONGLONG lTurnLessScore);    //������С��ע<by hxh>
    void setScore4(LONGLONG lAddLessScore);    //���ü���Сע<by hxh>
	
	void showOperaBtns();//��ʾ��ע���Ͱ�ť<by hxh>

	// ɾ�������ǩ
	void CloseWinLose(float t);
	// ��ҳ�ʱû��׼��
	void CloseRoundOpera(float t);	
	// ����ʼ�������뿪�������˳�������
	void LeaveGameResume(Object* obj);
	// ��ʼ��һ��
	void restartGame(float t);																

	tagUserData* getMeUserDate() { return EntityMgr::instance()->roomFrame()->getMeUserItem()->getUserData(); }
	WORD getMeChairID(){return EntityMgr::instance()->getDispatch()->m_wChairID;};

	// add by hxh 20160919
#ifdef USE_PRINTTEST
	void PrintTest(Object *obj);
	void PrintTest_callback_once(float t);
	void PrintTest1(Object *obj);
	void PrintTest1_callback_once(float t);
#endif

	// add by hxh 20160919
#ifdef USE_PRINTSCORE
	void PrintScore1(Object *obj);
	void PrintScore1_callback_once(float t);
#endif

	//��ע��Ϣ
public:
	LONGLONG						m_lCellScore;						//��Ԫ��ע,����ָСäע<by hxh>
	LONGLONG						m_lTurnLessScore;					//��С��ע
	LONGLONG						m_lTurnMaxScore;					//�����ע
	LONGLONG						m_lAddLessScore;					//��С��ע
	LONGLONG						m_lCenterScore;						//���ĳ���

	cocos2d::Size                            m_WinSize;                                      //��Ʒֱ���
	RoomLight*                      m_roomLight;                                    //�ƹ�<by hxh>
	DZPKOperaLayer*					m_pOperaLayer;									//��ť�������
	DZPKChipPot*					m_pChipPot;										//	�����
	Menu*							m_StartLeave;									//����ʼ�������뿪��
	DZPKCommunityCards*				m_pCommunityCards;								//	������
	
#ifdef USE_PRINTSCORE
	LabelTTF *m_Score[MAX_SCORE_NUM];
#endif

	//Trusteeship*					m_pTrusteeship;									//�йܽ���
	RoyalFlush*						m_pRoyalFlush;									//�ʼ�ͬ��˳����

	map<int, UserDZPK*> m_mPlayerList;	//	����б�

};

#endif  // __DZPKLAYER_SCENE_H__
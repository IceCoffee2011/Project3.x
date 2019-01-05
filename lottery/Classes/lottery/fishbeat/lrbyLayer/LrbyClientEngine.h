#ifndef _LKPY_GAME_CLIENTENGINE_H_ 
#define _LKPY_GAME_CLIENTENGINE_H_

#pragma once

#include "cocos2d.h"
#include "CMD_Fish.h"
#include "GameScene.h"
#include "LrbyClientView.h"
#include "GlobalDef.h"
#include "TableData.h"

#include "EntityMgr.h"
#include "MyNSString.h"
#include "Define.h"

class LrbyClientEngine : public Node
{
public:
	static int	switchViewChairID(unsigned int nChairID); 
//=========================================================================================
	//�ؼ�����
protected:
	//IClientKernel*					m_pClientKernel;
	//�û�����
public:
	LrbyClientView*					m_pGameClientView;					//��Ϸ��ͼ
	TCHART							m_szAccounts[BY_GAME_PLAYER][LEN_NICKNAME];
	bool							m_bBackGroundSound;					//��������
	tagDDZUserInfoHead*                    m_userInfo[BY_GAME_PLAYER];			//�û���Ϣ
	bool                            m_isGameStart;
	int								m_MyChair;
	bool							m_isMyself;
	//��Ϸ����
public:
	char							m_userChat[LEN_USER_CHAT * 2];		//��������
	BYTE							m_userChatID;						//��������
public:
	LrbyClientEngine(void);
	virtual~LrbyClientEngine(void);

	CREATE_FUNC(LrbyClientEngine);
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
public:
	//��ȡ�ں�
	//IClientKernel* getClientKernel()const{return m_pClientKernel;};
	//�ͷŶ���
	virtual void Release(){ 
		delete this;
	}
	//�ӿڲ�ѯ
	//virtual void * QueryInterface(REFGUID Guid, DWORD dwQueryVer){return NULL;}
public:
//	void AllowFire(bool allow) { allow_fire_ = allow; }

	//��Ϣ����

	//��Ϣ����  add by zengxin
	void onMessageGame(Object* obj);			
	void onMessageScene(Object* obj);		
	void onUpdateTable(Object* obj);		
	void onUpdataMatch(Object* obj);		//this Messager is userd to change gear
	void onViewMessage(Object* obj);
	//bool onSceneMessage(unsigned char cbStation,const void* pBuffer,WORD wDataSize);
	//bool onGameMessage(WORD wSubCmdID, const void* pBuffer, WORD wDataSize);

	void onUpdateNotification();

protected:
	bool OnSubExchangeFishScore(void* data, WORD data_size);	//�������õĽ��
	bool OnSubSwitchScene(void* data, WORD data_size);			//�����л�
	bool OnSubHitFishLK(void* data, WORD data_size);			//		
	bool OnSubCatSweepFishResult(void* data, WORD data_size);	//
	bool OnSubCatSweepFish(void* data, WORD data_size);			//
	bool OnSubLockTimeout(void* data, WORD data_size);			//����ʱ�����
	bool OnSubBulletIonTimeout(void* data, WORD data_size);		//Ion�ӵ�ʱ�����
	bool OnSubCatchFish(void* data, WORD data_size);			//������
	bool OnSubUserFire(void* data, WORD data_size);				//��߿���
	bool OnSubFishTrace(void* data, WORD data_size);			//�µ���Ⱥ����
	bool OnSubSceneEnd(void* data, WORD data_size);				//�л���������
	bool OnSubStockOperateResult(void* data, WORD data_size);	//
	bool OnSubGameConfig(void* data, WORD data_size);			//��Ϸ������Ϣ
	bool OnOnLineAward(void* data, WORD data_size);				//��Ϸ���߽���
	bool OnSubTimeStamp(void* data, WORD data_size);			//ʱ���<by hxh>
	// ��ʼ��Ϣ;
	void Start();
public :
	// ǿ��
	void CloseGameView();
	// ��ʼ����Ϸ��ͼ
	virtual void* InitGameView();
	// ��ȡ��Ϸ��ͼ
	virtual void* GetGameView();
	//
	virtual DWORD GetGameVersion();
	// ��Ϸ��ʼ��
	virtual bool OnInitClientKernel(TableData* clientKernel);
	// 
	void ReleaseGameView();
	// �ȼý���
	virtual bool OnGetAlmsResult(BYTE cbRetCode);
	// �Թ�״̬
	virtual void OnEventLookonMode(bool bLookonUser, void* pData, WORD wDataSize);
	// ������Ϣ
	virtual bool OnEventFrameMessage(WORD wSubCmdID, void* pData, WORD wDataSize);
	// ��Ϸ��Ϣ
	virtual bool OnEventGameMessage(WORD wSubCmdID, void* pData, WORD wDataSize);
	// ������Ϣ
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void * pData, WORD wDataSize);
	// ���������Ϣ
	virtual bool AddGameTableMessage(TCHART* strMessage, WORD wType);
	// ���������Ϣ
	virtual bool OnEventMatchMessage(WORD wSubCmdID, void* pData, WORD wDataSize);
	// �û�����
	virtual void OnEventUserEnter(tagDDZUserInfoHead* userInfo, WORD wChairID, bool bLookonMode);
	// �û��뿪
	virtual void OnEventUserLeave(tagDDZUserInfoHead* userInfo, WORD wChairID, bool bLookonMode);
	// �û�����
	virtual void OnEventUserScore(tagDDZUserInfoHead* userInfo, WORD wChairID, bool bLookonMode);
	// �û�״̬
	virtual void OnEventUserStatus(tagDDZUserInfoHead* userInfo, WORD wChairID, bool bLookonMode);
	// �û���Ա
	virtual void OnEventUserMemberOrder(tagDDZUserInfoHead* userInfo, WORD wChairID,bool bLookonMode);
	// ����״̬
	virtual void OnEventTableStatus(BYTE cbTableStatus);
	// ���ÿ��
	virtual void ResetGameFrame();
	// ��Ϣ��ʾ�봦��
	virtual bool OnMessage(WORD wType, const char * szText);
	// ��ȡ�Թ�
	virtual bool GetAllowLookon();
	// ��ʱ��
	virtual bool OnTimer(unsigned int uTimerID, unsigned int uBindParameter);
	// ���붩�����
	virtual bool OnApplyOrderResult(signed int nResultCode, uint16_t wCardTotal, uint32_t dwOrderAmount,const char* lpszOrderID,TCHART* lpszDesc);
	// ֧�����
	virtual bool OnPayResult(signed int nResultCode, uint8_t cbScoreType, LONGLONG lScore,TCHART* lpszDesc);
	// ϵͳ��Ϣ
	virtual bool OnSystemMessage(WORD wType, TCHART* strMessage);
};

#endif //_LKPY_GAME_CLIENTENGINE_H_

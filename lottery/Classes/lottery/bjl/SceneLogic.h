//  [3/19/2014 wucan]
#ifndef		__CC_SCENELOGIC_WUCAN__
#define		 __CC_SCENELOGIC_WUCAN__
#include "cocos2d.h"
#include "SceneData.h"
// #include "SceneView.h"
#include "CardManager.h"
#include "OperalayerBJL.h"
#include "ChipManager.h"
#include "CardTableLayer.h"
#include "ViewMenuLayer.h"

USING_NS_CC;

//	�ټ��֡�����Ϸ״̬
enum EBJLGameState
{
	EBJLGameState_Null = 0,	//	��
	EBJLGameState_Start,	//	��Ϸ��ʼ
	EBJLGameState_Idle,		//	����ʱ��
	EBJLGameState_Bet,		//	��עʱ��
	EBJLGameState_End		//	��Ϸ����
};

class SceneLogic:public Node
{
public:
	CREATE_FUNC(SceneLogic);
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	//��Ϣ����
	void onMessageGame(Object* obj);			
	void onMessageScene(Object* obj);		
	void onUpdateTable(Object* obj);		
	void onUpdataMatch(Object* obj);		//this Messager is userd to change gear
	void onViewMessage(Object* obj);
	bool onSceneMessage(unsigned char cbStation,const void* pBuffer,WORD wDataSize);
	bool onGameMessage(WORD wSubCmdID, const void* pBuffer, WORD wDataSize);

	CC_SYNTHESIZE(EBJLGameState, m_eGameState, GameState);

	//������Ϸ״ֵ̬
	EBJLGameState	GetGameState();

	//ϵͳ����
	// ��ȡ��ֵ
	static int GetCardValue(int nCardData) {
		return nCardData & MASK_VALUE;
	}

	// ��ȡ��ɫ
	static int GetCardColor(int nCardData) {
		return nCardData & MASK_COLOR;
	}

	// �߼���ֵ
	static int GetCardLogicValue(int nCardData) {
		// ��ֵ��ɫ
		int nCardValue = SceneLogic::GetCardValue(nCardData);
		int nCardColor = SceneLogic::GetCardColor(nCardData);

		// ת��
		if (nCardColor == 0x40) {
			return nCardValue + 2;
		}
		return (nCardValue <= 2) ? (nCardValue + 13) : nCardValue;
	}
private:
	tagUserData* getMeUserDate() { return EntityMgr::instance()->roomFrame()->getMeUserItem()->getUserData(); }
	WORD getMeChairID(){return getMeUserDate()->wChairID;}
	WORD getMeChairID1(){
		WORD meChairID = EntityMgr::instance()->getDispatch()->m_wChairID;
		return meChairID;
	}
	int	switchViewChairID(unsigned int nChairID);
	//_stateȡֵ��0����ʱ�䡢1��עʱ�䡢������ע��ʾ��2����ʱ��<by hxh 20160610>
	void setGameStateTip(int _state);

	//ׯ�Һ��мҵ���ע��ʾ��һ��<by hxh 20160719>
	void setCallScoreTip(bool isMeBanker);
	//jȡֵ��1������ׯ��2�ֻ�ׯ�ҡ�3������ׯ<by hxh 20160720>
	void setChangeBankerTip(int j);
	void ChangeBankerTip_callback_once(float t);
	void sendSeverData(WORD wSubCmdID);
	void sendSeverData(WORD wSubCmdID,void* pData,WORD wDataSize);
	void sendFrameData( WORD wSubCmdID,void* pData,WORD wDataSize);
	void checkNet(float ft);
	void onLinkResult(Object* obj);
	void onUpdateScoreAndGoldEgg(Object* obj);
	int getUserRealChairID(DWORD userID);
	//���ܺ���
private:
	// �յ���Ϸ���������Ȼ��������������ƺ��������Ϸ��¼��ˢ�½�ҡ��ɼ�������<by hxh 20160811>
	void AddGameRecord(Object *obj);

	void onUserStart(Object *pSender);
	bool onUserStartView(const void * pBuffer, WORD wDataSize);
	bool onUserBEeiLv(const void * pBuffer, WORD wDataSize);
	bool onUserAdd(const void * pBuffer, WORD wDataSize);
	bool onSubSendCard(const void * pBuffer, WORD wDataSize);
	bool onSubLandScore(const void * pBuffer, WORD wDataSize);
	bool onSubGameStart(const void * pBuffer, WORD wDataSize);
	bool onSubOutCard(const void * pBuffer, WORD wDataSize);
	bool onSubPassCard(const void * pBuffer, WORD wDataSize);
	//��Ϸ����;
	bool onSubGameEnd(const void * pBuffer, WORD wDataSize);
	//���� ����
	bool onUserExpression(const void * pBuffer, WORD wDataSize);
	//��ʾ��Ϣ<by hxh>
	bool onSubTipInfo( const void * pBuffer, WORD wDataSize);
	//��Ϸ��¼
	bool OnSubCheatCard(const void * pBuffer, WORD wDataSize);
	//ȡ����ׯ
	bool OnSubUserCancelBanker(const void * pBuffer, WORD wDataSize);
	//��Ϸ����
	bool OnSubGameFree(const void *pBuffer, WORD wDataSize);
	//����״̬<by hxh>
	bool OnGameSceneFree(const void *pBuffer, WORD wDataSize);
	//��ע�׶�<by zengxin>
	bool OnGameSceneOnBet(const void *pBuffer, WORD wDataSize);
	//��Ϸ״̬<by hxh>
	bool OnGameScenePlay(const void *pBuffer, WORD wDataSize);

	//<add by hxh 20160720>
	void showMoveingLabelTips(const char* str);

	cocos2d::Size					size;// ��Ʒֱ��ʴ�С<by hxh>
	ViewMenuLayer					*m_menuLayergic;
	CardManager*					m_pCardManager;									//�ƹ�����
	OperaLayer *                    m_OperaLayer;
	ChipManager*                    m_chipManager;                                   //���������
	Sprite *SpriteGameStare;        //��Ϸ��ʼ��������ע��ǩ
	Sprite *SpriteGameTime;         //ʱ���־
	Sprite *SpriteChangeBanker;     //�л�ׯ�ұ�־<by hxh>
	OperaLayer *operlayer;

	CC_SYNTHESIZE(CardTableLayer*, m_cardTableLayer, CardTableLayer);

private:
	//--����
	BYTE						m_handCardData[GAME_PLAYER][MAX_COUNT];						//�˿��б�
	WORD						m_handCardNum[GAME_PLAYER];
	//--����
	BYTE						m_BackCardData[GAME_PLAYER];								//����
	//--���������
	BYTE						m_outCardData[MAX_COUNT];
	WORD						m_outCardNum;
	WORD						m_beilv;
	BYTE						m_bLastCallScore;													
	WORD						m_wCurrentUser;												//��ǰ���
	WORD						m_wTempUser;												//�ϼ�
	WORD						m_nBankerUser;												//����
	bool						m_wOpenUser[GAME_PLAYER];									//�������
	bool                        m_isMeBanker;// �Ƿ���ׯ<by hxh>
	int                         m_ChangeBanker;// �л�ׯ�ұ�־<by hxh>
	WORD						m_baseScore;												//��Ϸ��������
	bool						m_isOut;
	//������Ϣ
protected:
	LONGLONG						m_lPlayBetScore;					//��������ע
	LONGLONG						m_lPlayFreeSocre;					//������ɻ���

	//��ע��
protected:
	LONGLONG						m_lAllBet[AREA_MAX];				//����ע
	LONGLONG						m_lPlayBet[AREA_MAX];				//�����ע
	LONGLONG						m_lPlayScore[AREA_MAX];				//�����Ӯ

	//ׯ����Ϣ
protected:
	WORD							m_wBankerUser;						//��ǰׯ��
	LONGLONG						m_lBankerScore;						//ׯ�һ���
	//LONGLONG						m_lBankerWinScore;					//ׯ��Ӯ��
	//WORD							m_wBankerTime;						//ׯ�Ҿ���
	//bool							m_bEnableSysBanker;					//ϵͳ��ׯ

	//�û���ע
	LONGLONG m_lBetScore[8];							//��ע��Ŀ

	//��Ϸ����
protected:
	CMD_S_GameEnd                   m_GameEnd;                              //��Ϸ����<by hxh>
	//�˿���Ϣ
	BYTE							m_ucHandCardData[3];					//�м�����<by hxh>
	BYTE							m_ucHandCardData1[3];					//ׯ������<by hxh>

	BYTE							m_cbTableCardArray[2][3];				//�����˿�

	//ׯ����Ϣ
	//LONGLONG						m_plBankerScore;						//ׯ�ҳɼ�
	//LONGLONG						m_plBankerTotallScore;					//ׯ�ҳɼ�
	//int								m_pnBankerTime;						//��ׯ����

	//��ҳɼ�
	//LONGLONG						m_plPlayScore[AREA_MAX];				//��ҳɼ�
	//LONGLONG						m_plPlayAllScore;						//��ҳɼ�

	//ȫ����Ϣ
	//LONGLONG						m_plRevenue;							//��Ϸ˰��
};		
#endif

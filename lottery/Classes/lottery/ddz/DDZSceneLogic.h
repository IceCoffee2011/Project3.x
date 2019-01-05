//  [3/19/2014 wucan]
#ifndef		DDZ___CC_SCENELOGIC_WUCAN__
#define		DDZ___CC_SCENELOGIC_WUCAN__
#include "cocos2d.h"
#include "DDZSceneData.h"
#include "EntityMgr.h"

USING_NS_CC;
class DDZSceneView;
class DDZSceneLogic:public Node
{
public:
	CREATE_FUNC(DDZSceneLogic);
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

	CC_SYNTHESIZE(DDZSceneView*,m_DDZSceneView,DDZSceneView);

	//	��λ��ר��
	static void studioUI(Node* pParent, Node* pChild);


	//	��ȡ��Ϸ״̬
	DDZGame_State getGameState() const;


   //��Ϸ����
    bool gameMain(WORD wSubCmdID, const void *pData, WORD wDataSize);


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
		int nCardValue = DDZSceneLogic::GetCardValue(nCardData);
		int nCardColor = DDZSceneLogic::GetCardColor(nCardData);

		// ת��
		if (nCardColor == 0x40) {
			return nCardValue + 2;
		}
		return (nCardValue <= 2) ? (nCardValue + 13) : nCardValue;
	}
	static int	switchViewChairID(unsigned int nChairID); 
	BYTE							m_BackCardData[DDZGAME_PLAYER];								//����

private:
	tagUserData* getMeUserDate() { return EntityMgr::instance()->roomFrame()->getMeUserItem()->getUserData(); }
	WORD getMeChairID(){return getMeUserDate()->wChairID;}
	WORD getMeChairID1(){
		WORD meChairID = EntityMgr::instance()->getDispatch()->m_wChairID;
		return meChairID;
	}
	void sendSeverData(WORD wSubCmdID);
	void sendSeverData(WORD wSubCmdID,void* pData,WORD wDataSize);
	void sendFrameData( WORD wSubCmdID,void* pData,WORD wDataSize);
	void checkNet(float ft);
	void onLinkResult(Object* obj);
	void onUpdateScoreAndGoldEgg(Object* obj);
	int getUserRealChairID(DWORD userID);
	//���ܺ���
private:
    //��Ϸ��ʼ
    bool OnSubGameStart(const void * pdata, WORD wDataSize);
#if 0
    //�û��е���
    bool OnSubCallBanker(const void * pdata, WORD wDataSize);
    //�û�������
    bool OnSubRodBanker(const void * pdata, WORD wDataSize);
    //�ӱ���Ϣ
    bool OnSubDouble(const void * pdata, WORD wDataSize);
    //�û�����
    bool OnSubValidCard(const void * pdata, WORD wDataSize);
    //ׯ����Ϣ
    bool OnSubBankerInfo(const void * pdata, WORD wDataSize);
    //�û�����
    bool OnSubOutCard(const void * pdata, WORD wDataSize);
    //�û�����
    bool OnSubPassCard(const void * pdata, WORD wDataSize);
    //���ƿ�ʼ
    bool OnSubOutCardStart(const void * pdata, WORD wDataSize);
    //��Ϸ����
    bool OnSubGameConclude(const void * pdata, WORD wDataSize);
    //���û���
    bool OnSubSetBaseScore(const void * pdata, WORD wDataSize);
    //�µĵ���
    bool OnSubNewBank(const void * pdata, WORD wDataSize);
    //�û��й�
    bool OnSubTrustee(const void * pdata, WORD wDataSize);
#endif
	void onUserStart(Object *pSender);
	bool onUserStartView(const void * pBuffer, WORD wDataSize);
	bool onUserBEeiLv(const void * pBuffer, WORD wDataSize);
	bool onUserAdd(const void * pBuffer, WORD wDataSize);
	bool onSubSendCard(const void * pBuffer, WORD wDataSize);
	bool onSubOpenCard(const void * pBuffer, WORD wDataSize);
	bool onSubLandScore(const void * pBuffer, WORD wDataSize);
	bool onSubGameStart(const void * pBuffer, WORD wDataSize);
	bool onSubOutCard(const void * pBuffer, WORD wDataSize);
	bool onSubPassCard(const void * pBuffer, WORD wDataSize);
		//��Ϸ����;
	bool onSubGameEnd(const void * pBuffer, WORD wDataSize);
	bool onUserOnLine(const void * pBuffer, WORD wDataSize);
	bool onUserChat( const void * pBuffer, WORD wDataSize );
	bool onUserExpression(const void * pBuffer, WORD wDataSize);
	bool onRoomLimit(const void * pBuffer, WORD wDataSize);

	//add by zengxin 20161102 �е���
	bool onCallLord(const void * pBuffer, WORD wDataSize);

	//add by zengxin 20161102 ������
	bool onRobLord(const void * pBuffer, WORD wDataSize);

	//add by zengxin 20161008  �������ָ��Ծִ���   ���ƽ׶�
	bool OnGameScenePlay(const void *pBuffer, WORD wDataSize);

	//add by zengxin 20161008 �������ָ��Ծ�   �е����׶�
	bool OnGameSceneCallLord(const void *pBuffer, WORD wDataSize);

	//add by zengxin 20161104 �������ָ��Ծ�   �������׶�
	bool OnGameSceneRobLord(const void *pBuffer, WORD wDataSize);

	// <add by zengxin 20160923>  �û�Ϊ��һ���е����û�
	void showMyFirstJiaoDiZhuBtnViews(float dt);

public:
	//--����
	BYTE						m_handCardData[DDZGAME_PLAYER][MAX_COUNT];			//	�˿��б�
	WORD						m_handCardNum[DDZGAME_PLAYER];						//	������Ŀ
	WORD						m_nBankerUser;										//	����
private:
	//--����
	//--���������
	BYTE							m_outCardData[MAX_COUNT];
	WORD						m_outCardNum;											//������Ŀ
	WORD						m_beilv;
	BYTE						m_bLastCallScore;													
	WORD						m_wCurrentUser;															//��ǰ���
	WORD						m_wStartUser;											//	��ʼ���
	WORD						m_wTempUser;																//�ϼ�
	bool							m_wOpenUser[DDZGAME_PLAYER];									//�������
	DDZGame_State				m_eGameState;																//��Ϸ״̬
	WORD						m_baseScore;																//��Ϸ��������
	bool							m_isOut;																		//��Ϸ�Ѿ������ˣ����ڼӱ�

	bool						m_isCallLord;											//��ǰ���Ƿ����˽й�����, ��������չʾ�е���������������ť

	//����״̬�Ĳ�������
	//ʱ����Ϣ
	BYTE							m_cbTimeCallBanker;					//�е���ʱ��
	BYTE							m_cbTimeRodBanker;					//������ʱ��
	BYTE							m_cbTimeOutCard;						//����ʱ��
	BYTE							m_cbTimeStartGame;					//��ʼʱ��
	BYTE							m_cbTimeHeadOutCard;					//�׳�ʱ��

	LONG							m_lCellScore;							//��������
};		
#endif

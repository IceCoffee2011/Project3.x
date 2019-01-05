#ifndef __PPC_GAME_MESSAGE_H__
#define __PPC_GAME_MESSAGE_H__

#include "cocos2d.h"
#include "BaseGameLayer.h"
#include "GlobalDef.h"

//	��Ϸ��Ϣ����
class PPCGameMessage: public BaseGameLayer
{
public:
	PPCGameMessage();
	~PPCGameMessage();
	CREATE_FUNC(PPCGameMessage);

public://�̳е����෽��
	//	���������Ϸ
	void dealEnterGame(Ref* pSender);

	//	���������Ϣ
	void dealPlayerInfo(Ref* pSender);

	//	������Ϸ��Ϣ
	void dealMessageGame(Ref* pSender);

private:
	bool init();

	//	����״̬
	void dealGameState(tagUserData eData);
	
private://ͨѶ�ӿ�

	//	ʵ����Ϸ��Ϣ
	bool OnEventGameMessage(WORD wSubCmdID, void* pData, WORD wDataSize);

	//	ʵ����Ϸ����
	void onMessageScene(unsigned char cbStation,const void* pBuffer,unsigned short wDataSize);

	//	��;������������״̬
	void OnGameSceneFree(const void *pBuffer, WORD wDataSize);

	//	��;����������ע�׶�
	void  OnGameScenePlay(const void *pBuffer, WORD wDataSize);

	//	��;������������׶�
	void  OnGameScenePlayEnd(const void *pBuffer, WORD wDataSize);

	//��Ϸ����
	bool OnSubGameFree(void *pBuffer, WORD wDataSize);
	//��Ϸ��ʼ
	bool OnSubGameStart(void *pBuffer, WORD wDataSize);
	//�û���ע
	bool OnSubPlaceJetton(void *pBuffer, WORD wDataSize, bool bGameMes);
	//������ׯ
	bool OnSubUserApplyBanker(void *pBuffer, WORD wDataSize);

	//ȡ����ׯ
	bool OnSubUserCancelBanker(void *pBuffer, WORD wDataSize);
	//�л�ׯ��
	bool OnSubChangeBanker(void *pBuffer, WORD wDataSize);
	//��Ϸ����
	bool OnSubGameEnd(void *pBuffer, WORD wDataSize);
	//��Ϸ��¼
	bool OnSubGameRecord(void *pBuffer, WORD wDataSize);
	//	��ׯ�б�
	bool OnApplyBankerList(void *pBuffer, WORD wDataSize);

	//��עʧ��
	bool OnSubPlaceJettonFail(void *pBuffer, WORD wDataSize);
	//SUB_S_CHECK_IMAGE
	bool OnSubCheckImageIndex(void *pBuffer, WORD wDataSize);
	//����
	bool OnSubAdminControl(void *pBuffer, WORD wDataSize);
	//SUB_S_SCORE_RESULT
	bool OnSubScoreResult(void *pBuffer, WORD wDataSize);
	//SUB_S_ACCOUNT_RESULT
	bool OnSubAccountResult(void *pBuffer, WORD wDataSize);

};

#endif  // __PPC_GAME_MESSAGE_H__
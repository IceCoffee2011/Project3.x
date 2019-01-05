#ifndef __SGLY_MESSAGE_CENTER_H__
#define __SGLY_MESSAGE_CENTER_H__

#include "cocos2d.h"
#include "BaseGameLayer.h"
#include "GlobalDef.h"

USING_NS_CC;

/*
**	@brief	ˮ����԰������Ϣ��������
*/
class SGLYMessageCenter: public BaseGameLayer
{
public:
	SGLYMessageCenter();
	~SGLYMessageCenter();
	CREATE_FUNC(SGLYMessageCenter);

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
	void OnGameScenePlay(const void *pBuffer, WORD wDataSize);

	//	��;������������׶�
	void OnGameScenePlayEnd(const void *pBuffer, WORD wDataSize);

	//	��Ϸ����
	bool OnSubGameFree(const void *pBuffer, WORD wDataSize);

	//	��Ϸ��ʼ
	bool OnSubGameStart(const void *pBuffer, WORD wDataSize);

	//	�û���ע
	bool OnSubPlaceJetton(const void *pBuffer, WORD wDataSize);

	//	������ׯ
	bool OnSubUserApplyBanker(const void *pBuffer, WORD wDataSize);

	//	ȡ����ׯ
	bool OnSubUserCancelBanker(const void *pBuffer, WORD wDataSize);

	//	�л�ׯ��
	bool OnSubChangeBanker(const void *pBuffer, WORD wDataSize);

	//	��Ϸ����
	bool OnSubGameEnd(const void *pBuffer, WORD wDataSize);

	//	��Ϸ��¼
	bool OnSubGameRecord(const void *pBuffer, WORD wDataSize);

	//	��ׯ�б�
	bool OnApplyBankerList(const void *pBuffer, WORD wDataSize);

	//	��עʧ��
	bool onBetFailed(const void *pBuffer, WORD wDataSize);

	//	���³���
	bool OnSubUpdateChip(const void *pBuffer, WORD wDataSize);

	//	�´�С
	bool OnSubGuessBigSmall(const void *pBuffer, WORD wDataSize);

};

#endif  // __SGLY_MESSAGE_CENTER_H__
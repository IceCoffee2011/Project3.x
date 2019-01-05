#include "BRNNGameMessage.h"
#include "BRNNManageAudio.h"
#include "BRNNGameScene.h"
#include "BRNNGameLogic.h"
#include "BRNNProtocol.h"
#include "EntityMgr.h"
#include "MyNSString.h"
#include "BRNNTool.h"
#include "ToolKit.h"

BRNNGameMessage::BRNNGameMessage()
{
}

BRNNGameMessage::~BRNNGameMessage()
{
}

bool BRNNGameMessage::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!BaseGameLayer::init());

		bRet = true;
	} while (0);

	return bRet;
}

void BRNNGameMessage::dealGameState(tagUserData eData)
{
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return;
	}

	tagUserData* pPlayerData = EntityMgr::instance()->roomFrame()->getMeUserDate();
	if (pPlayerData->dwUserID != eData.dwUserID)
	{
		//	���������������״̬����
		return;
	}

	switch (eData.cbUserStatus)
	{
	case US_NULL:	//	�뿪
	case US_FREE:
		{
			pScene->m_pPopupApplyList->removeListItem(pPlayerData->wChairID);
		}
		break;
	case US_SIT:
	case US_PLAYING:
		{
			pScene->m_pInfoBar->m_pPlayerName->setString(eData.szNickName);
			pScene->m_pInfoBar->updatePlayerGold(eData.lScore);
			if (eData.cbGender == 1)	//	��
			{
				pScene->m_pInfoBar->m_pPlayerFace->initWithSpriteFrameName(BRNNTextureName::s_brnn_face_man);
			}
			else
			{
				pScene->m_pInfoBar->m_pPlayerFace->initWithSpriteFrameName(BRNNTextureName::s_brnn_face_woman);
			}
			if (pScene->m_pGameLayer->getApplyState() != E_BRNN_EPPC_Apply_State_Banker)
			{
				pScene->m_pGameLayer->checkoutEnabledBtnChip(pPlayerData->lScore);
			}

		}
		break;
	case US_READY:
		{
		}
		break;
	case US_LOOKON:
		break;
	case US_OFFLINE:
		{
		}
		break;
	case US_AGAIN_GAME:
		break;
	case US_LEFT:
		{
		}
		break;
	default:
		break;
	}
}

void BRNNGameMessage::dealEnterGame(Ref* pSender)
{

}

void BRNNGameMessage::dealPlayerInfo(Ref* pSender)
{
	tagUserBuffer* tag = (tagUserBuffer*)pSender;
	DWORD dwUserID = tag->dwUserID;

	CUserItem* pUserItem = (CUserItem*)EntityMgr::instance()->roomFrame()->getUserItem(dwUserID);
	if (!pUserItem)
	{
		return;
	}

	tagUserData* pUserData = pUserItem->getUserData();
	if (!pUserData)
	{
		return;
	}
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (pScene)
	{
	}
	dealGameState(*pUserData);
}

void BRNNGameMessage::dealMessageGame(Ref* pSender)
{
	tagGameBuffer* tag = (tagGameBuffer*)pSender;
	int Applicead = tag->nDataSize;
	OnEventGameMessage(tag->wSubCmdID,tag->dateBuffer,tag->nDataSize);
}

bool BRNNGameMessage::OnEventGameMessage(WORD wSubCmdID, void* pData, WORD wDataSize)
{
	switch (wSubCmdID)
	{
	case BRNN_SUB_S_GAME_FREE:
		return OnSubGameFree(pData, wDataSize);
	case BRNN_SUB_S_GAME_START:
		return OnSubGameStart(pData, wDataSize);
	case BRNN_SUB_S_PLACE_JETTON:
		return OnSubPlaceJetton(pData, wDataSize);
	case BRNN_SUB_S_GAME_END:
		return OnSubGameEnd(pData, wDataSize);
	case BRNN_SUB_S_APPLY_BANKER:
		return OnSubUserApplyBanker(pData, wDataSize);
	case BRNN_SUB_S_CHANGE_BANKER:
		return OnSubChangeBanker(pData, wDataSize);
	case BRNN_SUB_S_CHANGE_USER_SCORE:
		break;
	case BRNN_SUB_S_SEND_RECORD:
		return OnSubGameRecord(pData, wDataSize);
	case BRNN_SUB_S_PLACE_JETTON_FAIL:
		onBetFailed(pData, wDataSize);
		log("BRNN_SUB_S_PLACE_JETTON_FAIL");
		break;
	case BRNN_SUB_S_CANCEL_BANKER:
		return OnSubUserCancelBanker(pData, wDataSize);
	case BRNN_SUB_S_SEND_ACCOUNT:
		break;
	case BRNN_SUB_S_ADMIN_CHEAK:
		break;
	case BRNN_SUB_C_GET_PLAYLIST:
		return OnApplyBankerList(pData, wDataSize);
	default:
		break;
	}
	return true;
}

void BRNNGameMessage::onMessageScene(unsigned char cbStation,const void* pBuffer,unsigned short wDataSize)
{
	CCLOG("BRNNGameMessage::onMessageScene cbStation=%d,wDataSize=%d", cbStation, wDataSize);
	switch(cbStation)
	{
	case GAME_STATUS_FREE://0
		{
			CCLOG("GAME_STATUS_FREE 0");
			OnGameSceneFree(pBuffer, wDataSize);
		}
		break;
	case GS_PLACE_JETTON:
		{
			OnGameScenePlay(pBuffer, wDataSize);
		}
		break;
	case GS_GAME_END://100
		{
			CCLOG("GAME_STATUS_PLAY 100");
			OnGameScenePlayEnd(pBuffer, wDataSize);
		}
		break;
	default:
		break;
	}
}

//	��;������������״̬
void BRNNGameMessage::OnGameSceneFree(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_StatusFree) != wDataSize)
	{
		return;
	}
	BRNN_CMD_S_StatusFree* pMessageData = (BRNN_CMD_S_StatusFree*)pBuffer;
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return;
	}

	//	ʱ��

	pScene->m_pClock->playCountdownTimer(pMessageData->cbTimeLeave);
	pScene->m_pClock->setTimerType(E_BRNN_Idle);
	pScene->m_eGameStatue = E_BRNN_Idle;

	//	ׯ��:�ս���ֱ��ˢ��ׯ�ң���������

	//CUserItem* pUserItem = (CUserItem*)EntityMgr::instance()->roomFrame()->getUserItemByChairID(pMessageData->wBankerUser);
	//if (!pUserItem)
	//{
	//	return;
	//}
//	OutputDebugString(pMessageData->szBankerNickName);
	pScene->m_pInfoBar->updateBankerInfo(
		pMessageData->wBankerUser,
		pMessageData->szBankerNickName,
		pMessageData->cbBankerGender,
		pMessageData->lBankerScore,
		pMessageData->lBankerWinScore,
		pMessageData->cbBankerTime,
		pMessageData->bEnableSysBanker);
}

//	��;����������ע�׶�
void BRNNGameMessage::OnGameScenePlay(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_StatusPlay) != wDataSize)
	{
		return;
	}
	BRNN_CMD_S_StatusPlay* pMessageData = (BRNN_CMD_S_StatusPlay*)pBuffer;
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return;
	}

	//	ʱ��
	pScene->m_pClock->playCountdownTimer(pMessageData->cbTimeLeave);
	pScene->m_pClock->setTimerType(E_BRNN_Bet);
	pScene->m_eGameStatue = E_BRNN_Bet;
	BRNNManageAudio::getInstance()->playBGMusic();

	//�Ѿ���ע��ֵ �� ���� ��1��ʼ
	for (int i = E_BRNN_PokerPos_E; i < E_BRNN_PokerPos_NULL; i++)
	{
		//��ǰ�����Ѿ���ע����չʾ
		pScene->m_pGameLayer->allocationChip(BRNNTool::convertToClientArea(i), pMessageData->lAllJettonScore[i]);
	}

	//	ׯ��:�ս���ֱ��ˢ��ׯ�ң���������

	//CUserItem* pUserItem = (CUserItem*)EntityMgr::instance()->roomFrame()->getUserItemByChairID(pMessageData->wBankerUser);
	//if (!pUserItem)
	//{
	//	return;
	//}
	pScene->m_pInfoBar->updateBankerInfo(
		pMessageData->wBankerUser,
		pMessageData->szBankerNickName,
		pMessageData->cbBankerGender,
		pMessageData->lBankerScore,
		pMessageData->lBankerWinScore,
		pMessageData->cbBankerTime,
		pMessageData->bEnableSysBanker);

}

//	��;������������׶�
void BRNNGameMessage::OnGameScenePlayEnd(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_StatusPlay) != wDataSize)
	{
		return;
	}
	BRNN_CMD_S_StatusPlay* pMessageData = (BRNN_CMD_S_StatusPlay*)pBuffer;
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return;
	}

	//	ʱ��
	pScene->m_pClock->playCountdownTimer(pMessageData->cbTimeLeave);
	pScene->m_pClock->setTimerType(E_BRNN_OpenCard);
	pScene->m_eGameStatue = E_BRNN_OpenCard;

	//	����

	for (int i = E_BRNN_PokerPos_E; i < E_BRNN_PokerPos_NULL; i++)
	{
		//��ǰ�����Ѿ���ע����չʾ
		pScene->m_pGameLayer->allocationChip(BRNNTool::convertToClientArea(i), pMessageData->lAllJettonScore[i]);
	}

	//	����

	for (int i = E_BRNN_PokerPos_B; i < E_BRNN_PokerPos_NULL; i++)
	{
		BRNNHandsCard* pHandCard = pScene->m_pGameLayer->m_pHandCard[i];
		BYTE bShowCardData[BRNN_HANDS_CARD_COUNT];
		memset(bShowCardData, 0, sizeof(bShowCardData));
		BYTE bTmpShowCardData[BRNN_HANDS_CARD_COUNT];
		memset(bTmpShowCardData, 0, sizeof(bTmpShowCardData));
		E_BRNN_CardType eCardType = BRNNGameLogic::GetCardType(pMessageData->cbTableCardArray[i], BRNN_HANDS_CARD_COUNT, bTmpShowCardData);
		if (eCardType == E_BRNN_CardType_Error)
		{
			continue;
		}

		pHandCard->setCardType(eCardType);

		//	��Ŀ����
		if (eCardType >= E_BRNN_CardType_Niu1)
		{
			bShowCardData[0] = bTmpShowCardData[3];
			bShowCardData[1] = bTmpShowCardData[4];
			bShowCardData[2] = bTmpShowCardData[0];
			bShowCardData[3] = bTmpShowCardData[1];
			bShowCardData[4] = bTmpShowCardData[2];				
		}
		else
		{
			memcpy(bShowCardData, bTmpShowCardData, sizeof(bTmpShowCardData));
		}
		//	��ʼ�����Ʋ���ʾ

		pHandCard->initHandsCard(bShowCardData);
		for (int j = 0; j < BRNN_HANDS_CARD_COUNT; j++)
		{
			pHandCard->m_pPokerCard[j]->setVisible(true);
			pHandCard->m_pPokerCard[j]->showCardObverse(false);
		}

		//	��Ŀ�Ű�
		if (eCardType >= E_BRNN_CardType_Niu1)
		{
			pHandCard->showCardMarkedness();
		}
		pHandCard->showCardType(eCardType);

		//	Ӯ���������
		if (i > E_BRNN_PokerPos_B)
		{
			bool bIsWin = pMessageData->bResult[i - 1];
			pScene->m_pGameLayer->m_pBetArea[i - 1]->setAreaHighLight(bIsWin);
		}
	}

	//	��ʾ��ˢ�½��������ֵ

	pScene->m_pSettlement->updatePlayerScore(pMessageData->lEndUserScore);
	pScene->m_pSettlement->updatePlayerCapital(pMessageData->lEndUserReturnScore);
	pScene->m_pSettlement->updateBankerScore(pMessageData->lEndBankerScore);
	pScene->m_pSettlement->setVisible(true);

	//	ׯ��:�ս���ֱ��ˢ��ׯ�ң���������

	//CUserItem* pUserItem = (CUserItem*)EntityMgr::instance()->roomFrame()->getUserItemByChairID(pMessageData->wBankerUser);
	//if (!pUserItem)
	//{
	//	return;
	//}
	pScene->m_pInfoBar->updateBankerInfo(
		pMessageData->wBankerUser,
		pMessageData->szBankerNickName,
		pMessageData->cbBankerGender,
		pMessageData->lBankerScore,
		pMessageData->lBankerWinScore,
		pMessageData->cbBankerTime,
		pMessageData->bEnableSysBanker);

}

//	��Ϸ����
bool BRNNGameMessage::OnSubGameFree(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_GameFree) != wDataSize)
	{
		return false;
	}

	BRNN_CMD_S_GameFree* pMessageData = (BRNN_CMD_S_GameFree*)pBuffer;
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}

	//	ʱ��
	pScene->m_pClock->playCountdownTimer(pMessageData->cbTimeLeave);
	pScene->m_pClock->setTimerType(E_BRNN_Idle);
	pScene->m_eGameStatue = E_BRNN_Idle;

	//	����
	pScene->resetGameScene();

	return true;
}

//	��Ϸ��ʼ
bool BRNNGameMessage::OnSubGameStart(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_GameStart) != wDataSize)
	{
		return false;
	}

	BRNN_CMD_S_GameStart* pMessageData = (BRNN_CMD_S_GameStart*)pBuffer;
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}

	//	ʱ��
	pScene->m_pClock->playCountdownTimer(pMessageData->cbTimeLeave);
	pScene->m_pClock->setTimerType(E_BRNN_Bet);
	pScene->m_eGameStatue = E_BRNN_Bet;
	BRNNManageAudio::getInstance()->playBGMusic();

	if (pMessageData->wBankerUser == INVALID_CHAIR)
	{
		return true;
	}

	//	ˢ������
	auto pSelfItem = EntityMgr::instance()->roomFrame()->getMeUserItem();
	if (!pSelfItem)
	{
		return false;
	}
	pScene->m_pInfoBar->updatePlayerGold(pSelfItem->getUserGold());
	pScene->m_pInfoBar->updateBankerGold(pMessageData->lBankerScore);

	return true;
}

//	�û���ע
bool BRNNGameMessage::OnSubPlaceJetton(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_PlaceJetton) != wDataSize)
	{
		return false;
	}
	BRNN_CMD_S_PlaceJetton* pMessageData = (BRNN_CMD_S_PlaceJetton*)pBuffer;
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}

	tagUserData* pPlayerData = EntityMgr::instance()->roomFrame()->getMeUserDate();
	E_BRNNBetAreaType eAreaType = BRNNTool::convertToClientArea((int)pMessageData->cbJettonArea);
	pScene->m_pGameLayer->bet(eAreaType, pMessageData->lJettonScore);
	BRNNManageAudio::getInstance()->playSoundEffect(E_BRNNAudio_Bet);

	if (pMessageData->wChairID == pPlayerData->wChairID)
	{
		//	������Ҹ�ע
		BRNNBetArea* pArea = pScene->m_pGameLayer->getTableArea(eAreaType);
		LONGLONG llSelf = pArea->getChipValueSelf() + (LONGLONG)pMessageData->lJettonScore;
		pArea->setChipValueSelf(llSelf);
		pArea->setLabChipValueSelf(llSelf);

		//	�������Ͷע
		LONGLONG llPlayerBetSum = pScene->m_pInfoBar->getPlayerBetSum() + pMessageData->lJettonScore;
		pScene->m_pInfoBar->updatePlayerBetSum(llPlayerBetSum);

		//	ˢ��
		int nMaxMultiple = 5;
		SCORE sUsableGold = pPlayerData->lScore - pScene->m_pInfoBar->getPlayerBetSum() * nMaxMultiple;
		pScene->m_pGameLayer->checkoutEnabledBtnChip(sUsableGold);

		//	������ҿ��ý����
		SCORE sPlayerGold = pScene->m_pInfoBar->getPlayerGold() - pMessageData->lJettonScore;
		pScene->m_pInfoBar->updatePlayerGold(sPlayerGold);
	}

	return true;
}

//	������ׯ
bool BRNNGameMessage::OnSubUserApplyBanker(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_ApplyBanker) != wDataSize)
	{
		return false;
	}
	BRNN_CMD_S_ApplyBanker* pMessageData = (BRNN_CMD_S_ApplyBanker*)pBuffer;
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}
	int nSelfChairID = EntityMgr::instance()->roomFrame()->getMeUserDate()->wChairID;
	if (pMessageData->wApplyUser == nSelfChairID)
	{
		//	����������ׯ�ɹ����ı���ʾ�İ�ť
		pScene->m_pGameLayer->setApplyState(E_BRNN_EPPC_Apply_State_Apply);
	}

	if (pScene->m_pPopupApplyList->isVisible())
	{
		EntityMgr::instance()->getDispatch()->sendSocketDate(BRNN_SUB_C_GET_PLAYLIST);
	}

	return true;
}

//	ȡ����ׯ
bool BRNNGameMessage::OnSubUserCancelBanker(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_CancelBanker) != wDataSize)
	{
		return false;
	}
	BRNN_CMD_S_CancelBanker* pMessageData = (BRNN_CMD_S_CancelBanker*)pBuffer;
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}
	int nSelfChairID = EntityMgr::instance()->roomFrame()->getMeUserDate()->wChairID;
	if (pMessageData->wChairID == nSelfChairID)
	{
		//	����������ׯ�ɹ����ı���ʾ�İ�ť
		pScene->m_pGameLayer->setApplyState(E_BRNN_Apply_State_Null);
	}
	if (pScene->m_pPopupApplyList->isVisible())
	{
		EntityMgr::instance()->getDispatch()->sendSocketDate(BRNN_SUB_C_GET_PLAYLIST);
	}
	return true;
}

//	�л�ׯ��
bool BRNNGameMessage::OnSubChangeBanker(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_ChangeBanker) != wDataSize)
	{
		return false;
	}
	BRNN_CMD_S_ChangeBanker* pMessageData = (BRNN_CMD_S_ChangeBanker*)pBuffer;
	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}
	BRNNManageAudio::getInstance()->playSoundEffect(E_BRNNAudio_Change_Banker);

	tagUserData* pUserData = EntityMgr::instance()->roomFrame()->getMeUserDate();
	int nSelfChairID = pUserData->wChairID;

	//	�л�ׯ�Ҷ���
	pScene->m_pGameLayer->showAniChangeBanker(pMessageData->wBankerUser);

	//	���������
	if (pMessageData->wBankerUser == nSelfChairID)
	{
		//	���ó��밴ť
		pScene->m_pGameLayer->setAllBtnChipEnable(false);
		//	��ʾ����Ҫ��ׯ��
		pScene->m_pGameLayer->setApplyState(E_BRNN_EPPC_Apply_State_Banker);
	}
	else
	{
		E_BRNNApplyState eApplyState = pScene->m_pGameLayer->getApplyState();
		if (eApplyState == E_BRNN_EPPC_Apply_State_Banker)
		{
			pScene->m_pGameLayer->setApplyState(E_BRNN_Apply_State_Null);
			pScene->m_pGameLayer->checkoutEnabledBtnChip(pUserData->lScore);
		}
	}

	if (pScene->m_pPopupApplyList->isVisible())
	{
		EntityMgr::instance()->getDispatch()->sendSocketDate(BRNN_SUB_C_GET_PLAYLIST);
	}

	//	ˢ��ׯ����Ϣ
	if (pMessageData->wBankerUser == INVALID_CHAIR)
	{
		pScene->m_pInfoBar->updateBankerInfo(INVALID_CHAIR,(TCHART*)"***",1,0,0, 0);
	}
	else
	{
		CUserItem* pUserItem = (CUserItem*)EntityMgr::instance()->roomFrame()->getUserItemByChairID(pMessageData->wBankerUser);
		if (!pUserItem)
		{
			return true;
		}
		pScene->m_pInfoBar->updateBankerInfo(
			pMessageData->wBankerUser,
		pMessageData->szBankerNickName,
		pMessageData->cbBankerGender,
			pMessageData->lBankerScore,
			0, 0);
	}

	return true;
}

//	��Ϸ����
bool BRNNGameMessage::OnSubGameEnd(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_GameEnd) != wDataSize)
	{
		return false;
	}

	BRNN_CMD_S_GameEnd* pMessageData = (BRNN_CMD_S_GameEnd*)pBuffer;
// 	log(" B : %d, %d, %d, %d, %d \n E : %d, %d, %d, %d, %d \n S : %d, %d, %d, %d, %d \n W : %d, %d, %d, %d, %d \n N : %d, %d, %d, %d, %d",
// 		pMessageData->cbTableCardArray[0][0], pMessageData->cbTableCardArray[0][1], pMessageData->cbTableCardArray[0][2], pMessageData->cbTableCardArray[0][3], pMessageData->cbTableCardArray[0][4],
// 		pMessageData->cbTableCardArray[1][0], pMessageData->cbTableCardArray[1][1], pMessageData->cbTableCardArray[1][2], pMessageData->cbTableCardArray[1][3], pMessageData->cbTableCardArray[1][4],
// 		pMessageData->cbTableCardArray[2][0], pMessageData->cbTableCardArray[2][1], pMessageData->cbTableCardArray[2][2], pMessageData->cbTableCardArray[2][3], pMessageData->cbTableCardArray[2][4],
// 		pMessageData->cbTableCardArray[3][0], pMessageData->cbTableCardArray[3][1], pMessageData->cbTableCardArray[3][2], pMessageData->cbTableCardArray[3][3], pMessageData->cbTableCardArray[3][4],
// 		pMessageData->cbTableCardArray[4][0], pMessageData->cbTableCardArray[4][1], pMessageData->cbTableCardArray[4][2], pMessageData->cbTableCardArray[4][3], pMessageData->cbTableCardArray[4][4]
// 	);

	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}
	auto pSelfItem = EntityMgr::instance()->roomFrame()->getMeUserItem();
	if (!pSelfItem)
	{
		return false;
	}

	SCORE sPlayerScore = pMessageData->lUserScore;
	SCORE sBankerScore = pMessageData->lBankerScore;
	SCORE sBankerTotallScore = pMessageData->lBankerTotallScore;
	int nBankerTime = pMessageData->nBankerTime;
	SCORE sPlayerBetSum = pScene->m_pInfoBar->getPlayerBetSum();
	bool bIsWin = sPlayerScore > sPlayerBetSum ? true : false;
	BRNNManageAudio::getInstance()->stopBGMusic();

	//	ˢ��ʱ��
	pScene->m_pClock->playCountdownTimer(pMessageData->cbTimeLeave);
	pScene->m_pClock->setTimerType(E_BRNN_OpenCard);
	pScene->m_eGameStatue = E_BRNN_OpenCard;

 	//	ˢ�½��������ֵ
	pScene->m_pSettlement->updatePlayerScore(pMessageData->lUserScore);
	pScene->m_pSettlement->updatePlayerCapital(pMessageData->lUserReturnScore);
	pScene->m_pSettlement->updateBankerScore(pMessageData->lBankerScore);

	//	���ƶ���
	int nIdx = (BRNNGameLogic::GetCardValue(pMessageData->bcFirstCard[0]) + BRNNGameLogic::GetCardValue(pMessageData->bcFirstCard[1]) - 1) % 5;
	float fAniTime = pScene->m_pGameLayer->doAniSendCard(nIdx, pMessageData->cbTableCardArray);

	bool bResultE = pMessageData->bResult[0];
	bool bResultS = pMessageData->bResult[1];
	bool bResultW = pMessageData->bResult[2];
	bool bResultN = pMessageData->bResult[3];

	//	���㴦��
	auto pDelay = DelayTime::create(fAniTime + 2.0f);
	auto pEnding = CallFunc::create([=]()
	{
		pScene->m_pSettlement->setVisible(true);
		SCORE sPlayerTotal = pScene->m_pInfoBar->getPlayerTotal() + sPlayerScore;
		pScene->m_pInfoBar->updatePlayerTotal(sPlayerTotal);
		pScene->m_pInfoBar->updateBankerTotal(sBankerTotallScore);
		pScene->m_pInfoBar->updateBankerTime(nBankerTime);
		if (bIsWin)
		{
			BRNNManageAudio::getInstance()->playSoundEffect(E_BRNNAudio_Win);
		}
		else
		{
			BRNNManageAudio::getInstance()->playSoundEffect(E_BRNNAudio_Lose);
		}

		pScene->m_pGameLayer->m_pBetArea[E_BRNNBetArea_E]->setAreaHighLight(bResultE);
		pScene->m_pGameLayer->m_pBetArea[E_BRNNBetArea_S]->setAreaHighLight(bResultS);
		pScene->m_pGameLayer->m_pBetArea[E_BRNNBetArea_W]->setAreaHighLight(bResultW);
		pScene->m_pGameLayer->m_pBetArea[E_BRNNBetArea_N]->setAreaHighLight(bResultN);
	});
	auto pSeq = Sequence::create(pDelay, pEnding, nullptr);
	pScene->runAction(pSeq);

	return true;
}

//	��Ϸ��¼
bool BRNNGameMessage::OnSubGameRecord(const void *pBuffer, WORD wDataSize)
{
	//Ч�����
	if (wDataSize%sizeof(BRNN_tagServerGameRecord)!=0)
	{
		return false;
	}

	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}

	WORD wRecordCount = wDataSize / sizeof(BRNN_tagServerGameRecord);

	int nItemCount = pScene->m_pPopupTravel->getItemCount();
	if (nItemCount < 0)
	{
		return false;
	}
	//	ʵ�������ȶ������1���������䴦��
	if (nItemCount >= (BRNN_MAX_SCORE_HISTORY - 1) && wRecordCount == (BRNN_MAX_SCORE_HISTORY - 1))
	{
		nItemCount = BRNN_MAX_SCORE_HISTORY - 2;
	}
	for (int i = nItemCount; i < wRecordCount; i++) 
	{
		BRNN_tagServerGameRecord* pRecord = (((BRNN_tagServerGameRecord *)pBuffer) + i);
		pScene->m_pPopupTravel->addListItem(*pRecord);
	}

	return true;
}

//	��ׯ�б�
bool BRNNGameMessage::OnApplyBankerList(const void *pBuffer, WORD wDataSize)
{
	//Ч������
	BRNN_CMD_S_ApplyBankerList* pApplyList = (BRNN_CMD_S_ApplyBankerList*)pBuffer;
	if (wDataSize!=pApplyList->getLength()) return false;

	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}

	pScene->m_pPopupApplyList->removeAllListItem();
	pScene->m_pPopupApplyList->setPopupVisible(true);

	for (int i = 0; i < pApplyList->cbCount; i++)
	{
		pScene->m_pPopupApplyList->addListItem((*pApplyList)[i]);
/*
		char cNikeName[300];
		MyNSString::wc2mbs((*pApplyList)[i].szNickName, 32, cNikeName);
		WORD wChairID = (*pApplyList)[i].wChairID;
		DWORD dwUserID = (*pApplyList)[i].dwUserID;
		DOUBLE lScore=(*pApplyList)[i].lScore;
*/
	}
	return true;
}

bool BRNNGameMessage::onBetFailed(const void *pBuffer, WORD wDataSize)
{
	if (sizeof(BRNN_CMD_S_PlaceJettonFail) != wDataSize)
	{
		return false;
	}
	BRNN_CMD_S_PlaceJettonFail* pMessageData = (BRNN_CMD_S_PlaceJettonFail*)pBuffer;

	BRNNGameScene* pScene = BRNNGameScene::getBRNNGameScene();
	if (!pScene)
	{
		return false;
	}

	Dictionary * pDictionary = Dictionary::createWithContentsOfFile(BRNN_XML_FILE_NAME);
	string sTips = ((CCString*)pDictionary->objectForKey(BRNN_XML_KEY_BET_FAILED))->getCString();
	ToolKit::showTips(sTips);

	return true;
}


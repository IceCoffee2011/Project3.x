#include "SGLYGameLayer.h"
#include "SGLYGameScene.h"
#include "SGLYRes.h"
#include "SGLYPopupSupplyChip.h"
#include "SGLYProtocol.h"
#include "ToolKit.h"
#include "RoomLayer.h"
#include "EntityMgr.h"
#include "SGLYTool.h"
#include "SGLYPopupQuit.h"
#include "SGLYPopupSetting.h"
#include "SGLYManageAudio.h"
#include "SGLYAniLottery.h"


SGLYGameLayer::SGLYGameLayer():
	m_eApplyState(E_SGLY_ApplyState_Null),
	m_nCurrBetMultiple(0),
	m_wBankerChairID(INVALID_CHAIR)
{
}

SGLYGameLayer::~SGLYGameLayer()
{
}

void SGLYGameLayer::reset()
{
	closedLotteryHighLight();
	for (auto k : m_vSpecialMask)
	{
		Sprite* pMask = dynamic_cast<Sprite*>(k);
		pMask->removeFromParent();
	}
	m_vSpecialMask.clear();
	//�ͷ��ڴ�
	vector<Node*>().swap(m_vSpecialMask);

	m_pLotteryTips->stopAllActions();
	m_pLotteryTips->setVisible(false);

	m_pGoodLuckTips->stopAllActions();
	m_pGoodLuckTips->setVisible(false);

	m_pGuessResultTips->setVisible(false);

	m_pBtnSupplyChip->setEnabled(true);
	m_pBtnBetContinue->setEnabled(true);

	stopAllActions();
}

//	������ׯ״̬
void SGLYGameLayer::setApplyState(E_SGLY_ApplyState eState)
{
	m_eApplyState = eState;
	switch (eState)
	{
	case E_SGLY_ApplyState_Apply:
		m_pBtnApply->setVisible(false);
		m_pBtnCancel->setVisible(true);
		m_pBtnDown->setVisible(false);
		break;
	case E_SGLY_ApplyState_Banker:
		m_pBtnApply->setVisible(false);
		m_pBtnCancel->setVisible(false);
		m_pBtnDown->setVisible(true);
		break;
	case E_SGLY_ApplyState_Null:
		m_pBtnApply->setVisible(true);
		m_pBtnCancel->setVisible(false);
		m_pBtnDown->setVisible(false);
		break;
	default:
		break;
	}
}

E_SGLY_ApplyState SGLYGameLayer::getApplyState() const
{
	return m_eApplyState;
}

void SGLYGameLayer::setLotteryHighLight(int nLotteryID, bool bIsHighLight)
{
	m_pLotteryHighLight[nLotteryID]->setVisible(bIsHighLight);
}

void SGLYGameLayer::setOnlyLotteryHighLight(int nLotteryID, bool bIsHighLight)
{
	closedLotteryHighLight();
	setLotteryHighLight(nLotteryID, bIsHighLight);
}

void SGLYGameLayer::closedLotteryHighLight()
{
	for (int i = 0; i < SGLY_LOTTERY_COUNT; i++)
	{
		setLotteryHighLight(i, false);
	}
}

void SGLYGameLayer::showAniChangeBanker(int nChairID)
{
	SGLYGameScene* pScene = SGLYGameScene::getGameScene();
	if (!pScene)
	{
		return;
	}
	cocos2d::Size sVSize = Director::getInstance()->getVisibleSize();

	float fMoveTime = 1.0f;
	float fShowTime = 2.0f;

	int nSelfChairID = EntityMgr::instance()->roomFrame()->getMeUserDate()->wChairID;
	Sprite* pImgTips = nullptr;
	if (nChairID == INVALID_CHAIR)
	{
		pImgTips = Sprite::createWithSpriteFrameName(SGLYTextureName::sSGLY_TipsNoneBanker);
	}
	else if (nChairID == nSelfChairID)
	{
		pImgTips = Sprite::createWithSpriteFrameName(SGLYTextureName::sSGLY_TipsOfficeholdingBanker);
	}
	else
	{
		pImgTips = Sprite::createWithSpriteFrameName(SGLYTextureName::sSGLY_TipsTurnBanker);
	}
	pScene->addChild(pImgTips);
	pImgTips->setPosition(Vec2(sVSize.width / 2, sVSize.height + pImgTips->getContentSize().height / 2));
	auto pMoveTo = MoveTo::create(fMoveTime, Vec2(sVSize / 2));
	auto pFadeIn = FadeIn::create(fShowTime);
	auto pRemoveSelf = RemoveSelf::create();
	auto pSeq = Sequence::create(pMoveTo, pFadeIn, pRemoveSelf, nullptr);
	pImgTips->runAction(pSeq);
}

//	չ�ֽ������ͱ���
void SGLYGameLayer::showLotteryType(int nLotteryID)
{
	if (nLotteryID < 0 || nLotteryID >= SGLY_LOTTERY_COUNT)
	{
		return;
	}

	if (nLotteryID == 9 || nLotteryID == 21)
	{
		return;
	}

	cocos2d::Size sVSize = Director::getInstance()->getVisibleSize();
	string sTextureName[SGLY_LOTTERY_COUNT] =
	{
		SGLYTextureName::sSGLY_LotteryTipsOrange,
		SGLYTextureName::sSGLY_LotteryTipsBell,
		SGLYTextureName::sSGLY_LotteryTipsBar25,
		SGLYTextureName::sSGLY_LotteryTipsBar,
		SGLYTextureName::sSGLY_LotteryTipsApple,
		SGLYTextureName::sSGLY_LotteryTipsApple2,
		SGLYTextureName::sSGLY_LotteryTipsPear,

		SGLYTextureName::sSGLY_LotteryTipsWatermelon,
		SGLYTextureName::sSGLY_LotteryTipsWatermelon2,
		"",
		SGLYTextureName::sSGLY_LotteryTipsApple,
		SGLYTextureName::sSGLY_LotteryTipsOrange2,

		SGLYTextureName::sSGLY_LotteryTipsOrange,
		SGLYTextureName::sSGLY_LotteryTipsBell,
		SGLYTextureName::sSGLY_LotteryTipsSeven2,
		SGLYTextureName::sSGLY_LotteryTipsSeven,
		SGLYTextureName::sSGLY_LotteryTipsApple,
		SGLYTextureName::sSGLY_LotteryTipsPear2,
		SGLYTextureName::sSGLY_LotteryTipsPear,

		SGLYTextureName::sSGLY_LotteryTipsStar,
		SGLYTextureName::sSGLY_LotteryTipsStar2,
		"",
		SGLYTextureName::sSGLY_LotteryTipsApple,
		SGLYTextureName::sSGLY_LotteryTipsBell2
	};

	m_pLotteryTips->initWithSpriteFrameName(sTextureName[nLotteryID]);
	m_pLotteryTips->setVisible(true);
	auto pScaleSmall = ScaleTo::create(0.5f, 0.5f);
	auto pScaleBig = ScaleTo::create(0.5f, 1);
	auto pSeqScale = Sequence::create(pScaleSmall, pScaleBig, nullptr);
	auto pRepeat = Repeat::create(pSeqScale, 5);
	auto pHide = Hide::create();
	auto pSeq = Sequence::create(pRepeat, pHide, nullptr);
	m_pLotteryTips->runAction(pSeq);
}

//	չ��GoodLuck���ͱ���
void SGLYGameLayer::showGoodLuckType(E_SGLY_GoodLuckType eType)
{
	cocos2d::Size sVSize = Director::getInstance()->getVisibleSize();
	string sTextureName[E_SGLY_GoodLuck_Null] =
	{
		SGLYTextureName::sSGLY_LuckTypeLoses,
		SGLYTextureName::sSGLY_LuckTypeDaSanYuan,
		SGLYTextureName::sSGLY_LuckTypeDaSiXi,
		SGLYTextureName::sSGLY_LuckTypeXiaoSanYuan,
		SGLYTextureName::sSGLY_LuckTypePaoHuoChe,
		""
	};
	m_pGoodLuckTips->initWithSpriteFrameName(sTextureName[eType]);
	m_pGoodLuckTips->setVisible(true);
	if (eType != E_SGLY_GoodLuck_Swallow)
	{
		auto pScaleSmall = ScaleTo::create(0.5f, 0.5f);
		auto pScaleBig = ScaleTo::create(0.5f, 1);
		auto pSeqScale = Sequence::create(pScaleSmall, pScaleBig, nullptr);
		auto pRepeat = Repeat::create(pSeqScale, 5);
		auto pHide = Hide::create();
		auto pSeq = Sequence::create(pRepeat, pHide, nullptr);
		m_pGoodLuckTips->runAction(pSeq);
	}
}

//	չ�ֲ´�С���
void SGLYGameLayer::showGuessReslt(bool bIsWin)
{
	cocos2d::Size sVSize = Director::getInstance()->getVisibleSize();
	if (bIsWin)
	{
		m_pGuessResultTips->initWithSpriteFrameName(SGLYTextureName::sSGLY_GuessSucceed);
		SGLYManageAudio::getInstance()->playSoundEffect(E_SGLY_Audio_Guess_Win);
	}
	else
	{
		m_pGuessResultTips->initWithSpriteFrameName(SGLYTextureName::sSGLY_GuessLose);
		SGLYManageAudio::getInstance()->playSoundEffect(E_SGLY_Audio_Guess_Lose);
	}
	m_pGuessResultTips->setVisible(true);
}

//	��ȡ�������
Sprite* SGLYGameLayer::getLottery(int nLotteryID) const
{
	if (nLotteryID < 0 && nLotteryID >= SGLY_LOTTERY_COUNT)
	{
		return nullptr;
	}
	return m_pIconLottery[nLotteryID];
}

//	������Ϸ�����׶��߼�
void SGLYGameLayer::dealGameEnd()
{
	SGLYGameScene* pScene = SGLYGameScene::getGameScene();
	if (!pScene)
	{
		return;
	}
	pScene->m_pPopupSupplyChip->setPopupVisible(false);
	m_pBtnSupplyChip->setEnabled(false);
}

bool SGLYGameLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!Layer::init());

		initUI();
		setApplyState(E_SGLY_ApplyState_Null);
		changeMultipleMode(E_SGLY_BettingMode_M1);

		bRet = true;
	} while (0);

	return bRet;
}

void SGLYGameLayer::initUI()
{
	cocos2d::Size sVSize = Director::getInstance()->getVisibleSize();

	//	����
	m_pBG = Sprite::create(SGLYTextureName::sSGLY_GameBG);
	addChild(m_pBG);
	m_pBG->setPosition(Vec2(sVSize / 2));
	cocos2d::Size sBGSize = m_pBG->getContentSize();

	vector<Node*> vList;

	//	��ʼ�����

	Vec2 vPosLottery[SGLY_LOTTERY_COUNT] =
	{
		Vec2(sBGSize.width * 0.149321, sBGSize.height * 0.736547),
		Vec2(sBGSize.width * 0.265793, sBGSize.height * 0.736547),
		Vec2(sBGSize.width * 0.382267, sBGSize.height * 0.736547),
		Vec2(sBGSize.width * 0.498745, sBGSize.height * 0.736547),
		Vec2(sBGSize.width * 0.615220, sBGSize.height * 0.736547),
		Vec2(sBGSize.width * 0.731688, sBGSize.height * 0.736547),
		Vec2(sBGSize.width * 0.850244, sBGSize.height * 0.736547),

		Vec2(sBGSize.width * 0.850244, sBGSize.height * 0.671376),
		Vec2(sBGSize.width * 0.850244, sBGSize.height * 0.604819),
		Vec2(sBGSize.width * 0.850244, sBGSize.height * 0.539646),
		Vec2(sBGSize.width * 0.850244, sBGSize.height * 0.474477),
		Vec2(sBGSize.width * 0.850244, sBGSize.height * 0.407921),

		Vec2(sBGSize.width * 0.850244, sBGSize.height * 0.342749),
		Vec2(sBGSize.width * 0.731694, sBGSize.height * 0.342749),
		Vec2(sBGSize.width * 0.617298, sBGSize.height * 0.342749),
		Vec2(sBGSize.width * 0.500821, sBGSize.height * 0.342749),
		Vec2(sBGSize.width * 0.382264, sBGSize.height * 0.342749),
		Vec2(sBGSize.width * 0.265793, sBGSize.height * 0.342749),
		Vec2(sBGSize.width * 0.149321, sBGSize.height * 0.342749),

		Vec2(sBGSize.width * 0.149321, sBGSize.height * 0.407921),
		Vec2(sBGSize.width * 0.149321, sBGSize.height * 0.474477),
		Vec2(sBGSize.width * 0.149321, sBGSize.height * 0.539646),
		Vec2(sBGSize.width * 0.149321, sBGSize.height * 0.604819),
		Vec2(sBGSize.width * 0.149321, sBGSize.height * 0.671376)
	};

	for (int i = 0; i < SGLY_LOTTERY_COUNT; i++)
	{
		char cTextureName[128];
		sprintf(cTextureName, SGLY_LOTTERY_FORMAT, i);
		m_pIconLottery[i] = Sprite::createWithSpriteFrameName(cTextureName);
		m_pBG->addChild(m_pIconLottery[i]);
		m_pIconLottery[i]->setPosition(vPosLottery[i]);
		m_pLotteryHighLight[i] = Sprite::createWithSpriteFrameName(SGLYTextureName::sSGLY_HighLightLottery);
		m_pIconLottery[i]->addChild(m_pLotteryHighLight[i]);
		m_pLotteryHighLight[i]->setPosition(Vec2(m_pIconLottery[i]->getContentSize() / 2));
		m_pLotteryHighLight[i]->setVisible(false);
	}

	//	�˳���ť
	m_pBtnQuit = Button::create(
		SGLYTextureName::sSGLY_BtnQuitNormal,
		SGLYTextureName::sSGLY_BtnQuitPressed,
		"",
		Widget::TextureResType::PLIST);
	m_pBG->addChild(m_pBtnQuit);
	m_pBtnQuit->setPosition(Vec2(sBGSize.width * 0.93, sBGSize.height * 0.97));
	m_pBtnQuit->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnQuitEvent, this));

	//	���ð�ť
	m_pBtnSetting = Button::create(
		SGLYTextureName::sSGLY_BtnSettingNormal,
		SGLYTextureName::sSGLY_BtnSettingPressed,
		"",
		Widget::TextureResType::PLIST);
	m_pBG->addChild(m_pBtnSetting);
	m_pBtnSetting->setPosition(Vec2(sBGSize.width * 0.83, sBGSize.height * 0.97));
	m_pBtnSetting->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnSettingEvent, this));

	//	��ׯ�б�
	m_pBtnApplyList = Button::create(
		SGLYTextureName::sSGLY_BtnApplyListNormal,
		SGLYTextureName::sSGLY_BtnApplyListPressed,
		"",
		Widget::TextureResType::PLIST);
	m_pBG->addChild(m_pBtnApplyList);
	m_pBtnApplyList->setPosition(Vec2(sBGSize.width * 0.2, sBGSize.height * 0.88));
	m_pBtnApplyList->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnApplyListEvent, this));

	//	��ť����������ׯ
	m_pBtnApply = Button::create(
		SGLYTextureName::sSGLY_BtnApplyNormal,
		SGLYTextureName::sSGLY_BtnApplyPressed,
		"",
		Widget::TextureResType::PLIST);
	m_pBG->addChild(m_pBtnApply);
	m_pBtnApply->setPosition(Vec2(sBGSize.width * 0.8, sBGSize.height * 0.88));
	m_pBtnApply->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnApplyEvent, this));

	//	��ť����ȡ������
	m_pBtnCancel = Button::create(
		SGLYTextureName::sSGLY_BtnCancelNormal,
		SGLYTextureName::sSGLY_BtnCancelPressed,
		"",
		Widget::TextureResType::PLIST);
	m_pBG->addChild(m_pBtnCancel);
	m_pBtnCancel->setPosition(Vec2(sBGSize.width * 0.8, sBGSize.height * 0.88));
	m_pBtnCancel->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnCancelEvent, this));

	//	��ť������Ҫ��ׯ
	m_pBtnDown = Button::create(
		SGLYTextureName::sSGLY_BtnDownNormal,
		SGLYTextureName::sSGLY_BtnDownPressed,
		"",
		Widget::TextureResType::PLIST);
	m_pBG->addChild(m_pBtnDown);
	m_pBtnDown->setPosition(Vec2(sBGSize.width * 0.8, sBGSize.height * 0.88));
	m_pBtnDown->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnDownEvent, this));

	//	������밴ť
	m_pBtnSupplyChip = Button::create(
		SGLYTextureName::sSGLY_BtnSupplyNormal,
		SGLYTextureName::sSGLY_BtnSupplyPressed,
		SGLYTextureName::sSGLY_BtnSupplyDisabled,
		Widget::TextureResType::PLIST);
	m_pBG->addChild(m_pBtnSupplyChip);
	m_pBtnSupplyChip->setPosition(Vec2(sBGSize.width * 0.37, sBGSize.height * 0.215));
	m_pBtnSupplyChip->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnSupplyEvent, this));

	//	������ť
	m_pBtnBetContinue = Button::create(
		SGLYTextureName::sSGLY_BtnContinueBetNormal,
		SGLYTextureName::sSGLY_BtnContinueBetPressed,
		"",
		Widget::TextureResType::PLIST);
	m_pBG->addChild(m_pBtnBetContinue);
	m_pBtnBetContinue->setPosition(Vec2(sBGSize.width * 0.53, sBGSize.height * 0.215));
	m_pBtnBetContinue->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnBetContinueEvent, this));

	//	ѺС��1-7����ť
	Button* pBtnBetSmall = Button::create(
		SGLYTextureName::sSGLY_BtnBetSmallNormal,
		SGLYTextureName::sSGLY_BtnBetSmallPressed,
		"",
		Widget::TextureResType::PLIST);
	m_pBG->addChild(pBtnBetSmall);
	pBtnBetSmall->setPosition(Vec2(sBGSize.width * 0.69, sBGSize.height * 0.215));
	pBtnBetSmall->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnBetSmallEvent, this));

	//	Ѻ��8-14����ť
	Button* pBtnBetBig = Button::create(
		SGLYTextureName::sSGLY_BtnBetBigNormal,
		SGLYTextureName::sSGLY_BtnBetBigPressed,
		"",
		Widget::TextureResType::PLIST);
	m_pBG->addChild(pBtnBetBig);
	pBtnBetBig->setPosition(Vec2(sBGSize.width * 0.85, sBGSize.height * 0.215));
	pBtnBetBig->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnBetBigEvent, this));

	//	������ť
	Vec2 vBtnMulitplePos[E_SGLY_BettingMode_Null] =
	{
		Vec2(sBGSize.width * 0.2, sBGSize.height * 0.245),
		Vec2(sBGSize.width * 0.175, sBGSize.height * 0.215),
		Vec2(sBGSize.width * 0.14, sBGSize.height * 0.185)
	};

	string sBtnMulitpleTextureName[E_SGLY_BettingMode_Null][2] =
	{
		SGLYTextureName::sSGLY_BtnMultipleNormal_1, SGLYTextureName::sSGLY_BtnMultiplePressed_1,
		SGLYTextureName::sSGLY_BtnMultipleNormal_10, SGLYTextureName::sSGLY_BtnMultiplePressed_10,
		SGLYTextureName::sSGLY_BtnMultipleNormal_100, SGLYTextureName::sSGLY_BtnMultiplePressed_100
	};

	for (int i = E_SGLY_BettingMode_M1; i < E_SGLY_BettingMode_Null; i++)
	{
		m_pBtnMultiple[i] = Button::create(
			sBtnMulitpleTextureName[i][0],
			sBtnMulitpleTextureName[i][0],
			sBtnMulitpleTextureName[i][1],
			Widget::TextureResType::PLIST);
		m_pBG->addChild(m_pBtnMultiple[i]);
		m_pBtnMultiple[i]->setTag(i);
		m_pBtnMultiple[i]->setPosition(vBtnMulitplePos[i]);
		m_pBtnMultiple[i]->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnMultipleEvent, this));
	}

	//	��ע��ť
	string sBtnBetTextureName[E_SGLY_Lottery_Null][2] =
	{
		SGLYTextureName::sSGLY_BtnBetBarNormal, SGLYTextureName::sSGLY_BtnBetBarPressed,
		SGLYTextureName::sSGLY_BtnBetSevenNormal, SGLYTextureName::sSGLY_BtnBetSevenPressed,
		SGLYTextureName::sSGLY_BtnBetStarNormal, SGLYTextureName::sSGLY_BtnBetStarPressed,
		SGLYTextureName::sSGLY_BtnBetWatermelonNormal, SGLYTextureName::sSGLY_BtnBetWatermelonPressed,
		SGLYTextureName::sSGLY_BtnBetBellNormal, SGLYTextureName::sSGLY_BtnBetBellPressed,
		SGLYTextureName::sSGLY_BtnBetPearNormal, SGLYTextureName::sSGLY_BtnBetPearPressed,
		SGLYTextureName::sSGLY_BtnBetOrangeNormal, SGLYTextureName::sSGLY_BtnBetOrangePressed,
		SGLYTextureName::sSGLY_BtnBetAppleNormal, SGLYTextureName::sSGLY_BtnBetApplePressed
	};

	for (int i = E_SGLY_Lottery_Bar; i < E_SGLY_Lottery_Null; i++)
	{
		Button* pBtnBar = Button::create(
			sBtnBetTextureName[i][0],
			sBtnBetTextureName[i][1],
			"",
			Widget::TextureResType::PLIST);
		m_pBG->addChild(pBtnBar);
		pBtnBar->setPosition(Vec2(sBGSize.width * (0.06 + i * 0.125), sBGSize.height * 0.065));
		pBtnBar->setTag(i);
		pBtnBar->addClickEventListener(CC_CALLBACK_1(SGLYGameLayer::onClickBtnBetEvent, this));
	}

	m_pLotteryTips = Sprite::create();
	addChild(m_pLotteryTips);
	m_pLotteryTips->setPosition(Vec2(sBGSize.width * 0.5, sBGSize.height * 0.63));
	m_pLotteryTips->setVisible(false);

	m_pGoodLuckTips = Sprite::create();
	addChild(m_pGoodLuckTips);
	m_pGoodLuckTips->setPosition(Vec2(sBGSize.width * 0.5, sBGSize.height * 0.63));
	m_pGoodLuckTips->setVisible(false);

	m_pGuessResultTips = Sprite::create();
	addChild(m_pGuessResultTips);
	m_pGuessResultTips->setPosition(Vec2(sBGSize.width * 0.5, sBGSize.height * 0.65));
	m_pGuessResultTips->setVisible(false);
}

//	���䱶��ģʽ
void SGLYGameLayer::changeMultipleMode(E_SGLY_BettingMode eType)
{
	switch (eType)
	{
	case E_SGLY_BettingMode_M1:
		m_pBtnMultiple[E_SGLY_BettingMode_M1]->setEnabled(false);
		m_pBtnMultiple[E_SGLY_BettingMode_M10]->setEnabled(true);
		m_pBtnMultiple[E_SGLY_BettingMode_M100]->setEnabled(true);
		m_nCurrBetMultiple = 1;
		break;
	case E_SGLY_BettingMode_M10:
		m_pBtnMultiple[E_SGLY_BettingMode_M1]->setEnabled(true);
		m_pBtnMultiple[E_SGLY_BettingMode_M10]->setEnabled(false);
		m_pBtnMultiple[E_SGLY_BettingMode_M100]->setEnabled(true);
		m_nCurrBetMultiple = 10;
		break;
	case E_SGLY_BettingMode_M100:
		m_pBtnMultiple[E_SGLY_BettingMode_M1]->setEnabled(true);
		m_pBtnMultiple[E_SGLY_BettingMode_M10]->setEnabled(true);
		m_pBtnMultiple[E_SGLY_BettingMode_M100]->setEnabled(false);
		m_nCurrBetMultiple = 100;
		break;
	case E_SGLY_BettingMode_Null:
		break;
	default:
		break;
	}
}

//	�����ע��ť�¼�
void SGLYGameLayer::onClickBtnBetEvent(Ref* pSender)
{
	log("SGLYGameLayer::onClickBtnBetEvent");

	SGLYGameScene* pScene = SGLYGameScene::getGameScene();
	if (!pScene)
	{
		return;
	}
	int nSelfChairID = EntityMgr::instance()->roomFrame()->getMeUserDate()->wChairID;
	int nBankerChairID = pScene->m_pGameLayer->getBankerChairID();
	if (nSelfChairID == nBankerChairID)
	{
		//	�����ׯʱ������Ӧ�¼�
		return;
	}

	E_SGLY_Process eProcess = pScene->m_pClock->getProcess();
	if (eProcess != E_SGLY_Process_Bet)
	{
		//	������ע�����ڼ䣬����Ӧ��ע�¼���
		return;
	}

	Button* pBtn = dynamic_cast<Button*>(pSender);
	if (!pBtn)
	{
		return;
	}
	LONGLONG llNormalBetCount = 1;
	E_SGLY_Lottery eTag = (E_SGLY_Lottery)pBtn->getTag();
	E_SGLY_Audio eAudioID[E_SGLY_Lottery_Null] =
	{
		E_SGLY_Audio_BtnBet_Bar,
		E_SGLY_Audio_BtnBet_Seven,
		E_SGLY_Audio_BtnBet_Star,
		E_SGLY_Audio_BtnBet_Watermelon,
		E_SGLY_Audio_BtnBet_Bell,
		E_SGLY_Audio_BtnBet_Pear,
		E_SGLY_Audio_BtnBet_Orange,
		E_SGLY_Audio_BtnBet_Apple
	};
	SGLYManageAudio::getInstance()->playSoundEffect(eAudioID[eTag]);
	SGLY_CMD_C_PlaceJetton pMessage;
	pMessage.cbJettonArea = eTag;
	pMessage.lJettonScore = SGLYTool::exchangeForGold(llNormalBetCount) * m_nCurrBetMultiple;
	EntityMgr::instance()->getDispatch()->sendSocketDate(SGLY_SUB_C_PLACE_JETTON, &pMessage, sizeof(pMessage));
}

//	����˳���ť�¼�
void SGLYGameLayer::onClickBtnQuitEvent(Ref* pSender)
{
	Scene* pScene = Director::getInstance()->getRunningScene();
	if (!pScene)
	{
		return;
	}
	SGLYPopupQuit* pPopupQuit = SGLYPopupQuit::create();
	pScene->addChild(pPopupQuit);
}

//	������ð�ť�¼�
void SGLYGameLayer::onClickBtnSettingEvent(Ref* pSender)
{
	Scene* pScene = Director::getInstance()->getRunningScene();
	if (!pScene)
	{
		return;
	}
	SGLYPopupSetting* pSetting = SGLYPopupSetting::create();
	pScene->addChild(pSetting);
}

//	���������밴ť�¼�
void SGLYGameLayer::onClickBtnSupplyEvent(Ref* pSender)
{

	SGLYGameScene* pScene = SGLYGameScene::getGameScene();
	if (!pScene)
	{
		return;
	}
	pScene->m_pPopupSupplyChip->setPopupVisible(true);
}

//	�����Ѻ��ť�¼�
void SGLYGameLayer::onClickBtnBetContinueEvent(Ref* pSender)
{
	SGLYGameScene* pScene = SGLYGameScene::getGameScene();
	if (!pScene)
	{
		return;
	}

	//	���Ƶ��Ƶ��
	m_pBtnBetContinue->setEnabled(false);
	auto pDelay = DelayTime::create(0.5f);
	auto pCall = CallFunc::create([=](){
		m_pBtnBetContinue->setEnabled(true);
	});
	auto pSeq = Sequence::create(pDelay, pCall, nullptr);
	runAction(pSeq);

	int nSelfChairID = EntityMgr::instance()->roomFrame()->getMeUserDate()->wChairID;
	int nBankerChairID = pScene->m_pGameLayer->getBankerChairID();
	if (nSelfChairID == nBankerChairID)
	{
		//	�����ׯʱ������Ӧ�¼�
		return;
	}

	E_SGLY_Process eProcess = pScene->m_pClock->getProcess();
	if (eProcess != E_SGLY_Process_Bet)
	{
		//	������ע�����ڼ䣬����Ӧ��ע�¼���
		return;
	}

	for (int i = 0; i < E_SGLY_Lottery_Null; i++)
	{
		LONGLONG llCurrBet = pScene->m_pInfoCenter->getValueSelfBet((E_SGLY_Lottery)i);
		LONGLONG llContinueBet = pScene->m_pInfoCenter->getValueContinueBet((E_SGLY_Lottery)i);
		if (llContinueBet <= 0 || llContinueBet <= llCurrBet)
		{
			continue;
		}

		SGLY_CMD_C_PlaceJetton pMessage;
		pMessage.cbJettonArea = i;
		pMessage.lJettonScore = SGLYTool::exchangeForGold(llContinueBet);
		EntityMgr::instance()->getDispatch()->sendSocketDate(SGLY_SUB_C_PLACE_JETTON, &pMessage, sizeof(pMessage));
	}
}

//	���ѺС��1-7����ť�¼�
void SGLYGameLayer::onClickBtnBetSmallEvent(Ref* pSender)
{
	SGLYGameScene* pScene = SGLYGameScene::getGameScene();
	if (!pScene)
	{
		return;
	}
	E_SGLY_Process eProcess = pScene->m_pClock->getProcess();
	if (eProcess != E_SGLY_Process_Guess)
	{
		//	���ڲ´�С�����ڼ䣬����Ӧ�¼���
		return;
	}

	SGLY_CMD_C_BigSmall pMessage;
	pMessage.cbBigSmall = 0;
	EntityMgr::instance()->getDispatch()->sendSocketDate(SGLY_SUB_C_BIG_SMALL, &pMessage, sizeof(pMessage));
}

//	���Ѻ��8-14����ť�¼�
void SGLYGameLayer::onClickBtnBetBigEvent(Ref* pSender)
{
	SGLYGameScene* pScene = SGLYGameScene::getGameScene();
	if (!pScene)
	{
		return;
	}
	E_SGLY_Process eProcess = pScene->m_pClock->getProcess();
	if (eProcess != E_SGLY_Process_Guess)
	{
		//	���ڲ´�С�����ڼ䣬����Ӧ�¼���
		return;
	}

	SGLY_CMD_C_BigSmall pMessage;
	pMessage.cbBigSmall = 1;
	EntityMgr::instance()->getDispatch()->sendSocketDate(SGLY_SUB_C_BIG_SMALL, &pMessage, sizeof(pMessage));
}

//	���������ť�¼�
void SGLYGameLayer::onClickBtnMultipleEvent(Ref* pSender)
{
	Button* pBtnMultiple = dynamic_cast<Button*>(pSender);
	if (!pBtnMultiple)
	{
		return;
	}
	E_SGLY_BettingMode eTag = (E_SGLY_BettingMode)pBtnMultiple->getTag();
	changeMultipleMode(eTag);
}

//	�����ׯ�б�ť�¼�
void SGLYGameLayer::onClickBtnApplyListEvent(Ref* pSender)
{
	EntityMgr::instance()->getDispatch()->sendSocketDate(SGLY_SUB_C_GET_PLAYLIST);
}

//	���������ׯ��ť�¼�
void SGLYGameLayer::onClickBtnApplyEvent(Ref* pSender)
{
	int nChairID = EntityMgr::instance()->roomFrame()->getMeUserDate()->wChairID;
	SGLY_CMD_S_ApplyBanker pMessage;
	pMessage.wApplyUser = nChairID;
	EntityMgr::instance()->getDispatch()->sendSocketDate(SGLY_SUB_C_APPLY_BANKER, &pMessage, sizeof(pMessage));
}

//	���ȡ�����밴ť�¼�
void SGLYGameLayer::onClickBtnCancelEvent(Ref* pSender)
{
	SGLY_CMD_S_CancelBanker pMessage;
	pMessage.wChairID = EntityMgr::instance()->roomFrame()->getMeUserDate()->wChairID;
	EntityMgr::instance()->getDispatch()->sendSocketDate(SGLY_SUB_C_CANCEL_BANKER, &pMessage, sizeof(pMessage));
}

//	�����Ҫ��ׯ��ť�¼�
void SGLYGameLayer::onClickBtnDownEvent(Ref* pSender)
{
	SGLY_CMD_S_CancelBanker pMessage;
	pMessage.wChairID = EntityMgr::instance()->roomFrame()->getMeUserDate()->wChairID;
	EntityMgr::instance()->getDispatch()->sendSocketDate(SGLY_SUB_C_CANCEL_BANKER, &pMessage, sizeof(pMessage));
}


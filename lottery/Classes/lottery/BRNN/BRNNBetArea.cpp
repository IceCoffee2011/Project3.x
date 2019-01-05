#include "BRNNBetArea.h"
#include "BRNNRes.h"
#include "MyConfig.h"

BRNNBetArea::BRNNBetArea():
	m_llChipValueSum(0),
	m_llChipValueSelf(0),
	m_eAreaType(E_BRNNBetArea_NULL),
	m_pBG(nullptr),
	m_pLight(nullptr),
	m_pChipValueSelfFloor(nullptr),
	m_pLabChipValueSum(nullptr),
	m_pLabChipValueSelf(nullptr)
{
}

BRNNBetArea::~BRNNBetArea()
{
}

void BRNNBetArea::resetTableArea()
{
	stopAllActions();
	//	�������

	m_llChipValueSum = 0;
	m_llChipValueSelf = 0;

	m_pLabChipValueSum->setString("");
	m_pLabChipValueSelf->setString("");

	//	�ر��������

	m_pLight->stopAllActions();
	m_pLight->setVisible(false);

	//	����������
	m_pVesselChip->removeAllChildren();
}

void BRNNBetArea::initArea(E_BRNNBetAreaType eArea)
{
	m_eAreaType = eArea;

	string sBGFileName[E_BRNNBetArea_NULL] =
	{
		BRNNTextureName::s_brnn_bet_area_e,
		BRNNTextureName::s_brnn_bet_area_s,
		BRNNTextureName::s_brnn_bet_area_w,
		BRNNTextureName::s_brnn_bet_area_n
	};
	m_pBG = Sprite::createWithSpriteFrameName(sBGFileName[eArea]);
	addChild(m_pBG);
	cocos2d::Size sBGSize = m_pBG->getContentSize();
	setContentSize(sBGSize);

	m_pVesselChip = Node::create();
	m_pBG->addChild(m_pVesselChip);
	m_pVesselChip->setPosition(Vec2(sBGSize / 2));

	m_pLight = Sprite::createWithSpriteFrameName(BRNNTextureName::s_brnn_bet_area_mask);
	addChild(m_pLight);
	m_pLight->setVisible(false);

	m_pChipValueSelfFloor = Sprite::createWithSpriteFrameName(BRNNTextureName::s_brnn_bet_area_self_value_floor);
	m_pBG->addChild(m_pChipValueSelfFloor);

	m_pLabChipValueSelf = Label::create();
	m_pChipValueSelfFloor->addChild(m_pLabChipValueSelf);
	m_pLabChipValueSelf->setPosition(Vec2(m_pChipValueSelfFloor->getContentSize() / 2));
	m_pLabChipValueSelf->setColor(Color3B::YELLOW);
	m_pLabChipValueSelf->setSystemFontSize(25);

	m_pLabChipValueSum = Label::create();
	m_pBG->addChild(m_pLabChipValueSum);
	m_pLabChipValueSum->setColor(Color3B::WHITE);
	m_pLabChipValueSum->setSystemFontSize(25);

	//	��ͬ�汾��Դ����Ҫ�����Ӧλ��
	MyConfig& myconfig=MyConfig::Instance();
	if(myconfig.m_platform==0)	//	9E
	{
		m_pChipValueSelfFloor->setPosition(Vec2(sBGSize.width * 0.5, sBGSize.height * 0.065));
		m_pLabChipValueSum->setPosition(Vec2(sBGSize.width * 0.5, sBGSize.height * 0.935));
	}
	else//	��Ӯ��
	{
		m_pChipValueSelfFloor->setPosition(Vec2(sBGSize.width * 0.5, sBGSize.height * 0.135));
		m_pLabChipValueSum->setPosition(Vec2(sBGSize.width * 0.5, sBGSize.height * 0.885));
	}

	float fOriginY = this->getPosition().y - sBGSize.height / 2;
	float fOriginX = this->getPosition().x - sBGSize.width / 2;
	m_rAreaRect = Rect(Vec2(fOriginX, fOriginY), sBGSize);
}

bool BRNNBetArea::isContainsPoint(Vec2 vPos)
{
	return m_rAreaRect.containsPoint(vPos);
}

Sprite* BRNNBetArea::addTableChip(E_BRNNChipType eType)
{
	string sBufChipNormal[E_BRNNChip_NULL] = 
	{
		BRNNTextureName::s_brnn_chip_normal_1,
		BRNNTextureName::s_brnn_chip_normal_5,
		BRNNTextureName::s_brnn_chip_normal_10,
		BRNNTextureName::s_brnn_chip_normal_50,
		BRNNTextureName::s_brnn_chip_normal_100,
		BRNNTextureName::s_brnn_chip_normal_200,
		BRNNTextureName::s_brnn_chip_normal_500,
		BRNNTextureName::s_brnn_chip_normal_1k,
	};
	Sprite* pChip = Sprite::createWithSpriteFrameName(sBufChipNormal[eType]);
	m_pVesselChip->addChild(pChip);
	pChip->setScale(BRNN_AREA_CHIP_SCALE_SMALL);

	//	����this��λ�����������ģ�����ķ�Χ��Ҫ����
	cocos2d::Size sBGSize = m_pBG->getContentSize();
	float fXScale = 0.7f;
	float fYScale = 0.3f;
	float fX = random(sBGSize.width / 2 * -fXScale, sBGSize.width / 2 * fXScale);
	float fY = random(sBGSize.height / 2 * -fYScale, sBGSize.height / 2 * fYScale);
	pChip->setPosition(Vec2(fX, fY));
	return pChip;
}

void BRNNBetArea::setAreaHighLight(bool isHighLight)
{
	m_pLight->setVisible(isHighLight);
	if (isHighLight)
	{
		auto pBlink = Blink::create(2.0f, 3);
		m_pLight->runAction(pBlink);
	}
}

//	���ó�����ע�ı���ֵ
void BRNNBetArea::setLabChipValueSum(LONGLONG llValue)
{
	char cBufValue[128];
	sprintf(cBufValue, "%lld",llValue);
	m_pLabChipValueSum->setString(cBufValue);
}

//	���ó����ע�ı���ֵ
void BRNNBetArea::setLabChipValueSelf(LONGLONG llValue)
{
	char cBufValue[128];
	sprintf(cBufValue, "%lld",llValue);
	m_pLabChipValueSelf->setString(cBufValue);
}

bool BRNNBetArea::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!Node::init());

		bRet = true;
	} while (0);

	return bRet;
}

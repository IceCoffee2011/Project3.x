#include "AwardLayer.h"


USING_NS_CC;
using namespace cocostudio;
using namespace ui;


AwardLayer::AwardLayer()
{
	m_btnQuit = nullptr;
	m_btnConfirm = nullptr;
	m_nAllStep = 0;
	m_nCurStep = 0;
	m_nCanGetCount = 0;
	m_nCanMaxCount = 0;
	m_nTotalTime = 0;
	for (int i = 0; i < 6; i++)
	{
		m_Award_Show[i] = nullptr;
		m_Award_Show_Min[i] = nullptr;
		m_Award_NotGet[i] = nullptr;
	}
	m_Label_Hour = nullptr;
	m_Label_Min = nullptr;
	m_Label_Sec = nullptr;

	m_nSecond[0] = 60;
	m_nSecond[1] = 120;
	m_nSecond[2] = 300;
	m_nSecond[3] = 600;
	m_nSecond[4] = 1800;
	m_nSecond[5] = 3600;
}

AwardLayer::~AwardLayer()
{
}

bool AwardLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->setAnchorPoint(Vec2(0.5f, 0.5f));
	uiWidget = GUIReader::getInstance()->widgetFromJsonFile("709/AwardLayer/AwardLayer.ExportJson");
	uiWidget->setRotation(180.0f);
	uiWidget->setPosition(Vec2(uiWidget->getContentSize().width, uiWidget->getContentSize().height));
	this->addChild(uiWidget);
	this->setContentSize(uiWidget->getContentSize());

	std::string name;
	for (int i = 0; i < 6; i++)
	{
		name = StringUtils::format("Award_Show%d", i);
		m_Award_Show[i] = dynamic_cast<ImageView*>(Helper::seekWidgetByName(uiWidget, name));
		name = StringUtils::format("Award_Show_Min%d", i);
		m_Award_Show_Min[i] = dynamic_cast<ImageView*>(Helper::seekWidgetByName(uiWidget, name));
		name = StringUtils::format("Award_NotGet%d", i);
		m_Award_NotGet[i] = dynamic_cast<ImageView*>(Helper::seekWidgetByName(uiWidget, name));
	}
	
	//ʱ���֣���
	m_Label_Hour = dynamic_cast<Text*>(Helper::seekWidgetByName(uiWidget, "Award_Label_Hour"));
	m_Label_Min = dynamic_cast<Text*>(Helper::seekWidgetByName(uiWidget, "Award_Label_Min"));
	m_Label_Sec = dynamic_cast<Text*>(Helper::seekWidgetByName(uiWidget, "Award_Label_Sec"));

	m_Label_Hour->setString("");
	m_Label_Min->setString("");
	m_Label_Sec->setString("");
	//ȷ����ȡ��ť
	m_btnConfirm = dynamic_cast<Button*>(Helper::seekWidgetByName(uiWidget, "Award_Btn_Get"));
	m_btnConfirm->addTouchEventListener(this, SEL_TouchEvent(&AwardLayer::buttonConfirm));

	//�رհ�ť
	m_btnQuit  = dynamic_cast<Button*>(Helper::seekWidgetByName(uiWidget,"Award_Btn_Quit"));
	m_btnQuit->addTouchEventListener(this,SEL_TouchEvent(&AwardLayer::buttonQuit));

	return true;
}


void AwardLayer::buttonQuit(cocos2d::Ref* sender,cocos2d::ui::TouchEventType type)
{
	if (type != TouchEventType::TOUCH_EVENT_ENDED)
		return;
	this->removeFromParentAndCleanup(true);
	
}

void AwardLayer::buttonConfirm(cocos2d::Ref* sender,cocos2d::ui::TouchEventType type)
{
	if (type != TouchEventType::TOUCH_EVENT_ENDED)
	{
		return;
	}
	if (m_nCurStep >= m_nAllStep)
	{
		return;
	}
	
	if (++m_nCurStep >= m_nAllStep)
	{
		//ȷ����ȡ��Ϊ���ɵ�
		m_btnConfirm->setColor(Color3B::GRAY);
		m_btnConfirm->setEnabled(false);
	}

}

void AwardLayer::setStatus(int nAllSetp, int nCurStep, int nTotlaTime)
{
	//������ԣ��ͷ���
	if (nCurStep > nAllSetp || nCurStep > 6 || nAllSetp > 6)
	{
		
	}
	
	m_nAllStep = nAllSetp - 1;
	m_nCurStep = nCurStep - 1;
	m_nTotalTime = nTotlaTime;

	//����Ѿ���ȡ���ڿ�����ȡ ����
	if (nCurStep >= nAllSetp)
	{
		m_btnConfirm->setColor(Color3B::GRAY);
		m_btnConfirm->setEnabled(false);
	}
	
	m_nCanGetCount = 0;
	//m_nCanMaxCount = m_nCurStep
	if(m_nCurStep == 5)
	{
		m_btnConfirm->setEnabled(true);
	}
	//�Ѿ���ȡ��
	for (int i = 0; i <= m_nCurStep; i++)
	{
		//С�ֱ�ǩ ������ȡ��
		m_Award_NotGet[i]->loadTexture("709/AwardLayer/Award_FinishGet.png");
		//ͼ�����
		m_Award_Show[i]->loadTexture(StringUtils::format("709/AwardLayer/Award_Show%d.png", i));
	}

	//������ȡ�� ������ȡ��
	for (int i = m_nCurStep + 1; i <= m_nAllStep; i++)
	{
		//С�ֱ�ǩ
		m_Award_NotGet[i]->loadTexture("709/AwardLayer/Award_CanGet.png");
		//ͼ����
		//m_Award_Show[i]->loadTexture(StringUtils::format("AwardLayer/Award_Show%d.png", i));
	}

	//δ�ﵽ����ȡ������
	for (int i = m_nAllStep + 1; i < 6; i++)
	{
		//С�ֱ�ǩ ��δ�ﵽ��
		m_Award_NotGet[i]->loadTexture("709/AwardLayer/Award_CanNotGet.png");
		//ͼ����
		m_Award_Show[i]->setColor(ccc3(100, 100, 100));
	}

	this->schedule(SEL_SCHEDULE(&AwardLayer::onTime),1.0f);
}

void AwardLayer::setCurStatus(int nCurStep)
{
	if (nCurStep > 5)
	{
		return;
	}
	//�ı�ͼ��
	//С�ֱ�ǩ ������ȡ��
	m_Award_NotGet[nCurStep]->loadTexture("709/AwardLayer/Award_FinishGet.png");
	//ͼ�����
	m_Award_Show[nCurStep]->loadTexture(StringUtils::format("709/AwardLayer/Award_Show%d.png", nCurStep));
}

void AwardLayer::onTime(float dt)
{	
// 	m_nSecond[0] = 60;
// 	m_nSecond[1] = 120;
// 	m_nSecond[2] = 300;
// 	m_nSecond[3] = 600;
// 	m_nSecond[4] = 1800;
// 	m_nSecond[5] = 3600;
	
	m_nTotalTime++;
	switch (m_nAllStep)
	{
	case -1:
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		{
			int nTempTime = m_nSecond[m_nAllStep + 1] - m_nTotalTime;	
			m_Label_Hour->setString(StringUtils::format("%02d", nTempTime / 3600));
			m_Label_Min->setString(StringUtils::format("%02d", nTempTime / 60));
			m_Label_Sec->setString(StringUtils::format("%02d", nTempTime % 60));
			if (m_nTotalTime >= m_nSecond[m_nAllStep + 1])
			{
				//С�ֱ�ǩ
				m_Award_NotGet[m_nAllStep + 1]->loadTexture("709/AwardLayer/Award_CanGet.png");
				//ͼ���ԭ��
				m_Award_Show[m_nAllStep + 1]->setColor(Color3B::WHITE);
				//ȷ����ȡ��ť��λ
				m_btnConfirm->setColor(Color3B::WHITE);
				m_btnConfirm->setEnabled(true);

				m_nAllStep = m_nAllStep + 1;				
			}
		}		
		break;
	default:
		m_Label_Hour->setString("00");
		m_Label_Min->setString("00");
		m_Label_Sec->setString("00");
		if (m_nCurStep >= m_nAllStep)
		{
			m_btnConfirm->setEnabled(false);
		}		
		break;
	}

}




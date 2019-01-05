#include "DDZTimer.h"
#include "MyTools.h"//<by hxh>
#include "DDZTimeCheckControl.h"
using namespace std;
using namespace DDZtexture_name;

#define NO_ACTION_ALL_TIME		32		//�ͻ������������������ʱ�䣬������Ϊ40s��

DDZTimer::DDZTimer():
	longTimeNoAction(false),
	m_allCountTime(0)
{

}

DDZTimer::~DDZTimer()
{

}

bool DDZTimer::init()
{
	if (!Node::init())
	{
		return false;
	}
	g_timerNode = Node::create();
	this->addChild(g_timerNode);

	//ʱ��
	Sprite * timer = Sprite::createWithSpriteFrameName(DDZtexture_name::s_timer);
	g_timerNode->addChild(timer);
	cocos2d::Size sTimeBGSize = timer->getContentSize();

	//ʱ������
	m_pDDZTimeNum = Label::createWithBMFont(DDZtexture_name::s_fntDDZTimeNum, "");
	timer->addChild(m_pDDZTimeNum);
	m_pDDZTimeNum->setPosition(Vec2(sTimeBGSize.width * 0.5, sTimeBGSize.height * 0.4));
	m_timeKey= 0;
	m_gameState =DDZGame_null;
	return true;
}

void DDZTimer::start(int userId, int t,DDZGame_State gameState,int key)
{
	longTimeNoAction = false;
	stopCheckCheckNoAction();
	cocos2d::Size sVSize = Director::getInstance()->getVisibleSize();
	this->unscheduleAllSelectors();
	g_timerNode->stopAllActions();
	m_time = t;
	m_allCountTime = t;
	m_gameState = gameState;
	m_UserID =userId;
	m_timeKey= key;

	switch(userId)
	{
	case 0://�ϼ�
		this->setPosition(Vec2(sVSize.width * 0.15, sVSize.height * 0.7));
		break;
	case 1://�Լ�
		this->setPosition(Vec2(sVSize.width * 0.5, sVSize.height * 0.6));
		break;
	case 2://�¼�
		this->setPosition(Vec2(sVSize.width * 0.85, sVSize.height * 0.7));
		break;
	}
	m_pDDZTimeNum->setString(Value(m_time--).asString());
	this->schedule(schedule_selector(DDZTimer::time_schedule),1.0f);

	int nextUserId = m_UserID - 1;
	if (nextUserId < 0)
	{
		nextUserId = 2;
	}
	DDZCConline * _onLineData =DDZCConline::create(DDZmsgToView_OnLine);
	_onLineData->m_isOnline = true;
	_onLineData->m_userID =	nextUserId;
	NotificationCenter::getInstance()->postNotification(MESSAGE_TOVIEW,_onLineData);
}

void DDZTimer::time_schedule(float t)
{
	int leaveTime = DDZTimeCheckControl::getInstance()->getPauseTime();
	int temp = m_time - leaveTime;
	if (leaveTime > 0)
	{
		if (leaveTime <= 30)
		{
			if (temp > 0)
			{
				m_time = temp;
			}
			else
			{
				m_time = m_time > 3 ? 3 : m_time;// ����ʱ������3�룬��3������ʾ
			}
		}
		else
		{
			m_time = m_time > 3 ? 3 : m_time;// ����ʱ������3�룬��3������ʾ
		}
	}

	if (m_time>0)
	{
		m_pDDZTimeNum->setString(Value(m_time--).asString());
		if (m_time<5)
		{
			m_pDDZTimeNum->runAction(Sequence::create(ScaleTo::create(0.2f,1.2f),ScaleTo::create(0.2f,1.0f),NULL));
			if (g_timerNode->numberOfRunningActions()<=0)
			{
				g_timerNode->runAction(CCShake::create(10.0f,1));
			}
		}
	}else{
		this->unschedule(schedule_selector(DDZTimer::time_schedule));
		g_timerNode->stopAllActions();
		this->setVisible(false);
		if (m_UserID ==1)
		{
			DDZCCtimeCallBack* _callBackData=DDZCCtimeCallBack::create(DDZmsgToview_TimeCallBack);
			_callBackData->m_gameState =m_gameState;
			_callBackData->m_timeKey =m_timeKey;
			NotificationCenter::getInstance()->postNotification(MESSAGE_TOVIEW,_callBackData);
		}
		else
		{//���˵���ʱ���󣬻�δ����
			longTimeNoAction = true;
			startCheckNoAction();
		}
	}
}

void DDZTimer::onUserNoAction(float dt)
{
	//֪ͨ�û���ʾ����״̬
	if (!longTimeNoAction)
	{
		return;
	}
	DDZCConline * _onLineData =DDZCConline::create(DDZmsgToView_OnLine);
	_onLineData->m_isOnline = false;
	_onLineData->m_userID =	m_UserID;
	NotificationCenter::getInstance()->postNotification(MESSAGE_TOVIEW,_onLineData);
}

void DDZTimer::startCheckNoAction()
{
	//
	this->scheduleOnce(schedule_selector(DDZTimer::onUserNoAction), 1.0f);
}

void DDZTimer::stopCheckCheckNoAction()
{
	//
	unschedule(schedule_selector(DDZTimer::onUserNoAction));
}


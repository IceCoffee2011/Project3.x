#include "SetUpLayer.h"

SetUpLayer::SetUpLayer()
{
	
	m_voiceIsOpen = UserDefault::getInstance()->getBoolForKey("ZJD_SOUNDSTATE",false);
	m_faceIsOpen = UserDefault::getInstance()->getBoolForKey("faceIsOpen",true);
	m_musicVol = UserDefault::getInstance()->getFloatForKey("ZJD_SOUNDNUM",0.5f);
	m_soundEffVol = UserDefault::getInstance()->getFloatForKey("SOUNDEFFVOL",0.5f);
	m_soundBarIsSelected = false;
	m_musicBarIsSelected = false;
}

SetUpLayer::~SetUpLayer()
{

}

bool SetUpLayer::init()
{
	cocos2d::Size size = Director::getInstance()->getWinSize();
	m_bgPoint = ccp(size.width/2,size.height/2);
	if (!Layer::init())
	{
		return false;
	}

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(SetUpLayer::onTouchBegan,this);
	listener->onTouchEnded = CC_CALLBACK_2(SetUpLayer::onTouchEnded,this);
	listener->onTouchMoved = CC_CALLBACK_2(SetUpLayer::onTouchMoved,this);
	listener->onTouchCancelled = CC_CALLBACK_2(SetUpLayer::onTouchCancelled,this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//���ñ�����ɫ͸��
	LayerColor * colorLayer = LayerColor::create(ccc4(0,0,0,120));
	this->addChild(colorLayer);
	//����batchnode
	m_batchNode = SpriteBatchNode::create(texture_name::s_cardTable);
	//�����׿�
	m_bgSprite = Sprite::createWithSpriteFrameName(texture_name::s_task_k);
	m_bgSprite->setPosition(m_bgPoint);
	//�������ذ�ť
	if(!m_voiceIsOpen)
	{
		m_voice = Sprite::createWithSpriteFrameName(texture_name::s_on);//��������ͼ
	}else{
		m_voice = Sprite::createWithSpriteFrameName(texture_name::s_off);//�����ص�ͼ
	}
	m_voice->setAnchorPoint(ccp(0,0.5f));
	m_voice->setPosition(ccp(m_bgPoint.x-180.0f,m_bgPoint.y+85.0f));
	m_voiceOnOff = Sprite::createWithSpriteFrameName(texture_name::s_on_off);//�������ذ�ť
	m_voiceOnOff->setAnchorPoint(m_voice->getAnchorPoint());
	if (!m_voiceIsOpen)
	{
		m_voiceOnOff->setPosition(m_voice->getPosition());
	}else{
		m_voiceOnOff->setPosition(ccp(m_voice->getPositionX()+m_voice->getContentSize().width/2-10,m_voice->getPositionY()));
	}
	//��������
	Sprite * voiceFont = Sprite::createWithSpriteFrameName(texture_name::s_voice);
	voiceFont->setPosition(ccp(m_bgPoint.x-40.0f,m_bgPoint.y+85.0f));
	//���鿪�ذ�ť
	if (m_faceIsOpen)
	{
		m_face = Sprite::createWithSpriteFrameName(texture_name::s_on);
	}else{
		m_face = Sprite::createWithSpriteFrameName(texture_name::s_off);
	}
	m_face->setAnchorPoint(ccp(0,0.5f));
	m_face->setPosition(ccp(m_bgPoint.x+27,m_bgPoint.y+85.0f));
	m_faceOnOff = Sprite::createWithSpriteFrameName(texture_name::s_on_off);
	m_faceOnOff->setAnchorPoint(m_face->getAnchorPoint());
	if (m_faceIsOpen)
	{
		m_faceOnOff->setPosition(m_face->getPosition());
	}else{
		m_faceOnOff->setPosition(ccp(m_face->getPositionX()+m_face->getContentSize().width/2-10,m_face->getPositionY()));
	}
	//��������
	Sprite * faceFont = Sprite::createWithSpriteFrameName(texture_name::s_expression);
	faceFont->setPosition(ccp(m_bgPoint.x+175.0f,m_bgPoint.y+85.0f));
	//��Ч
	Sprite * soundEffSprite = Sprite::createWithSpriteFrameName(texture_name::s_soundEffect);
	soundEffSprite->setPosition(ccp(m_voice->getPositionX()+m_voice->getContentSize().width/2-20,m_bgPoint.y));
	Sprite * soundProgressBg = Sprite::createWithSpriteFrameName(texture_name::s_progress_bj);
	soundProgressBg->setPosition(ccp(m_bgPoint.x+50.0f,soundEffSprite->getPositionY()));

	m_soundEffTimer = ProgressTimer::create(Sprite::createWithSpriteFrameName(texture_name::s_progress));
	m_soundEffTimer->setPosition(soundProgressBg->getPosition());
	m_soundEffTimer->setMidpoint(ccp(0,0));
	m_soundEffTimer->setBarChangeRate(ccp(1.0f,0));
	m_soundEffTimer->setType(ProgressTimer::Type::BAR);
	m_soundEffTimer->setPercentage(m_soundEffVol*100);
	m_soundEffTimerBar = Sprite::createWithSpriteFrameName(texture_name::s_on_off);
	m_soundEffTimerBar->setAnchorPoint(ccp(0.3f,0.5f));
	m_soundEffTimerBar->setPosition(ccp(m_soundEffTimer->getPositionX()-m_soundEffTimer->getContentSize().width/2
		+m_soundEffTimer->getPercentage()*m_soundEffTimer->getContentSize().width/100.0f,
		m_soundEffTimer->getPositionY()));

	//��������
	Sprite * musicSprite = Sprite::createWithSpriteFrameName(texture_name::s_music);
	musicSprite->setPosition(ccp(soundEffSprite->getPositionX(),soundEffSprite->getPositionY()-75.0f));
	Sprite * musicProgressBg = Sprite::createWithSpriteFrameName(texture_name::s_progress_bj);
	musicProgressBg->setPosition(ccp(m_bgPoint.x+50.0f,musicSprite->getPositionY()));

	m_musicTimer = ProgressTimer::create(Sprite::createWithSpriteFrameName(texture_name::s_progress));
	m_musicTimer->setPosition(musicProgressBg->getPosition());
	m_musicTimer->setMidpoint(ccp(0,0));
	m_musicTimer->setBarChangeRate(ccp(1.0f,0));
	m_musicTimer->setType(ProgressTimer::Type::BAR);
	m_musicTimer->setPercentage(m_musicVol*100);
	m_musicTimerBar = Sprite::createWithSpriteFrameName(texture_name::s_on_off);
	m_musicTimerBar->setAnchorPoint(ccp(0.3f,0.5f));
	m_musicTimerBar->setPosition(ccp(m_musicTimer->getPositionX()-m_musicTimer->getContentSize().width/2
		+m_musicTimer->getPercentage()*m_musicTimer->getContentSize().width/100.0f,
		m_musicTimer->getPositionY()));

	this->addChild(m_batchNode);
 	m_batchNode->addChild(m_bgSprite);
 	m_batchNode->addChild(m_voice,0,0);
	m_batchNode->addChild(m_voiceOnOff,1,0);
	m_batchNode->addChild(voiceFont);
	m_batchNode->addChild(m_face,0,0);
	m_batchNode->addChild(m_faceOnOff,1,0);
	m_batchNode->addChild(faceFont);
	m_batchNode->addChild(soundEffSprite);
	m_batchNode->addChild(musicSprite);
	m_batchNode->addChild(soundProgressBg);
	m_batchNode->addChild(musicProgressBg);
	this->addChild(m_soundEffTimer);
	this->addChild(m_soundEffTimerBar);
	this->addChild(m_musicTimer);
	this->addChild(m_musicTimerBar);

	return true;
}

bool SetUpLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	Vec2 point = pTouch->getLocation();
	if (m_voiceOnOff->boundingBox().containsPoint(point))	//�ж��Ƿ������������
	{
		m_voiceIsOpen = !m_voiceIsOpen;
		SoundControl::sharedSoundControl()->setVoiceIsOpen(m_voiceIsOpen);
		setVoiceState(m_voiceIsOpen);
		return true;
	}
	if (m_faceOnOff->boundingBox().containsPoint(point))	//�ж��Ƿ���б��鿪��
	{
		m_faceIsOpen = !m_faceIsOpen;
		UserDefault::getInstance()->setBoolForKey("faceIsOpen",m_faceIsOpen);
		setFaceState(m_faceIsOpen);
		return true;
	}
	if (!m_bgSprite->boundingBox().containsPoint(point))	//�ж��Ƿ����������������
	{
		this->getParent()->removeChild(this,true);
		return true;
	}
	if (m_soundEffTimerBar->boundingBox().containsPoint(point))	//�ж��Ƿ������Ч�϶�����ť
	{
		m_soundBarIsSelected = true;
	}
	if(m_musicTimerBar->boundingBox().containsPoint(point))		//�ж��Ƿ���б��������϶�����ť
	{
		m_musicBarIsSelected = true;
	}
	return true;
}

void SetUpLayer::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	Vec2 point = pTouch->getLocation();
	if (m_soundBarIsSelected)	//��Ч���϶�Ч��
	{
		if (point.x<=m_soundEffTimer->getPositionX()-m_soundEffTimer->getContentSize().width/2)
		{
			m_soundEffTimer->setPercentage(0);
			m_soundEffVol = 0;
			m_soundEffTimerBar->setPosition(ccp(m_soundEffTimer->getPositionX()-m_soundEffTimer->getContentSize().width/2
				+m_soundEffTimer->getPercentage()*m_soundEffTimer->getContentSize().width/100.0f,
				m_soundEffTimer->getPositionY()));
			SoundControl::sharedSoundControl()->setSoundEffVol(m_soundEffVol);//������Ч����
		}else
		if (point.x>=m_soundEffTimer->getPositionX()+m_soundEffTimer->getContentSize().width/2)
		{
			m_soundEffTimer->setPercentage(100.0f);
			m_soundEffVol = 1.0;
			m_soundEffTimerBar->setPosition(ccp(m_soundEffTimer->getPositionX()-m_soundEffTimer->getContentSize().width/2
				+m_soundEffTimer->getPercentage()*m_soundEffTimer->getContentSize().width/100.0f,
				m_soundEffTimer->getPositionY()));
			SoundControl::sharedSoundControl()->setSoundEffVol(m_soundEffVol);//������Ч����
		}else{
			m_soundEffTimerBar->setPositionX(point.x);
			m_soundEffTimer->setPercentage((point.x-(m_soundEffTimer->getPositionX()-m_soundEffTimer->getContentSize().width/2))/m_soundEffTimer->getContentSize().width*100.0f);
			m_soundEffVol = ((float)m_soundEffTimer->getPercentage())/100.0f;
			SoundControl::sharedSoundControl()->setSoundEffVol(m_soundEffVol);//������Ч����
		}
		return;
	}

	if (m_musicBarIsSelected)	//�����������϶�Ч��
	{
		if (point.x<=m_musicTimer->getPositionX()-m_musicTimer->getContentSize().width/2)
		{
			m_musicTimer->setPercentage(0);
			m_musicVol = 0;
			m_musicTimerBar->setPosition(ccp(m_musicTimer->getPositionX()-m_musicTimer->getContentSize().width/2
				+m_musicTimer->getPercentage()*m_musicTimer->getContentSize().width/100.0f,
				m_musicTimer->getPositionY()));
			SoundControl::sharedSoundControl()->setMusicVol(m_musicVol);
		}else
		if (point.x>=m_musicTimer->getPositionX()+m_musicTimer->getContentSize().width/2)
		{
			m_musicTimer->setPercentage(100.0f);
			m_musicVol = 1.0f;
			m_musicTimerBar->setPosition(ccp(m_musicTimer->getPositionX()-m_musicTimer->getContentSize().width/2
				+m_musicTimer->getPercentage()*m_musicTimer->getContentSize().width/100.0f,
				m_musicTimer->getPositionY()));
			SoundControl::sharedSoundControl()->setMusicVol(m_musicVol);
		}else{
			m_musicTimerBar->setPositionX(point.x);
			m_musicTimer->setPercentage((point.x-(m_musicTimer->getPositionX()-m_musicTimer->getContentSize().width/2))/m_musicTimer->getContentSize().width*100.0f);
			m_musicVol = ((float)m_musicTimer->getPercentage())/100.0f;
			SoundControl::sharedSoundControl()->setMusicVol(m_musicVol);
		}
		return;
	}

}

void SetUpLayer::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	m_soundBarIsSelected = false;
	m_musicBarIsSelected = false;
}

void SetUpLayer::onTouchCancelled(Touch *pTouch, Event *pEvent)
{

}

void SetUpLayer::setVoiceState(bool voiceState)
{
	m_batchNode->removeChild(m_voice,true);
	if(!voiceState)
	{
		m_voice = Sprite::createWithSpriteFrameName(texture_name::s_on);//��������ͼ
		m_voice->setAnchorPoint(ccp(0,0.5f));
		m_voice->setPosition(ccp(m_bgPoint.x-180.0f,m_bgPoint.y+85.0f));
		m_voiceOnOff->setPosition(m_voice->getPosition());
	}else{
		m_voice = Sprite::createWithSpriteFrameName(texture_name::s_off);//�����ص�ͼ
		m_voice->setAnchorPoint(ccp(0,0.5f));
		m_voice->setPosition(ccp(m_bgPoint.x-180.0f,m_bgPoint.y+85.0f));
		m_voiceOnOff->setPosition(ccp(m_voice->getPositionX()+m_voice->getContentSize().width/2-10,m_voice->getPositionY()));
	}
	m_batchNode->addChild(m_voice,0,0);
}

void SetUpLayer::setFaceState(bool faceState)
{
	m_batchNode->removeChild(m_face,true);
	if (faceState)
	{
		m_face = Sprite::createWithSpriteFrameName(texture_name::s_on);
		m_face->setAnchorPoint(ccp(0,0.5f));
		m_face->setPosition(ccp(m_bgPoint.x+27,m_bgPoint.y+85.0f));
		m_faceOnOff->setPosition(m_face->getPosition());
	}else{
		m_face = Sprite::createWithSpriteFrameName(texture_name::s_off);
		m_face->setAnchorPoint(ccp(0,0.5f));
		m_face->setPosition(ccp(m_bgPoint.x+27,m_bgPoint.y+85.0f));
		m_faceOnOff->setPosition(ccp(m_face->getPositionX()+m_face->getContentSize().width/2-10,m_face->getPositionY()));
	}
	m_batchNode->addChild(m_face,0,0);
}

void SetUpLayer::onEnter()
{
	Layer::onEnter();
}

void SetUpLayer::onExit()
{
	Layer::onExit();
}

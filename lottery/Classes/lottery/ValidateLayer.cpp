#include "ValidateLayer.h"
#include "CocosUnits.h"
#include "Define.h"
#include "ConfigMgr.h"
#include "EntityMgr.h"
#include "network/HttpClient.h"
#include "MovingLabelLayer.h"

bool ValidateLayer::m_isShow = false;

ValidateLayer::ValidateLayer()
{
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ValidateLayer::validateCodeReback), "ValidateCodeReback", NULL);
}

ValidateLayer::~ValidateLayer()
{
	NotificationCenter::getInstance()->removeObserver(this, "ValidateCodeReback");
}

bool ValidateLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
   
	this->initData();
	this->initView();
    
    return true;
}

void ValidateLayer::initData()
{
	iTimer = 0;
	iType = 0;
	m_times = 0;
	m_isValidating = false;
	m_phoneNumber.clear();
}

void ValidateLayer::startTimer()
{
	//�Ӹ�����
	if(m_isValidating) return;	

	//��ʼ����ʱ
	iTimer = 120;
	//�ҵ�ʱ��label
	auto layer = (LayerColor *)this->getChildByTag(1234);
	if(layer == nullptr) return;
	auto bk = (Sprite *)layer->getChildByTag(1235);
	if(bk == nullptr) return;
	auto btGet = (EditBox *)bk->getChildByTag(9527);
	if(btGet == nullptr) return;
	auto lbTimer = (LabelTTF *)btGet->getChildByTag(9528);
	if(lbTimer == nullptr) return;
	auto lbTips = (LabelTTF *)bk->getChildByTag(2222);
	if(lbTips == nullptr) return;

	m_isValidating = true;

	//�������ڷ�����֤��
	lbTips->setString(ConfigMgr::instance()->text("display_text.xml", "t5014"));

	//������֤��
	sendHttpRequest();

	btGet->setEnabled(false);
	lbTimer->setVisible(true);

	this->schedule([=](float dt){
		//��ʾ����ʱ
		lbTimer->setString(String::createWithFormat("%s(%d)",ConfigMgr::instance()->text("display_text.xml","t5030"),iTimer)->getCString());
		if(iTimer <= 0)
		{
			lbTimer->setVisible(false);
			btGet->setEnabled(true);			
			m_isValidating = false;
			this->unschedule("deTimer_start");
			UserDefault::getInstance()->setStringForKey("VALIDATECODE","aaaaaa");
		}
		iTimer --;
	},1.0f,"deTimer_start");
}

void ValidateLayer::stopTimer()
{
	//ֹͣ����ʱ
	iTimer = 0;

	//�ҵ�ʱ��label
	auto layer = (LayerColor *)this->getChildByTag(1234);
	if(layer == nullptr) return;
	auto bk = (Sprite *)layer->getChildByTag(1235);
	if(bk == nullptr) return;
	auto btGet = (EditBox *)bk->getChildByTag(9527);
	if(btGet == nullptr) return;
	auto lbTimer = (LabelTTF *)btGet->getChildByTag(9528);
	if(lbTimer == nullptr) return;

	btGet->setEnabled(true);
	lbTimer->setVisible(false);
	UserDefault::getInstance()->setStringForKey("VALIDATECODE","aaaaaa");
}

void ValidateLayer::initView()
{
	//��ʼ������
	LayerColor* layer = LayerColor::create(ccc4(0, 0,0, 200), SCREEN_WIDTH, SCREEN_HEIGHT);
	layer->ignoreAnchorPointForPosition(false);
	//layer->setOpacity(125);
	layer->setTag(1234);
	layer->setPosition(Vec2(SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2));
	this->addChild(layer);

	//��������¼�
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [=](Touch *pTouch, Event *pEvent){return true;};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, layer);

	//�������ؼ�
	auto listener_back = EventListenerKeyboard::create();
	listener_back->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event *event){
		if(keycode == EventKeyboard::KeyCode::KEY_BACK)
		{			
			event->stopPropagation();
		}
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener_back, layer);

	//����ͼ
	Sprite *bk1 = Sprite::createWithSpriteFrame(spriteFrame("recharge_25_3.png"));
	bk1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	bk1->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50));
	bk1->setTag(1235);
	layer->addChild(bk1,1);

	float nYPos = bk1->getContentSize().height / 2;
	float posX1 = bk1->getContentSize().width / 2;
	int fontSize = 27;

	//��ʾ
	LabelTTF* tipsLabel = LabelTTF::create(ConfigMgr::instance()->text("display_text.xml", "t5015"), "", fontSize);
	tipsLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	tipsLabel->setPosition(Vec2(bk1->getContentSize().width / 2, nYPos * 11 / 8));
	tipsLabel->setColor(ccc3(200,0,0));
	tipsLabel->setTag(2222);
	tipsLabel->setVerticalAlignment(TextVAlignment::CENTER);
	tipsLabel->setHorizontalAlignment(TextHAlignment::LEFT);
	bk1->addChild(tipsLabel);

	//��֤��
	EditBox* editBindBox = EditBox::create(cocos2d::Size(200,60), "blank.png");	
	editBindBox->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	editBindBox->setPosition(Vec2(posX1 / 2 + 30,nYPos));
	editBindBox->setFontColor(ccc3(120,120,120));
	editBindBox->setPlaceholderFontColor(ccColor4B::GRAY);
	editBindBox->setPlaceHolder(ConfigMgr::instance()->text("display_text.xml", "t5001"));
	editBindBox->setPlaceholderFontName("");
	editBindBox->setPlaceholderFontSize(22);
	editBindBox->setFontName("");
	editBindBox->setFontSize(26);
	editBindBox->setInputFlag(ui::EditBox::InputFlag::SENSITIVE);
	editBindBox->setInputMode(EditBox::InputMode::NUMERIC);
	editBindBox->setMaxLength(6);
	editBindBox->setTag(9999);
	bk1->addChild(editBindBox);

	//��֤�밴ť 
	auto btnGetValidate = ui::Button::create("my_lottery_34_1.png","my_lottery_34_2.png","my_lottery_34_3.png");
	btnGetValidate->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	btnGetValidate->addClickEventListener([=](Ref* ){
		if(btnGetValidate->isEnabled())
		{
			startTimer();
		}
	});
	btnGetValidate->setTag(9527);
	btnGetValidate->setPosition(Vec2(posX1 * 11 / 8, nYPos));
	bk1->addChild(btnGetValidate);	

	//����ʱ��Ļ
	auto lbTimer = LabelTTF::create();
	lbTimer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	lbTimer->setPosition(btnGetValidate->getContentSize() / 2);
	lbTimer->setTag(9528);
	btnGetValidate->addChild(lbTimer);
	lbTimer->setFontName("");
	lbTimer->setFontSize(22);
	lbTimer->setString(ConfigMgr::instance()->text("display_text.xml","t5030"));
	lbTimer->setFontFillColor(Color3B::WHITE);
	lbTimer->setVisible(false);

	//ȡ��
	auto btnCancel = ui::Button::create("beting24.png","beting25.png","beting24.png");
	btnCancel->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	btnCancel->addClickEventListener(CC_CALLBACK_1(ValidateLayer::close,this));
	btnCancel->setPosition(Vec2(posX1 * 9 / 16, nYPos / 2));
	bk1->addChild(btnCancel);

	//ȷ��
	auto btnOK = ui::Button::create("beting22.png","beting23.png","beting22.png");
	btnOK->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	btnOK->addClickEventListener(CC_CALLBACK_1(ValidateLayer::confirm,this));
	btnOK->setPosition(Vec2(posX1 * 23 / 16, nYPos / 2));
	bk1->addChild(btnOK);	
}

void ValidateLayer::show(const char* phoneNumber,const int iShowType /* = 0 */)
{
	//���ƴ򿪵�Ψһ��
	if (m_isShow) return;m_isShow = true;

	ValidateLayer* _instance = ValidateLayer::create();
	_instance->setShowType(phoneNumber,iShowType);
	Director::getInstance()->getRunningScene()->addChild(_instance,255);
}

void ValidateLayer::setShowType(const char* phoneNumber,const int showType)
{
	iType = showType;
	m_phoneNumber.clear();
	m_phoneNumber.append(phoneNumber);
}

void ValidateLayer::close(Object* obj)
{
	playButtonSound();
	m_isShow = false;
	m_isValidating = false;

	NotificationCenter::getInstance()->postNotification("Validated",Integer::create(-1));

	this->removeFromParentAndCleanup(true);
}

void ValidateLayer::confirm(Object* obj)
{
	playButtonSound();

	//�ҵ���֤��
	auto layer = (LayerColor *)this->getChildByTag(1234);
	if(layer == nullptr) return;
	auto bk = (Sprite *)layer->getChildByTag(1235);
	if(bk == nullptr) return;
	auto dtCode = (EditBox *)bk->getChildByTag(9999);
	if(dtCode == nullptr) return;

	if(strlen(dtCode->getText()) != 6)
	{
		MovingLabelLayer* layer= MovingLabelLayer::MovingLabelLayerWith(ConfigMgr::instance()->text("display_text.xml","t5050"),Vec2(SCREEN_WIDTH / 2,425));
		this->addChild(layer,255);
		return;
	}

	if(iType == 1 || iType == 2)
	{		
		std::string codeStr = UserDefault::getInstance()->getStringForKey("VALIDATECODE","aaaaaa");
		if(codeStr.compare(dtCode->getText()) == 0)
		{			
			//�ȷ���Ϣ����Ȼ����ָ��Ϊ����
			NotificationCenter::getInstance()->postNotification("Validated",Integer::create(iType));
			//��֤�ɹ�	
			this->removeFromParentAndCleanup(true);
			m_isShow = false;
			m_isValidating = false;
		}else
		{
			MovingLabelLayer* layer= MovingLabelLayer::MovingLabelLayerWith(ConfigMgr::instance()->text("display_text.xml","t5050"),Vec2(SCREEN_WIDTH / 2,425));
			this->addChild(layer,255);			
		}
	}else
	{
		//���ͻ�ȡ��֤��Ľӿ�
		EntityMgr::instance()->getDispatch()->SendPacketWithValidateYanZhengMa(dtCode->getText(),iType);
	}

	
}

void ValidateLayer::validateCodeReback(Object *obj)
{
	Dictionary* data = (Dictionary* )obj;
	if(data == nullptr) return;

	Integer* nResult = (Integer *)data->objectForKey("nResult");
	String* sDesc = (String *)data->objectForKey("sDesc");

	if(nResult->getValue() == 0)
	{		
		//�ȷ���Ϣ����Ȼ����ָ��Ϊ����
		NotificationCenter::getInstance()->postNotification("Validated",Integer::create(iType));
		//��֤�ɹ�	
		this->removeFromParentAndCleanup(true);
		m_isShow = false;
		m_isValidating = false;
	}else
	{
		//��֤ʧ��
		MovingLabelLayer* layer= MovingLabelLayer::MovingLabelLayerWith(sDesc->getCString(),Vec2(SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2));
		this->addChild(layer,255);
		//��ԭ��ʱ
		stopTimer();
	}
}

void ValidateLayer::sendHttpRequest()
{	
	//�������
	timeval psv;	
	gettimeofday(&psv, NULL);
	unsigned long int rand_seed = psv.tv_sec*1000+psv.tv_usec;
	srand(rand_seed);
	//������֤�� �����ĸ���Ч���� �п�����3��0 ������С����
	int tempNum = (rand() % 1000) * 1000 + rand() % 1000;
	String* codeStr = String::createWithFormat("%06d",tempNum);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	CCLOG("code: %s", codeStr->getCString());
#endif // DEBUG	

	//������֤���������
	if(iType == 1 || iType == 2)//�󶨵�ʱ�򲻷���
	{
		UserDefault::getInstance()->setStringForKey("VALIDATECODE",codeStr->getCString());
	}else
	{
		EntityMgr::instance()->getDispatch()->SendPacketWithSendYanZhengMa(codeStr->getCString(),iType);
	}

	/*1	name	����������û��˺�
		2	pwd	�������������½webƽ̨�����������еĽӿ����룩
		3	content	����������������ݣ�1-500 �����֣�����300�ַ��ڣ�UTF-8����
		4	mobile	����������ֻ����롣�����Ӣ�Ķ��Ÿ���
		5	stime	��ѡ������������ʱ�䣬��дʱ����д��ʱ�䷢�ͣ�����ʱΪ��ǰʱ�䷢�ͣ��뵽��
		6	sign	����������û�ǩ������������ϵ���۽��к�̨�󶨣�
		7	type	����������̶�ֵ pt
		8	extno	��ѡ����������չ�룬�û�������չ�룬ֻ��Ϊ���֣�����Ҫ��չ��ͬǩ������Ҫ����չ�ĺ���Ͷ�Ӧ��ǩ�������ͷ���
		*/

	//CCLOG("rand()---> %d",tempNum);

	String* urlStr = String::create(ConfigMgr::instance()->text("display_config.xml","t5041"));
	String* nameStr = String::create("caifu000111222");
	String* pwdStr = String::create("DBA9C1688034B26F772E5BAFBBA5"); //��ȷ��
	//String* pwdStr = String::create("DBA9C1688034B26F772E5BAFBBA1");//����ģ�ֻ��Ϊ�˲���
	String* contentStr = String::createWithFormat("%s%s%s",
		ConfigMgr::instance()->text("display_config.xml",String::createWithFormat("t%d",5043 + iType)->getCString()),  //�ı�����
		codeStr->getCString(),
		ConfigMgr::instance()->text("display_config.xml","t5042"));
	String* mobileStr = String::create(m_phoneNumber);
	String* signStr = String::create(ConfigMgr::instance()->text("display_config.xml","t5040"));
	
	//��Ӳ���
	String* urlDataStr = String::createWithFormat("name=%s&pwd=%s&content=%s&mobile=%s&stime=&sign=%s&type=pt&extno=",nameStr->getCString(),pwdStr->getCString(),contentStr->getCString(),mobileStr->getCString(),signStr->getCString());
	//CCLOG("%s", urlStr->getCString());
	//��������
	network::HttpRequest* request = new network::HttpRequest();
	request->setUrl(urlStr->getCString());
	request->setRequestData(urlDataStr->getCString(),urlDataStr->length());
	request->setRequestType(network::HttpRequest::Type::POST); 
	request->setResponseCallback(this, callfuncND_selector(ValidateLayer::onHttpRequestCompleted));
	request->setTag("Post validate code");		
	network::HttpClient::getInstance()->send(request); 
	network::HttpClient::getInstance()->setTimeoutForConnect(10);
	network::HttpClient::getInstance()->setTimeoutForRead(10);
	request->release();
}

void ValidateLayer::onHttpRequestCompleted(Node *sender, void *data)  
{  
	network::HttpResponse *response = (network::HttpResponse*)data;  

	//�յ�����ֵ�ˣ�����Ϊʲô�������ô˱��
	m_isValidating = false;

	if (!response)  
	{  
		return;  
	}  

	int statusCode = response->getResponseCode();  
	char statusString[64] = {};  
	sprintf(statusString, "HTTP Status Code: %d, tag = %s", statusCode, response->getHttpRequest()->getTag());  

	if (!response->isSucceed())   
	{  
		return;  
	}  

	// dump data  
	std::vector<char> *buffer = response->getResponseData();
	if(buffer->size() < 3)
	{		
		return;
	}
	std::string temp(buffer->begin(),buffer->end());
	//std::string temp(buffer->begin(),buffer->end());
	String* responseData=String::create(temp);	

	//�����ַ���
	Array* tempArr = responseData->componentsSeparatedByString(",");
	if(tempArr->count() > 0)
	{
		String* tempStr = (String* )tempArr->getObjectAtIndex(0);
		int tempInt = atoi(tempStr->getCString());

		//�ҵ���ʾ��
		auto layer = (LayerColor *)this->getChildByTag(1234);
		if(layer == nullptr) return;
		auto bk = (Sprite *)layer->getChildByTag(1235);
		if(bk == nullptr) return;
		auto lbTips = (LabelTTF *)bk->getChildByTag(2222);
		if(lbTips == nullptr) return;

		switch (tempInt)
		{
		case -1:
			lbTips->setString(ConfigMgr::instance()->text("display_text.xml","t5011"));
			stopTimer();
			break;
		case 0:
			//��ʾ�ѷ��͵��ֻ�
			lbTips->setString(ConfigMgr::instance()->text("display_text.xml","t5000"));
			break;
		case 1:	case 2:	case 3:	case 4:	case 10: case 11: case 12: case 13:	case 14:
			lbTips->setString(ConfigMgr::instance()->text("display_text.xml","t5013"));	
			stopTimer();
			break;
		default://����10��
			lbTips->setString(ConfigMgr::instance()->text("display_text.xml","t5012"));	
			stopTimer();
			break;
		}
	}	
} 
//
//  BaseLayer.cpp
//  Game
//
//  Created by ���� on 13-6-19.
//  Modify by hd
//

#include "BaseLayer.h"
#include "GBEventIDs.h"
#include "MovingLabelLayer.h"
#include "ConfigMgr.h"
#include "Define.h"
#include "LoginLayer.h"

BaseLayer::BaseLayer()
{
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(BaseLayer::CloseNetWorkShut), MSG_UI_ANS_LS_NETWORKSHUT, NULL);
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(BaseLayer::ReConNetWork), MSG_UI_ANS_NETWORK_RECON, NULL);
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(BaseLayer::ReadyToConNet), MSG_UI_ANS_NETWORK_RECON_ING, NULL);
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(BaseLayer::getSystemTimeObject), "GetSystemTimeRet", NULL);
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(BaseLayer::backToLogin), "BackToLogin",NULL);
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(BaseLayer::changeNet), "NetWorkChange",NULL);
}
BaseLayer::~BaseLayer()
{
	NotificationCenter::getInstance()->removeObserver(this, MSG_UI_ANS_LS_NETWORKSHUT);
	NotificationCenter::getInstance()->removeObserver(this, MSG_UI_ANS_NETWORK_RECON);
	NotificationCenter::getInstance()->removeObserver(this, MSG_UI_ANS_NETWORK_RECON_ING);
	NotificationCenter::getInstance()->removeObserver(this, "GetSystemTimeRet");
	NotificationCenter::getInstance()->removeObserver(this, "BackToLogin");
	NotificationCenter::getInstance()->removeObserver(this, "NetWorkChange");
}

bool BaseLayer::init()
{
	if(!Layer::init())
	{
		return false;
	}

	return true;
}

void  BaseLayer::CloseNetWorkShut(Object *obj)
{
	MovingLabelLayer* layer = MovingLabelLayer::MovingLabelLayerWith(ConfigMgr::instance()->text("display_DuangDong.xml","t180"),
		Vec2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f));
	Director::getInstance()->getRunningScene()->addChild(layer, 255);
}

void  BaseLayer::ReConNetWork(Object *obj)
{
	//ˢ�½���
	refreshLayer();
	//����
	EntityMgr::instance()->getDispatch()->resetConTimes();
	//Ϊ0����Ҫ����ʾ��
	Integer* tempInt = (Integer *)obj;
	if (tempInt->getValue() == 0|| tempInt->getValue() == 1) return;
	//������ʾ
	MovingLabelLayer* layer = MovingLabelLayer::MovingLabelLayerWith(ConfigMgr::instance()->text("display_DuangDong.xml","t1000"),
		Vec2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f));
	Director::getInstance()->getRunningScene()->addChild(layer, 255);
}

void BaseLayer::getSystemTimeObject(Object *obj)
{
	EntityMgr::instance()->getDispatch()->resetConTimes();
}

void BaseLayer::ReadyToConNet(Object *obj)
{
	MovingLabelLayer* layer = MovingLabelLayer::MovingLabelLayerWith(ConfigMgr::instance()->text("display_DuangDong.xml","t1001"),
		Vec2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f));
	Director::getInstance()->getRunningScene()->addChild(layer, 255);
}

void BaseLayer::backToLogin(Object *obj)
{
	LoginLayer *loginLayer = LoginLayer::create();
	Scene* pScene = Scene::create();
	pScene->addChild(loginLayer);
	TransitionFade *tScene = TransitionFade::create(0.5f, pScene, Color3B::WHITE);
	Director::getInstance()->replaceScene(tScene);	

	//1Ϊ���粻�ȶ�
	Integer* tempInt = (Integer *)obj;
	if(tempInt->getValue())
	{
		MovingLabelLayer* layer = MovingLabelLayer::MovingLabelLayerWith(ConfigMgr::instance()->text("display_DuangDong.xml","t1003"),
			Vec2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f));
		loginLayer->addChild(layer, 255);	
	} else
	{	
		MovingLabelLayer* layer = MovingLabelLayer::MovingLabelLayerWith(ConfigMgr::instance()->text("display_DuangDong.xml","t1002"),
			Vec2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f));
		loginLayer->addChild(layer, 255);
	}
}

void BaseLayer::changeNet(Object *obj)
{
	MovingLabelLayer* layer = MovingLabelLayer::MovingLabelLayerWith(ConfigMgr::instance()->text("display_DuangDong.xml","t1004"),
		Vec2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f));
	Director::getInstance()->getRunningScene()->addChild(layer, 255);
}
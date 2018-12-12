#pragma once
#ifndef __MY_SCENE_PLAZA_H__
#define __MY_SCENE_PLAZA_H__

#include "cocos2d.h"
#include "ui/UIWidget.h"
#include "ui/UICheckBox.h"

using namespace cocos2d;
//using namespace cocos2d::ui;
class ScenePlaza : public cocos2d::Layer
{
public:
	static ScenePlaza* s_pScenePlaza;
	static CCSprite* FanliLayer;
	static std::vector<int> 					JoinRoomNumber;
	static std::vector<CCSprite*> 			    JoinRoomNumberSprite;
	static int MyOutCardCount;
	static int RightOutCardCount;
	static int UpOutCardCount;
	static int LeftOutCardCount;
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	void update(float l);
	CREATE_FUNC(ScenePlaza);	
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	void menuCloseCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type, CCSprite* Layer);//�رհ�ť�ص�
	void menuOnlyCloseCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type, CCSprite* Layer);//ֻ�رս���
	void menuShezhiCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type, CCSprite* Layer);//���ð�ť�ص�
	void menuNumberCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type, CCSprite* Layer);//���뷿�����뷿��Ű�ť�Ļص�
	void menuFKSXCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type,int tag);//����ˢ�°�ť�ص�
	void menuToMilitary(Ref * pSender, cocos2d::ui::Widget::TouchEventType type);
	void menuExplain(Ref * pSender, cocos2d::ui::Widget::TouchEventType type);
	void setCloseLayer();
	void setFankuiLayer();
	void setShezhiLayer();
	void setKefuLayer();
	void setFangkaLayer();
	void setShengmingLayer();
	void setHeadLayer();
	void setWanfaLayer();
	void setCreateRoom();
	void setJoinRoom();
	void CreateRoom(Ref * pSender, cocos2d::ui::Widget::TouchEventType type);
	void SelectWanfa(Ref* pSender, cocos2d::ui::Widget::TouchEventType type, ui::CheckBox* btn1, ui::CheckBox* btn2);//������
	void SelectMoshi(Ref* pSender, cocos2d::ui::Widget::TouchEventType type, ui::CheckBox* btn1, ui::CheckBox* btn2);//��������
	void Selectfenorju(Ref* pSender, cocos2d::ui::Widget::TouchEventType type, ui::CheckBox* btn1, ui::CheckBox* btn2);//����������
	void AfterCapture(CCRenderTexture* pScreen, const std::string& fileName);
	void DongDaiZhuang(signed int tag);
	void OnGetBullet(const std::string& strBullet);
	void OnGuiXiMaJiang();
	void OnHowOpenRoom();
	void ReflashRoomCard();
private:
	bool m_isBulletinBoard;
	bool	  isMusicOpen;
	bool	  isVoiceOpen;
	bool m_isAfterCaptureing;
	ui::Widget*   ScenePlazaRoot;
};

#endif // __MY_SCENE_PLAZA_H__

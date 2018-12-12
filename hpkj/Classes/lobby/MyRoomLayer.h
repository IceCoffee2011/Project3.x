#pragma once
#ifndef __MY_ROOM_LAYER_H__
#define __MY_ROOM_LAYER_H__

#include "cocos2d.h"
#include "ui/UIWidget.h"
#include "ui/UICheckBox.h"

using namespace cocos2d;
//using namespace cocos2d::ui;
class MyRoomLayer : public cocos2d::Layer
{
public:
    static MyRoomLayer* s_pMyRoomLayer;
	static CCSprite* FanliLayer;
	static std::vector<int> 					JoinRoomNumber;
	static std::vector<CCSprite*> 			    JoinRoomNumberSprite;
	static int MyOutCardCount;
	static int RightOutCardCount;
	static int UpOutCardCount;
	static int LeftOutCardCount;
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	CREATE_FUNC(MyRoomLayer);
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
    void update(float l);
	void menuCloseCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type, CCSprite* Layer);//�رհ�ť�ص�
	void menuOnlyCloseCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type, CCSprite* Layer);//ֻ�رս���
	void menuShezhiCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type, CCSprite* Layer);//���ð�ť�ص�
	void menuNumberCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type, CCSprite* Layer);//���뷿�����뷿��Ű�ť�Ļص�
	void menuFKSXCallBack(Ref * pSender, cocos2d::ui::Widget::TouchEventType type);//����ˢ�°�ť�ص�
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
	bool	      isMusicOpen;
	bool	      isVoiceOpen;
	bool          m_isBulletinBoard;
	bool          m_isAfterCaptureing;
	ui::Widget*   MyRoomLayerRoot;
};

#endif // __MY_ROOM_LAYER_H__

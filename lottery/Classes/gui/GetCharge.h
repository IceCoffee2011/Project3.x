//
//  GetCharge.h
//  Game
//
//  Created by ���� on 13-8-6.
//
//

#ifndef __Game__GetCharge__
#define __Game__GetCharge__

#include "cocos2d.h"
#include "CocosUnits.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class GetCharge : public Layer
{
public:
    static GetCharge * GetChargeWith(Vec2 pos);
    bool initGetCharge(Vec2 pos);
    GetCharge();
    ~GetCharge();
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
    virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
    virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
    virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);
    void getCharge(Object* obj);
    void getCoins(Object* obj);
    void getQB(Object * obj);
    void getTips(Object* obj);
	bool isLegal(std::string str);
	void doget(Object* obj);
	void showLingHuaFei();
	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);					//�ֻ����ذ�ť
public:
    void closeGetCharge(Object * obj);
    int currentSelct;                    //�����ȡʱ��ǰ��ȡ������
    
    
    Menu* m_pBackMenu;            //����
    Menu* m_pGetMenu;             //��ȡ��ť
    Menu* m_pDogetMenu;           //������ȡ��ť
    Menu* m_pGetTips;             //��׬����
    
    EditBox* m_pInputBox1;
    EditBox* m_pInputBox2;
    bool m_bBackMenu;
    bool m_bGetMenu;
    bool m_bInputBox1;
    bool m_bInputBox2;
    bool m_bDogetMenu;
    bool m_bGetTips;
    
private:
    bool m_bEnoughGet;
    LabelTTF* m_pTips11;          //�컰��
    Sprite* m_pTips12;
    Sprite* m_pTips13;
	LabelTTF* m_pTips14;

    
    LabelTTF* m_pTips21;          //��QB
    Sprite* m_pTips22;
    Sprite* m_pTips23;
	LabelTTF* m_pTips24;
    
    LabelTTF* m_pTips31;          //����
    //LabelTTF* m_pTips32;
	LabelTTF* m_pTips34;

private:
    MenuItemSprite* getchargeItemSprite;
    MenuItemSprite* getcoinsItemSprite;
    MenuItemSprite* getQBItemSprite;
    MenuItemSprite* getTipsItemSprite;
};

#endif /* defined(__Game__GetCharge__) */

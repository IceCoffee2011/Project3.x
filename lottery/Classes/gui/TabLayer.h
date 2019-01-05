#ifndef __Game__TabLayer__
#define __Game__TabLayer__

#include "CocosUnits.h"
#include "ConfigMgr.h"
#include "AnsString.h"
#include <iostream>
#include <string>
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;

#define TabLayerBaseTag  1

class TabLayer : public Layer
{
protected:
	int currentItem;				//���ڱ��tab�ĵ�ǰҳ Ĭ��Ϊ��һҳ0
	Sprite * pBJ;					//����ͼƬ
	Sprite *maskSprite;			//����ͼƬ
private:
	float tabMenuWidth;				//tab��ǩ���
	Menu* tabMenu;				//��ǩ��ť
	int tabNum;						//��ǩ����
	float itemGap;
	Vector<MenuItem*> tabMenuItem;			//��ǩ�Ӳ˵�
	Array *normalName;			//��ǩ����
	Array *selectedName;
public:
	TabLayer();
	~TabLayer();
	static TabLayer *createWithTabItems(Array *itemNormalName, Array *itemSelectedName);
	bool initWithTabItems(Array *itemNormalName, Array *itemSelectedName);
	void setTabMenuPositionY(float yPos){tabMenu->setPositionY(yPos);};
	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);					//�ֻ����ذ�ť
public:
	void dismiss(Object *obj);
	void pressTabButton(Object *obj);
	virtual void doSomething();
	virtual void doSomethingBeforeClosed(){};
};
#endif  //__Game__WarningLayler__
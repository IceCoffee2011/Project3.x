#ifndef __Game__ActivityLayer__
#define __Game__ActivityLayer__
#include "CocosUnits.h"
#include "ConfigMgr.h"
#include "AnsString.h"
#include <iostream>
#include "cocos2d.h"
class ActivityLayer : public Layer
{

public:
	ActivityLayer();
	~ActivityLayer();
	virtual bool init();
	static Scene* scene();
	CREATE_FUNC(ActivityLayer);

	void changeActivity(int type);

	void leftActivity(Object* obj);
	void rightActivity(Object* obj);

	void enterActivity(Object* obj);

public:
	
	void dismiss(Object *obj);
	void toFreeLayer(Object* obj);

	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);					//�ֻ����ذ�ť

private:
	Sprite* m_pUpArrow;			//ָ������ļ�ͷ
	Sprite* m_pWhiteBox;			//�׿�
	Array* m_ActivitySpriteArray;	//�ͼƬ
	float m_cDistanceSize;
	int m_nSelectActivity;
	cocos2d::Size winSize;
	Array* m_ActivityContextArray;//�����
	LabelTTF* activityTips;

	Menu* m_EnterMenu;
};
#endif  //__Game__HelpLayer__
#ifndef __Game__MenuLayler__
#define __Game__MenuLayler__

#include "CocosUnits.h"
#include "ConfigMgr.h"
#include "AnsString.h"
#include <iostream>
#include "cocos2d.h"

#include "RegistLayer.h"
class MenuLayer : public Layer
{
private:
	MenuItemSprite *musicItem;
	MenuItemSprite *effectItem;
	bool hasEffect;
	bool hasMusic;
public:
	Menu *pButtonMenu;
public:
	MenuLayer();
	~MenuLayer();
	virtual bool init();
	static Scene* scene();

	CREATE_FUNC(MenuLayer);

public:
	void permitButtonClick();							//����ť��
	void forbidButtonClick();							//��ֹ��ť��
	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);					//�ֻ����ذ�ť
	void pressMusicItem(Object* obj);					//��Ϸ��������
	void pressEffectItem(Object* obj);					//��Ϸ��������
};
#endif  //__Game__MenuLayler__
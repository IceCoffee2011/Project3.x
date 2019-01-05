#ifndef __Game__WarningLayler__
#define __Game__WarningLayler__

#include "CocosUnits.h"
#include "ConfigMgr.h"
#include "AnsString.h"
#include "PromptBox.h"
#include <iostream>
#include "cocos2d.h"

class WarningLayer : public Layer
{
private:
	cocos2d::Size winSize;
	int signInDays;
	Sprite *signInImage;
	Array *awardImage;
	Menu *signInMenu;
	PromptBox* promptBox;
	bool cancelOrNot;
private:
	/**�����Ƿ���������**/

public:
	WarningLayer();
	~WarningLayer();
	virtual bool init();
	static Scene* scene();
	CREATE_FUNC(WarningLayer);
	void setSignInDays(int days);
	void requestSignInDays();					//��ҳ��ѯǩ������
	void signIn();								//ǩ��
	void cancelHttpRequest(Object *obj);
	void onHttpRequestCompleted(Node *sender, void *data);//��ѯǩ�������ص�
	void onSignInCompleted(Node *sender, void *data);//ǩ���ص�
	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);					//�ֻ����ذ�ť
public:
	void dismiss(Object *obj);
	void onGetTaskAward(Object* obj);
};
#endif  //__Game__WarningLayler__
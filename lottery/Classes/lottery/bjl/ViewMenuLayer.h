//  [3/26/2014 xieyi]
#ifndef		__VIEW_MENU_LAYER__
#define		__VIEW_MENU_LAYER__
#include "cocos2d.h"
#include "BJLRes.h"
#include "SceneData.h"
#include "MyTimer.h"
USING_NS_CC;

class ViewMenuLayer : public Layer
{
public:
	CREATE_FUNC(ViewMenuLayer);
	virtual bool init();
	ViewMenuLayer();
	~ViewMenuLayer();
	bool m_isVisibleStart;	//�Ƿ����ƿ�ʼ
	void setTimer(int userId,Game_State gameState,int t,bool visible,int key);

	void closeTimer();
	void SetTimeSprite();

	//virtual void keyBackClicked(void);				//����
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void setMenuNameTipsView(bool isVisible);
private:
								//��Ӱ�ť��
	void addMenuBarItem(const char * normal,const char * selected,const char * disable,
		Object * context,SEL_MenuHandler selector,Vec2 point,
		Object * pUserObject, int tag,bool visible);
	//Sprite* addMenuBarTips(const char * name,float delTime,Vec2 pt);
	void removeSelfCall(Node* _node);
private:
	CC_SYNTHESIZE(Menu *,m_menu,Menu);								//��ť
	Menu * m_menuBar;			//�˵���
	Node * m_menuBarNode;		//�˵����ڵ�
	Node*  m_menuBarTips;
	bool m_menuBarIsShow;		//�˵����Ƿ���ʾ
	CC_SYNTHESIZE(MyTimer*,m_timer,MyTimer);			//��ʱ��
	float m_menuPositionY;
	bool m_isAutoHints;		//�Ƿ��Զ�����
};

#endif
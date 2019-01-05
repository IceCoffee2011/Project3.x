//  [3/26/2014 xieyi]
#ifndef	DDZ___VIEW_MENU_LAYER__
#define	DDZ___VIEW_MENU_LAYER__
#include "cocos2d.h"
#include "DDZDDZRes.h"
#include "DDZSceneData.h"
#include "DDZTimer.h"
#include "ui/CocosGUI.h"
#include "DDZDialogLayer.h"

USING_NS_CC;
using namespace ui;


class DDZViewMenuLayer : public Layer
{
public:
	DDZViewMenuLayer();
	~DDZViewMenuLayer();
	CREATE_FUNC(DDZViewMenuLayer);
	virtual bool init();
	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);

	void enterGameView();		//����Ծֽ���
	void startGame();		//��ʼ��Ϸ
	void visibleCard();		//����
	void jiaoDiZhu();		//�е���
	void qiangDiZhu();		//������
	void outCard(int state);			//����
	void jiaBei(bool isShow);			//�ӱ�
	void firstOutCard();	//��һ�ֳ���
	void diZhuFirstOutCard();	//������һ�ֳ���
	void gameDDZSettlement();	//��Ϸ����
	void finishClick();		//��ɰ�ť����¼�(���ذ�ť)
	void setVisibleStartNumber(int num);	//�������ƿ�ʼ����
	void setTimer(int userId,DDZGame_State gameState,int t,bool visible,int key);
	void closeTimer();
	void hintVisibleCardItem();		//��������x2��ť
	void setRobotEnable(bool enable);//���û������Ƿ����
	void setTalkEnable(bool enable);//���������Ƿ����

	bool isShowBtns();//�Ƿ�չʾ������ذ�ť

	//	���ð�ť�˵����Ƿ���ʾ
	void setMenuItemVisible(DDZMenuItemType type, bool isVisible);

	bool m_isVisibleStart;	//�Ƿ����ƿ�ʼ
private:
	//�˵���ť�ص�
	void menuCallback(Object * pSender);			

	//��Ӱ�ť��
	MenuItemSprite* addMenuItem(const char * normal,const char * selected,const char * disable,
		Object * context,SEL_MenuHandler selector,Vec2 point,
		Object * pUserObject, int tag,bool visible);

	MenuItemSprite* addMenuBarItem(const char * normal,const char * selected,const char * disable,
		Object * context,SEL_MenuHandler selector,Vec2 point,
		Object * pUserObject, int tag,bool visible);

	//	����˵�������
	void onClickPullTab(Ref* sender);

	//	�������
	void onClickBack(Ref* sender);

	//	�������
	void onClickSetting(Ref* sender);

private:
	CC_SYNTHESIZE(Menu *,m_menu,Menu);					//	��ť
	CC_SYNTHESIZE(DDZTimer*,m_timer,DDZTimer);			//	��ʱ��
	Menu* m_menuBar;									//	�˵���
	float m_menuPositionY;								//	��ťλ��Y����
	Sprite* m_pMenuBG;									//	�˵�������
	Button* m_pPullTab;									//	�˵�������
	bool m_bIsShowMenu;									//	�Ƿ���ʾ�˵���
	MenuItemSprite* m_pMenuItem[DDZmenu_Count];			//	�˵�������
};

#endif
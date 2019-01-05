#ifndef _ACCOUNT_LAYER_H_
#define _ACCOUNT_LAYER_H_
#include "cocos2d.h"
#include "cocos/ui/CocosGUI.h"
#include "CMD_Fish.h"

enum Button_Type
{
	TYPE_EXIT,
	TYPE_CANCLE
};
class AccountLayer : public cocos2d::Layer
{
public:
	AccountLayer(void);
	~AccountLayer(void);
	virtual bool init();
	CREATE_FUNC(AccountLayer);
public:
	void setAccountLayerInfo(NS_lrbyFish::CMD_S_FireHarvest* fishHarvest);
	void OnBtnCallBack(cocos2d::Ref* sender,cocos2d::ui::TouchEventType type);
private:
	//��ť
	cocos2d::ui::Widget*    uiWidget;
	cocos2d::ui::Button*	m_btnExit;	//���㲢�˳�
	cocos2d::ui::Button*	m_btnCancel;//ȡ��
	cocos2d::ui::Text*		m_txtFish[24];//�������
	
};

#endif //_ACCOUNT_LAYER_H_

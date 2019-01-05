#ifndef __DZPK_DIALOG_H__
#define __DZPK_DIALOG_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

//	�Ի��򡪡�����
class DialogBase: public Layer
{
public:
	DialogBase();
	~DialogBase();
	virtual bool init();
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

	//	�رնԻ���
	virtual void closed();
private:

protected:
	//	���Ӵ��ڳߴ�
	 cocos2d::Size m_sVSize;

};

//	�Ի��򡪡�ʤ�����
class DialogEnding: public DialogBase
{
public:
	DialogEnding();
	~DialogEnding();
	enum EndingType
	{
		EndingType_Win = 0,	//	ʤ
		EndingType_Lose,	//	��
		EndingType_Draw		//	��
	};

	static DialogEnding* create(EndingType eType);
	bool init(EndingType eType);

	void initUI(EndingType eType);
private:

};

//	�Ի��򡪡��˳���Ϸ
class DialogQuit: public DialogBase
{
public:
	DialogQuit();
	~DialogQuit();
	CREATE_FUNC(DialogQuit);
	bool init();
	void initUI();
private:

};

//	�Ի��򡪡���ʱ�˳�
class DialogTimeOutQuit: public DialogBase
{
public:
	DialogTimeOutQuit();
	~DialogTimeOutQuit();
	CREATE_FUNC(DialogTimeOutQuit);
	bool init();
	void initUI();
private:
	//	����
	Sprite* m_pBG;

	//	��ť����ȷ��
	ui::Button* m_pBtnOK;

	//	���ȷ����ť
	void onClickBtnOK(Ref* sender);
};




#endif	//	__DZPK_DIALOG_H__
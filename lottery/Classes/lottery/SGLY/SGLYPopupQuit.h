#ifndef __SGLY_POPUP_QUIT_H__
#define __SGLY_POPUP_QUIT_H__

#include "cocos2d.h"
#include "BaseDialog.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

/*
**	@brief	����ţţ�����˳�����
*/
class SGLYPopupQuit: public BaseDialog
{
public:
	SGLYPopupQuit();
	~SGLYPopupQuit();
	CREATE_FUNC(SGLYPopupQuit);
private:
	bool init();
	void initUI();

	//	���ȷ����ť
	void onClickBtnOK(Ref* pSender);

	//	���ȡ����ť
	void onClickBtnNO(Ref* pSender);

	//	����
	Sprite* m_pBG;

	//	��ʾ��
	Label* m_pLabTips;

	//	��ť����ȷ��
	Button* m_pBtnOK;

	//	��ť����ȡ��
	Button* m_pBtnNO;

};


#endif  // __SGLY_POPUP_QUIT_H__
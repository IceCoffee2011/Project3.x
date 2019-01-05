#ifndef __BRNN_DIALOG_QUIT_H__
#define __BRNN_DIALOG_QUIT_H__

#include "cocos2d.h"
#include "BaseDialog.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

/*
**	@brief	����ţţ�����˳�����
*/
class BRNNDialogQuit: public BaseDialog
{
public:
	BRNNDialogQuit();
	~BRNNDialogQuit();
	CREATE_FUNC(BRNNDialogQuit);
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


#endif  // __BRNN_DIALOG_QUIT_H__
#ifndef __PPC_DIALOG_QUIT_H__
#define __PPC_DIALOG_QUIT_H__

#include "cocos2d.h"
#include "BaseDialog.h"
#include "ui/CocosGUI.h"
#include "PPCEnum.h"
#include "PPCRes.h"

USING_NS_CC;
using namespace ui;

//	�����������˳�����
class PPCDialogQuit: public BaseDialog
{
public:
	PPCDialogQuit();
	~PPCDialogQuit();
	CREATE_FUNC(PPCDialogQuit);
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


#endif  // __PPC_DIALOG_QUIT_H__
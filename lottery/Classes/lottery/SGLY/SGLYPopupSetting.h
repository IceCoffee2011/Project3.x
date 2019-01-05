#ifndef __SGLY_POPUP_SETTING_H__
#define __SGLY_POPUP_SETTING_H__

#include "cocos2d.h"
#include "BaseDialog.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace std;

/*
**	@brief	ˮ����԰�������ý���
*/
class SGLYPopupSetting: public BaseDialog
{
public:
	SGLYPopupSetting();
	~SGLYPopupSetting();
	CREATE_FUNC(SGLYPopupSetting);

private:
	bool init();
	void initUI();

	//	������ָ�ѡ���¼�
	void onCBMusicEvent(Ref* pSender,CheckBox::EventType type);

	//	�����Ч��ѡ���¼�
	void onCBSoundEffectEvent(Ref* pSender,CheckBox::EventType type);

	//	���ȷ����ť�¼�
	void onClickBtnOKEvent();

	//	���ȡ����ť�¼�
	void onClickBtnNOEvent();

	//	����
	Sprite* m_pBG;

	//	�ı���������
	Sprite* m_pTextSetting;

	//	�ı���������
	Sprite* m_pTextMusic;

	//	�ı�������Ч
	Sprite* m_pTextSoundEffect;

	//	��ѡ�򡪡�����
	CheckBox* m_pCheckBoxMusic;

	//	��ѡ�򡪡���Ч
	CheckBox* m_pCheckBoxSoundEffect;

	//	��ť����ȷ��
	Button* m_pBtnOK;

	//	��ť����ȡ��
	Button* m_pBtnNO;

	//	�Ƿ񿪱�������
	bool m_bOnMusic;

	//	�Ƿ���Ч
	bool m_bOnSoundEffect;

};


#endif  // __SGLY_POPUP_SETTING_H__
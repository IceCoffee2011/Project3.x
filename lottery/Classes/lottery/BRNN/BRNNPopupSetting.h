#ifndef __BRNN_POPUP_SETTING_H__
#define __BRNN_POPUP_SETTING_H__

#include "cocos2d.h"
#include "BaseDialog.h"
#include "cocos-ext.h"

USING_NS_CC;

/*
**	@brief	����ţţ�������ý���
*/
class BRNNPopupSetting: public Layer
{
public:
	BRNNPopupSetting();
	~BRNNPopupSetting();
	CREATE_FUNC(BRNNPopupSetting);

	//	�������ý����Ƿ���ʾ
	void setPopupSettingVisible(bool bIsVisible);
private:
	bool init();
	void initUI();

	//	���ֿ��ذ�ť�¼�
	void onControlMusicChange(Ref* sender, extension::Control::EventType controlEvent);

	//	��Ч���ذ�ť�¼�
	void onControlSoundEffectChange(Ref* sender, extension::Control::EventType controlEvent);

	//	���㴥���¼�������ʼ
	bool onTouchBegan(Touch *touch, Event *unused_event);

	//	���㴥���¼������ƶ�
	void onTouchMoved(Touch *touch, Event *unused_event);

	//	���㴥���¼�����ȡ��
	void onTouchCancelled(Touch *touch, Event *unused_event);

	//	���㴥���¼���������
	void onTouchEnded(Touch *touch, Event *unused_event);

	//	����
	Sprite* m_pBG;

	//	���ذ�ť��������
	extension::ControlSwitch* m_pControlMusic;

	//	���ذ�ť������Ч
	extension::ControlSwitch* m_pControlSoundEffect;
};


#endif  // __BRNN_POPUP_SETTING_H__
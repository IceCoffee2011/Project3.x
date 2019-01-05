#ifndef __BASE_DIALOG_H__
#define __BASE_DIALOG_H__

#include "cocos2d.h"

USING_NS_CC;

//	�Ի��򡪡�����
class BaseDialog: public Layer
{
public:
	BaseDialog();
	virtual ~BaseDialog();
	virtual bool init();

	//	�رնԻ���
	virtual void closed();

protected:

	//	���㴥���¼�������ʼ
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);

	//	���㴥���¼������ƶ�
	virtual void onTouchMoved(Touch *touch, Event *unused_event);

	//	���㴥���¼�����ȡ��
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);

	//	���㴥���¼���������
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

	//	���Ӵ��ڳߴ�
	 cocos2d::Size m_sVSize;

	 //	������
	 EventListenerTouchOneByOne* m_pListener;

private:

};


#endif	//	__BASE_DIALOG_H__
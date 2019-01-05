#ifndef __BASE_GAME_LAYER_H__
#define __BASE_GAME_LAYER_H__

#include "cocos2d.h"
#include "GBEventIDs.h"

USING_NS_CC;

#define NOTIFICATION_GAME_ENTERGAME "EnterGame"	//	��Ϣ������Ϸ����������Ϸ

/*
**	������
**	��Ϸ��������
*/
class BaseGameLayer: public Layer
{
public:
	BaseGameLayer();
	virtual ~BaseGameLayer();
	virtual bool init();

	//	���������Ϸ
	virtual void dealEnterGame(Ref* pSender) = 0;
	//	���������Ϣ
	virtual void dealPlayerInfo(Ref* pSender) = 0;
	//	������Ϸ��Ϣ
	virtual void dealMessageGame(Ref* pSender) = 0;
	//	��Ϸ����
	virtual void onMessageScene(unsigned char cbStation,const void* pBuffer,unsigned short wDataSize) = 0;
	//	������Ϸ������Ϣ
	virtual void dealMessageScene(Ref* sender);
	//	��������Ͽ�
	virtual void dealShutNetWork(Ref* sender);
	//	�����¼����ʧ��
	virtual void dealLoginRoomFailed(Ref* sender);
	//	��������ʧ����Ϣ
	virtual void dealSitDownFaild(Ref* sender);

protected:
	//	���ͨ����Ϣ
	virtual void addNotification();

	//	�Ƴ�ͨ����Ϣ
	virtual void removeNotification();


};


#endif  // __BASE_GAME_LAYER_H__

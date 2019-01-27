//  [4/8/2014 xieyi]
#ifndef __DIALOGLAYER__
#define __DIALOGLAYER__
#include "cocos2d.h"
#include "BJLRes.h"
#include <limits>
USING_NS_CC;

enum dialog_type
{
	dialog_hints = 1,//��������
	dialog_back,//����
	dialog_poChan,//�Ʋ�
	dialog_poChanSongCoin,//�Ʋ��ͽ��
	dialog_dismissTable,//��ɢ����
	dialog_roomLimitMin,//��������
	dialog_roomLimitMax,//��������
	dialog_BankerList,//��ׯ�б�<by hxh>
};


class DialogLayer : public Layer
{

public:
	DialogLayer(dialog_type type);
	~DialogLayer();
	virtual bool init();
	bool onTouchBegan(Touch *pTouch, Event *pEvent);;
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent){};
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent){};
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent){};

	static DialogLayer * create(dialog_type type);
	dialog_type m_type;
	virtual void onEnter();
	virtual void onExit();

private:
	void menuOkCallBack(Object * pSender);	//ȷ��
	void menuCancleCallBack(Object * pSender);//ȡ��
	void initTable(char* Name,int type);		//--1Ϊֻ��ȷ����2Ϊȷ����ȡ��
	LabelTTF * m_ttf;
};

#endif
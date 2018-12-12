#ifndef __SETUPLAYER__
#define __SETUPLAYER__
#include "cocos2d.h"
#include "BJLRes.h"
#include "SoundControl.h"
#include <limits>
USING_NS_CC;

class SetUpLayer : public Layer
{
public:
	SetUpLayer();
	~SetUpLayer();
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void onTouchMoved(Touch *pTouch, Event *pEvent);
	void onTouchEnded(Touch *pTouch, Event *pEvent);
	void onTouchCancelled(Touch *pTouch, Event *pEvent);
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	CREATE_FUNC(SetUpLayer);
private:
	bool m_voiceIsOpen;		//�����Ƿ��
	bool m_faceIsOpen;		//���鹦���Ƿ��
	float m_musicVol;//��������
	float m_soundEffVol;//��Ч����
	Sprite * m_voice;		//����״̬
	Sprite * m_voiceOnOff;	//�������ذ�ťͼƬ
	Sprite * m_face;		//����״̬
	Sprite * m_faceOnOff;	//���鿪�ذ�ťͼƬ
	Sprite * m_bgSprite;	//����
	Vec2 m_bgPoint;		//����λ��
	void setVoiceState(bool voiceState);	//��������״̬
	void setFaceState(bool faceState);		//���ñ��鿪��״̬
	SpriteBatchNode * m_batchNode;
	ProgressTimer * m_soundEffTimer;	//��Ч��
	ProgressTimer * m_musicTimer;		//����������
	Sprite * m_soundEffTimerBar;	//��Ч���ϵİ�ť
	bool m_soundBarIsSelected;		//��Ч����ť�Ƿ���
	Sprite * m_musicTimerBar;		//�����������ϵİ�ť
	bool m_musicBarIsSelected;		//�����������Ƿ���
};

#endif
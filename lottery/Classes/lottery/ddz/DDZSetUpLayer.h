//  [4/3/2014 xieyi]
#ifndef DDZ___SETUPLAYER__
#define DDZ___SETUPLAYER__
#include "cocos2d.h"
#include "DDZDDZRes.h"
#include "DDZSoundControl.h"
#include <limits>
USING_NS_CC;

class DDZSetUpLayer : public Layer
{
public:
	DDZSetUpLayer();
	~DDZSetUpLayer();
	virtual bool onTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	CREATE_FUNC(DDZSetUpLayer);
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
	CCProgressTimer * m_soundEffTimer;	//��Ч��
	CCProgressTimer * m_musicTimer;		//����������
	Sprite * m_soundEffTimerBar;	//��Ч���ϵİ�ť
	bool m_soundBarIsSelected;		//��Ч����ť�Ƿ���
	Sprite * m_musicTimerBar;		//�����������ϵİ�ť
	bool m_musicBarIsSelected;		//�����������Ƿ���
};

#endif
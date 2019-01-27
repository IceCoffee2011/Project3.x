//  [3/26/2014 xieyi]
#ifndef __USER__
#define __USER__

#include "cocos2d.h"
#include "BJLRes.h"
USING_NS_CC;

class User : public Layer
{
public:
	User();
	~User();
	virtual bool init();
	CREATE_FUNC(User);
	void setUserIcon(int gender);
	void setLordIcon(bool blord);
	void setIsOnline(bool isOnline);//�����Ƿ�����
	void setUserInfor(char* name,int gold,char* huafeidian);
	void userIconCallBack(Object* obj);
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent){};
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent){};
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent){};

	void  eyeCallUp(Object* _obj);
	//void setSpt
private:
	Sprite*					 m_userInfor;//�����Ϣ
	Sprite*					 m_userEye;
	CC_SYNTHESIZE(Sprite*,m_userIcon,userIcon);
	CC_SYNTHESIZE(Vec2,m_pos,IconPos);
	CC_SYNTHESIZE(int ,m_gender,Gender);//����Ա�,1��ʾ��
	CC_SYNTHESIZE(bool,m_isDiZhu,IsDiZhu);//�ǲ��ǵ���

	CC_SYNTHESIZE(int,m_userId,UserId);//�û�Id��
	CC_SYNTHESIZE(int,m_score,Score);//�û�������Ҳ���ǽ�ң�
	CC_SYNTHESIZE(int,m_goldEggs,GooldEggs);//���ѵ�
	bool        m_isOnline;
	bool        m_isOut;
	int		  m_UserSptKey;				//12�����Ů��34 ������Ů,56ũ����Ů
};

#endif
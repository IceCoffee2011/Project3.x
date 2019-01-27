//  [3/26/2014 xieyi]
#ifndef DDZ___USER__
#define DDZ___USER__

#include "cocos2d.h"
#include "DDZRes.h"
#include "DDZSceneData.h"

USING_NS_CC;

class DDZUser : public Layer
{
public:
	DDZUser();
	~DDZUser();
	virtual bool init();
	CREATE_FUNC(DDZUser);
	void setUserIcon(int gender);
	void setLordIcon(bool blord);
	void setIsOnline(bool isOnline);//�����Ƿ�����
	void userIconCallBack(Object* obj);
	virtual bool onTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchMoved(CCTouch *pTouch, CCEvent *pEvent){};
	virtual void onTouchEnded(CCTouch *pTouch, CCEvent *pEvent){};
	virtual void onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent){};

	void  eyeCallUp(Object* _obj);

	//	�����û���Ϣ
	void setUserInfor(DDZCCuserInfor* pInfor);

	Sprite* m_pImgReady;	//	׼����ʶ

	Sprite* m_noUser;		//������ͷ��

	//	�����ͼID
	CC_SYNTHESIZE(int ,m_nViewID, ViewID);

	void setUserChairId(int id);

	CC_SYNTHESIZE(Vec2,m_userInfoPos,UserInfoPos);
	CC_SYNTHESIZE(Vec2,m_pos,IconPos);

	void setUserLeave(int userId, bool isLeave);

	bool m_isLeave;				//�û��뿪����

private:
	Sprite*					 m_userInfor;//�����Ϣ
	Sprite*					 m_userEye;
	CC_SYNTHESIZE(Sprite*,m_userIcon,userIcon);
	
	CC_SYNTHESIZE(int ,m_gender,Gender);//����Ա�,1��ʾ��
	CC_SYNTHESIZE(bool,m_isDiZhu,IsDiZhu);//�ǲ��ǵ���

	CC_SYNTHESIZE(int long, m_lnUserID, UserID);//�û�Id��
	CC_SYNTHESIZE(int,m_score,Score);//�û�������Ҳ���ǽ�ң�
	bool        m_isOnline;
	bool        m_isOut;
	int		  m_UserSptKey;				//12�����Ů��34 ������Ů,56ũ����Ů

	

	bool			m_IsGetLord;			//�Ƿ��Ѿ������˵���

	bool		m_IsLord;				//�Ƿ�Ϊ����
};

#endif
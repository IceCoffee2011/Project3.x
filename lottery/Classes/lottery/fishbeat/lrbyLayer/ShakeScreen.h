#ifndef __GAME_SHAKE_SCREEN_H__
#define __GAME_SHAKE_SCREEN_H__

#include <iostream>
#include "cocos2d.h"


using namespace cocos2d;
using namespace std;

class ShakeScreen : public ActionInterval
{
public:
	ShakeScreen();
	virtual ~ShakeScreen();
	//param d �𶯳�����ʱ��
	//param strength �𶯵ķ���
	static ShakeScreen* create(float d, float strength);
	//������Ч���ĳ�ʼ����������������ֵ��ͬ
	static ShakeScreen* create(float d, float strength_x, float strength_y);
	bool initWithDuration(float d, float strength_x, float strength_y);

	virtual ShakeScreen* clone() const override;
	virtual ShakeScreen* reverse() const override;
	virtual void startWithTarget(Node* target) override;
	virtual void update(float time) override;
	virtual void stop(void);

protected:
	//�����λ��
	float _initial_x, _initial_y;
	//�����ķ���
	float _strength_x, _strength_y;
	bool _bShake;
};


#endif // __GAME_SHAKE_SCREEN_H__
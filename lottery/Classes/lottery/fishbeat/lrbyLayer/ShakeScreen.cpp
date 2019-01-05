#include "ShakeScreen.h"
#include "CMD_Fish.h"

ShakeScreen::ShakeScreen():
	_strength_x(0.0f),
	_strength_y(0.0f),
	_initial_x(0.0f),
	_initial_y(0.0f),
	_bShake(true)
{

}

ShakeScreen:: ~ShakeScreen()
{

}

//param d �𶯳�����ʱ��
//param strength �𶯵ķ���
ShakeScreen* ShakeScreen::create(float d, float strength)
{
	return create(d, strength, strength);
}
//������Ч���ĳ�ʼ����������������ֵ��ͬ
ShakeScreen* ShakeScreen::create(float d, float strength_x, float strength_y)
{
	ShakeScreen* p_action = new ShakeScreen();
	p_action->initWithDuration(d, strength_x, strength_y);
	p_action->autorelease();

	return p_action;
}

bool ShakeScreen::initWithDuration(float d, float strength_x, float strength_y)
{
	if(ActionInterval::initWithDuration(d))
	{
		_strength_x = strength_x;
		_strength_y = strength_y;

		return true;
	}
	return false;
}

float fgRangRand(float min, float max)
{
	float rnd = ((float)rand()/(float)RAND_MAX);

	return rnd * (max - min) + min;
}

ShakeScreen* ShakeScreen::clone() const
{
	auto a = new ShakeScreen();
	a->initWithDuration(_duration, _strength_x, _strength_y);
	a->autorelease();

	return a;
}

ShakeScreen* ShakeScreen::reverse() const
{
	return ShakeScreen::create(_duration, -_strength_x, -_strength_y);
}

void ShakeScreen::startWithTarget(Node* target)
{
	ActionInterval::startWithTarget(target);
	if(_initial_x == 0 && _initial_y == 0)
	{
		_initial_x = NS_lrbyFish::kResolutionWidth / 2;
		_initial_y = NS_lrbyFish::kResolutionHeight / 2;
	}

}

void ShakeScreen::update(float time)
{
	if (!_bShake)
	{
		_bShake = true;
		return;
	}
	else
	{
		_bShake = false;
	}
	float rndx = fgRangRand(-_strength_x, _strength_x);
	float rndy = fgRangRand(-_strength_y, _strength_y);

	_target->setPosition(Vec2(_initial_x + rndx, _initial_y + rndy));
}

void ShakeScreen::stop(void)
{
	_target->setPosition(Vec2(_initial_x, _initial_y));

	ActionInterval::stop();
}
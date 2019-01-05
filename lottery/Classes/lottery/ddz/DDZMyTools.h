//  [4/10/2014 xieyi]
#ifndef DDZ___SHAKE_H__
#define DDZ___SHAKE_H__
#include "cocos2d.h"
USING_NS_CC;

//��������
class DDZCCShake : public cocos2d::CCActionInterval
{
public:
	DDZCCShake();
	static DDZCCShake * create(float d,float strength);
	static DDZCCShake * createWithStrength(float d,float strength_x,float strength_y);
	bool initWithDuration(float d,float stength_x,float strength_y);

protected:

	void startWithTarget(cocos2d::Node * pTarget);
	void update(float time);
	void stop(void);
	Vec2 m_startPosition;
	float m_strength_x;
	float m_strength_y;

};
//�������
class DDZCCStrokeLabel : public cocos2d::Node {
public:
	static DDZCCStrokeLabel* create(cocos2d::LabelTTF* labelTTF,cocos2d::Color3B fullColor,cocos2d::Color3B StrokeColor,float strokeSize);
	virtual bool init();
	float getStrokeSize();
	void setStrokeSize(float strokeSize);
private:
	cocos2d::Sprite* m_sprite;
	cocos2d::LabelTTF* m_label;
	cocos2d::Color3B m_fullColor;
	cocos2d::Color3B m_StrokeColor;
	float m_strokeSize;
};

#endif
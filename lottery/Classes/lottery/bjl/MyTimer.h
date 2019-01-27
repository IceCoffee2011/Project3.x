//  [3/26/2014 xieyi]
#ifndef __TIMER__
#define __TIMER__

#include "cocos2d.h"
#include "BJLRes.h"
#include "SceneData.h"
USING_NS_CC;
using namespace cocos2d;
class CCtimeCallBack:public Integer
{
public:
	CCtimeCallBack(int v):Integer(v){};
	CREATE_FUNC_MSG(CCtimeCallBack);
	Game_State m_gameState;
	int				m_timeKey;
};
class MyTimer : public Node
{
public :
	MyTimer();
	~MyTimer();
	CREATE_FUNC(MyTimer);
	virtual bool init();
	void time_schedule(float t);		//ʱ��ص�
	int m_time;
	void start(int userId, int t,Game_State gameState,int key);	//���м�ʱ��
	LabelAtlas * m_number;			//��ʱ������
	Game_State m_gameState;				//��Ϸ״̬
	int				m_timeKey;
	int				m_UserID;
	Sprite *m_nikeSprite;

	void AddObject();
	void RemoveObject();

	void setCCteefTag(Object *obj); //����
	void setCardTalayer(Object *obj); //����  
	void setPlaceScore(Object *obj);  //��ע
private:
	Node * g_timerNode;
};

#endif
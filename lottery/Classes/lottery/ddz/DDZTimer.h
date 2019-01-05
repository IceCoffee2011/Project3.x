//  [3/26/2014 xieyi]
#ifndef DDZ___TIMER__
#define DDZ___TIMER__

#include "cocos2d.h"
#include "DDZDDZRes.h"
#include "DDZSceneData.h"
USING_NS_CC;

class DDZCCtimeCallBack:public Integer
{
public:
	DDZCCtimeCallBack(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCtimeCallBack);
	DDZGame_State m_gameState;
	int				m_timeKey;
};

class DDZTimer : public Node
{
public :
	DDZTimer();
	~DDZTimer();
	CREATE_FUNC(DDZTimer);
	virtual bool init();
	void time_schedule(float t);		//ʱ��ص�
	int m_time;
	void start(int userId, int t,DDZGame_State gameState,int key);	//���м�ʱ��
	Label* m_pDDZTimeNum;		//	��ʱ������
	DDZGame_State m_gameState;				//��Ϸ״̬
	int				m_timeKey;
	int				m_UserID;

	bool longTimeNoAction;				//�Ƿ���볤ʱ��δ��������

	void startCheckNoAction();			//������Ҳ��������

	void stopCheckCheckNoAction();		//�ر���Ҳ��������

	void onUserNoAction(float dt);		//�û���ʱ��û�в����� ��ʾ�û�����
private:
	Node * g_timerNode;

	int m_allCountTime;					//����ʱ��ʼ����ʱ��
};

#endif
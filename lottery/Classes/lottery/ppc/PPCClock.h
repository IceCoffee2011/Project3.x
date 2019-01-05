#ifndef __PPC_CLOCK_H__
#define __PPC_CLOCK_H__

#include "cocos2d.h"
#include "PPCEnum.h"

USING_NS_CC;

//	ʱ��
class PPCClock: public Node
{
public:
	PPCClock();
	~PPCClock();
	CREATE_FUNC(PPCClock);

	//	����ʱ��
	void countdownTimer(int nValue);

	//	�趨��ʱ������
	void setTimerType(EPPCProcessType eType);
private:
	bool init();
	void initUI();
	void initData();

	//	��������ʱ��
	void onCountdown(float dt);

	//	������ʱ�¼�
	void onTimeEvent();

	//	������ʱ���¼�
	void onLotteryTime();

	//	ʱ�ӱ���
	Sprite* m_pBG;

	//	��ʾ��
	Sprite* m_pTips;

	//	ʱ������
	Label* m_pBMFNum;

	//	ʱ����ֵ
	int m_nTime;

	//	��������
	EPPCProcessType m_eType;
};

#endif  // __PPC_CLOCK_H__
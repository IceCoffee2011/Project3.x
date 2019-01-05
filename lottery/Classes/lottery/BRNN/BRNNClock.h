#ifndef __BRNN_CLOCK_H__
#define __BRNN_CLOCK_H__

#include "cocos2d.h"
#include "BRNNDefine.h"

USING_NS_CC;

/*
**	@brief	����ţţ����ʱ��
*/
class BRNNClock: public Node
{
public:
	BRNNClock();
	~BRNNClock();
	CREATE_FUNC(BRNNClock);

	//	����ʱ��
	void playCountdownTimer(int nValue);

	//	�趨��ʱ������
	void setTimerType(E_BRNNProcessType eType);
private:
	bool init();
	void initUI();
	void initData();

	//	��������ʱ��
	void onCountdown(float dt);

	//	ʱ�ӱ���
	Sprite* m_pBG;

	//	��ʾ��
	Sprite* m_pTips;

	//	ʱ������
	Label* m_pBMFNum;

	//	ʱ����ֵ
	int m_nTime;

	//	��������
	E_BRNNProcessType m_eType;
};

#endif  // __BRNN_CLOCK_H__
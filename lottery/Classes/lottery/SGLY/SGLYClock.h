#ifndef __SGLY_CLOCK_H__
#define __SGLY_CLOCK_H__

#include "cocos2d.h"
#include "SGLYDefine.h"

USING_NS_CC;

/*
**	@brief	ˮ����԰����ʱ��
*/
class SGLYClock: public Node
{
public:
	SGLYClock();
	~SGLYClock();
	CREATE_FUNC(SGLYClock);

	//	����
	void reset();

	//	����ʱ��
	void playCountdownTimer(int nValue);

	//	�趨��ʱ������
	void setTimerType(E_SGLY_Process eType);

	//	��ʾ�´�С����
	void showGuessAni();

	//	������ʾ������
	void setLabNum(int nValue);

	//	��õ�ǰ����״̬
	E_SGLY_Process getProcess() const;
private:
	bool init();
	void initUI();
	void initData();

	//	��������ʱ��
	void onCountdown(float dt);

	//	�����ʾ����
	void showRandomNum(float dt);

	//	ʱ�ӱ���
	Sprite* m_pBG;

	//	��ʾ������
	Sprite* m_pTipsBG;

	//	��ʾ��
	Sprite* m_pTips;

	//	ʱ������
	Label* m_pLabNum;

	//	ʱ����ֵ
	int m_nTime;

	//	�������
	int m_nRandomNum;

	//	��������
	E_SGLY_Process m_eType;
};

#endif  // __SGLY_CLOCK_H__
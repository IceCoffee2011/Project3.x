#ifndef __SGLY_ANI_LOTTERY_H__
#define __SGLY_ANI_LOTTERY_H__

#include "cocos2d.h"

USING_NS_CC;

/*
**	@brief	ˮ����԰������ת�����������������棩
*/
class SGLYAniLottery: public ActionInterval
{
public:
	SGLYAniLottery();
	~SGLYAniLottery();

	static SGLYAniLottery* create(float fDuration, int nIdx);

private:
	void initData(float fDuration, int nIdx);
	void showHighLight(int nIdx);
	void update(float time);

	int m_TargetIdx;	//	Ŀ������
	int m_nFinishSHift;	//	����·��
	int m_nCurrIdx;	//	��ǰ����logo����
	bool m_bSegregate;	//	����

	int m_nS0;	//	���ٶ���λ��
	int m_nS1;	//	���ٶ���λ��
	int m_nS2;	//	���ٶ���λ��

	int m_nSSum;	//	��·��
	int m_nEndS0;	//	���ٶ��յ�
	int m_nEndS1;	//	���ٶ��յ�
	int m_nEndS2;	//	���ٶ��յ�

	int m_nSNor0;	//	���ٶε�λ·��
	int m_nSNor1;	//	���ٶε�λ·��
	int m_nSNor2;	//	���ٶε�λ·��

	float m_fT0;	//	���ٶγ���ʱ��
	float m_fT1;	//	���ٶγ���ʱ��
	float m_fT2;	//	���ٶγ���ʱ��

	float m_fAveT1;	//	���ٶ�ƽ��ʱ��
	float m_fAveV1;	//	���ٶ�ƽ���ٶ�

	float m_fStartV0;	//	���ٶγ��ٶ�
	float m_fEndV0;	//	���ٶ�ĩ�ٶ�

	float m_fStartV2;	//	���ٶγ��ٶ�
	float m_fEndV2;	//	���ٶ�ĩ�ٶ�

	float m_fA0;	//	���ٶμ��ٶ�
	float m_fA2;	//	���ٶμ��ٶ�

	float m_fVT;	//	ĩ�ٶ�
	float m_fPayT;	//	����ʱ��
};

/*
**	@brief	ˮ����԰������ת���������������ٰ棩
*/
class SGLYAniUniform: public ActionInterval
{
public:
	SGLYAniUniform();
	~SGLYAniUniform();

	/*
	**	@brief	����ˮ����԰GoodLuck����Ч��
	**	@fDuration	����ʱ��
	**	@nBeginIdx	��ʼλ������
	**	@nEndIdx	����λ������
	**	@pMoveTarget	�ƶ����
	**	@nCount	����Ȧ��
	**	@bIsForward	�Ƿ���ת
	*/
static SGLYAniUniform* create(float fDuration, int nBeginIdx, int nEndIdx, Node* pMoveTarget, bool bIsForward = true, int nCount = 1);

private:

	void initData(float fDuration, int nBeginIdx, int nEndIdx, Node* pMoveTarget, bool bIsForward, int nCount);
	void showHighLight(int nIdx);
	void update(float time);

	//	��ʼλ������
	int m_nBeginIdx;

	//	����λ������
	int m_nEndIdx;

	//	�Ƿ���ת
	bool m_bIsForward;

	//	��·��
	int m_nTotalS;

	//	ƽ���ٶ�
	float m_fAveV;

	//	����·��
	int m_nRunS;

	//	��ǰλ������
	int m_nCurrIdx;

	//	�ƶ�����
	Node* m_pMoveTarget;

	//	ִֻ��һ������
	bool m_bOnce;
};

#endif  // __SGLY_ANI_LOTTERY_H__
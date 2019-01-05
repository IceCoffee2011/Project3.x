#ifndef __PPC_ANI_ON_DRIVE_H__
#define __PPC_ANI_ON_DRIVE_H__

#include "cocos2d.h"
#include "PPCGameLayer.h"

USING_NS_CC;

class PPCAniOnDrive: public ActionInterval
{
public:
	PPCAniOnDrive();
	~PPCAniOnDrive();

	static PPCAniOnDrive* create(float fDuration, int nIdx);

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

#endif  // __PPC_ANI_ON_DRIVE_H__
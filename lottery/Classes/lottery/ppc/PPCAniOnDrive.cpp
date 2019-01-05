#include "PPCAniOnDrive.h"
#include "PPCGameScene.h"

PPCAniOnDrive::PPCAniOnDrive()
{
}

PPCAniOnDrive::~PPCAniOnDrive()
{
}

PPCAniOnDrive* PPCAniOnDrive::create(float fDuration, int nIdx)
{
	PPCAniOnDrive* pAction = new PPCAniOnDrive();
	if (pAction && pAction->initWithDuration(fDuration))
	{
		pAction->autorelease();
		pAction->initData(fDuration, nIdx);
	}
	else
	{
		delete pAction;
		pAction = nullptr;
	}

	return pAction;
}

void PPCAniOnDrive::initData(float fDuration, int nIdx)
{
	m_TargetIdx = nIdx;
	m_nFinishSHift = 0;											//	����·��
	m_nCurrIdx = 0;												//	��ǰ����logo����
	m_bSegregate = false;

	m_nS0 = PPC_CARLGOG_COUNT;									//	����ʱ�����λ��
	m_nS1 = 2 * PPC_CARLGOG_COUNT + nIdx;						//	����ʱ�����λ��
	m_nS2 = PPC_CARLGOG_COUNT;									//	����ʱ�����λ��

	m_nSSum = m_nS0 + m_nS1 + m_nS2;							//	��·��
	m_nEndS0 = m_nS0;											//	���ٶ��յ�
	m_nEndS1 = m_nS0 + m_nS1;									//	���ٶ��յ�
	m_nEndS2 = m_nSSum;											//	���ٶ��յ�

	m_nSNor0 = 0;												//	���ٶε�λ·��
	m_nSNor1 = 0;												//	���ٶε�λ·��
	m_nSNor2 = 0;												//	���ٶε�λ·��

	m_fAveV1 = (2 * m_nS0 + m_nS1 + 2 * m_nS2) / fDuration;		//	����ƽ���ٶ�
	m_fT1 = (float)m_nS1 / m_fAveV1;							//	���ٳ���ʱ��
	m_fAveT1 = m_fT1 / m_nS1;									//	����ƽ��ʱ��

	m_fT0 = (fDuration - m_fT1) / 2;							//	���ٳ���ʱ��
	m_fT2 = m_fT0;												//	���ٳ���ʱ��

	m_fStartV0 = 0;												//	���ٳ��ٶ�
	m_fEndV0 = m_fAveV1;										//	����ĩ�ٶ�
	m_fA0 = (m_fEndV0 - m_fStartV0) / m_fT0;					//	���ٶ�

	m_fStartV2 = m_fAveV1;										//	���ٳ��ٶ�
	m_fEndV2 = 0;												//	����ĩ�ٶ�
	m_fA2 = (m_fEndV2 - m_fStartV2) / m_fT2;					//	���ٶ�

	m_fVT = 0;													//	ĩ�ٶ�
	m_fPayT = 0;												//	����ʱ��
}

void PPCAniOnDrive::showHighLight(int nIdx)
{
	PPCGameScene* pGameScene = dynamic_cast<PPCGameScene*>(Director::getInstance()->getRunningScene());
	if (!pGameScene)
	{
		return;
	}
	pGameScene->m_pPPCGameLayer->showSingleCarLogoHighLight(nIdx, true);
}

void PPCAniOnDrive::update(float time)
{
	if (!_target)
	{
		return;
	}
	bool bIsRun = false;
	float dt = time * _duration;

	if (m_nFinishSHift > m_nSSum && m_nCurrIdx > m_TargetIdx)
	{
		return;
	}
	if (m_nFinishSHift == 0)
	{
		bIsRun = true;
	}
	else if (m_nFinishSHift > 0 && m_nFinishSHift <= m_nEndS0)
	{

		if (!m_bSegregate)
		{
			m_fVT = sqrtf((2 * m_fA0 * m_nSNor0) + powf(m_fStartV0, 2));	
			m_fPayT = (m_fVT - m_fStartV0) / m_fA0;

			m_bSegregate = true;
		}
		if (dt >= m_fPayT)
		{
			bIsRun = true;
			m_nSNor0++;
		}
	}
	else if (m_nFinishSHift > m_nEndS0 && m_nFinishSHift <= m_nEndS1)
	{
		float fNodeT = m_fT0 + m_nSNor1 * m_fAveT1;
		if (dt >= fNodeT)
		{
			bIsRun = true;
			m_nSNor1++;
		}
	}
	else if (m_nFinishSHift > m_nEndS1 && m_nFinishSHift <= m_nEndS2)
	{
		if (!m_bSegregate)
		{
			m_fVT = sqrtf((2 * m_fA2 * m_nSNor2) + powf(m_fStartV2, 2));	
			float fTime = (m_fVT - m_fStartV2) / m_fA2;

			m_fPayT = m_fT0 + m_fT1+ fTime;
			m_bSegregate = true;
		}
		if (dt >= m_fPayT)
		{
			bIsRun = true;
			m_nSNor2++;
		}
	}

	if (bIsRun)
	{
		showHighLight(m_nCurrIdx);
		m_nCurrIdx++;
		m_nFinishSHift++;
		m_bSegregate = false;
	}

	if (m_nCurrIdx == PPC_CARLGOG_COUNT)
	{
		m_nCurrIdx = 0;
	}
}
#ifndef __BRNN_INFO_BAR_H__
#define __BRNN_INFO_BAR_H__

#include "cocos2d.h"
#include "Define.h"

USING_NS_CC;
using namespace std;

/*
**	@brief	����ţţ������Ϣ��
*/
class BRNNInfoBar: public Layer
{
public:
	BRNNInfoBar();
	~BRNNInfoBar();
	CREATE_FUNC(BRNNInfoBar);

	//	����
	void resetInfoBar();
	
	/*����ׯ����Ϣ
	wBankerUser			��ǰׯ��
	szBankerNickName	ׯ���ǳ�
	cbBankerGender		ׯ���Ա�
	lBankerScore		ׯ�ҷ���
	lBankerWinScore		ׯ�ҳɼ�
	cbBankerTime		ׯ�Ҿ���
	bSystemBanker		ϵͳ��ׯ
	*/
	void updateBankerInfo(WORD wBankerUser, TCHART szBankerNickName[], BYTE cbBankerGender, SCORE lBankerScore, SCORE lBankerWinScore, WORD cbBankerTime, bool bSystemBanker = true);

	//	������ҽ��
	void updatePlayerGold(SCORE sValue);

	//	������ҳɼ�
	void updatePlayerTotal(SCORE sValue);

	//	�������Ͷע����
	void updatePlayerBetSum(SCORE sValue);

	//	����ׯ�ҽ��
	void updateBankerGold(SCORE sValue);

	//	����ׯ�ҳɼ�
	void updateBankerTotal(SCORE sValue);

	//	����ׯ����ׯ��
	void updateBankerTime(WORD wValue);

	//	���ͷ��
	Sprite* m_pPlayerFace;

	//	����ǳ�
	Label* m_pPlayerName;

	//	��ҲƸ�
	Label* m_pPlayerGold;

	//	��ҳɼ�
	Label* m_pPlayerTotal;

	//	���Ͷע
	Label* m_pPlayerBetSum;

	//	ׯ��ͷ��
	Sprite* m_pBankerFace;

	//	ׯ���ǳ�
	Label* m_pBankerName;

	//	ׯ�ҲƸ�
	Label* m_pBankerGold;

	//	ׯ�ҳɼ�
	Label* m_pBankerTotal;

	//	ׯ����ׯ
	Label* m_pBankerTime;

private:
	bool init();
	void initUI();
	void initData();

	//	��ҽ����ֵ
	CC_SYNTHESIZE(SCORE, m_dPlayerGold, PlayerGold);

	//	��ҳɼ���ֵ
	CC_SYNTHESIZE(SCORE, m_dPlayerTotal, PlayerTotal);

	//	���Ͷע�ܶ���ֵ
	CC_SYNTHESIZE(SCORE, m_dPlayerBetSum, PlayerBetSum);

	//	ׯ������ID
	CC_SYNTHESIZE(SCORE, m_sBankerChairID, BankerChairID);

	//	������ׯ����
	string m_sNoneBankerName;
};


#endif  // __BRNN_INFO_BAR_H__
#ifndef __SGLY_INFO_CENTER_H__
#define __SGLY_INFO_CENTER_H__

#include "cocos2d.h"
#include "SGLYDefine.h"
#include "Define.h"

USING_NS_CC;

/*
**	@brief	ˮ����԰������Ϣ��
*/
class SGLYInfoCenter: public Layer
{
public:
	SGLYInfoCenter();
	~SGLYInfoCenter();
	CREATE_FUNC(SGLYInfoCenter);

	//	����
	void reset();

	/*
	**	@brief				����ׯ����Ϣ
	**	@wBankerUser		��ǰׯ��
	**	@szBankerNickName	ׯ���ǳ�
	**	@lBankerChip		ׯ�ҳ���
	**	@lBankerWinScore	ׯ�ҳɼ�
	**	@cbBankerTime		ׯ�Ҿ���
	**	@bSystemBanker		ϵͳ��ׯ
	*/
	void updateBankerInfo(WORD wBankerUser, TCHART szBankerNickName[], LONGLONG lBankerChip, LONGLONG lBankerWinScore, WORD cbBankerTime, bool bSystemBanker = true);

	//	���¸�ע
	void updateSelfBet(E_SGLY_Lottery eType, const LONGLONG sValue);

	//	������ע
	void updateTotalBet(E_SGLY_Lottery eType, const LONGLONG sValue);

	//	������Ϣ��
	void updateInfoBar(E_SGLY_InfoBar eType, const LONGLONG sValue);

	//	������Ϣ����ֵ
	void setValueInfoBar(E_SGLY_InfoBar eType, const LONGLONG sValue);

	//	�����Ϣ����ֵ
	LONGLONG getValueInfoBar(E_SGLY_InfoBar eType) const;

	//	���ø�ע��ֵ
	void setValueSelfBet(E_SGLY_Lottery eType, const LONGLONG sValue);

	//	��ø�ע��ֵ
	LONGLONG getValueSelfBet(E_SGLY_Lottery eType) const;

	//	������ע��ֵ
	void setValueTotalBet(E_SGLY_Lottery eType, const LONGLONG sValue);

	//	�����ע��ֵ
	LONGLONG getValueTotalBet(E_SGLY_Lottery eType) const;

	//	������Ѻ��ֵ
	void setValueContinueBet(E_SGLY_Lottery eType, const LONGLONG sValue);

	//	�����Ѻ��ֵ
	LONGLONG getValueContinueBet(E_SGLY_Lottery eType) const;

	//	�Ƿ���д��Ѻ��ֵ
	CC_SYNTHESIZE(bool, m_bOverwrite, Overwrite);
private:
	bool init();

	void initUI();

	void initData();

	//	��ֵ����������ׯ
	string m_sNoneBankerName;

	//	�ı�����ׯ���ǳ�
	Label* m_pLabBankerNickname;

	//	��ֵ������Ϣ��
	LONGLONG m_sValueInfoBar[E_SGLY_InfoBar_Null];

	//	�ı�������Ϣ��
	Label* m_pLabInfoBar[E_SGLY_InfoBar_Null];

	//	��ֵ������ע
	LONGLONG m_sValueSelfBet[E_SGLY_Lottery_Null];

	//	�ı�������ע
	Label* m_pLabSelfBet[E_SGLY_Lottery_Null];

	//	��ֵ������ע
	LONGLONG m_sValueTotalBet[E_SGLY_Lottery_Null];

	//	�ı�������ע
	Label* m_pLabTotalBet[E_SGLY_Lottery_Null];

	//	��ֵ������Ѻ
	LONGLONG m_sValueContinueBet[E_SGLY_Lottery_Null];
	LONGLONG m_llNoneBankerChip;
};


#endif  // __SGLY_INFO_CENTER_H__
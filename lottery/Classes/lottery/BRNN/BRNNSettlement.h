#ifndef __BRNN_SETTLEMENT_H__
#define __BRNN_SETTLEMENT_H__

#include "cocos2d.h"
#include "Define.h"

USING_NS_CC;

/*
**	@brief	����ţţ�����������
*/
class BRNNSettlement: public Layer
{
public:
	BRNNSettlement();
	~BRNNSettlement();

	CREATE_FUNC(BRNNSettlement);

	//	������ҵ÷�
	void updatePlayerScore(SCORE sValue);

	//	������ҷ��ر���
	void updatePlayerCapital(SCORE sValue);

	//	����ׯ�ҵ÷�
	void updateBankerScore(SCORE sValue);

private:
	bool init();
	void initUI();

	//	����
	Sprite* m_pBG;

	//	��ҵ÷�
	Label* m_pLabPlayerScore;

	//	��ҷ��ر���
	Label* m_pLabPlayerCapital;

	//	ׯ�ҵ÷�
	Label* m_pLabBankerScore;

};

#endif  // #define __BRNN_SETTLEMENT_H__

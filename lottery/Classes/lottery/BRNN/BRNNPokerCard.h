#ifndef __BRNN_POKER_CARD_H__
#define __BRNN_POKER_CARD_H__

#include "cocos2d.h"
#include "Card.h"
#include "BRNNDefine.h"
#include "Define.h"

USING_NS_CC;

/*
**	@brief	����ţţ�����˿���
*/
class BRNNPokerCard: public Card
{
public:
	BRNNPokerCard();
	~BRNNPokerCard();
	CREATE_FUNC(BRNNPokerCard);

	//	��ʼ������
	void initCard(const int nCardIdx);

private:
	bool init();

	/*
	**	@brief	��ȡ���������ļ���
	**	@nCardIdx	����������0Ϊ���Ʊ��棬1-54Ϊ����
	*/
	string getCardFileName(const int nCardIdx);

};

/*
**	@brief	����ţţ��������
*/
class BRNNHandsCard: public Node
{
public:
	BRNNHandsCard();
	~BRNNHandsCard();
	CREATE_FUNC(BRNNHandsCard);
	
	//	����
	void resetHandsCard();

	//	��ʼ����������
	void initHandsCard(int nIdx, const BYTE sCardData);

	//	��ʼ����������
	void initHandsCard(const BYTE sCardData[]);

	//	չ����������
	void showCardType(E_BRNN_CardType eCardType);

	//	��Ŀչʾ����
	void showCardMarkedness();

	//	�˿���
	BRNNPokerCard* m_pPokerCard[BRNN_HANDS_CARD_COUNT];

	//	�˿�������
	BYTE m_cbCardData[BRNN_HANDS_CARD_COUNT];

	//	����
	CC_SYNTHESIZE(E_BRNN_CardType, m_eCardType, CardType);
private:
	bool init();
	void initUI();

	//	���͵���
	Sprite* m_pCardTypeFloor;

	//	����
	Sprite* m_pCardType;

};

#endif  // __BRNN_POKER_CARD_H__
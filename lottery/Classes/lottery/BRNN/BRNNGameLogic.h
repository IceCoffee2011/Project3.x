#ifndef __BRNN_GAME_LOGIC_H__
#define __BRNN_GAME_LOGIC_H__

#include "cocos2d.h"
#include "BRNNDefine.h"
#include "Define.h"

//////////////////////////////////////////////////////////////////////////
		
//��ֵ����
#define	LOGIC_MASK_COLOR			0xF0								//��ɫ����
#define	LOGIC_MASK_VALUE			0x0F								//��ֵ����

//��������
#define	ST_VALUE					1									//��ֵ����
#define	ST_NEW					    3									//��ֵ����
#define	ST_LOGIC					2									//�߼�����

//�˿���Ŀ
#define CARD_COUNT					54									//�˿���Ŀ

//////////////////////////////////////////////////////////////////////////


/*
**	@brief	����ţţ������Ϸ�߼�
*/
class BRNNGameLogic
{
	//��������
public:

	//��������
public:
	//���캯��
	BRNNGameLogic();
	//��������
	virtual ~BRNNGameLogic();

	//���ͺ���
public:
	//��ȡ��ֵ
	static BYTE GetCardValue(BYTE cbCardData) 
	{ 
		return cbCardData&LOGIC_MASK_VALUE; 
	}

	//��ȡ��ɫ
	static BYTE GetCardColor(BYTE cbCardData)
	{
		return (cbCardData&LOGIC_MASK_COLOR)>>4;
	}

	//���ƺ���
public:
	//�����˿�
	static void SortCardList(BYTE cbCardData[], BYTE cbCardCount, BYTE cbSortType);

	//	ת����Ӧ����
	static E_BRNN_CardType RetType(int itype);

	//�߼�����
public:
	//��ȡ�Ƶ�
	static BYTE GetCardListPip(const BYTE cbCardData[], BYTE cbCardCount);

	//��ȡ����
	static E_BRNN_CardType GetCardType(const BYTE cbCardData[], BYTE cbCardCount,BYTE bcOutCadData[] = NULL);

	//��С�Ƚ�
	static int CompareCard(const BYTE cbFirstCardData[], BYTE cbFirstCardCount,const BYTE cbNextCardData[], BYTE cbNextCardCount,BYTE &Multiple);

	//�߼���С
	static BYTE GetCardLogicValue(BYTE cbCardData);

	static BYTE GetCardNewValue(BYTE cbCardData);
};

//////////////////////////////////////////////////////////////////////////

#endif	//	__BRNN_GAME_LOGIC_H__

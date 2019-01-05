#ifndef GAME_LOGIC_HEAD_FILE
#define GAME_LOGIC_HEAD_FILE
#include"CMD_DZPK.h"

// �����˿����߼�
class DZPKGameLogic
{
	//��������
public:
	//���캯��
	DZPKGameLogic();
	//��������
	virtual ~DZPKGameLogic();

	//��������
private:
	static BYTE m_cbCardData[DZPK_FULL_COUNT];				//�˿˶���

	//���ƺ���
public:
	//�����˿�
	static void SortCardList(BYTE cbCardData[], BYTE cbCardCount);
	//�����˿�
	static void RandCardList(BYTE cbCardBuffer[], BYTE cbBufferCount);

	//���ͺ���
public:
	//��ȡ����
	static BYTE GetCardType(BYTE cbCardData[], BYTE cbCardCount);
	//��ȡ��ֵ
	static BYTE GetCardValue(BYTE cbCardData) { return cbCardData&LOGIC_MASK_VALUE; }
	//��ȡ��ɫ
	static BYTE GetCardColor(BYTE cbCardData) { return cbCardData&LOGIC_MASK_COLOR; }
	//�����˿�
	static BYTE GetSameCard(const BYTE bCardData[],const BYTE bMaxCard[],BYTE bCardCount,BYTE bMaxCardCount,BYTE bResultData[]);

	//���ܺ���
public:
	//�߼���ֵ
	static BYTE GetCardLogicValue(BYTE cbCardData);
	//�Ա��˿�
	static BYTE CompareCard(BYTE cbFirstData[], BYTE cbNextData[], BYTE cbCardCount);
	//�����˿�
	static void AnalysebCardData(const BYTE cbCardData[], BYTE cbCardCount, tagAnalyseResult_dzpk & AnalyseResult);
	//7��5
	static BYTE FiveFromSeven(BYTE cbHandCardData[],BYTE cbHandCardCount,BYTE cbCenterCardData[],BYTE cbCenterCardCount,BYTE cbLastCardData[],BYTE cbLastCardCount);
	//�������
	static bool SelectMaxUser(BYTE bCardData[DZPKGAME_PLAYER][MAX_CENTERCOUNT],UserWinList &EndResult,const LONGLONG lAddScore[]);
};

//////////////////////////////////////////////////////////////////////////

#endif

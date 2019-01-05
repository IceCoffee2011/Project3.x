#ifndef __BRNN_BET_AREA_H__
#define __BRNN_BET_AREA_H__

#include "cocos2d.h"
#include "BRNNDefine.h"
#include "Define.h"

USING_NS_CC;
using namespace std;

/*
**	@brief	����ţţ������ע�����
*/
class BRNNBetArea: public Node
{
public:
	BRNNBetArea();
	~BRNNBetArea();
	CREATE_FUNC(BRNNBetArea);

	//	������ע�����
	void resetTableArea();

	//	��ʼ�������
	void initArea(E_BRNNBetAreaType eArea);

	//	�ж�һ���Ƿ���������
	bool isContainsPoint(Vec2 vPos);

	//	��ӳ���
	Sprite* addTableChip(E_BRNNChipType eType);

	//	���������Ƿ����
	void setAreaHighLight(bool isHighLight);

	//	���ó�����ע�ı���ֵ
	void setLabChipValueSum(LONGLONG llValue);

	//	���ó����ע�ı���ֵ
	void setLabChipValueSelf(LONGLONG llValue);

private:
	bool init();

	//	���򱳾�
	Sprite* m_pBG;

	//	�������
	Sprite* m_pLight;

	//	�����ע�ı�����
	Sprite* m_pChipValueSelfFloor;

	//	������ע�ı�
	Label* m_pLabChipValueSum;

	//	�����ע�ı�
	Label* m_pLabChipValueSelf;

	//	�������
	cocos2d::Rect m_rAreaRect;

	//	��������
	E_BRNNBetAreaType m_eAreaType;

	//	�����������
	Node* m_pVesselChip;

	//	������ע��
	CC_SYNTHESIZE(LONGLONG, m_llChipValueSum, ChipValueSum);

	//	�����ע��
	CC_SYNTHESIZE(LONGLONG, m_llChipValueSelf, ChipValueSelf);
};


#endif  // __BRNN_BET_AREA_H__

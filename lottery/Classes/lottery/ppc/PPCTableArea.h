#ifndef __PPC_TABLE_AREA_H__
#define __PPC_TABLE_AREA_H__

#include "cocos2d.h"
#include "common/PPCEnum.h"
#include "common/PPCRes.h"
#include "Define.h"

USING_NS_CC;
using namespace std;

//	���������
class PPCTableArea: public Node
{
public:
	PPCTableArea();
	~PPCTableArea();
	CREATE_FUNC(PPCTableArea);

	//	�������������
	void resetTableArea();

	//	��ʼ�������
	void initArea(EPPCCarLogoType eArea);

	//	�ж�һ���Ƿ���������
	bool isContainsPoint(Vec2 vPos);

	//	��ӳ���
	Sprite* addTableChip(EPPCChipType eType);

	//	���������Ƿ����
	void setAreaHighLight(bool isHighLight);

	//	���ó�����ע�ı���ֵ
	void setLabChipValueSum(LONGLONG llValue);

	//	���ó����ע�ı���ֵ
	void setLabChipValueSelf(LONGLONG llValue);

private:
	bool init();
	void initData();

	//	����ͼ��
	Sprite* m_pIcon;

	//	������ע�ı�
	Label* m_pLabChipValueSum;

	//	�����ע�ı�
	Label* m_pLabChipValueSelf;

	//	�������
	Sprite* m_pLight;

	//	�������
	cocos2d::Rect m_rAreaRect;

	//	��������
	EPPCCarLogoType m_eAreaType;

	//	�����������
	vector<Node*> m_vVesselChip;

	//	������ע��
	CC_SYNTHESIZE(LONGLONG, m_llChipValueSum, ChipValueSum);

	//	�����ע��
	CC_SYNTHESIZE(LONGLONG, m_llChipValueSelf, ChipValueSelf);
};


#endif  // __PPC_TABLE_AREA_H__

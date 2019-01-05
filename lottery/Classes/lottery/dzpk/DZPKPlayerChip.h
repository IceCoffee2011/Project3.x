#ifndef __DZPK_PLAYER_CHIP_H__
#define __DZPK_PLAYER_CHIP_H__

#include "cocos2d.h"
#include "DZPKChip.h"

USING_NS_CC;

class DZPKPlayerChip: public DZPKChip
{
public:
	DZPKPlayerChip();
	~DZPKPlayerChip();
	CREATE_FUNC(DZPKPlayerChip);
	bool init();

	/*
	**	@brief	�������
	*/
	void clearChip();

	/*
	**	@brief	���ó���λ��
	**	@vBetPos	��עʱ��������λ��
	**	@vPlayerPos	��ҳ����ʼλ��
	**	@vChipPoolPos	�����λ��
	*/
	void setChipPosition(Vec2 vBetPos, Vec2 vPlayerPos, Vec2 vChipPoolPos);

	/*
	**	@brief	��ע
	*/
	void bet(LONGLONG llValue);

	/*
	**	@brief	����
	*/
	void collect();

	/*
	**	@brief	�ַ�
	*/
	void distribute(LONGLONG llValue);

	/*
	**	@brief	��ע����
	*/
	void aniBet();

	/*
	**	@brief	���ܶ���
	*/
	void aniCollect();

	/*
	**	@brief	�ַ�����
	*/
	void aniDistribute();

private:

	/*
	**	@brief	������ֵ
	*/
	LONGLONG m_llChipValue;

	/*
	**	@brief	��עʱ��������λ��
	*/
	Vec2 m_vBetPos;

	/*
	**	@brief	��ҳ����ʼλ��
	*/
	Vec2 m_vPlayerPos;

	/*
	**	@brief	�����λ��
	*/
	Vec2 m_vChipPotPos;

};



#endif  // __DZPK_PLAYER_CHIP_H__
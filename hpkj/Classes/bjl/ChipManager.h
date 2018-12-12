#ifndef __GAME_CHIPMANAGER_H__
#define __GAME_CHIPMANAGER_H__
#pragma once

/***************************************
 ���������
 ��Ϸ����
 xxxx 2013.1.10
 ***************************************/

#include "cocos2d.h"
#include "Define.h"
USING_NS_CC;

class ChipManager : public cocos2d::Layer
{
public:
	ChipManager();
	~ChipManager();
	//��������
	static ChipManager *create();
	//��ʼ����ע
	bool initTotalChipValue();
	
	//���õ�ע
	void showGetChipManager(BYTE cbBetArea,LONGLONG lBetScore);

	//���ó��뾫��
	void showChipManagerSprite(BYTE cbBetArea, LONGLONG lBetScore);

	//��ע��ʼ��Ϊ0
	void initGetChipManager();

	//��ʾ��ע
	void showTotalChipValue();
	//����
	void dissRemoveChuoValue();

private:
	cocos2d::Size WinSize;
	Sprite*   m_pSpriteNunber[8];     //��ע
	CCLabelAtlas* m_pTotalChipValue[8];  	//��ע����
	Array *ChipManagerArray;
	Sprite* m_pTotalChipsBG;
};

#endif
#ifndef __GAME_CARDMANAGER_H__
#define __GAME_CARDMANAGER_H__
#pragma once

/***************************************
 �ƹ�����
 ��Ϸ����

 ***************************************/

#include "cocos2d.h"
#include "CardSprite.h"
#include "CMD_BJL.h"//by hxh
#include "Tools.h"//by hxh
USING_NS_CC;
using namespace cocos2d;

// add by hxh 20160806
//#define USE_PRINTTEST3

struct PlayerCard
{
	//������е�������
	CardSprite* cards[3];
};

class CardManager : public cocos2d::Layer
{
public:
	virtual void onExit();//add by zengxin 20160921
	//��������
	static CardManager *create();
	void showPlayerCardfive();
	//��ʾ��ʾǰ������
	void showPlayerCard(); 
	//��ʾ����������
	void showPlayerCard1(BYTE m_cbTableCardArray[2][3],BYTE m_cbCardCount[2]);
	// ��ʾׯ�ҵ���������<by hxh>
	void showBankThirdCard(BYTE m_cbTableCardArray[2][3]);

	//��Ϸ����ˢ������
	void updatePlayerCard(int chairID,unsigned char bHandCardData[3]);
	//��������
	void SetHandCardData(unsigned char bHandCardData[]);
	//��������
	void SetHandCardData1(unsigned char bHandCardData1[]);

	//���ƶ���
	//(�мҵ�һ��)
	void SetAnmionPlayOneCard();
	//(ׯ�ҵ�һ��)
	void SetAnmionBankoneCard(Object* obj);
    //(�мҵڶ���)
	void SetAnmionPlayTwoCard(Object* obj);
	//ׯ�ҵڶ���
	void SetAnmionBankTwoCard(Object* obj);
	//�мҵ�����
	void  SendCardToPlayerRuntion(float loat);
	//ׯ�ҵ�����
	void  SendCardToBankThirdCard(float loat);
	// ������Ч<by hxh 20160729>
	void playSendCardSoundEffect();

	//////////////////////////////////////////////////////
	//��Ϸ�������÷���
	void resetManager();
	void HideCards();
	//���ÿ�Ƭ����
	void SetAnimation(Sprite * Sprite,int Number);

	void afterCatchPalyerUsed(Object *obj);//�м�
	void afterCatchBankUsed(Object *obj);//ׯ��

	void SetAnimationdoule(float loat){}

	//��ʾ�ټ��ֿ��ƽ�����棨�����Ŷ����� <by zengxin>
	void showGameOverWithNoAnim( BYTE m_cbTableCardArray[2][3],BYTE m_cbCardCount[2]);

public:

	//��ȡ��ֵ
	BYTE GetCardValue(BYTE cbCardData) { return cbCardData&LOGIC_MASK_VALUE; }
	//��ȡ��ɫ
	BYTE GetCardColor(BYTE cbCardData) { return cbCardData&LOGIC_MASK_COLOR; }

	//��ȡ�Ƶ�
	BYTE GetCardPip(BYTE cbCardData);
	//��ȡ�Ƶ�
	BYTE GetCardListPip(const BYTE cbCardData[], BYTE cbCardCount);

	Sprite *GAMEoverSprite;                        //��Ϸ����

	LabelTTF* PlayhomeTTf[8];    //8����ע����ı�ǩ<by hxh>
	LabelTTF* ScoreGameover;   //�ϼ���Ӯ<by hxh>
	LabelTTF* Xian;   //�е���<by hxh>
	LabelTTF* Zhuang; //ׯ����<by hxh>

	//������Ϸ��������ʱ��
	void showGameOver();
	void showGameOveAnmionTime(float dt);
	void remaggerDissGameOver();
	void SetScoreGameOver(LONGLONG lPlayScore,int Index, LONGLONG	lPlayAllScore);

private:
	//��ʼ������
	bool initCardManager();
	//��ʼ�������������
	void initPlayerCard();

	void SetPlayBankNumber();
public:
	PlayerCard        playerCard[8];  //�������
	unsigned char     m_ucHandCardData[3];
	unsigned char     m_ucHandCardData1[3];
	int m_ZXP;//ׯ��ƽ���<by hxh>
	//unsigned short    m_bPlayerStatus[8]; 

	Sprite *Player;  //�м�
	Sprite *Banker;  // ׯ��
	Sprite *AndBureauSprite;  //�;�
    Sprite *XianZhuangBg;  //��ׯ����<by hxh>
	// add by hxh 20160806
#ifdef USE_PRINTTEST3
	LabelTTF *Test;
	LabelTTF *Test2;
#endif
public:
	unsigned char     m_ucDeskCardData[5];
	bool FreehomeThirdCard;  //�м��Ƿ񷢵������� flase��ʾû�У�true��ʾ��
	cocos2d::Size Winsize;
	Sprite *m_pUserPlaySprite;  //�мҵ���
	Sprite *m_pUserBankSprite;  //ׯ�ҵ���

	BYTE cbBankerCount;	//�мҵ���(�����Ƶ�ʱ��)
	BYTE cbPlayerTwoCardCount;	//ׯ�ҵ���
	BYTE m_cbBankerCount;	//��ʾ�мҵ������ƣ������Ƶ�ʱ��

};

#endif  // __GAME_CARDMANAGER_H__
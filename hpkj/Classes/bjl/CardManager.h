#ifndef __GAME_CARDMANAGER_H__
#define __GAME_CARDMANAGER_H__
#pragma once

/***************************************
 �ƹ�����
 ��Ϸ����

 ***************************************/

#include "cocos2d.h"
#include "CardSprite.h"
#include "CMD_BJL.h"
#include "Tools.h"
USING_NS_CC;
using namespace cocos2d;


struct PlayerCard
{
	//������е�������
	CardSprite* cards[3];
};

class CardManager : public cocos2d::Layer
{
public:
	//��������
	static CardManager *create();
	void showPlayerCardfive();
	//��ʾ��ʾǰ������
	void showPlayerCard(); 
	//��ʾ����������
	void showPlayerCard1(BYTE m_cbTableCardArray[2][3],BYTE m_cbCardCount[2]);

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
	// ������Ч
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

	LabelTTF* PlayhomeTTf[8];    //8����ע����ı�ǩ
	LabelTTF* ScoreGameover;   //�ϼ���Ӯ
	LabelTTF* Xian;   //�е���
	LabelTTF* Zhuang; //ׯ����

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

	void SetPlayBankNumber(float flat);
public:
	CardSprite*       commonCards[5];	//���Ź�����
	PlayerCard        playerCard[8];  //�������
	unsigned char     m_ucHandCardData[3];
	unsigned char     m_ucHandCardData1[3];

	unsigned short    m_bPlayerStatus[8]; 

	Sprite *Player;  //�м�
	Sprite *Banker;  // ׯ��
	Sprite *AndBureauSprite;  //�;�
    Sprite *XianZhuangBg;  //��ׯ����
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

#endif
#ifndef _DZPKOperaLayer_H_
#define _DZPKOperaLayer_H_
#pragma once

/***************************************
 �������
 ��Ϸ����
 xxxx 2014.1.5
 ***************************************/

#include "cocos2d.h"
#include "CMD_DZPK.h"
#include "EntityMgr.h"
#include "RoomLayer.h"
#include "Tools.h"
#include "DZPKRaiseSlider.h"

USING_NS_CC;

// ���ڲ���<add by hxh 20161021>
//#define SHOW_BET_XZ_BTN

class DZPKLayer;//by hxh

class DZPKOperaLayer : public cocos2d::Layer
{
public:
	//��������
	static DZPKOperaLayer *create();  

	//��ť����<by hxh>
	enum {
		SPRITE_NUM=9,
		CKPX_BTN = 0,			//	�鿴����˵����ť
		CKPX_PIC=1,				//	�鿴����ͼ
		GRYZ_BTN=2,				//	������ע��ť
		CHECK_GP_BTN = 7,		//	���ư�ť
		CALL_GZ_BTN = 5,		//	��ע��ť
		RAISE_JZ_BTN = 6,		//	��ע��ť
		BET_XZ_BTN = 8,			//	��ע��ť
		FOLD_QP_BTN = 3,		//	���ư�ť
		ALLIN_QX_BTN = 4		//	ȫ�°�ť
	};

	// add by hxh 20161009
	void showBtn(int idx,bool visible);	

	//��ʾ�ұ����е�ѡ��ť(���������ťΪ��ע�ͼ�ע)
	void showDXGZJZBtns(int iGZ1GP2);
	//�����ұ����е�ѡ��ť
	void dismissDXBtns();
	//��ʾ��ע��
	void showRaiseSlider();
	//���ؼ�ע��
	void dismissRaiseSlider();

	// add by hxh 20160928
	DZPKLayer* getDZPKLayer();

	//	��ע������
	DZPKRaiseSlider* m_pRaiseSlider;

private:

	//��ʼ������
	bool initOperaLayer();
	//ִ�й�ѡ�Ĳ���
	void doGXOpera(float t);
	// add by hxh 20160921
	void SendAddScoreReq(LONGLONG lScore,int idx);
	//����¼��Ĵ���<by hxh>
	void onBtnBegan(int idx);
	void onBtnEnded(int idx);
	//����¼��ļ���
	bool onTouchBegan(Touch *pTouch, Event *pEvent);  
	void onTouchEnded(Touch *pTouch, Event *pEvent);   

	// add by hxh 20160919
	static const char * SPRITE_NAME(int idx){
		const char * s_szArr[SPRITE_NUM]={"�鿴����","�鿴����ͼƬ","���κ�ע","����","ȫ��","��ע","��ע","����","��ע"};
		const char * s=(idx>=0&&idx<SPRITE_NUM?s_szArr[idx]:"");
		return s;
	}

	//"1��","2��ע","3��ע","4��ע","5����","6ȫ��<add by hxh 20161009>
	static BYTE getJudgeAction(int idx){
		BYTE s_iArr[SPRITE_NUM]={0,0,2,5,6,2,3,1,4};
		BYTE i=(idx>=0&&idx<SPRITE_NUM?s_iArr[idx]:0);
		return i;
	}

	//��ťͼƬ��Դ<by hxh>
	static const char * getBtnTexName(int idx);
private:

	//��ť<by hxh>
	Sprite *m_pBTN[SPRITE_NUM];
#if 1
	//�鿴����˵����ť
	Sprite *m_pCKPX_BTN;
	//�鿴����ͼ
	Sprite *m_pCKPX_PIC;
	//������ע��ť
	Sprite *m_pGRYZ_BTN;
	//���ư�ť
	Sprite *m_pQP_BTN;
	//��ע��ť
	Sprite *m_pGZ_BTN;
	//��ע��ť
	Sprite *m_pJZ_BTN;
	//ȫ�°�ť
	Sprite *m_pQX_BTN;
	//���ư�ť
	Sprite *m_pGP_BTN;
	//��ע��ť
	Sprite *m_pXZ_BTN;
#endif	

	//������ע��ť�Ƿ��Ѱ���
	bool m_bGRYZ;

	//ȡ��עֵ������עֵ
	bool m_bGetRaiseInfo;

	//����Ϣ
	CMD_C_NULL cNull;

	//��ע��Ϣ
	CMD_C_AddScore m_addScore;
};

#endif  // __DZPKOperaLayer_H__
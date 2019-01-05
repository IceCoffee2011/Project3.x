#ifndef __CCTOUCHSPRITE_H__
#define __CCTOUCHSPRITE_H__

#include "cocos2d.h"
USING_NS_CC;

class CCTouchSprite : public Sprite
{
public:
	CCTouchSprite();
	~CCTouchSprite();

	static CCTouchSprite* createWithPic(const char *fileName, int row, int cell); //��̬�������ڴ��Զ��ͷţ�
	static CCTouchSprite* createWithPic(const char *fileName, int row, int cell, Object *rec, SEL_CallFuncN selector); //��̬�������ڴ��Զ��ͷţ�
	static CCTouchSprite* createWithSpriteFrame(SpriteFrame *pSpriteFrame,int row, int cell, Object *rec,SEL_CallFuncN selector);  //��̬�������ڴ��Զ��ͷţ�

	//void myInit();//�Զ����ʼ������
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);
	virtual void onTouchCancelled(Touch* pTouch, Event* pEvent);

	CC_SYNTHESIZE(int, rowIndex, RowIndex);//sprite�ڵڼ���
	
	CC_SYNTHESIZE(int, cellIndex, CellIndex);//sprite�ڵڼ���

private:
	//�ж��Ƿ�����ť
	bool isClickSprite(Touch* pTouch);
protected:
	SEL_CallFuncN c_pfnSelector;
	Object* m_pListener;
private:
	//�ж��Ƿ��ƶ�
	bool m_bMovedSprite;
	bool m_bDoubleClick;

};

#endif
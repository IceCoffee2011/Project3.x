//  [3/26/2014 xieyi]
#ifndef DDZ___SETTLEMENT__
#define DDZ___SETTLEMENT__
#include "cocos2d.h"
#include "BJLRes.h"
#include "DDZUser.h"
#include "CMD_DDZ.h"
#include "DDZCardTableLayer.h"
USING_NS_CC;

class DDZSettlement : public Layer
{
public:

	DDZSettlement();
	~DDZSettlement();
	static DDZSettlement* create(DDZCMD_S_GameEnd* sGameData, int nLandlordID);
	virtual bool init(DDZCMD_S_GameEnd* sGameData, int nLandlordID);

	bool onTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void onTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void onTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	void onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	void onClickBtnClose(Ref* pSender);

private:

	Sprite* m_pBG;	//����ͼƬ
	Sprite* m_pTitle;	//	����
	Sprite* m_pImgText;	//	��ʶ����

	Sprite* m_pImgPlayer[DDZGAME_PLAYER];	//	���ͷ������
	Label* m_pLabPlayerName[DDZGAME_PLAYER];	//	����ǳ�
	Label* m_pLabBomb[DDZGAME_PLAYER];	//	ը������
	Label* m_pLabOnceScore[DDZGAME_PLAYER];	//	���ε÷�����
	Label* m_pLabDiFen;	//	�׷�

};

#endif
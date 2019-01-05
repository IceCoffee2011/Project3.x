#ifndef __SGLY_GAME_LAYER_H__
#define __SGLY_GAME_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SGLYDefine.h"

USING_NS_CC;
using namespace ui;
using namespace std;

/*
**	@brief	ˮ����԰������Ϸ���ֲ�
*/
class SGLYGameLayer: public Layer
{
public:
	SGLYGameLayer();
	~SGLYGameLayer();
	CREATE_FUNC(SGLYGameLayer);

	//	����
	void reset();
	
	//	������ׯ״̬
	void setApplyState(E_SGLY_ApplyState eState);

	//	��ȡ����״̬
	E_SGLY_ApplyState getApplyState() const;

	/*
	**	@brief	����ĳ���������
	**	@nLotteryID		����ID
	**	@bIsHighLight	�Ƿ����
	*/	
	void setLotteryHighLight(int nLotteryID, bool bIsHighLight);

	/*
	**	@brief	���ý���1���������
	**	@nLotteryID		����ID
	**	@bIsHighLight	�Ƿ����
	*/	
	void setOnlyLotteryHighLight(int nLotteryID, bool bIsHighLight);

	/*
	**	@brief	�ر����н������
	*/	
	void closedLotteryHighLight();

	//	�л�ׯ�Ҷ���
	void showAniChangeBanker(int nChairID);

	//	չ�ֽ������ͱ���
	void showLotteryType(int nLotteryID);

	//	չ��GoodLuck���ͱ���
	void showGoodLuckType(E_SGLY_GoodLuckType eType);

	//	չ�ֲ´�С���
	void showGuessReslt(bool bIsWin);

	//	��ȡ�������
	Sprite* getLottery(int nLotteryID) const;

	//	������Ϸ�����׶��߼�
	void dealGameEnd();

	//	��ǰׯ������ID
	CC_SYNTHESIZE(int, m_wBankerChairID, BankerChairID);

	//	�������������
	vector<Node*> m_vSpecialMask;
private:
	bool init();

	void initUI();

	//	���䱶��ģʽ
	void changeMultipleMode(E_SGLY_BettingMode eType);

	//	�����ע��ť�¼�
	void onClickBtnBetEvent(Ref* pSender);

	//	����˳���ť�¼�
	void onClickBtnQuitEvent(Ref* pSender);

	//	������ð�ť�¼�
	void onClickBtnSettingEvent(Ref* pSender);

	//	���������밴ť�¼�
	void onClickBtnSupplyEvent(Ref* pSender);

	//	�����Ѻ��ť�¼�
	void onClickBtnBetContinueEvent(Ref* pSender);

	//	���ѺС��1-7����ť�¼�
	void onClickBtnBetSmallEvent(Ref* pSender);

	//	���Ѻ��8-14����ť�¼�
	void onClickBtnBetBigEvent(Ref* pSender);

	//	���������ť�¼�
	void onClickBtnMultipleEvent(Ref* pSender);

	//	�����ׯ�б�ť�¼�
	void onClickBtnApplyListEvent(Ref* pSender);

	//	���������ׯ��ť�¼�
	void onClickBtnApplyEvent(Ref* pSender);

	//	���ȡ�����밴ť�¼�
	void onClickBtnCancelEvent(Ref* pSender);

	//	�����Ҫ��ׯ��ť�¼�
	void onClickBtnDownEvent(Ref* pSender);

	//	����
	Sprite* m_pBG;

	//	����ͼ��
	Sprite* m_pIconLottery[SGLY_LOTTERY_COUNT];

	//	�������
	Sprite* m_pLotteryHighLight[SGLY_LOTTERY_COUNT];

	//	����ģʽ
	Button* m_pBtnMultiple[E_SGLY_BettingMode_Null];

	//	�˳���ť
	Button* m_pBtnQuit;

	//	���ð�ť
	Button* m_pBtnSetting;

	//	��ׯ�б�
	Button* m_pBtnApplyList;

	//	��ť�����������
	Button* m_pBtnSupplyChip;

	//	��ť������Ѻ
	Button* m_pBtnBetContinue;

	//	��ť����������ׯ
	Button* m_pBtnApply;

	//	��ť����ȡ������
	Button* m_pBtnCancel;

	//	��ť������Ҫ��ׯ
	Button* m_pBtnDown;

	//	 ������ʾ
	Sprite* m_pLotteryTips;

	//	 GoodLuck��ʾ
	Sprite* m_pGoodLuckTips;

	//	�´�С�����ʾ
	Sprite* m_pGuessResultTips;

	//	����״̬
	E_SGLY_ApplyState m_eApplyState;

	//	��ǰѺע����
	int m_nCurrBetMultiple;
};


#endif  // __SGLY_GAME_LAYER_H__
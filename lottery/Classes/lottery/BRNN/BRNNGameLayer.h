#ifndef __BRNN_GAME_LAYER_H__
#define __BRNN_GAME_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "BRNNBetArea.h"
#include "BRNNDefine.h"
#include "BRNNRes.h"
#include "Define.h"
#include "BRNNPokerCard.h"
#include "BRNNPopupApplyList.h"

USING_NS_CC;
using namespace std;
using namespace ui;

/*
**	@brief	����ţţ������Ϸ���ֲ�
*/
class BRNNGameLayer: public Layer
{
public:
	BRNNGameLayer();
	~BRNNGameLayer();
	CREATE_FUNC(BRNNGameLayer);

	//	����
	void resetGameLayer();
	
	/*
	**	@brief			���ƶ���
	**	@nIdx			������ʼ����
	**	@sCardData		��������
	**	@return			���ط��ƶ�����ʱ��
	*/
	float doAniSendCard(const int nIdx, const BYTE sCardData[][5]);

	/*
	**	@brief		��ע
	**	@eAreaType	�ֻ��˶������������
	**	@sValue		������ֵ
	*/
	void bet(E_BRNNBetAreaType eAreaType, SCORE sValue);

	/*
	**	@brief		��ȡ�����
	**	@eType	�ֻ��˶������������
	**	@return		����ָ�������ָ��
	*/
	BRNNBetArea* getTableArea(E_BRNNBetAreaType eType);

	//	�������
	void allocationChip(E_BRNNBetAreaType eAreaType, SCORE sValue);

	//	�л�ׯ�Ҷ���
	void showAniChangeBanker(int nChairID);

	//	���ó��밴ť�Ƿ�����ʹ��
	void setBtnChipEnable(E_BRNNChipType eType, bool bEnabled);

	//	�������г��밴ť�Ƿ�����ʹ��
	void setAllBtnChipEnable(bool bEnabled);

	//	������밴ťʹ��
	void checkoutEnabledBtnChip(SCORE sValue);

	//	������ׯ״̬
	void setApplyState(E_BRNNApplyState eState);

	//	��ȡ��ǰ��ׯ״̬
	E_BRNNApplyState getApplyState() const;

	//	����
	BRNNHandsCard* m_pHandCard[E_BRNN_PokerPos_NULL];

	//	��ע�����
	BRNNBetArea* m_pBetArea[E_BRNNBetArea_NULL];

private:
	bool init();
	void initUI();

	//	���㴥���¼�������ʼ
	bool onTouchBegan(Touch *touch, Event *unused_event);

	//	���㴥���¼������ƶ�
	void onTouchMoved(Touch *touch, Event *unused_event);

	//	���㴥���¼�����ȡ��
	void onTouchCancelled(Touch *touch, Event *unused_event);

	//	���㴥���¼���������
	void onTouchEnded(Touch *touch, Event *unused_event);

	//	��������¼�
	void onClickBTNChipEvent(Ref* pSender);

	//	����˳���Ϸ�¼�
	void onClickBTNQuitEvent();

	//	������ð�ť
	void onClickBTNSettingEvent();

	//	���·����ť
	void onClickBTNTravelEvent();

	//	�����ׯ�б��¼�
	void onClickBTNApplyListEvent();

	//	���������ׯ�¼�
	void onClickBTNApplyEvent();

	//	���ȡ�������¼�
	void onClickBTNCancelApplyEvent();

	//	�����Ҫ��ׯ�¼�
	void onClickBTNDownEvent();

	//	��Ϸ��������
	Sprite* m_pBG;

	//	��ť�����˳���Ϸ
	Button* m_pBTNQuit;

	//	��ť��������
	Button* m_pBTNSetting;

	//	��ť����·��
	Button* m_pBTNTravel;

	//	��ť������ׯ�б�
	Button* m_pBTNApplyList;

	//	��ť����������ׯ
	Button* m_pBTNApply;

	//	��ť����ȡ������
	Button* m_pBTNCancelApply;

	//	��ť������Ҫ��ׯ
	Button* m_pBTNDown;

	//	���밴ť
	Button* m_pBTNChip[E_BRNNChip_NULL];

	//	�����������
	Sprite* m_pChipHighLight[E_BRNNChip_NULL];

	//	��ǰѡ�г��������
	E_BRNNChipType m_eCurrChipType;

	//	����״̬
	E_BRNNApplyState m_eApplyState;
};


#endif  // __BRNN_GAME_LAYER_H__
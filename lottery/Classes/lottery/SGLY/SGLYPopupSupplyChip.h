#ifndef __SGLY_POPUP_SUPPLY_CHIP_H__
#define __SGLY_POPUP_SUPPLY_CHIP_H__

#include "cocos2d.h"
#include "BaseDialog.h"
#include "ui/CocosGUI.h"
#include "Define.h"

USING_NS_CC;
using namespace ui;
using namespace std;
/*
**	@brief	ˮ����԰����ʱ��
*/
class SGLYPopupSupplyChip: public BaseDialog
{
public:
	SGLYPopupSupplyChip();
	~SGLYPopupSupplyChip();
	CREATE_FUNC(SGLYPopupSupplyChip);

	//	�����Ƿ���ʾ����
	void setPopupVisible(bool bIsVisible);
private:
	bool init();
	void initUI();
	void initData();
	void update(float dt);

	//	��ʾ�һ���ʾ
	void showExchangeTips(const LONGLONG llGoldValue);
	
	//	�������100��ť�¼�
	void onClickBtnChip100Event(Ref* pSender);

	//	�������1000��ť�¼�
	void onClickBtnChip1000Event(Ref* pSender);

	//	�������10000��ť�¼�
	void onClickBtnChip10000Event(Ref* pSender);

	//	����������ť�¼�
	void onClickBtnChipMaxEvent(Ref* pSender);

	//	�����հ�ť�¼�
	void onClickBtnClearEvent(Ref* pSender);

	//	���ȷ����ť�¼�
	void onClickBtnOKEvent(Ref* pSender);

	//	���ȡ����ť�¼�
	void onClickBtnNOEvent(Ref* pSender);

	//	����
	Sprite* m_pBG;

	//	���밴ť����100
	Button* m_pBtnChip100;

	//	���밴ť����1000
	Button* m_pBtnChip1000;

	//	���밴ť����10000
	Button* m_pBtnChip10000;

	//	���밴ť�������
	Button* m_pBtnChipMax;

	//	��ť�������
	Button* m_pBtnClear;

	//	��ť����ȷ��
	Button* m_pBtnOK;

	//	��ť����ȡ��
	Button* m_pBtnNO;

	//	�ı���������
	Label* m_pLabDeclaration;

	//	�ı������������
	Label* m_pLabExchangeRate;

	//	�ı������һ�������ʾ
	Label* m_pLabTipsExchangeChip;

	//	�ı�����ʣ����
	Label* m_pLabSurplusGold;

	//	�ַ������桪������
	string m_sDeclaration;

	//	�ַ������桪���һ����ʸ�ʽ
	string m_sExchangeRateFormat;

	//	�ַ������桪���һ�������ʾ��ʽ
	string m_sTipsExchangeChipFormat;

	//	�ַ������桪��ʣ������ʾ��ʽ
	string m_sTipsSurplusGoldFormat;

	//	��ҳ�����
	LONGLONG m_llPlayerChipValue;

	//	����볡ʱ�����
	LONGLONG m_llPlayerGold;
};


#endif  // __SGLY_POPUP_SUPPLY_CHIP_H__
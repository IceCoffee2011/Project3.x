#ifndef __PPC_CONTROL_H__
#define __PPC_CONTROL_H__

#include "cocos2d.h"
#include "PPCRes.h"
#include "PPCTableArea.h"
#include "Define.h"
#include "ui/CocosGUI.h"
#include "Define.h"

USING_NS_CC;
using namespace ui;

//	��������������̨
class PPCControl: public Layer
{
public:
	PPCControl();
	~PPCControl();
	CREATE_FUNC(PPCControl);
	
	//	����
	void resetPPCControl();

	/*
	**	@brief		��ע
	**	@eAreaType	�ֻ��˶������������
	**	@sValue		������ֵ
	*/
	void bet(EPPCCarLogoType eAreaType, SCORE sValue);

	//	��ע����
	void showAniBet(EPPCCarLogoType eType);

	//	��ʾ�������
	void showAreaHighLight(EPPCCarLogoType eCarLogoType);

	/*
	**	@brief		��ȡ�����
	**	@eType		�ֻ��˶������������
	**	@return		����ָ�������ָ��
	*/
	PPCTableArea* getTableArea(EPPCCarLogoType eType);

	/*
	��ǰ�����Ѿ���ע�������ֳ�ÿ����ֵ�ĳ������չʾ
	*/
	void betAll(EPPCCarLogoType eAreaType, SCORE sValue);

	//	���ó��밴ť�Ƿ�����ʹ��
	void setBtnChipEnable(EPPCChipType eType, bool bEnabled);

	//	�������г��밴ť�Ƿ�����ʹ��
	void setAllBtnChipEnable(bool bEnabled);

	//	������밴ťʹ��
	void checkoutEnabledBtnChip(SCORE sValue);

	//	�Ƿ��н�
	bool isWinTheLotterys(EPPCCarLogoType eLotteryType);

private:
	bool init();
	void initData();
	void initUI();

	//	��������¼�
	void onClickChip(Ref* pSender);

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchCancelled(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);

	//	���������
	PPCTableArea* m_pTableArea[EPPCCarLogo_Null];

	//	���밴ť�����⻷
	Sprite* m_pChipHighLight[EPPCChip_Null];

	//	����
	Button* m_pBtnChip[EPPCChip_Null];

	//	��ǰѡ�г�������
	EPPCChipType m_eCurrChipType;

};


#endif  // __PPC_CONTROL_H__

#ifndef __PPC_GAME_LAYER_H__
#define __PPC_GAME_LAYER_H__

#include "cocos2d.h"
#include "PPCCarLogo.h"
#include "PPCProtocol.h"
#include "PPCTravel.h"
#include "ui/CocosGUI.h"
#include "PPCPopupApplyList.h"

using namespace ui;

//	��Ϸ��������
class PPCGameLayer: public Layer
{
public:
	PPCGameLayer();
	~PPCGameLayer();
	CREATE_FUNC(PPCGameLayer);

	//	����
	void resetGameLayer();

	//	��������logo
	void resetCarLogo();

	//	������ׯ״̬
	void setApplyState(EPPCApplyState eState);

	//	��ȡ��ǰ��ׯ״̬
	EPPCApplyState getApplyState();

	/*
	**	@brief		ֻ��ʾ��������logo������
					���������Ƿ�ͬʱ��ʾ������Ĭ�ϸ���ʱ����ʾ������
	**	@nIdx		����logo������
	**	@bShowCar	true����ʾ������false������������Ĭ��Ϊfalse
	*/
	void showSingleCarLogoHighLight(int nIdx, bool bShowCar = false);

	//	�л�ׯ�Ҷ���
	void showAniChangeBanker(int nChairID);

	//	����logo�б�
	map<int, PPCCarLogo*> m_mCarLogoList;

	//	·��
	PPCTravel* m_pTravel;

public:
	//�����Ϸ��¼
	void addGameRecord(EPPCCarLogoType eType);

private:
	bool init();

	void initUI();

	//	��ʼ������logo
	void initCarLogo();

	//	����˳��¼�
	void onClickBtnQuit();

	//	������ð�ť
	void onClickBtnSetting();

	//	�����ׯ�б��¼�
	void onClickBtnApplyList();

	//	���������ׯ�¼�
	void onClickBtnApply();

	//	���ȡ�������¼�
	void onClickBtnCancelApply();

	//	�����Ҫ��ׯ�¼�
	void onClickBtnDown();

	//	��ť�����˳�
	Button* m_pBtnQuit;

	//	��ť������ׯ�б�
	Button* m_pBtnApplyList;

	//	��ť����������ׯ
	Button* m_pBtnApply;

	//	��ť����ȡ������
	Button* m_pBtnCancelApply;

	//	��ť������Ҫ��ׯ
	Button* m_pBtnDown;

	//	����������
	Sprite* m_pPPCBG;

	//	������ׯ״̬
	EPPCApplyState m_eApplyState;

};

#endif  // __PPC_GAME_LAYER_H__
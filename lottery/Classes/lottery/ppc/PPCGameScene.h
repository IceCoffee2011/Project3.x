#ifndef __PPC_GAME_SCENE_H__
#define __PPC_GAME_SCENE_H__

#include "cocos2d.h"
#include "PPCGameLayer.h"
#include "PPCGameMessage.h"
#include "PPCControl.h"
#include "PPCInfoBar.h"
#include "PPCClock.h"
#include "ToolKit.h"
#include "PPCEnding.h"
#include "PPCPopupApplyList.h"

//	��Ϸ����
class PPCGameScene: public Scene
{
public:
	PPCGameScene();
	~PPCGameScene();
	CREATE_FUNC(PPCGameScene);

	//	����
	void resetGameScene();

	//	��Ϸ��������
	PPCGameLayer* m_pPPCGameLayer;

	//	����̨
	PPCControl* m_pPPCControl;

	//	��Ϣ��
	PPCInfoBar* m_pPPCInfoBar;

	//	ʱ��
	PPCClock* m_pPPCClock;

	//	��ׯ�б��
	PPCPopupApplyList* m_pApplyListView;

	//	��Ϸ�����
	PPCEnding* m_pPPCEnding;

	//	��Ϣ�����
	PPCGameMessage* m_pPPCGameMessage;

public:
	EPPCProcessType m_GameStatue;//��Ϸ״̬

	//	���������������н����
	SCORE m_lApplyBankerCondition;

private:
	bool init();
	void initUI();
	void onEnter();

	//	Ԥ������Դ
	void addRes();

};

#endif  // __PPC_GAME_SCENE_H__
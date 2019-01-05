#ifndef __BRNN_GAME_SCENE_H__
#define __BRNN_GAME_SCENE_H__

#include "cocos2d.h"
#include "BRNNDefine.h"
#include "BRNNGameMessage.h"
#include "BRNNGameLayer.h"
#include "BRNNClock.h"
#include "BRNNInfoBar.h"
#include "BRNNSettlement.h"
#include "BRNNPopupApplyList.h"
#include "BRNNPopupTravel.h"
#include "BRNNPopupSetting.h"

USING_NS_CC;

/*
**	@brief	����ţţ������Ϸ����
*/
class BRNNGameScene: public Scene
{
public:
	BRNNGameScene();
	~BRNNGameScene();
	CREATE_FUNC(BRNNGameScene);

	//	��ȡ��ǰ��Ϸ����
	static BRNNGameScene* getBRNNGameScene();

	//	Ԥ������Դ
	void preLoadRes();

	//	�������
	void clear();

	//	������Ϸ����
	void resetGameScene();

	//	��Ϸ���ֲ�
	BRNNGameLayer* m_pGameLayer;

	//	��Ϣ��
	BRNNInfoBar* m_pInfoBar;

	//	ʱ��
	BRNNClock* m_pClock;

	//	�������
	BRNNSettlement* m_pSettlement;

 	//	��ׯ�б�
	BRNNPopupApplyList* m_pPopupApplyList;

	//	·��
	BRNNPopupTravel* m_pPopupTravel;

	//	����
	BRNNPopupSetting* m_pPopupSetting;

	//	ͨѶ��Ϣ��
	BRNNGameMessage* m_pGameMessage;

	//��Ϸ״̬
	E_BRNNProcessType m_eGameStatue;

private:
	bool init();
	void initUI();
	void onEnter();
};

#endif  // __BRNN_GAME_SCENE_H__
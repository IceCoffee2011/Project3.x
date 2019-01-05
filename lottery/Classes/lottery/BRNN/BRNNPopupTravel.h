#ifndef __BRNN_POPUP_TRAVEL_H__
#define __BRNN_POPUP_TRAVEL_H__

#include "cocos2d.h"
#include "GlobalDef.h"
#include "ui/CocosGUI.h"
#include "BRNNProtocol.h"

USING_NS_CC;
using namespace ui;

/*
**	@brief	����ţţ����·��
*/
class BRNNPopupTravel: public Layer
{
public:
	BRNNPopupTravel();
	~BRNNPopupTravel();
	CREATE_FUNC(BRNNPopupTravel);

	//	�������
	void addListItem(BRNN_tagServerGameRecord sData);

	//	��ȡ·���б�������
	int getItemCount();

	//	���õ����Ƿ���ʾ
	void setPopupVisible(bool bIsVisible);

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

	//	����
	Sprite* m_pBG;

	//	�б���ͼ
	ListView* m_pListView;

	//	�б���������
	map<int, Widget*> m_mItemArray;
};

#endif  // __BRNN_POPUP_TRAVEL_H__
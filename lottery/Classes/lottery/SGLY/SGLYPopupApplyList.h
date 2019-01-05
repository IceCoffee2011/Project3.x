#ifndef __SGLY_POPUP_APPLY_LIST_H__
#define __SGLY_POPUP_APPLY_LIST_H__

#include "cocos2d.h"
#include "GlobalDef.h"
#include "ui/CocosGUI.h"
#include "SGLYProtocol.h"
#include "BaseDialog.h"

USING_NS_CC;
using namespace std;
using namespace ui;

/*
**	@brief	ˮ����԰������ׯ�б�
*/
class SGLYPopupApplyList: public BaseDialog
{
public:
	SGLYPopupApplyList();
	~SGLYPopupApplyList();
	CREATE_FUNC(SGLYPopupApplyList);

	//	ˢ���б�
	void updateListView();

	//	���õ����Ƿ���ʾ
	void setPopupVisible(bool bIsVisible);

	//	����б���
	void addListItem(SGLY_tagBankerListPlayer sBankerData);

	//	����б�����
	Widget* getListItem(int nChairID);

	//	ɾ���б���
	void removeListItem(int nChairID);

	//	ɾ�������б���
	void removeAllListItem();

	//	�ж��б����Ƿ����
	bool isItemExist(int nChairID);
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

	//	�ı���������
	Sprite* m_pTextTitle;

	//	�ı������ǳ�
	Sprite* m_pTextNickname;

	//	�ı���������
	Sprite* m_pTextChip;

	//	�б���ͼ
	ListView* m_pListView;

	//	�б���������
	map<int, Widget*> m_mItemArray;

};

#endif  // __SGLY_POPUP_APPLY_LIST_H__
#ifndef __BRNN_POPUP_APPLY_LIST_H__
#define __BRNN_POPUP_APPLY_LIST_H__

#include "cocos2d.h"
#include "GlobalDef.h"
#include "ui/CocosGUI.h"
#include "BRNNProtocol.h"

USING_NS_CC;
using namespace std;
using namespace ui;

/*
**	@brief	����ţţ������ׯ�б�
*/
class BRNNPopupApplyList: public Layer
{
public:
	BRNNPopupApplyList();
	~BRNNPopupApplyList();
	CREATE_FUNC(BRNNPopupApplyList);

	//	ˢ���б�
	void updateListView();

	//	���õ����Ƿ���ʾ
	void setPopupVisible(bool bIsVisible);

	//	����б���
	void addListItem(int nChairID);

	//	����б���
	void addListItem(BRNN_tagBankerListPlayer sBankerData);

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

	//	���⡪��ͷ��
	Sprite* m_pTitleFace;

	//	���⡪���ǳ�
	Sprite* m_pTitleNickname;

	//	���⡪�����
	Sprite* m_pTitleGold;

	//	�б���ͼ
	ListView* m_pListView;

	//	�б���������
	map<int, Widget*> m_mItemArray;

};

#endif  // __BRNN_POPUP_APPLY_LIST_H__
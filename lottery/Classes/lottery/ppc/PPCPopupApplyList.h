#ifndef __PPC_POPUP_APPLY_LIST_H__
#define __PPC_POPUP_APPLY_LIST_H__

#include "cocos2d.h"
#include "BaseDialog.h"
#include "PPCEnum.h"
#include "PPCRes.h"
#include "PPCProtocol.h"
#include "GlobalDef.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace std;
using namespace ui;

//	������������װ�б�
class PPCPopupApplyList: public Layer
{
public:
	PPCPopupApplyList();
	~PPCPopupApplyList();
	CREATE_FUNC(PPCPopupApplyList);

	//	ˢ���б�
	void updateListView();

	//	����б���
	void addListItem(int nChairID);

	//	����б���
	void addListItem(ppcTagBankerListPlayer sBankerData);

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

	//	����رհ�ť
	void onClickBtnClosed(Ref* pSender);

	//	����
	Sprite* m_pBG;

	//	�رհ�ť
	ui::Button* m_pClosed;

	//	�б���ͼ
	ui::ListView* m_pListView;

	//	�б���������
	map<int, Widget*> m_mItemArray;

};

#endif  // __PPC_POPUP_APPLY_LIST_H__
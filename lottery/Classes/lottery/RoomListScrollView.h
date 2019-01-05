#ifndef __RoomListScrollView__
#define __RoomListScrollView__
#include "struct.h"//by hxh
#include "CocosUnits.h"
#include "ConfigMgr.h"
#include "AnsString.h"
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"


USING_NS_CC;
USING_NS_CC_EXT;
//using namespace ui;

class RoomListScrollView : public Layer,TableViewDataSource,TableViewDelegate 
{
    
public:
    RoomListScrollView();
    ~RoomListScrollView();
    virtual bool init(int idx);
    //CREATE_FUNC(RoomListScrollView);
	static RoomListScrollView* create(int idx)
	{
		RoomListScrollView *pRet = new RoomListScrollView();
		if (pRet && pRet->init(idx))
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = nullptr;
			return nullptr;
		}
	}

	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view);
	virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view);

	//�����¼� ������ǵ�������Ǹ���ҳ
	virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
	//ÿһ��ĸ߶ȺͿ��
	virtual cocos2d::Size cellSizeForTable(cocos2d::extension::TableView *table);
	//�����б��ÿһ������
	virtual TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
	//һ��������
	virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);

public:
    void onEnter();
    void onExit();
    bool onTouchBegan(Touch *pTouch, Event *pEvent);
    void onTouchMoved(Touch *pTouch, Event *pEvent);
    void onTouchEnded(Touch *pTouch, Event *pEvent);
    void onTouchCancelled(Touch *pTouch, Event *pEvent);

private:
	int m_Count;	//�ܸ���
	int m_length;	//һ�ж��ٸ�
	int m_itemHeigth;	
	int m_itemWidth;
	int m_pandingX;		//x ���
	int m_pandingY;

	TableView* m_table;
public:
	int m_idx;
	vector<tagGameServer> m_RoomList;
};
#endif  //__RoomListScrollView__
#ifndef _SCROLLADD_H_
#define _SCROLLADD_H_

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class ScrollAdd: public Layer,TableViewDataSource,TableViewDelegate 
{
public:

	ScrollAdd();
	~ScrollAdd();
	virtual bool init();
	CREATE_FUNC(ScrollAdd);

	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);

	virtual void scrollViewDidScroll(ScrollView* view);
	virtual void scrollViewDidZoom(ScrollView* view);

	//�����¼� ������ǵ�������Ǹ���ҳ
	virtual void tableCellTouched(TableView* table, TableViewCell* cell);
	//ÿһ��ĸ߶ȺͿ��
	virtual cocos2d::Size cellSizeForTable(TableView *table);
	//�����б��ÿһ������
	virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
	//һ��������
	virtual ssize_t numberOfCellsInTableView(TableView *table);

	void onEnter();
	void onExit();
private:

	TableView* pView;
	cocos2d::Vector<String *> pData;
	Sprite* pSprite;

	Vec2 m_start_pos;
	int m_cur_index;

	void initData();
	void initView();

	void changeFrame(bool isLeft);
	void refresh(float delta);
};


#endif //_SCROLLADD_H_
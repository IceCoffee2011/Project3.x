#ifndef __TABLE_VIEW_LAYER__
#define __TABLE_VIEW_LAYER__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TableViewLayer : public Layer,TableViewDataSource,TableViewDelegate 
{
public:
	virtual bool init();

	static Scene* scene();
	static TableViewLayer* tableViewLayerWith1();

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

	virtual cocos2d::Size tableCellSizeForIndex(TableView *table, ssize_t idx) {
		return cellSizeForTable(table);
	} 

	CREATE_FUNC(TableViewLayer);
protected:
private:
	void spriteClickCallBack(Node* pNode);
};

#endif //__TABLE_VIEW_LAYER__
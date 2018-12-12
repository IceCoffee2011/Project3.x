#ifndef __Game__RankSystemLayer__
#define __Game__RankSystemLayer__

#include "TabLayer.h"
#include "cocos-ext.h"
#include "cocos2d.h"
#include "network/HttpClient.h"

USING_NS_CC;
USING_NS_CC_EXT;

enum RankTableTag
{
	RankTableTag_Rich,
	RankTableTag_Hero,
	RankTableTag_Luck,
	RankTableTag_Teacher,
	RankTableTag_Charm
};

class RankSystemLayer : public TabLayer,public TableViewDelegate,
	public TableViewDataSource
{

private:
	bool flag;
	cocos2d::Size winSize;
	cocos2d::Size tableItemSize;
	Sprite *myRankBk;							//�ҵ����б���ͼ
	LabelTTF *myRankLabel1;					//�ҵ�������
	LabelTTF *myRankLabel2;					//�ҵ�����ֵ
	Sprite *rankBk;							//�����Ϸ�ͼƬ

	LabelTTF *myRankFieldLabel1;					//�����ֶ�1
	LabelTTF *myRankFieldLabel2;					//�����ֶ�2
	LabelTTF *myRankFieldLabel3;					//�����ֶ�3
	LabelTTF *myRankFieldLabel4;					//�����ֶ�4
	
	//�Ƹ���
	string richRankText;
	TableView *richTable;
	//Ӣ�۰�
	string heroRankText;
	TableView *heroTable;
	//���˰�
	string luckRankText;
	TableView *luckTable;
	//��ʦ��
	string teacherRankText;
	TableView *teacherTable;
	//������
	string charmRankText;
	TableView *charmTable;
private:
	void initView();
public:
	RankSystemLayer();
	~RankSystemLayer();
	void OnExit();
	static RankSystemLayer *create();
	static RankSystemLayer *createWithTabItems(Array *itemNormalName, Array *itemSelectedName);

	virtual void doSomethingBeforeClosed();
	virtual void doSomething();
	void setMyRankText(string text, RankTableTag tag);
	void reloadData(RankTableTag tag);
	void sendButton(Object *obj);
	void deleteButton(Object *obj);
	void chatButton(Object *obj);
	void pressAddButton(Object *obj);

	virtual void tableCellTouched(TableView* table, TableViewCell* cell);
	virtual cocos2d::Size cellSizeForTable(TableView *table);
	virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(TableView *table);
	virtual void scrollViewDidScroll(ScrollView* view);
	virtual void scrollViewDidZoom(ScrollView* view);

};

class RankTableHelper: public Object, public TableViewDelegate,
	public TableViewDataSource
{ 
private:
	RankSystemLayer *father;
	cocos2d::Size winSize;
	cocos2d::Size tableItemSize;
	int itemsNum;
	RankTableTag tableTag;
	string url;
	Array *nicknameArray;
	Array *field4ValueArray;
	network::HttpClient* httpClient;
	bool cancelOrNot;
public:
	RankTableHelper(RankSystemLayer *fath, int num, RankTableTag tag);
	~RankTableHelper();
	void cancelHttpRequest(Object *obj);
	void onHttpRequestCompleted(Node *sender, void *data);
	void addTableData(string nickname, string field4);
	virtual void tableCellTouched(TableView* table, TableViewCell* cell);
	virtual cocos2d::Size cellSizeForTable(TableView *table);
	virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(TableView *table);
	virtual void scrollViewDidScroll(ScrollView* view);
	virtual void scrollViewDidZoom(ScrollView* view);
};

#endif  //__Game__WarningLayler__
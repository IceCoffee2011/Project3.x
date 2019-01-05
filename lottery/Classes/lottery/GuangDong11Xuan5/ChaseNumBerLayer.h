#ifndef _ChaseNumBerLayer_H
#define _ChaseNumBerLayer_H

#include "cocos2d.h"
#include "cocos-ext.h"
#include <string>
#include "GuangDong11Xuan5WuFen.h"
#include "Define.h"
#include "LotteryGlobal.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
enum ChaseNutagType
{ 
	ChaseNuZhuiHaowuTag = 0,                                   //
	ChaseNuZhuiHaoShiwuTag,
	ChaseNuZhuiHaoerShiTag,
	ChaseNuZhuiHaoerShiwuTag,                                           //
};
class ChaseNumBerLayer : public Layer, public TableViewDelegate,
	public TableViewDataSource, public EditBoxDelegate
{
public:
	ChaseNumBerLayer();
	~ChaseNumBerLayer();
	CREATE_FUNC(ChaseNumBerLayer);
	virtual bool init();
	static Scene* scene();
	virtual void onEnter();
	virtual void onExit();
	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);	
	virtual void tableCellTouched(TableView* table, TableViewCell* cell);
	virtual cocos2d::Size cellSizeForTable(TableView *table);
	virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(TableView *table);
	virtual void scrollViewDidScroll(ScrollView* view);
	virtual void scrollViewDidZoom(ScrollView* view);	

	virtual void editBoxEditingDidBegin(EditBox* editBox){};
	virtual void editBoxEditingDidEnd(EditBox* editBox);
	virtual void editBoxTextChanged(EditBox* editBox, const std::string& text) {};
	virtual void editBoxReturn(EditBox* editBox){};
private:
	void initData();
	void initView();		
	//top menu
	void back(Object *obj);
	void setting(Object* obj);
	//transaction menu
	void recharge(Object *obj);
	void withdraw(Object* obj);
	//record menu
	void betRecord(Object *obj);
	void touZhuContinueRet(Object *obj);
	void ZhuiHaoQiShuRecord(Object *obj);
	void contiRecord(Object *obj);
	void changeKind(Object *obj);//
	void XuanZeQiShu(Object *obj);
	void IsEndeBeiTou(Object *obj);
	void IsEndeZhuiHao(Object *obj);
	void XuanZeZhuiHaoQiShu(Object *obj);
	void TouZhuZhuiHaoButton(Object *obj);
	void ZhuiHaoCloseButton(Object *obj);
	void ShowZhuiHaoMen();
	void dissZhuiHaoMen();

	void IsFendanHourRet(Object *obj);

	cocos2d::Size winSize;
	TableView *touZhuTable;
	//������¼
	EditBox *tempItemInpu;
	LabelTTF *gameTypeLabel;
	LabelTTF *gameKindLabel;
	LabelTTF *qiShuLabel;
	LabelTTF *haoMaLabel;
	LabelTTF *timeLabel;
	LabelTTF *TouZhuJinEChaseNumBerLabel;
	Sprite *gap1;
	LabelTTF *gameTypeLabe2;
	LabelTTF *gameKindLabe2;
	LabelTTF *qiShuLabe2;
	LabelTTF *haoMaLabe2;
	LabelTTF *timeLabe2;
	LabelTTF *tempIttf;
	Sprite *gap2;
	EditBox *beilvInput;
	EditBox *CtratebeilvInput;
	MenuItemSprite *XuanZeQiShuItem;
	MenuItemSprite *StramItem;
	MenuItemSprite *CloseItem;
	MenuItemSprite *betRecordItem;
	MenuItemSprite *GetRecordItem;
	MenuItemSprite *ButtonCodeRecordItem;
	Menu *pCloseButton;
	Menu *recordMenu;
	Menu *recordMenu2;
	Menu *middleMenu;
	Menu *StramMenu2;
	Menu *ZhuiHaoQiShuQiShMenu;
	bool ZhuiHaoQiShuBool;
	bool ZhuiHao11Xuan5KIsShowQiShu;
	int ZhuiHaoBool;  //�н����Ƿ�ֹͣ׷�ţ�0�� 1��
	int BeiTouBool;   //�Ƿ�Ͷ��1���ڱ�Ͷ 0��
	int zhuiHaoQiShu;  //׷������
	float cellHeight;
	int BaoCunQiShu;  //����ѡ������
	int Mkind;
	float nMoshiNumber;
	float TouZhuJinENumber;
	int betZhuiHaoZhuShu;
	int nMoshi;
	int ZhuiHao;
	int QuanJunBeiShu;   //���浱ǰ���õı�������Ϊȫ�ֱ���
	DWORD GDselectedItemTagNumber;  //��ǰ����
	BYTE chaseStatus[MAX_QIHAO];			//��ѡ���״̬��0λδѡ�У�1Ϊѡ��,Ĭ��Ϊ0
	int chaseInputStatus[MAX_QIHAO];    //������ֵ	Ĭ��Ϊ1
	float chaseInputMonreny[MAX_QIHAO];    //��Ǯ��ֵ	Ĭ��Ϊ1
	bool ZhuiHaoBeiShu;
	Integer *gameKyTe;            //��Ʊ����
	Integer *gameKind;            //��Ϸ����
	Integer *betZhuShu;           //ע��
	Integer *nMoshiteger;         //ģʽ
	Float *ZhangHuYuENumber;      //�˻����
	String *betNumber;            //��Ʊ����
	    /**********/
    Node *m_TableNode;
    Sprite *fandianTableBk;
    TableView *fandianTable;
    cocos2d::Size tableViewSize;
    float tableCellWidth;
    float tableCellHeight;
    float tableCellNum;
    int fandianStatus;              //0��1��2�ֱ��ʾ���ɼ���������ñ��������ñ�����Ĭ��Ϊ0

};

#endif // __HELLOWORLD_SCENE_H__
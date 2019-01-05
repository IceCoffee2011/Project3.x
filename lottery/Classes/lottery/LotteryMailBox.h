#ifndef __LotteryMailBox__
#define __LotteryMailBox__
#include "cocos2d.h"
#include "cocos-ext.h"
#include <string>
#include "Define.h"
#include "BaseLayer.h"

USING_NS_CC_EXT;
USING_NS_CC;
using namespace std;

class LotteryMailBox: public Layer, public TableViewDelegate,
	public TableViewDataSource
{
public:
	LotteryMailBox();
	~LotteryMailBox();
	CREATE_FUNC(LotteryMailBox);
	virtual bool init();
	static Scene* scene();
	virtual void onEnter();
	virtual void onExit();
	virtual void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);	

	virtual void tableCellTouched(TableView* table, TableViewCell* cell);
	virtual cocos2d::Size cellSizeForTable(TableView *table);
	virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(TableView *table);
	virtual void scrollViewDidScroll(extension::ScrollView* view);
	virtual void scrollViewDidZoom(extension::ScrollView* view);	

	//ˢ��
	void refreshLayer();

	void displayIndex(const int index);
private:
	void initData();
	void initView();		
	//top menu
	void back(Object *obj);
	void toNotice(Object *obj);
	void toMail(Object *obj);
	//
	void toInbox(Object *obj);
	void toOutBox(Object *obj);
	void toSendBox(Object *obj);

	//��һҳ��һҳ
	void toPre(Object *obj);
	void toNext(Object *obj);

	//ɾ���ظ�
	void toDel(Object *obj);
	void toReply(Object *obj);

	void getInboxMessageRet(Object *obj);
	void chkInboxMessageRet(Object *obj);
	void getXJUserInfoRet(Object *obj);
	void sendMessageRet(Object *obj);
	void getMessageCountRet(Object *obj);
	void deleteMessageRet(Object *obj);

	//���淵��
	//void getNoticeRet(Object *obj);

	const char* getUtfString(const char* tempStr);

	//��ѯվ����
	void queryMessageBox();
	//��ѯ�� ģ������
	void queryMember(const char* name = "");

	//��ʾ�¼�
	void showSubMember();
	//��ʾ�ռ���
	void showSendMember();
	//��ʾ����
	void showSendTopic();

	//ˢ��layer
	void refreshList(Layer *lyScl);

	void selectButton(Object *obj);

	cocos2d::Size winSize;
	string username;
	DOUBLE money;
	float cellHeight;
	float cellNum;
	TableView *userInfoTable;

	//�б�����
	int row_count;
	Array* m_arrContent;

	//��ѯ�������
	int m_iBoxType;
	int m_iPage;
	int m_iPageCount;
	int m_iPageNum;
	int m_iCurRow;
	//�ϼ�
	int m_top_id;
	int m_user_page_count;
	int m_user_page_cur;

	bool m_isPosting;
	//���������
	int m_iCurRevType;

	//�������¼�������ʾ ��һ�������б����� �����޸�Ϊ�洢�������������Ϣ
	cocos2d::Vector<Dictionary *> vec_NameId;

	//���� ��Ϊ����һ�λ�ȡ��  ����б���������浱ǰ���ص�ֵ
	Array* m_arrUserInfo;

	//���ʹ���
	int m_i_sendtimes;
};

#endif
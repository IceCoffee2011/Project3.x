//  [4/8/2014 xieyi]
#ifndef DDZ___DIALOGLAYER__
#define DDZ___DIALOGLAYER__
#include "cocos2d.h"
#include "DDZRes.h"
#include <limits>
#include "ui/CocosGUI.h"

USING_NS_CC;

enum DDZdialog_type
{
	DDZdialog_hints = 1,//��������
	DDZdialog_back,//����
	DDZdialog_poChan,//�Ʋ�
	DDZdialog_poChanSongCoin,//�Ʋ��ͽ��
	DDZdialog_dismissTable,//��ɢ����
	DDZdialog_roomLimitMin,//��������
	DDZdialog_roomLimitMax,//��������
	DDZdialog_ChangeTableFailed,	//	����ʧ��
	DDZdialog_Reject,	//	�޳����
	DDZdialog_Other_Login,	//	��ص�¼
};


class DDZDialogLayer : public Layer
{

public:
	DDZDialogLayer(DDZdialog_type type);
	~DDZDialogLayer();
	virtual bool init();
	virtual bool onTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	static DDZDialogLayer * create(DDZdialog_type type);
	DDZdialog_type m_type;
	virtual void onEnter();
	virtual void onExit();
	//	������ʾ������
	void setTipsString(const std::string sText);

private:
	//	��ť����ȷ��
	ui::Button* m_pBtnOK;	

	//	��ť����ȡ��
	ui::Button* m_pBtnCancel;

	//	��ʾ��
	LabelTTF * m_pLabTips;

	//	���ȷ����ť�¼�
	void onClickBtnOK(Ref* pSender);

	//	���ȡ����ť�¼�
	void onClickBtnCancel(Ref* pSender);

	void initTable(const string sName,int type);		//--1Ϊֻ��ȷ����2Ϊȷ����ȡ��
};

#endif
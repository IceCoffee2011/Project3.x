#ifndef __GAME_FC3D_PL3_H__
#define __GAME_FC3D_PL3_H__
#include "FC3DPL3BetArea.h"
#include "cocos2d.h"
#include "cocos-ext.h"

#define AREA_BALL_TAG1			0
#define AREA_BALL_TAG2			20
#define AREA_BALL_TAG3			40
#define AREA_BALL_TAG4			60
#define AREA_BALL_TAG5			80
#define AREA_MENU_TAG1			200
#define AREA_MENU_TAG2			220
#define AREA_MENU_TAG3			240
#define AREA_MENU_TAG4			260
#define AREA_MENU_TAG5			280
#define AREA_GAP				AREA_BALL_TAG2-AREA_BALL_TAG1
#define INVALID_TAG				-100
#define BALL_NUM				10

USING_NS_CC;
USING_NS_CC_EXT;

class FC3DPL3WuFen : public FC3DPL3BetArea, public EditBoxDelegate
{

public:
	FC3DPL3WuFen();
	~FC3DPL3WuFen();
	virtual bool init();
	static Scene* scene();
	void pressKindButton(int tag);
	CREATE_FUNC(FC3DPL3WuFen);

	void onEnter();
	void onExit();
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void onTouchMoved(Touch *pTouch, Event *pEvent);
	void onTouchEnded(Touch *pTouch, Event *pEvent);
	void onTouchCancelled(Touch *pTouch, Event *pEvent);
	virtual String *getBetNumber();
	virtual void createRandomNumbers();
	virtual void clearNumbers();
	void clearNumbers(int area);
	void cancelAllMenuSelect();
	virtual void setBetKind(ThreeNumbersKind kind);

	virtual void editBoxEditingDidBegin(EditBox* editBox);
	virtual void editBoxEditingDidEnd(EditBox* editBox);
	virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);
	virtual void editBoxReturn(EditBox* editBox){};
private:
	int areaNum;
	Node *m_node;
	float m_start;
	float m_end;
	//Vec2 m_endPos;
	Vec2 startPoint;
	Vec2 endPoint;
	Vec2 pt;
	float areaTitleXDelta;
	int m_num;
	int m_repeat;	
	std::string m_betString;
	std::string m_inputString;

	//����
	std::vector<Vec2>  m_vecPot;
	bool m_bDrag;
private:
	void initDanshiArea();
	void initWArea(const char *titleXmlIndex);
	void initQArea(const char *titleXmlIndex);
	void initBArea(const char *titleXmlIndex);
	void initSArea(const char *titleXmlIndex);
	void initGWArea(const char *titleXmlIndex);
	void initBalls(Vec2 startPos, int startTag);
	void initDXDS(Vec2 startPos, int startTag);		//��ʼ����С��˫
	void initHeZhiBalls(Vec2 startPos, int startTag);
	void initMenu(Vec2 menuPos, int startTag);
	void pressBig(Object *obj);
	void pressLittle(Object *obj);
	void pressAll(Object *obj);
	void pressSingle(Object *obj);
	void pressDouble(Object *obj);
	void pressClear(Object *obj);
	void cancelMenuSelect(int itemTag);

	//��ѡ���
	void createZuXuanRandomNumbers(int area, int num);
	void createRenXuanRandomNumbers();
	void createQianEr_ZuXuanRandomNumbers();
	void createQianSan_ZuXuanRandomNumbers();
	 virtual void onAcceleration(Acceleration* acc, Event* unused_event);

    int ballStatus[5][10];
    int menuStatus[5][6]; 
    int areaStatus[5];
public:

	//��ȡͶע����
	String* getGuanJunBetNumber();		//ǰ1
	String* getGuanYaJunBetNumber();		//ǰ2
	String* getQianSanBetNumber();		//ǰ3
	String* getHouYiBetNumber();			//��1
	String* getHouErBetNumber();			//��2
	String* getDingWeiDanBetNumber();		//��λ��
	String* getDaXiaoDanShuangBetNumber();	//��С��˫
	String* getGuanYaHeZhiBetNumber();		//��ֵ
	String* getQianEr_ZuXuanBetNumber();		//ǰ2��ѡ
	String* getQianSan_ZuXuanBetNumber(int nAmount);		//ǰ3��ѡ
	String* getBuDingWeiBetNumber();			//����λ
	//����
	String *getDanShiBetNumber();	
	void setDanShiCount();
	//��ʽ���
	void createDanShiRandomNumber();
};
#endif  //__Game__HelpScrollView__
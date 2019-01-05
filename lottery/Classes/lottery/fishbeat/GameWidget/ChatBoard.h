
#pragma once

#include "cocos2d.h"
#include "ui/UILayout.h"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"

class ChatBoard : public cocos2d::Layer
{
public:
	enum CHAT_MODE
	{
		CHAT_WORD,
		CHAT_GROUP,
		CHAT_WISPER,

	};
public:
	ChatBoard();
	~ChatBoard();

	CREATE_FUNC(ChatBoard);

	virtual bool init();

	void SpreadBoard();


	bool _isSpread;

	CC_SYNTHESIZE(cocos2d::Size, m_PanelSize, PanelSize);
protected:

	void testRecoverWord();

	void SetLayerTouchEnable(bool var);

private:
	void loadUIFromJson();
	
	void onCtrlBtn(cocos2d::Ref* sender,cocos2d::ui::TouchEventType type);
	
	void onSwitchList(cocos2d::Ref* sender,cocos2d::ui::TouchEventType type);
	
	void onSendMsg(cocos2d::Ref* sender,cocos2d::ui::TouchEventType type);
	void SendMessage();//�Լ�������Ϣ

	std::string WrapStr(std::string str, int length);

	void setChatMode(CHAT_MODE mode);


	void delayFreshList();
	void onfreshList(float dt);

private:
	cocos2d::ui::Widget*			m_widgetUI;
	cocos2d::ui::ListView*			m_ChatList;//�����б�
	cocos2d::ui::ImageView*			m_ChatPanel;
// 	cocos2d::extension::EditBox*	m_InputBox;

	cocos2d::ui::TextField*			m_InputBox;//�����
	
	cocos2d::ui::Button*			m_CtrlBtn;//��������
	cocos2d::ui::Button*			m_BtnWorld;//
	cocos2d::ui::Button*			m_BtnGroup;//
	cocos2d::ui::Button*			m_BtnWisper;//����

	cocos2d::ui::Button*			m_BtnSendMsg;//����
	
	cocos2d::EventListenerTouchOneByOne* m_TouchListener;

private:
	CHAT_MODE						m_CurretMode;

	std::vector<std::string>		m_WordListWorld;//��������

	std::vector<std::string>		m_WordListGroup;//��������

	std::vector<std::string>		m_WordListWisper;//��������


};


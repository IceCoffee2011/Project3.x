#ifndef _POPUP_LAYER_H_
#define _POPUP_LAYER_H_
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocos/ui/CocosGUI.h"
USING_NS_CC;
USING_NS_CC_EXT;

class PopupLayer : public Layer{

public:
	static PopupLayer* popLayer;
	PopupLayer();
	~PopupLayer();
	virtual bool init();
	//��Ҫ��д����ע�ắ�������¸�����������
	//virtual void registerWithTouchDispatcher();
	//��д��������������true�����������㣬�ﵽ��ģ̬��Ч��
	bool TouchBegan(Touch *pTouch, Event *pEvent);
	//��̬��������������һ�������㣬���ñ���ͼƬ
	static PopupLayer* create(const char* backgroundImage);
	//���ñ���
	void setTitle(const char* title, int fontsize = 25);
	//�����ı����ݣ�padding Ϊ���ֵ��Ի�������Ԥ���ľ��룬���ǿɿصģ����Ϸ��ľ����������
	void setContentText(const char* text, int fontsize=25, int padding=50, int paddingTop=150);
	//�����ϲ������ϲ�ص����������ڻص�ʱ����CCNode����
	void setCallBackFunc(const std::function<void (cocos2d::Ref *,cocos2d::ui::TouchEventType )> &callBack);
	//���menuItem��ť����װ��һ������������Щ��Ҫ�Ĳ���
	bool addButton(const char* normalImage, const char* selectedImage, int tag=0);
	//Ϊ������ʾ��ʱ��������Ч��ѡ����onEnter�ﶯ̬����
	virtual void onEnter();
	virtual void onExit();
	CREATE_FUNC(PopupLayer);
private:
	void buttonCallBack(CCObject* pSender,cocos2d::ui::TouchEventType type);
	//�����������ߵĿհ�����
	int m_contentPadding;
	int m_contentPaddingTop;
	//CCObject* m_callbackListener;
	//SEL_CallFuncN m_callback;
	std::function<void (cocos2d::Ref *,cocos2d::ui::TouchEventType )> m_callback;
	//������CCMenu*���ͱ���m_pMenu, ����ֱ�Ӷ���Ĭ�ϵ�set/get����
	CC_SYNTHESIZE_RETAIN(ui::Button*, m_pMenu, MenuButton);
	CC_SYNTHESIZE_RETAIN(Sprite*, m_sfBackGround, SpriteBackGround);
	CC_SYNTHESIZE_RETAIN(ui::Scale9Sprite*, m_s9BackGround, Sprite9BackGround);
	CC_SYNTHESIZE_RETAIN(LabelTTF*, m_ltTitle, LabelTitle);
	CC_SYNTHESIZE_RETAIN(ui::Text*, m_ltContentText, LabelContentText);
};

#endif //!_POPUP_LAYER_H_

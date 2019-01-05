#ifndef __Validate__Layer__
#define __Validate__Layer__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class ValidateLayer : public Layer {
public:
    CREATE_FUNC(ValidateLayer);
	virtual bool init();
    ValidateLayer();
    virtual ~ValidateLayer();

	//iShowType 0Ϊ��¼��֤ 1Ϊ���ֻ���֤ 2Ϊȡ������֤ 3ת�� 4�ֺ�
	static void show(const char* phoneNumber,const int iShowType = 0); 
	void setShowType(const char* phoneNumber,const int showType);
private:

	static bool m_isShow;
	int m_times;//������֤�����
	int iTimer;
	int iType;//0��½ 1�� 2��� 3ת�� 4�ֺ�
	bool m_isValidating; //������֤
	std::string m_phoneNumber;

	void close(Object* obj);
	void confirm(Object* obj);
	void validateCodeReback(Object *obj);
	//��ʼ��
	void initView();
	void initData();

	void startTimer();
	void stopTimer();

	void sendHttpRequest();
	void onHttpRequestCompleted(Node *sender, void *data);
};

#endif /* __Validate__Layer__ */

#include "JniControl.h"
#include "DDZRes.h"
#include "BJLSceneControl.h"
#include "GlobalUnits.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JniHelper.h"
#endif

JniControl::JniControl(void)
{
	NotificationCenter::getInstance()->addObserver(this,callfuncO_selector(JniControl::JniC_MsgToAndroid),MESSAGE_JNICONTROL,NULL);
}


JniControl::~JniControl(void)
{
	NotificationCenter::getInstance()->removeObserver(this, MESSAGE_JNICONTROL);
}

JniControl* JniControl::sharedJniControl()
{
	static JniControl* s_GniControl=NULL;
	if (!s_GniControl)
	{
		s_GniControl = new JniControl();
	}
	return s_GniControl;
}

void JniControl::JniC_MsgToAndroid( Object* obj )
{
	Integer* _int=(Integer*)obj;
	//CCAssert(_int, "JniC_MsgToAndroid obj=null");

	switch(_int->getValue())
	{
	case MSG_JNI_Share:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)	
	//
#endif
		break;

	case MSG_JNI_Task:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)	
	//
#endif
		break;
	case MSG_JNI_Start:
		break;
	case MSG_JNI_Recharge:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		//�͵ȼ� = 1 �еȼ� = 2 �ߵȼ� = 3 ��X = 1 ûX = 2
		if(g_GlobalUnits.getGolbalUserData()->lScore < ConfigMgr::instance()->m_Config.nServerEnter[(((1-1) % 3 ) << 1) + 1])
		{
			showAndroidRechageLayer(String::createWithFormat("%d",g_GlobalUnits.getGolbalUserData()->dwUserID)->getCString(),"1","5");
		}
		else if(g_GlobalUnits.getGolbalUserData()->lScore < ConfigMgr::instance()->m_Config.nServerEnter[(((2-1) % 3 ) << 1) + 1])
		{
			showAndroidRechageLayer(String::createWithFormat("%d",g_GlobalUnits.getGolbalUserData()->dwUserID)->getCString(),"2","5");
		}
		else
		{
			showAndroidRechageLayer(String::createWithFormat("%d",g_GlobalUnits.getGolbalUserData()->dwUserID)->getCString(),"3","5");
		}
#else
		//NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_UPDATESCOREANDGOLDEGG,NULL);  ˢ��Ǯ�ͻ��ѵ�
#endif
		break;
	}
}
JniControl* Jni=JniControl::sharedJniControl();
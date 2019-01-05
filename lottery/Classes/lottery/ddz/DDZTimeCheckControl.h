//  [3/26/2014 xieyi]
#ifndef DDZ___TIME_CHECK__
#define DDZ___TIME_CHECK__

#include "cocos2d.h"

USING_NS_CC;


class DDZTimeCheckControl
{
public :
	DDZTimeCheckControl();
	virtual ~DDZTimeCheckControl();

	static DDZTimeCheckControl* getInstance();

	void  saveEnterBackgroundTime();

	void  saveEnterForegroundTime();

	int getPauseTime();

	void resetTimes();
	
private:

	long m_pauseTime;//�����̨ʱ��

	long m_backTime;//�ص�ǰ̨ʱ��

};

#endif
#ifndef __Game__ChoosePlayerPhotoLayer__
#define __Game__ChoosePlayerPhotoLayer__

#include "CocosUnits.h"
#include "ConfigMgr.h"
#include "AnsString.h"
#include <iostream>
#include "cocos2d.h"
class ChoosePlayerPhotoLayer : public Layer
{

private:
	/**ȷ��ѡ��ı�־**/
	Sprite *m_choose_log;
public:
	ChoosePlayerPhotoLayer();
	~ChoosePlayerPhotoLayer();
	virtual bool init();
	static Scene* scene();
	CREATE_FUNC(ChoosePlayerPhotoLayer);
public:
	
	//void choose1(Object *obj);
	//void choose2(Object *obj);
	//void choose3(Object *obj);
	//void choose4(Object *obj);
	//void choose5(Object *obj);
	//void choose6(Object *obj);
	//void choose7(Object *obj);
	//void choose8(Object *obj);
	void dismiss(Object *obj);
	
};
#endif  //__Game__ChoosePlayerPhotoLayer__
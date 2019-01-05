#ifndef __PPC_TRAVEL_H__
#define __PPC_TRAVEL_H__

#include "cocos2d.h"
#include "PPCEnum.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace std;

//	����������·��
class PPCTravel: public Node
{
public:
	PPCTravel();
	~PPCTravel();
	CREATE_FUNC(PPCTravel);

	//	���·��
	void addTravelItem(EPPCCarLogoType eType);

	//	��ȡ·���б�������
	int getTraveItemCount();
private:
	bool init();
	void initUI();

	//	·���б���ͼ
	ListView* m_pListView;
};


#endif  // __PPC_TRAVEL_H__
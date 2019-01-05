#ifndef __PPC_ENDING_H__
#define __PPC_ENDING_H__

#include "cocos2d.h"
#include "BaseDialog.h"
#include "PPCEnum.h"
#include "PPCRes.h"

USING_NS_CC;
using namespace std;



//	�������
class PPCEnding: public Layer
{
public:
	PPCEnding();
	~PPCEnding();

	CREATE_FUNC(PPCEnding);

	//	��ҵ÷�
	Label* m_pLabPlayerScore;

	//	��ҷ��ر���
	Label* m_pLabPlayerCapital;

	//	ׯ�ҵ÷�
	Label* m_pLabBankerScore;

	//	ׯ�ҷ��ر���
	Label* m_pLabBankerCapital;

private:
	bool init();
	void initUI();

	//	����
	Sprite* m_pBG;


};

#endif  // __PPC_ENDING_H__
//  [4/1/2014 wucan]

#ifndef	DDZ___VIEW_TASK__
#define	DDZ___VIEW_TASK__
#include "DDZDDZLogic.h"
#include "DDZDDZRes.h"
#include "cocos2d.h"
USING_NS_CC;

class DDZViewTask:public Node
{
public:
	CREATE_FUNC(DDZViewTask);
	virtual bool init();
	void setBackTaskView(BYTE* _data,WORD _num);									//--���Ʊ�������
	void setLastTaskView(WORD _key);														//--����������
	Node * m_dpNode;		//���Ƽӱ�
	Node * m_jsNode;		//�����Ƽӱ�
private:
	LabelTTF * addTaskString(char * key,Vec2 point,Color3B color,int fontSize);
};
#endif
//  [4/1/2014 wucan]

#ifndef		__VIEW_TASK__
#define		__VIEW_TASK__
#include "BJLRes.h"
#include "cocos2d.h"
USING_NS_CC;

class ViewTask:public Node
{
public:
	CREATE_FUNC(ViewTask);
	virtual bool init();
	void setBackTaskView(BYTE* _data,WORD _num);									//--���Ʊ�������
	void setLastTaskView(WORD _key);														//--����������
	Node * m_dpNode;		//���Ƽӱ�
	Node * m_jsNode;		//�����Ƽӱ�
private:
	LabelTTF * addTaskString(char * key,Vec2 point,Color3B color,int fontSize);
};
#endif
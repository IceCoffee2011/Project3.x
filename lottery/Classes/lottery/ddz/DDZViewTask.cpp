#include "DDZViewTask.h"
bool DDZViewTask::init()
{
	bool ret= false;
	cocos2d::Size size  = Director::getInstance()->getWinSize();
	do 
	{
		m_dpNode = Node::create();//��������node
		m_jsNode = Node::create();
		this->addChild(m_dpNode);
		this->addChild(m_jsNode);
		ret =true;
	} while (0);
	return ret;
}

void DDZViewTask::setBackTaskView(BYTE* _data,WORD _num)
{
	m_dpNode->removeAllChildren();
	cocos2d::Size size  = Director::getInstance()->getWinSize();
	DDZDDZLogic _logic;
	WORD _uumBeilv = _logic.getBackbeiLv(_data,_num);
	Sprite * bgSprite = Sprite::createWithSpriteFrameName(DDZtexture_name::s_jiaBeiBar);//����
	Sprite * jbSprite = NULL;//�ӱ�
	switch(_uumBeilv)
	{
	case 2:
		jbSprite = Sprite::createWithSpriteFrameName(DDZtexture_name::s_twice);
		break;
	case 3:
		jbSprite = Sprite::createWithSpriteFrameName(DDZtexture_name::s_thrice);
		break;
	case 4:
		jbSprite = Sprite::createWithSpriteFrameName(DDZtexture_name::s_fourfold);
		break;
	case 5:
		jbSprite = Sprite::createWithSpriteFrameName(DDZtexture_name::s_fivefold);
		break;
	case 6:
		jbSprite = Sprite::createWithSpriteFrameName(DDZtexture_name::s_sixfold);
		break;
	case 9:
		jbSprite = Sprite::createWithSpriteFrameName(DDZtexture_name::s_nonuple);
		break;
	default:
		m_dpNode->setVisible(false);
		break;
	}
	if (NULL!=jbSprite)
	{
		m_dpNode->addChild(bgSprite);
		jbSprite->setPosition(bgSprite->getPosition());
		m_dpNode->addChild(jbSprite);
		m_dpNode->setPosition(ccp(80.0f,size.height-40));
		m_dpNode->runAction(MoveTo::create(0.2f,ccp(120.0f,size.height-40)));
	}
	
	//--��������
	//m_beillu[_uerID] *= _unmBeilv;
}

void DDZViewTask::setLastTaskView(WORD _key)
{
	m_jsNode->removeAllChildren();
	cocos2d::Size size = Director::getInstance()->getWinSize();
	//-key Ϊ��ʾ����
	Vec2 point = ccp(size.width/2,size.height*0.6);
	Color3B color = ccc3(181,135,57);
	int fontSize = 20;
	char * key;
	DDZDDZLogic _logic;
	switch(_key)
	{
	case CT_SINGLE://���ƽ���x2
		key = "ct_single";
		break;
	case CT_DOUBLE://���ƽ���x2
		key = "ct_double";
		break;
	case CT_SINGLE_LINE://˳��x3
		key = "ct_single_line";
		break;
	case CT_DOUBLE_LINE://����x3
		key = "ct_double_line";
	case	CT_THREE_LINE://����x3
		key = "ct_three_line";
		break;
	case CT_THREE_LINE_TAKE_ONE://����һx3
		key = "ct_three_line_take_one";
		break;
	case CT_THREE_LINE_TAKE_TWO://����һ��x3
		key = "ct_three_line_take_two";
		break;
	case CT_BOMB_CARD://ը��x4
		key = "ct_bomb_card";
		break;
	case CT_MISSILE_CARD://���x5
		key = "ct_missile_card";
		break;
	default:
		return;
	}
	m_jsNode->addChild(addTaskString(key,point,color,fontSize));
}

LabelTTF * DDZViewTask::addTaskString(char * key,Vec2 point,Color3B color,int fontSize)
{
	Dictionary * strings = Dictionary::createWithContentsOfFile("ddz_strings.xml");
	const char * str = ((CCString*)strings->objectForKey(key))->getCString();
	LabelTTF * pLableTTF = LabelTTF::create(str,"",fontSize);
	pLableTTF->setColor(color);
	pLableTTF->setPosition(point);
	return pLableTTF;
}

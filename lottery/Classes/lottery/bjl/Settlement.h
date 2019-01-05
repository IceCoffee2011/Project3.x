//  [3/26/2014 xieyi]
#ifndef __SETTLEMENT__
#define __SETTLEMENT__
#include "cocos2d.h"
#include "DDZRes.h"
#include "User.h"
#include "CardTableLayer.h"
USING_NS_CC;

enum{
	tag_showcard = 1,	//����
	tag_jiabei,			//�ӱ�
	tag_qiangdizhu,		//������
	tag_bomb,			//ը��
	tag_spring,			//����
	tag_lowcardtype,	//��������
	tag_overcardtype,	//��������
	tag_basescore,		//�׷�
	tag_tableconsume,	//��������
	tag_total,			//�ܱ���
};

class Settlement : public Node
{
public:

	Settlement();
	~Settlement();
	virtual bool init();
	CREATE_FUNC(Settlement);
	void setUserMessage(Integer * obj);		//�����Ϣ
	void setTimesMessage(CMD_S_GameEnd* _gameEnd,WORD _userID);	//���ñ�����Ϣ
private:
	void addString(char* key,Vec2 point,Color3B  color,int fontSize,int tag,int num);		//���Ҫ��ʾ���ַ���
	void addUserString(const char * res,float pointY,Color3B color,int fontSize,long udpScore,const char * nikeName,bool isJiaBei,bool isDiZhu,bool isSelf);
	Sprite * m_bgLeftSprite;	//����ͼƬ
	SpriteBatchNode * m_batchNode;	//
};

#endif
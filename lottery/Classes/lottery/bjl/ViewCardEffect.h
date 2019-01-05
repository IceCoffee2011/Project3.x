//  [3/27/2014 wucan]

#ifndef			__VIEW_CARD_EFFECT__
#define			__VIEW_CARD_EFFECT__
#include "cocos2d.h"
#include "DDZRes.h"
#include "SoundControl.h"
#include "CardTableLayer.h"
USING_NS_CC;

enum EffectType
{
	Effect_LandLord=1,
	Effect_NoLandLord,
	Effect_RobLord,
	Effect_NoRobLord,
	Effect_PassCard,
	Effect_OpenStart,						//--���ƿ�ʼ
	Effect_gameStart,						//--��ͨ��ʼ
	Effect_openCard,						//--����ʱ������
	Effect_jiaBei,							//�ӱ�
	Effect_alarm,							//����
	Effect_outcardErr,						//���ƴ���
	Effect_noBigCard,						//û���ܴ���ϼ�
	Effect_task,								//������ʾ
	Effect_LlinkOFF,						//�Զ�����
};

class ViewCardEffect:public Node
{
public:
	CREATE_FUNC(ViewCardEffect);
	virtual bool init();
	void runEffect(EffectType _type,int userId);									//--��������
	void runCardEffect(int cardType,int userId,int cardNum,int userOutCardState);						//--�������Ͷ���
	void runRobot(bool isOnRobot);													//--�������йܶ���
	void runVoice(string voiceString,int _userID );
	void runVoiceAndFace(int _type,int _key,int _userID);					//--������������
	void runSettlementEffect(Integer * obj,int tableConsume,CardTableLayer * layer);		//���㶯��
	void runHfdEffect(Integer * obj);							//���ѵ㶯��

private:
	void effectOpenStart(bool isOpen,int userId);					//--���ƺ�ֱ�ӿ�ʼ
	void effectOpenCard(int userId);										//--��������
	void effectLandLord(bool isLand,int userId);					//--���޽е���
	void effectRodLord(bool isRob,int userId);		//--����������
	void effectPassCard(int userId);						//--����
	void effectJiaBei(int userId,bool isJiaBei);				//�ӱ�
	void effectAlarm(int userId);	//����
	void removeAlarm();//�Ƴ����о���
	void addEffect(const char* key,Vec2 point,Color3B  color,int fontSize,bool showDi);	//���˵�Ļ������֣�
	void addUserInputMsgEffect(const char* key,Vec2 point,Color3B color,int fontSize,bool showDi);
	void addPictureEffect(const char* key,Vec2 point,bool isAddPartiCar=false);	//���ͼƬЧ��
	void removerSelf(Node* node);
	void changeCoinNumber(Node * node);//�ı�������
	void changeHfdNumber(Node * node);//�ı仰�ѵ�����

private:
	bool m_leftAlarm;
	bool m_rightAlarm;
/*	Animation * getAnimation (const char * key,int frameNum);*/

	Vec2 getEffectPos(int _userID);
	//--���������
	void RobotCallBack(Object* obj);
private:
	Node*     m_RobotNode;
	unsigned int g_udpCoinNumber;//�仯�Ľ������
	unsigned int g_hfdCoinNumber;//���ѵ�仯����
	CardTableLayer * g_cardTableLayer;
};

#endif
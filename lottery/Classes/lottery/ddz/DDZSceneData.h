#ifndef		DDZ___CC_SCENEDATA_WUCAN__
#define		DDZ___CC_SCENEDATA_WUCAN__
#include "cocos2d.h"
USING_NS_CC;
#include "CMD_DDZ.h"
#include "DDZLogic.h"
#define CREATE_FUNC_MSG(__TYPE__) \
static __TYPE__* create(int v) \
{ \
	__TYPE__ *pRet = new __TYPE__(v); \
	pRet->autorelease(); \
	return pRet; \
}

enum DDZGame_State
{
	DDZGame_null = 0,			//��
	DDZGame_Wait,				//�ȴ�״̬
	DDZGame_Start,				//��ʼ
	DDZGame_landLord,			//������
	DDZGame_jiaBei,				//�ӱ�
	DDZGame_Run,				//����
	DDZGame_Over,				//��Ϸ����
};

enum
{
	DDZmsgToView_UserInfor=1,				//--����������Ϣ
	DDZmsgToView_SitDown,					//--����
	DDZmsgToView_start,						//--��Ϸ��ʼ
	DDZmsgToView_startView,					//--��ʼЧ������
	DDZmsgToView_addView,					//--�ӱ�����
	DDZmsgToView_sendCard,					//--����
	DDZmsgToView_backCard,					//--����
	DDZmsgToView_openCard,					//--����
	DDZmsgToView_landLord,					//--������
	DDZmsgToView_beiLv,						//--���ʱ仯
	DDZmsgToview_LordView,					//--�������ֱ仯
	DDZmsgToView_time,						//	ʱ��		
	DDZmsgToView_outCard,					//	����
	DDZmsgToView_passCard,					//	����
	DDZmsgToView_gameOver,					//--��Ϸ����
	DDZmsgToView_SettmentUser,				//--��Ϸ����������Ϣ
	DDZmsgToView_openCardNum,				//--viewHandCard����
	DDZmsgToview_TimeCallBack,				//--ʱ��ص�  Time ����
	DDZmsgToView_OnLine,					//--���������ʾ
	DDZmsgToView_Reconnect,					//--��������
	DDZmsgToView_socketoffConnect,			//--����Ͽ��Զ�����
	DDZmsgToView_socketoff,					//--����Ͽ������ش���
	DDZmsgToView_DDZVoiceAndFace,			//--���������
	DDZmsgToView_huafeidian,				//--���ѵ�
	DDZmsgToView_Close,						//--ǿ�ƹر�
	DDZmsgToView_RoomLimit,					//--��������

	DDZmsgToLogic_openStart,				//	���ƿ���
	DDZmagToLogc_gameStart,					//	��ͨ����
	DDZmsgToLogc_openCard,					//	����
	DDZmsgToLogc_LandLord,					//	�е���
	DDZmsgToLogic_outCard,					//	����
	DDZmsgToLogic_passCard,					//	����
	DDZmsgToLogic_MoreGame,					//	����һ��
	DDZmagToLogc_jiabei,					//--�ӱ�
	DDZmsgToLogic_face,						//--����
	DDZmsgToLogic_changeTable				//	����
};

//�����˵�ö��
enum DDZMenuItemType
{
	DDZmenu_visibleStartMenuItem = 1,	//���ƿ�ʼ
	DDZmenu_startMenuItem,				//��ͨ��ʼ
//	menu_menuBarItem,				//�˵���
	DDZmenu_rechargemenuItem,			//���ٳ�ֵ
	DDZmenu_outCardMenuItem,			//����
	DDZmenu_passOutCardMenuItem,		//��Ҫ
	DDZmenu_hintMenuItem,				//��ʾ
	DDZmenu_jiaoDiZhuItem,				//�е���
	DDZmenu_buJiaoItem,					//����
	DDZmenu_qiangDiZhuItem,				//������
	DDZmenu_passQiangDiZhuItem,			//����
	DDZmenu_visibleCardItem,			//����X2
	DDZmenu_doubleItem,					//�ӱ�
	DDZmenu_unDoubleItem,				//���ӱ�
	DDZmenu_settlementDetial,			//��������
	DDZmenu_again,						//����һ��
	DDZmenu_OutAgency,					//ȡ���й�
	DDZmenu_changeTable,				//����
	DDZmenu_visibleCardStartItem,		//���ƹ����е����ƿ�ʼ
	DDZmenu_number,						//���ƿ�ʼ��ť����
	DDZmenu_menuBarRobotItem,			//�˵����йܰ�ť
	DDZmenu_menuBarOptionsItem,			//�˵������ð�ť
	DDZmenu_menuBarBackItem,			//�˵������ذ�ť
	DDZmenu_Count						//	����
};

//--������Ϣ����
class DDZCCuserInfor:public Integer
{
public:
	DDZCCuserInfor(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCuserInfor);
	DWORD		m_userInforID;		//�û�id
	WORD		m_ChairID;		    //����id={0,1,2}<add by hxh 20160901>
	WORD		m_ViewID;		    //��ͼid={0����ϼҡ�1�·��Լ���2�ұ��¼�}<add by hxh 20160901>
	LONG		m_score;			//����
	WORD		m_gender;			//�Ա�
	LONG		m_GoldEggs;			//���ѵ�
	TUserState	m_UserState;		//	�û�״̬
	char		m_PosName[32];		//����
	char        m_name[32];
};

//--���ƿ�ʼ��Ϣ
class DDZCCopenStart:public Integer
{
public:
	DDZCCopenStart(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCopenStart);
	WORD				m_bCurrentUser;                     //��ʼ�û� 
	bool					m_bOpenCard;							//���ƿ�ʼ
};

//--������Ϣ
class DDZCCsendCard: public Integer
{
public:
	DDZCCsendCard(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCsendCard);
	//	��������
	BYTE m_handCardData[MAX_COUNT];
	//	������Ŀ
	WORD m_handCardNum;
	//	�Ƿ�����
	bool m_bOpen;
	//	�Ƿ���Ч��
	bool m_bEffect;
	//	���ID
	WORD m_userID;
};

//--������Ϣ
class DDZCCopenCard: public Integer
{
public:
	DDZCCopenCard(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCopenCard);
	WORD m_openID;
};

//--������
class DDZCClandLord: public Integer
{
public:
	DDZCClandLord(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCClandLord);
	WORD		m_landID;
	WORD		m_LandKey;
	bool			m_isLand;
};

//--��ʾʱ��
class DDZCCtimeControl:public Integer
{
public:
	DDZCCtimeControl(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCtimeControl);
	WORD		m_timeUserID;
	WORD		m_timeNum;
	DDZGame_State	m_gameState;			//--Game_landLord <2 Ϊ�е��� >2Ϊ������
	WORD		m_timeKey;					//--Game_Run 0Ϊ�����״γ��Ʋ��������ƣ�1Ϊ�����״γ��Ʋ������ƣ�2Ϊ�Լ��״γ��ƣ�3Ϊ��ͨ����			
	WORD		m_BankUser;
};

//--��ҳ���
class DDZCCoutCard:public Integer
{
public:
	DDZCCoutCard(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCoutCard);
	BYTE		m_outkCard[MAX_COUNT];				//�����˿�
	WORD  m_numCard;
	WORD  m_outUser;
	WORD  m_bankUser;
};

//--�������
class DDZCCpassCard:public Integer
{
public:
	DDZCCpassCard(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCpassCard);
	WORD m_passUser;
};

//--��Ϸ����
class DDZCCgameOver:public Integer
{
public:
	DDZCCgameOver(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCgameOver);
	//CMD_S_GameConclude m_gameEndData;
	DDZCMD_S_GameEnd* m_gameEndData;
	//	���ID
	DWORD m_UserID;
	//	�Ƿ��Ʋ�
	bool m_isPochang;
};

//--���Ʊ�����Ϣ
class DDZCCviewOpenCardNum:public Integer
{
public:
	DDZCCviewOpenCardNum(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCviewOpenCardNum);
	WORD  m_num;
};

//--�ӱ�����
class DDZCCaddView:public Integer
{
public:
	DDZCCaddView(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCaddView);
	WORD			m_addID;
	WORD			m_AddType;		//--�ӱ����ͣ�1 ���֣� 2Ӱ�أ�3.����
};

//--���Ʊ仯
class DDZCCbackData:public Integer
{
public:
	DDZCCbackData(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCbackData);
	BYTE   m_data[DDZGAME_PLAYER];
	WORD	m_taskKey;
	bool    m_isNew;
};

//--���ʱ仯
class DDZCCbeilv:public Integer
{
public:
	DDZCCbeilv(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCbeilv);
	WORD		m_beilv;
	WORD		m_base;
};

//--��������
class DDZCConline: public Integer
{
public:
	DDZCConline(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCConline);
	WORD    m_userID;
	bool        m_isOnline;
};

//--����
class DDZCCfaceAndVioce: public Integer
{
public:
	DDZCCfaceAndVioce(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCfaceAndVioce);
	int m_Type;//��1���� 2������
	int m_KeyID;
	int m_UserID;
	char voice[512];
};

//--��������
class DDZCClandView:public Integer
{
public:
	DDZCClandView(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCClandView);
	int m_landUserID;
};

//���������Ϣ
class DDZCCSettmentUserMessage:public Integer
{
public:
	DDZCCSettmentUserMessage(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCSettmentUserMessage);
	int m_userId;//�û�id
	int m_diZhuId;//����id
	int m_updScore;//�仯�ķ���
	int m_isJiabei;//�Ƿ�ӱ�
	char m_nikeName[32];//�ǳ�
};

//--���ѵ�仯
class DDZCChuafeidian:public Integer
{
public:
	DDZCChuafeidian(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCChuafeidian);
	int  m_huafeidian;
};

//--��������
class DDZCCRoomLimit:public Integer
{
public:
	DDZCCRoomLimit(int v):Integer(v){};
	CREATE_FUNC_MSG(DDZCCRoomLimit);
	int  m_RoomLimitKey;			//--1��̫���ˣ�2̫����
};
#endif



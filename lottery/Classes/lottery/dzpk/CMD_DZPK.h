//DZPK�������� .h
//Created by xxxx on 14-1-7.

#ifndef GAME_DZPK_CMD_ZJH_H
#define GAME_DZPK_CMD_ZJH_H
#include"Define.h"
#pragma pack(1)//<by hxh>
// �����궨��

// add by hxh 20160930
#define USE_NEW_PROTOCOL
//#define AS_PLAYERINFO_FIELD

//	��Ϸ�㼶ö��
enum EDZPKLayerZOrder
{
	EDZPKLayerZOrder_Table = 1000,	//	����
	EDZPKLayerZOrder_PlayerInfo,	//	�����Ϣ
	EDZPKLayerZOrder_Card,	//	����
	EDZPKLayerZOrder_Trusteeship,	//	�й�
	EDZPKLayerZOrder_Control,	//	���Ʋ㣨��ť��
	EDZPKLayerZOrder_Dialog,	//	�Ի���
};

#if 0
#define bkWidth							854
#define bkHeight						480
#define xDelta							50
#define yDelta							50
#endif
#define cardDelta						5
#define MY_VIEW_CHAIR_ID                3									//�����ͼID
#define DDPKKIND_ID						308									//��Ϸ I D
#define DZPKGAME_PLAYER					8									//��Ϸ����
#define GAME_NAME						TEXT("�����˿�")					//��Ϸ����
#define GAME_GENRE						(GAME_GENRE_GOLD|GAME_GENRE_MATCH)	//��Ϸ����
#define COMMON_CARDS_COUNT				5						            // ��������Ŀ<by hxh>
#define MAX_JETION_AREA                 4                                   // ��ע����
#define MAX_TIMES                       5                                   // �������


//��ֵ����
#define	LOGIC_MASK_COLOR			0xF0								//��ɫ����
#define	LOGIC_MASK_VALUE			0x0F								//��ֵ����


//�˿�����
#define CT_SINGLE					1									//��������
#define CT_ONE_LONG				    2									//��������
#define CT_TWO_LONG			    	3									//��������
#define CT_THREE_TIAO				4									//��������
#define	CT_SHUN_ZI					5									//˳������
#define CT_TONG_HUA					6									//ͬ������
#define CT_HU_LU					7									//��«����
#define CT_TIE_ZHI					8									//��֧����
#define CT_TONG_HUA_SHUN			9									//ͬ��˳��
#define CT_KING_TONG_HUA_SHUN		10									//�ʼ�ͬ��˳

//��Ŀ����
#define DZPK_FULL_COUNT					52									//ȫ����Ŀ
#define DZPK_HAND_CARD_COUNT			2									//������Ŀ<by hxh>
#define MAX_CENTERCOUNT					5									//�����Ŀ


////////////////////////////////////////////////////////////////////////////
// ����������ṹ
#define SUB_S_GAME_START				100									//��Ϸ��ʼ
#define SUB_S_ADD_SCORE					101									//��ע���
#define SUB_S_GIVE_UP					102									//������ע	
#define SUB_S_SEND_CARD					103									//������Ϣ
#define SUB_S_GAME_END					104									//��Ϸ����
#define SUB_S_SIT_DOWN					105									//�û�����
#define SUB_S_OPEN_CARD					106									//�û�����
#define SUB_S_SP_USER					107									//�����û�

//�ͻ�������ṹ
#define SUB_C_ADD_SCORE					1									//�û���ע
#define SUB_C_GIVE_UP					2									//������Ϣ
#define SUB_C_OPEN_CARD					3									//������Ϣ
#define SUB_C_IN_CHIPS					 4001								//�һ�����
#define SUB_C_CHECK						 4002								//�����ڶ��غϿ�ʼ�ſ����еĲ�����

// add by hxh 20161009
inline int DZPKGetActionID(BYTE cbJudgeAction)
{
	int actionID=cbJudgeAction+100;
	return actionID;
}

// ������<by hxh>
inline const char * DZPKGetCardName(unsigned char cbCardData)
{
	//��ȡ��ɫ={0����,16÷��,32����,48����,64��}
	BYTE cbCardColor=cbCardData&LOGIC_MASK_COLOR;
	//��ȡ��ֵ
	BYTE cbCardValue=cbCardData&LOGIC_MASK_VALUE;

	//��Ч�ж�
	bool bLegal=false;
	if ((cbCardData==0x4E)||(cbCardData==0x4F))
		bLegal=true;
	if ((cbCardColor<=0x30)&&(cbCardValue>=0x01)&&(cbCardValue<=0x0D)) 
		bLegal=true;

	if(bLegal)
	{
		static const char * szCardName[5][15]={
			{"��A","��2","��3","��4","��5","��6","��7","��8","��9","��10","��J","��Q","��K","",""},
			{"÷A","÷2","÷3","÷4","÷5","÷6","÷7","÷8","÷9","÷10","÷J","÷Q","÷K","",""},
			{"��A","��2","��3","��4","��5","��6","��7","��8","��9","��10","��J","��Q","��K","",""},
			{"��A","��2","��3","��4","��5","��6","��7","��8","��9","��10","��J","��Q","��K","",""},
			{"","","","","","","","","","","","","","С��","����"},
		};
		unsigned char nColorIndex=(cbCardData & 0xf0)>>4;
		unsigned char nValueIndex=(cbCardData & 0x0f)-1;
		return szCardName[nColorIndex][nValueIndex];
	}
	else
		return "";
}

// ������<by hxh>
inline const char * DZPKGetCardPicName(unsigned char cbCardData)
{
	//��ȡ��ɫ={0����,16÷��,32����,48����,64��}
	BYTE cbCardColor=cbCardData&LOGIC_MASK_COLOR;
	//��ȡ��ֵ
	BYTE cbCardValue=cbCardData&LOGIC_MASK_VALUE;

	//��Ч�ж�
	bool bLegal=false;
	if ((cbCardData==0x4E)||(cbCardData==0x4F))
		bLegal=true;
	if ((cbCardColor<=0x30)&&(cbCardValue>=0x01)&&(cbCardValue<=0x0D)) 
		bLegal=true;

	if(bLegal)
	{
		static const char * szCardName[5][15]={
			{"Ad","2d","3d","4d","5d","6d","7d","8d","9d","Td","Jd","Qd","Kd","",""},
			{"Ac","2c","3c","4c","5c","6c","7c","8c","9c","Tc","Jc","Qc","Kc","",""},
			{"Ah","2h","3h","4h","5h","6h","7h","8h","9h","Th","Jh","Qh","Kh","",""},
			{"As","2s","3s","4s","5s","6s","7s","8s","9s","Ts","Js","Qs","Ks","",""},
			{"","","","","","","","","","","","","","00","00"},
		};
		unsigned char nColorIndex=(cbCardData & 0xf0)>>4;
		unsigned char nValueIndex=(cbCardData & 0x0f)-1;
		return szCardName[nColorIndex][nValueIndex];
	}
	else
		return "00";
}

//����״̬
struct CMD_S_StatusFree_dzpk
{
	LONGLONG							lCellMinScore;						//��С��ע
	LONGLONG							lCellMaxScore;						//�����ע
};

//��Ϸ״̬
struct CMD_S_StatusPlay_dzpk
{
	//��ע��Ϣ
	LONGLONG							lCellScore;								//��Ԫ��ע
	LONGLONG							lTurnMaxScore;							//�����ע
	LONGLONG							lTurnLessScore;							//��С��ע
	LONGLONG							lCellMaxScore;							//�����ע
	LONGLONG							lAddLessScore;							//����Сע
	LONGLONG							lTableScore[DZPKGAME_PLAYER];			//��ע��Ŀ
	LONGLONG			 				lTotalScore[DZPKGAME_PLAYER];			//�ۼ���ע
	LONGLONG							lCenterScore;							//���ĳ���

	//״̬��Ϣ
	WORD								wDUser;									//D���
	WORD				 				wCurrentUser;							//��ǰ���
	BYTE								cbPlayStatus[DZPKGAME_PLAYER];			//��Ϸ״̬,ȡֵ0��1
	LONGLONG							lUserMaxScore[DZPKGAME_PLAYER];			//�û������<by hxh>
	BYTE							    cbBalanceCount;							//ƽ�����

	//�˿���Ϣ
	BYTE								cbCenterCardData[MAX_CENTERCOUNT];		//�˿���Ŀ
	BYTE								cbHandCardData[DZPK_HAND_CARD_COUNT];	//�յ���Ϣ��ҵ���������
};

//�û���ע
struct CMD_S_AddScore
{
	WORD								wCurrentUser;						//��ǰ�û�
	WORD								wAddScoreUser;						//��ע�û�
	LONGLONG							lAddScoreCount;						//��ע��Ŀ
	LONGLONG							lTurnLessScore;						//��С��ע
	LONGLONG							lTurnMaxScore;						//�����ע
	LONGLONG							lAddLessScore;						//��С��ע
	BYTE								cbJudgeAction;                       //�ж���ע����   "1��","2��ע","3��ע","4��ע","5����","6ȫ��
};

//�û���ע
struct CMD_C_AddScore
{
	LONGLONG							lScore;								//��ע��Ŀ
	BYTE								cbJudgeAction;                       //�ж���ע����   "1��","2��ע","3��ע","4��ע","5����","6ȫ��
};
//�û�����
struct CMD_S_GiveUp
{
	WORD								wGiveUpUser;						//�����û�
	LONGLONG							lLost;								//������	
};
//������Ϣ���ݰ�
struct CMD_S_SendCard
{
	BYTE								cbPublic;							//�Ƿ���
	WORD								wCurrentUser;						//��ǰ�û�
	BYTE								cbSendCardCount;					//������Ŀ={3,4,5}
	BYTE								cbCenterCardData[MAX_CENTERCOUNT];	//�����˿�	
};

//��Ϸ��ʼ
struct CMD_S_GameStart_dzpk
{
	WORD				 				wCurrentUser;						//��ǰ���
	WORD								wDUser;								//D���
	WORD								wMinChipInUser;						//Сäע���
	WORD								wMaxChipInUser;						//��äע���	
	LONGLONG							lCellScore;							//��Ԫ��ע
	LONGLONG							lTurnMaxScore;						//�����ע
	LONGLONG							lTurnLessScore;						//��С��ע
	LONGLONG							lAddLessScore;						//����Сע
#ifdef USE_NEW_PROTOCOL
	LONGLONG							lUserMaxScore[DZPKGAME_PLAYER];			//�û������<by hxh>
	BYTE								cbPlayStatus[DZPKGAME_PLAYER];		//��Ϸ״̬,ȡֵ0��1
#endif
	BYTE								cbCardData[DZPKGAME_PLAYER][DZPK_HAND_CARD_COUNT];	//�û��˿�
};

//�սṹ��
struct CMD_C_NULL
{

};


//��Ϸ����
struct CMD_S_GameEnd_dzpk
{
	BYTE							cbTotalEnd;							    //ǿ�˱�־	1������������̣�����5�Ź����ƣ�������Ϸ��	0��δ����������̽�����Ϸ
	double							lGameTax[DZPKGAME_PLAYER];				//��Ϸ˰��
	double							lGameScore[DZPKGAME_PLAYER];			//��Ϸ�÷�
	BYTE							cbCardData[DZPKGAME_PLAYER][DZPK_HAND_CARD_COUNT];	//�û��˿�
	BYTE							cbLastCenterCardData[DZPKGAME_PLAYER][MAX_CENTERCOUNT];//����˿�
	BYTE							cbLastCardKind[DZPKGAME_PLAYER];        //��������
};

//�û�����
struct CMD_S_OpenCard
{
	WORD								wWinUser;							//�û�����
};


//ʤ����Ϣ�ṹ
struct UserWinList
{
	BYTE bSameCount;
	WORD wWinerList[DZPKGAME_PLAYER];
};
//�����ṹ
struct tagAnalyseResult_dzpk
{
	BYTE 							cbFourCount;						//������Ŀ
	BYTE 							cbThreeCount;						//������Ŀ
	BYTE 							cbLONGCount;						//������Ŀ
	BYTE							cbSignedCount;						//������Ŀ
	BYTE 							cbFourLogicVolue[1];				//�����б�
	BYTE 							cbThreeLogicVolue[1];				//�����б�
	BYTE 							cbLONGLogicVolue[2];				//�����б�
	BYTE 							cbSignedLogicVolue[5];				//�����б�
	BYTE							cbFourCardData[MAX_CENTERCOUNT];			//�����б�
	BYTE							cbThreeCardData[MAX_CENTERCOUNT];			//�����б�
	BYTE							cbLONGCardData[MAX_CENTERCOUNT];		//�����б�
	BYTE							cbSignedCardData[MAX_CENTERCOUNT];		//������Ŀ
};
#pragma pack()//<by hxh>
#endif
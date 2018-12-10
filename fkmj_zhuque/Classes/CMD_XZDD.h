#ifndef CMD_SPARROW_HEAD_FILE
#define CMD_SPARROW_HEAD_FILE

#include "GameDefine.h"

//�������
struct XZDD_CMD_WeaveItem
{
	BYTE							cbWeaveKind;						//�������
	BYTE							cbCenterCard;						//�����˿�
	BYTE							cbPublicCard;						//������־
	WORD							wProvideUser;						//��Ӧ�û�

	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(cbWeaveKind);
		Stream_VALUE(cbCenterCard);
		Stream_VALUE(cbPublicCard);
		Stream_VALUE(wProvideUser);
	}
};


#pragma pack(1)

//�������
#define GAME_PLAYER					4									//��Ϸ����

#define GAME_GENRE					(GAME_GENRE_SCORE|GAME_GENRE_MATCH|GAME_GENRE_GOLD)	//��Ϸ����

//��Ϸ״̬
#define GS_MJ_FREE					GAME_STATUS_FREE					//����״̬
#define GS_MJ_PLAY					(GAME_STATUS_PLAY+1)				//��Ϸ״̬

#define GS_MJ_HUANPAI                 (GAME_STATUS_PLAY+2)						//����״̬
#define GS_MJ_XUANQUE                 (GAME_STATUS_PLAY+3)						//ѡȱ״̬

#define TIME_START_GAME				30									//��ʼ��ʱ��
#define TIME_OPERATE_CARD				15									//������ʱ��

#define		GAME_TYPE_SICHUAN  0                      //�Ĵ��齫
#define		GAME_TYPE_CHENGDU  1					   //�ɶ��齫
#define		GAME_TYPE_YICHANG  2

#define		GAME_RULE_NO_WAIT				1
#define		GAME_RULE_XZ					2
#define		GAME_RULE_XL					3
#define		GAME_RULE_HUAN3				4
#define		GAME_RULE_DIN_QUE				5
#define		GAME_RULE_3FAN				6
#define		GAME_RULE_4FAN				7
#define		GAME_RULE_ZIMO_DI				8
#define		GAME_RULE_ZIMO_FAN			9
#define		GAME_RULE_YAOJIU_JIANGDUI		10
#define		GAME_RULE_TIANDI_HU			11
#define		GAME_RULE_5FAN				12
#define		GAME_RULE_DAODAO_HU			13
#define		GAME_RULE_DIANPAO				14
#define		GAME_RULE_ZIMOHU				15
#define		GAME_RULE_QIDUI				16

#define MAX_GAME_RULE				6		//������
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//����������ṹ

#define SUB_S_GAME_START			100									//��Ϸ��ʼ
#define SUB_S_OUT_CARD				101									//��������
#define SUB_S_SEND_CARD				102									//�����˿�
#define SUB_S_OPERATE_NOTIFY		104									//������ʾ
#define SUB_S_OPERATE_RESULT		105									//��������
#define SUB_S_GAME_END				106									//��Ϸ����
#define SUB_S_TRUSTEE				107									//�û��й�
#define SUB_S_CHI_HU				108									//
#define SUB_S_GANG_SCORE			110									//

//2016.5.20
#define SUB_S_HUANPAI 120				//����
#define SUB_S_XUANQUE 121				//ѡȱ
#define SUB_S_XUANQUE_NOTICE 122		//֪ͨ��ʼѡȱ
#define SUB_S_HUANPAI_CHENGDU 123				//����

#define SUB_S_HUANPAI_NOTICE  125				//����

#define SUB_S_MASTER_HANDCARD		220									//
#define SUB_S_MASTER_LEFTCARD		221									//ʣ���ƶ�


#define ZI_PAI_COUNT	7												//����ȫ��

#define MASK_CHI_HU_RIGHT			0x0fffffff							//���ȨλDWORD����			

//��������
#define MAX_WEAVE					4									//������
#define MAX_INDEX					34									//�������
#define MAX_COUNT					14									//�����Ŀ
#define MAX_REPERTORY				108									//�����


//��Ϸ״̬
struct XZDD_CMD_S_StatusFree
{
	LONGLONG						lCellScore;							//�������
	WORD							wBankerUser;						//ׯ���û�
	bool							bTrustee[GAME_PLAYER];				//�Ƿ��й�
};

//��Ϸ״̬
struct XZDD_CMD_S_StatusPlay
{
	//��Ϸ����
	LONGLONG						lCellScore;									//��Ԫ����
	WORD							wBankerUser;								//ׯ���û�
	WORD							wCurrentUser;								//��ǰ�û�

	//״̬����
	BYTE							cbActionCard;								//�����˿�
	BYTE							cbActionMask;								//��������
	BYTE							cbLeftCardCount;							//ʣ����Ŀ
	bool							bTrustee[GAME_PLAYER];						//�Ƿ��й�
	WORD							wWinOrder[GAME_PLAYER];						//
	BYTE							cbWinCout;									//��ʤ��Ŀ

	//������Ϣ
	WORD							wOutCardUser;								//�����û�
	BYTE							cbOutCardData;								//�����˿�
	BYTE							cbDiscardCount[GAME_PLAYER];				//������Ŀ
	BYTE							cbDiscardCard[GAME_PLAYER][60];				//������¼

	//�˿�����
	BYTE							cbCardCount;								//�˿���Ŀ
	BYTE							cbCardData[MAX_COUNT];						//�˿��б�
	BYTE							cbSendCardData;								//�����˿�

	//����˿�
	BYTE							cbWeaveCount[GAME_PLAYER];					//�����Ŀ
	XZDD_CMD_WeaveItem					WeaveItemArray[GAME_PLAYER][MAX_WEAVE];		//����˿�

	//������Ϣ
	WORD							wHeapHand;									//����ͷ��
	WORD							wHeapTail;									//����β��
	BYTE							cbHeapCardInfo[GAME_PLAYER][2];				//������Ϣ


	BYTE							nQueColor[GAME_PLAYER];						//ȱɫ
	BYTE							nChiHuCard[GAME_PLAYER][60];
	WORD							nChiHuCardNum[GAME_PLAYER];

	bool                         bHasHu[GAME_PLAYER];
};

//��Ϸ��ʼ
struct XZDD_CMD_S_GameStart
{
	QYLONG							lSiceCount;									//���ӵ���
	WORD							wBankerUser;								//ׯ���û�
	WORD							wCurrentUser;								//��ǰ�û�
	BYTE							cbUserAction;								//�û�����
	BYTE							cbCardData[MAX_COUNT*GAME_PLAYER];			//�˿��б�
	WORD							wHeapHand;									//������ͷ
	WORD							wHeapTail;									//������β
	BYTE							cbHeapCardInfo[GAME_PLAYER][2];				//������Ϣ
	BYTE							cbLeftCardCount;							//

	BYTE							nLeftTime;                        //���Ƶ���ʱ
};

struct XZDD_CMD_S_StateHuanPai
{
	WORD							wBankerUser;								//ׯ���û�
	BYTE							cbCardData[MAX_COUNT];						//�˿��б�
	BYTE							cbLeftCardCount;							//
	BYTE							nLeftTime;									//���Ƶ���ʱ
	bool                            bHuan;									    //�Ƿ��Ѿ�����
};

struct XZDD_CMD_S_StateXuanQue
{
	WORD							wBankerUser;								//ׯ���û�
	BYTE							cbCardData[MAX_COUNT];						//�˿��б�
	BYTE							cbLeftCardCount;							//
	BYTE							nLeftTime;									//XuanQue����ʱ
	BYTE                            nQueColor;									
};
//��������
struct XZDD_CMD_S_OutCard
{
	WORD							wOutCardUser;						//�����û�
	BYTE							cbOutCardData;						//�����˿�
};

//�����˿�
struct XZDD_CMD_S_SendCard
{
	BYTE							cbCardData;							//�˿�����
	BYTE							cbActionMask;						//��������
	WORD							wCurrentUser;						//��ǰ�û�
	bool							bTail;								//ĩβ����

	BYTE                           nLeftTime;

	bool                        bHasHuPai;					//�Ƿ��Ѿ���
};


//������ʾ
struct XZDD_CMD_S_OperateNotify
{
	WORD							wResumeUser;						//��ԭ�û�
	BYTE							cbActionMask;						//��������
	BYTE							cbActionCard;						//�����˿�
	bool                         bHasHuPai;
};

//��������
struct XZDD_CMD_S_OperateResult
{
	WORD							wOperateUser;						//�����û�
	WORD							wProvideUser;						//��Ӧ�û�
	BYTE							cbOperateCode;						//��������
	BYTE							cbOperateCard;						//�����˿�
};


//�û��й�
struct XZDD_CMD_S_Trustee
{
	bool							bTrustee;							//�Ƿ��й�
	WORD							wChairID;							//�й��û�
};


//2016.5.20
struct XZDD_CMD_S_HuanPai
{
	WORD   wChairId;
	BYTE   cbHuanCard[3];
};
struct XZDD_CMD_S_HuanPaiChengDu
{
	WORD   wChairId;
	BYTE   cbRemoveHuanCard[3];
	BYTE   cbHuanCard[3];
	WORD   wSice;
};
struct XZDD_CMD_S_XuanQue
{
	BYTE nQueColor[4];
	BYTE nLeftTime;
};

struct XZDD_CMD_S_XuanQueNotice
{
	WORD   wChairId;
	BYTE nLeftTime;
	BYTE nQueColor;
};
//////////////////////////////////////////////////////////////////////////
//�ͻ�������ṹ

#define SUB_C_OUT_CARD				1									//��������
#define SUB_C_OPERATE_CARD			3									//�����˿�
#define SUB_C_TRUSTEE				4									//�û��й�

#define SUB_C_MASTER_LEFTCARD		6									//ʣ���ƶ�
#define SUB_C_MASTER_CHEAKCARD		7									//ѡ�����
#define SUB_C_MASTER_ZHANIAO		8									//����
//2016.5.20
#define SUB_C_HUANPAI 11				//����
#define SUB_C_XUANQUE 12				//ѡȱ

#define CARD_COLOR_NULL			0
#define CARD_COLOR_TONG			1
#define CARD_COLOR_WAN			2
#define CARD_COLOR_TIAO			3
//��������
struct XZDD_CMD_C_OutCard
{
	BYTE							cbCardData;							//�˿�����
};

//��������
struct XZDD_CMD_C_OperateCard
{
	BYTE							cbOperateCode;						//��������
	BYTE							cbOperateCard;						//�����˿�
};

//�û��й�
struct XZDD_CMD_C_Trustee
{
	bool							bTrustee;							//�Ƿ��й�	
};
//2016.5.20
struct XZDD_CMD_C_HuanPai
{
	BYTE    cbHuanCard[3];
	BYTE		nMasttKindColor;
};
struct XZDD_CMD_C_XuanQue
{
	BYTE nQueChoice;
};
//////////////////////////////////////////////////////////////////////////


struct  XZDD_Card_Info
{
	int		nLen;
	int		nColor;
	std::vector<BYTE> kCardList;

	bool   operator <  (const   XZDD_Card_Info&   rhs   )  const   //��������ʱ����д�ĺ���
	{  
		return   nLen   <   rhs.nLen;
	}
};

struct XZDD_MaterCheckCard
{
	BYTE							cbCheakCard;						//��������
};

struct XZDD_MaterNiaoCout
{
	BYTE							cbNiaoCout;							//��������
};

struct XZDD_MasterLeftCard
{
	BYTE      kMasterLeftIndex[MAX_INDEX];
	BYTE      kMasterCheakCard;
};


#pragma pack()


struct  XZDDGameRecordPlayer
{
	DWORD dwUserID;
	std::string kHead;
	std::string kNickName;
	std::vector<BYTE> cbCardData;
	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(dwUserID);
		Stream_VALUE(kHead);
		Stream_VALUE(kNickName);
		Stream_VECTOR(cbCardData);
	}
};

struct  XZDDGameRecordOperateResult
{
	enum Type
	{
		TYPE_NULL,
		TYPE_OperateResult,
		TYPE_SendCard,
		TYPE_OutCard,
		TYPE_ChiHu,
	};
	XZDDGameRecordOperateResult()
	{
		cbActionType = 0;
		wOperateUser = 0;
		wProvideUser = 0;
		cbOperateCode = 0;
		cbOperateCard = 0;
	}
	BYTE							cbActionType;
	WORD							wOperateUser;						//�����û�
	WORD							wProvideUser;						//��Ӧ�û�
	BYTE							cbOperateCode;						//��������
	BYTE							cbOperateCard;						//�����˿�
	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(cbActionType);
		Stream_VALUE(wOperateUser);
		Stream_VALUE(wProvideUser);
		Stream_VALUE(cbOperateCode);
		Stream_VALUE(cbOperateCard);
	}
};
struct  XZDDGameRecord
{
	std::vector<XZDDGameRecordPlayer> kPlayers;
	std::vector<XZDDGameRecordOperateResult> kAction;
	void StreamValue(datastream& kData,bool bSend)
	{
		StructVecotrMember(XZDDGameRecordPlayer,kPlayers);
		StructVecotrMember(XZDDGameRecordOperateResult,kAction);
	}

};


struct XZDD_MasterHandCardInfo
{
	int nChairId;
	std::vector<BYTE>    kMasterHandCard;

	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(nChairId);
		Stream_VECTOR(kMasterHandCard);
	}
};

struct XZDD_MasterHandCard
{
	std::vector<XZDD_MasterHandCardInfo>    kMasterHandCardList;
	void StreamValue(datastream& kData,bool bSend)
	{
		StructVecotrMember(XZDD_MasterHandCardInfo,kMasterHandCardList);
	}
};


struct XZDD_CMD_S_ChiHu
{
	WORD							wChiHuUser;							//
	WORD							wProviderUser;						//
	BYTE							cbChiHuCard;						//
	std::vector<SCORE>            lGameScore;
	DWORD						dwChiHuRight;			//��������
	BYTE							cbGenCount;							//

	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(wChiHuUser);
		Stream_VALUE(wProviderUser);
		Stream_VALUE(cbChiHuCard);
		Stream_VECTOR(lGameScore);
		Stream_VALUE(dwChiHuRight);
		Stream_VALUE(cbGenCount);
	}	
	void resizeData()
	{
		lGameScore.resize(GAME_PLAYER);
	}
};

//
struct XZDD_CMD_S_GangScore
{
	WORD							wChairId;							//
	WORD							wPravadeId;							//
	BYTE                         cbXiaYu;
	std::vector<SCORE>            lGangScore;

	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VALUE(wChairId);
		Stream_VALUE(wPravadeId);
		Stream_VALUE(cbXiaYu);
		Stream_VECTOR(lGangScore);
	}
	void resizeData()
	{
		lGangScore.resize(GAME_PLAYER);
	}
};

struct XZDD_CMD_CardInfoList
{
	std::vector<BYTE>					kHandCardList;
	std::vector<XZDD_CMD_WeaveItem>    kWeaveItemList;
	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VECTOR(kHandCardList);
		StructVecotrMember(XZDD_CMD_WeaveItem,kWeaveItemList);
	}
};

struct XZDD_AllEndInfo
{
	std::vector<SCORE>            lGameScoreTotal;
	std::vector<SCORE>            lHuaZhuScore;
	std::vector<SCORE>            lChaJiaoScore;
	std::vector<BYTE>				cbGenCount;
	std::vector<BYTE>				cbFanShu;
	std::vector<XZDD_CMD_S_ChiHu>		kChiHuInfoList;
	std::vector<XZDD_CMD_S_GangScore>   kGangInfoList;

	std::vector<XZDD_CMD_CardInfoList>   kCardInfoList;
	
	void StreamValue(datastream& kData,bool bSend)
	{
		Stream_VECTOR(lGameScoreTotal);
		Stream_VECTOR(lHuaZhuScore);
		Stream_VECTOR(lChaJiaoScore);
		Stream_VECTOR(cbGenCount);
		Stream_VECTOR(cbFanShu);
		StructVecotrMember(XZDD_CMD_S_ChiHu,kChiHuInfoList);
		StructVecotrMember(XZDD_CMD_S_GangScore,kGangInfoList);
		StructVecotrMember(XZDD_CMD_CardInfoList,kCardInfoList);
	}
	void resizeData()
	{
		lGameScoreTotal.resize(GAME_PLAYER);
		lHuaZhuScore.resize(GAME_PLAYER);
		lChaJiaoScore.resize(GAME_PLAYER);
		cbGenCount.resize(GAME_PLAYER);
		cbFanShu.resize(GAME_PLAYER);
		kCardInfoList.resize(GAME_PLAYER);
	}
};


#endif

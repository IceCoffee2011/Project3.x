#ifndef __SGLY_PROTOCOL_H__
#define __SGLY_PROTOCOL_H__

#include "Define.h"
#pragma pack(1)
//////////////////////////////////////////////////////////////////////////
//�����궨��

#define KIND_ID						32								//��Ϸ I D
#define GAME_PLAYER					100								//��Ϸ����

#define VERSION_SERVER				PROCESS_VERSION(6,0,3)			//����汾
#define VERSION_CLIENT				PROCESS_VERSION(6,0,3)			//����汾

#define GAME_NAME					TEXT("ˮ����԰")				//��Ϸ����
#define CLIENT_MODULE_NAME			TEXT("SGDZ_CLIENT.exe")			//�ͻ���ģ������
#define	SERVER_MODULE_NAME			TEXT("SGDZ_SERVER.DLL")			//�����ģ������

//״̬����
#define	GS_PLACE_JETTON				GAME_STATUS_PLAY				//��ע״̬
#define	GS_GAME_END					GAME_STATUS_PLAY+1				//����״̬

//�������
#define ID_BAR					0									//BAR����
#define ID_DOUBLE_SEVEN			1									//˫������
#define ID_STAR					2									//��������
#define ID_WATERMELON			3									//��������
#define ID_BELL					4									//��������
#define ID_PAWPAW				5									//ľ������
#define ID_ORANGE				6									//��������
#define ID_APPLE				7									//ƻ������

#define	PATH_STEP_NUMBER		24									//ת�������
#define JETTON_AREA_COUNT		8									//��ע��������

//��¼��Ϣ
struct SGLY_tagServerGameRecord
{
	DWORD	 	dwGameTimes;										//�ڼ���
	BYTE		cbRecord;											//��Χ��ID_BAR��ID_APPLE
	bool		bGoodLuck;
};

//////////////////////////////////////////////////////////////////////////
//����������ṹ

#define SGLY_SUB_S_GAME_FREE			99										//��Ϸ����
#define SGLY_SUB_S_GAME_START			100										//��Ϸ��ʼ
#define SGLY_SUB_S_PLACE_JETTON			101										//�û���ע
#define SGLY_SUB_S_GAME_END				102										//��Ϸ����
#define SGLY_SUB_S_APPLY_BANKER			103										//����ׯ��
#define SGLY_SUB_S_CHANGE_BANKER		104										//�л�ׯ��
#define SGLY_SUB_S_CHANGE_USER_SCORE	105										//���»���
#define SGLY_SUB_S_SEND_RECORD			106										//��Ϸ��¼
#define SGLY_SUB_S_PLACE_JETTON_FAIL	107										//��עʧ��
#define SGLY_SUB_S_CANCEL_BANKER		108										//ȡ������
#define SGLY_SUB_S_BIG_SMALL			109										//�´�С
#define SGLY_SUB_S_CHIP_UPDATE			110										//�һ�����
#define SGLY_SUB_S_ADMIN_COMMDN			111										//�����˺ſ���

//	���³���
struct SGLY_CMD_S_ChipUpdate
{
	WORD								wChairID;								//�һ���������
	LONGLONG							lTotalScore;							//����ҵ��ܳ���������Ӧ�ķ���
};

//�´�С
struct SGLY_CMD_S_BigSmall
{
	bool								bWin;									//�´�С�ɹ�
	BYTE								cbBigSmall;								//��С��ʵ����ֵ
	LONGLONG							lUserScore;								//��ҳɼ�
	LONGLONG							lBankerScore;							//ׯ�ҳɼ�
};

//�û���ע
struct SGLY_CMD_S_PlaceJetton
{
	WORD								wChairID;								//�û�λ��
	BYTE								cbJettonArea;							//��������
	LONGLONG							lJettonScore;							//��ע��Ŀ
	LONGLONG							lTotalJettonScore[JETTON_AREA_COUNT];	//	������ע���
	bool								cbAndroid;
};

//ʧ�ܽṹ
struct CMD_S_PlaceJettonFail
{
	BYTE								cbJettonArea;							//��ע����
	LONGLONG							lJettonScore;							//��ǰ��ע
};

//��ׯ�б����
struct SGLY_tagBankerListPlayer
{
	SGLY_tagBankerListPlayer(){memset(this, 0, sizeof(*this));}
	WORD wChairID;
	DWORD dwUserID;
	DOUBLE lScore;
	BYTE cbGender;
	TCHART szNickName[32];
};

//��ׯ�б�
struct SGLY_CMD_S_ApplyBankerList
{
	SGLY_CMD_S_ApplyBankerList(){memset(this, 0, sizeof(*this));}
	BYTE cbCount;//	��ׯ�б���Ҹ���
	inline SGLY_tagBankerListPlayer & operator [](unsigned int);
	int getLength()const{return sizeof(*this) + cbCount * sizeof(SGLY_tagBankerListPlayer);}
};

struct SGLY_CMD_S_ApplyBankerListMax:public SGLY_CMD_S_ApplyBankerList
{
	SGLY_tagBankerListPlayer wApplyList[GAME_PLAYER];
};

inline SGLY_tagBankerListPlayer & SGLY_CMD_S_ApplyBankerList::operator [](unsigned int index)
{
	return ((SGLY_tagBankerListPlayer *)((unsigned char *)this + sizeof(*this)))[index];
}

//����ׯ��
struct SGLY_CMD_S_ApplyBanker
{
	WORD								wApplyUser;								//�������
};

//ȡ������
struct SGLY_CMD_S_CancelBanker
{
	TCHART								szCancelUser[32];						//ȡ�����
	WORD								wChairID;								//ȡ�����chairID
};

//�л�ׯ��
struct SGLY_CMD_S_ChangeBanker
{
	WORD								wBankerUser;							//��ׯ���
	TCHART								szBankerNickName[32];					//	ׯ���ǳ�
	LONGLONG							lBankerScore;							//ׯ�ҽ��
	LONGLONG							lBankerChip;							//	ׯ�ҵ�ǰ���г���
};

//��Ϸ״̬
struct SGLY_CMD_S_StatusFree
{
	LONGLONG							lCurrentJetton[GAME_PLAYER];			//�������ϴ�ͬ��ÿ����ҵĳ�����
	DWORD								dwChipRate;								//�������
	//ȫ����Ϣ
	BYTE								cbTimeLeave;							//ʣ��ʱ��
	//�����Ϣ
	LONGLONG							lUserMaxScore;							//��ҽ��
	//ׯ����Ϣ
	WORD								wBankerUser;							//��ǰׯ��
	TCHART								szBankerNickName[32];					//	ׯ���ǳ�
	WORD								wBankerTime;							//ׯ�Ҿ���
	LONGLONG							lBankerWinScore;						//ׯ�ҳɼ�
	LONGLONG							lBankerScore;							//ׯ�ҷ���
	bool								bEnableSysBanker;						//ϵͳ��ׯ
	//������Ϣ
	LONGLONG							lApplyBankerCondition;					//��������
	LONGLONG							lAreaLimitScore[JETTON_AREA_COUNT];		//��������

	//��������
	TCHART								szRoomName[32];							//��������
};

//��Ϸ״̬
struct SGLY_CMD_S_StatusPlay
{
	LONGLONG							lCurrentJetton[GAME_PLAYER];			//�������ϴ�ͬ��ÿ����ҵĳ�����
	DWORD								dwChipRate;								//�������
	//ȫ����ע
	LONGLONG							lTotalJettonScore[JETTON_AREA_COUNT];
	//�����ע
	LONGLONG							lUserAreaScore[JETTON_AREA_COUNT];
	//��������ע
	LONGLONG							lAreaScoreLimit[JETTON_AREA_COUNT];		

	//�˿���Ϣ
	BYTE							cbWinArea;							//����ֹͣ��λ��
	BYTE							cbGoodLuckType;						//����GoodLuck
	BYTE							cbPaoHuoCheCount;
	BYTE							cbPaoHuoCheArea[7];

	//��һ���
	LONGLONG							lUserMaxScore;							//�����ע							
	//������Ϣ
	LONGLONG							lApplyBankerCondition;					//��������
	//�˿���Ϣ
	BYTE								cbCardCount[2];							//�˿���Ŀ
	BYTE								cbTableCardArray[2][3];					//�����˿�
	//ׯ����Ϣ
	WORD								wBankerUser;							//��ǰׯ��
	TCHART								szBankerNickName[32];					//	ׯ���ǳ�
	WORD								cbBankerTime;							//ׯ�Ҿ���
	LONGLONG							lBankerWinScore;						//ׯ��Ӯ��
	LONGLONG							lBankerScore;							//ׯ�ҷ���
	bool								bEnableSysBanker;						//ϵͳ��ׯ
	//������Ϣ
	LONGLONG							lEndBankerScore;						//ׯ�ҳɼ�
	LONGLONG							lEndUserScore;							//��ҳɼ�
	LONGLONG							lEndUserReturnScore;					//���ػ���
	LONGLONG							lEndRevenue;							//��Ϸ˰��
	//ȫ����Ϣ
	BYTE								cbTimeLeave;							//ʣ��ʱ��
	BYTE								cbGameStatus;							//��Ϸ״̬

	//��������
	TCHART								szRoomName[32];							//��������
};

//��Ϸ����
struct SGLY_CMD_S_GameFree
{
	BYTE								cbTimeLeave;							//ʣ��ʱ��
	BYTE								cbGameRecordCount;
	SGLY_tagServerGameRecord			cbGameRecord[8];
	//BYTE								cbGameRecord;							//���ο����Ľ��
	//LONGLONG							lGameTimes;								//��ǰ����Ϸ���������ĵڼ���
	LONGLONG							lApplyBankerCondition;
	DWORD								wApplyUserCount;
	LONGLONG							lBankerTotallScore;						//ׯ�ҳɼ�
	int									iBankerTime;							//��ׯ����
};

//��Ϸ��ʼ
struct SGLY_CMD_S_GameStart
{
	WORD								wBankerUser;							//ׯ��λ��
	LONGLONG							lBankerScore;							//ׯ�ҽ��
	LONGLONG							lUserMaxScore;							//�ҵĽ��
	BYTE								cbTimeLeave;							//ʣ��ʱ��
	LONGLONG							lAreaLimitScore[JETTON_AREA_COUNT];		//��������·�
};

//��Ϸ����
struct SGLY_CMD_S_GameEnd
{
	//�¾���Ϣ
	BYTE								cbTimeLeave;							//ʣ��ʱ��
	//�˿���Ϣ
	BYTE								cbWinArea;								//����ֹͣ��λ��
	BYTE								cbGoodLuckType;							//����GoodLuck
	BYTE								cbPaoHuoCheCount;
	BYTE								cbPaoHuoCheArea[7];
	//ׯ����Ϣ
	LONGLONG							lBankerScore;							//ׯ�ҳɼ�
	LONGLONG							lBankerTotallScore;						//ׯ�ҳɼ�
	int									iBankerTime;							//��ׯ����
	//��ҳɼ�
	LONGLONG							lUserScore;								//��ҳɼ�
	LONGLONG							lUserReturnScore;						//���ػ���
	//ȫ����Ϣ
	LONGLONG							lRevenue;								//��Ϸ˰��
	LONGLONG							lApplyBankerCondition;
};

//////////////////////////////////////////////////////////////////////////
//�ͻ�������ṹ

#define SGLY_SUB_C_PLACE_JETTON			1										//�û���ע
#define SGLY_SUB_C_APPLY_BANKER			2										//����ׯ��
#define SGLY_SUB_C_CANCEL_BANKER		3										//ȡ������
#define SGLY_SUB_C_BIG_SMALL			4										//�´�С
#define SGLY_SUB_C_EXCHANGE				5										//�һ�����
#define SGLY_SUB_C_ADMIN_COMMDN			6										//�����˺ſ���
#define SGLY_SUB_C_GET_PLAYLIST			7										//��ׯ�б�

//�һ�����
struct SGLY_CMD_C_Exchange
{
	LONGLONG							lExchangeScore;							//�һ��ɳ�����ܷ��������Ǳ���Ҫ�һ��ķ����������ܵķ�����
};

//�´�С	��С��0����1��
struct SGLY_CMD_C_BigSmall
{
	BYTE								cbBigSmall;
};

//�û���ע
struct SGLY_CMD_C_PlaceJetton
{
	BYTE								cbJettonArea;							//��������
	LONGLONG							lJettonScore;							//��ע��Ŀ
};

//�������
enum SGLY_enOperateResult
{
	enOperateResult_NULL,
	enOperateResult_Win,
	enOperateResult_Lost
};

//��¼��Ϣ
struct SGLY_tagClientGameRecord
{
	SGLY_enOperateResult				enOperateFlags;							//������ʶ
	BYTE								cbPlayerCount;							//�мҵ���
	BYTE								cbBankerCount;							//ׯ�ҵ���
	BYTE								cbKingWinner;							//����Ӯ��
	bool								bPlayerTwoPair;							//���ӱ�ʶ
	bool								bBankerTwoPair;							//���ӱ�ʶ
};

//��ʷ��¼
#define MAX_SCORE_HISTORY			1000								//��ʷ����
#define MAX_SHOW_HISTORY			10									//һ�������ʾ����ʷ��¼����

//ͬʱ��ʾ������ׯ�������
#define MAX_SCORE_BANKER			4
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//����������Ϣ
struct SGLY_tagControlInfo
{
	BYTE cbControlArea;						//��������
};

//���������Ʒ���
#define	 S_CR_FAILURE				0		//ʧ��
#define  S_CR_UPDATE_SUCCES			1		//���³ɹ�
#define	 S_CR_SET_SUCCESS			2		//���óɹ�
#define  S_CR_CANCEL_SUCCESS		3		//ȡ���ɹ�

struct SGLY_CMD_S_ControlReturns
{
	BYTE cbReturnsType;				//�ظ�����
	BYTE cbControlArea;				//��������
	BYTE cbControlTimes;			//���ƴ���
};

//�ͻ��˿�������
#define  C_CA_UPDATE				1		//����
#define	 C_CA_SET					2		//����
#define  C_CA_CANCELS				3		//ȡ��
struct SGLY_CMD_C_ControlApplication
{
	BYTE cbControlAppType;			//��������
	BYTE cbControlArea;				//��������
	BYTE cbControlTimes;			//���ƴ���
};
//////////////////////////////////////////////////////////////////////////
#pragma pack()
#endif	//	__SGLY_PROTOCOL_H__

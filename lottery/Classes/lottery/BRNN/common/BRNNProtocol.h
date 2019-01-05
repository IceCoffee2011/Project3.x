#ifndef __BRNN_PROTOCOL_H__
#define __BRNN_PROTOCOL_H__

#include "Define.h"
#pragma pack(1)


//////////////////////////////////////////////////////////////////////////
//�����궨��

#define KIND_ID						104									//��Ϸ I D
#define GAME_PLAYER					100									//��Ϸ����
#define BRNN_GAME_PLAYER					100							//��Ϸ����
#define GAME_NAME					TEXT("����ţţ")					//��Ϸ����

//״̬����
#define	GS_PLACE_JETTON				GAME_STATUS_PLAY					//��ע״̬
#define	GS_GAME_END					GAME_STATUS_PLAY+1					//����״̬
#define	GS_MOVECARD_END				GAME_STATUS_PLAY+2					//����״̬

//�������
#define BANKER_INDEX				0									//ׯ������
#define SHUN_MEN_INDEX				1									//˳������
#define DUI_MEN_INDEX				2									//��������
#define DAO_MEN_INDEX				3									//��������
#define HUAN_MEN_INDEX				4									//��������
#define MAX_INDEX					3									//�������

#define AREA_COUNT					4									//������Ŀ
//���ʶ���
#define RATE_TWO_PAIR				12									//��������
#define SERVER_LEN					32									//���䳤��


//////////////////////////////////////////////////////////////////////////
//����������ṹ

#define BRNN_SUB_S_GAME_FREE				99									//��Ϸ����
#define BRNN_SUB_S_GAME_START				100									//��Ϸ��ʼ
#define BRNN_SUB_S_PLACE_JETTON				101									//�û���ע
#define BRNN_SUB_S_GAME_END					102									//��Ϸ����
#define BRNN_SUB_S_APPLY_BANKER				103									//����ׯ��
#define BRNN_SUB_S_CHANGE_BANKER			104									//�л�ׯ��
#define BRNN_SUB_S_CHANGE_USER_SCORE		105									//���»���
#define BRNN_SUB_S_SEND_RECORD				106									//��Ϸ��¼
#define BRNN_SUB_S_PLACE_JETTON_FAIL		107									//��עʧ��
#define BRNN_SUB_S_CANCEL_BANKER			108									//ȡ������
#define BRNN_SUB_S_SEND_ACCOUNT				109									//�����˺�
#define BRNN_SUB_S_ADMIN_CHEAK				111									//��ѯ�˺�


#define BRNN_SUB_S_AMDIN_COMMAND			110									//����Ա����

//����ظ�
struct BRNN_CMD_S_CommandResult
{
	BYTE cbAckType;					//�ظ�����
		#define ACK_SET_WIN_AREA  1
		#define ACK_PRINT_SYN     2
		#define ACK_RESET_CONTROL 3
	BYTE cbResult;
		#define CR_ACCEPT  2			//����
		#define CR_REFUSAL 3			//�ܾ�
	BYTE cbExtendData[20];			//��������
};
//ʧ�ܽṹ
struct BRNN_CMD_S_PlaceJettonFail
{
	WORD							wPlaceUser;							//��ע���
	BYTE							lJettonArea;						//��ע����
	LONGLONG						lPlaceScore;						//��ǰ��ע
};

//��¼��Ϣ
struct BRNN_tagServerGameRecord
{
	bool							bWinShunMen;						//	��
	bool							bWinDuiMen;							//	��
	bool							bWinDaoMen;							//	��
	bool							bWinHuang;							//	��
};

//���»���
struct BRNN_CMD_S_ChangeUserScore
{
	WORD							wChairID;							//���Ӻ���
	DOUBLE							lScore;								//��һ���

	//ׯ����Ϣ
	WORD							wCurrentBankerChairID;				//��ǰׯ��
	BYTE							cbBankerTime;						//ׯ�Ҿ���
	DOUBLE							lCurrentBankerScore;				//ׯ�ҷ���
};

//��ׯ�б����
struct BRNN_tagBankerListPlayer
{
	BRNN_tagBankerListPlayer(){memset(this, 0, sizeof(*this));}
	WORD wChairID;
	DWORD dwUserID;
	DOUBLE lScore;
	BYTE cbGender;
	TCHART szNickName[32];
};

//��ׯ�б�
struct BRNN_CMD_S_ApplyBankerList
{
	BRNN_CMD_S_ApplyBankerList(){memset(this, 0, sizeof(*this));}
	BYTE cbCount;//	��ׯ�б���Ҹ���
	inline BRNN_tagBankerListPlayer & operator [](unsigned int);
	int getLength()const{return sizeof(*this) + cbCount * sizeof(BRNN_tagBankerListPlayer);}
};

inline BRNN_tagBankerListPlayer & BRNN_CMD_S_ApplyBankerList::operator [](unsigned int index)
{
	return ((BRNN_tagBankerListPlayer *)((unsigned char *)this + sizeof(*this)))[index];
}

//����ׯ��
struct BRNN_CMD_S_ApplyBanker
{
	WORD							wApplyUser;							//�������
};

//ȡ������
struct BRNN_CMD_S_CancelBanker
{
	TCHART							szCancelUser[32];					//ȡ�����
	WORD							wChairID;							//�û�����ID
};

//�л�ׯ��
struct BRNN_CMD_S_ChangeBanker
{
	WORD							wBankerUser;						//��ׯ���
	TCHART							szBankerNickName[32];				//	ׯ���ǳ�
	BYTE							cbBankerGender;						//	ׯ���Ա�
	LONGLONG						lBankerScore;						//ׯ�ҽ��
};

//��Ϸ״̬
struct BRNN_CMD_S_StatusFree
{
	//ȫ����Ϣ
	BYTE							cbTimeLeave;						//ʣ��ʱ��

	//�����Ϣ
	LONGLONG						lUserMaxScore;						//��ҽ��

	//ׯ����Ϣ
	WORD							wBankerUser;						//��ǰׯ��
	TCHART							szBankerNickName[32];				//	ׯ���ǳ�
	BYTE							cbBankerGender;						//	ׯ���Ա�
	WORD							cbBankerTime;						//ׯ�Ҿ���
	LONGLONG						lBankerWinScore;					//ׯ�ҳɼ�
	LONGLONG						lBankerScore;						//ׯ�ҷ���
	bool							bEnableSysBanker;					//ϵͳ��ׯ

	//������Ϣ
	LONGLONG						lApplyBankerCondition;				//��������
	LONGLONG						lAreaLimitScore;					//��������

	//������Ϣ
	TCHART							szGameRoomName[SERVER_LEN];			//��������
};

//��Ϸ״̬
struct BRNN_CMD_S_StatusPlay
{
	//ȫ����ע
	LONGLONG						lAllJettonScore[AREA_COUNT+1];		//ȫ����ע

	//�����ע
	LONGLONG						lUserJettonScore[AREA_COUNT+1];		//������ע

	//��һ���
	LONGLONG						lUserMaxScore;						//�����ע							

	//������Ϣ
	LONGLONG						lApplyBankerCondition;				//��������
	LONGLONG						lAreaLimitScore;					//��������

	//�˿���Ϣ
	BYTE							cbTableCardArray[5][5];				//�����˿�

	bool							bResult[AREA_COUNT];				//	ʤ�����

	//ׯ����Ϣ
	WORD							wBankerUser;						//��ǰׯ��
	TCHART							szBankerNickName[32];				//	ׯ���ǳ�
	BYTE							cbBankerGender;						//	ׯ���Ա�

	WORD							cbBankerTime;						//ׯ�Ҿ���
	LONGLONG						lBankerWinScore;					//ׯ��Ӯ��
	LONGLONG						lBankerScore;						//ׯ�ҷ���
	bool							bEnableSysBanker;					//ϵͳ��ׯ

	//������Ϣ
	LONGLONG						lEndBankerScore;					//ׯ�ҳɼ�
	LONGLONG						lEndUserScore;						//��ҳɼ�
	LONGLONG						lEndUserReturnScore;				//���ػ���
	LONGLONG						lEndRevenue;						//��Ϸ˰��

	//ȫ����Ϣ
	BYTE							cbTimeLeave;						//ʣ��ʱ��
	BYTE							cbGameStatus;						//��Ϸ״̬

	//������Ϣ
	TCHART							szGameRoomName[SERVER_LEN];			//��������
};

//��Ϸ����
struct BRNN_CMD_S_GameFree
{
	BYTE							cbTimeLeave;						//ʣ��ʱ��
	LONGLONG                        nListUserCount;						//�б�����
};

//��Ϸ��ʼ
struct BRNN_CMD_S_GameStart
{
	WORD							wBankerUser;						//ׯ��λ��
	LONGLONG						lBankerScore;						//ׯ�ҽ��
	LONGLONG						lUserMaxScore;						//�ҵĽ��
	BYTE							cbTimeLeave;						//ʣ��ʱ��
	bool							bContiueCard;						//��������
	int								nChipRobotCount;					//�������� (��ע������)
};

//�û���ע
struct BRNN_CMD_S_PlaceJetton
{
	WORD							wChairID;							//�û�λ��
	BYTE							cbJettonArea;						//��������
	LONGLONG						lJettonScore;						//��ע��Ŀ
	bool							bIsAndroid;							//�Ƿ������
};

//��Ϸ����
struct BRNN_CMD_S_GameEnd
{
	//�¾���Ϣ
	BYTE							cbTimeLeave;						//ʣ��ʱ��

	//�˿���Ϣ
	BYTE							cbTableCardArray[5][5];				//�����˿�
	BYTE							cbLeftCardCount;					//�˿���Ŀ

	bool							bResult[AREA_COUNT];				//	ʤ�����

	BYTE							bcFirstCard[2];

	//ׯ����Ϣ
	SCORE							lBankerScore;						//ׯ�ҳɼ�
	SCORE							lBankerTotallScore;					//ׯ�ҳɼ�
	int								nBankerTime;						//��ׯ����

	//��ҳɼ�
	SCORE							lUserScore;							//��ҳɼ�
	SCORE							lUserReturnScore;					//���ػ���

	//ȫ����Ϣ
	SCORE							lRevenue;							//��Ϸ˰��
};

//////////////////////////////////////////////////////////////////////////
//�ͻ�������ṹ

#define BRNN_SUB_C_PLACE_JETTON			1									//�û���ע
#define BRNN_SUB_C_APPLY_BANKER			2									//����ׯ��
#define BRNN_SUB_C_CANCEL_BANKER		3									//ȡ������
#define BRNN_SUB_C_CONTINUE_CARD		4									//��������
#define BRNN_SUB_C_AMDIN_COMMAND		5									//����Ա����
#define BRNN_SUB_C_GET_ACCOUNT			6									//��ȡ�ǳ�
#define BRNN_SUB_C_CHEAK_ACCOUNT		7									//��ȡ�ǳ�
#define BRNN_SUB_C_GET_PLAYLIST			8									//��ׯ�б�

//�ͻ�����Ϣ
#define IDM_ADMIN_COMMDN			WM_USER+1000
#define IDM_GET_ACCOUNT				WM_USER+1001
#define IDM_CHEAK_ACCOUNT			WM_USER+1002

//�û���ע
struct BRNN_CMD_C_PlaceJetton
{
	BYTE							cbJettonArea;						//��������
	LONGLONG						lJettonScore;						//��ע��Ŀ
};

//////////////////////////////////////////////////////////////////////////
#pragma pack()
#endif	//	__BRNN_PROTOCOL_H__

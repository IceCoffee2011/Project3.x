#ifndef __PPC_PROTOCOL_H__
#define __PPC_PROTOCOL_H__

#include "Define.h"
#pragma pack(1)
//////////////////////////////////////////////////////////////////////////


//�����궨��

#define KIND_ID						108									//��Ϸ I D
#define GAME_PLAYER					100									//��Ϸ����
#define GAME_NAME					TEXT("������")						//��Ϸ����

//�汾��Ϣ
#define VERSION_SERVER			    PROCESS_VERSION(6,0,3)				//����汾
#define VERSION_CLIENT				PROCESS_VERSION(6,0,3)				//����汾

//״̬����
#define	GS_PLACE_JETTON				GAME_STATUS_PLAY						//��ע״̬
#define	GS_GAME_END					GAME_STATUS_PLAY+1						//����״̬
#define	GS_MOVECARD_END				GAME_STATUS_PLAY+2						//����״̬

//��������
#define ID_TIAN_MEN					1									//˳��
#define ID_DI_MEN					2									//��߽�
#define ID_XUAN_MEN					3									//��
#define ID_HUANG_MEN				4									//����

//�������
#define BANKER_INDEX				0									//ׯ������
#define SHUN_MEN_INDEX				1									//˳������
#define DUI_MEN_INDEX				2									//��������
#define DAO_MEN_INDEX				3									//��������
#define HUAN_MEN_INDEX				4									//��������

#define AREA_COUNT					8									//������Ŀ


//���ʶ���
#define RATE_TWO_PAIR				12									//��������

//��������Ϣ
struct ppcTagRobotInfo
{
	int nChip[6];														//���붨��
	int nAreaChance[AREA_COUNT];										//������
	TCHART szCfgFileName[260];										//�����ļ�
	int	nMaxTime;														//�������

	ppcTagRobotInfo()
	{
		int nTmpChip[6] = {1,5,10,100,500,1000};
		int nTmpAreaChance[AREA_COUNT] = {1, 2, 2, 5, 10, 10, 10, 10};
// 		TCHART szTmpCfgFileName[MAX_PATH] = _T("BumperCarBattle.ini");

		nMaxTime = 1;
		memcpy(nChip, nTmpChip, sizeof(nChip));
		memcpy(nAreaChance, nTmpAreaChance, sizeof(nAreaChance));
// 		memcpy(szCfgFileName, szTmpCfgFileName, sizeof(szCfgFileName));
	}
};

//��¼��Ϣ
struct ppcTagServerGameRecord
{
	BYTE							bWinMen[AREA_COUNT+1];						//˳��ʤ��
};

//////////////////////////////////////////////////////////////////////////
//����������ṹ

#define SUB_S_TO_ANDROID			98									//ׯ��ȡǮ
#define SUB_S_GAME_FREE				99									//��Ϸ����
#define SUB_S_GAME_START			100									//��Ϸ��ʼ
#define SUB_S_PLACE_JETTON			101									//�û���ע
#define SUB_S_GAME_END				102									//��Ϸ����
#define SUB_S_APPLY_BANKER			103									//����ׯ��
#define SUB_S_CHANGE_BANKER			104									//�л�ׯ��
#define SUB_S_CHANGE_USER_SCORE		105									//���»���
#define SUB_S_SEND_RECORD			106									//��Ϸ��¼
#define SUB_S_PLACE_JETTON_FAIL		107									//��עʧ��
#define SUB_S_CANCEL_BANKER			108									//ȡ������
#define SUB_S_CHECK_IMAGE			109									//ȡ������
#define SUB_S_ADMIN_COMMDN			110									//ϵͳ����


//ʧ�ܽṹ
struct ppcCMD_S_PlaceJettonFail
{
	WORD						wPlaceUser;							//��ע���
	BYTE						lJettonArea;						//��ע����
	SCORE						lPlaceScore;						//��ǰ��ע
};

//���»���
struct ppcCMD_S_ChangeUserScore
{
	WORD						wChairID;							//���Ӻ���
	DOUBLE						lScore;								//��һ���

	//ׯ����Ϣ
	WORD						wCurrentBankerChairID;				//��ǰׯ��
	BYTE						cbBankerTime;						//ׯ�Ҿ���
	DOUBLE						lCurrentBankerScore;				//ׯ�ҷ���
};

//��ׯ�б����
struct ppcTagBankerListPlayer
{
	ppcTagBankerListPlayer(){memset(this, 0, sizeof(*this));}
	WORD wChairID;				//	����ID
	DWORD dwUserID;				//	�û�ID
	DOUBLE lScore;				//	�����
	BYTE cbGender;				//	�Ա�
	TCHART szNickName[32];		//	�ǳ�
};

//��ׯ�б�
struct ppcCMD_S_ApplyBankerList
{
	ppcCMD_S_ApplyBankerList(){memset(this, 0, sizeof(*this));}
	BYTE cbCount;//	��ׯ�б���Ҹ���
	inline ppcTagBankerListPlayer & operator [](unsigned int);
	int getLength()const{return sizeof(*this) + cbCount * sizeof(ppcTagBankerListPlayer);}
};

inline ppcTagBankerListPlayer & ppcCMD_S_ApplyBankerList::operator [](unsigned int index)
{
	return ((ppcTagBankerListPlayer *)((unsigned char *)this + sizeof(*this)))[index];
}

//����ׯ��
struct ppcCMD_S_ApplyBanker
{
	WORD						wApplyUser;							//������ң�����ID��
};

//ȡ������
struct ppcCMD_S_CancelBanker
{
	TCHART					    szCancelUser[32];					//ȡ�����
	WORD						wChairID;							//���Ӻ���
};

//�л�ׯ��
struct ppcCMD_S_ChangeBanker
{
	WORD						wBankerUser;						//��ׯ���
	TCHART						szBankerNickName[32];				//	ׯ���ǳ�
	SCORE						lBankerScore;						//ׯ�ҽ��
};

//����״̬
struct ppcCMD_S_StatusFree
{
	//ȫ����Ϣ
	BYTE						cbTimeLeave;						//ʣ��ʱ��

	//�����Ϣ
	SCORE						lUserMaxScore;						//��ҽ��

	//ׯ����Ϣ
	WORD						wBankerUser;						//��ǰׯ��
	TCHART						szBankerNickName[32];				//	ׯ���ǳ�
	WORD						cbBankerTime;						//ׯ�Ҿ���
	SCORE						lBankerWinScore;					//ׯ�ҳɼ�
	SCORE						lBankerScore;						//ׯ�ҷ���
	bool						bEnableSysBanker;					//ϵͳ��ׯ

	//������Ϣ
	SCORE						lApplyBankerCondition;				//��������
	SCORE						lAreaLimitScore;					//��������
	int							CheckImage;

	TCHART						szGameRoomName[32];					//�������� 
};

//��Ϸ״̬
struct ppcCMD_S_StatusPlay
{
	//ȫ����ע
	SCORE						lAllJettonScore[AREA_COUNT+1];		//ȫ����ע

	//�����ע
	SCORE						lUserJettonScore[AREA_COUNT+1];		//������ע

	//��һ���
	SCORE						lUserMaxScore;						//�����ע							

	//������Ϣ
	SCORE						lApplyBankerCondition;				//��������
	SCORE						lAreaLimitScore;					//��������

	//�˿���Ϣ
	BYTE						cbTableCardArray[1][1];				//�����˿�

	//ׯ����Ϣ
	WORD						wBankerUser;						//��ǰׯ��
	TCHART						szBankerNickName[32];				//	ׯ���ǳ�
	WORD						cbBankerTime;						//ׯ�Ҿ���
	SCORE						lBankerWinScore;					//ׯ��Ӯ��
	SCORE						lBankerScore;						//ׯ�ҷ���
	bool						bEnableSysBanker;					//ϵͳ��ׯ

	//������Ϣ
	SCORE						lEndBankerScore;					//ׯ�ҳɼ�
	SCORE						lEndUserScore;						//��ҳɼ�
	SCORE						lEndUserReturnScore;				//���ػ���
	SCORE						lEndRevenue;						//��Ϸ˰��

	//ȫ����Ϣ
	BYTE						cbTimeLeave;						//ʣ��ʱ��
	BYTE						cbGameStatus;						//��Ϸ״̬
	int							CheckImage;
	TCHART						szGameRoomName[32];					//�������� 
};

//��Ϸ����
struct ppcCMD_S_GameFree
{
	BYTE						cbTimeLeave;						//ʣ��ʱ��
};

//��Ϸ��ʼ
struct ppcCMD_S_GameStart
{
	WORD						wBankerUser;						//��ǰׯ��
	SCORE						lBankerScore;						//ׯ�ҽ��
	SCORE						lUserMaxScore;						//�ҵĽ��
	BYTE						cbTimeLeave;						//ʣ��ʱ��	
	bool						bContiueCard;						//��������
	int							nChipRobotCount;					//�������� (��ע������)
};

//�û���ע
struct ppcCMD_S_PlaceJetton
{
	WORD						wChairID;							//�û�λ��
	BYTE						cbJettonArea;						//��������
	SCORE						lJettonScore;						//��ע��Ŀ
	BYTE						cbAndroid;							//������
};

//��Ϸ����
struct ppcCMD_S_GameEnd
{
	//�¾���Ϣ
	BYTE						cbTimeLeave;						//ʣ��ʱ��

	//�˿���Ϣ
	BYTE						cbTableCardArray[1][1];				//�����˿�
	BYTE						cbLeftCardCount;					//�˿���Ŀ

	BYTE						bcFirstCard;
 
	//ׯ����Ϣ
	SCORE						lBankerScore;						//ׯ�ҳɼ�
	SCORE						lBankerTotallScore;					//ׯ�ҳɼ�
	int							nBankerTime;						//��ׯ����
								
	//��ҳɼ�
	SCORE						lUserScore;							//��ҳɼ�
	SCORE						lUserReturnScore;					//���ػ���

	//ȫ����Ϣ
	SCORE						lRevenue;							//��Ϸ˰��
};

//////////////////////////////////////////////////////////////////////////
//�ͻ�������ṹ

#define SUB_C_PLACE_JETTON			1									//�û���ע
#define SUB_C_APPLY_BANKER			2									//����ׯ��
#define SUB_C_CANCEL_BANKER			3									//ȡ������
#define SUB_C_CONTINUE_CARD			4									//��������
#define SUB_C_CHECK_IMAGE			5									//��������
#define SUB_C_ADMIN_COMMDN			6									//ϵͳ����
#define SUB_C_GET_ACCOUNT			7									//��ȡ�ʺ�
#define SUB_C_CHECK_ACCOUNT			8									//��ȡ�ʺ�
#define SUB_S_SCORE_RESULT			9									//���ֽ��
#define SUB_S_ACCOUNT_RESULT		10									//�ʺŽ��
#define SUB_C_GET_PLAYLIST			11									//��ׯ�б�

//�û�������ע
struct ppcCMD_C_PlaceJetton
{
	BYTE						cbJettonArea;						//��������
	SCORE						lJettonScore;						//��ע��Ŀ
};

struct ppcCMD_C_CheckImage
{
	int Index;
};

//////////////////////////////////////////////////////////////////////////

#define IDM_ADMIN_COMMDN	WM_USER+1000
#define IDM_GET_ACCOUNT		WM_USER+1001
#define IDM_CHEAK_ACCOUNT	WM_USER+1002

//����������Ϣ
struct ppcTagControlInfo
{
	BYTE cbControlArea;						//��������
};

//���������Ʒ���
#define	 S_CR_FAILURE				0		//ʧ��
#define  S_CR_UPDATE_SUCCES			1		//���³ɹ�
#define	 S_CR_SET_SUCCESS			2		//���óɹ�
#define  S_CR_CANCEL_SUCCESS		3		//ȡ���ɹ�
struct ppcCMD_S_ControlReturns
{
	BYTE cbReturnsType;				//�ظ�����
	BYTE cbControlArea;				//��������
	BYTE cbControlTimes;			//���ƴ���
};


//�ͻ��˿�������
#define  C_CA_UPDATE				1		//����
#define	 C_CA_SET					2		//����
#define  C_CA_CANCELS				3		//ȡ��
struct ppcCMD_C_ControlApplication
{
	BYTE cbControlAppType;			//��������
	BYTE cbControlArea;				//��������
	BYTE cbControlTimes;			//���ƴ���
};

struct ppcCMD_C_CheakAccount
{
	TCHART szUserAccount[32];
};

struct ppcCMD_S_ScoreResult
{
	SCORE lUserJettonScore[AREA_COUNT+1];	//������ע
};

struct ppcCMD_S_AccountResult
{
	TCHART szAccount[100][32];					//�ʺ��ǳ�
};

//////////////////////////////////////////////////////////////////////////
#pragma pack()
#endif	//	__PPC_PROTOCOL_H__

#ifndef DDZ_CMD_GAMECLIENT_HEAD_FILE
#define DDZ_CMD_GAMECLIENT_HEAD_FILE
#include "Define.h"
#pragma pack(1)

//////////////////////////////////////////////////////////////////////////////////
//�����궨��

#define DDZKIND_ID					200									//��Ϸ I D
#define DDZGAME_PLAYER				3							        //��Ϸ����
#define GAME_NAME					TEXT("������")						//��Ϸ����

//�������
#define VERSION_SERVER				PROCESS_VERSION(6,0,3)				//����汾
#define VERSION_CLIENT				PROCESS_VERSION(6,0,3)				//����汾

//״̬����
#define GAME_SCENE_FREE				GAME_STATUS_FREE					//�ȴ���ʼ
#define GAME_SCENE_PLAY				GAME_STATUS_PLAY					//��Ϸ����
#define GAME_SCENE_BET				GAME_STATUS_PLAY					//��ע״̬
#define	GAME_SCENE_END				GAME_STATUS_PLAY+1					//����״̬
//��Ŀ����
#define MAX_COUNT					20									//�����Ŀ
#define FULL_COUNT					54									//ȫ����Ŀ

//�߼���Ŀ
#define NORMAL_COUNT				17									//������Ŀ
#define DISPATCH_COUNT				51									//�ɷ���Ŀ
#define GOOD_CARD_COUTN				38									//������Ŀ

//��ֵ����
#define	MASK_COLOR					0xF0								//��ɫ����
#define	MASK_VALUE					0x0F								//��ֵ����

//�߼�����
#define CT_ERROR					0									//��������
#define CT_SINGLE					1									//��������
#define CT_DOUBLE					2									//��������
#define CT_THREE					3									//��������
#define CT_SINGLE_LINE				4									//��������
#define CT_DOUBLE_LINE				5									//��������
#define CT_THREE_LINE				6									//��������
#define CT_THREE_TAKE_ONE			7									//����һ��
#define CT_THREE_TAKE_TWO			8									//����һ��
#define CT_FOUR_TAKE_ONE			9									//�Ĵ�����
#define CT_FOUR_TAKE_TWO			10									//�Ĵ�����
#define CT_BOMB_CARD				11									//ը������
#define CT_MISSILE_CARD				12									//�������

//////////////////////////////////////////////////////////////////////////////////
//״̬����
/*
#define GAME_SCENE_FREE				GAME_STATUS_FREE					//�ȴ���ʼ
#define GAME_SCENE_CALL				GAME_STATUS_PLAY					//�з�״̬
#define GAME_SCENE_PLAY				GAME_STATUS_PLAY+1					//��Ϸ����
*/

//��Ϸ״̬   �������¼Ӳ���
#define GAME_SCENE_FREE				GAME_STATUS_FREE					//�ȴ���ʼ
#define GAME_SCENE_CALL				GAME_STATUS_PLAY					//�е���״̬
#define GAME_SCENE_ROD				GAME_STATUS_PLAY+1					//������״̬
//#define GAME_SCENE_ADD				GAME_STATUS_PLAY+2					//�ӱ�״̬
#define GAME_SCENE_PLAY				GAME_STATUS_PLAY+2					//��Ϸ����


#define AREA_MAX					8									//�������
//���ʶ���
#define RATE_TWO_PAIR				12									//��������
#define SERVER_LEN					32									//���䳤��

#if 0
//#define KIND_ID						ID_LAND						        //��Ϸ I D
#define DDZGAME_PLAYER					3									//��Ϸ����
//#define GAME_NAME					TEXT("��������Ϸ")					//��Ϸ����
#define GAME_GENRE					(GAME_GENRE_SCORE|GAME_GENRE_GOLD)	//��Ϸ����
#define MAX_COUNT					20
#define GAME_WIDTH				1024
#define GAME_HEIGHT				738

//���������λ��
#define CHAT_DLG_X					740                     
#define CHAT_DLG_Y					650
#endif

//��Ϸ����
struct DDZCMD_S_GameFree
{
	//��Ϸ����
	LONG							lCellScore;							//��������

	//ʱ����Ϣ
	BYTE							cbTimeCallBanker;					//�е���ʱ��
	BYTE							cbTimeRodBanker;					//������ʱ��
	BYTE							cbTimeOutCard;						//����ʱ��
	//BYTE							cbTimeCallScore;					//�з�ʱ��
	BYTE							cbTimeStartGame;					//��ʼʱ��
	BYTE							cbTimeHeadOutCard;					//�׳�ʱ��

	//��ʷ����
	SCORE							lTurnScore[DDZGAME_PLAYER];			//������Ϣ
	SCORE							lCollectScore[DDZGAME_PLAYER];			//������Ϣ
};

//�е���״̬
struct DDZCMD_S_StatusCall
{
	//ʱ����Ϣ
	BYTE							cbTimeCallBanker;					//�е���ʱ��
	BYTE							cbTimeRodBanker;					//������ʱ��
	//BYTE							cbTimeAddDouble;					//�ӱ�ʱ��
	BYTE							cbTimeStartGame;					//��ʼʱ��
	BYTE							cbTimeHeadOutCard;					//�׳�ʱ��
	BYTE							cbTimeOutCard;						//����ʱ��

	//��Ϸ��Ϣ
	LONG							lCellScore;							//��Ԫ����
	WORD							wFirstUser;							//�׽��û�
	//WORD							wFirstValidUser;					//�׽�����
	WORD							wCurrentUser;						//��ǰ���
	WORD							wStartTime;							//��ʼ����
	//WORD							wValidCardTime;						//���Ʊ���
	//bool							bValidCardInfo[GAME_PLAYER];		//������Ϣ
	BYTE							cbCallBankerInfo[DDZGAME_PLAYER];		//�е�����Ϣ	
	BYTE							cbHandCardData[DDZGAME_PLAYER][NORMAL_COUNT];		//�����˿�

	//��ʷ����
	SCORE							lTurnScore[DDZGAME_PLAYER];			//������Ϣ
	SCORE							lCollectScore[DDZGAME_PLAYER];			//������Ϣ
};

//������״̬
struct DDZCMD_S_StatusRod
{
	//ʱ����Ϣ
	BYTE							cbTimeCallBanker;					//�е���ʱ��
	BYTE							cbTimeRodBanker;					//������ʱ��
	//BYTE							cbTimeAddDouble;					//�ӱ�ʱ��
	BYTE							cbTimeStartGame;					//��ʼʱ��
	BYTE							cbTimeHeadOutCard;					//�׳�ʱ��
	BYTE							cbTimeOutCard;						//����ʱ��

	//��Ϸ��Ϣ
	LONG							lCellScore;							//��Ԫ����
	WORD							wFirstUser;							//�׽��û�
	//WORD							wFirstValidUser;					//�׽�����
	WORD							wBankerUser;						//ׯ���û�
	WORD							wCurrentUser;						//��ǰ�û�

	WORD							wStartTime;							//��ʼ����
	//WORD							wValidCardTime;						//���Ʊ���
	WORD							wRodBankerTime;						//����������

	//bool							bValidCardInfo[GAME_PLAYER];		//������Ϣ
	BYTE							cbCallBankerInfo[DDZGAME_PLAYER];		//�е�����Ϣ	
	BYTE							cbRodBankerInfo[DDZGAME_PLAYER];		//��������Ϣ
	//BYTE							cbValidCardInfo[DDZGAME_PLAYER];		//������Ϣ
	BYTE							cbHandCardData[DDZGAME_PLAYER][NORMAL_COUNT];//�����˿�

	//��ʷ����
	SCORE							lTurnScore[DDZGAME_PLAYER];			//������Ϣ
	SCORE							lCollectScore[DDZGAME_PLAYER];			//������Ϣ
};

/*
//�з�״̬
struct DDZCMD_S_StatusCall
{
	//ʱ����Ϣ
	BYTE							cbTimeOutCard;						//����ʱ��
	BYTE							cbTimeCallScore;					//�з�ʱ��
	BYTE							cbTimeStartGame;					//��ʼʱ��
	BYTE							cbTimeHeadOutCard;					//�׳�ʱ��

	//��Ϸ��Ϣ
	LONG							lCellScore;							//��Ԫ����
	WORD							wCurrentUser;						//��ǰ���
	BYTE							cbBankerScore;						//ׯ�ҽз�
	BYTE							cbScoreInfo[DDZGAME_PLAYER];			//�з���Ϣ
	BYTE							cbHandCardData[NORMAL_COUNT];		//�����˿�
	//��ʷ����
	SCORE							lTurnScore[DDZGAME_PLAYER];			//������Ϣ
	SCORE							lCollectScore[DDZGAME_PLAYER];			//������Ϣ
};
*/
//�û���ע
struct DDZCMD_S_PlaceBet
{
	WORD							wChairID;							//�û�λ��
	BYTE							cbBetArea;							//��������
	LONGLONG						lBetScore;							//��ע��Ŀ
	BYTE							cbAndroidUser;						//������ʶ
};

//��Ϸ״̬
struct DDZ_CMD_S_StatusPlay
{
	//ʱ����Ϣ
	BYTE							cbTimeCallBanker;					//�е���ʱ��
	BYTE							cbTimeRodBanker;					//������ʱ��
	BYTE							cbTimeAddDouble;					//�ӱ�ʱ��
	BYTE							cbTimeStartGame;					//��ʼʱ��
	BYTE							cbTimeHeadOutCard;					//�׳�ʱ��
	BYTE							cbTimeOutCard;						//����ʱ��

	//��Ϸ����
	LONG							lCellScore;							//��Ԫ����
	WORD							wBankerUser;						//ׯ���û�
	WORD							wCurrentUser;						//��ǰ���

	WORD							wStartTime;							//��ʼ����
	//WORD							wValidCardTime;						//���Ʊ���
	WORD							wRodBankerTime;						//����������
	WORD							wBackCardTime;						//���Ʊ���
	WORD							wBombTime;							//ը������
	WORD							wCardTypeTime;						//���ͱ���

	BYTE							cbBombCount;						//ը������
	BYTE							cbCallBankerInfo[DDZGAME_PLAYER];		//�е�����Ϣ	
	BYTE							cbRodBankerInfo[DDZGAME_PLAYER];		//��������Ϣ
	BYTE							cbAddDoubleInfo[DDZGAME_PLAYER];		//�ӱ���Ϣ	
	//bool							bValidCardInfo[GAME_PLAYER];		//������Ϣ

	//������Ϣ
	WORD							wTurnWiner;							//ʤ�����
	BYTE							cbTurnCardCount;					//������Ŀ
	BYTE							cbTurnCardData[MAX_COUNT];			//��������

	//�˿���Ϣ
	BYTE							cbBankerCard[3];					//��Ϸ����
	BYTE							cbHandCardCount[DDZGAME_PLAYER];	//�˿���Ŀ
	BYTE							cbHandCardData[DDZGAME_PLAYER][MAX_COUNT];		//�����˿�
	//BYTE							cbHandCardData[MAX_COUNT];			//�����˿�

	//��ʷ����
	SCORE							lTurnScore[DDZGAME_PLAYER];			//������Ϣ
	SCORE							lCollectScore[DDZGAME_PLAYER];		//������Ϣ
};

//��Ϸ����<by hxh 20160822>
struct DDZCMD_S_GameEnd
{
	
	//���ֱ���
	LONG							lCellScore;							//��Ԫ����
	SCORE							lGameScore[DDZGAME_PLAYER];			//��Ϸ����

	//�����־
	BYTE							bChunTian;							//�����־
	BYTE							bFanChunTian;						//�����־

	//ը����Ϣ
	BYTE							cbBombCount;						//ը������
	BYTE							cbEachBombCount[DDZGAME_PLAYER];	//ը������

	//��Ϸ��Ϣ
	//BYTE							cbBankerScore;						//�з���Ŀ
	BYTE							cbCardCount[DDZGAME_PLAYER];		//�˿���Ŀ
	BYTE							cbHandCardData[FULL_COUNT];			//�˿��б�
	
};

//����ׯ��
struct DDZCMD_S_ApplyBanker
{
	WORD							wApplyUser;							//�������
};
//ȡ������
struct DDZCMD_S_CancelBanker
{
	WORD							wCancelUser;						//ȡ�����
};
//�л�ׯ��
struct DDZCMD_S_ChangeBanker
{
	WORD							wBankerUser;						//��ׯ���
	LONGLONG						lBankerScore;						//ׯ�ҷ���
};

////��¼��Ϣ
//struct tagServerGameRecord
//{
//	BYTE							cbKingWinner;						//����Ӯ��
//	bool							bPlayerTwoPair;						//���ӱ�ʶ
//	bool							bBankerTwoPair;						//���ӱ�ʶ
//	BYTE							cbPlayerCount;						//�мҵ���
//	BYTE							cbBankerCount;						//ׯ�ҵ���
//};
//��עʧ��
struct DDZCMD_S_PlaceBetFail
{
	WORD							wPlaceUser;							//��ע���
	BYTE							lBetArea;							//��ע����
	LONGLONG						lPlaceScore;						//��ǰ��ע
};
//����ظ�
struct DDZCMD_S_CommandResult
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
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//����������ṹ

#define SUB_S_GAME_FREE				99									//��Ϸ����
#if 0
#define SUB_S_GAME_START			100									//��Ϸ��ʼ
#define SUB_S_PLACE_JETTON			101									//�û���ע
#define SUB_S_GAME_END				102									//��Ϸ����
#define SUB_S_APPLY_BANKER			103									//����ׯ��
#define SUB_S_CHANGE_BANKER			104									//�л�ׯ��
#define SUB_S_CHANGE_USER_SCORE		105									//���»���
#define SUB_S_SEND_RECORD			106									//��Ϸ��¼
#define SUB_S_PLACE_JETTON_FAIL		107									//��עʧ��
#else
#define DDZ_SUB_S_GAME_START			100									//��Ϸ��ʼ
#define DDZ_SUB_S_CALL_BANKER			101									//�е���
#define DDZ_SUB_S_BANKER_INFO			102									//ׯ����Ϣ
#define DDZ_SUB_S_ROD_BANKER			103									//������
#define DDZ_SUB_S_OUT_CARD				106									//�û�����
#define DDZ_SUB_S_PASS_CARD				107									//�û�����
#define DDZ_SUB_S_OUT_START_START		108									//��ʼ����
#define DDZ_SUB_S_GAME_CONCLUDE			109									//��Ϸ����
#define DDZ_SUB_S_SET_BASESCORE			110									//���û���
#define DDZ_SUB_S_CHEAT_CARD			111									//�����˿�

#endif
#define SUB_S_CANCEL_BANKER			108									//ȡ������
#define SUB_S_AMDIN_COMMAND			109									//����Ա����

#define HLDDZ_SUB_S_GAME_START              100									//��Ϸ��ʼ
#define HLDDZ_SUB_S_CALL_SCORE              101									//�û��з�
#define HLDDZ_SUB_S_CALL_BANKER             101									//�е���
#define HLDDZ_SUB_S_BANKER_INFO             102									//ׯ����Ϣ
#define HLDDZ_SUB_S_ROD_BANKER              103									//������
#define HLDDZ_SUB_S_DOUBLE                  104									//�ӱ���Ϣ
#define HLDDZ_SUB_S_VALID_CARD              105									//�û�����
#define HLDDZ_SUB_S_OUT_CARD				106                                 //�û�����
#define HLDDZ_SUB_S_PASS_CARD				107                                 //�û�����
#define HLDDZ_SUB_S_OUT_START_START         108									//��ʼ����
#define HLDDZ_SUB_S_GAME_CONCLUDE			109                                 //��Ϸ����
#define HLDDZ_SUB_S_SET_BASESCORE			110                                 //���û���
#define HLDDZ_SUB_S_TRUSTEE                 111									//�û��й�
#define HLDDZ_SUB_S_NEWBANK                 112                                 //�µĵ���
#if 0
#define REC_SUB_S_SEND_CARD				100									//��������
#define REC_SUB_S_LAND_SCORE			101									//�з�����
#define REC_SUB_S_GAME_START			102									//��Ϸ��ʼ
#define REC_SUB_S_OUT_CARD				103									//�û�����
#define REC_SUB_S_PASS_CARD				104									//��������
#define REC_SUB_S_GAME_END				105									//��Ϸ����
#define REC_SUB_S_SPRING                106                                 //������Ϣ
#define REC_SUB_S_OUTCARD_TIMES         108                                 //���ƴ���    
#define REC_SUB_S_LOOK_TRUSTEE          109                                 //�йܲ�ѯ
#define REC_SUB_S_WARN_INFO             111                                 //������Ϣ
#define REC_SUB_S_OFFLINE_CARD          125                                 //���߳���
#define REC_SUB_S_USER_OFFLINE          150                                 //��Ҷ���
#define REC_SUB_S_DAOFAN                151                                 //�û�����
#define REC_SUB_S_OPENCARD			152									//�û�����
#define REC_SUB_S_TIMETOCLOSE			154								//��ɢ�û�
#define GS_WK_SCORE                    50                                   //�з�״̬  
#define SUB_S_GAME_READY             5001                //֪ͨ�ͻ��˷���׼������
#define SUB_C_GAME_READY             5002                //֪ͨ�ͻ��˷���׼������
#define SUB_S_ALL_READY              5003                //֪ͨ�ͻ����Ѿ�׼���õ���
#define SUB_C_ALL_READY              5004                //֪ͨ������Ѿ�׼���õ���
#define SUB_C_ANDROCHAIR             5005                //���������Ӻ�
//#define SUB_C_MATCH_TYPE             5006                //��������
#define SUB_SC_READYTIMEOUT					72				//׼����ʱ
#define SUB_S_GAMESTART					5008				//��Ϸ��ʼ
#endif

////��Ϸ��ʼ
//struct DDZCMD_S_GameStart
//{
//	BYTE							cbTimeLeave;						//ʣ��ʱ��
//
//	WORD							wBankerUser;						//ׯ��λ��
//	LONGLONG						lBankerScore;						//ׯ�ҽ��
//
//	LONGLONG						lPlayBetScore;						//��������ע	
//	LONGLONG						lPlayFreeSocre;						//������ɽ��
//
//	int								nChipRobotCount;					//�������� (��ע������) 
//	__int64                         nListUserCount;						//�б�����
//	int								nAndriodCount;						//�������б�����
//};

//�����˿�<add by hxh 20160822>
struct DDZCMD_S_GameStart
{
	WORD							wStartUser;							//��ʼ���
	WORD				 			wCurrentUser;						//��ǰ���
	WORD							wStartTime;							//��ʼ����
	BYTE							cbCardData[NORMAL_COUNT];			//�˿��б�
};

#if 1
//�����˿�
struct HLDDZ_CMD_S_GameStart
{
	WORD							wStartUser;							//��ʼ���
	WORD				 			wCurrentUser;						//��ǰ���
	BYTE							cbValidCardData;					//�����˿�
	BYTE							cbValidCardIndex;					//����λ��
	BYTE							cbCardData[NORMAL_COUNT];			//�˿��б�
};
#else
//�����˿�
struct DDZCMD_S_SendAllCard
{
	WORD				 			wCurrentUser;						//��ǰ���
	BYTE							bCardData[GAME_PLAYER][MAX_COUNT];			//�˿���
	BYTE                            bMingPai[MAX_COUNT];                           //����
	BYTE							bBackCardData[GAME_PLAYER];					//�����˿�
	LONG							lBaseScore;							//��������
	bool							bDog;								//gou
};
//��ʼ��Ϣ
struct HLDDZ_CMD_S_Game_Start
{
	WORD				 			wBankerUser;						//ׯ�����
	WORD				 			wCurrentUser;						//��ǰ���
	BYTE							cbCardData[MAX_COUNT];				//�˿�����
    
};
#endif

//�������˿�
struct DDZCMD_S_AndroidCard
{
	BYTE							cbHandCard[DDZGAME_PLAYER][NORMAL_COUNT];//�����˿�
	WORD							wCurrentUser ;						//��ǰ���
#if 1
	//�γ����
	BYTE							cbBankerCard[3];					  //ׯ���˿�
	WORD							wAndroidUserID;						  //�������
#endif
};

//�����˿�
struct DDZCMD_S_CheatCard
{
	WORD							wCardUser[DDZGAME_PLAYER ];				//�������
	BYTE							cbUserCount;							//��������
	BYTE							cbCardData[DDZGAME_PLAYER ][MAX_COUNT];	//�˿��б�
	BYTE							cbCardCount[DDZGAME_PLAYER ];				//�˿�����

};
//�û��з�
struct DDZCMD_S_CallScore
{
	WORD				 			wCurrentUser;						//��ǰ���
	WORD							wCallScoreUser;						//�з����
	BYTE							cbCurrentScore;						//��ǰ�з�
	BYTE							cbUserCallScore;					//�ϴνз�
};


//�û��е���
struct CMD_S_CallBanker
{
	WORD				 			wCurrentUser;						//��ǰ���
	WORD							wLastUser;							//�е������
	BYTE							cbCallInfo;							//�е���
};

//�û�������
struct CMD_S_RodBanker
{
	WORD							wRodBankerTime;						//����������

	WORD				 			wBankerUser;						//ׯ�����
	WORD				 			wCurrentUser;						//��ǰ���	
	WORD							wLastUser;							//���������
	BYTE							cbRodlInfo;							//������
};

#if 0
//�û��з֣�����ˣ�
struct DDZCMD_S_LandScore
{
	bool								bCanLand;							//���޽з�
	WORD							bLandUser;							//�з����
	WORD							wLanddata;							//�з���ұ�ʶ--���ڱ���������ͽе���
	WORD				 			wCurrentUser;						//��ǰ���
	WORD							wCurrentData;						//��ǰ��ұ�ʶ
	//BYTE							bLandScore;							//�ϴνз�
	//BYTE							bCurrentScore;						//��ǰ�з�
	//bool                            bGameStart;                         //��Ϸ��ʼ��־
};
//�û��е���
struct HLDDZ_CMD_S_CallBanker
{
	WORD				 			wCurrentUser;						//��ǰ���
	WORD							wLastUser;							//�е������
	BYTE							cbCallInfo;							//�е���
};
#endif

//ׯ����Ϣ
struct DDZCMD_S_BankerInfo
{

	WORD				 			wBankerUser;						//ׯ�����
	WORD				 			wCurrentUser;						//��ǰ���
	//WORD							wBackCardTime;						//���Ʊ���
	BYTE							cbBankerCard[3];					//ׯ���˿�
	//BYTE							cbBackCardType;						//��������
	//bool							bDoubleInfo[3];						//�ܷ�ӱ�
};

#if 1
//ׯ����Ϣ
struct HLDDZ_CMD_S_BankerInfo
{
	WORD				 			wBankerUser;						//ׯ�����
	WORD				 			wCurrentUser;						//��ǰ���
	BYTE							cbBankerScore;						//ׯ�ҽз�
	BYTE							cbBankerCard[3];					//ׯ���˿�
};
#else
//ׯ����Ϣ
struct HLDDZ_CMD_S_BankerInfo
{
	WORD				 			wBankerUser;						//ׯ�����
	WORD				 			wCurrentUser;						//��ǰ���
	WORD							wBackCardTime;						//���Ʊ���
	BYTE							cbBankerCard[3];					//ׯ���˿�
	BYTE							cbBackCardType;						//��������
	bool							bDoubleInfo[3];						//�ܷ�ӱ�
};
#endif

//�û�����
struct DDZCMD_S_OutCard
{
	BYTE							cbCardCount;						//������Ŀ
	WORD				 			wCurrentUser;						//��ǰ���
	WORD							wOutCardUser;						//�������
	BYTE							cbCardData[MAX_COUNT];				//�˿��б�
};

//�û�����
struct HLDDZ_CMD_S_OutCard
{
	BYTE							cbCardCount;						//������Ŀ
	WORD				 			wCurrentUser;						//��ǰ���
	WORD							wOutCardUser;						//�������
	BYTE							cbCardData[MAX_COUNT];				//�˿��б�
};

//��������
struct DDZCMD_S_PassCard
{
	BYTE							cbTurnOver;							//һ�ֽ���
	WORD				 			wCurrentUser;						//��ǰ���
	WORD				 			wPassCardUser;						//�������
};

//��������
struct HLDDZ_CMD_S_PassCard
{
	BYTE							cbTurnOver;							//һ�ֽ���
	WORD				 			wCurrentUser;						//��ǰ���
	WORD				 			wPassCardUser;						//�������
};

//��Ϸ����
struct DDZCMD_S_GameConclude
{
	//���ֱ���
	SCORE							lCellScore;							//��Ԫ����<by hxh>
	SCORE							lGameScore[DDZGAME_PLAYER];			//��Ϸ����

	//�����־
	BYTE							bChunTian;							//�����־
	BYTE							bFanChunTian;						//�����־

	//ը����Ϣ
	BYTE							cbBombCount;						//ը������
	BYTE							cbEachBombCount[DDZGAME_PLAYER];		//ը������

	//��Ϸ��Ϣ
	BYTE							cbBankerScore;						//�з���Ŀ
	BYTE							cbCardCount[DDZGAME_PLAYER];			//�˿���Ŀ
	BYTE							cbHandCardData[FULL_COUNT];			//�˿��б�
};

//��Ϸ����
struct HLDDZ_CMD_S_GameConclude
{
	//���ֱ���
	SCORE							lCellScore;							//��Ԫ����
	SCORE							lGameScore[DDZGAME_PLAYER];			//��Ϸ����
    
	//�����־
	BYTE							bChunTian;							//�����־
	BYTE							bFanChunTian;						//�����־
    
	//ը����Ϣ
	BYTE							cbBombCount;						//ը������
	BYTE							cbEachBombCount[DDZGAME_PLAYER];		//ը������
    
	//��Ϸ��Ϣ
	BYTE							cbBankerScore;						//�з���Ŀ
	BYTE							cbCardCount[DDZGAME_PLAYER];			//�˿���Ŀ
	BYTE							cbHandCardData[DDZGAME_PLAYER];			//�˿��б�
};

//////////////////////////////////////////////////////////////////////////////////
//�����

#define SUB_C_CALL_SCORE			1									//�û��з�
#define SUB_C_CALL_BANKER			2									//�û��е���
#define SUB_C_ROD_BANKER			3									//�û�������
#define SUB_C_DOUBLE				4									//�û��ӱ�
#define SUB_C_OUT_CARD				5									//�û�����
#define SUB_C_PASS_CARD				6									//�û�����



//========================================================================================
//����������ֵ����  �����ͽУ�������ʱ����Ӧ����ֵ��
//�е���
#define CB_NOT_CALL					0									//û�е���
#define CB_CALL_BENKER				1									//�е���
#define CB_NO_CALL_BENKER			2									//���е���

//������
#define CB_NOT_ROD					0									//û������
#define CB_ROD_BANKER				1									//������
#define CB_NO_ROD_BANKER			2									//��������
#define CB_CAN_NO_ROD				3									//������

//////////////////////////////////////////////////////////////////////////////////


#if 0
#define SUB_C_CALL_SCORE			1									//�û��з�
#define SUB_C_DOUBLE_SCORE			2									//�û��ӱ�
#define SUB_C_OUT_CARD				3									//�û�����
#define SUB_C_PASS_CARD				4									//�û�����
#define SUB_C_TRUSTEE               5                                   //�û��й�

#define HLDDZ_SUB_C_VALID_CARD			1									//�û�����
#define HLDDZ_SUB_C_CALL_SCORE			2									//�û��з�
#define HLDDZ_SUB_C_CALL_BANKER			2									//�û��е���
#define HLDDZ_SUB_C_ROD_BANKER			3									//�û�������
#define HLDDZ_SUB_C_DOUBLE				4									//�û��ӱ�
#define HLDDZ_SUB_C_OUT_CARD				5									//�û�����
#define HLDDZ_SUB_C_PASS_CARD				6									//�û�����
#define HLDDZ_SUB_C_TRUSTEE				7									//�û��й�
#define HLDDZ_SUB_C_BRIGHT_START			8									//���ƿ�ʼ
#endif
#if 0
#define SUB_C_CLIENT_READY           4001                //�ͻ���׼������
#define REC_SUB_C_LAND_SCORE			1									//�û��з�
#define REC_SUB_C_OUT_CART				2									//�û�����
#define REC_SUB_C_PASS_CARD				3									//��������
#define REC_SUB_C_TRUSTEE				4									//�й���Ϣ
#define REC_SUB_C_GAME_END              5                                   //��Ϸ����
#define REC_SUB_C_LOOKTRUSTEE           6                                   //��ѯ�й�
#define REC_SUB_C_WARN_INFO             12									//������Ϣ
#define REC_SUB_C_TURN_COUNT            13									//��������
#define REC_SUB_C_CONTINUE              14                                  //��������
#define	REC_SUB_S_GOLDEGG               16                                  //�ͽ�
#define REC_SUB_S_RESED_CARD            17                                   //���·��ƣ����ھ���
#define REC_SUB_S_BEILV						20								//--���ʱ仯
#define REC_SUB_S_ONLINE					22								//--������߱�־
#define REC_SUB_C_OVER						24								//--�ͻ����������������ڲ���
#endif
#define REC_SUB_C_DAOFAN                15                                  //�û�����
#define REC_SUB_C_OPNE_CARD				18								//--�������

//�û��з�
struct DDZCMD_C_CallScore
{
	BYTE							cbCallScore;						//�з���Ŀ
};

//�û��е���
struct CMD_C_CallBanker
{				
	BYTE							cbCallInfo;							//�е���
};

//�û�������
struct CMD_C_RodBanker
{				
	BYTE							cbRodInfo;							//������
};



#if 1
//�û��з�
struct HLDDZ_CMD_C_CallScore
{
	BYTE							cbCallScore;						//�з���Ŀ
};
#else
//�û��з�(�ͻ���)
struct DDZCMD_C_LandScore  
{
	bool								  bLandScore;							//��������
    WORD                            bLandUser;                          //�з��û�
};
#endif

#if 0
//�û��е���
struct HLDDZ_CMD_C_CallBanker
{
	BYTE							cbCallInfo;							//�е���
};

//�û�������
struct HLDDZ_CMD_C_RodBanker
{
	BYTE							cbRodInfo;							//������
};

//�û��ӱ�
struct HLDDZ_CMD_C_Double
{
	BYTE							cbDoubleInfo;						//�ӱ���Ϣ
};

//��Ϸ�з�
struct DDZCMD_S_StatusScore
{
	BYTE							bLandScore;							//��������
	LONG							lBaseScore;							//��������
	WORD				 			wCurrentUser;						//��ǰ���
	BYTE							bScoreInfo[DDZGAME_PLAYER];			//�з���Ϣ
	BYTE							bCardData[DDZGAME_PLAYER][20];			//�����˿�
	bool							bUserTrustee[DDZGAME_PLAYER];			//����й�
	BYTE							bBackCardData[DDZGAME_PLAYER];			//�����˿�
	WORD						wOpenCard[DDZGAME_PLAYER];				//����  �������
	//��ʷ����
	long long						lTurnScore[DDZGAME_PLAYER];			//������Ϣ
	long long						lCollectScore[DDZGAME_PLAYER];			//������Ϣ
};
//�ͽ�
struct DDZCMD_S_GoldEgg
{
	WORD                            bCurrentUser;                       //��ǰ���
	BYTE                            bGoldEgg;                           //����Ŀ
};
//���·��ƣ����ھ���
struct DDZCMD_S_ReSedCrad
{
	WORD                            bTurnUser;                          //��һ�ֳ����û�
	BYTE							bTurnCount;							//��һ�ֳ�������Ŀ
	BYTE							bTurnData[MAX_COUNT];						//�˿��б�
	BYTE							bCardCount;							//����Ŀ
	BYTE							bCardData[MAX_COUNT];						//�˿��б�
};

//��������
struct DDZCMD_S_TurnCount
{
	WORD                            wTurnChairID;                       //���ID
	WORD                            wTurnCount;                         //����
};

//�û�����
struct DDZCMD_S_WarnInfo
{
	WORD                           wWarnUser;                           //�������
	bool                           bWarn;                               //������Ϣ
	WORD                           wWarnNum;                            //����ʱ����Ŀ
};
//�йܽṹ
struct DDZCMD_C_UserTrustee {
	WORD							wUserChairID;						//�������
	bool							bTrustee;							//�йܱ�ʶ
};

//������ʾ
struct DDZCMD_S_OutCardNotify
{
	BYTE							bOutCard;							//���Ʊ�־
	WORD							wCurrentUser;						//��ǰ�û�
};
#endif

//�û�����
struct DDZCMD_C_OutCard
{
	BYTE							cbCardCount;						//������Ŀ
	BYTE							cbCardData[MAX_COUNT];				//�˿�����
};

//�û�����
struct HLDDZ_CMD_C_OutCard
{
	BYTE							cbCardCount;						//������Ŀ
	BYTE							cbCardData[MAX_COUNT];				//�˿�����
};
//�û����ƣ�����ˣ�
//struct CMD_S_OutCard
//{
//	BYTE							bCardCount;							//������Ŀ
//	WORD				 			wCurrentUser;						//��ǰ���
//	WORD							wOutCardUser;						//�������
//	BYTE							bCardData[MAX_COUNT];						//�˿��б�
//	bool                            bIsNoGameEnd;                       //�Ƿ����
//};

//���ƣ��ͻ��ˣ�
//struct CMD_C_OutCard
//{
//	BYTE							bCardCount;							//������Ŀ
//	BYTE							bCardData[MAX_COUNT];						//�˿��б�
//	WORD                            wOutCardUser;                       //�������
//};


//��������
//struct CMD_S_PassCard
//{
//	bool							bNewTurn;							//һ�ֿ�ʼ
//	WORD				 			wPassUser;							//�������
//	WORD				 			wCurrentUser;						//��ǰ���
//};

//--��Ҷ���������־
struct DDZCMD_S_UserOffLine
{
	WORD    m_userID;
	bool        m_isOnline;
};

//�û�����
struct DDZCMD_S_OPENCARD
{
	WORD	bOpenUser;
};

//�û�����
struct DDZCMD_C_OPENCARD
{
	WORD	bOpenUser;
	WORD		bNum;
};

//�û�����
struct DDZCMD_C_DAOFAN
{
	WORD                            m_bUserDaofanID;
};
//�û�׼������
struct DDZCMD_C_START
{
	WORD							bCurrentUser;                     //��ʼ�û� 
	bool								bOpenCard;							//���ƿ�ʼ
};
struct DDZCMD_S_READY
{
	WORD							bCurrentUser;                     //��ʼ�û� 
	bool								bOpenCard;							//���ƿ�ʼ
};
struct DDZCMD_S_DAOFAN
{
	WORD                            m_bUserDaofanID;								//��ǰ�û�
};

//���ʱ仯
struct DDZCMD_S_BEILV
{
	WORD beillu[DDZGAME_PLAYER];							//����
};
//////////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif
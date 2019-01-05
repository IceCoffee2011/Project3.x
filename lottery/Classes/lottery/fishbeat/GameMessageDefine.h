
#if !defined(_GAME_MESSAGE_DEFINE_H_)
#define _GAME_MESSAGE_DEFINE_H_

//����
enum emGameRoom
{
	em_GR_LogonFinish,				//��¼���
	em_GR_LogonFailure,				//��¼ʧ��
	em_GR_LogonSuccess,				//��¼�ɹ�
	em_GR_StartGame,				//������Ϸ
	em_GR_EndGame,					//�˳���Ϸ
	em_GR_TCPShut,					//����ر�
	em_GR_TCPLink,					//��������
	em_GR_SYS_MSG,					//ϵͳ��Ϣ
	em_GR_UpdateNotify,				//��Ϸ����
	em_GR_CreateTable,
	em_GR_UpdateTable,
	em_GR_SystemMSG,				//ϵͳ��Ϣ
	em_GR_LogonValidate,			//��¼��֤
	em_GR_ObjPartake,				//�ڳ�
	em_GR_UserSaveScore,
	em_GR_ApplyOrderResult,
	em_GR_PayResult,
	em_GR_WaitDistribute,
	em_GRCreateRoomFinish,				//�����������
};
//���˲���
enum emGameMessage
{
	em_GM_FishTrace,				//������Ⱥ
	em_GM_ExchangeFishScore,		//
	em_GM_UserFire,					//�û�����
	em_GM_CatchFish,				//ץס��
	em_GM_BulletIONTimeOut,			//�����ڳ�ʱ
	em_GM_LockTime,					//������ʱ
	em_GM_CatchSweepFish,			//
	em_GM_CatchSweepFishResult,		//
	em_GM_HitFishLK,				//
	em_GM_SwitchScene,				//
	em_GM_StockOperateResult,		//
	em_GM_SceneEnd,					//
	em_GM_FireScore,				//
	em_GM_HARVEST,
	em_GM_CONFIG,
	em_GM_HELPMONEY,
	em_GM_MESSAGE,
	em_GM_OnLineAward,				//��Ϸ���߽���
	em_GM_AwardScore				//��Ϸ���߽���
};
//����ţţ
enum emNiuniuMsg
{

};
//�ټ���
enum emBaccaratMsg
{
	em_BA_GameFree,
	em_BA_GameStart,
	em_BA_PlaceBet,
	em_BA_ApplyBanker,
	em_BA_CancelBanker,
	em_BA_ChangeBanker,
	em_BA_GameEnd,
	em_BA_GameRecord,
	em_BA_PlaceBetFail,
	em_BA_CommandResult,
	em_BA_CancelPlaceBet,
	em_BA_RandcardList,
	em_BA_StatusFree,
	em_BA_StatusPlay
};
#endif // !defined(_GAME_MESSAGE_DEFINE_H_)
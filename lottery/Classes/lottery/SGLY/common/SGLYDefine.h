#ifndef __SGLY_DEFINE_H__
#define __SGLY_DEFINE_H__

#include "VersionControl.h"

/***********************ˮ����԰�Զ����	begin*************************************************/
#ifdef VER_9YI
#define SGLY_APPLY_LIST_VIEW_SIZE cocos2d::Size(615.0f, 75.0f * 3.0f)							//	ˮ����԰������ׯ�б���ͼ�ߴ�
#endif // VER_9YI

#ifdef VER_QIANBO
#define SGLY_APPLY_LIST_VIEW_SIZE cocos2d::Size(593.0f, 49.0f * 4.0f)							//	ˮ����԰������ׯ�б���ͼ�ߴ�
#endif // VER_QIANBO

#ifdef VER_369
#define SGLY_APPLY_LIST_VIEW_SIZE cocos2d::Size(593.0f, 49.0f * 4.0f)							//	ˮ����԰������ׯ�б���ͼ�ߴ�
#endif // VER_369

#define SGLY_RES_PLIST "sgly_res.plist"															//	ˮ����԰����plist��Դ
#define SGLY_LOTTERY_FORMAT "sgly_lottery_%d.png"												//	ˮ����԰�����齱�������ļ���ͨ�ø�ʽ
#define SGLY_HISTORY_ITEM_FORMAT "sgly_history_item_%d.png"										//	ˮ����԰������ʷ��¼���������ļ���ͨ�ø�ʽ

#define SGLY_LOTTERY_COUNT 24																	//	ˮ����԰������������
#define SGLY_HISTORY_COUNT_MAX 50																//	ˮ����԰������ʷ��¼�ܸ���
#define SGLY_HISTORY_LIST_VIEW_SIZE cocos2d::Size(67.0f * 8.0f, 70.0f)							//	ˮ����԰������ʷ��¼�б���ͼ�ߴ�
//	XML���

#define SGLY_XML_FILE_NAME "sgly_strings.xml"													//	ˮ����԰����XML�ļ�
#define SGLY_XML_KEY_QUIT "tips_quit"															//	ˮ����԰����key�����˳���ʾ��
#define SGLY_XML_KEY_SYSTEM_BANKER "system_banker"												//	ˮ����԰����key����ϵͳ��ׯʱ��ʾ��ׯ����
#define SGLY_XML_KEY_BET_FAILED "bet_failed"													//	ˮ����԰����key������עʧ��

#define SGLY_XML_KEY_SUPPLY_DECLARATION "supply_declaration"									//	ˮ����԰����key����������봰�ڡ�������
#define SGLY_XML_KEY_SUPPLY_EXCHANGE_RATE_FORMAT "supply_exchange_rate_format"					//	ˮ����԰����key����������봰�ڡ����һ����ʸ�ʽ
#define SGLY_XML_KEY_SUPPLY_TIPS_EXCHANGE_CHIP_FORMAT "supply_tips_exchange_format"				//	ˮ����԰����key����������봰�ڡ����һ�������ʾ���ʽ
#define SGLY_XML_KEY_SUPPLY_TIPS_SURPLUS_GOLD_FORMAT "supply_tips_surplus_gold_format"			//	ˮ����԰����key����������봰�ڡ���ʣ������ʾ���ʽ

//	��ұ�������

#define SGLY_DATA_KEY_AUDIO_VOLUME_BGM "sgly_volume_bgm"										//	ˮ����԰����key����������������
#define SGLY_DATA_KEY_AUDIO_VOLUME_SOUND_EFFECT "sgly_volume_sound_effect"						//	ˮ����԰����key������Ч����
#define SGLY_DATA_KEY_AUDIO_ON_BGM "sgly_on_bgm"												//	ˮ����԰����key�����򿪱�������
#define SGLY_DATA_KEY_AUDIO_ON_SOUND_EFFECT "sgly_on_sound_effect"								//	ˮ����԰����key��������Ч

/***********************ˮ����԰�Զ����	end*************************************************/



/***********************ˮ����԰ö��	begin*************************************************/


/*
**	@brief	ˮ����԰������������ö��
*/
enum E_SGLY_Lottery
{
	E_SGLY_Lottery_Bar = 0,		//	BAR
	E_SGLY_Lottery_Seven,		//	77
	E_SGLY_Lottery_Star,		//	����
	E_SGLY_Lottery_Watermelon,	//	����
	E_SGLY_Lottery_Bell,		//	����
	E_SGLY_Lottery_Pear,		//	��
	E_SGLY_Lottery_Orange,		//	��
	E_SGLY_Lottery_Apple,		//	ƻ��
	E_SGLY_Lottery_Null			//	��
};

/*
**	@brief	ˮ����԰����������ׯ״̬ö��
*/
enum E_SGLY_ApplyState
{
	E_SGLY_ApplyState_Apply = 0,	//	������ׯ
	E_SGLY_ApplyState_Banker,		//	�Ѿ���ׯ
	E_SGLY_ApplyState_Null,			//	��
};

/*
**	@brief	ˮ����԰����ʱ������
*/
enum E_SGLY_Process
{
	E_SGLY_Process_Idle = 0,	//	����ʱ��
	E_SGLY_Process_Bet,			//	��עʱ��	
	E_SGLY_Process_Lottery,		//	����ʱ��
	E_SGLY_Process_Guess,		//	�´�Сʱ��
	E_SGLY_Process_Null			//	��
};

/*
**	@brief	ˮ����԰����Ѻעģʽ
*/
enum E_SGLY_BettingMode
{
	E_SGLY_BettingMode_M1 = 0,	//	1��
	E_SGLY_BettingMode_M10,		//	10��	
	E_SGLY_BettingMode_M100,	//	100��
	E_SGLY_BettingMode_Null		//	��
};

/*
**	@brief	ˮ����԰�������������ֵ����
*/
enum E_SGLY_InfoBar
{
	E_SGLY_InfoBar_PlayerChip = 0,	//	��ҳ���
	E_SGLY_InfoBar_PlayerScore,		//	��ҳɼ�
	E_SGLY_InfoBar_BankerChip,		//	ׯ�ҳ���
	E_SGLY_InfoBar_BankerWinScore,	//	ׯ�ҳɼ�
	E_SGLY_InfoBar_BankerTime,		//	ׯ��
	E_SGLY_InfoBar_Null				//	��
};

/*
**	@brief	ˮ����԰����GoodLuck����
*/
enum E_SGLY_GoodLuckType
{
	E_SGLY_GoodLuck_Swallow = 0,	//	������
	E_SGLY_GoodLuck_DaSanYuan,		//	����Ԫ
	E_SGLY_GoodLuck_DaSiXi,			//	����ϲ
	E_SGLY_GoodLuck_XiaoSanYuan,	//	С��Ԫ
	E_SGLY_GoodLuck_PaoHuoChe,		//	�ܻ�
	E_SGLY_GoodLuck_SuiJiDaQiang,	//	�����ǹ
	E_SGLY_GoodLuck_Null			//	��
};

/*
**	@brief	ˮ����԰������Ƶ�ļ�ö��
*/
enum E_SGLY_Audio
{
	//	��������

	E_SGLY_Audio_BGM = 0,					//	��������

	//	��Ч

	E_SGLY_Audio_BtnBet_Bar,				//	��ע��ť����BAR
	E_SGLY_Audio_BtnBet_Seven,				//	��ע��ť����77
	E_SGLY_Audio_BtnBet_Star,				//	��ע��ť��������
	E_SGLY_Audio_BtnBet_Watermelon,			//	��ע��ť��������
	E_SGLY_Audio_BtnBet_Bell,				//	��ע��ť��������
	E_SGLY_Audio_BtnBet_Pear,				//	��ע��ť������
	E_SGLY_Audio_BtnBet_Orange,				//	��ע��ť������
	E_SGLY_Audio_BtnBet_Apple,				//	��ע��ť����ƻ��
	E_SGLY_Audio_Lottery_Bar,				//	�����BAR
	E_SGLY_Audio_Lottery_Seven,				//	�����77
	E_SGLY_Audio_Lottery_Star,				//	���������
	E_SGLY_Audio_Lottery_Watermelon,		//	���������
	E_SGLY_Audio_Lottery_Bell,				//	���������
	E_SGLY_Audio_Lottery_Pear,				//	�������
	E_SGLY_Audio_Lottery_Orange,			//	�������
	E_SGLY_Audio_Lottery_Apple,				//	�����ƻ��
	E_SGLY_Audio_Guess_Lose,				//	�´�С����ʧ��
	E_SGLY_Audio_Guess_Win,					//	�´�С�����ɹ�
	E_SGLY_Audio_GoodLuck_Flash,			//	GoodLuck������ת�����ƶ�
	E_SGLY_Audio_GoodLuck_Hit,				//	GoodLuck�����ִ�Ŀ��λ��
	E_SGLY_Audio_TimeWarning,				//	ʱ�侯��
	E_SGLY_Audio_TurnStart,					//	��ת������ʼ
	E_SGLY_Audio_DispatchLottery,			//	Ĭ����ת�����ƶ�
	E_SGLY_Audio_GameStart,					//	��Ϸ��ʼ

	E_SGLY_Audio_Null						//	��
};


/***********************ˮ����԰ö��	end*************************************************/

#endif	//	__SGLY_DEFINE_H__
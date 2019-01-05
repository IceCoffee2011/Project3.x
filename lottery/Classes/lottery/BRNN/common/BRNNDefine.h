#ifndef __BRNN_DEFINE_H__
#define __BRNN_DEFINE_H__

/***********************����ţţ�Զ����	begin*************************************************/

#define BRNN_POKER_CARD_PLIST "common_poker_card.plist"							//	�˿���plist
#define BRNN_RES_PLIST "brnn_res.plist"											//	��ԴͼƬplist

#define BRNN_POKER_CARD_FORMAT "poker_card_%d.png"								//	�˿����ļ�����ʽ��0Ϊ���棩
#define BRNN_POKER_CARD_COUNT 54												//	�˿�������

#define BRNN_HANDS_CARD_COUNT 5													//	����ţţ����������
#define BRNN_CARD_SCALE_BIG 1.1f												//	����ţţ�����������š�����

#define BRNN_AREA_CHIP_SCALE_SMALL 0.5f											//	����ţţ���������������ű���

#define BRNN_CLOCK_NUMBER_FNT "brnn_fnt_time_num.fnt"							//	����ţţ����ʱ�����������ļ�

#define BRNN_APPLY_LIST_VIEW_SIZE cocos2d::Size(590.0f, 81.0f * 3.0f)			//	����ţţ������ׯ�б���ͼ�ߴ�
#define BRNN_TRAVEL_VIEW_SIZE cocos2d::Size(66.0f * 11.0f, 59.0f * 4.0f)		//	����ţţ����·����ͼ�ߴ�
#define BRNN_TRAVEL_COLUMN_SIZE cocos2d::Size(66.0f, 59.0f * 4.0f)				//	����ţţ����·��һ�гߴ�

#define BRNN_MAX_SCORE_HISTORY 16												//	����ţţ����·����ʷ����

//	XML���

#define BRNN_XML_FILE_NAME "brnn_strings.xml"									//	����ţţ����XML�ļ�
#define BRNN_XML_KEY_QUIT "tips_quit"											//	����ţţ����key�����˳���ʾ��
#define BRNN_XML_KEY_SYSTEM_BANKER "system_banker"								//	����ţţ����key����ϵͳ��ׯʱ��ʾ��ׯ����
#define BRNN_XML_KEY_BET_FAILED "bet_failed"									//	����ţţ����key������עʧ��

//	��ұ�������

#define BRNN_DATA_KEY_AUDIO_VOLUME_BGM "volume_bgm"								//	����ţţ����key����������������
#define BRNN_DATA_KEY_AUDIO_VOLUME_SOUND_EFFECT "volume_sound_effect"			//	����ţţ����key������Ч����
#define BRNN_DATA_KEY_AUDIO_ON_BGM "on_bgm"										//	����ţţ����key�����򿪱�������
#define BRNN_DATA_KEY_AUDIO_ON_SOUND_EFFECT "on_sound_effect"					//	����ţţ����key��������Ч


/***********************����ţţ�Զ����	end*************************************************/



/***********************����ţţö��	begin*************************************************/



/*
**	@brief	����ţţ���������о�
*/
enum E_BRNN_CardType
{
	E_BRNN_CardType_Error,			//	��������
	E_BRNN_CardType_Point,			//	��������
	E_BRNN_CardType_Niu1,			//	ţ1
	E_BRNN_CardType_Niu2,			//	ţ2
	E_BRNN_CardType_Niu3,			//	ţ3
	E_BRNN_CardType_Niu4,			//	ţ4
	E_BRNN_CardType_Niu5,			//	ţ5
	E_BRNN_CardType_Niu6,			//	ţ6
	E_BRNN_CardType_Niu7,			//	ţ7
	E_BRNN_CardType_Niu8,			//	ţ8
	E_BRNN_CardType_Niu9,			//	ţ9
	E_BRNN_CardType_NiuNiu,			//	ţţ
	E_BRNN_CardType_SmallNiu,		//	С��ţţ
	E_BRNN_CardType_BigNiu,			//	����ţţ
	E_BRNN_CardType_SilverNiu,		//	��ţ���Ļ���
	E_BRNN_CardType_GoldNiu,		//	��ţ���廨��
	E_BRNN_CardType_Bomb			//	ը��
};

/*
**	@brief	����ţţ������������
*/
enum E_BRNNChipType
{
	E_BRNNChip_1 = 0,	//	������ֵ����1
	E_BRNNChip_5,		//	������ֵ����5
	E_BRNNChip_10,		//	������ֵ����10
	E_BRNNChip_50,		//	������ֵ����50
	E_BRNNChip_100,		//	������ֵ����100
	E_BRNNChip_200,		//	������ֵ����200
	E_BRNNChip_500,		//	������ֵ����500
	E_BRNNChip_1k,		//	������ֵ����1k
	E_BRNNChip_NULL		//	������ֵ������
};

/*
**	@brief	����ţţ������������
*/
enum E_BRNNBetAreaType
{
	E_BRNNBetArea_E = 0,	//	��ע���򡪡���
	E_BRNNBetArea_S,		//	��ע���򡪡���
	E_BRNNBetArea_W,		//	��ע���򡪡���
	E_BRNNBetArea_N,		//	��ע���򡪡���
	E_BRNNBetArea_NULL		//	��ע���򡪡���
};

/*
**	@brief	����ţţ�����˿���λ��
*/
enum E_BRNN_PokerPos
{
	E_BRNN_PokerPos_B = 0,	//	�˿���λ�á���ׯ
	E_BRNN_PokerPos_E,		//	�˿���λ�á�����
	E_BRNN_PokerPos_S,		//	�˿���λ�á�����
	E_BRNN_PokerPos_W,		//	�˿���λ�á�����
	E_BRNN_PokerPos_N,		//	�˿���λ�á�����
	E_BRNN_PokerPos_NULL	//	�˿���λ�á�����
};

/*
**	@brief	����ţţ������ʱ������
*/
enum E_BRNNProcessType
{
	E_BRNN_Idle = 0,	//	����ʱ��
	E_BRNN_Bet,			//	��עʱ��	
	E_BRNN_OpenCard,	//	����ʱ��
	E_BRNN_Null			//	��
};

/*
**	@brief	����ţţ����������ׯ״̬ö��
*/
enum E_BRNNApplyState
{
	E_BRNN_EPPC_Apply_State_Apply = 0,	//	������ׯ
	E_BRNN_EPPC_Apply_State_Banker,		//	�Ѿ���ׯ
	E_BRNN_Apply_State_Null,			//	��
};

/*
**	@brief	����ţţ������Ƶ�ļ�ö��
*/
enum E_BRNNAudio
{
	E_BRNNAudio_BGMusic = 0,	//	��������
	E_BRNNAudio_Change_Banker,	//	��Ч�����л�ׯ��
	E_BRNNAudio_Countdown,		//	��Ч��������ʱ
	E_BRNNAudio_Game_Start,		//	��Ч������Ϸ��ʼ
	E_BRNNAudio_Bet,			//	��Ч������ע
	E_BRNNAudio_Lose,			//	��Ч������
	E_BRNNAudio_Win,			//	��Ч����Ӯ
	E_BRNNAudio_Null			//	��
};



/***********************����ţţö��	end*************************************************/

#endif	//	__BRNN_DEFINE_H__
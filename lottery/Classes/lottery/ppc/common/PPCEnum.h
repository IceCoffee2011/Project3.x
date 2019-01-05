#ifndef __PPC_ENUM_H__
#define __PPC_ENUM_H__

/***********************�������Զ����	begin*************************************************/


#define PPC_CAR_LOGO_SCALE_BIG 0.7f											//	�����������н��������logo�����ߴ�����ֵ������
#define PPC_CAR_LOGO_SCALE_SMALL 0.5f										//	�����������н��������logo�����ߴ�����ֵ����С
#define PPC_AREA_ICON_SCALE_SMALL 0.8f										//	��������������ͼ�ꡪ������logo�����ߴ�����ֵ����С
#define PPC_AREA_CHIP_SCALE_SMALL 0.3f										//	��������������ͼ�ꡪ��������롪���ߴ�����ֵ����С
#define PPC_AREA_SIZE Size(240, 124)										//	������������������ߴ�
#define PPC_TRAVEL_LIST_VIEW_SIZE Size(62 * 10, 50)							//	����������·���б���ͼ�ߴ�
#define PPC_APPLY_LIST_VIEW_SIZE Size(675.0f, 81.0f * 3.5f)					//	������������ׯ�б���ͼ�ߴ�
#define PPC_CARLGOG_COUNT 32												//	��������������logo����
#define PPC_SHOW_ENDING_DURATION 3											//	������������ʾ��������ʱ��

//��ʷ��¼
#define PPC_MAX_SCORE_HISTORY			65									//��ʷ����


//	XML���

#define PPC_XML_FILE_NAME "ppc_strings.xml"									//	����������XML�ļ�
#define PPC_XML_KEY_QUIT "tips_quit"										//	����������key�����˳���ʾ��
#define PPC_XML_KEY_SYSTEM_BANKER "system_banker"							//	����������key����ϵͳ��ׯʱ��ʾ��ׯ����
#define PPC_XML_KEY_BET_FAILED "bet_failed"									//	����������key������עʧ��

/***********************�������Զ����	end*************************************************/



/***********************������ö��	begin*************************************************/


//	��������������logoö��
enum EPPCCarLogoType
{
	EPPCCarLogo_Porsche_Big = 0,	//	����logo������ʱ�ݡ�����
	EPPCCarLogo_Porsche_Small,		//	����logo������ʱ�ݡ���С
	EPPCCarLogo_BMW_Big,			//	����logo������������
	EPPCCarLogo_BMW_Small,			//	����logo����������С
	EPPCCarLogo_Benz_Big,			//	����logo�������ۡ�����
	EPPCCarLogo_Benz_Small,			//	����logo�������ۡ���С
	EPPCCarLogo_VW_Big,				//	����logo�������ڡ�����
	EPPCCarLogo_VW_Small,			//	����logo�������ڡ���С
	EPPCCarLogo_Null				//	����logo������Ч
};

//	������������������ö��
enum EPPCChipType
{
	EPPCChip_1 = 0,	//	���롪�����Ϊ1
	EPPCChip_5,		//	���롪�����Ϊ5
	EPPCChip_10,	//	���롪�����Ϊ10
	EPPCChip_100,	//	���롪�����Ϊ100
	EPPCChip_500,	//	���롪�����Ϊ500
	EPPCChip_1k,	//	���롪�����Ϊ1k
	EPPCChip_Null,	//	��Ч
};

//	����������������ׯ״̬ö��
enum EPPCApplyState
{
	EPPC_EPPC_Apply_State_Apply = 0,	//	������ׯ
	EPPC_EPPC_Apply_State_Banker,		//	�Ѿ���ׯ
	EPPC_Apply_State_Null,				//	��
};

//	������������ʱ������
enum EPPCProcessType
{
	EPPC_Idle = 0,	//	����ʱ��
	EPPC_Bet,		//	��עʱ��	
	EPPC_Lottery,	//	����ʱ��
	EPPC_Null		//	��
};

//	�����������Ի�������ö��
enum EPPCDialog
{
	EPPCDialog_PPCEnding = 0	//	��Ϸ�������
};

/***********************������ö��	end*************************************************/

#endif	//	__PPC_ENUM_H__
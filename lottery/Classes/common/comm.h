#ifndef _COMM_H_
#define _COMM_H_

//�˻�����
#define		ACCOUNT_LENGTH		21
//���볤��
#define		PASSWORD_LENGTH		21
//IP��ַ����
#define		IP_LENGTH			11
//ʱ�䳤��
#define		TIME_LENGTH			51
//QQ���볤��
#define		QQ_LENGTH			12
//������󳤶�
#define		HAOMAO_LENGTH		60

//������Ϣ
#define	KJ_QIHAO_LENGTH			30
#define	KJ_HAOMA_LENGTH			30
#define	KJ_SHIJIAN_LENGTH		30

#define	TOP_KAIJIANG_NUMBERS	5

#define MAX_BEISHU				10000
#define MAX_ZHUIHAO_BEISHU		999

//ͨ��Ͷע����ת��������£�
#define		NSmallNumber		1				//С
#define		NSingleNumber		3				//��
#define		NDoubleNumber		2				//˫
#define		NTigerNumber		4				//��
#define		NPingNumber			5				//��=ƽ
#define		NDragonNumber		6				//��
#define		NHalfSerialNumber	7				//��˳ ��540 790 706
#define		NSimpleNumber		8				//�������ų����ӣ�˳�ӣ����ӣ���˳ ��Ϊ�н�
#define		NBigNumber			9				//��
#define		NSmallSingleNumber	10				//С��
#define		NSmallDoubleNumber	11				//С˫
#define		NBigSingleNumber	12				//��
#define		NBigDoubleNumber	13				//��˫
#define		NCoupleNumber		14				//����
#define		NSerialNumber		15				//˳�ӣ�һ������
#define		NAllSame			16				//���ӣ�ȫ��ͬ��
#define		NLimitSmall			17				//��ֵС,0-5
#define		NLimitBig			18				//��ֵ��22-27
//����10��
#define		NSumDigitBig		19				//��β���ܺ͸�λ����
#define		NSumDigitSmall		20				//��βС���ܺ͸�λ��С��
#define		NHeshuDa			21				//���������еĸ�λ��ʮλ�������֮�ͣ�
#define		NHeshuXiao			22				//����С�����еĸ�λ��ʮλ�������֮�ͣ�
#define		NZhongNumber		23				//�У��_��̖֮�a��01��02��03��04��05��06��07
#define		NFacaiNumber		24				//�l���_��̖֮�a��08��09��10��11��12��13��14
#define		NBaiNumber			25				//�ף��_��̖֮�a��15��16��17��18��19��20
#define		NEastNumber			26				//�|���_����̖�a��01��05��09��13��17
#define		NSouthNumber		27				//�ϣ��_����̖�a��02��06��10��14��18
#define		NWestNumber			28				//�����_����̖�a��03��07��11��15��19
#define		NNorthNumber		29				//�����_����̖�a��04��08��12��16��20
//����8
#define		NFrontMore			30				//ǰ�ࣺǰ�P̖�a��01-40������P̖�a�ǣ�41~80���������r
#define		NBackMore			31				//��ࣺ��P̖�a��41-80����ǰ�P̖�a�ǣ�01~40��������
#define		NEqualNumber		32				//ǰ��ͣ�ǰ�̺�������̺��������ͬ
#define		NSingleMore			33				//���ࣺ�_����20��̖�a�У�����̖�a��˫��̖�a������
#define		NDoubleMore			34				//˫�ࣺ�_����20��̖�a�У�˫��̖�a�ȵ���̖�a������
#define		NEqualDigits		35				//��˫����ͬ
//�_����20��̖�a��ӵ��ܺ�ֵ����5���Σ��Խ�ľ��ˮ������������
//��210��695����ľ��696��763����ˮ��764��855������856��923��������924��1410��
#define		NSumGold			36				//��
#define		NSumWood			37				//ľ
#define		NSumWater			38				//ˮ
#define		NSumFire			39				//��
#define		NSumEarth			40				//��
//����
#define		NSZero				0				//0 �� ��
#define		NSOne				1				//1	�� ��
#define		NSTwo				2				//2	�� ż

//��Ʊ����
typedef enum {
	CZChongQingSSC=1,		//����ʱʱ��	1
	CZJiangXiSSC=2,			//����ʱʱ��	2
	CZ3D=3,					//����3D		3
	CZXinJiangSSC=4,		//�½�ʱʱ��	4
	CZPailie3,				//����3			5
	CZGD11Xuan5,			//�㶫11ѡ5		6
	CZCQ11Xuan5,			//����11ѡ5		7
	CZSD11Xuan5,			//ɽ��11ѡ5		8
	CZJX11Xuan5,			//����11ѡ5		9
	CZKUAILE8,				//��������8		10
	CZ_FENFEN_CAI,			//�ֲַʣ�5���ӿ�����24Сʱ��ͣ��ÿ��288��	11
	CZ_WUFEN_CAI,			//5�ֲ�			12
	CZ_BJPK10,				//��������		13
	CZ_HK6HeCai,			//������Ͳ�	14
	CZ_SEVENSTAR,			//���ǲʣ�		15	
	CZ_HLJ11Xuan5,			//������11ѡ5	16
	CZ_LUCKY_28,			//����28		17
	CZ_KUAI_3,				//���տ�3		18
	CZ_GD_HAPPY10MIN,		//�㶫����10��	19
	CZ_KOREA_FEN_CAI,		//����1.5�ֲ�	20
	CZ_LUCKY_FARM,			//����ũ�����������10��=21
	CZ_XJP_ERFEN_CAI,		//�¼���2�ֲ�	22
	CZ_TIANJIN_SSC,			//���ʱʱ��	23
	CZ_BEIJING_5FEN_CAI,	//����5�ֲʣ�	24
	CZ_CANADA_FEN_CAI,		//���ô�3.5��	25
	CZ_JILI_2FEN_CAI,		//�������ֲ�	26
	CZ_STOCK_FINANCE,		//����֤ȯ
	CZ_TENCENT_FEN_CAI=28,	//��Ѷ�ֲַ�
	CZ_QQ_FEN_CAI=29,		//QQ�ֲַ�
	CZ_TENCENT_2FC,			//��Ѷ2�ֲ�
	CZ_QQ_2FEN_CAI,				//QQ2�ֲ�
	CZ_SOCCER_TEAM,			//����
	CZ_XYFT,				//���˷�ͧ		33
	CZCount
}CaiZhong;

//ʱʱ���淨����
typedef enum 
{
	inValid,
	//QianSanZhiXuan,			//ǰ��ֱѡ
	QianSanZhiXuan_FuShi=1,		//ǰ��ֱѡ��ʽ��Ҳ������ǰ��
	QianSanZhiXuan_DanShi,		//

	//HouSanZhiXuan,			//����ֱѡ
	HouSanZhiXuan_FuShi,		//����ֱѡ��ʽ��Ҳ�����Ǻ���
	HouSanZhiXuan_DanShi,

	//QianSanZuXuan,			//ǰ����ѡ
	QianSanZuXuan_ZuSanFuShi,
	QianSanZuXuan_ZuSanDanShi,
	QianSanZuXuan_ZuLiuFuShi,
	QianSanZuXuan_ZuLiuDanShi,

	//HouSanZuXuan,				//������ѡ
	HouSanZuXuan_ZuSanFuShi,
	HouSanZuXuan_ZuSanDanShi,
	HouSanZuXuan_ZuLiuFuShi,
	HouSanZuXuan_ZuLiuDanShi,

	//WuXingQianEr,				//����ǰ��
	WuXingQianEr_FuShi,
	WuXingQianEr_DanShi,

	//WuXingHouEr,				//���Ǻ��
	WuXingHouEr_FuShi,
	WuXingHouEr_DanShi,

	//QianErZuXuan,				//ǰ����ѡ
	QianErZuXuan_FuShi,
	QianErZuXuan_DanShi,

	//HouErZuXuan,				//�����ѡ
	HouErZuXuan_FuShi,
	HouErZuXuan_DanShi,

	DaXiaoDanShuang,			//��С��˫,���

	//BuDingWei,				//����λ
	BuDingWei_QianSan,
	BuDingWei_HouSan,

	DingWeiDan,					//��λ��=24
		
	RenXuan2,					//��ѡ2,3,4
	RenXuan3,
	RenXuan4,
	
	QianSanHunhe,				//ǰ�����
	ZhongSanHunhe,				//�������
	HouSanHunhe,				//�������
	
	//����ֱѡ��ʽ�淨
	WuxingZhixuan,				//����ֱѡ��0209������=31
	WuxingQianSi,				//����ǰ��
	WuxingHousi,				//���Ǻ���
	WuxingZhongsan,				//��������������ǰ�������Ǻ�������һ�ţ�

	//������ѡ�淨
	ZhongsanZusan,				//����������0209������
	ZhongsanZuliu,				//��������
	
	//������ѡ�淨
	Zuxuan120,					//��ѡ120
	Zuxuan60,					//��ѡ60
	Zuxuan30,					//��ѡ30
	Zuxuan20,					//��ѡ20
	Zuxuan10,					//��ѡ10
	Zuxuan5,					//��ѡ5
								
	//������ֵ�淨
	QianSanZhiXuanHeZhi,		//ǰ��ֱѡ��ֵ
	HouSanZhiXuanHeZhi,			//����ֱѡ��ֵ
	ZhongSanZhiXuanHeZhi,		//����ֱѡ��ֵ
	
	//��������λ
	BuDingWei_QianEr,			//����λ��ǰ2
	BuDingWei_HouEr,			//����λ����2

	//����Ȥζ�淨
	QW_YiFanFengShun,			//Ȥζ��һ����˳��һ��һ��һ�����־��н�
	QW_HaoShiChengShuang,		//Ȥζ�����³�˫��2��һ�������ֲ��н�
	QW_SanXingBaoXi,			//Ȥζ�����Ǳ�ϲ��3��һ�������ֲ��н�
	QW_SiJiFaCai,				//Ȥζ���ļ����ƣ�4��һ�������ֲ��н�
	NiuNiu_Num = 52,			//ţţ��5������֮����10�ı�����ţ1--ţ10��ţţ�� 1:10����ţͨ�ԣ�
	NiuNiu_None,				//ţţ����ţ 1:2
	ZhongsanZusan_DanShi,				//����������ʽ
	DaXiaoDanShuang_DW,			//��λ����С��˫;
	Zonghe_DXDSLh = 56,			//�ܺʹ�С��˫���ܺ�ֵ��춵��23���С춵��22��С��
	SSC_LongHu,					//������ͷ����βΪ����β����ͷΪ������ ��
	QianSan_Quwei,				//ǰ������˳�Ӷ��Ӱ�˳����
	ZhongSan_Quwei,				//��������˳�Ӷ��Ӱ�˳����
	HouSan_Quwei,				//��������˳�Ӷ��Ӱ�˳����
	HouErZhixuan_Hezhi = 61,	//���ֱѡ��ֵ
	QianErZhixuan_Hezhi,		//ǰ��ֱѡ��ֵ
	RenSanZhixuan_Hezhi,		//����ֱѡ��ֵ	0
	RenErZhixuan_Hezhi,			//�ζ�ֱѡ��ֵ	0
	SSC_LongHuYaJun = 65,		//�������Ǿ�
	Ren3Zu3_Fushi,				//��3��3��ʽ	
	Ren3Zu6_Fushi,				//��3��6��ʽ	
	Ren3Hunhe_Zuxuan,			//��3��� ��ѡ	
	Ren2Zuxuan_Fushi,			//��2��ѡ ��ʽ	
	Ren2Zuxuan_Danshi,			//��2��ѡ ��ʽ	

	QSZuXuan24=72,	 //ǰ����ѡ24
	QSZuXuan12=73,	 //ǰ����ѡ12
	QSZuXuan6=74,	 //ǰ����ѡ6
	QSZuXuan4=75,	 //ǰ����ѡ4
	HSZuXuan24=76,	 //������ѡ24
	HSZuXuan12=77,	 //������ѡ12
	HSZuXuan6=78,	 //������ѡ6
	HSZuXuan4=79,	 //������ѡ4

	//������ʽ�淨
	WuxingZhixuan_DanShi,	//����ֱѡ��ʽ
	WuxingQianSi_DanShi,	//����ǰ�ĵ�ʽ
	WuxingHousi_DanShi,		//���Ǻ��ĵ�ʽ	
	WuxingZhongsan_DanShi, //����������ʽ
	ZhongsanZuliu_DanShi,	//����������ʽ
	ZhongsanZusan_DanShi_Bet,	//����������ʽ

	RenXuan4_DanShi,//��ѡ�ĵ�ʽ
	RenXuan3_DanShi,//��ѡ3��ʽ
	RenXuan2_DanShi,//��ѡ2��ʽ
	Ren3Zu3_DanShi, //ѡ��������ʽ
	Ren3Zu6_DanShi, //����������ʽ	

	WanFaCount
}SSCWanFaKind;



//11ѡ5���淨
typedef enum tagEnumIIXuan5
{
		IIinValid,
		IIRenXuan2,						//��ѡ��
		IIRenXuan3,						//��ѡ��
		IIRenXuan4,						//��ѡ��
		IIRenXuan5,						//��ѡ��
		IIRenXuan6,						//��ѡ��
		IIRenXuan7,						//��ѡ��
		IIRenXuan8,						//��ѡ��
		QianYi,							//ǰһ
		QianEr_ZhiXuan,					//ǰ�� ֱѡѡ��
		QianEr_ZuXuan,					//ǰ����ѡѡ��
		QianSan_ZhiXuan,				//ǰ��ֱѡѡ��
		QianSan_ZuXuan,					//ǰ����ѡѡ��
		//�����淨
		IIRenXuan2_DanTuo,
		IIRenXuan3_DanTuo,
		IIRenXuan4_DanTuo,
		IIRenXuan5_DanTuo,
		IIRenXuan6_DanTuo,
		IIRenXuan7_DanTuo,
		IIRenXuan8_DanTuo,
		IIRenXuan1,		//
		//������ʽ�淨
		QianEr_ZhiXuan_DanShi,			//ǰ��ֱѡ��ʽ		
		QianSan_ZhiXuan_DanShi,		
		IIRenXuan1_DanShi,
		IIRenXuan2_DanShi,		
		IIRenXuan3_DanShi,	
		IIRenXuan4_DanShi,		
		IIRenXuan5_DanShi,	
		IIRenXuan6_DanShi,		
		IIRenXuan7_DanShi,		
		IIRenXuan8_DanShi,

		IIWanFaCount
}IIXuan5GameKind;


//	��������PK10
typedef enum
{
	PKinValid,

	WF_GuanJun,		//�ھ�
	WF_GuanYaJun,	//���Ǿ�
	WF_YaJun,		//�Ǿ�
	WF_QianSan,		//	ǰ��
	WF_DiSan,		//����
	WF_QianSi,		//	ǰ��
	WF_DiSi,		//����
	WF_QianWu,		//	ǰ��
	WF_DiWu,		//����
	WF_QianLiu,		//	ǰ��
	WF_DiLiu,		//����
	WF_QianQi,		//	ǰ��
	WF_DiQi,		//����
	WF_QianBa,		//	ǰ��
	WF_DiBa,		//�ڰ�
	WF_QianJiu,		//	ǰ��
	WF_DiJiu,		//�ھ�
	WF_QianShi,		//	ǰʮ
	WF_DiShi,		//��ʮ
	WF_DXDS,		//��С��˫������PK10û�кͣ�
	WF_DWD,			//��λ��
	WF_GYHZ,		//���Ǻ�ֵ����עΪ��С��˫
	//�����淨
	WF_GuanYaJun_DanShi,//���Ǿ���ʽ
	WF_QianSan_DanShi,//ǰ����ʽ
	WF_QianSi_DanShi,//ǰ�ĵ�ʽ
	WF_QianWu_DanShi,//ǰ�嵥ʽ
	PK10WanFaCount
}PK10GameKind;



//3D�����������淨��������3��
typedef	enum	tagEnumTreeNumbers
{
	Invalid,
	enWF_ZhixuanFushi,					//����ֱѡ��ʽ,
	enWF_ZhixuanDanshi,					//����ֱѡ��ʽ,
	enWF_QiansanzusanFushi,				//ǰ��������ʽ,
	enWF_QiansanzusanDanshi,			//ǰ��������ʽ,
	enWF_QiansanzuliuFushi,				//ǰ��������ʽ,
	enWF_QiansanzuliuDanshi,			//ǰ��������ʽ,
	enWF_QianyizhixuanFushi,			//ǰһֱѡ��ʽ,
	enWF_QianerzhixuanFushi,			//ǰ��ֱѡ��ʽ,
	enWF_QianerzhixuanDanshi,			//ǰ��ֱѡ��ʽ,
	enWF_Budingwei,						//���ǲ���λ,
	enWF_HouyizhixuanFushi,				//��һֱѡ��ʽ,
	enWF_HouerzhixuanFushi,				//���ֱѡ��ʽ,
	enWF_HouerzhixuanDanshi,			//���ֱѡ��ʽ,
	enWF_ZhixuanHezhi,					//����ֱѡ��ֵ,
	enWF_DaxiaoDanshuang,				//��С��˫
	enWF_DingWeiDan,					//��λ��
	enWF_Count							//�淨����
}ThreeNumbersKind;

typedef enum {	
	QiXingValidate,
	QiXingCai_LiangDing=1,
	QiXingCai_SanDing,
	QiXingCai_SiDing,
	QiXingCai_YiDing,
	QiXingCai_LiangZiXian,
	QiXingCai_SanZiXian,
}QiXingCaiKind;


//����28�淨
typedef enum {
	xy28_validate,
	xy28_tm0,
	xy28_tm1,
	xy28_tm2,
	xy28_tm3,
	xy28_tm4,
	xy28_tm5,
	xy28_tm6,
	xy28_tm7,
	xy28_tm8,
	xy28_tm9,
	xy28_tm10,
	xy28_tm11,
	xy28_tm12,
	xy28_tm13,
	xy28_tm14,
	xy28_tm15,
	xy28_tm16,
	xy28_tm17,
	xy28_tm18,
	xy28_tm19,
	xy28_tm20,
	xy28_tm21,
	xy28_tm22,
	xy28_tm23,
	xy28_tm24,
	xy28_tm25,
	xy28_tm26,
	xy28_tm27,

	enXY28_DXDS,	//��ֵ��С��˫
	enXY28_Funny,		//Ȥζ ���
	enXY28_JiZhi,		//��ֵ
}XingYun28Kind;

//������8
typedef enum {
	enBJK8_validate,
	enBJK8_RX_1,
	enBJK8_RX_2,
	enBJK8_RX_3,
	enBJK8_RX_4,
	enBJK8_RX_5,
	enBJK8_RX_6,
	enBJK8_RX_7,
	enBJK8_RX_8,
	enBJK8_RX_9,
	enBJK8_RX_10,
	enBJK8_ShangXia=15,
	enBJK8_JiOu=16,
	enBJK8_HeZhiDXDS=17,
}BeiJingKuai8Kind;

//������ϲ�
typedef enum {
	LiuHeCai_validate,
	LiuHeCai_Tmdm=1,
	LiuHeCai_Tmds,
	LiuHeCai_Tmdx,
	LiuHeCai_Tmsx,
	LiuHeCai_Tmbs,
	LiuHeCai_Pmdm,
	LiuHeCai_Zm1t,
	LiuHeCai_Zm2t,
	LiuHeCai_Zm3t,
	LiuHeCai_Zm4t,
	LiuHeCai_Zm5t,
	LiuHeCai_Zm6t
}LiuHeCaiKind;

//׷������״̬
enum ZhuiHaoType
{
	YuanTag = 0,                                   //�˳�
	JiaoTag,                                         //����
	FenTag,                                           //����
};

//Բ�Ƿ�
enum xIazhuyShiYiXuanWuType
{
	YuanShiYiXuanWuTag = 0,                                   //Ԫ
	JiaoShiYiXuanWuTag,                                       //��
	FenShiYiXuanWuTag,                                        //��
};

//important:�����˳�򣬴�����ѡ���淨��ʱ�򣬵����ťʱ��ӦΪʲô�淨ID
//�ð�ť������ʾʲô�淨���ƣ���displaytext.txt�����������ȷ����
static SSCWanFaKind wanFaMap[100] = {
	inValid, 
	WuxingZhixuan,
	WuxingZhixuan_DanShi,	//����ֱѡ��ʽ	
	Zuxuan120,					//��ѡ120
	Zuxuan60,					//��ѡ60
	Zuxuan30,					//��ѡ30
	Zuxuan20,					//��ѡ20
	Zuxuan10,					//��ѡ10
	Zuxuan5,					//��ѡ5
	WuxingQianSi,
	WuxingQianSi_DanShi,	//����ǰ�ĵ�ʽ
	QSZuXuan24,	 //ǰ����ѡ24
	QSZuXuan12,	 //ǰ����ѡ12
	QSZuXuan6,	 //ǰ����ѡ6
	QSZuXuan4,	 //ǰ����ѡ4	
	WuxingHousi,	
	WuxingHousi_DanShi,		//���Ǻ��ĵ�ʽ
	HSZuXuan24,	 //������ѡ24
	HSZuXuan12,	 //������ѡ12
	HSZuXuan6,	 //������ѡ6
	HSZuXuan4,	 //������ѡ4
	QianSanZhiXuan_FuShi,
	QianSanZhiXuan_DanShi,
	QianSanZuXuan_ZuLiuFuShi,
	QianSanZuXuan_ZuLiuDanShi,
	QianSanZuXuan_ZuSanFuShi,
	QianSanZuXuan_ZuSanDanShi,
	QianSanHunhe,
	WuxingZhongsan,
	WuxingZhongsan_DanShi, //����������ʽ
	ZhongsanZuliu,
	ZhongsanZuliu_DanShi,	//����������ʽ
	ZhongsanZusan,
	ZhongsanZusan_DanShi,	//����������ʽ
	ZhongSanHunhe,
	HouSanZhiXuan_FuShi,
	HouSanZhiXuan_DanShi,
	HouSanZuXuan_ZuLiuFuShi,
	HouSanZuXuan_ZuLiuDanShi,
	HouSanZuXuan_ZuSanFuShi,
	HouSanZuXuan_ZuSanDanShi,
	HouSanHunhe,
	WuXingQianEr_FuShi,
	WuXingQianEr_DanShi,
	QianErZuXuan_FuShi,
	QianErZuXuan_DanShi,
	WuXingHouEr_FuShi,
	WuXingHouEr_DanShi,
	HouErZuXuan_FuShi,
	HouErZuXuan_DanShi,
	QianSanZhiXuanHeZhi,
	ZhongSanZhiXuanHeZhi,
	HouSanZhiXuanHeZhi,
	BuDingWei_QianSan,
	BuDingWei_HouSan,
	BuDingWei_QianEr,
	BuDingWei_HouEr,
	DingWeiDan,
	DaXiaoDanShuang_DW,
	DaXiaoDanShuang,//�����С��˫
	Zonghe_DXDSLh,//��ֵ��С��˫
	RenXuan4,					//��ѡ��	//��ѡ2,3,4
	RenXuan4_DanShi,			//��ѡ�ĵ�ʽ					
	RenXuan3,					//��ѡ��
	RenXuan3_DanShi,			//��ѡ����ʽ	
	Ren3Zu6_Fushi,				//��3��6��ʽ	
	Ren3Zu6_DanShi,				//��3��6��ʽ
	Ren3Zu3_Fushi,				//��3��3��ʽ	
	Ren3Zu3_DanShi,				//������3��ʽ
	Ren3Hunhe_Zuxuan,			//��3��� ��ѡ	
	RenXuan2,					//�ζ�
	RenXuan2_DanShi,			//�ζ���ʽ
	Ren2Zuxuan_Fushi,			//��2��ѡ ��ʽ	
	Ren2Zuxuan_Danshi,			//��2��ѡ ��ʽ
	QW_YiFanFengShun,				//Ȥζ��һ����˳��һ��һ��һ�����־��н�
	QW_HaoShiChengShuang,			//Ȥζ�����³�˫��2��һ�������ֲ��н�
	QW_SanXingBaoXi,				//Ȥζ�����Ǳ�ϲ��3��һ�������ֲ��н�
	QW_SiJiFaCai,					//Ȥζ���ļ����ƣ�4��һ�������ֲ��н�
	SSC_LongHu						//������  ������456  
};

static PK10GameKind PK10WanfaMap[100] = {
	PKinValid,
	WF_GuanJun,		//�ھ�
	WF_GuanYaJun,	//���Ǿ�
	WF_GuanYaJun_DanShi,//���Ǿ���ʽ
	WF_QianSan,		//	ǰ��
	WF_QianSan_DanShi,
	WF_QianSi,		//	ǰ��
	WF_QianSi_DanShi,
	WF_QianWu,		//	ǰ��
	WF_QianWu_DanShi,
	WF_DWD,			//��λ��
	WF_DXDS,		//��С��˫������PK10û�кͣ�
	WF_GYHZ,		//���Ǻ�ֵ����עΪ��С��˫
	PK10WanFaCount
};

static ThreeNumbersKind treeNumbersMap[100] = {
	Invalid,
	enWF_QianyizhixuanFushi,			//ǰһֱѡ��ʽ,
	enWF_QianerzhixuanFushi,			//ǰ��ֱѡ��ʽ,
	enWF_QianerzhixuanDanshi,			//ǰ��ֱѡ��ʽ
	enWF_ZhixuanFushi,					//����ֱѡ��ʽ,
	enWF_ZhixuanDanshi,					//����ֱѡ��ʽ
	enWF_QiansanzusanFushi,				//ǰ��������ʽ,
	enWF_QiansanzusanDanshi,
	enWF_QiansanzuliuFushi,				//ǰ��������ʽ,
	enWF_QiansanzuliuDanshi,
	enWF_HouyizhixuanFushi,				//��һֱѡ��ʽ,
	enWF_HouerzhixuanFushi,				//���ֱѡ��ʽ,
	enWF_HouerzhixuanDanshi,
	enWF_Budingwei,						//���ǲ���λ,
	enWF_DingWeiDan,					//��λ��
	enWF_DaxiaoDanshuang,				//��С��˫	
	enWF_ZhixuanHezhi,					//����ֱѡ��ֵ,
};

static tagEnumIIXuan5 GuangDongwanFaMap[100] = {	
	IIinValid,
	QianYi,							//ǰһ
	QianEr_ZhiXuan,					//ǰ�� ֱѡѡ��
	QianEr_ZhiXuan_DanShi,			//ǰ��ֱѡ��ʽ
	QianEr_ZuXuan,					//ǰ����ѡѡ��
	QianSan_ZhiXuan,				//ǰ��ֱѡѡ��
	QianSan_ZhiXuan_DanShi,
	QianSan_ZuXuan,					//ǰ����ѡѡ��	
	IIRenXuan1,						//��ѡһ
	IIRenXuan1_DanShi,
	IIRenXuan2,						//��ѡ��
	IIRenXuan2_DanShi,
	IIRenXuan3,						//��ѡ��
	IIRenXuan3_DanShi,
	IIRenXuan4,						//��ѡ��
	IIRenXuan4_DanShi,
	IIRenXuan5,						//��ѡ��
	IIRenXuan5_DanShi,
	IIRenXuan6,						//��ѡ��
	IIRenXuan6_DanShi,
	IIRenXuan7,						//��ѡ��
	IIRenXuan7_DanShi,
	IIRenXuan8,						//��ѡ��
	IIRenXuan8_DanShi,
	IIRenXuan2_DanTuo,				//����
	IIRenXuan3_DanTuo,
	IIRenXuan4_DanTuo,
	IIRenXuan5_DanTuo,
	IIRenXuan6_DanTuo,
	IIRenXuan7_DanTuo,
	IIRenXuan8_DanTuo,
	IIWanFaCount
};

static QiXingCaiKind tagQiXingCai[50]=
{
	QiXingValidate,
	QiXingCai_LiangDing,
	QiXingCai_SanDing,
	QiXingCai_SiDing,
	QiXingCai_YiDing,
	QiXingCai_LiangZiXian,
	QiXingCai_SanZiXian
};

static int tagXingYun28[50]=
{
	xy28_validate,
	xy28_tm0,
	xy28_tm1,
	xy28_tm2,
	xy28_tm3,
	xy28_tm4,
	xy28_tm5,
	xy28_tm6,
	xy28_tm7,
	xy28_tm8,
	xy28_tm9,
	xy28_tm10,
	xy28_tm11,
	xy28_tm12,
	xy28_tm13,
	xy28_tm14,
	xy28_tm15,
	xy28_tm16,
	xy28_tm17,
	xy28_tm18,
	xy28_tm19,
	xy28_tm20,
	xy28_tm21,
	xy28_tm22,
	xy28_tm23,
	xy28_tm24,
	xy28_tm25,
	xy28_tm26,
	NBigNumber,
	NSmallNumber,	
	NBigSingleNumber,		
	NSmallSingleNumber,
	NBigDoubleNumber,
	NSmallDoubleNumber,
	NSingleNumber,
	NDoubleNumber,
	NLimitBig,
	NLimitSmall
};

static BeiJingKuai8Kind tagKuai8[50]=
{
	enBJK8_validate,
	enBJK8_RX_1,
	enBJK8_RX_2,
	enBJK8_RX_3,
	enBJK8_RX_4,
	enBJK8_RX_5,
	enBJK8_RX_6,
	enBJK8_RX_7,
	enBJK8_ShangXia,
	enBJK8_JiOu,
	enBJK8_HeZhiDXDS
};

static LiuHeCaiKind tagLiuHe[50] =
{
	LiuHeCai_validate,
	LiuHeCai_Tmdm,	
	LiuHeCai_Tmds,
	LiuHeCai_Tmsx,
	LiuHeCai_Tmbs,
	LiuHeCai_Pmdm,
	LiuHeCai_Zm1t,
	LiuHeCai_Zm2t,
	LiuHeCai_Zm3t,
	LiuHeCai_Zm4t,
	LiuHeCai_Zm5t,
	LiuHeCai_Zm6t
};

enum xIazhuyShiShiCAIWuType
{ 
	YuanShiShiCAITag = 0,                                   //Ԫ
	JiaoShiShiCAITag,                                         //��
	FenShiShiCAITag,                                           //��
	LiShiShiTag
};

#endif //_COMM_H_
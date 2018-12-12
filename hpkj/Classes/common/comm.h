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


//��Ʊ����
typedef enum {
	CZChongQingSSC=1,		//����ʱʱ��
	CZJiangXiSSC=2,			//����ʱʱ��
	CZ3D=3,					//����3D
	CZXinJiangSSC = 4,		//�½�ʱʱ��
	CZPailie3,				//����3
	CZGD11Xuan5,			//�㶫11ѡ5
	CZCQ11Xuan5,			//����11ѡ5 
	CZSD11Xuan5,			//ɽ��11ѡ5
	CZJX11Xuan5,			//����11ѡ5
	CZKUAILE8,				//��������8
	CZ_FENFEN_CAI,			//�ֲַʣ�5���ӿ�����24Сʱ��ͣ��ÿ��288��
	CZ_WUFEN_CAI,			//5�ֲ�
	CZ_BJKUAICHE,			//����PK10
	CZ_LIUHECAI = 14,
	CZ_QiXingCai = 15,		//���ǲ�--lly
	CZHLJ11Xuan5 = 16,		//������11ѡ5
	CZXingYun28,
	CZ_KUAI_3,				//���տ�3		1-6
	CZ_GD_HAPPY10MIN,		//�㶫����10��	8 of 20
	CZ_SECOND,				//�����
	CZ_LUCKY_FARM,			//����ũ�����������10��=21
	CZ_ERFEN_CAI,			//2�ֲ�
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
	NiuNiu_DxDs,				//ţţ����С��˫ 1:2.5
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

	//������ʽ�淨
	WuxingZhixuan_DanShi,	//����ֱѡ��ʽ
	WuxingQianSi_DanShi,	//����ǰ�ĵ�ʽ
	WuxingHousi_DanShi,		//���Ǻ��ĵ�ʽ	
	WuxingZhongsan_DanShi, //����������ʽ
	ZhongsanZuliu_DanShi,	//����������ʽ
	ZhongsanZusan_DanShi,	//����������ʽ

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

		//������ʽ�淨
		QianEr_ZhiXuan_DanShi,			//ǰ��ֱѡ��ʽ
		
		QianSan_ZhiXuan_DanShi,
		
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
	WuxingQianSi,
	WuxingQianSi_DanShi,	//����ǰ�ĵ�ʽ
	WuxingHousi,	
	WuxingHousi_DanShi,		//���Ǻ��ĵ�ʽ
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
	//QianErZhixuan_Hezhi, //Ŀǰ������
	//HouErZhixuan_Hezhi,	//Ŀǰû��
	BuDingWei_QianSan,
	BuDingWei_HouSan,
	BuDingWei_QianEr,
	BuDingWei_HouEr,
	DaXiaoDanShuang_DW,
	DingWeiDan,
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

	IIWanFaCount
};

enum xIazhuyShiShiCAIWuType
{ 
	YuanShiShiCAITag = 0,                                   //Ԫ
	JiaoShiShiCAITag,                                         //��
	FenShiShiCAITag,                                           //��
};

#endif //_COMM_H_
#ifndef CMD_FISH_H_
#define CMD_FISH_H_

#include "Define.h"
#include "cocos2d.h"
//////////////////////////////////////////////////////////////////////////
#pragma pack(push,1)
// ������
namespace NS_lrbyFish
{
const WORD BY_KIND_ID					= 715;
const WORD BY_GAME_PLAYER				= 8;				//��Ϸ������
const DWORD  BY_VERSION_SERVER			= 101056515;//100728832;       // PROCESS_VERSION(1,0,0)
const DWORD BY_VERSION_CLIENT			= 101056515;//100728832;      // PROCESS_VERSION(1,0,0)

// �򵥵İ汾���
// ����ͻ����и���Ӧ�ø������ֵ.���ֻ�޸�EXE�İ汾���������ݰ�û�޸ĵĻ������¿ͻ�����ûʲô����ģ���ΪEXE�İ汾�ǿ���ֱ�ӱ��޸ĵ�
// ֻҪ������ǰ��EXE�汾,������֮���ٻ���ȥ�������BUG�Ļ����ڻ���û�޸���
const WORD  GAME_VERSION			=30;

const int kResolutionWidth			= 1280;
const int kResolutionHeight			= 720;

typedef LONGLONG FISHSCORE;

// add by hxh 20161227
//#define USE_TRACETIME

#ifndef M_PI
#define M_PI    3.14159265358979323846f
#define M_PI_2  1.57079632679489661923f
#define M_PI_4  0.785398163397448309616f
#define M_1_PI  0.318309886183790671538f
#define M_2_PI  0.636619772367581343076f
#endif
const float kChairDefaultAngle[BY_GAME_PLAYER] = { M_PI, M_PI,M_PI, -M_PI_2, 0, 0, 0, M_PI_2};
const float kChairDefaultAngleOther[BY_GAME_PLAYER] = {180.0f,180.0f,180.0f,-90.0f,0.0f,0.0f,0.0f,90.0f};


//const float kChairDefaultAngle[BY_GAME_PLAYER] = {M_PI ,0};

enum TraceType {
  TRACE_LINEAR = 0,
  TRACE_BEZIER
};

struct FPoint {
  float x;
  float y;
};

struct FPointAngle {
  float x;
  float y;
  float angle;
};

//////////////////////////////////////////////////////////////////////////
// ��Ϸ����

/*
// ��λ��
-------------
    0   1   2 
7               3                
    6   5   4
-------------
*/

enum SceneKind {
  SCENE_KIND_1 = 0,
  SCENE_KIND_2,
  SCENE_KIND_3,
  SCENE_KIND_4,
  SCENE_KIND_5,

  SCENE_KIND_COUNT
};

enum FishKind {
  FISH_KIND_1 = 0,
  FISH_KIND_2,
  FISH_KIND_3,
  FISH_KIND_4,
  FISH_KIND_5,
  FISH_KIND_6,
  FISH_KIND_7,
  FISH_KIND_8,
  FISH_KIND_9,
  FISH_KIND_10,
  FISH_KIND_11,
  FISH_KIND_12,
  FISH_KIND_13,
  FISH_KIND_14,
  FISH_KIND_15,
  FISH_KIND_16,
  FISH_KIND_17,
  FISH_KIND_18,
  FISH_KIND_19,
  FISH_KIND_20, // ���
  FISH_KIND_21, // ����
  FISH_KIND_23, // �ֲ�ը��
  FISH_KIND_22, // ����ը��
  FISH_KIND_24, // ����ը�� 
  FISH_KIND_25, // ����Ԫ1
  FISH_KIND_26, // ����Ԫ2
  FISH_KIND_27, // ����Ԫ3
  FISH_KIND_28, // ����ϲ1
  FISH_KIND_29, // ����ϲ2
  FISH_KIND_30, // ����ϲ3
  FISH_KIND_31, // ����1
  FISH_KIND_32, // ����2
  FISH_KIND_33, // ����3
  FISH_KIND_34, // ����4
  FISH_KIND_35, // ����5
  FISH_KIND_36, // ����6
  FISH_KIND_37, // ����7
  FISH_KIND_38, // ����8
  FISH_KIND_39, // ����9
  FISH_KIND_40, // ����10
 // FISH_KIND_41, // ��ȯ��

  FISH_KIND_COUNT
};

enum BulletKind {
  BULLET_KIND_1_NORMAL = 0,
  BULLET_KIND_2_NORMAL,
  BULLET_KIND_3_NORMAL,
  BULLET_KIND_4_NORMAL,
  BULLET_KIND_1_ION,
  BULLET_KIND_2_ION,
  BULLET_KIND_3_ION,
  BULLET_KIND_4_ION,

  BULLET_KIND_COUNT
};

const DWORD kBulletIonTime						= 20;
const DWORD kLockTime							= 10;

const int kMaxCatchFishCount					= 2;

// ���ƿͻ��˵�����������
//const int kFishKindCount[FISH_KIND_COUNT] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

//////////////////////////////////////////////////////////////////////////
// ���������

const WORD SUB_S_GAME_CONFIG					= 100;
const WORD SUB_S_FISH_TRACE						= 101;
const WORD SUB_S_EXCHANGE_FISHSCORE				= 102;
const WORD SUB_S_USER_FIRE						= 103;
const WORD SUB_S_CATCH_FISH						= 104;
const WORD SUB_S_BULLET_ION_TIMEOUT				= 105;
const WORD SUB_S_LOCK_TIMEOUT					= 106;
const WORD SUB_S_CATCH_SWEEP_FISH				= 107;
const WORD SUB_S_CATCH_SWEEP_FISH_RESULT		= 108;
const WORD SUB_S_HIT_FISH_LK					= 109;
const WORD SUB_S_SWITCH_SCENE					= 110;
const WORD SUB_S_STOCK_OPERATE_RESULT			= 111;
const WORD SUB_S_SCENE_END						= 112;
const WORD SUB_S_FIRE_SCORE						= 113;
const WORD SUB_S_NOW_HARVEST					= 114;		//����ս��
const WORD SUB_S_ONLINE_AWARD					= 115;		//���߽���
const WORD SUB_S_AWARD_RESULT					= 116;      //���߽������ؽ��

//20150613
struct FishTraceInfo 
{
	float init_x_pos[5];
	float init_y_pos[5];
	int init_count;
};

struct CMD_S_GameStatus
{
  DWORD game_version;
  //bool   isscene;	//verysharp
  FISHSCORE fish_score[BY_GAME_PLAYER];
  FISHSCORE exchange_fish_score[BY_GAME_PLAYER];
};

struct CMD_S_FishScore
{
	LONGLONG fish_score[BY_GAME_PLAYER];
};

struct CMD_S_AwardScore
{
	WORD chair_id;
	int  curStep;
	FISHSCORE award_score;
};

struct CMD_S_GameConfig {
	int exchange_ratio_userscore;
	int exchange_ratio_fishscore;
	int exchange_count;

	int min_bullet_multiple;
	int max_bullet_multiple;

	int bomb_range_width;
	int bomb_range_height;

	int fish_multiple[FISH_KIND_COUNT];
	int fish_speed[FISH_KIND_COUNT];
	int fish_bounding_box_width[FISH_KIND_COUNT];
	int fish_bounding_box_height[FISH_KIND_COUNT];
	int fish_hit_radius[FISH_KIND_COUNT];

	int bullet_speed[BULLET_KIND_COUNT];
	int net_radius[BULLET_KIND_COUNT];
};

//struct CMD_S_GameConfig
//{
//  int exchange_ratio_userscore;
//  int exchange_ratio_fishscore;
//  int exchange_count;
//
//  int min_bullet_multiple;
//  int max_bullet_multiple;
//  //int cannonNumber;//verysharp
//
//  int bomb_range_width;
//  int bomb_range_height;
//
//  int fish_multiple[FISH_KIND_COUNT];
//  int fish_speed[FISH_KIND_COUNT];
//  int fish_bounding_box_width[FISH_KIND_COUNT];
//  int fish_bounding_box_height[FISH_KIND_COUNT];
//  int fish_hit_radius[FISH_KIND_COUNT];
//
//  int bullet_speed[BULLET_KIND_COUNT];
//  int net_radius[BULLET_KIND_COUNT];
//
//  int lock_percent;
//  int lostlock_percent;
//  int firetime_;
//  int fish_time;
//  int max_bullet_num;
//
//  int fishL_max_multiple;
//  int fishLK_max_multiple;
//};

struct CMD_S_FishTrace
{
  FPoint init_pos[5];
  int init_count;
  FishKind fish_kind;
  int fish_id;
  TraceType trace_type;
#ifdef USE_TRACETIME
  DWORD FishMoveSecs;
  DWORD BuildTraceTime;
#endif
};

struct CMD_S_ExchangeFishScore
{
  WORD chair_id;
  FISHSCORE swap_fish_score;
  FISHSCORE exchange_fish_score;
  //FISHSCORE user_score; //verysharp
};

struct CMD_S_UserFire
{
  BulletKind bullet_kind;
  int bullet_id;
  WORD chair_id;
  WORD android_chairid;
  float angle;
  int bullet_mulriple;
  int lock_fishid;
  FISHSCORE fish_score;
};

struct CMD_S_CatchFish
{
  WORD chair_id;
  int fish_id;
  FishKind fish_kind;
  bool bullet_ion;
  FISHSCORE fish_score;
  //FISHSCORE user_fish_score; //verysharp
};

struct CMD_S_BulletIonTimeout
{
  WORD chair_id;
};

struct CMD_S_CatchSweepFish
{
  WORD chair_id;
  int fish_id;
  //int bulletmul; //verysharp
};

struct CMD_S_CatchSweepFishResult
{
  WORD chair_id;
  int fish_id;
  FISHSCORE fish_score;
  FISHSCORE user_fish_score;
  int catch_fish_count;
  int catch_fish_id[300];
  //int bulletmul; //verysharp
};

struct CMD_S_HitFishLK
{
  WORD chair_id;
  int fish_id;
  int fish_mulriple;
};

struct CMD_S_SwitchScene
{
  SceneKind scene_kind;
  int fish_count;
  FishKind fish_kind[300];
  int fish_id[300];
};

struct CMD_S_StockOperateResult
{
  unsigned char operate_code;
  FISHSCORE stock_score;
};

struct CMD_S_FireHarvest
{
	int nFishHarvest[FISH_KIND_COUNT];
	LONGLONG iNowScore;			//��ǰ���ϵĽ��
	LONGLONG iNowFishScore;		//��ǰ���ϵ����
	LONGLONG iCanExchangeGold;	//���ϵ���ҿ�ת���ɵĽ��
};

struct CMD_S_OnLineAward {
	WORD chair_id;		//����ID
	int nAllStep; 
	int nCurStep;
	int nTotalTime;		//�û���ʱ��
};

//////////////////////////////////////////////////////////////////////////
// �ͻ�������

const WORD SUB_C_EXCHANGE_FISHSCORE				=1;
const WORD SUB_C_USER_FIRE						=2;
const WORD SUB_C_CATCH_FISH						=3;
const WORD SUB_C_CATCH_SWEEP_FISH				=4;
const WORD SUB_C_HIT_FISH_I						=5;
const WORD SUB_C_STOCK_OPERATE					=6;
const WORD SUB_C_USER_FILTER					=7;
const WORD SUB_C_ANDROID_STAND_UP				=8;
const WORD SUB_C_FISH20_CONFIG					=9;
const WORD SUB_C_ANDROID_BULLET_MUL				=10;
const WORD SUB_C_SWITCH_BULLENT					=11;
const WORD SUB_MOBILE_GET_Harvest				=12;		//�ֻ��˻�ȡ����ս��
const WORD SUB_C_ONLINE_AWARD_GET				=13;		//��ȡ��Ϸ���߽�����ʾ
const WORD SUB_C_ONLINE_AWARD_COM				=14;		//ȷ����ȡ��Ϸ���߽���
const WORD SUB_C_TIME_STAMP					    =15;		//ʱ���<by hxh>

/* 
ʱ���
������ʱ��T=(C2-C1+S1-S2)/2
ʱ���dT=C1-S1
���磬�������˹켣����ʱ��BuildTraceTime����ɿͻ��˵�ʱ�����BuildTraceTime+dT
*/
struct CMD_C_TimeStamp
{
	CMD_C_TimeStamp()
	{
		memset(this, 0, sizeof(*this));
	}
     
	unsigned long long tClientSendTime;				//�ͻ��˷���ʱ��C1,�ͻ��˷��������ʱ��д
	DWORD tServerRecvTime;							//����������ʱ��S1
	DWORD tServerSendTime;							//����������ʱ��S2
    unsigned long long tClientRecvTime;				//�ͻ��˽���ʱ��C2,�ͻ����յ����ذ�ʱ��д
	// ��������ĳ���
    long long tTransTime;//����T 
    long long tClientServerTimeInterval;//����dT
	inline void AutoCalc();
};

inline void CMD_C_TimeStamp::AutoCalc()
{
	tTransTime=(tClientRecvTime-tClientSendTime+tServerRecvTime-tServerSendTime)/2;
	tClientServerTimeInterval=tClientSendTime-tServerRecvTime;
}

struct CMD_C_ExchangeFishScore
{
	int increase;		//0��ʾ�·֣�1��ʾ�������ļ��趨�����Ϸ֣�2��ʾһ�����������еķ֣�3��ʾ�ֻ����Ϸ�
	//__int64 iExchangeCount;	//�ֻ����Ϸ����� //verysharp
};

struct CMD_C_UserFire
{
  BulletKind bullet_kind;
  float angle;
  int bullet_mulriple;
  int lock_fishid;
};

struct CMD_C_CatchFish
{
  WORD chair_id;
  int fish_id;
  BulletKind bullet_kind;
  int bullet_id;
  int bullet_mulriple;
  //DWORD dwCatchFishTick; //verysharp
};

struct CMD_C_CatchSweepFish
{
  WORD chair_id;
  int fish_id;
  int catch_fish_count;
  int catch_fish_id[300];
  //int bulletmul;  //verysharp
  //DWORD dwCatchFishTick;  //verysharp
};

struct CMD_C_HitFishLK
{
  int fish_id;
  //int bulletmul; //verysharp
};

struct CMD_C_StockOperate
{
  unsigned char operate_code; // 0��ѯ 1 ��� 2 ���� 3 ��ѯ��ˮ
};

struct CMD_C_UserFilter
{
  DWORD game_id;
  unsigned char operate_code; // 0 ������ 1 ������ 2 ���
};

struct CMD_C_Fish20Config 
{
  DWORD game_id;
  int catch_count;
  double catch_probability;
};

struct CMD_C_AndroidBulletMul
{
  WORD chair_id;
  int bullet_id;
  int bullet_mulriple;
  BulletKind bullet_kind;
};

enum SendDataBaseRequst
{	
	DBR_GR_FISH_ROOMDATA = 2000,				//��ѯ����
	DBR_GR_FISH_SAVE_SUERDATA,					//д�˸���	
	DBR_GR_FISH_GET_SUERDATA,					//��ȡ����	
	DBR_GR_FISH_UPATA_SUERDATA					//���¸���

};

}
#pragma pack(pop)
#endif // CMD_FISH_H_

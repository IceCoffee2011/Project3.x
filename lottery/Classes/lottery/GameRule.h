#pragma once
#include "EntityMgr.h"
#include "comm.h"
#include <string>
#include "cocos2d.h"
using namespace std;

//#define		KJ_QIHAO_LENGTH		255
//#define		KJ_SHIJIAN_LENGTH		255

#define IN 
#define OUT

const int delay_chqssc = 0;
const int delay_xjssc = 0;
const int delay_wfc = 0;

class CGameRule:public Node
{
public:
	virtual ~CGameRule(void);
protected:
	CGameRule(void);
	MsgDispatch *theApp;
	static int GetSecByHMS(int h,int m,int s);
	//��ȡ�����賿��ʱ����ʱ���
	static time_t GetMorningTime(time_t t);
public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0) = 0;
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj() = 0;
	//���´ο���ʱ�仹ʣ�µ�ʱ��
	virtual long GetKjShjDiff();
	//���´ο���ʱ�仹ʣ�µ�ʱ��-�ַ�������		��ֲʴ�30	�ֲַʴ�10
	virtual string GetKjShjDiffDesc();
	//�Ƿ�ɳ���-�뿪��ʱ�����������
	virtual bool IsCanCancel(string qihao);
	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();

	//add by hd
	CC_SYNTHESIZE(int, fenDanDuration, FenDanDuration);
	CC_SYNTHESIZE(int, isStopSell,IsStopSell);

	int  m_nStartQihao;      //��ʼ���ں�
	time_t	m_tStartTime;	//��ʼ��ʱ��

	int m_iKjShjFirst;//ÿ���һ�ڿ���ʱ��
	int m_iKjShjLast;//ÿ�����һ�ڿ���ʱ��
	int m_qishu;//ÿ�쿪������
	int m_timespan;//����Ƶ��

	//�Ƿ��ڷⵥʱ����
	bool IsFenDanDuration();

	//���ó�ʼ�ں�
	void SetStartQiHao(int value);
	//���ó�ʼʱ��
	void SetStartTime(const char* value);
};

//////////////////////////////////////////////////////
/*
����ʱʱ��2019.2����ǰ��
ʱ��1 00:00-02:00(0-7200)
ʱ��2 10:00-22:00(36000-79200)
ʱ��3 22:00-24:00(79200-86400)
565,�µ�ʱ��09:25
fenDanDuration = 35;�ⵥʱ��00:35
ÿ��ʱ����timespan_ye_kj_shj=600s
������
ʱ��1 00:10-03:10(600-11400)ǰ9��
ʱ��2 03:10-07:10(11400-25800)
ʱ��3 07:10-23:50(25800-85800)��50��
*/
class CChqSSCRule : public CGameRule
{
public:
	CChqSSCRule(void);
	virtual ~CChqSSCRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	virtual bool IsCanCancel(string qihao);

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();

	//��ȡ�ں�
	int GetQiShu(int sec);
	//��ȡ����ʱ��
	int GetKjShj(int qishu);
};

//////////////////////////////////////////////////////////////////////////
//����1.5�ֲ�
//////////////////////////////////////////////////////////////////////////
class CHgydwfcRule : public CGameRule
{
public:
	CHgydwfcRule(void);
	virtual ~CHgydwfcRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
	bool IsCanCancel(string qihao);
	//virtual string GetKjShjDiffDesc(int nSecond = 60);
	void SetQihaocha(int nQihao);
	void SetStartQihao(const char* nQihao,const char* chTime);

private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
	int timespan_kj_shj;
	int timespan_ye_kj_shj;
	int nQihaocha;
};

//////////////////////////////////////////////////////////////////////////
//���ô�3.5�ֲ�
//////////////////////////////////////////////////////////////////////////
class CCanadaSDWFRule : public CGameRule
{
public:
	CCanadaSDWFRule(void);
	virtual ~CCanadaSDWFRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

////////////////////////////////////////////////////////////
//ԭ������ ���ڵ�����
class CJxSSCRule  : public CGameRule
{
public:
	CJxSSCRule(void);
	CJxSSCRule(int iKjShjFirst,int iKjShjLast,int qishu,int timespan,int fdtimespan);
	virtual ~CJxSSCRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//��ȡ�ں�
	virtual int GetQiShu(int sec);
	//��ȡ����ʱ��
	virtual int GetKjShj(int qishu);
};


/////////////////////////////////////////////////////////
//�½���
class CXJSSCRule  : public CGameRule
{
public:
	CXJSSCRule(void);
	CXJSSCRule(int iKjShjFirst,int iKjShjLast,int qishu,int timespan,int fdtimespan);
	virtual ~CXJSSCRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//��ȡ�ں�
	virtual int GetQiShu(int sec);
	//��ȡ����ʱ��
	virtual int GetKjShj(int qishu);
};

////////////////////////////////////////////////////////////////////////
class CFenFenCaiRule : public CGameRule
{
public:
	CFenFenCaiRule(void);
	virtual ~CFenFenCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
private:	

	int timespan_kj_shj;

};

////////////////////////////////////////////////////////////////////////
class CTentcentCaiRule : public CGameRule
{
public:
	CTentcentCaiRule(void);
	virtual ~CTentcentCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];
};

////////////////////////////////////////////////////////////////////////
class CQQCaiRule : public CGameRule
{
public:
	CQQCaiRule(void);
	virtual ~CQQCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];
};

//���ֲ�///////////////////////////////////////////////////////
class CErFenCaiRule : public CGameRule
{
public:
	CErFenCaiRule(void);
	virtual ~CErFenCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

/////////////////////////////////////////////////////////////////////
class CWuFenCaiRule : public CGameRule
{
public:
	CWuFenCaiRule(void);
	virtual ~CWuFenCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

///////////////////////////////////////////////////////////////////////////
//�㶫11ѡ5��ɽ��11ѡ5������11ѡ5��������11ѡ5
class CGD11X5Rule : public CJxSSCRule
{
public:
	struct tagStr
	{
		tagStr()
		{
			memset(this,0,sizeof(*this));
		}
		char m_lastExpect[KJ_QIHAO_LENGTH];
	    char m_lastKjShj[KJ_SHIJIAN_LENGTH];  
	};

	CGD11X5Rule(void);
	CGD11X5Rule(CaiZhong gameKind,const char *para1,int iKjShjFirst,int iKjShjLast,int qishu,int timespan,int fdtimespan);
	virtual ~CGD11X5Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);

public:
	static map<CaiZhong,tagStr> m_mapStr;
	CaiZhong m_gameKind;
	char m_para1[20];
};

//////////////////////////////////////////////////////////////////
//����11ѡ5
class CCQ11X5Rule : public CGameRule
{
public:
	CCQ11X5Rule(void);
	virtual ~CCQ11X5Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//////////////////////////////////////////////////////
//������11ѡ5
class CHlj11X5Rule : public CGameRule
{
public:
	CHlj11X5Rule(void);
	virtual ~CHlj11X5Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};
///////////////////////////////////////////////////////////////
//PK10:
class  CBJPK10Rule : public CGameRule
{
public:
	CBJPK10Rule(void);
	virtual ~CBJPK10Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//��ȡ�����һ�ڵ��ں�	
	int GetQiShu0();
	//���쵽�˶�����
	int GetQiShu(int sec);
	//��ȡ����ʱ��
	int GetKjShj(int qishu);
private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

class CFC3DRule : public CGameRule
{
public:
	CFC3DRule(void);
	virtual ~CFC3DRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

class CPL3Rule : public CGameRule
{
public:
	CPL3Rule(void);
	virtual ~CPL3Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//���ǲ�
class CQiXingCaiRule : public CGameRule
{
public:
	CQiXingCaiRule(void);
	virtual ~CQiXingCaiRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

class CKuaiLe8Rule : public CGameRule
{
public:
	CKuaiLe8Rule(void);
	virtual ~CKuaiLe8Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//��ȡ�����һ�ڵ��ں�	
	int GetQiShu0();
	//���쵽�˶�����
	int GetQiShu(int sec);
	//��ȡ����ʱ��
	int GetKjShj(int qishu);
private:

	int timespan_kj_shj;
};

//���ϲ�
class LiuHeCaiRule : public CGameRule
{
public:
	LiuHeCaiRule(void);
	virtual ~LiuHeCaiRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//���ÿ���ʱ��
	static void SetNextKjShj(int wYear,int wMonth,int wDay,int wHour,int wMinute,int wSecond,int wMilliseconds);

	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static int m_nextExpect;  //�����ں�
	static time_t m_nextKjShj; //���ڿ���ʱ��

};
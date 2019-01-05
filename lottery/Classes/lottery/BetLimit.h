#ifndef _BETLIMIT_H_
#define _BETLIMIT_H_

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class BetLimit
{
public:
	BetLimit(){}
	~BetLimit(){}
	//�Ƿ񳬹�ע������
	static int GetMaxBetFromId(int gameKind,int wanfaId);
	//�õ��淨������
	static std::string GetWanFaNameFromId(const int gameId,const int wanfaId);
	//��ⶨλ���Ƿ�Ϸ�Ͷע  �����淨Ҳʹ�ô˺���
	static bool CheckDingWeiDanStr(int wanfaId,const char* betNumber);
	//У�������ַ���
	static std::string AjustDateStr(const char* dateString);
	//��������ַ���
	static bool CheckDateStr(const char* dateString);
	//�����ͷ���
	static std::string GetLongHuHeStr(const char* touzhunumber);
	//���������ż����
	static std::string GetKuai8Str(const char* touzhunumber,const int delta = 0);
	//���ϲʷ���
	static std::string GetLiuHeCaiStr(const char* touzhunumber, const int delta = 0);
	//��Ф����
	static std::string GetLiuHeShengXiaoStr(const char* touzhunumber);
	//��С��˫����
	static std::string GetDXDSHStr(const char* touzhunumber);
	//��ʮ��ǧ����
	static std::string GetGSBQWStr(const char* touzhunumber);
	//����28����
	static std::string GetXingYunStr(const int wanfa,const char* touzhunumber);
	//����28�������
	static std::string GetXingYunResultStr(const char* resultStr);
	//��8�ַ�����
	static std::string GetKuai8ResultStr(const char* resultStr);
	//��������***
	static std::string GetNameWithXing(const char* name);
	//���п�������
	static std::string GetBankCardWithXing(const char* name);
	//��������ַ�����Ч�� ��ȫ��Ϊ����
	static std::string GetDanShiStr(const char* touzhunumber,const int number,const int isRepeat,const int maxNum,const int numCount = 1,const bool isPK = false);
	//��ѡ��ʽ
	static std::string GetRenXuanDanShiStr(const char* touzhunumber,const int number,const int isRepeat,const int maxNum,const char* tailStr,int beishu,bool isZhiXuan);
	//�ض�λ�淨id typeId 0, 1, 2, 3, 4, 5�ֱ���������, �㶫11ѡ5, PK10, 3D ���ǲ� ��8
	static int GetWanfaIdFromId(const int wafaId,const int typeId);
	//���ַ���
	static void SpanStringByLen(std::string &spanStr,const int len = 35);
	//����ַ����Ƿ��пո�
	static bool CheckStrSpace(const char* str);
	//����ַ����Ƿ��ַ�
	static bool ValidateStr(const char* str);
	//׷������
	static long long getRealQihao(long long iQihao,int gameKind, long long GDselectedItemTagNumber);
	//��������ַ���  Ĭ��λ��Ϊ5����ʱ����������λ�� ����ע��
	static int GetStrFromSplit(std::string &splitStr, const int num,const int maxCount);
	//��ȡ�������
	static int GetLastNumberFromStr(const char* str);
	//�Զ�ȥ���ո�
	static std::string GetStrWithoutSpace(const char* str);
	//ȥ��html��ǩ
	static std::string GetStrWithoutHtml(const char* str);
};

#endif
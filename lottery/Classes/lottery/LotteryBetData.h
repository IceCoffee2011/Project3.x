#ifndef _LOTTERY_BET_DATA_H_
#define _LOTTERY_BET_DATA_H_

#include "cocos2d.h"

#define LIST_MAX_SIZE 9

USING_NS_CC;


class MyBetData
{
private:

	static MyBetData* _instance;
	//�û��Ѿ�ѡ����淨 ���� id�Ǻ���Ե�xml�������һ����
	std::vector<int> m_wanfaList;
	//�û����ֲ��� ��һ�������ǵ�ǰ�淨���ڶ��������ǵ�ǰԪ�Ƿ�
	std::vector<int> m_paramList;
	//��ǰ���ֵ�id
	int m_curCaizhong;
	//�淨key
	std::string m_wanfaKey;
	//����key
	std::string m_paramKey;
	
	MyBetData();
	~MyBetData();	

public:
	static MyBetData* getInstance();	

	//id
	bool addWanfaToList(const int wanfaId);
	bool delWanfaFromList(const int wanfaId);
	//���õ�ǰ����
	void setCurCaiZhongId(const int caizhongId);
	int getCurCaiZhongId();
	//��һ���淨
	void setLastWanfaId(const int wanfaId);
	int getLastWanfaId();
	//��һ��Ԫ�Ƿ�
	void setLastMoShi(const int moshi);
	int getLastMoshi();
	//��������
	void saveData(bool isSaveWanfa = true,bool isSaveParam = true);
	//��ȡ����
	void reloadData();

	//�淨�б��С
	int getWanfaSize();
	//�淨�б��ֵ
	int getWanfaAt(const int index);

private:

	//�ָ��ַ���
	void splitString(std::vector<int>& vec,std::string str);

};


#endif //_LOTTERY_BET_DATA_H_
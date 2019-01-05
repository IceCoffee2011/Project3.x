#include "LotteryBetData.h"
#include "EntityMgr.h"

MyBetData* MyBetData::_instance = nullptr;

MyBetData::MyBetData()
{

}

MyBetData::~MyBetData()
{
	if(_instance) delete _instance;
}

MyBetData* MyBetData::getInstance()
{
	if(_instance == nullptr)
	{
		_instance = new (std::nothrow)MyBetData();

		_instance->m_curCaizhong = 0;
	}

	return _instance;
}

//id
bool MyBetData::addWanfaToList(const int wanfaId)
{
	bool result = false;

	if(m_wanfaList.size() >= LIST_MAX_SIZE) return result;

	for(int i  = 0;i < m_wanfaList.size();i ++)
	{
		if(wanfaId == m_wanfaList.at(i))
		{
			return result;
		}
	}

	m_wanfaList.push_back(wanfaId);

	saveData();
	//��ӳɹ�
	result = true;

	return result;
}

bool MyBetData::delWanfaFromList(const int id)
{
	bool result = false;

	if(m_wanfaList.size() == 1) return result;

	for(int i = 0;i < m_wanfaList.size();i ++)
	{
		if(id == i)
		{
			//ɾ���ɹ�
			result = true;
			m_wanfaList.erase(m_wanfaList.begin() + i);
			break;
		}
	}

	return result;
}

//���õ�ǰ����
void MyBetData::setCurCaiZhongId(const int caizhongId)
{
	if(m_curCaizhong == caizhongId)
	{
		//return;
	}
	//��ֵ
	m_curCaizhong = caizhongId;

	//���¼���
	m_wanfaKey.clear();	
	m_wanfaKey.append(String::createWithFormat("WanFaList_%d_%d",EntityMgr::instance()->getDispatch()->m_dwUserID,m_curCaizhong)->getCString());
	m_paramKey.clear();
	m_paramKey.append(String::createWithFormat("ParamList_%d_%d",EntityMgr::instance()->getDispatch()->m_dwUserID,m_curCaizhong)->getCString());

	reloadData();

}

int MyBetData::getCurCaiZhongId()
{
	return m_curCaizhong;
}

//��һ���淨
void MyBetData::setLastWanfaId(const int wanfaId)
{
	m_paramList[0] = wanfaId;

	saveData();
}

int MyBetData::getLastWanfaId()
{
	return m_paramList.at(0);
}

//��һ��Ԫ�Ƿ�
void MyBetData::setLastMoShi(const int moshi)
{
	m_paramList[1] = moshi;

	saveData();
}

int MyBetData::getLastMoshi()
{
	return m_paramList.at(1);
}

void MyBetData::splitString(std::vector<int>& vec,std::string str)
{
	//����һ
	//int i=0;
	//
	//char buff[30];
	//memset(buff,0,sizeof(buff));
	//sprintf(buff, str.c_str());
	////���9��
	//char* p[9];
	//memset(p,0,sizeof(p));

	//while((p[i]=strtok(buff,","))!=NULL) 
	//{
	//	vec.push_back(atoi(p[i]));
	//	i++;		
	//}

	//������
	int i = 0;
	int pos1,pos2 = 0;

	std::string tempStr;
	tempStr.clear();
	tempStr.append(str);

	pos1 = 0;
	pos2 = 0;
	while(pos2 >= 0 && pos2 != tempStr.npos)
	{
		//�ÿ�		
		pos2 = tempStr.find(",");
		if(pos2 > 0 && pos2 != tempStr.npos)
		{
			vec.push_back(atoi(tempStr.substr(pos1,pos2 - pos1).c_str()));
		} else
		{
			vec.push_back(atoi(tempStr.substr(pos1,tempStr.size() - pos1).c_str()));
			break;
		}
		tempStr[pos2] = ' ';
		pos1 = pos2 + 1;		
	}
}

void MyBetData::saveData(bool isSaveWanfa,bool isSaveParam)
{
	std::string myStr = "";
	//�����淨�˵�
	if(isSaveWanfa)
	{
		for(int i = 0;i <m_wanfaList.size();i ++)
		{
			if(i != 0) myStr.append(",");
			const char* temp = String::createWithFormat("%d",m_wanfaList.at(i))->getCString();
			myStr.append(temp);		
		}
		UserDefault::getInstance()->setStringForKey(m_wanfaKey.c_str(),myStr);
	}	

	myStr.clear();
	//�����û�ϰ��
	if(isSaveParam)
	{
		for(int j = 0;j < m_paramList.size();j ++)
		{
			if(j != 0) myStr.append(",");
			const char* temp = String::createWithFormat("%d",m_paramList.at(j))->getCString();
			myStr.append(temp);	
		}
		UserDefault::getInstance()->setStringForKey(m_paramKey.c_str(),myStr);
	}
}

void MyBetData::reloadData()
{
	//����б�
	m_paramList.clear();
	m_wanfaList.clear();

	//std::vector<int>(m_paramList).swap(m_paramList);
	//std::vector<int>(m_wanfaList).swap(m_wanfaList);

	//��������
	std::string tempWanfaList = UserDefault::getInstance()->getStringForKey(m_wanfaKey.c_str(),"");
	std::string tempParamList = UserDefault::getInstance()->getStringForKey(m_paramKey.c_str(),"");

	if(tempWanfaList.size() > 0)
	{
		splitString(m_wanfaList, tempWanfaList);
	}else
	{
		m_wanfaList.push_back(1);
	}

	if(tempParamList.size() > 0)
	{
		splitString(m_paramList, tempParamList);
	}else
	{
		m_paramList.push_back(-1);
		m_paramList.push_back(0);
	}
}

int MyBetData::getWanfaSize()
{
	return m_wanfaList.size();
}

int MyBetData::getWanfaAt(const int index)
{
	if(index >= m_wanfaList.size())
	{
		return 0;
	}

	return m_wanfaList.at(index);
}
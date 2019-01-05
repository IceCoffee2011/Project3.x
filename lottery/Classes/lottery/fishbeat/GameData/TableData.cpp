#include "TableData.h"
#include "GlobalDef.h"
#include "CMD_Fish.h"

TableData::TableData(void)
{
	m_pIClientItems = NULL;
	m_bLockerFlag=false;						// ����־
	m_bPlayStatus=false;						// ��Ϸ��־
}

TableData::~TableData(void)
{
	if (m_pIClientItems != NULL)
	{
		delete []m_pIClientItems;
		m_pIClientItems = NULL;
	}
}
//��������
WORD TableData::GetNullChairCount(WORD & wNullChairID)
{
	//���ñ���
	wNullChairID=INVALID_CHAIR;
	WORD wChairCount = 1;//GameRoom::GetInstance()->GetTableFrame()->GetChairCount();

	//Ѱ��λ��
	for (WORD i=0;i<wChairCount;i++)
	{
		if (m_pIClientItems[i]==NULL)
		{
			wNullChairID=i;
			return wNullChairID;
		}
	}
	return INVALID_TABLE;
}

//���ú���
void TableData::InitTableView(WORD wTableID, WORD wChairCount)
{
	if (m_pIClientItems != NULL)
	{
		delete []m_pIClientItems;
		m_pIClientItems = NULL;
	}


	// ��ȡ�������������
	WORD wTableChairCount = NS_lrbyFish::BY_GAME_PLAYER;//GameRoom::GetInstance()->GetTableFrame()->GetChairCount();
	m_pIClientItems = new CUserItem *[wTableChairCount];
	for (WORD i = 0; i < wTableChairCount; i++)
	{
		m_pIClientItems[i]=NULL;
	}
}
//��ȡ�û�
CUserItem * TableData::GetClientUserItem(WORD wChairID)
{
	WORD wChairCount = NS_lrbyFish::BY_GAME_PLAYER;//GameRoom::GetInstance()->GetTableFrame()->GetChairCount();
	if (wChairID < wChairCount)
		return m_pIClientItems[wChairID];
	return NULL;
}
//������Ϣ
bool TableData::SetClientUserItem(WORD wChairID, CUserItem * pIClientUserItem)
{
	WORD wChairCount = NS_lrbyFish::BY_GAME_PLAYER;//GameRoom::GetInstance()->GetTableFrame()->GetChairCount();
	if (wChairID < wChairCount)
		m_pIClientItems[wChairID] = pIClientUserItem;
	return true;
}
// ����״̬
void TableData::setTableStatus(bool bPlaying, bool bLocker)
{
	m_bPlayStatus = bPlaying;
	m_bLockerFlag = bLocker;
}
//��Ϸ��־
bool TableData::GetPlayFlag()
{
	return m_bPlayStatus;
}
//�����־
bool TableData::GetLockerFlag()
{
	return m_bLockerFlag;
}

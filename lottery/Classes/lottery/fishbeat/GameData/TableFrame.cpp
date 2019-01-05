#include "TableFrame.h"
#include "UserItem.h"
#include "GlobalDef.h"
#include "UINotificationCenter.h"


CTableFrame::CTableFrame(void)
{
	m_nTableCount = 0;
	m_bWaitDistribute=false;
	m_TableView = NULL;
	m_nEnterTableID = INVALID_TABLE;
	m_lServerRule = 0;
}


CTableFrame::~CTableFrame(void)
{
	if(m_TableView!=NULL)
	{
		delete []m_TableView;
		m_TableView = NULL;
	}
}
bool CTableFrame::ConfigTableFrame(WORD nTableCount, WORD nChairCount,DWORD lServerRule, WORD nServerType, WORD nServerID)
{	
		m_nTableCount = nTableCount;
		m_nChairCount = nChairCount;
		m_lServerRule = lServerRule;
		if(m_TableView!=NULL)
		{
			delete []m_TableView;
			m_TableView = NULL;
		}
		m_TableView = new TableData[m_nTableCount];
		for (WORD i = 0; i < nTableCount; i++)
		{
			m_TableView[i].InitTableView(i+1, nChairCount);
		}
		//		
	return true;
}
// ������Ŀ
WORD CTableFrame::GetTableCount()
{
	return m_nTableCount;
}

// ������Ŀ
WORD CTableFrame::GetChairCount()
{
	return m_nChairCount;
}

// ��ȡ�û�
CUserItem* CTableFrame::GetClientUserItem(WORD nTableID, WORD nChairID)
{
	if (nTableID < m_nTableCount)
		return m_TableView[nTableID].GetClientUserItem(nChairID);
	return NULL;
}

// ������Ϣ
bool CTableFrame::SetClientUserItem(WORD nTableID, WORD nChairID,TableData* clientUserItem)
{
	if (nTableID < m_nTableCount)
	{
		bool bRet= m_TableView[nTableID].SetClientUserItem(nChairID,(CUserItem*)clientUserItem);
		CUINotificationBuffer *pNotifRef = CUINotificationBuffer::create(em_GR_UpdateTable,nTableID);
		NotificationCenter::getInstance()->postNotification("ongameroom", pNotifRef);
		return true;
	}
	return false;
}

// ��Ϸ��־
bool CTableFrame::GetPlayFlag(WORD nTableID)
{
	if (nTableID < m_nTableCount)
		return m_TableView[nTableID].GetPlayFlag();
	return false;
}

// �����־
bool CTableFrame::GetLockerFlag(WORD nTableID)
{
	if (nTableID < m_nTableCount)
		return m_TableView[nTableID].GetLockerFlag();
	return false;
}

// ������
void CTableFrame::SetFocusFrame(WORD nTableID, bool bFocusFrame)
{

}

// ����״̬
void CTableFrame::SetTableStatus(WORD nTableID, bool bPlaying, bool bLocker)
{
	if (nTableID < m_nTableCount)
	{
		m_TableView[nTableID].setTableStatus(bPlaying, bLocker);
		CUINotificationBuffer *pNotifRef = CUINotificationBuffer::create(em_GR_UpdateTable,nTableID);
		NotificationCenter::getInstance()->postNotification("ongameroom", pNotifRef);
	}
}

//����״̬ (�Ƿ�ȴ�����)
void CTableFrame::SetTableStatus(bool bWaitDistribute)
{
	m_bWaitDistribute=bWaitDistribute;
	//CUINotificationBuffer *pNotifRef = CUINotificationBuffer::create(em_GR_UpdateTable,nTableID);
	//NotificationCenter::getInstance()->postNotification("ongameroom", pNotifRef);
	return;
}
// ���ӿ���
bool CTableFrame::VisibleTable(WORD nTableID)
{
	return true;
}

// ������Ϸ����ͼ
bool CTableFrame::UpdateTableView(WORD nTableID)
{
	CUINotificationBuffer *pNotifRef = CUINotificationBuffer::create(em_GR_UpdateTable,nTableID);
	NotificationCenter::getInstance()->postNotification("ongameroom", pNotifRef);
	return true;
}

// ��ȡ����
TableData* CTableFrame::GetTableViewItem(WORD nTableID)
{
	if (nTableID < m_nTableCount)
		return &m_TableView[nTableID];
	return NULL;
}

// ��������0λ�ñ�ʾ������1λ�ñ�ʾ��λ
WORD CTableFrame::GetNullChairCount(WORD nTableID, WORD & wNullChairID)
{
	if (nTableID < m_nTableCount)
	{
		m_TableView[nTableID].GetNullChairCount(wNullChairID);
		if(wNullChairID!=INVALID_CHAIR)
			return nTableID;//m_TableView[nTableID].GetNullChairCount(wNullChairID);
	}
	return INVALID_TABLE;
}

#ifndef __ROOM_FRAMESINK_H__
#define __ROOM_FRAMESINK_H__

#pragma once
#include "cocos2d.h"
#include "TableData.h"
#include "Define.h"

#define UPDATA_ROOM_TABLE 123

class CTableFrame 
{
private:
	// ��Ϣ�洢
	WORD					m_nTableCount;
	bool                    m_bWaitDistribute;                  //�ȴ�����
	WORD					m_nChairCount;
	TableData*				m_TableView;
	DWORD					m_lServerRule;
public:
	WORD					m_nEnterTableID;
	CTableFrame(void);
	~CTableFrame(void);
public:
	// �ͷŶ���
	virtual void Release(){ delete this;}
	// �ӿڲ�ѯ
	//virtual void * QueryInterface(REFGUID Guid, DWORD dwQueryVer){return NULL;};
	// ��������
	virtual bool ConfigTableFrame(WORD nTableCount, WORD nChairCount,DWORD lServerRule, WORD nServerType, WORD nServerID);
	// ������Ŀ
	virtual WORD GetTableCount();
	// ������Ŀ
	virtual WORD GetChairCount();
	// ��ȡ�û�
	virtual CUserItem* GetClientUserItem(WORD nTableID, WORD nChairID);
	// ������Ϣ
	virtual bool SetClientUserItem(WORD nTableID, WORD nChairID,TableData* clientUserItem);
	// ��Ϸ��־
	virtual bool GetPlayFlag(WORD nTableID);
	// �����־
	virtual bool GetLockerFlag(WORD nTableID);
	// ������
	virtual void SetFocusFrame(WORD nTableID, bool bFocusFrame);
	// ����״̬
	virtual void SetTableStatus(WORD nTableID, bool bPlaying, bool bLocker);
	//����״̬ (�Ƿ�ȴ�����)
	virtual void SetTableStatus(bool bWaitDistribute);
	// ���ӿ���
	virtual bool VisibleTable(WORD nTableID);
	// ������Ϸ����ͼ
	virtual bool UpdateTableView(WORD nTableID);
	// ��ȡ����
	virtual TableData* GetTableViewItem(WORD nTableID);
	// ��������0λ�ñ�ʾ������1λ�ñ�ʾ��λ
	virtual WORD GetNullChairCount(WORD nTableID, WORD & wNullChairID);
	// ����״̬
	bool GetWaitDistribute() { return m_bWaitDistribute;};
	// �������
	DWORD GetServerRule() { return m_lServerRule; };
};

#endif //__ROOM_FRAMESINK_H__

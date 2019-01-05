#ifndef _TABLE_VIEW_H_
#define _TABLE_VIEW_H_
#pragma once

#include "cocos2d.h"
#include "AppDelegate.h"
#include "UserItem.h"
#include "Define.h"

class TableData
{
	// / �洢��Ϣ
	CUserItem**			m_pIClientItems;			        // �����û���Ϣ
	bool						m_bLockerFlag;						// ����־
	bool						m_bPlayStatus;						// ��Ϸ��־

public:
	TableData(void);
	~TableData(void);
	//�ͷŶ���
	virtual void Release(){ delete this;}
	//�ӿڲ�ѯ
	//virtual void * QueryInterface(REFGUID Guid, DWORD dwQueryVer){return NULL;};

	//��������
	virtual WORD GetNullChairCount(WORD & wNullChairID);
	//���ú���
	virtual void InitTableView(WORD wTableID, WORD wChairCount);
	//��ȡ�û�
	virtual CUserItem * GetClientUserItem(WORD wChairID);
	//������Ϣ
	virtual bool SetClientUserItem(WORD wChairID, CUserItem * pIClientUserItem);
	// ����״̬
	virtual void setTableStatus(bool bPlaying, bool bLocker);
	//��Ϸ��־
	virtual bool GetPlayFlag();
	//�����־
	virtual bool GetLockerFlag();
};

#endif //_TABLE_VIEW_H_

//
//  TcpNetwork.h
//  SDH
//
//  Created by zhouwei on 13-6-6.
//
//

#ifndef __SDH__TcpNetwork__
#define __SDH__TcpNetwork__

#define SOCKET_TCP_VER 0x01


#include <iostream>
#include "Define.h"
#include "BaseObject.h"
#include "GBEvent.h"
#include "GC_Socket.h"

//class MsgDispatch;
class ClientSock : public BaseObject
{
public:

	ClientSock();
	~ClientSock();

	void update();

	//�ж��ͷ����ӷ�����
	bool isServerConected();

	//���ӷ�����
	bool connectServer(const char* ip, unsigned short port);

	void sendData(WORD wMainCmdID,WORD wSubCmdID);

	void sendData(void* pData,WORD wDataSize,WORD wMainCmdID,WORD wSubCmdID,WORD wRountID);

	void sendData(WORD wMainCmdID,WORD wSubCmdID,void* pData,DWORD wDataSize);

	void recvData(GBEventArg& arg);

	DWORD SendDataBuffer(void * pBuffer, WORD wSendSize);

	WORD encryptBuffer(BYTE pcbDataBuffer[], WORD wDataSize, WORD wBufferSize);

	WORD crevasseBuffer(BYTE pcbDataBuffer[], WORD wDataSize);

	//���ӳ��
	WORD SeedRandMap(WORD wSeed);

	//ӳ�䷢������
	BYTE MapSendByte(BYTE const cbData);

	//ӳ���������
	BYTE MapRecvByte(BYTE const cbData);

	//����
	void reset();

	//�ر��׽���
	void closeSocket();

public:
	//void setDispatch(MsgDispatch* p) { m_pMsgDispatch = p; }
private:
	static IGC_SocketStream* m_pISocketStrem;

	//�����Զ��������ܣ�
	char	m_szIpaddr[20];
	short	m_nPort;

private:
	BYTE  m_cbSendRound;
	BYTE  m_cbRecvRound;
	DWORD m_dwSendXorKey;
	DWORD m_dwRecvXorKey;
	DWORD m_dwSendPacketCount;
	DWORD m_dwRecvPacketCount;
	
	short m_netstate;
};


#endif /* defined(__SDH__TcpNetwork__) */

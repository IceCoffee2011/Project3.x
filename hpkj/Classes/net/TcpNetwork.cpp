//
//  TcpNetwork.cpp
//
//  Created by zhouwei on 13-6-6.
//
//

#include "TcpNetwork.h"
#include "GlobalDef.h"
#include "IDataArchive.h"
#include "Define.h"
#include "GBEvent.h"
#include "GBEventIDs.h"
#include "CMD_LogonServer.h"
#include "GlobalDef.h"
#include "MsgDispatch.h"
#include "common.h"
#include "cocosUnits.h"
#include "ConfigMgr.h"
#include "packet.h"
#include "EntityMgr.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JniHelper.h"
#endif

IGC_SocketStream* ClientSock::m_pISocketStrem = NULL;
//��ʧ���Ӵ���
int ClientSock::loseConnectTimes = 0;
//�Ƿ�����������
bool ClientSock::isConnected = false;
bool ClientSock::isNeedConnet = false;

ClientSock::ClientSock()
{
    m_cbSendRound = 0;
	m_cbRecvRound = 0;
    m_dwSendXorKey = 0;
    m_dwRecvXorKey = 0;
    m_dwSendPacketCount =0;
    m_dwRecvPacketCount = 0;
	memset(m_szIpaddr, 0, sizeof(m_szIpaddr));
	m_nPort = 0;
	
	m_pISocketStrem = NULL;

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	m_netstate = getNetType();
#endif
}


ClientSock::~ClientSock()
{

}

void ClientSock::reset()
{
    m_cbSendRound=0;
	m_cbRecvRound=0;
	m_dwSendXorKey=0x12345678;
	m_dwRecvXorKey=0x12345678;
}

//�ж��Ƿ�������Ϸ������
bool ClientSock::isConectServer()
{
    if (m_pISocketStrem!=NULL)
    {
        return  true;
    }
    return false;
}

//���ӵ���������IP���˿�
bool ClientSock::connectGameServer(const char* ip, unsigned short port)
{
    GC_SocketConnector SocketConnector;
    m_pISocketStrem = SocketConnector.Connect(ip, port);
    if (!m_pISocketStrem)
    {		
        return false;
    }
	
	//save ip and port for reconnect
	memcpy(m_szIpaddr, ip, strlen(ip));
	m_nPort = port;
    reset();		
    return  true;
}

void ClientSock::update()
{    
    int nRetCode = 0;
    char szBuffer[4096] = {'\0'};
    int nSize = sizeof(szBuffer);
    while(true)
    {
		if (!m_pISocketStrem)
		{
			return;
		}

        timeval TimeoutValue    = {0, 0};
        
        nRetCode = m_pISocketStrem->CheckCanRecv(&TimeoutValue);
        if (nRetCode == -1)
        {
            break;
        }
        if (nRetCode == 0)
        {
            break;  // if no data arrive
        }

        nRetCode = m_pISocketStrem->Recv((char **)&szBuffer, &nSize);				
		   
        if (nRetCode < 1) //�ж��Ƿ���� ���绷�� �ı�
		{				
			//CCLOG("this is fuck drop line %d, %d",m_pISocketStrem->GetLastError(), m_pISocketStrem->IsAlive());
				
			NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_NETWORKSHUTDZPK); //dzpk-jhy
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
				//�жϵ�ǰ�ǲ���û��

#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				//�ж������Ƿ�����
				//int tempNetType = getNetType();
				//if(tempNetType != 0 && tempNetType == m_netstate)  //����û�иı�
				//{						
				//	return;//���������л�getNetType(); 
				//}

				//m_netstate = tempNetType;
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

				//�ж������Ƿ����� û�����������򷵻�


#endif								
				//�Ͽ�����
				//closeSocket();
				//isNeedConnet = true;
				//NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_NETWORKSHUT);

				break;		
        }        
        //printf("the message is:%s\n",szBuffer);
    
        tagBuffer tag;
        memset(tag.dateBuffer, 0, 81920);
        memcpy(tag.dateBuffer, szBuffer, 4096);
        tag.nDataSize = nSize;        

		GBEvent::instance()->fire(GBEVENT_NETWORK,tag);
    }
}

void ClientSock::sendValidate()
{
	BYTE cbBuffer[sizeof(TCP_Validate)];
	memset(cbBuffer, 0 , sizeof(TCP_Validate));
	TCP_Validate *validate = (TCP_Validate *)cbBuffer;
	Common_Compilation(validate->szValidateKey);	
	sendData(MDM_KN_COMMAND, SUB_KN_VALIDATE_SOCKET, (void*)validate, sizeof(TCP_Validate));
}

void ClientSock::sendData(WORD wMainCmdID,WORD wSubCmdID)
{
    //��������
	BYTE cbDataBuffer[SOCKET_BUFFER];
    memset(cbDataBuffer, 0, SOCKET_BUFFER);
    
	CMD_Head* pHead=(CMD_Head*)cbDataBuffer;
	pHead->CommandInfo.wMainCmdID=wMainCmdID;
	pHead->CommandInfo.wSubCmdID=wSubCmdID;
    
    //��������
	WORD wSendSize=sizeof(CMD_Head);
	if (!Common_MappedBuffer(cbDataBuffer, sizeof(CMD_Head)))
	{
		CCLOG("==================Common_MappedBuffer FAILED===============");
		return ;
	}

	//��������3��false��Ϊ����	
	if(loseConnectTimes > 100) loseConnectTimes = 100;

	if (m_pISocketStrem)
	{
		int ret = m_pISocketStrem->Send((char*)cbDataBuffer,wSendSize);
		if(ret == 1) {loseConnectTimes = 0; return;}
		loseConnectTimes ++;		
		if(loseConnectTimes == 2)
		{
			closeSocket();
			isNeedConnet = true; //��ʾ����
			NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_NETWORKSHUT);
		} else
		{
			reset();
			isNeedConnet = false; 
			return;
		} 
	}
	static bool isRun = false;
	if(isRun)
	{
		Director::getInstance()->getRunningScene()->scheduleOnce([=](float delta){	
		
			isRun = false;
		}, 3.0f,"Reconnect22");	
		return;
	}
	isRun = true;

	Director::getInstance()->getRunningScene()->scheduleOnce([=](float delta){	
		//���߻�������			
		if(isNeedConnet) NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_NETWORK_RECON_ING);

		if (!connectGameServer(m_szIpaddr, m_nPort))
		{
			closeSocket();
			isRun = false;
			return;
		}			
		//�Զ����ӳɹ�	
		if(isNeedConnet)
		{				
			NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_NETWORK_RECON);
		}
		isNeedConnet = false;
		isConnected = true;
		loseConnectTimes = 0;
		sendValidate();		
		//������֤
		isRun = false;
	}, 3.0f,"Reconnect2");	
	

}

void ClientSock::sendData(void* pData,WORD wDataSize,WORD wMainCmdID,WORD wSubCmdID,WORD wRountID)
{
    CMD_Head* pHead = new CMD_Head;
    pHead->CommandInfo.wMainCmdID = wMainCmdID;
    pHead->CommandInfo.wSubCmdID  = wSubCmdID;
    
    if (!pData || wDataSize <= 0)
    {
        memcpy(pHead + 1,pData,wDataSize);
    }
    m_pISocketStrem->Send((char*)pData,wDataSize);
}

void ClientSock::sendData(WORD wMainCmdID,WORD wSubCmdID,void* pData,DWORD wDataSize)
{
    if (wDataSize>SOCKET_PACKET) return;
    
	//��������
	BYTE cbDataBuffer[SOCKET_BUFFER];
	memset(cbDataBuffer, 0, SOCKET_BUFFER);

	CMD_Head* pHead=(CMD_Head *)cbDataBuffer;
	pHead->CommandInfo.wMainCmdID=wMainCmdID;
	pHead->CommandInfo.wSubCmdID=wSubCmdID;
	if (wDataSize>0)
	{
		assert(pData!=NULL);
		memcpy(pHead+1,pData,wDataSize);
	}

	//��������
	WORD wSendSize = sizeof(CMD_Head) + wDataSize;
	if (!Common_MappedBuffer(cbDataBuffer, sizeof(CMD_Head) + wDataSize))
	{
		CCLOG("==================Common_MappedBuffer FAILED===============");
		return ;
	}
	
	//WORD wSendSize=encryptBuffer(cbDataBuffer,sizeof(CMD_Head) + wDataSize,sizeof(cbDataBuffer));
    CCLOG("send %d_%d,send data size = %d",wMainCmdID,wSubCmdID,wSendSize);

	if (m_pISocketStrem)
	{
		int ret = m_pISocketStrem->Send((char*)cbDataBuffer,wSendSize);	
	} 	
}
void ClientSock::recvData(GBEventArg& arg)
{
    tagBuffer& tag = (tagBuffer&)arg;
}
//��������
WORD ClientSock::encryptBuffer(BYTE pcbDataBuffer[], WORD wDataSize, WORD wBufferSize)
{   
	//��������
	WORD wEncryptSize = wDataSize - sizeof(CMD_Command), wSnapCount = 0;
	if ((wEncryptSize % sizeof(DWORD)) != 0)
	{
		wSnapCount = sizeof(DWORD) - wEncryptSize % sizeof(DWORD);
		memset(pcbDataBuffer + sizeof(CMD_Info) + wEncryptSize, 0, wSnapCount);
	}
    
	//Ч�������ֽ�ӳ��
	BYTE cbCheckCode = 0;
	for (WORD i = sizeof(CMD_Info); i < wDataSize; i++)
	{
		cbCheckCode += pcbDataBuffer[i];
        
		pcbDataBuffer[i] = MapSendByte(pcbDataBuffer[i]);
        
	}
    
	//��д��Ϣͷ
	CMD_Head * pHead = (CMD_Head *)pcbDataBuffer;
	pHead->CmdInfo.cbCheckCode = ~cbCheckCode + 1;
	pHead->CmdInfo.wPacketSize = wDataSize;
	pHead->CmdInfo.cbVersion = SOCKET_VER;
    
    

	//������Կ
	DWORD dwXorKey = m_dwSendXorKey;
	if (m_dwSendPacketCount == 0)
	{        
        srand((unsigned)time(NULL));
		//���ɵ�һ���������
        dwXorKey = rand();
        
        dwXorKey = 1;
		//���ӳ������
		dwXorKey = SeedRandMap((WORD)dwXorKey);
		dwXorKey |= ((DWORD)SeedRandMap((WORD)(dwXorKey >> 16))) << 16;
		dwXorKey ^= g_dwPacketKey;
		m_dwSendXorKey = dwXorKey;
		m_dwRecvXorKey = dwXorKey;
	}
    
	//��������
	WORD*  pwSeed = (WORD *)(pcbDataBuffer + sizeof(CMD_Info));
	DWORD* pdwXor = (DWORD *)(pcbDataBuffer + sizeof(CMD_Info));
	WORD wEncrypCount = (wEncryptSize + wSnapCount) / sizeof(DWORD);
	for (WORD i = 0; i < wEncrypCount; i++)
	{
		*pdwXor++ ^= dwXorKey;
		dwXorKey = SeedRandMap(*pwSeed++);
		dwXorKey |= ((DWORD)SeedRandMap(*pwSeed++)) << 16;
		dwXorKey ^= g_dwPacketKey;
	}
    
	//������Կ
	if (m_dwSendPacketCount == 0)
	{
		memmove(pcbDataBuffer + sizeof(CMD_Head) + sizeof(DWORD), pcbDataBuffer + sizeof(CMD_Head), wDataSize);
		*((DWORD *)(pcbDataBuffer + sizeof(CMD_Head))) = m_dwSendXorKey;
		pHead->CmdInfo.wPacketSize += sizeof(DWORD);
		wDataSize += sizeof(DWORD);
	}
    
	//���ñ���
	m_dwSendPacketCount++;
	m_dwSendXorKey = dwXorKey;
    
    return wDataSize;
}

//��������
WORD ClientSock::crevasseBuffer(BYTE pcbDataBuffer[], WORD wDataSize)
{
    if (m_dwSendPacketCount <=0 || wDataSize < sizeof(CMD_Head))
    {
        CCLOG("data check error!",__FILE__, __LINE__);
        CCLOG("m_dwSendPacketCount = %d,wDataSize = %d",m_dwSendPacketCount, wDataSize);
        return 0;
    }
    
	if(((CMD_Head *)pcbDataBuffer)->CmdInfo.wPacketSize != wDataSize)
    {
        CCLOG("data size error!",__FILE__, __LINE__);
        return 0;
    }
        
	//��������
	WORD wSnapCount = 0;
	if ((wDataSize % sizeof(DWORD)) != 0)
	{
		wSnapCount = sizeof(DWORD) - wDataSize % sizeof(DWORD);
		memset(pcbDataBuffer + wDataSize, 0, wSnapCount);
	}
    
	//��������
	DWORD dwXorKey = m_dwRecvXorKey;
	DWORD * pdwXor = (DWORD *)(pcbDataBuffer + sizeof(CMD_Info));
	WORD  * pwSeed = (WORD *)(pcbDataBuffer + sizeof(CMD_Info));
	WORD wEncrypCount = (wDataSize + wSnapCount - sizeof(CMD_Info)) / 4;
	for (WORD i = 0; i < wEncrypCount; i++)
	{
		if ((i == (wEncrypCount - 1)) && (wSnapCount > 0))
		{
			BYTE * pcbKey = ((BYTE *) & m_dwRecvXorKey) + sizeof(DWORD) - wSnapCount;
			memcpy(pcbDataBuffer + wDataSize, pcbKey, wSnapCount);
		}
		dwXorKey = SeedRandMap(*pwSeed++);
		dwXorKey |= ((DWORD)SeedRandMap(*pwSeed++)) << 16;
		dwXorKey ^= g_dwPacketKey;
		*pdwXor++ ^= m_dwRecvXorKey;
		m_dwRecvXorKey = dwXorKey;
    }
    
	//Ч�������ֽ�ӳ��
	CMD_Head * pHead = (CMD_Head *)pcbDataBuffer;
	BYTE cbCheckCode = pHead->CmdInfo.cbCheckCode;
    
	for (int i = sizeof(CMD_Info); i < wDataSize; i++)
	{
		pcbDataBuffer[i] = MapRecvByte(pcbDataBuffer[i]);
		cbCheckCode += pcbDataBuffer[i];
    }
    
    if (cbCheckCode != 0 )
    {
        CCLOG("check code error",__FILE__, __LINE__);
        CCLOG("wDataSize = %d",wDataSize);
        return 0;
    }
    
    return wDataSize;
}

//���ӳ��
WORD ClientSock::SeedRandMap(WORD wSeed)
{
	DWORD dwHold = wSeed;
	return (WORD)((dwHold = dwHold * 241103L + 2533101L) >> 16);
}

//ӳ�䷢������
BYTE ClientSock::MapSendByte(BYTE const cbData)
{
	BYTE cbMap = g_SendByteMap[(BYTE)(cbData+m_cbSendRound)];
	m_cbSendRound += 3;
	return cbMap;
}

//ӳ���������
BYTE ClientSock::MapRecvByte(BYTE const cbData)
{
	BYTE cbMap = g_RecvByteMap[cbData] - m_cbRecvRound;
	m_cbRecvRound += 3;
	return cbMap;
}

//�ر��׽���
void ClientSock::closeSocket()
{
	if (m_pISocketStrem)
	{
		m_pISocketStrem->CloseSocket();
		m_pISocketStrem = NULL;
	}

    //�ָ�����
	m_cbSendRound=0;
	m_cbRecvRound=0;
	m_dwSendXorKey=0;
	m_dwRecvXorKey=0;
	m_dwSendPacketCount=0;
	m_dwRecvPacketCount=0;	
    CCLOG("close socket");
}
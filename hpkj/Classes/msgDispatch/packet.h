

#ifndef DEFINE_PACKET_H
#define DEFINE_PACKET_H
#pragma once
#include "Define.h"
#pragma pack(1)

//���綨��
//#define SOCKET_VER						0x66
#define SOCKET_VER						0x01
#define SOCKET_BUFFER					16384								//���绺��
#define SOCKET_PACKET					(SOCKET_BUFFER-sizeof(CMD_Head)-2*sizeof(DWORD))

//��������
#define DK_MAPPED			0x01						//ӳ������
#define DK_ENCRYPT			0x02						//��������
#define DK_COMPRESS			0x04						//ѹ������

//���ȶ���
#define SOCKET_TCP_BUFFER	16384									//���绺��
#define SOCKET_TCP_PACKET	(SOCKET_TCP_BUFFER-sizeof(TCP_Head))	//���绺��

#define IPC_VER							0x0001
#define IPC_IDENTIFIER					0x0001
#define IPC_PACKAGE						4096
#define IPC_BUFFER						(sizeof(IPC_Head)+IPC_PACKAGE)

#define MDM_GR_MATCH				7									//��������

#define SUB_GR_MATCH_FEE			400									//��������
#define SUB_GR_MATCH_NUM			401									//�ȴ�����
#define SUB_GR_LEAVE_MATCH			402									//�˳�����
#define SUB_GR_MATCH_INFO			403									//������Ϣ
#define SUB_GR_MATCH_WAIT_TIP		404									//�ȴ���ʾ
#define SUB_GR_MATCH_RESULT			405									//�������
#define SUB_GR_MATCH_STATUS			406									//����״̬
#define SUB_GR_MATCH_DESC			408									//��������
#define SUB_GR_MATCH_REBUY			409									//��������
#define SUB_GR_MATCH_TIME			410									//����ʱ��

#define SUB_CM_SYSTEM_MESSAGE		1									//ϵͳ��Ϣ
#define SUB_CM_ACTION_MESSAGE		2									//������Ϣ
#define SUB_CM_DOWN_LOAD_MODULE		3									//������Ϣ

//����״̬
#define MS_NULL						0x00								//û��״̬
#define MS_SIGNUP					0x01								//����״̬
#define MS_MATCHING					0x02								//����״̬
#define MS_OUT						0x03								//��̭״̬

//////////////////////////////////////////////////////////////////////////////////
//������Ϣ

#define IPC_CMD_GF_SOCKET			1									//������Ϣ

#define IPC_SUB_GF_SOCKET_SEND		1									//���緢��
#define IPC_SUB_GF_SOCKET_RECV		2									//�������

#pragma mark �ں�����
#define MDM_KN_COMMAND			0						//�ں�����
#define SUB_KN_DETECT_SOCKET	1						//�������
#define SUB_KN_VALIDATE_SOCKET	2						//��֤����
///////////////////////////////////////////////////////////////////////////
//�ṹ����
//������֤
typedef struct
{
	TCHART				szValidateKey[64];							//��֤�ַ�
}TCP_Validate;

//��������
struct CMD_GR_Match_Num
{
	DWORD							dwWaitting;							//�ȴ�����
	DWORD							dwTotal;							//��������
	DWORD							dwMax;								//�������
};

//ϵͳ��Ϣ
struct CMD_CM_SystemMessageDZPK
{
	WORD							wType;								//��Ϣ����
	WORD							wLength;							//��Ϣ����
	TCHART							szString[1024];						//��Ϣ����
};
//������Ϣ
struct CMD_CM_ActionMessage
{
	WORD							wType;								//��Ϣ����
	WORD							wLength;							//��Ϣ����
	DWORD							nButtonType;						//��ť����
	TCHART							szString[1024];						//��Ϣ����
};

struct CMD_GR_MatchTime
{
	WORD							wNowHour;						//������Сʱ
	WORD							wNowMinute;						//����������
	WORD							wNowSeconds;					//��������
	WORD							wStartHour;						//����ʱ��-Сʱ
	WORD							wStartMinute;					//����ʱ��-����
};

#define MAX_MATCH_DESC				4									//�������

//��������
struct CMD_GR_MatchDesc
{
	TCHART							szTitle[MAX_MATCH_DESC][16];		//��Ϣ����
	TCHART							szDescribe[MAX_MATCH_DESC][64];		//��������
	DWORD						crTitleColor;						//������ɫ
	DWORD						crDescribeColor;					//������ɫ
};

/////////////////////////////////////////////////////////////////////////////////////////
//�ں�����
#define MDM_KN_COMMAND				0									//�ں�����
#define SUB_KN_DETECT_SOCKET		1									//�������
#define SUB_KN_SHUT_DOWN_SOCKET			2								

//��½״̬
enum enLoginState
{
    enLogin_Server,                     //��½������
    enGame_Server,                      //��Ϸ������
};

//�����ں�
struct CMD_Info
{
	BYTE								cbVersion;							
	BYTE								cbCheckCode;						//Ч���ֶ�
	WORD								wPacketSize;						//���ݴ�С
};

//�����ں�
struct TCP_Info
{
	BYTE							cbDataKind;							//��������
	BYTE							cbCheckCode;						//Ч���ֶ�
	WORD							wPacketSize;						//���ݴ�С
};

//��������
struct CMD_Command
{
	WORD								wMainCmdID;							//��������
	WORD								wSubCmdID;							//��������
};

//��������
struct TCP_Command
{
	WORD							wMainCmdID;							//��������
	WORD							wSubCmdID;							//��������
};

//�����ͷ
struct CMD_Head
{
	CMD_Info							CmdInfo;							//�����ṹ
	CMD_Command							CommandInfo;						//������Ϣ
};

//�����ͷ
struct TCP_Head
{
	TCP_Info						TCPInfo;							//�����ṹ
	TCP_Command						CommandInfo;						//������Ϣ
};

//���绺��
struct CMD_Buffer
{
	CMD_Head							Head;								//���ݰ�ͷ
	BYTE								cbBuffer[SOCKET_PACKET];			//���ݻ���
};

struct CMD_KN_DetectSocket
{
	DWORD								dwSendTickCount;
	DWORD								dwRecvTickCount;
};

//�������
struct IPC_GF_SocketRecv
{
	TCP_Command						CommandInfo;						//������Ϣ
	BYTE							cbBuffer[SOCKET_TCP_PACKET];		//���ݻ���
};

struct IPC_Head
{
	WORD								wVersion;
	WORD								wDataSize;
	WORD								wMainCmdID;
	WORD								wSubCmdID;
};

struct IPC_Buffer
{
	IPC_Head							Head;								
	BYTE								cbBuffer[IPC_PACKAGE];
};

/////////////////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif

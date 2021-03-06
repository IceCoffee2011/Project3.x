﻿#ifndef GLOBAL_DEF_HEAD_FILE
#define GLOBAL_DEF_HEAD_FILE
#pragma once
#include "GBEvent.h"
#include "packet.h"
#include "struct.h"
#include "cocos2d.h"

//////////////////////////////////////////////////////////////////////////
#ifdef VER_369
typedef DWORD TPacketKey;
typedef TCHART TMapElem;
#else
typedef WORD TPacketKey;
typedef BYTE TMapElem;
#endif

//加密密钥
const TPacketKey g_dwPacketKey=0xA55AA55A;

//发送映射
const TMapElem g_SendByteMap[256]=
{
	0x70,0x2F,0x40,0x5F,0x44,0x8E,0x6E,0x45,0x7E,0xAB,0x2C,0x1F,0xB4,0xAC,0x9D,0x91,
	0x0D,0x36,0x9B,0x0B,0xD4,0xC4,0x39,0x74,0xBF,0x23,0x16,0x14,0x06,0xEB,0x04,0x3E,
	0x12,0x5C,0x8B,0xBC,0x61,0x63,0xF6,0xA5,0xE1,0x65,0xD8,0xF5,0x5A,0x07,0xF0,0x13,
	0xF2,0x20,0x6B,0x4A,0x24,0x59,0x89,0x64,0xD7,0x42,0x6A,0x5E,0x3D,0x0A,0x77,0xE0,
	0x80,0x27,0xB8,0xC5,0x8C,0x0E,0xFA,0x8A,0xD5,0x29,0x56,0x57,0x6C,0x53,0x67,0x41,
	0xE8,0x00,0x1A,0xCE,0x86,0x83,0xB0,0x22,0x28,0x4D,0x3F,0x26,0x46,0x4F,0x6F,0x2B,
	0x72,0x3A,0xF1,0x8D,0x97,0x95,0x49,0x84,0xE5,0xE3,0x79,0x8F,0x51,0x10,0xA8,0x82,
	0xC6,0xDD,0xFF,0xFC,0xE4,0xCF,0xB3,0x09,0x5D,0xEA,0x9C,0x34,0xF9,0x17,0x9F,0xDA,
	0x87,0xF8,0x15,0x05,0x3C,0xD3,0xA4,0x85,0x2E,0xFB,0xEE,0x47,0x3B,0xEF,0x37,0x7F,
	0x93,0xAF,0x69,0x0C,0x71,0x31,0xDE,0x21,0x75,0xA0,0xAA,0xBA,0x7C,0x38,0x02,0xB7,
	0x81,0x01,0xFD,0xE7,0x1D,0xCC,0xCD,0xBD,0x1B,0x7A,0x2A,0xAD,0x66,0xBE,0x55,0x33,
	0x03,0xDB,0x88,0xB2,0x1E,0x4E,0xB9,0xE6,0xC2,0xF7,0xCB,0x7D,0xC9,0x62,0xC3,0xA6,
	0xDC,0xA7,0x50,0xB5,0x4B,0x94,0xC0,0x92,0x4C,0x11,0x5B,0x78,0xD9,0xB1,0xED,0x19,
	0xE9,0xA1,0x1C,0xB6,0x32,0x99,0xA3,0x76,0x9E,0x7B,0x6D,0x9A,0x30,0xD6,0xA9,0x25,
	0xC7,0xAE,0x96,0x35,0xD0,0xBB,0xD2,0xC8,0xA2,0x08,0xF3,0xD1,0x73,0xF4,0x48,0x2D,
	0x90,0xCA,0xE2,0x58,0xC1,0x18,0x52,0xFE,0xDF,0x68,0x98,0x54,0xEC,0x60,0x43,0x0F
};

//接收映射
const TMapElem g_RecvByteMap[256]=
{
	0x51,0xA1,0x9E,0xB0,0x1E,0x83,0x1C,0x2D,0xE9,0x77,0x3D,0x13,0x93,0x10,0x45,0xFF,
	0x6D,0xC9,0x20,0x2F,0x1B,0x82,0x1A,0x7D,0xF5,0xCF,0x52,0xA8,0xD2,0xA4,0xB4,0x0B,
	0x31,0x97,0x57,0x19,0x34,0xDF,0x5B,0x41,0x58,0x49,0xAA,0x5F,0x0A,0xEF,0x88,0x01,
	0xDC,0x95,0xD4,0xAF,0x7B,0xE3,0x11,0x8E,0x9D,0x16,0x61,0x8C,0x84,0x3C,0x1F,0x5A,
	0x02,0x4F,0x39,0xFE,0x04,0x07,0x5C,0x8B,0xEE,0x66,0x33,0xC4,0xC8,0x59,0xB5,0x5D,
	0xC2,0x6C,0xF6,0x4D,0xFB,0xAE,0x4A,0x4B,0xF3,0x35,0x2C,0xCA,0x21,0x78,0x3B,0x03,
	0xFD,0x24,0xBD,0x25,0x37,0x29,0xAC,0x4E,0xF9,0x92,0x3A,0x32,0x4C,0xDA,0x06,0x5E,
	0x00,0x94,0x60,0xEC,0x17,0x98,0xD7,0x3E,0xCB,0x6A,0xA9,0xD9,0x9C,0xBB,0x08,0x8F,
	0x40,0xA0,0x6F,0x55,0x67,0x87,0x54,0x80,0xB2,0x36,0x47,0x22,0x44,0x63,0x05,0x6B,
	0xF0,0x0F,0xC7,0x90,0xC5,0x65,0xE2,0x64,0xFA,0xD5,0xDB,0x12,0x7A,0x0E,0xD8,0x7E,
	0x99,0xD1,0xE8,0xD6,0x86,0x27,0xBF,0xC1,0x6E,0xDE,0x9A,0x09,0x0D,0xAB,0xE1,0x91,
	0x56,0xCD,0xB3,0x76,0x0C,0xC3,0xD3,0x9F,0x42,0xB6,0x9B,0xE5,0x23,0xA7,0xAD,0x18,
	0xC6,0xF4,0xB8,0xBE,0x15,0x43,0x70,0xE0,0xE7,0xBC,0xF1,0xBA,0xA5,0xA6,0x53,0x75,
	0xE4,0xEB,0xE6,0x85,0x14,0x48,0xDD,0x38,0x2A,0xCC,0x7F,0xB1,0xC0,0x71,0x96,0xF8,
	0x3F,0x28,0xF2,0x69,0x74,0x68,0xB7,0xA3,0x50,0xD0,0x79,0x1D,0xFC,0xCE,0x8A,0x8D,
	0x2E,0x62,0x30,0xEA,0xED,0x2B,0x26,0xB9,0x81,0x7C,0x46,0x89,0x73,0xA2,0xF7,0x72
};

//////////////////////////////////////////////////////////////////////////
struct tagBuffer : public GBEventArg
{
    BYTE dateBuffer[81920];
    unsigned int nDataSize;
    tagBuffer()
    {
        memset(dateBuffer, '\0', 0);
        nDataSize = 0;
    }
};

struct tagCmdBuffer : public GBEventArg
{
    CMD_Command command;
	//WORD wMainCmdID;						//主命令码
	//WORD wSubCmdID;							//子命令码
    BYTE dateBuffer[40960];
    unsigned int nDataSize;
};

struct tagUserBuffer : public cocos2d::Object
{
    unsigned int dwUserID;
};

struct tagGameBuffer : public cocos2d::Object
{
    WORD wSubCmdID;
    BYTE dateBuffer[4096];
    unsigned int nDataSize;
};

struct tagSceneBuffer : public cocos2d::Object
{
    unsigned char cbState;
    unsigned int nDataSize;
    BYTE dateBuffer[4096];
};


struct tagBuffer1 : public GBEventArg
{
    BYTE dateBuffer[4096];
    unsigned int nDataSize;
};

//注册buffer
struct tagRegBuffer : public cocos2d::Object
{
	LONG            lErrorCode;
	unsigned char	szErrorDescribe[128];	
};

//系统buffer
struct tagSystemBuffer : public GBEventArg
{
	WORD			wMessageType;					//消息类型
	WORD			wMessageLength;					//消息长度
	char			szContent[1024];				//消息内容
};

//找回密码
struct tagGetPassObj : public cocos2d::Object
{
    long 			lErrCode;                       //消息标志 0成功
	char			szPassword[33];                 //密码
	unsigned char	szErrorDescribe[128];           //描述信息
};

//赠送金币
struct tagScoreGifObj : public cocos2d::Object
{
    long 			lErrCode;                       //消息标志 0成功
	long			lScore;                         //赠送金币
	unsigned char	szErrorDescribe[128];           //描述信息
};

//领取金币 话费点
struct tagChargeObj  : public cocos2d::Object
{
	long			lErrCode;
	long			lScore;
	long			lGoldeggs;
    unsigned char	szErrorDescribe[128];
};

//房间登录失败
struct tagRoomLogonFailObj  : public cocos2d::Object
{
	int							lErrorCode;					// 错误代码
	TCHART						szDescribeString[128];		// 错误描述
};

//请求失败
struct tagRequestFailureObj  : public cocos2d::Object
{
	BYTE							cbFailureCode;						//错误代码
	BYTE                            cbCommandCode;                      //命令代码
	TCHART							szDescribeString[256];				// 描述信息
};

//破产 降级
struct tagBankruptObj  : public cocos2d::Object
{
    bool bBankrupt;    //true 破产,flase 领取金币
};

//获取用户列表
struct tagUserListObj  : public cocos2d::Object
{
    long				lErrCode;
    unsigned char		szUserNameList[270];				//用户名列表，最多２０个
};

//获取用户
struct tagUserObj  : public cocos2d::Object
{
    unsigned char       szUserName[32];                  //用户名
};

//配置信息
struct tagConfigObj  : public cocos2d::Object
{
    char		szGame[128];                                //游戏公告
	unsigned int        nHighVerID;							//高版本
	unsigned int        nLowVerID;						    //低版本
	bool                bForcedUpdate;                     //是否强制更新
};

//表情消息
struct tagExpressObj  : public cocos2d::Object
{
    unsigned int        type;       //1表情 2语音
    unsigned int        nId;        //id
};

//更新消息
struct tagUpdateObj  : public cocos2d::Object
{
    bool bUpdate;     //更新消息
};

struct tagInviteInfo : public cocos2d::Object
{
    WORD wTableID;
    unsigned char       szUserName[32];//用户名
};

struct SDownloadGamePrize_Return
{
	LONG lReturn;
	DWORD dwDownloadGameInfo;
	DWORD dwCurScore;
	BYTE nIndex;
	BYTE nSubCmd;
	SDownloadGamePrize_Return()
	{
		memset(this, 0, sizeof(*this));
	}
};

struct SDownloadGamePrize_Returnn : public Object
{
	LONG lReturn;
	DWORD dwDownloadGameInfo;
	DWORD dwCurScore;
	BYTE nIndex;
	BYTE nSubCmd;
	SDownloadGamePrize_Returnn()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif











#ifndef JNI_HELPER_H
#define JNI_HELPER_H

#include "cocos2d.h"
#include "EntityMgr.h"
#include "AnsString.h"
#include "Define.h"
#include "../proj.android/jni/hellocpp/Jni_system.h"
#include "GlobalUnits.h"
#include "TaskInfo.h"
#include "ConfigMgr.h"

using namespace cocos2d;


inline void IMEI(const char* address)
{
	CCLOG("AAAAAAAAAAAmacaddress = %s",address);
	EntityMgr::instance()->setMacAddress(String::createWithFormat("%s%s","M",address)->getCString());
	CCLOG("cccccccccccccccccccccccc%s",address);
}

inline void reConnect()
{
	pMsgDispatch->SendReConnect();	
}

inline void downloadGame(const char* gameID)
{
	downloadAndriodGame(gameID);
}

inline void RechargeableCard(const char* type, const char* dwCardFee, const char* cardnum, const char* cardpassword)
{
	CCLOG("type:%s,dwCardFee:%s,cardnum:%s,cardpassword:%s,",type,dwCardFee,cardnum,cardpassword);
	if(pMsgDispatch->connectLoginServer())
	{
		pMsgDispatch->phoneCardRechange(type,dwCardFee,cardnum,cardpassword);
	}
}

inline void PurpleGoldIslandCard(const char* cardnum, const char* cardpassword)
{
	CCLOG("cardnum:%s,cardpassword:%s,",cardnum,cardpassword);
	if(pMsgDispatch->connectLoginServer())
	{
		pMsgDispatch->isLnadCardRecarge(cardnum,cardpassword);
	}
}

inline void getOrder(const char* payName,const char* chargeNum)
{
	if (pMsgDispatch->getLoginState() == enLogin_Server)
	{
		if(!pMsgDispatch->connectLoginServer())
		{
			networkAnomaly();
			return;
		}
	}
	
	pMsgDispatch->sendOrderInfo(payName,ans::AnsString::string2Int(chargeNum));
	CCLOG("payName = %s,string2Int(chargeNum) = %d",payName,ans::AnsString::string2Int(chargeNum));
	CCLOG("payName = %s,atoi(chargeNum) = %d",payName,atoi(chargeNum));
	
}

inline void orderOver(const char* coinsNum/*,const char* goldEggNum*/)
{
	g_GlobalUnits.getGolbalUserData()->lScore = ans::AnsString::string2Int(coinsNum);
	CCLOG("coinsNum in jnihelper  = %d",ans::AnsString::string2Int(coinsNum));
	//g_GlobalUnits.getGolbalUserData()->lGoldEggs = (int)goldEggNum;
	NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_UPDATESCOREANDGOLDEGG,NULL);
}

inline void cannelRechanger()
{
	NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_CANNELRECHANGER,NULL);
}

inline void getChannl(const char* str)
{
	CCLOG("*****************************channelstr = %s",str);
	
	pConfigMgr->m_Config.m_channelStr = str;
}

inline void getVersion(const char* str)
{
	CCLOG("11111111111111111111version = %s",str);
	//�ֽ�汾 �õ��汾��

	int versionFix[3];
	versionFix[0] = 0;
	versionFix[1] = 0;
	versionFix[2] = 0;
	/* У��x_sVer */
	bool ret = true;
	if(str==NULL || strlen(str)<5)
	{
		ret = false;
		CCLOG("version error size");
	}

	size_t iLen = strlen(str);
	int iCot = 0;

	for(size_t i=0; i<iLen; i++)
	{
		if(str[i]==0x2E)
		{
			iCot++;
		}
		else if(str[i]<0x30 || str[i]>0x39)
		{
			ret = false;
			CCLOG("have error char");
		}
	}

	if(iCot!=2)
	{
		ret = false;
		CCLOG("less point");
	}

	/* ��ȡ */
	if(ret)
	{
		sscanf(str, "%d.%d.%d", versionFix+0, versionFix+1, versionFix+2);
	}
	pConfigMgr->m_VersionInfo.m_nHighVersion = versionFix[0];
	pConfigMgr->m_VersionInfo.m_nMiddleVersion = versionFix[1];
	pConfigMgr->m_VersionInfo.m_nLowVersion = versionFix[2];
}

inline void downloadPesent(const char* pesent,const char* gameID)
{
	int _pesent = atoi(pesent);
	int _gameID = atoi(gameID);
	CCLOG("downloadgame gameID = %d,pesent = %d",_gameID,_pesent);

	if (EntityMgr::instance()->m_nDownLoadPe == _pesent)
	{
		return;
	}
	if(_pesent%2==0)
	{
		Integer* inter = Integer::create(_pesent);
		//EntityMgr::instance()->m_nDownLoadPe = _pesent;

		switch (_gameID)
		{
		case GameId_DDZ:
			{
				break;
			}
		case GameId_PHZ:
			{
				NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_RUNBREAD,inter);
				if (_pesent >= 100)
				{
					//pMsgDispatch->connectLoginServer();
					//pMsgDispatch->getDownLoadAward(SeverID_PHZ,1);
					EntityMgr::instance()->m_nDownLoadPe = 1;
				}
				break;
			}
		case GameId_CSMJ:
			{
				NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_CHANGSHAMAJIADOWNLOAD,inter);
				if (_pesent >= 100)
				{
					//pMsgDispatch->connectLoginServer();
					//pMsgDispatch->getDownLoadAward(SeverID_CSMJ,1);
					EntityMgr::instance()->m_nDownLoadPe = 1;
				}
				break;
			}
		case GameId_ZJH:
			{
				break;
			}
		case GameId_SDK:
			{
				NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_THREETOONE,inter);
				if (_pesent >= 100)
				{
					//pMsgDispatch->connectLoginServer();
					//pMsgDispatch->getDownLoadAward(SeverID_SDH,1);
					EntityMgr::instance()->m_nDownLoadPe = 1;
				}
				break;
			}
		case GameId_PDK:
			{
				NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_RUNFASTDOWNLOAD,inter);
				if (_pesent >= 100)
				{
					//pMsgDispatch->connectLoginServer();
					//pMsgDispatch->getDownLoadAward(SeverID_PDK,1);
					EntityMgr::instance()->m_nDownLoadPe = 1;
				}
				break;
			}

		default:
			{
				assert(false);
				return;
			}
		}
	}
}

inline int isGameExit(int gameID)
{
	CCLOG("GAMEID = %d,exist = %d",gameID,getGameExist(gameID));
	return getGameExist(gameID);
}

inline void openAndriodGame(const char* gameID)
{
	openGame(gameID);
}

inline void outInout(const char* str)
{
	CCLOG("%s  is null ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`",str);
}

inline void cannelGameDownload()
{
	CCLOG("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
	EntityMgr::instance()->m_nDownLoadPe = 1;
	NotificationCenter::getInstance()->postNotification(MSG_UI_ANS_CANNELDOWNLOADGAME,NULL);
	CCLOG("cccccccccccccccccccccccccccccccccccccccccccccc");
}

inline void newUMMessage()
{
	TaskInfo* info = TaskInfo::ShareTaskInfo();
	info->m_nUMMessage++;
}

#endif //JNI_HELPER_H

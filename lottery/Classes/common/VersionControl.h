#ifndef VERSION_DEFINE_FILE
#define VERSION_DEFINE_FILE
#pragma once

#include "cocos2d.h"
#include <string>
using namespace std;
using namespace cocos2d;

//app�汾 a ver_9yi | b ver_qianbo | c ver_369
//#define VER_9YI
//#define VER_QIANBO
#define VER_369

//��Ϸ���
#define USE_ZJH
#define USE_DZPK
#define USE_DDZ
#define USE_BJL
#define USE_FISHBEAT
#define USE_PPC		//	������
#define USE_BRNN	//	����ţţ
#define USE_SGLY	//	ˮ����԰

//��Դ�ȸ���
//#define USE_HOT_UPDATE
//֧��ѡ����
#define USE_ROOM_LIST

//�汾����
#ifdef VER_QIANBO

#define BALL_RADDIUS 84
#define HEAD_IMG "beark2.png"
#define HE_IMG "gamble_00.png"

#endif

#ifdef VER_369

#define BALL_RADDIUS 84
#define HEAD_IMG "beark2.png"
#define HE_IMG "gamble_00.png"

#endif

#ifdef VER_9YI

#define BALL_RADDIUS 78
#define HEAD_IMG "room_01.png"
#define HE_IMG "gamble_00.png"

#endif

#endif //VERSION_DEFINE_FILE
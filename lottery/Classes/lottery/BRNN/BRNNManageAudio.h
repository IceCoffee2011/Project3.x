#ifndef __BRNN_MANAGE_AUDIO_H__
#define __BRNN_MANAGE_AUDIO_H__

#include "cocos2d.h"
#include "BRNNDefine.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

/*
**	@brief	����ţţ������Ƶ����
*/
class BRNNManageAudio
{
public:
	BRNNManageAudio();
	~BRNNManageAudio();

	//	����
	static BRNNManageAudio* getInstance();

	//	Ԥ������Ƶ�ļ�
	void preLoadAudio();

	//	�������
	void clear();

	//	���ű�������
	void playBGMusic(bool bLoop = false);

	//	ֹͣ���ű�������
	void stopBGMusic();

	//	������Ч
	void playSoundEffect(E_BRNNAudio eSound, bool bLoop = false);

	//	ֹͣ����������Ч
	void stopAllSoundEffect();

	//	���ñ�����������
	void setBGMusicVolume(float fVolume);

	//	������Ч����
	void setSoundEffectVolume(float fVolume);

	//	�����Ƿ�򿪱�������
	CC_SYNTHESIZE(bool, m_bOnBGMusic, OnBGMusic);

	//	�����Ƿ����Ч
	CC_SYNTHESIZE(bool, m_bOnSoundEffect,OnSoundEffect);

private:
	bool init();

	//	��Ƶ�ļ���
	char* m_sAudioFile[E_BRNNAudio_Null];
};


#endif  // __BRNN_MANAGE_AUDIO_H__
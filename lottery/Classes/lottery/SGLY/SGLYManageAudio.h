#ifndef __SGLY_MANAGE_AUDIO_H__
#define __SGLY_MANAGE_AUDIO_H__

#include "cocos2d.h"
#include "SGLYDefine.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

/*
**	@brief	ˮ����԰������Ƶ����
*/
class SGLYManageAudio
{
public:
	SGLYManageAudio();
	~SGLYManageAudio();

	//	����
	static SGLYManageAudio* getInstance();

	//	Ԥ������Ƶ�ļ�
	void preLoadAudio();

	//	�������
	void clear();

	//	���ű�������
	void playBGMusic(bool bLoop = false);

	//	ֹͣ���ű�������
	void stopBGMusic();

	//	������Ч
	void playSoundEffect(E_SGLY_Audio eSound, bool bLoop = false);

	//	ֹͣ����������Ч
	void stopAllSoundEffect();

	//	���ñ�����������
	void setBGMusicVolume(float fVolume);

	//	������Ч����
	void setSoundEffectVolume(float fVolume);

	//	�����Ƿ�����������
	void setOnBGMusic(bool bIsOn);

	//	��õ�ǰ�Ƿ�����������
	bool getOnBGMusic() const;

	//	�����Ƿ�����Ч
	void setOnSoundEffect(bool bIsOn);

	//	��õ�ǰ�Ƿ�����Ч
	bool getOnSoundEffect() const;

private:
	bool init();

	//	�Ƿ�����������
	bool m_bOnBGMusic;

	//	�Ƿ�����Ч
	bool m_bOnSoundEffect;

	//	��Ƶ�ļ���
	string m_sAudioFile[E_SGLY_Audio_Null];
};


#endif  // __SGLY_MANAGE_AUDIO_H__
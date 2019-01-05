#include "Sound.h"
#include "cocos2d.h"


USING_NS_CC;
using namespace CocosDenshion;

Sound * Sound::m_sound = NULL;
Sound * Sound::getInstance()
{
	if(m_sound == NULL)
	{
		m_sound = new Sound();
	}
	return m_sound;
}
void Sound::freeInstance()
{
	if(m_sound != NULL)
	{
		delete m_sound;
		m_sound = NULL;
	}
}

Sound::Sound()
{

	////Ԥ�ȼ��������������������ļ�
	//auto audio = SimpleAudioEngine::getInstance();
	////Ԥ�ȼ������ֵĺ�����win32���ǿյ�ʵ�� ���ŵ�Ч�����ͺ�� ��android��û������
	//audio->preloadBackgroundMusic(getMusic(MUSIC_TYPE_BACKGROUND1));
	//audio->preloadBackgroundMusic(getMusic(MUSIC_TYPE_BACKGROUND2));
	//audio->preloadBackgroundMusic(getMusic(MUSIC_LANDTYPE_BACKGROUND));
	////������Ч ��win32�¼�����Чû��ʲôЧ�������ų������ͺ�ģ�������android��û���ͺ������
	//for (int i = EFFECT_TYPE_BINGO; i < EFFECT_TYPE_Unknow; ++ i)
	//{
	//	audio->preloadEffect(getEffect((EFFECT_TYPE)(i)));
	//}
	//
	//for (int i = EFFECT_LANDTYPE_BEGIN; i < EFFECT_LANDTYPE_Unknow; i++)
	//{
	//	audio->preloadEffect(getEffect((EFFECT_LANDTYPE)(i)));
	//}
	//// ���������Ĵ�С0.0-1.0 ��win32��Ҳ�ǿյ�ʵ��
	//float fVolume = UserDefault::getInstance()->getFloatForKey("BgMusicVol", 0.9f);
	//audio->setBackgroundMusicVolume(fVolume);
	//fVolume = UserDefault::getInstance()->getFloatForKey("EffectsVol", 0.9f);
	//audio->setEffectsVolume(fVolume);
}

//��ȡ��Ч�����ֵ��ļ�
const char * Sound::getMusic(MUSIC_TYPE type)
{
	switch(type)
	{
	case MUSIC_TYPE_SceneBg:
		return "sounds/SceneBg.mp3";
		break;
	case MUSIC_TYPE_BACKGROUND1:
		return "sounds/bgm/bgm1.mp3";
		break;
	case MUSIC_TYPE_BACKGROUND2:
		return "sounds/bgm/bgm2.mp3";
		break;
		case MUSIC_TYPE_BACKGROUND3:
			return "sounds/bgm/bgm3.mp3";
			break;
		case MUSIC_TYPE_BACKGROUND4:
			return "sounds/bgm/bgm4.mp3";
			break;
	default:
		break;
	}
	return NULL;
}

void Sound::playBgMusic(MUSIC_TYPE type)
{
 	bool bMusic = getMusicStatue();
	if(bMusic)
	{
		auto audio = SimpleAudioEngine::getInstance();
		if(!audio->isBackgroundMusicPlaying())
		{
			audio->playBackgroundMusic(this->getMusic(type),true);
		}
		else
		{
			audio->resumeBackgroundMusic();
		}
	}
}

const char * Sound::getEffect(EFFECT_FOUR_FISH_TYPE type)
{
	switch (type)
	{
	case EFFECT_TYPE_BINGO: return "sounds/effect/bingo.mp3";
	case EFFECT_TYPE_CANNON_SWITCH: return "sounds/effect/changecannon.mp3";
	case EFFECT_TYPE_SILVER: return "sounds/effect/silver.mp3";
	case EFFECT_TYPE_CATCH: return "sounds/effect/catch.mp3";
	case EFFECT_TYPE_FIRE: return "sounds/effect/fire.mp3";
	case EFFECT_TYPE_FISH10_1: return "sounds/effect/fish10_1.mp3";
	case EFFECT_TYPE_FISH10_2: return "sounds/effect/fish10_2.mp3";
	case EFFECT_TYPE_FISH11_1: return "sounds/effect/fish11_1.mp3";
	case EFFECT_TYPE_FISH11_2: return "sounds/effect/fish11_2.mp3";
	case EFFECT_TYPE_FISH12_1: return "sounds/effect/fish12_1.mp3";
	case EFFECT_TYPE_FISH12_2: return "sounds/effect/fish12_2.mp3";
	case EFFECT_TYPE_FISH13_1: return "sounds/effect/fish13_1.mp3";
	case EFFECT_TYPE_FISH13_2: return "sounds/effect/fish13_2.mp3";
	case EFFECT_TYPE_FISH14_1: return "sounds/effect/fish14_1.mp3";
	case EFFECT_TYPE_FISH14_2: return "sounds/effect/fish14_2.mp3";
	case EFFECT_TYPE_FISH15_1: return "sounds/effect/fish15_1.mp3";
	case EFFECT_TYPE_FISH15_2: return "sounds/effect/fish15_2.mp3";
	case EFFECT_TYPE_FISH16_1: return "sounds/effect/fish16_1.mp3";
	case EFFECT_TYPE_FISH16_2: return "sounds/effect/fish16_2.mp3";
	case EFFECT_TYPE_FISH17_1: return "sounds/effect/fish17_1.mp3";
	case EFFECT_TYPE_FISH17_2: return "sounds/effect/fish17_2.mp3";
	case EFFECT_TYPE_GOLD: return "sounds/effect/gold.mp3";
	case EFFECT_TYPE_INSERT: return "sounds/effect/insert.mp3";
	case EFFECT_TYPE_ION_CATCH: return "sounds/effect/ion_catch.mp3";
	case EFFECT_TYPE_ION_FIRE: return "sounds/effect/ion_fire.mp3";
	case EFFECT_TYPE_LOCK: return "sounds/effect/lock.mp3";
	case EFFECT_TYPE_WAVE: return "sounds/effect/wave.mp3";
	case EFFECT_TYPE_coinsky: return "sounds/effect/coinsHuahua.mp3";
	case EFFECT_TYPE_Unknow:
		break;
	default:
		break;
	}
	return nullptr;
}

void Sound::playEffect(EFFECT_FOUR_FISH_TYPE type)
{
	bool bEffect = getEffectStatue();
	if(bEffect)
	{
		auto audio = SimpleAudioEngine::getInstance();
		audio->playEffect(this->getEffect(type));
	}
}


void Sound::setBgMusicVolume(float volume) //���ñ�����������
{
	UserDefault::getInstance()->setFloatForKey("BgMusicVol", volume);
	auto audio = SimpleAudioEngine::getInstance();
	audio->setBackgroundMusicVolume(volume);
}

float Sound::getBgMusicVolume()             //��ȡ������������
{
	float fVolume = UserDefault::getInstance()->getFloatForKey("BgMusicVol", 0.9f);
	return fVolume;
}

void Sound::setEffectsVolume(float volume) //������Ч����
{
	UserDefault::getInstance()->setFloatForKey("EffectsVol", volume);
	auto audio = SimpleAudioEngine::getInstance();
	audio->setEffectsVolume(volume);
}

float  Sound::getEffectsVolume() //��ȡ��Ч����
{
	float fVolume = UserDefault::getInstance()->getFloatForKey("EffectsVol", 0.9f);
	return fVolume;
}

bool Sound::getEffectStatue()
{
	bool bEffect = UserDefault::getInstance()->getBoolForKey("MusicEffect", true);
	return bEffect;
}

bool Sound::getMusicStatue()
{
	bool bMusic = UserDefault::getInstance()->getBoolForKey("Music", true);
	return bMusic;
}

void Sound::StopEffect()
{
	SimpleAudioEngine::getInstance()->stopAllEffects();
}

void Sound::StopMusic()
{
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
}

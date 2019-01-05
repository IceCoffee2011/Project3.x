#include "PPCSound.h"
#include "cocos2d.h"


USING_NS_CC;
using namespace CocosDenshion;

PPCSound * PPCSound::m_sound = NULL;
PPCSound * PPCSound::getInstance()
{
	if(m_sound == NULL)
	{
		m_sound = new PPCSound();
	}
	return m_sound;
}
void PPCSound::freeInstance()
{
	if(m_sound != NULL)
	{
		delete m_sound;
		m_sound = NULL;
	}
}

PPCSound::PPCSound():
	m_type(EPPC_Null)
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
const char * PPCSound::getMusic(PPC_MUSIC_TYPE type)
{
	switch(type)
	{
	case MUSIC_TYPE_BACKGROUND1:
		return "bk1.mp3";
	case MUSIC_TYPE_BACKGROUND2:
		return "bk2.mp3";
	case MUSIC_TYPE_BACKGROUND3:
		return "bk3.mp3";
	case MUSIC_TYPE_BACKGROUND4:
		return "bk4.mp3";
	case MUSIC_TYPE_BACKGROUND5:
		return "bk5.mp3";
	case MUSIC_TYPE_BACKGROUND6:
		return "bk6.mp3";
	case MUSIC_TYPE_BACKGROUND7:
		return "bk7.mp3";
	case MUSIC_TYPE_BACKGROUND8:
		return "bk8.mp3";
	case MUSIC_TYPE_BACKGROUND9:
		return "bk9.mp3";
	case MUSIC_TYPE_BACKGROUND_GAME_FREE:
		return "ppc_background.mp3";
	case EFFECT_TYPE_KAICHEYINYUE: 
		return "ppc_kaicheyinyue.mp3";
	default:
		break;
	}

	return NULL;
}

void PPCSound::playBgMusic(PPC_MUSIC_TYPE type)
{
 	bool bMusic = getMusicStatue();
	if(bMusic)
	{
		auto audio = SimpleAudioEngine::getInstance();
		if(!audio->isBackgroundMusicPlaying())
		{
			audio->playBackgroundMusic(this->getMusic(type),false);
		}
		else
		{
			audio->resumeBackgroundMusic();
		}
	}
}

void PPCSound::playBgMusicRandom()
{
	int start = MUSIC_TYPE_BACKGROUND1;
	int end = MUSIC_TYPE_BACKGROUND9;
	int type = random(start, end);
	playBgMusic(PPC_MUSIC_TYPE(type));
}

const char * PPCSound::getEffect(PPC_EFFECT type)
{
	switch (type)
	{
	case EFFECT_TYPE_ADD_GOLD: return "ppc_add_gold.mp3";
	case EFFECT_TYPE_ADD_GOLD_EX: return "ppc_add_gold_ex.mp3";
	case EFFECT_TYPE_CHEER1: return "ppc_cheer1.mp3";
	case EFFECT_TYPE_CHEER2: return "ppc_cheer2.mp3";
	case EFFECT_TYPE_CHEER3: return "ppc_cheer3.mp3";
	case EFFECT_TYPE_DISPATCH_CARD: return "ppc_dispatch_card.mp3";
	case EFFECT_TYPE_END_DRAW: return "ppc_end_draw.mp3";
	case EFFECT_TYPE_END_LOST: return "ppc_end_lost.mp3";
	case EFFECT_TYPE_END_WIN: return "ppc_end_win.mp3";
	case EFFECT_TYPE_GAME_START: return "ppc_game_start.mp3";
	case EFFECT_TYPE_IDC_SND: return "ppc_idc_snd_.mp3";
	//case EFFECT_TYPE_KAICHEYINYUE: return "ppc_kaicheyinyue.mp3";
	case EFFECT_TYPE_PLEASE_BET: return "ppc_please_bet.mp3";
	case EFFECT_TYPE_PLEASE_SPEAK: return "ppc_please_speak.mp3";
	case EFFECT_TYPE_TIME_WARIMG: return "ppc_time_warimg.mp3";
	default:
		break;
	}
	return nullptr;
}

void PPCSound::playEffect(PPC_EFFECT type)
{
	bool bEffect = getEffectStatue();
	if(bEffect)
	{
		auto audio = SimpleAudioEngine::getInstance();
		audio->playEffect(this->getEffect(type));
	}
}


void PPCSound::setBgMusicVolume(float volume) //���ñ�����������
{
	UserDefault::getInstance()->setFloatForKey("BgMusicVol", volume);
	auto audio = SimpleAudioEngine::getInstance();
	audio->setBackgroundMusicVolume(volume);
}

float PPCSound::getBgMusicVolume()             //��ȡ������������
{
	float fVolume = UserDefault::getInstance()->getFloatForKey("BgMusicVol", 0.9f);
	return fVolume;
}

void PPCSound::setEffectsVolume(float volume) //������Ч����
{
	UserDefault::getInstance()->setFloatForKey("EffectsVol", volume);
	auto audio = SimpleAudioEngine::getInstance();
	audio->setEffectsVolume(volume);
}

float  PPCSound::getEffectsVolume() //��ȡ��Ч����
{
	float fVolume = UserDefault::getInstance()->getFloatForKey("EffectsVol", 0.9f);
	return fVolume;
}

//��Ч����
bool PPCSound::getEffectStatue()
{
	//bool bEffect = UserDefault::getInstance()->getBoolForKey("PPC_Music_Effect_Switch", true);
	std::string type = PPC_EFFECT_SWITCH;
	bool bEffect = UserDefault::getInstance()->getBoolForKey(type.c_str(), true);
	return bEffect;
}

//�������ֿ���
bool PPCSound::getMusicStatue()
{
	std::string type = PPC_MUSICE_SWITCH;
	bool bMusic = UserDefault::getInstance()->getBoolForKey(type.c_str(), true);
	return bMusic;
}

void PPCSound::StopEffect()
{
	SimpleAudioEngine::getInstance()->stopAllEffects();
}

void PPCSound::StopMusic()
{
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
}

void PPCSound::playGameStartEffects()
{
	m_type = EPPC_Bet;
	StopMusic();
	playEffect(EFFECT_TYPE_PLEASE_BET);
	playBgMusicRandom();
}

void PPCSound::playGameEndEffects()
{
	m_type = EPPC_Lottery;
	StopMusic();
	playEffect(EFFECT_TYPE_GAME_START);
	playBgMusic(EFFECT_TYPE_KAICHEYINYUE);
}

void PPCSound::playEffectShowResult(bool win)
{
	m_type = EPPC_Null;
	StopMusic();
	if (win)
	{
		playEffect(EFFECT_TYPE_END_WIN);
	}
	else
	{
		playEffect(EFFECT_TYPE_END_LOST);
	}
	//ɲ��
	playEffect(EFFECT_TYPE_IDC_SND);
}

void PPCSound::playMusiceOnGameFree()
{
	m_type = EPPC_Idle;
	StopMusic();
	StopEffect();
	playBgMusic(MUSIC_TYPE_BACKGROUND_GAME_FREE);
}


void PPCSound::playMusicByState()
{
	switch (m_type)
	{
	case EPPC_Idle:
		playBgMusic(MUSIC_TYPE_BACKGROUND_GAME_FREE);
		break;
	case EPPC_Bet:
		playBgMusicRandom();
		break;
	case EPPC_Lottery:
		playBgMusic(EFFECT_TYPE_KAICHEYINYUE);
		break;
	case EPPC_Null:
		break;
	default:
		break;
	}
}

#include "SGLYManageAudio.h"
#include "SGLYRes.h"

//	��Ƶ�����൥������
static SGLYManageAudio* m_sSharedSGLYManageAudio = nullptr;

SGLYManageAudio::SGLYManageAudio()
{
}

SGLYManageAudio::~SGLYManageAudio()
{
}

SGLYManageAudio* SGLYManageAudio::getInstance()
{
	if (!m_sSharedSGLYManageAudio)
	{
		m_sSharedSGLYManageAudio = new (std::nothrow)SGLYManageAudio();
		CCASSERT(m_sSharedSGLYManageAudio, "FATAL: Not enough memory");
		m_sSharedSGLYManageAudio->init();
	}

	return m_sSharedSGLYManageAudio;
}

//	Ԥ������Ƶ�ļ�
void SGLYManageAudio::preLoadAudio()
{
	//	��Ч
	for (int i = E_SGLY_Audio_BtnBet_Bar; i < E_SGLY_Audio_Null; i++)
	{
		SimpleAudioEngine::getInstance()->preloadEffect(m_sAudioFile[i].c_str());
	}
}

//	�������
void SGLYManageAudio::clear()
{
	SimpleAudioEngine::getInstance()->end();
}

//	���ű�������
void SGLYManageAudio::playBGMusic(bool bLoop)
{
	if (!getOnBGMusic())
	{
		//	��������
		return;
	}
	SimpleAudioEngine::getInstance()->playBackgroundMusic(m_sAudioFile[E_SGLY_Audio_BGM].c_str(), bLoop);
}

//	ֹͣ���ű�������
void SGLYManageAudio::stopBGMusic()
{
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

//	������Ч
void SGLYManageAudio::playSoundEffect(E_SGLY_Audio eSound, bool bLoop)
{
	if (eSound < E_SGLY_Audio_BtnBet_Bar && eSound >= E_SGLY_Audio_Null)
	{
		return;
	}
	if (!getOnSoundEffect())
	{
		//	������Ч
		return;
	}
	SimpleAudioEngine::getInstance()->playEffect(m_sAudioFile[eSound].c_str(), bLoop);
}

//	ֹͣ����������Ч
void SGLYManageAudio::stopAllSoundEffect()
{
	SimpleAudioEngine::getInstance()->stopAllEffects();
}

//	���ñ�����������
void SGLYManageAudio::setBGMusicVolume(float fVolume)
{
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(fVolume);
}

//	������Ч����
void SGLYManageAudio::setSoundEffectVolume(float fVolume)
{
	SimpleAudioEngine::getInstance()->setEffectsVolume(fVolume);
}

//	�����Ƿ�����������
void SGLYManageAudio::setOnBGMusic(bool bIsOn)
{
	m_bOnBGMusic = bIsOn;
	UserDefault::getInstance()->setBoolForKey(SGLY_DATA_KEY_AUDIO_ON_BGM, m_bOnBGMusic);
}

//	��õ�ǰ�Ƿ�����������
bool SGLYManageAudio::getOnBGMusic() const
{
	return m_bOnBGMusic;
}

//	�����Ƿ�����Ч
void SGLYManageAudio::setOnSoundEffect(bool bIsOn)
{
	m_bOnSoundEffect = bIsOn;
	UserDefault::getInstance()->setBoolForKey(SGLY_DATA_KEY_AUDIO_ON_SOUND_EFFECT, m_bOnSoundEffect);
}

//	��õ�ǰ�Ƿ�����Ч
bool SGLYManageAudio::getOnSoundEffect() const
{
	return m_bOnSoundEffect;
}

bool SGLYManageAudio::init()
{
	m_sAudioFile[E_SGLY_Audio_BGM] = SGLYTextureName::sSGLY_AudioBGM;
	m_sAudioFile[E_SGLY_Audio_BtnBet_Bar] = SGLYTextureName::sSGLY_AudioBtnBetBar;
	m_sAudioFile[E_SGLY_Audio_BtnBet_Seven] = SGLYTextureName::sSGLY_AudioBtnBetSeven;
	m_sAudioFile[E_SGLY_Audio_BtnBet_Star] = SGLYTextureName::sSGLY_AudioBtnBetStar;
	m_sAudioFile[E_SGLY_Audio_BtnBet_Watermelon] = SGLYTextureName::sSGLY_AudioBtnBetWatermelon;
	m_sAudioFile[E_SGLY_Audio_BtnBet_Bell] = SGLYTextureName::sSGLY_AudioBtnBetBell;
	m_sAudioFile[E_SGLY_Audio_BtnBet_Pear] = SGLYTextureName::sSGLY_AudioBtnBetPear;
	m_sAudioFile[E_SGLY_Audio_BtnBet_Orange] = SGLYTextureName::sSGLY_AudioBtnBetOrange;
	m_sAudioFile[E_SGLY_Audio_BtnBet_Apple] = SGLYTextureName::sSGLY_AudioBtnBetApple;
	m_sAudioFile[E_SGLY_Audio_Lottery_Bar] = SGLYTextureName::sSGLY_AudioLotteryBar;
	m_sAudioFile[E_SGLY_Audio_Lottery_Seven] = SGLYTextureName::sSGLY_AudioLotterySeven;
	m_sAudioFile[E_SGLY_Audio_Lottery_Star] = SGLYTextureName::sSGLY_AudioLotteryStar;
	m_sAudioFile[E_SGLY_Audio_Lottery_Watermelon] = SGLYTextureName::sSGLY_AudioLotteryWatermelon;
	m_sAudioFile[E_SGLY_Audio_Lottery_Bell] = SGLYTextureName::sSGLY_AudioLotteryBell;
	m_sAudioFile[E_SGLY_Audio_Lottery_Pear] = SGLYTextureName::sSGLY_AudioLotteryPear;
	m_sAudioFile[E_SGLY_Audio_Lottery_Orange] = SGLYTextureName::sSGLY_AudioLotteryOrange;
	m_sAudioFile[E_SGLY_Audio_Lottery_Apple] = SGLYTextureName::sSGLY_AudioLotteryApple;
	m_sAudioFile[E_SGLY_Audio_Guess_Lose] = SGLYTextureName::sSGLY_AudioGuessLose;
	m_sAudioFile[E_SGLY_Audio_Guess_Win] = SGLYTextureName::sSGLY_AudioGuessWin;
	m_sAudioFile[E_SGLY_Audio_GoodLuck_Flash] = SGLYTextureName::sSGLY_AudioGoodLuckFlash;
	m_sAudioFile[E_SGLY_Audio_GoodLuck_Hit] = SGLYTextureName::sSGLY_AudioGoodLuckHit;
	m_sAudioFile[E_SGLY_Audio_TimeWarning] = SGLYTextureName::sSGLY_AudioTimeWarning;
	m_sAudioFile[E_SGLY_Audio_TurnStart] = SGLYTextureName::sSGLY_AudioTurnStart;
	m_sAudioFile[E_SGLY_Audio_DispatchLottery] = SGLYTextureName::sSGLY_AudioDispatchLottery;
	m_sAudioFile[E_SGLY_Audio_GameStart] = SGLYTextureName::sSGLY_AudioGameStart;

	bool bBanBGM = UserDefault::getInstance()->getBoolForKey(SGLY_DATA_KEY_AUDIO_ON_BGM, true);
	bool bBanSoundEffect = UserDefault::getInstance()->getBoolForKey(SGLY_DATA_KEY_AUDIO_ON_SOUND_EFFECT, true);
	setOnBGMusic(bBanBGM);
	setOnSoundEffect(bBanSoundEffect);

	return true;
}
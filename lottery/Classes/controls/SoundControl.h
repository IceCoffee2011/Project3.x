//  [4/9/2014 xieyi]
#ifndef __SOUNDCONTROL__
#define __SOUNDCONTROL__
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

//������Ч��Դ
namespace sound_name
{
	const static char s_bgMusic[] = "xyxbg.mp3";//��������
// 	//����
// 	const static char s_man_wav0[] = "man/wav0.wav";//������������
// 	const static char s_man_wav1[] = "man/wav1.wav";//������ٷ���������
// 	const static char s_man_wav2[] = "man/wav2.wav";//�ӵ���
// 	const static char s_man_wav3[] = "man/wav3.wav";//�Ʋ��ںá�����
// 	const static char s_man_wav4[] = "man/wav4.wav";//��Ҫ��ʼ�����ˡ�����
// 	const static char s_man_wav5[] = "man/wav5.wav";//���ߵ�̫��������
// 	const static char s_man_bujiabei[] = "man/bujiabei.wav";//���ӱ�
// 	const static char s_man_bujiao[] = "man/bujiao.wav";//����
// 	const static char s_man_buqiang[] = "man/buqiang.wav";//����
// 	const static char s_man_buyao[] = "man/buyao.wav";//��Ҫ
// 	const static char s_man_dani[] = "man/dani.wav";//����
// 	const static char s_man_feiji[] = "man/feiji.wav";//�ɻ�
// 	const static char s_man_guo[] = "man/guo.wav";//��
// 	const static char s_man_huojian[] = "man/huojian.wav";//huojian
// 	const static char s_man_jiabei[] = "man/jiabei.wav";//�ӱ�
// 	const static char s_man_jiaodizhu[] = "man/jiaodizhu.wav";//�е���
// 	const static char s_man_liandui[] = "man/liandui.wav";//����
// 	const static char s_man_mingpai[] = "man/mingpai.wav";//����
// 	const static char s_man_qiangdizhu[] = "man/qiangdizhu.wav";//������
// 	const static char s_man_sandaiyi[] = "man/sandaiyi.wav";//����һ
// 	const static char s_man_sandaier[] = "man/sandaier.wav";//����һ��
// 	const static char s_man_sanshun[] = "man/sanshun.wav";//��˳
// 	const static char s_man_sanzhang[] = "man/sanzhang.wav";//����
// 	const static char s_man_shunzi[] = "man/shunzi.wav";//˳��
// 	const static char s_man_sidaier[] = "man/sidaier.wav";//�Ĵ���
// 	const static char s_man_yasi[] = "man/yasi.wav";//ѹ��
// 	const static char s_man_yaobuqi[] = "man/yaobuqi.wav";//Ҫ����
// 	const static char s_man_yidui[] = "man/yidui.wav";//һ��
// 	const static char s_man_yizhang[] = "man/yizhang.wav";//һ��
// 	const static char s_man_zhadan[] = "man/zhadan.wav";//ը��

	//Ů��

// 	const static char s_woman_wav0[] = "woman/wav0.wav";//������������
// 	const static char s_woman_wav1[] = "woman/wav1.wav";//������ٷ���������
// 	const static char s_woman_wav2[] = "woman/wav2.wav";//�ӵ���
// 	const static char s_woman_wav3[] = "woman/wav3.wav";//�Ʋ��ںá�����
// 	const static char s_woman_wav4[] = "woman/wav4.wav";//��Ҫ��ʼ�����ˡ�����
// 	const static char s_woman_wav5[] = "woman/wav5.wav";//���ߵ�̫��������
// 	const static char s_woman_bujiabei[] = "woman/bujiabei.wav";//���ӱ�
// 	const static char s_woman_bujiao[] = "woman/bujiao.wav";//����
// 	const static char s_woman_buqiang[] = "woman/buqiang.wav";//����
// 	const static char s_woman_buyao[] = "woman/buyao.wav";//��Ҫ
// 	const static char s_woman_dani[] = "woman/dani.wav";//����
// 	const static char s_woman_feiji[] = "woman/feiji.wav";//�ɻ�
// 	const static char s_woman_guo[] = "woman/guo.wav";//��
// 	const static char s_woman_huojian[] = "woman/huojian.wav";//huojian
// 	const static char s_woman_jiabei[] = "woman/jiabei.wav";//�ӱ�
// 	const static char s_woman_jiaodizhu[] = "woman/jiaodizhu.wav";//�е���
// 	const static char s_woman_liandui[] = "woman/liandui.wav";//����
// 	const static char s_woman_mingpai[] = "woman/mingpai.wav";//����
// 	const static char s_woman_qiangdizhu[] = "woman/qiangdizhu.wav";//������
// 	const static char s_woman_sandaiyi[] = "woman/sandaiyi.wav";//����һ
// 	const static char s_woman_sandaier[] = "woman/sandaier.wav";//����һ��
// 	const static char s_woman_sanshun[] = "woman/sanshun.wav";//��˳
// 	const static char s_woman_sanzhang[] = "woman/sanzhang.wav";//����
// 	const static char s_woman_shunzi[] = "woman/shunzi.wav";//˳��
// 	const static char s_woman_sidaier[] = "woman/sidaier.wav";//�Ĵ���
// 	const static char s_woman_yasi[] = "woman/yasi.wav";//ѹ��
// 	const static char s_woman_yaobuqi[] = "woman/yaobuqi.wav";//Ҫ����
// 	const static char s_woman_yidui[] = "woman/yidui.wav";//һ��
// 	const static char s_woman_yizhang[] = "woman/yizhang.wav";//һ��
// 	const static char s_woman_zhadan[] = "woman/zhadan.wav";//ը��
	
	// �ټ�����Ч<by hxh 20160729>
	const static char s_add_gold[] = "ADD_GOLD.wav";//��ע
	const static char s_dispatch_card[] = "DISPATCH_CARD.wav";//����
	const static char s_end_lost[] = "END_LOST.wav";//��
	const static char s_end_win[] = "END_WIN.wav";//Ӯ
	const static char s_time_warimg[] = "TIME_WARIMG.wav";//����ʱ����

	// �����˿���Ч<by hxh 20160912>
	const static char s_dzpk_b_ready[] = "dzpk_b_ready.mp3";//�ƾֿ�ʼ
	const static char s_dzpk_man_giveover[] = "dzpk_man_demand_type_0_6_0.mp3";//����
	const static char s_dzpk_women_giveover[] = "dzpk_women_demand_type_2_6_0.mp3";//����
	const static char s_dzpk_man_qx[] = "dzpk_man_demand_type_0_5_0.mp3";//ȫѹ
	const static char s_dzpk_women_qx[] = "dzpk_women_demand_type_2_5_0.mp3";//ȫѹ
	const static char s_dzpk_man_jz[] = "dzpk_man_demand_type_0_2_0.mp3";//��ע
	const static char s_dzpk_women_jz[] = "dzpk_women_demand_type_2_2_0.mp3";//��ע
	const static char s_dzpk_man_gz[] = "dzpk_man_demand_type_0_3_0.mp3";//��ע
	const static char s_dzpk_women_gz[] = "dzpk_women_demand_type_2_3_0.mp3";//��ע
	const static char s_dzpk_man_guo[] = "dzpk_man_demand_type_0_4_0.mp3";//��������
	const static char s_dzpk_women_guo[] = "dzpk_women_demand_type_2_4_0.mp3";//������Ů
	const static char s_dzpk_man_xz[] = "dzpk_man_demand_type_0_1_0.mp3";//��ע
	const static char s_dzpk_women_xz[] = "dzpk_women_demand_type_2_1_0.mp3";//��ע
	const static char s_dzpk_win[] = "sound_guzhang.mp3";//Ӯ�� by hxh
	const static char s_dzpk_lose[] = "sound_shibai.mp3";//���� by hxh
	const static char s_dzpk_chupai[] = "sound_chupai.mp3";//�ֵ��ҷ��ж� by hxh
    const static char s_dzpk_fapai[] = "sound_fapai.mp3";//����ʱ����ʼ�ķ��� by hxh
	const static char s_dzpk_gangjinru[] = "sound_gangjinru.mp3";//��Ҹռ�������ʱ����Ч���������������£��������ƣ� by hxh
	const static char s_dzpk_dianji[] = "sound_dianji.mp3";//������ⰴť by hxh
	const static char s_dzpk_card_type_1[] = "dzpk_card_type_1.mp3";//ɢ��
	const static char s_dzpk_card_type_2[] = "dzpk_card_type_2.mp3";//����
	const static char s_dzpk_card_type_3[] = "dzpk_card_type_3.mp3";//����
	const static char s_dzpk_card_type_4[] = "dzpk_card_type_4.mp3";//����
	const static char s_dzpk_card_type_5[] = "dzpk_card_type_5.mp3";//˳��
	const static char s_dzpk_card_type_6[] = "dzpk_card_type_6.mp3";//ͬ��
	const static char s_dzpk_card_type_7[] = "dzpk_card_type_7.mp3";//��«
	const static char s_dzpk_card_type_8[] = "dzpk_card_type_8.mp3";//����
	const static char s_dzpk_card_type_9[] = "dzpk_card_type_9.mp3";//ͬ��˳
	const static char s_dzpk_card_type_10[] = "dzpk_card_type_10.mp3";//ͬ����˳
	const static char s_dzpk_sound_base_card[] = "dzpk_sound_base_card.mp3";//
	const static char s_dzpk_chouma[] = "sound_chouma.mp3";//����ʱ�����ѡ���ע����ע����Ч by hxh
	const static char s_dzpk_dachouma[] = "sound_dachouma.mp3";//ʤ������ҳ����ƶ� by hxh
	const static char s_dzpk_sound_chip[] = "dzpk_sound_chip.mp3";//��������
	const static char s_dzpk_sound_chips[] = "dzpk_sound_chips.mp3";//�������
	const static char s_dzpk_sound_clock[] = "dzpk_sound_clock.mp3";//ʱ��
	const static char s_dzpk_daojishi[] = "sound_daojishi.mp3";//����ʱ��ʣ5��ʱ���ŵ���Ч by hxh
	const static char s_dzpk_sound_deal[] = "dzpk_sound_deal.mp3";//
	const static char s_dzpk_sound_pass[] = "dzpk_sound_pass.mp3";//
	const static char s_dzpk_sound_show_hand[] = "dzpk_sound_show_hand.mp3";//
	const static char s_dzpk_sound_take_chips[] = "dzpk_sound_take_chips.mp3";//
	const static char s_ct_sanshun[] = "ct_sanshun.mp3";//��˳
	const static char s_dzpk_b_show_card[] = "dzpk_b_show_card.mp3";//������
}

class SoundControl
{
public:
	SoundControl();
	~SoundControl();
	static SoundControl * sharedSoundControl();		//��ò��������ĵ���
	void playSoundEffect(const char * soundName);	//������Ч
	void playBackGroundMusic(const char * soundName,bool loop);	//���ű�������
	void coloseBackGroundMusic();
	void setVoiceIsOpen(bool var);					//��������
	void setSoundEffVol(float vol);					//��Ч����
	void setMusicVol(float vol);						//������������

private:
	bool m_voiceIsOpen;		//true��ʾ�ر�����
	float m_soundEffVol;
	float m_musicVol;
};

struct Tag 
{
	unsigned int userId;//�û�id
	unsigned int gender;//�Ա�
};

class SoundEffect
{
public:
	SoundEffect();
	~SoundEffect();
	static SoundEffect * sharedSoundEffect();
	void playEffect(const char * soundName,int userId);
	void playPassEffect(int userId);
	void playDaPaiEffect(int userId);
	void initLeftTag(Tag left);
	void initRightTag(Tag right);
	void initSelfTag(Tag self);

public:
	Tag m_leftUser;//�ϼ�
	Tag m_self;//�Լ�
	Tag m_rightUser;//�¼�
};

#endif
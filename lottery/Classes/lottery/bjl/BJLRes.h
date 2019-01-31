//  [3/18/2014 wucan]

#ifndef		__BJL_RES__
#define		__BJL_RES__
#include "Define.h"
//--Notification message
#define MESSAGE_JNICONTROL				"message_jnicontrol"
#define MESSAGE_TOVIEW						"message_toview"
#define MESSAGE_TOLOGIC					"message_tologic"
#define MESSAGE_MENUCLICKED			"message_menuclicked"		//��ť����

//--jnicontrol message
enum
{
	MSG_JNI_Share=1,
	MSG_JNI_Task,
	MSG_JNI_Start,
	MSG_JNI_Recharge,
};

////--game Scene
//enum
//{
//	SCENE_start=1,			//����
//	SCENE_game,
//	SCENE_endAgain
//};

namespace texture_name
{
	//����ͼƬ��Դ
	const static char s_cardTable1[] = "cardtable.png";//<by hxh>
	const static char s_cardTable[] = "myCardtable.png";
	const static char s_background[]="BJL_01.png";//����pic
	const static char s_cardtable[] = "cardtable.png";//<by hxh>
	const static char s_usericon[] = "manicon.png";//�����ͷ��pic
	const static char s_womanIcon[] = "womanicon.png";//Ů���ͷ��
	const static char s_bujiao[] = "btn_bujiao.png";//���е���btn
	const static char s_buqiang[] = "btn_buqiang.png";//��������btn
	const static char s_CCteefTag[] = "BJL_15.png";//����ʱ�� pic
	const static char s_PlaceScore[] = "BJL_14.png";//��עʱ�� pic
	const static char s_CardTalayer[] = "BJL_16.png";//����ʱ�� pic
	const static char s_GameState0[] = "BJL_23_1.png";//����ʱ�� pic
	const static char s_GameState1[] = "BJL_23_2.png";//��עʱ�� pic
	const static char s_GameState2[] = "BJL_23_3.png";//����ʱ�� pic
	const static char s_CallScoreTip[] = "BJL_04.png";//������ע��ʾ pic
	const static char s_BankerCallScoreTip[] = "BJL_04_2.png";//������ע��ʾ pic
	const static char s_timer[] = "BJL_19.png";//��ʱ�� pic<by hxh 20160630>
	const static char s_timerNumber[] = "timernumber_1.png";//��ʱ������ pic
	const static char s_ChipMagerNumber[] = "SCORE_NUMBER.png";//��ע���� pic
	const static char s_TIME_NUMBERScore[] = "TIME_NUMBER.png";//��ע���� pic
	const static char s_ChangeBankerTip1[] = "BJL_11.png";//������ׯ pic
	const static char s_ChangeBankerTip2[] = "BJL_12.png";//�ֻ�ׯ�� pic
	const static char s_ChangeBankerTip3[] = "BJL_13.png";//������ׯ pic
	const static char s_SpriteNunber[] = "SCORE_BACK.png";//��ע pic
	const static char s_MySpriteNunber[] = "ME_SCORE_BACK.png";//�Լ���ע pic
	const static char s_Light[]= "cm_15.png";//���밴ť��Ȧ
	const static char s_coinNumber1[] = "coinnumber1.png";
	const static char s_GameRecord[] = "BJL_06.png";//��Ϸ��¼ pic
	const static char s_ZXPGou[] = "BJL_24_1.png";//�� pic
	const static char s_BankerUser[]= "BJL_05.png";//ׯ���û� pic
	const static char s_Gender1[] = "bjl_face_man.png";//�� pic<by hxh 20160919>
	const static char s_Gender0[] = "bjl_face_woman.png";//Ů pic<by hxh 20160919>
	const static char s_Player[] = "BJL_20_2.png";//�� pic<by hxh 20160721>
	const static char s_Banker[] = "BJL_20_1.png";//ׯ pic<by hxh 20160721>
	const static char s_BankerPic1[] = "bjl_face_man_2.png";//ׯ��ͷ�� pic<by hxh 20160919>
	const static char s_settlementbg[] = "settlement_bg.png";//���㱳��
	const static char s_BankerPic2[] = "bjl_face_man_2.png";//ׯ��ͷ�� pic<by hxh 20160919>
	const static char s_PlayerWin[] = "BJL_20_5.png";//��Ӯ pic<by hxh 20160811>
	const static char s_BankerWin[] = "BJL_20_4.png";//ׯӮ pic<by hxh 20160811>
	const static char s_AndBureau[] = "BJL_20_3.png";//�� pic<by hxh 20160811>
	const static char s_GameEnd[] = "GAME_END.png";//��Ϸ���� pic<by hxh 20160811>
	const static char s_font_jiaodizhu[] = "font_jiaodizhu.png";//�е�����
	const static char s_font_pass[] = "font_pass.png";//������
	const static char s_font_qiangdizhu[] = "font_qiangdizhu.png";//��������
	const static char s_font_visiblecard[] = "font_visiblecard.png";//������
	const static char s_font_jiabei[] = "font_jiabei.png";//�ӱ���
	const static char s_font_hfd[] = "font_hfd.png";
	const static char s_x[] = "x.png";//X
	const static char s_menuBarBackground[] = "bg_menubar.png";//�˵�������
	const static char s_back[] = "btn_back.png";//���ذ�ť
	const static char s_options[] = "btn_options.png";//���ð�ť
	const static char s_pull[] = "btn_pull.png";//�˵�������
	const static char s_robot[] = "btn_robot.png";//�йܰ�ť
	const static char s_talk[] = "btn_talk.png";//���찴ť
	const static char s_task[] = "btn_task.png";//����ť
	const static char s_smallCard[] = "smallcard.png";//С�˿���ͼƬ
	const static char s_hintCard[] = "hintcard.png";//���ŵ��˿�ͼƬ
	const static char s_settlementDetial[] = "settlementdetial.png";//�鿴��ϸbtn
	const static char s_jiaBeiBar[] = "jbb_bj.png";//���Ƽӱ�������ʾ����ͼƬ

	const static char s_music[] = "music.png";//��������ͼƬ
	const static char s_soundEffect[] = "soundeffect.png";//��ЧͼƬ
	const static char s_off[] = "off.png";//�ر���ͼƬ
	const static char s_on[] = "on.png";//������ͼƬ
	const static char s_on_off[] = "on_off.png";//����ͼƬ
	const static char s_progress_bj[] = "progressbar0.png";//����������
	const static char s_progress[] = "progressbar1.png";//������
	const static char s_setup_bg[] = "task_k.png";//���õ׿�
	const static char s_expression[] = "expression.png";//��������
	const static char s_voice[] = "voice.png";//��������

	const static char s_confirm[] = "btn_confirm.png";//ȷ����ť
	const static char s_confirm1[] = "btn_confirm1.png";//ȷ����ť<by hxh>
	const static char s_faceBg[] = "face_bg.png";//����򱳾�
	//const static char s_xlt[] = "xlt.png";//������
	const static char s_yyk[] = "yyk.png";//������
	const static char s_banshou[] = "banshou.png";//�����˰���
	const static char s_cancleRobot[] = "btn_cancelrobot.png";//ȡ���й�
	const static char s_eye[]= "eye.png";//�������۾�
	const static char s_robot_pic[] = "robot.png";//������ͼƬ
	const static char s_paiBei0[] = "paibei0.png";//�Ʊ�0
	const static char s_paiBei1[] = "paibei1.png";//�Ʊ�1

	const static char s_dizhu_man[] = "dizhu_man.png";//�е���
	const static char s_farmer_man[] = "farmer_man.png";//��ũ��
	const static char s_dizhu_woman[] = "dizhu_woman.png";//Ů����
	const static char s_farmer_woman[] = "farmer_woman.png";//Ůũ��
	const static char s_btn_cancle[] = "btn_cancle.png";//ȡ����ť
	const static char s_btn_cancle1[] = "btn_cancle1.png";//ȡ����ť<by hxh>
	const static char s_huojian[] = "huojian.png";//���
	const static char s_huoyan[] = "huoyan.png";//����
	const static char s_paizi[] = "paizi.png";//���˶�����ͼ
	const static char s_font_deng[] = "font_deng.png";//��
	const static char s_font_dai[] = "font_dai.png";//��
	const static char s_font_qi[] = "font_qi.png";//��
	const static char s_font_ta[] = "font_ta.png";//��
	const static char s_font_wan[] = "font_wan.png";//��
	const static char s_font_jia[] = "font_jia.png";//��
	const static char s_font_zhong[] = "font_zhong.png";//��
	const static char s_A_8[] = "A_8.png";//������<by hxh>
	const static char s_loser[] = "loser.png";//ʧ�ܶ���
	const static char s_winner[] = "winner.png";//ʤ������
	const static char s_notify[] = "notify.png";//��Ϸ��������ʾ��Ϣ����
	const static char s_task_d[] = "task_d.png";//�������ֵ�
	const static char s_task_k[] = "task_k.png";//�����
	const static char s_bankerlist[] = "BJL_25_2.png";//��ׯ�б�<by hxh>

	//dzpk��ԴͼƬ<by hxh 20160826>
	const static char s_dzpklayerBG[] = "dzpk_backgroud.png";//�����˿����ӱ���
	const static char s_ready[] = "Ap_35.png";//׼��
	const static char s_tx_boy[] = "tx_boy%d.png";//��
	const static char s_tx_girl[] = "tx_girl%d.png";//Ů
	const static char s_ol_btn_ckpx_pressed[] = "ol_btn_ckpx_pressed.png";//�鿴���Ͱ���
	const static char s_ol_btn_gryz_pressed[] = "ol_btn_gryz_pressed.png";//���κ�ע����
	const static char s_table_level[] = "table_level%d.png";
	const static char s_room_light[] = "room_light.png";//�ƹ� by hxh 20161014
	//img_game_operalayer
	const static char s_win[] = "GaneSuccent.png";
	const static char s_lose[] = "GameWaring.png";
	const static char s_draw[] = "GameNumBer.png";
	const static char s_cd_bg_other[] = "cd_bg_other.png";//����ʱ by hxh 20161012
	const static char s_dl_btn_cancel[] = "dl_btn_cancel.png";//��
	const static char s_dl_btn_confirm[] = "strGame_button1.png";//"dl_btn_confirm.png";//��
	const static char s_dl_bg_wxts[] = "dl_bg_wxts.png";//��ܰ��ʾ
	const static char s_ol_bg_bccm[] = "ol_bg_bccm.png";//VipLagerBack
	const static char s_strGame_button1[] = "strGame_button1.png";//ȷ��
	const static char s_strGame_button2[] = "strGame_button2.png";//ȷ��
	const static char s_ol_btn_qp[] = "ol_btn_qp.png";//����
	const static char s_ol_btn_qx[] = "ol_btn_qx.png";//���
	const static char s_gp_btn[] = "Acard.png";//����
	const static char s_jz_btn[] = "ol_btn_jz.png";//��ע
	const static char s_gz_btn[] = "ol_btn_gz.png";//��ע
	const static char s_xz_btn[] = "ol_btn_xz.png";//��ע
	const static char s_ol_bg_raise[] = "ol_bg_raise.png";
	const static char s_ol_track_raise[] = "ol_track_raise.png";//����������ͼ
	const static char s_ol_progress_raise[] = "ol_progress_raise.png";//��������ͼ
	const static char s_ol_thumb_raise[] = "ol_thumb_raise.png";//����ͼ
	const static char s_ol_btn_ckpx_normal[] = "ol_btn_ckpx_normal.png";//�鿴����
	const static char s_ol_bg_ckpx[] = "ol_bg_ckpx.png";//����
	const static char s_ol_btn_gryz_normal[] = "ol_btn_gryz_normal.png";//���κ�ע
	const static char s_start_button1[] = "StartButton1.png";//��ʼ
	const static char s_start_button2[] = "StartButton2.png";//��ʼ
	const static char s_exit_button1[] = "exitbutton1.png";//�뿪
	const static char s_exit_button2[] = "exitbutton2.png";//�뿪
	const static char s_exit_1[] = "exit_1.png";//�˳�
	const static char s_exit_2[] = "exit_2.png";//�˳�
	const static char s_card_big_baiban[] = "card_big_baiban.png";//�˿��ƣ��󣩰װ�
	const static char s_card_small_baiban[] = "card_small_baiban.png";//�װ壨С��
	const static char s_card_color[] = "card_color.png";//�˿��ƻ�ɫ���ں췽÷��
	const static char s_card_num_black[] = "card_num_black.png";//�˿����ֺ�
	const static char s_card_num_red[] = "card_num_red.png";//�˿��ƺ�
	const static char s_joker[] = "joker.png";	//ͼƬ��СΪ pic

	const static char s_dzpk_raise_slider_floor[] = "dzpk_raise_slider_floor.png";			//��ע�������ذ�
	const static char s_dzpk_raise_slider_bg[] = "dzpk_raise_slider_bg.png";				//��ע����������
	const static char s_dzpk_raise_slider_progress[] = "dzpk_raise_slider_progress.png";	//��ע����������
	const static char s_dzpk_raise_slider_thumb[] = "dzpk_raise_slider_thumb.png";			//��ע������������
	const static char s_dzpk_raise_slider_allin[] = "dzpk_raise_slider_allin.png";			//	��ע���ı�����ȫ��

	const static char s_card[] ="card.png";//�˿���
	//DZPKImage
	const static char s_mk_bg_makers[] = "mk_bg_makers.png";//D
	const static char s_rf_back_light[] = "RF_back_light.png";//
	const static char s_rf_a[] = "RF_a.png";//A
	const static char s_rf_k[] = "RF_k.png";//K
	const static char s_rf_q[] = "RF_q.png";//Q
	const static char s_rf_j[] = "RF_j.png";//J
	const static char s_rf_10[] = "RF_10.png";//10
	const static char s_rf_back_circle[] = "RF_back_circle.png";//
	const static char s_rf_zi[] = "RF_zi.png";//�ʼ�ͬ��˳
	const static char s_ts_bg_lock[] = "ts_bg_lock.png";//��
	const static char s_ts_bg_circle1[] = "ts_bg_circle1.png";//
	const static char s_ts_bg_arrow[] = "ts_bg_arrow.png";//
	const static char s_action_think[] = "action_think.png";//˼��
	const static char s_small_blind[] = "small_blind.png";//Сäλ
	const static char s_big_blind[] = "big_blind.png";//��äλ
	const static char s_action_check[] = "action_check.png";//��
	const static char s_action_call[] = "action_call.png";//��ע
	const static char s_action_raise[] = "action_raise.png";//��ע
	const static char s_action_bet[] = "action_bet.png";//��ע
	const static char s_action_fold[] = "action_fold.png";//����
	const static char s_action_allin[] = "action_allin.png";//ȫ��
	const static char s_cardtype_gaopai[] = "cardtype_gaopai.png";//����
	const static char s_cardtype_hulu[] = "cardtype_hulu.png";//��«
	const static char s_cardtype_liangdui[] = "cardtype_liangdui.png";//����
	const static char s_cardtype_santiao[] = "cardtype_santiao.png";//����
	const static char s_cardtype_shunzi[] = "cardtype_shunzi.png";//˳��
	const static char s_cardtype_sitiao[] = "cardtype_sitiao.png";//����
	const static char s_cardtype_tonghua[] = "cardtype_tonghua.png";//ͬ��
	const static char s_cardtype_tonghuashun[] = "cardtype_tonghuashun.png";//ͬ��˳
	const static char s_cardtype_yidui[] = "cardtype_yidui.png";//һ��
	const static char s_room_win_label[] = "room_win_label.png";//ʤ����!
	const static char s_cardtype_gaopai_2[] = "cardtype_gaopai_2.png";//����
	const static char s_cardtype_hulu_2[] = "cardtype_hulu_2.png";//��«
	const static char s_cardtype_liangdui_2[] = "cardtype_liangdui_2.png";//����
	const static char s_cardtype_santiao_2[] = "cardtype_santiao_2.png";//����
	const static char s_cardtype_shunzi_2[] = "cardtype_shunzi_2.png";//˳��
	const static char s_cardtype_sitiao_2[] = "cardtype_sitiao_2.png";//����
	const static char s_cardtype_tonghua_2[] = "cardtype_tonghua_2.png";//ͬ��
	const static char s_cardtype_tonghuashun_2[] = "cardtype_tonghuashun_2.png";//ͬ��˳
	const static char s_cardtype_yidui_2[] = "cardtype_yidui_2.png";//һ��
	const static char s_cm_bg_redchip[] = "cm_bg_redchip.png";
	const static char s_cm_bg_bluechip[] = "cm_bg_bluechip.png";
	const static char s_cm_bg_purplechip[] = "cm_bg_purplechip.png";
	const static char s_desk_num_frame[] ="desk_num_frame.png";
	const static char s_dzchip[] = "dzchip_%d.png";//���� by hxh 20161015
	const static char s_room_card_frame[] = "room_card_frame.png";
	//dzpk
	const static char s_nullHead[] = "pi_bg_nullplayer.png";//��ͷ�� by hxh 20161012
	const static char s_info_bg_mask[] = "pi_bg_mask.png";//���ƻ��Թ�ʱ���� by hxh 20161012
	const static char s_info_bg_chipvalue[] = "pi_bg_chipvalue.png";//����ֵ���� by hxh 20161012
	const static char s_next_round[] = "next_round.png";//�ȴ���һ�� by hxh 20161012
	const static char s_offline[] = "offline.png";//���� by hxh 20161012
	
	//DZPKImageAdd
	const static char s_SendCardMachine0[] = "SendCardMachine0.png";
	const static char s_CardBK[] = "CardBK.png";
	const static char s_jingbao5[] = "jingbao5.png";
	//pic_show
	const static char s_tx_boy6[] = "tx_boy6.png";//ͷ��
	//pic_game
	const static char s_vip_level[] = "table_level1.png";//��Ա�ȼ�

	//���Сͷ��
	const static char s_man_head_icon[] = "man_head_icon.png";
	const static char s_woman_head_icon[] = "woman_head_icon.png";
	const static char s_userMessage[] = "usermessage.png";//�û���Ϣ��
}
#endif
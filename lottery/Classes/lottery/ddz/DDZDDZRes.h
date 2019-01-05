//  [3/18/2014 wucan]

#ifndef		DDZ___DDZ_RES__
#define		DDZ___DDZ_RES__
#include "Define.h"
//--Notification message
#define MESSAGE_JNICONTROL				"message_jnicontrol"
#define MESSAGE_TOVIEW						"message_toview"
#define MESSAGE_TOLOGIC					"message_tologic"
#define MESSAGE_MENUCLICKED			"message_menuclicked"		//��ť����

////--jnicontrol message
//enum
//{
//	MSG_JNI_Share=1,
//	MSG_JNI_Task,
//	MSG_JNI_Start,
//	MSG_JNI_Recharge,
//};
//
////--game Scene
//enum
//{
//	SCENE_start=1,			//����
//	SCENE_game,
//	SCENE_endAgain
//};


namespace DDZtexture_name
{
	//����ͼƬ��Դ
	//const static char s_cardTable[] = "cardtable.png";
	const static char s_cardTable[] = "ddzCardtable.png";

	//	�������
	const static char s_ddzBGSummary[] = "ddz_popups_summary_bg_summary.png";						//	������桪������
	const static char s_ddzTextLose[] = "ddz_popups_summary_text_lose.png";							//	������桪����ʶ���֡���ʧ��
	const static char s_ddzTextWin[] = "ddz_popups_summary_text_win.png";							//	������桪����ʶ���֡���ʤ��
	const static char s_ddzTitleLose[] = "ddz_popups_summary_title_lose.png";						//	������桪�����⡪��ʧ��
	const static char s_ddzTitleWin[] = "ddz_popups_summary_title_win.png";							//	������桪�����⡪��ʤ��
	const static char s_ddzTitleSpring[] = "ddz_popups_summary_title_spring.png";					//	������桪�����⡪������
	const static char s_ddzPlayerLandlordMan[] = "ddz_popups_summary_player_landlord_man.png";		//	������桪�����⡪��������
	const static char s_ddzPlayerLandlordWoman[] = "ddz_popups_summary_player_landlord_woman.png";	//	������桪�����⡪������Ů
	const static char s_ddzPlayerPeasantMan[] = "ddz_popups_summary_player_peasant_man.png";		//	������桪�����⡪��ũ����
	const static char s_ddzPlayerPeasantWoman[] = "ddz_popups_summary_player_peasant_woman.png";	//	������桪�����⡪��ũ��Ů


	//	����
	const static char s_fntDDZGoldNum[] ="ddz_fnt_gold_num.fnt";	//	�������������塪���������
	const static char s_fntDDZTimeNum[] ="ddz_fnt_time_num.fnt";	//	�������������塪����ʱ������

	//	����
	const static char s_smallCardFront[] ="ddz_bg_small_card_front.png";//��������
	const static char s_card[] ="card.png";//�˿���
	const static char s_chatBarBg[] = "ddz_bg_chat.png";//����򱳾�
	const static char s_faceBg[] = "ddz_bg_face.png";//����򱳾�
	const static char s_menuBarBackground[] = "ddz_bg_menu.png";//�˵�������
	const static char s_background[]="ddz_bg_table.png";//������������
	const static char s_timer[] = "ddz_bg_time.png";//��ʱ�� pic
	const static char s_popups_bg[] = "ddz_bg_popups.png";//��������
	const static char s_chatBarBG[] = "ddz_bg_chat_bar.png";//�����


	const static char s_notify[] = "notify.png";//��Ϸ��������ʾ��Ϣ����
	const static char s_jiaBeiBar[] = "jbb_bj.png";//���Ƽӱ�������ʾ����ͼƬ
	const static char s_showSelf[] = "showself.png";//���㣬��ʾ�Լ���Ŀʱ��ĵ�ͼ
	const static char s_hintCard[] = "hintcard.png";//���ŵ��˿�ͼƬ
	const static char s_task_k[] = "task_k.png";//�����

	//	��ť
	const static char s_buJiaoNormal[] = "ddz_btn_bujiao_normal.png";								//	������������ť�������С�������
	const static char s_buJiaoPressed[] = "ddz_btn_bujiao_selected.png";							//	������������ť�������С�������
	const static char s_againNormal[] = "btn_again.png";											//	������������ť��������һ�֡�������
	const static char s_againPressed[] = "btn_again.png";											//	������������ť��������һ�֡�������
	const static char s_buqiangNormal[] = "ddz_btn_buqiang_normal.png";								//	������������ť����������������
	const static char s_buqiangPressed[] = "ddz_btn_buqiang_selected.png";							//	������������ť����������������
	const static char s_rechargeNormal[] = "ddz_btn_buy_normal.png";								//	������������ť������ֵ��������
	const static char s_rechargePressed[] = "ddz_btn_buy_selected.png";								//	������������ť������ֵ��������
	const static char s_btnCancelNormal[] = "ddz_btn_cancel_normal.png";							//	������������ť����ȡ����������
	const static char s_btnCancelPressed[] = "ddz_btn_cancel_selected.png";							//	������������ť����ȡ����������
	const static char s_changeTableNormal[] = "ddz_btn_change_table_normal.png";					//	������������ť����������������
	const static char s_changeTablePressed[] = "ddz_btn_change_table_selected.png";					//	������������ť����������������
	const static char s_detailNormal[] = "ddz_btn_detail_normal.png";								//	������������ť�����鿴������ϸ��������
	const static char s_detailPressed[] = "ddz_btn_detail_selected.png";							//	������������ť�����鿴������ϸ��������
	const static char s_menuPullTabFrontNormal[] = "ddz_btn_pull_tab_front_normal.png";				//	������������ť�����˵���������������
	const static char s_menuPullTabBackNormal[] = "ddz_btn_pull_tab_back_normal.png";				//	������������ť�����˵���������������
	const static char s_jiaoDiZhuNormal[] = "ddz_btn_jiaodizhu_normal.png";							//	������������ť�����е�����������
	const static char s_jiaoDiZhuPressed[] = "ddz_btn_jiaodizhu_selected.png";						//	������������ť�����е�����������
	const static char s_notRedoubleNormal[] = "ddz_btn_not_redouble_normal.png";					//	������������ť�������ӱ���������
	const static char s_notRedoublePressed[] = "ddz_btn_not_redouble_selected.png";					//	������������ť�������ӱ���������
	const static char s_btnOKNormal[] = "ddz_btn_ok_normal.png";									//	������������ť����ȷ����������
	const static char s_btnOKPressed[] = "ddz_btn_ok_selected.png";									//	������������ť����ȷ����������
	const static char s_openCardNormal[] = "ddz_btn_open_card_normal.png";							//	������������ť��������X2��������
	const static char s_openCardPressed[] = "ddz_btn_open_card_selected.png";						//	������������ť��������X2��������
	const static char s_openStartNormal[] = "ddz_btn_open_start_normal.png";						//	������������ť�������ƿ�ʼ��������
	const static char s_openStartPressed[] = "ddz_btn_open_start_selected.png";						//	������������ť�������ƿ�ʼ��������
	const static char s_outCardNormal[] = "ddz_btn_out_card_normal.png";							//	������������ť�������ơ�������
	const static char s_outCardPressed[] = "ddz_btn_out_card_selected.png";							//	������������ť�������ơ�������
	const static char s_passNormal[] = "ddz_btn_pass_normal.png";									//	������������ť�������ơ�������
	const static char s_passPressed[] = "ddz_btn_pass_selected.png";								//	������������ť�������ơ�������
	const static char s_qiangDiZhuNormal[] = "ddz_btn_qiangdizhu_normal.png";						//	������������ť������������������
	const static char s_qiangDiZhuPressed[] = "ddz_btn_qiangdizhu_selected.png";					//	������������ť������������������
	const static char s_redoubleNormal[] = "ddz_btn_redouble_normal.png";							//	������������ť�����ӱ���������
	const static char s_redoublePressed[] = "ddz_btn_redouble_selected.png";						//	������������ť�����ӱ���������
	const static char s_startNormal[] = "ddz_btn_start_normal.png";									//	������������ť������ʼ��Ϸ��������
	const static char s_startPressed[] = "ddz_btn_start_selected.png";								//	������������ť������ʼ��Ϸ��������
	const static char s_tipsNormal[] = "ddz_btn_tips_normal.png";									//	������������ť������ʾ��������
	const static char s_tipsPressed[] = "ddz_btn_tips_selected.png";								//	������������ť������ʾ��������
	const static char s_cancelRobotNormal[] = "ddz_btn_cancel_robot_normal.png";					//	������������ť����ȡ���йܡ�������
	const static char s_cancelRobotPressed[] = "ddz_btn_cancel_robot_selected.png";					//	������������ť����ȡ���йܡ�������

	const static char s_talk[] = "ddz_btn_chat_normal.png";//���찴ť
	const static char s_back[] = "ddz_btn_quit_normal.png";//���ذ�ť
	const static char s_robot[] = "ddz_btn_robot_normal.png";//�йܰ�ť
	const static char s_options[] = "ddz_btn_setting_normal.png";//���ð�ť
	const static char s_task[] = "ddz_btn_task_normal.png";//����ť

	//	����
	const static char s_text_multiple[] = "ddz_text_beishu.png";					//	�������������֡�������
	const static char s_text_difen[] = "ddz_text_difen.png";						//	�������������֡����׷�
	const static char s_diZhuTag[] = "dizhutag.png";								//	������ǩ

	const static char s_font_jiaodizhu[] = "ddz_img_text_jiaodizhu.png";			//	�е�����
	const static char s_font_qiangdizhu[] = "ddz_img_text_qiangdizhu.png";			//	��������
	const static char s_font_buqiang[] = "ddz_img_text_buqiang.png";				//	������
	const static char s_font_bujiao[] = "ddz_img_text_bujiao.png";					//	������
	const static char s_font_jiabei[] = "ddz_img_text_jiabei.png";					//	�ӱ���
	const static char s_font_pass[] = "ddz_img_text_pass.png";						//	������
	const static char s_font_visiblecard[] = "ddz_img_text_mingpai.png";			//	������
	const static char s_ctDoubleLine[] = "ddz_img_text_liandui.png";				//	����
	const static char s_ctSingleLine[] = "ddz_img_text_shunzi.png";					//	˳��
	const static char s_ctThreeLine[] = "ddz_img_text_sanshun.png";					//	��˳
	const static char s_ddz_img_text_ready[] = "ddz_img_text_ready.png";			//	׼��

	//	������
	const static char s_userMessage[] = "ddz_bg_player_data.png";//�û���Ϣ��
	const static char s_usericon[] = "manicon.png";//�����ͷ��pic
	const static char s_womanIcon[] = "womanicon.png";//Ů���ͷ��

	//	����


	//	old
	const static char s_one[] = "one.png";//����1 pic
	const static char s_two[] = "two.png";//2 pic
	const static char s_three[] = "three.png";//3 pic
	const static char s_four[] = "four.png";//4 pic
	const static char s_five[] = "five.png";//5 pic
	//const static char s_exchange[] = "btn_exchange.png";//�һ� btn
	const static char s_coinNumber[]= "coinnumber.png";//�����
	const static char s_coinNumber1[] = "coinnumber1.png";
	const static char s_twice[] = "twice.png";//����
	const static char s_thrice[] = "thrice.png";//����
	const static char s_fourfold[] = "fourfold.png";//�ı�
	const static char s_fivefold[] = "fivefold.png";//�屶
	const static char s_nonuple[] = "nonuple.png";//�ű�
	const static char s_sixfold[] = "sixfold.png";//����
	const static char s_jiaBeiTag[] = "jiabeitag.png";//����ʱ�ļӱ���־
	const static char s_music[] = "music.png";//��������ͼƬ
	const static char s_soundEffect[] = "soundeffect.png";//��ЧͼƬ
	const static char s_off[] = "off.png";//�ر���ͼƬ
	const static char s_on[] = "on.png";//������ͼƬ
	const static char s_on_off[] = "on_off.png";//����ͼƬ
	const static char s_progress_bj[] = "progressbar0.png";//����������
	const static char s_progress[] = "progressbar1.png";//������
	const static char s_expression[] = "expression.png";//��������
	const static char s_voice[] = "voice.png";//��������
	//����
	const static char s_faceCool[] = "face_0.png";//��
	const static char s_faceHan[] = "face_1.png";//��
	const static char s_faceHanlen[] = "face_2.png";//����
	const static char s_faceKu[] = "face_3.png";//��
	const static char s_faceNu[] = "face_4.png";//ŭ
	const static char s_faceNue[] = "face_5.png";//Ű
	const static char s_faceQiu[] = "face_6.png";//��
	const static char s_faceTu[] = "face_7.png";//��
	const static char s_faceXiao[] = "face_8.png";//Ц
	const static char s_faceYun[] = "face_9.png";//��

	//const static char s_xlt[] = "xlt.png";//������
	const static char s_yyk[] = "yyk.png";//������
	const static char s_banshou[] = "banshou.png";//�����˰���
	const static char s_eye[]= "eye.png";//�������۾�
	const static char s_robot_pic[] = "robot.png";//������ͼƬ
	const static char s_paiBei0[] = "paibei0.png";//�Ʊ�0
	const static char s_paiBei1[] = "paibei1.png";//�Ʊ�1
	const static char s_plane[] = "plane.png";//�ɻ�
	const static char s_lxj0[] = "lxj0.png";//������0
	const static char s_lxj1[] = "lxj1.png";//������1
	const static char s_planeyy[] = "planeyy.png";//�ɻ��������Ӱ
	const static char s_bomb[] = "bomb.png";//ը����
	const static char s_bomb0[] = "bomb0.png";//ը������0
	const static char s_bomb1[] = "bomb1.png";//ը������1
	const static char s_bomb2[] = "bomb2.png";//ը������2
	const static char s_bomb3[] = "bomb3.png";//ը������3
	const static char s_bomb4[] = "bomb4.png";//ը������4
	const static char s_bomb5[] = "bomb5.png";//ը������5
	const static char s_bomb6[] = "bomb6.png";//ը������6
	const static char s_bomb7[] = "bomb7.png";//ը������7
	const static char s_yanwu0[] = "yanwu0.png";//��������任����
	const static char s_yanwu1[] = "yanwu1.png";
	const static char s_yanwu2[] = "yanwu2.png";
	const static char s_yanwu3[] = "yanwu3.png";
	const static char s_yanwu4[] = "yanwu4.png";
	const static char s_dizhu_man[] = "dizhu_man.png";//�е���
	const static char s_farmer_man[] = "farmer_man.png";//��ũ��
	const static char s_dizhu_woman[] = "dizhu_woman.png";//Ů����
	const static char s_farmer_woman[] = "farmer_woman.png";//Ůũ��
	const static char s_huojian[] = "huojian.png";//���
	const static char s_huoyan[] = "huoyan.png";//����
	const static char s_yun0[] = "yun0.png";//�����
	const static char s_yun1[] = "yun1.png";
	const static char s_yun2[] = "yun2.png";
	const static char s_yun3[] = "yun3.png";
	const static char s_paizi[] = "paizi.png";//���˶�����ͼ
	const static char s_font_deng[] = "font_deng.png";//��
	const static char s_font_dai[] = "font_dai.png";//��
	const static char s_font_qi[] = "font_qi.png";//��
	const static char s_font_ta[] = "font_ta.png";//��
	const static char s_font_wan[] = "font_wan.png";//��
	const static char s_font_jia[] = "font_jia.png";//��
	const static char s_font_zhong[] = "font_zhong.png";//��
	const static char s_zawu[] = "zawu.png";//����
	const static char s_jingbao0[] = "jingbao0.png";//��������
	const static char s_jingbao1[] = "jingbao1.png";
	const static char s_jingbao2[] = "jingbao2.png";
	const static char s_jingbao3[] = "jingbao3.png";
	const static char s_jingbao4[] = "jingbao4.png";
	const static char s_jingbao5[] = "jingbao5.png";
	const static char s_loser[] = "loser.png";//ʧ�ܶ���
	const static char s_winner[] = "winner.png";//ʤ������
	const static char s_task_d[] = "task_d.png";//�������ֵ�

	//���Сͷ��
	const static char s_man_head_icon[] = "man_head_icon.png";
	const static char s_woman_head_icon[] = "woman_head_icon.png";
	const static char s_dizhuCardTag[] = "dizhucardtag.png";//�������һ�ſ�Ƭ���Ͻ�ͼ��

	const static char s_showCardTag[] = "showcardtag.png";//���Ʊ�־
	const static char s_difenTimesNum[] = "difentimesnum.png";//�׷ֱ�������
	//գ��ͼƬ
	const static char s_dz_m_eye0[] = "dz_m_eye0.png";//�е���գ��
	const static char s_dz_m_eye1[] = "dz_m_eye1.png";
	const static char s_dz_m_eye2[] = "dz_m_eye2.png";
	const static char s_dz_wm_eye0[] = "dz_wm_eye0.png";//Ů����գ��
	const static char s_dz_wm_eye1[] = "dz_wm_eye1.png";
	const static char s_dz_wm_eye2[] = "dz_wm_eye2.png";
	const static char s_fm_m_eye0[] = "fm_m_eye0.png";//��ũ��գ��
	const static char s_fm_m_eye1[] = "fm_m_eye1.png";
	const static char s_fm_m_eye2[] = "fm_m_eye2.png";
	const static char s_fm_wm_eye0[] = "fm_wm_eye0.png";//Ůũ��գ��
	const static char s_fm_wm_eye1[] = "fm_wm_eye1.png";
	const static char s_fm_wm_eye2[] = "fm_wm_eye2.png";
	const static char s_m_eye0[] = "m_eye0.png";//�к�գ��
	const static char s_m_eye1[] = "m_eye1.png";
	const static char s_m_eye2[] = "m_eye2.png";
	const static char s_wm_eye0[] = "wm_eye0.png";//Ů����գ��
	const static char s_wm_eye1[] = "wm_eye1.png";
	const static char s_wm_eye2[] = "wm_eye2.png";


	const static char s_back_fen0[] = "back_fen0.png";//����
	const static char s_back_fen1[] = "back_fen1.png";
	const static char s_back_fen2[] = "back_fen2.png";

	const static char s_card_color[] = "card_color.png";//�˿��ƻ�ɫ���ں췽÷��
	const static char s_card_num_black[] = "card_num_black.png";//�˿����ֺ�
	const static char s_card_num_red[] = "card_num_red.png";//�˿��ƺ�
	const static char s_joker[] = "joker.png";	//ͼƬ��СΪ pic
	//������Դ
	const static char s_font_back[] = "font_back.png";//����
	const static char s_font_chat[] = "font_chat.png";//����
	const static char s_font_robot[] = "font_robot.png";//�й�
	const static char s_font_setup[] = "font_setup.png";//����
	const static char s_font_task[] = "font_task.png";//����
	const static char s_bubble[] = "bubble.png";//����

	//�µĶ������˿���ͼƬ
	const static char s_ddz_poker_back[] = "ddz_poker_back.png";//�Ƶ�ͼ
	const static char s_ddz_poker_black[] = "ddz_poker_black.png";//С��
	const static char s_ddz_poker_lord_icon[] = "ddz_poker_lord_icon.png";//�����Ǳ�
	const static char s_ddz_poker_red[] = "ddz_poker_red.png";//����
	const static char s_ddz_pokers_color[] = "ddz_pokers_color.png";//�ƵĻ�ɫ
	const static char s_ddz_pokers_num[] = "ddz_pokers_num.png";//�Ƶ���ֵ
}
#endif
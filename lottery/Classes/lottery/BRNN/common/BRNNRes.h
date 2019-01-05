#ifndef __BRNN_RES_H__
#define __BRNN_RES_H__

/*
**	����ţţ����������Դ
*/
namespace BRNNTextureName
{
	const static char s_brnn_table_bg[] = "brnn_table_bg.png";												//	������������
	const static char s_brnn_settlement_bg[] = "brnn_settlement_bg.png";									//	���������������

	const static char s_brnn_chip_normal_1[] = "brnn_chip_normal_1.png";									//	���롪������������ֵ1
	const static char s_brnn_chip_normal_5[] = "brnn_chip_normal_5.png";									//	���롪������������ֵ5
	const static char s_brnn_chip_normal_10[] = "brnn_chip_normal_10.png";									//	���롪������������ֵ10
	const static char s_brnn_chip_normal_50[] = "brnn_chip_normal_50.png";									//	���롪������������ֵ50
	const static char s_brnn_chip_normal_100[] = "brnn_chip_normal_100.png";								//	���롪������������ֵ100
	const static char s_brnn_chip_normal_200[] = "brnn_chip_normal_200.png";								//	���롪������������ֵ200
	const static char s_brnn_chip_normal_500[] = "brnn_chip_normal_500.png";								//	���롪������������ֵ500
	const static char s_brnn_chip_normal_1k[] = "brnn_chip_normal_1k.png";									//	���롪������������ֵ1k

	const static char s_brnn_chip_disable_1[] = "brnn_chip_disable_1.png";									//	���롪��ʧЧ������ֵ1
	const static char s_brnn_chip_disable_5[] = "brnn_chip_disable_5.png";									//	���롪��ʧЧ������ֵ5
	const static char s_brnn_chip_disable_10[] = "brnn_chip_disable_10.png";								//	���롪��ʧЧ������ֵ10
	const static char s_brnn_chip_disable_50[] = "brnn_chip_disable_50.png";								//	���롪��ʧЧ������ֵ50
	const static char s_brnn_chip_disable_100[] = "brnn_chip_disable_100.png";								//	���롪��ʧЧ������ֵ100
	const static char s_brnn_chip_disable_200[] = "brnn_chip_disable_200.png";								//	���롪��ʧЧ������ֵ200
	const static char s_brnn_chip_disable_500[] = "brnn_chip_disable_500.png";								//	���롪��ʧЧ������ֵ500
	const static char s_brnn_chip_disable_1k[] = "brnn_chip_disable_1k.png";								//	���롪��ʧЧ������ֵ1k
	const static char s_brnn_chip_high_light[] = "brnn_chip_light.png";										//	���롪����ť���������⻷

	const static char s_brnn_apply_normal[] = "brnn_btn_apply_normal.png";									//	��ť����������ׯ��������
	const static char s_brnn_apply_selected[] = "brnn_btn_apply_normal.png";								//	��ť����������ׯ��������
	const static char s_brnn_cancel_normal[] = "brnn_btn_cancel_normal.png";								//	��ť����ȡ�����롪������
	const static char s_brnn_cancel_selected[] = "brnn_btn_cancel_normal.png";								//	��ť����ȡ�����롪������
	const static char s_brnn_down_normal[] = "brnn_btn_down_normal.png";									//	��ť������Ҫ��ׯ��������
	const static char s_brnn_down_selected[] = "brnn_btn_down_normal.png";									//	��ť������Ҫ��ׯ��������

	const static char s_brnn_apply_lsit_normal[] = "brnn_btn_apply_list_normal.png";						//	��ť������ׯ�б�������
	const static char s_brnn_apply_lsit_pressed[] = "brnn_btn_apply_list_selected.png";						//	��ť������ׯ�б�������
	const static char s_brnn_quit_normal[] = "brnn_btn_quit_normal.png";									//	��ť�����˳���������
	const static char s_brnn_quit_selected[] = "brnn_btn_quit_selected.png";								//	��ť�����˳���������
	const static char s_brnn_setting_normal[] = "brnn_setting_nomal.png";									//	��ť�������á�������
	const static char s_brnn_setting_selected[] = "brnn_setting_select.png";								//	��ť�������á�������
	const static char s_brnn_btn_travel_normal[] = "brnn_btn_travel_normal.png";							//	��ť����·����������
	const static char s_brnn_btn_travel_selected[] = "brnn_btn_travel_selected.png";						//	��ť����·����������

	const static char s_brnn_tips_idle_time[] = "brnn_tips_idle_time.png";									//	��ʾ�������ʱ��
	const static char s_brnn_tips_bet_time[] = "brnn_tips_bet_time.png";									//	��ʾ�����עʱ��
	const static char s_brnn_tips_open_card_time[] = "brnn_tips_open_card_time.png";						//	��ʾ�������ʱ��
	const static char s_brnn_tips_none_banker[] = "brnn_tips_none_banker.png";								//	��ʾ���������ׯ
	const static char s_brnn_tips_officeholding_banker[] = "brnn_tips_officeholding_banker.png";			//	��ʾ���������ׯ
	const static char s_brnn_tips_turn_banker[] = "brnn_tips_turn_banker.png";								//	��ʾ�����תׯ��
	const static char s_brnn_clock_bg[] = "brnn_clock_bg.png";												//	ͼ�ꡪ������
	const static char s_brnn_face_null[] = "brnn_face_null.png";											//	ͼ�ꡪ����
	const static char s_brnn_face_man[] = "brnn_face_man.png";												//	ͼ�ꡪ����ͷ��
	const static char s_brnn_face_woman[] = "brnn_face_woman.png";											//	ͼ�ꡪ��Ůͷ��

	const static char s_brnn_card_type_floor[] = "brnn_card_type_floor.png";								//	���͡�������
	const static char s_brnn_card_type_meiniu[] = "brnn_card_type_meiniu.png";								//	���͡���ûţ
	const static char s_brnn_card_type_niu1[] = "brnn_card_type_niu1.png";									//	���͡���ţ1
	const static char s_brnn_card_type_niu2[] = "brnn_card_type_niu2.png";									//	���͡���ţ2
	const static char s_brnn_card_type_niu3[] = "brnn_card_type_niu3.png";									//	���͡���ţ3
	const static char s_brnn_card_type_niu4[] = "brnn_card_type_niu4.png";									//	���͡���ţ4
	const static char s_brnn_card_type_niu5[] = "brnn_card_type_niu5.png";									//	���͡���ţ5
	const static char s_brnn_card_type_niu6[] = "brnn_card_type_niu6.png";									//	���͡���ţ6
	const static char s_brnn_card_type_niu7[] = "brnn_card_type_niu7.png";									//	���͡���ţ7
	const static char s_brnn_card_type_niu8[] = "brnn_card_type_niu8.png";									//	���͡���ţ8
	const static char s_brnn_card_type_niu9[] = "brnn_card_type_niu9.png";									//	���͡���ţ9
	const static char s_brnn_card_type_niuniu[] = "brnn_card_type_niuniu.png";								//	���͡���ţţ
	const static char s_brnn_card_type_silverniu[] = "brnn_card_type_silverniu.png";						//	���͡�����ţ���Ļ���
	const static char s_brnn_card_type_goldniu[] = "brnn_card_type_goldniu.png";							//	���͡�����ţ���廨��
	const static char s_brnn_card_type_bomb[] = "brnn_card_type_bomb.png";									//	���͡���ը��

	const static char s_brnn_bet_area_e[] = "brnn_bet_area_e.png";											//	��ע����顪����
	const static char s_brnn_bet_area_s[] = "brnn_bet_area_s.png";											//	��ע����顪����
	const static char s_brnn_bet_area_w[] = "brnn_bet_area_w.png";											//	��ע����顪����
	const static char s_brnn_bet_area_n[] = "brnn_bet_area_n.png";											//	��ע����顪����
	const static char s_brnn_bet_area_mask[] = "brnn_bet_area_mask.png";									//	��ע����顪����������
	const static char s_brnn_bet_area_self_value_floor[] = "brnn_bet_area_self_value_floor.png";			//	��ע����顪������ܸ�ע����

	//	���򡪡���ׯ�б�

	const static char s_brnn_apply_list_bg[] = "brnn_apply_list_bg.png";									//	��ׯ�б�������
	const static char s_brnn_dialog_apply_list_item_bg[] = "brnn_apply_list_item_bg.png";					//	��ׯ�б��������ͼ
	const static char s_brnn_dialog_apply_list_title_face[] = "brnn_apply_list_title_face.png";				//	��ׯ�б������⡪��ͷ��
	const static char s_brnn_dialog_apply_list_title_gold[] = "brnn_apply_list_title_gold.png";				//	��ׯ�б������⡪�����
	const static char s_brnn_dialog_apply_list_title_nickname[] = "brnn_apply_list_title_nickname.png";		//	��ׯ�б������⡪���ǳ�
	const static char s_brnn_dialog_apply_list_item_face_man[] = "brnn_apply_list_item_face_man.png";		//	��ׯ�б�����ͷ��
	const static char s_brnn_dialog_apply_list_item_face_woman[] = "brnn_apply_list_item_face_woman.png";	//	��ׯ�б���Ůͷ��

	//	���򡪡�·��

	const static char s_brnn_popup_travel_bg[] = "brnn_travel_bg.png";										//	·����������
	const static char s_brnn_popup_travel_item_bg[] = "brnn_travel_item_bg.png";							//	·�����������ͼ
	const static char s_brnn_popup_travel_icon_e[] = "brnn_travel_icon_e.png";								//	·��������
	const static char s_brnn_popup_travel_icon_s[] = "brnn_travel_icon_s.png";								//	·��������
	const static char s_brnn_popup_travel_icon_w[] = "brnn_travel_icon_w.png";								//	·��������
	const static char s_brnn_popup_travel_icon_n[] = "brnn_travel_icon_n.png";								//	·��������
	const static char s_brnn_popup_travel_icon_lose[] = "brnn_travel_icon_lose.png";						//	·��������
	const static char s_brnn_popup_travel_icon_win[] = "brnn_travel_icon_win.png";							//	·������Ӯ

	//	�˳���Ϸ����
	const static char s_brnn_popup_quit_bg[] = "brnn_dialog_quit_bg.png";									//	���������˳���Ϸ��������
	const static char s_brnn_btn_no_normal[] = "brnn_btn_no_normal.png";									//	��ť����ȡ����������
	const static char s_brnn_btn_no_selected[] = "brnn_btn_no_selected.png";								//	��ť����ȡ����������
	const static char s_brnn_btn_ok_normal[] = "brnn_btn_ok_normal.png";									//	��ť����ȷ����������
	const static char s_brnn_btn_ok_selected[] = "brnn_btn_ok_selected.png";								//	��ť����ȷ����������
	const static char s_brnn_btn_closed_normal[] = "brnn_btn_closed_normal.png";							//	��ť������š�������
	const static char s_brnn_btn_closed_selected[] = "brnn_btn_closed_selected.png";						//	��ť������š�������

	//	���ý���
	const static char s_brnn_setting_bg[] = "brnn_setting_bg.png";											//	���ý��桪������
	const static char s_brnn_setting_switch_mask[] = "brnn_setting_switch_mask.png";						//	���ý��桪�����ء������ֵ�ͼ
	const static char s_brnn_setting_switch_on[] = "brnn_setting_switch_on.png";							//	���ý��桪�����ء�����
	const static char s_brnn_setting_switch_off[] = "brnn_setting_switch_off.png";							//	���ý��桪�����ء�����
	const static char s_brnn_setting_switch_thumb[] = "brnn_setting_switch_thumb.png";						//	���ý��桪�����ء����ְ�

}

#endif	//	__BRNN_RES_H__
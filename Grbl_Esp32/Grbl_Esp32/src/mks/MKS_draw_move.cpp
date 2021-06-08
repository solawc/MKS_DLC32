#include "MKS_draw_move.h"

MKS_MOVE_PAGE move_page;
MKS_MOVE_CTRL_T ui_move_ctrl;

LV_IMG_DECLARE(back);
LV_IMG_DECLARE(Home);
LV_IMG_DECLARE(Positionting);
LV_IMG_DECLARE(Unlock);
LV_IMG_DECLARE(X_N);			
LV_IMG_DECLARE(X_P);			
LV_IMG_DECLARE(Y_N);			
LV_IMG_DECLARE(Y_P);			
LV_IMG_DECLARE(Hhome);		



static void event_henadle_pupup_com(lv_obj_t* obj, lv_event_t event) { 

	if (event == LV_EVENT_RELEASED) {
		set_click_status(true);
		common_popup_com_del();
	}
}

static void event_handler_x_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.move_dis == M_0_1_MM) {
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91X0.1F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X0.1F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X0.1F2000\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91X1.0F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X1.0F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X1.0F2000\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91X10F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X10F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X10F2000\n");
		}
	}
}

static void event_handler_x_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(mks_grbl.move_dis == M_0_1_MM) {
			// MKS_GRBL_CMD_SEND("$J=G91X-0.1F2000\n");
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91X-0.1F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-0.1F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-0.1F2000\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			// MKS_GRBL_CMD_SEND("$J=G91X-1.0F2000\n");
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91X-1.0F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-1.0F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-1.0F2000\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			// MKS_GRBL_CMD_SEND("$J=G91X-10.0F2000\n");
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91X-10F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-10F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-10F2000\n");
		}
	}
}

static void event_handler_y_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(mks_grbl.move_dis == M_0_1_MM) {
			// MKS_GRBL_CMD_SEND("$J=G91Y0.1F2000\n");
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91Y0.1F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y0.1F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y0.1F2000\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			// MKS_GRBL_CMD_SEND("$J=G91Y1.0F2000\n");
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91Y1.0F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y1.0F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y1.0F2000\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			// MKS_GRBL_CMD_SEND("$J=G91Y10.0F2000\n");
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91Y10F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y10F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y10F2000\n");
		}
	}
}

static void event_handler_y_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(mks_grbl.move_dis == M_0_1_MM) {
			// MKS_GRBL_CMD_SEND("$J=G91Y-0.1F2000\n");
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91Y-0.1F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-0.1F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-0.1F2000\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			// MKS_GRBL_CMD_SEND("$J=G91Y-1.0F2000\n");
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91Y-1.0F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-1.0F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-1.0F2000\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			// MKS_GRBL_CMD_SEND("$J=G91Y-10.0F2000\n");
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91Y-10F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-10F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-10F2000\n");
		}
	}
}

static void event_handler_len(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if (mks_grbl.move_dis == M_0_1_MM) {
			mks_grbl.move_dis = M_1_MM;
			lv_label_set_text(move_page.Label_len, "1mm");
		}else if(mks_grbl.move_dis == M_1_MM) {
			mks_grbl.move_dis = M_10_MM;
			lv_label_set_text(move_page.Label_len, "10mm");
		}else if(mks_grbl.move_dis == M_10_MM) {
			mks_grbl.move_dis = M_0_1_MM;
			lv_label_set_text(move_page.Label_len, "0.1mm");
		}
	}
}

static void event_handler_unlock(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        // mks_clear_move();
		// motors_set_disable(true);
		MKS_GRBL_CMD_SEND("$X\n");
		// draw_pos_popup("Unlock success");
		set_click_status(false);
		mks_draw_common_popup_info_com("Info", "Unlock success!", "", event_henadle_pupup_com);
	}
}

static void event_handler_home(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		// 保证激光不会打开
		MKS_GRBL_CMD_SEND("M5\n");
		mks_grbl.power_persen = P_0_PERSEN;

       	MKS_GRBL_CMD_SEND("$J=G90X0Y0F2000\n");
		// draw_pos_popup("Homing success");
		// draw_pos_popup_2("      Homing...");
		set_click_status(false);
		mks_draw_common_pupup_info("Info", "Homing...", " ");
		ui_move_ctrl.soft_homing_status = HOMING_START;
	}
}

static void event_handler_pos(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		
		set_click_status(false);
		if(sys.state == State::Idle && mks_get_motor_status() ) {
			MKS_GRBL_CMD_SEND("G92X0Y0Z0\n");
			// draw_pos_popup("Positioning success");
			mks_draw_common_popup_info_com("Info", "Positioning success", " ", event_henadle_pupup_com);
		}else {
			// draw_pos_popup("Please wait machine stop!");
			mks_draw_common_popup_info_com("Warring", "Please wait machine stop!", " ", event_henadle_pupup_com);
		}
	}
}

static void event_handler_hhome(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("M5\n");
		mks_grbl.power_persen = P_0_PERSEN;
		set_click_status(false);
		if(hard_limits->get()) {
			MKS_GRBL_CMD_SEND("$H\n");
			ui_move_ctrl.hard_homing_status = HOMING_START;
			// draw_pos_popup_2("Hard Homing...");
			mks_draw_common_pupup_info("Info", "Homing...", " ");
		}
		else {
			// draw_pos_popup_2("No Enable Hard Homing...");
			mks_draw_common_popup_info_com("Warring", "No Enable Hard Homing...", " ", event_henadle_pupup_com);
		}
	}
}

static void event_handler_len_set(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(mks_grbl.move_dis == M_0_1_MM) {
			mks_grbl.move_dis = M_1_MM;
			mks_lv_label_updata(move_page.label_len, "1mm");
		}else if(mks_grbl.move_dis == M_1_MM) {
			mks_grbl.move_dis = M_10_MM;
			mks_lv_label_updata(move_page.label_len, "10mm");
		}else if(mks_grbl.move_dis == M_10_MM) {
			mks_grbl.move_dis = M_0_1_MM;
			mks_lv_label_updata(move_page.label_len, "0.1mm");
		}
	}
}

static void event_handler_speed(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.move_speed == LOW_SPEED) {
			mks_grbl.move_speed = MID_SPEED;
			mks_lv_label_updata(move_page.label_speed, "Mid Speed");
		}else if(mks_grbl.move_speed == MID_SPEED) {
			mks_grbl.move_speed = HIGHT_SPEED;
			mks_lv_label_updata(move_page.label_speed, "High Speed");
		}else if(mks_grbl.move_speed == HIGHT_SPEED) {
			mks_grbl.move_speed = LOW_SPEED;
			mks_lv_label_updata(move_page.label_speed, "Low Speed");
		}
	}
}


static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_lv_clean_ui();
		mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_ready();
	}
}

void mks_draw_move(void) {
 
 #if defined(USE_RELASE)
	/* 背景层 */
	move_page.tool_scr = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(move_page.tool_scr, 460, 90);
    lv_obj_set_pos(move_page.tool_scr, 10, 10);

	move_page.move_scr = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(move_page.move_scr, 270, 200);
    lv_obj_set_pos(move_page.move_scr, 10, 110);

	move_page.dist_scr = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(move_page.dist_scr, 180, 200);
    lv_obj_set_pos(move_page.dist_scr, 290, 110);
#else 
	mks_global.mks_src_1 = lv_obj_create(mks_global.mks_src, NULL);
	lv_obj_set_size(mks_global.mks_src_1, 460, 90);
    lv_obj_set_pos(mks_global.mks_src_1, 10, 10);

	mks_global.mks_src_2 = lv_obj_create(mks_global.mks_src, NULL);
	lv_obj_set_size(mks_global.mks_src_2, 270, 200);
    lv_obj_set_pos(mks_global.mks_src_2, 10, 110);

	mks_global.mks_src_3 = lv_obj_create(mks_global.mks_src, NULL);
	lv_obj_set_size(mks_global.mks_src_3, 180, 200);
    lv_obj_set_pos(mks_global.mks_src_3, 290, 110);
#endif
	/* 背景层样式 */

#if defined(USE_RELASE)
	lv_style_copy(&move_page.mbk_color, &lv_style_scr);
    move_page.mbk_color.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    move_page.mbk_color.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    move_page.mbk_color.text.color = LV_COLOR_WHITE;
    move_page.mbk_color.body.radius = 17;
    lv_obj_set_style(move_page.move_scr, &move_page.mbk_color);
	lv_obj_set_style(move_page.dist_scr, &move_page.mbk_color);
	lv_obj_set_style(move_page.tool_scr, &move_page.mbk_color);
#else
	lv_obj_set_style(mks_global.mks_src_1, &mks_global.mks_src_1_style);
	lv_obj_set_style(mks_global.mks_src_2, &mks_global.mks_src_2_style);
	lv_obj_set_style(mks_global.mks_src_3, &mks_global.mks_src_3_style);
#endif

#if defined(USE_RELASE)
	move_page.Back = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.Back, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10 , event_handler_back);
    move_page.m_unlock = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.m_unlock, &Unlock, &Unlock, LV_ALIGN_CENTER, -10, -10, event_handler_unlock);
	move_page.home = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.home, &Home, &Home, LV_ALIGN_CENTER, 90, -10, event_handler_home);
	move_page.postivs = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.postivs, &Positionting, &Positionting, LV_ALIGN_CENTER, 190, -10, event_handler_pos);
	move_page.hhome = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.hhome, &Hhome, &Hhome, LV_ALIGN_CENTER, -110, -10, event_handler_hhome);

	lv_imgbtn_creat_mks(move_page.move_scr, move_page.x_n, &X_N, &X_N, LV_ALIGN_CENTER, 90, 0, event_handler_x_n);
    lv_imgbtn_creat_mks(move_page.move_scr, move_page.x_p, &X_P, &X_P, LV_ALIGN_CENTER, -90, 0, event_handler_x_p);
    lv_imgbtn_creat_mks(move_page.move_scr, move_page.y_n, &Y_N, &Y_N, LV_ALIGN_CENTER, 0, -50, event_handler_y_n);
    lv_imgbtn_creat_mks(move_page.move_scr, move_page.y_p, &Y_P, &Y_P, LV_ALIGN_CENTER, 0, 50, event_handler_y_p);
#else
	move_page.Back = lv_imgbtn_creat_mks(mks_global.mks_src_1, move_page.Back, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10 , event_handler_back);
    move_page.m_unlock = lv_imgbtn_creat_mks(mks_global.mks_src_1, move_page.m_unlock, &Unlock, &Unlock, LV_ALIGN_CENTER, -10, -10, event_handler_unlock);
	move_page.home = lv_imgbtn_creat_mks(mks_global.mks_src_1, move_page.home, &Home, &Home, LV_ALIGN_CENTER, 90, -10, event_handler_home);
	move_page.postivs = lv_imgbtn_creat_mks(mks_global.mks_src_1, move_page.postivs, &Positionting, &Positionting, LV_ALIGN_CENTER, 190, -10, event_handler_pos);
	move_page.hhome = lv_imgbtn_creat_mks(mks_global.mks_src_1, move_page.hhome, &Hhome, &Hhome, LV_ALIGN_CENTER, -110, -10, event_handler_hhome);

	lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.x_n, &X_N, &X_N, LV_ALIGN_CENTER, 90, 0, event_handler_x_n);
    lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.x_p, &X_P, &X_P, LV_ALIGN_CENTER, -90, 0, event_handler_x_p);
    lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.y_n, &Y_N, &Y_N, LV_ALIGN_CENTER, 0, -50, event_handler_y_n);
    lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.y_p, &Y_P, &Y_P, LV_ALIGN_CENTER, 0, 50, event_handler_y_p);
#endif

	/* 按键样式 */
	lv_style_copy(&move_page.btn_color, &lv_style_scr);
    move_page.btn_color.body.main_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    move_page.btn_color.body.grad_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    move_page.btn_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    move_page.btn_color.text.color = LV_COLOR_BLACK;
	move_page.btn_color.body.radius = 10;

	// move_page.btn_len = mks_lv_btn_set(move_page.dist_scr, move_page.btn_len, 120, 50, 40, 40, event_handler_len_set);
	// move_page.btn_speed = mks_lv_btn_set(move_page.dist_scr, move_page.btn_speed, 120, 50, 40, 130, event_handler_speed);

#if defined(USE_RELASE)
	move_page.btn_len = mks_lv_btn_set_for_screen(move_page.dist_scr, move_page.btn_len, 120, 50, 0, -40, event_handler_len_set);
	move_page.btn_speed = mks_lv_btn_set_for_screen(move_page.dist_scr, move_page.btn_speed, 120, 50, 0, 40, event_handler_speed);
#else 
	move_page.btn_len = mks_lv_btn_set_for_screen(mks_global.mks_src_3, move_page.btn_len, 120, 50, 0, -40, event_handler_len_set);
	move_page.btn_speed = mks_lv_btn_set_for_screen(mks_global.mks_src_3, move_page.btn_speed, 120, 50, 0, 40, event_handler_speed);
#endif

	lv_btn_set_style(move_page.btn_len, LV_BTN_STYLE_REL, &move_page.btn_color);
	lv_btn_set_style(move_page.btn_len, LV_BTN_STYLE_PR, &move_page.btn_color);

	lv_btn_set_style(move_page.btn_speed, LV_BTN_STYLE_REL, &move_page.btn_color);
	lv_btn_set_style(move_page.btn_speed,LV_BTN_STYLE_PR,&move_page.btn_color);
	
#if defined(USE_RELASE)
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_back, 17, 65, "Back", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_unlock, 196, 65, "Unlock", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_home, 300, 65, "Home", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_postivs, 390, 65, "Position", 100);
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_unlock, 100, 65, "HHome", 80);
#else
	mks_lvgl_long_sroll_label_with_wight_set_center(mks_global.mks_src_1, move_page.Label_back, 17, 65, "Back", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(mks_global.mks_src_1, move_page.Label_unlock, 196, 65, "Unlock", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(mks_global.mks_src_1, move_page.Label_home, 300, 65, "Home", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(mks_global.mks_src_1, move_page.Label_postivs, 390, 65, "Position", 100);
	mks_lvgl_long_sroll_label_with_wight_set_center(mks_global.mks_src_1, move_page.Label_unlock, 100, 65, "HHome", 80);
#endif


	if(mks_grbl.move_dis == M_0_1_MM) {
		move_page.label_len = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_len, move_page.label_len, 0, 0, "0.1mm", 50);
	}else if(mks_grbl.move_dis == M_1_MM) {
		move_page.label_len = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_len, move_page.label_len, 0, 0, "1mm", 50);
	}else if(mks_grbl.move_dis == M_10_MM) {
		move_page.label_len = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_len, move_page.label_len, 0, 0, "10mm", 50);
	}
	
	if(mks_grbl.move_speed == LOW_SPEED) {
		move_page.label_speed = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_speed, move_page.label_speed, 0, 0, "Low Speed", 100); //l:500, m:1000, h:2000
	}else if(mks_grbl.move_speed == MID_SPEED) {
		move_page.label_speed = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_speed, move_page.label_speed, 0, 0, "Mid Speed", 100);
	}else if(mks_grbl.move_speed == HIGHT_SPEED) {
		move_page.label_speed = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_speed, move_page.label_speed, 0, 0, "High Speed", 100);
	}	

	mks_ui_page.mks_ui_page = MKS_UI_Control;
    mks_ui_page.wait_count = DEFAULT_UI_COUNT;
}

void set_click_status(bool status) {
	lv_obj_set_click(move_page.Back, status);
	lv_obj_set_click(move_page.m_unlock, status);
	lv_obj_set_click(move_page.home, status);
	lv_obj_set_click(move_page.postivs, status);
	lv_obj_set_click(move_page.hhome, status);
}

lv_obj_t* move_popup_scr;
lv_style_t move_popup_color;
lv_style_t move_popup_btn_style;
lv_obj_t* move_popup_btn_sure;
lv_obj_t* move_popup_label_sure;
lv_obj_t* move_popup_label_dis;

static void event_handler_popup_sure(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		lv_obj_set_click(move_page.Back, true);
		lv_obj_set_click(move_page.m_unlock, true);
		lv_obj_set_click(move_page.home, true);
		lv_obj_set_click(move_page.postivs, true);
		lv_obj_set_click(move_page.hhome, true);
		lv_obj_del(move_popup_scr);
	}
}

static void event_handler_popup_sure_1(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		lv_obj_set_click(move_page.Back, true);
		lv_obj_set_click(move_page.m_unlock, true);
		lv_obj_set_click(move_page.home, true);
		lv_obj_set_click(move_page.postivs, true);
		lv_obj_set_click(move_page.hhome, true);
		lv_obj_del(move_popup_scr);
	}
}

void draw_pos_popup(const char *text) {

	lv_obj_set_click(move_page.Back, false);
	lv_obj_set_click(move_page.m_unlock, false);
	lv_obj_set_click(move_page.home, false);
	lv_obj_set_click(move_page.postivs, false);
	lv_obj_set_click(move_page.hhome, false);

	move_popup_scr = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(move_popup_scr, move_popup_size_x, move_popup_size_y);
    lv_obj_set_pos(move_popup_scr, move_popup_x, move_popup_y);

	lv_style_copy(&move_popup_color, &lv_style_scr);
	move_popup_color.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    move_popup_color.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    move_popup_color.text.color = LV_COLOR_BLACK;
    move_popup_color.body.radius = 17;
	lv_obj_set_style(move_popup_scr, &move_popup_color);

	lv_style_copy(&move_popup_btn_style, &lv_style_scr);
	move_popup_btn_style.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    move_popup_btn_style.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    move_popup_btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    move_popup_btn_style.text.color = LV_COLOR_WHITE;
	move_popup_btn_style.body.radius = 10;

	move_popup_btn_sure = mks_lv_btn_set(move_popup_scr, move_popup_btn_sure, move_popup_btn_size_x, move_popup_btn_size_y, move_popup_btn_x, move_popup_btn_y, event_handler_popup_sure);
	lv_btn_set_style(move_popup_btn_sure, LV_BTN_STYLE_REL, &move_popup_btn_style);
	lv_btn_set_style(move_popup_btn_sure,LV_BTN_STYLE_PR, &move_popup_btn_style);

	move_popup_label_dis = mks_lvgl_long_sroll_label_with_wight_set_center(move_popup_scr, move_popup_label_dis, 90, 50, text, 200);
	move_popup_label_sure = mks_lvgl_long_sroll_label_with_wight_set_center(move_popup_btn_sure, move_popup_label_sure, 50, 0, "Yes",50);
}

void draw_pos_popup_1(const char *text) {

	lv_obj_set_click(move_page.Back, false);
	lv_obj_set_click(move_page.m_unlock, false);
	lv_obj_set_click(move_page.home, false);
	lv_obj_set_click(move_page.postivs, false);
	lv_obj_set_click(move_page.hhome, false);

	move_popup_scr = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(move_popup_scr, move_popup_size_x, move_popup_size_y);
    lv_obj_set_pos(move_popup_scr, move_popup_x, move_popup_y);

	lv_style_copy(&move_popup_color, &lv_style_scr);
	move_popup_color.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    move_popup_color.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    move_popup_color.text.color = LV_COLOR_BLACK;
    move_popup_color.body.radius = 17;
	lv_obj_set_style(move_popup_scr, &move_popup_color);

	lv_style_copy(&move_popup_btn_style, &lv_style_scr);
	move_popup_btn_style.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    move_popup_btn_style.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    move_popup_btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    move_popup_btn_style.text.color = LV_COLOR_WHITE;
	move_popup_btn_style.body.radius = 10;

	move_popup_btn_sure = mks_lv_btn_set(move_popup_scr, 
										move_popup_btn_sure, 
										move_popup_btn_size_x, 
										move_popup_btn_size_y, 
										move_popup_btn_x,
										 move_popup_btn_y, 
										 event_handler_popup_sure_1);
	lv_btn_set_style(move_popup_btn_sure, LV_BTN_STYLE_REL, &move_popup_btn_style);
	lv_btn_set_style(move_popup_btn_sure,LV_BTN_STYLE_PR, &move_popup_btn_style);

	move_popup_label_dis = mks_lvgl_long_sroll_label_with_wight_set_center(move_popup_scr, move_popup_label_dis, 100, 50, text, 200);
	move_popup_label_sure = mks_lvgl_long_sroll_label_with_wight_set_center(move_popup_btn_sure, move_popup_label_sure, 50, 0, "Yes",50);
}


void draw_pos_popup_2(const char *text) {
	lv_obj_set_click(move_page.Back, false);
	lv_obj_set_click(move_page.m_unlock, false);
	lv_obj_set_click(move_page.home, false);
	lv_obj_set_click(move_page.postivs, false);
	lv_obj_set_click(move_page.hhome, false);

	move_popup_scr = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(move_popup_scr, move_popup_size_x, move_popup_size_y);
    lv_obj_set_pos(move_popup_scr, move_popup_x, move_popup_y);

	lv_style_copy(&move_popup_color, &lv_style_scr);
	move_popup_color.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    move_popup_color.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    move_popup_color.text.color = LV_COLOR_BLACK;
    move_popup_color.body.radius = 17;
	lv_obj_set_style(move_popup_scr, &move_popup_color);
	move_popup_label_dis = mks_lvgl_long_sroll_label_with_wight_set_center(move_popup_scr, move_popup_label_dis, 100, 50, text, 200);
}




void hard_home_check(void) {
	switch(ui_move_ctrl.hard_homing_status) {

		case HOMING_NONE:
			
		break;

		case HOMING_START:
			if(sys.state == State::Homing) 		ui_move_ctrl.hard_homing_status = HOMING_RUNNING;
			else if(sys.state == State::Idle)	ui_move_ctrl.hard_homing_status = HOMING_SUCCEED;
			else if(sys.state == State::Alarm)	ui_move_ctrl.hard_homing_status = HOMING_FAIL;
			else								ui_move_ctrl.hard_homing_status = HOMING_FAIL;
		break;

		case HOMING_RUNNING:
			if(sys.state == State::Idle) 		ui_move_ctrl.hard_homing_status = HOMING_SUCCEED;
			else if(sys.state == State::Alarm)	ui_move_ctrl.hard_homing_status = HOMING_FAIL;
			else if(sys.state == State::Homing)	ui_move_ctrl.hard_homing_status = HOMING_RUNNING;
			else 								ui_move_ctrl.hard_homing_status = HOMING_FAIL;
		break;

		case HOMING_SUCCEED:
			ui_move_ctrl.hard_homing_status = HOMING_NONE;
			// lv_obj_del(move_popup_scr);
			// draw_pos_popup_1("Homing succeed!");
			common_pupup_info_del();
			mks_draw_common_popup_info_com("Info", "Homing succeed!", " ", event_henadle_pupup_com);
		break;

		case HOMING_FAIL:
			ui_move_ctrl.hard_homing_status = HOMING_NONE;
			// lv_obj_del(move_popup_scr);
			// draw_pos_popup_1("Homing fail,please unlock!");
			common_pupup_info_del();
			mks_draw_common_popup_info_com("Info", "Homing fail", "please unlock!", event_henadle_pupup_com);
		break;
	}
}

void soft_home_check(void) { 

	switch(ui_move_ctrl.soft_homing_status) {

		case HOMING_NONE:

		break;

		case HOMING_START:
			if(sys.state == State::Jog) 		ui_move_ctrl.soft_homing_status = HOMING_RUNNING;
			else if(sys.state == State::Idle)	ui_move_ctrl.soft_homing_status = HOMING_SUCCEED;
			else if(sys.state == State::Alarm)	ui_move_ctrl.soft_homing_status = HOMING_FAIL;
			else 								ui_move_ctrl.soft_homing_status = HOMING_FAIL;
		break;

		case HOMING_RUNNING:
			if(sys.state == State::Idle)		ui_move_ctrl.soft_homing_status = HOMING_SUCCEED;
			else if(sys.state == State::Alarm)	ui_move_ctrl.soft_homing_status = HOMING_FAIL;
			else if(sys.state == State::Jog)	ui_move_ctrl.soft_homing_status = HOMING_RUNNING;
			else 								ui_move_ctrl.soft_homing_status = HOMING_FAIL;
		break;

		case HOMING_SUCCEED:
			// lv_obj_del(move_popup_scr);
			
			ui_move_ctrl.soft_homing_status = HOMING_NONE;
			
			common_pupup_info_del();
			// draw_pos_popup_1("Homing success!");
			mks_draw_common_popup_info_com("Info", "Homing succeed!", " ", event_henadle_pupup_com);
		break;

		case HOMING_FAIL:
			// lv_obj_del(move_popup_scr);
			ui_move_ctrl.soft_homing_status = HOMING_NONE;
			common_pupup_info_del();
			// draw_pos_popup_1("Homing fail");
			mks_draw_common_popup_info_com("Info", "Homing fail", " ", event_henadle_pupup_com);
		break;
	}
}

bool mks_get_motor_status(void) { 
	return stepper_idle;
}

void mks_clear_move(void) {
	lv_obj_clean(mks_src);
}





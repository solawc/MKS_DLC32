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

static void event_handler_x_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X0.1F1000\n");
		
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X1.0F1000\n");
		
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X10.0F1000\n");
		}
	}
}

static void event_handler_x_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X-0.1F1000\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X-1.0F1000\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X-10.0F1000\n");
		}
	}
}

static void event_handler_y_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y0.1F1000\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y1.0F1000\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y10.0F1000\n");
		}
	}
}

static void event_handler_y_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y-0.1F1000\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y-1.0F1000\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y-10.0F1000\n");
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
		draw_pos_popup("Unlock success");
	}
}

static void event_handler_home(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
       MKS_GRBL_CMD_SEND("$J=G90X0Y0F1600\n");
		// draw_pos_popup("Homing success");
		draw_pos_popup_2("      Homing...");
		ui_move_ctrl.soft_homing_status = HOMING_START;
	}
}

static void event_handler_pos(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
    	MKS_GRBL_CMD_SEND("G92X0Y0Z0\n");
		draw_pos_popup("Positioning success");
	}
}

static void event_handler_hhome(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
    	// MKS_GRBL_CMD_SEND("$X\n");
		MKS_GRBL_CMD_SEND("$H\n");
		ui_move_ctrl.hard_homing_status = HOMING_START;
		draw_pos_popup_2("Hard Homing...");
	}
}

static void event_handler_dis_0_1(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_grbl.move_dis = M_0_1_MM;

		lv_label_set_text(move_page.label_len_0_1, "#000000 0.1mm#");
		lv_label_set_text(move_page.label_len_1, "#ffffff 1mm#");
		lv_label_set_text(move_page.label_len_10, "#ffffff 10mm#");
	}
}

static void event_handler_dis_1(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_grbl.move_dis = M_1_MM;
		lv_label_set_text(move_page.label_len_1, "#000000 1mm#");
		lv_label_set_text(move_page.label_len_0_1, "#ffffff 0.1mm#");
		lv_label_set_text(move_page.label_len_10, "#ffffff 10mm#");
	}
}

static void event_handler_dis_10(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		mks_grbl.move_dis = M_10_MM;

		lv_label_set_text(move_page.label_len_10, "#000000 10mm#");
		lv_label_set_text(move_page.label_len_0_1, "#ffffff 0.1mm#");
		lv_label_set_text(move_page.label_len_1, "#ffffff 1mm#");
	}
}


static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_clear_move();
		mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_ready();
	}
}

void mks_draw_move(void) {
 
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

	mks_ui_page.mks_ui_page = MKS_UI_Control;
    mks_ui_page.wait_count = DEFAULT_UI_COUNT;

	/* 背景层样式 */
	lv_style_copy(&move_page.mbk_color, &lv_style_scr);
    move_page.mbk_color.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    move_page.mbk_color.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    move_page.mbk_color.text.color = LV_COLOR_WHITE;
    move_page.mbk_color.body.radius = 17;
    lv_obj_set_style(move_page.move_scr, &move_page.mbk_color);
	lv_obj_set_style(move_page.dist_scr, &move_page.mbk_color);
	lv_obj_set_style(move_page.tool_scr, &move_page.mbk_color);

	move_page.Back = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.Back, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10 , event_handler_back);
    move_page.m_unlock = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.m_unlock, &Unlock, &Unlock, LV_ALIGN_CENTER, -10, -10, event_handler_unlock);
	move_page.home = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.home, &Home, &Home, LV_ALIGN_CENTER, 90, -10, event_handler_home);
	move_page.postivs = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.postivs, &Positionting, &Positionting, LV_ALIGN_CENTER, 190, -10, event_handler_pos);
	move_page.hhome = lv_imgbtn_creat_mks(move_page.tool_scr, move_page.hhome, &Hhome, &Hhome, LV_ALIGN_CENTER, -110, -10, event_handler_hhome);

	lv_imgbtn_creat_mks(move_page.move_scr, move_page.x_n, &X_N, &X_N, LV_ALIGN_CENTER, 90, 0, event_handler_x_n);
    lv_imgbtn_creat_mks(move_page.move_scr, move_page.x_p, &X_P, &X_P, LV_ALIGN_CENTER, -90, 0, event_handler_x_p);
    lv_imgbtn_creat_mks(move_page.move_scr, move_page.y_n, &Y_N, &Y_N, LV_ALIGN_CENTER, 0, -50, event_handler_y_n);
    lv_imgbtn_creat_mks(move_page.move_scr, move_page.y_p, &Y_P, &Y_P, LV_ALIGN_CENTER, 0, 50, event_handler_y_p);

	/* 按键样式 */
	lv_style_copy(&move_page.btn_color, &lv_style_scr);
    move_page.btn_color.body.main_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    move_page.btn_color.body.grad_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    move_page.btn_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    move_page.btn_color.text.color = LV_COLOR_BLACK;
	move_page.btn_color.body.radius = 10;

	/* 按键创建 */
	move_page.btn_len_0_1 = mks_lv_btn_set(move_page.dist_scr, move_page.btn_len_0_1, 80, 40, 50, 20, event_handler_dis_0_1);
	move_page.btn_len_1 = mks_lv_btn_set(move_page.dist_scr, move_page.btn_len_1, 80, 40, 50, 80, event_handler_dis_1);
	move_page.btn_len_10 = mks_lv_btn_set(move_page.dist_scr, move_page.btn_len_10, 80, 40, 50, 140, event_handler_dis_10);

	lv_btn_set_style(move_page.btn_len_0_1, LV_BTN_STYLE_REL, &move_page.btn_color);
	lv_btn_set_style(move_page.btn_len_0_1,LV_BTN_STYLE_PR,&move_page.btn_color);
	lv_btn_set_style(move_page.btn_len_1, LV_BTN_STYLE_REL, &move_page.btn_color);
	lv_btn_set_style(move_page.btn_len_1,LV_BTN_STYLE_PR,&move_page.btn_color);
	lv_btn_set_style(move_page.btn_len_10, LV_BTN_STYLE_REL, &move_page.btn_color);
	lv_btn_set_style(move_page.btn_len_10,LV_BTN_STYLE_PR,&move_page.btn_color);
	
	
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_back, 17, 65, "Back", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_unlock, 196, 65, "Unlock", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_home, 300, 65, "Home", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_postivs, 390, 65, "Position", 100);
	mks_lvgl_long_sroll_label_with_wight_set_center(move_page.tool_scr, move_page.Label_unlock, 100, 65, "HHome", 80);

	if(mks_grbl.move_dis == M_0_1_MM) 
		move_page.label_len_0_1 = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_len_0_1, move_page.label_len_0_1, 0, 0, "#000000 0.1mm#", 50);
	else 
		move_page.label_len_0_1 = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_len_0_1, move_page.label_len_0_1, 0, 0, "#ffffff 0.1mm#", 50);

	if(mks_grbl.move_dis == M_1_MM) 
		move_page.label_len_1 = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_len_1, move_page.label_len_1, 0, 0, "#000000 1mm#", 50);
	else 
		move_page.label_len_1 = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_len_1, move_page.label_len_1, 0, 0, "#ffffff 1mm#", 50);

	if(mks_grbl.move_dis == M_10_MM) 
		move_page.label_len_10 = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_len_10, move_page.label_len_10, 0, 0, "#000000 10mm#", 50);
	else 
		move_page.label_len_10 = mks_lvgl_long_sroll_label_with_wight_set_center(move_page.btn_len_10, move_page.label_len_10, 0, 0, "#ffffff 10mm#", 50);

	mks_ui_page.mks_ui_page = MKS_UI_Control;
    mks_ui_page.wait_count = DEFAULT_UI_COUNT;
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

	move_popup_label_dis = mks_lvgl_long_sroll_label_with_wight_set_center(move_popup_scr, move_popup_label_dis, 100, 50, text, 200);
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
	move_popup_label_sure = mks_lvgl_long_sroll_label_with_wight_set_center(move_popup_btn_sure, move_popup_label_sure, 50, 0, "YES",50);
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
			lv_obj_del(move_popup_scr);
			draw_pos_popup_1("Homing succeed!");
		break;

		case HOMING_FAIL:
			ui_move_ctrl.hard_homing_status = HOMING_NONE;
			lv_obj_del(move_popup_scr);
			draw_pos_popup_1("Homing fail,please unlock!");
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
			lv_obj_del(move_popup_scr);
			ui_move_ctrl.soft_homing_status = HOMING_NONE;
			draw_pos_popup_1("Homing success!");
			
		break;

		case HOMING_FAIL:
			lv_obj_del(move_popup_scr);
			ui_move_ctrl.soft_homing_status = HOMING_NONE;
			draw_pos_popup_1("Homing fail");
			
		break;
	}

}



void mks_clear_move(void) {
	lv_obj_clean(mks_src);
}





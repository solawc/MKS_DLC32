#include "MKS_draw_move.h"


/* Screan Build */
lv_obj_t* move_scr;
lv_obj_t* dist_scr;
lv_obj_t* tool_scr;

lv_style_t mbk_color;
lv_style_t btn_color;

/* imgbtn */
lv_obj_t* x_n;			//+
lv_obj_t* x_p;			//-
lv_obj_t* y_n;			//+
lv_obj_t* y_p;			//-

lv_obj_t* m_unlock;
lv_obj_t* postivs;
lv_obj_t* home;

lv_obj_t* btn_len_0_1;
lv_obj_t* btn_len_1;
lv_obj_t* btn_len_10;

lv_obj_t* len;
static lv_obj_t* Back;
/* Label */

lv_obj_t* Label_len;
lv_obj_t* Label_back;
lv_obj_t* Label_unlock;
lv_obj_t* Label_postivs;
lv_obj_t* Label_home;

lv_obj_t* label_len_0_1;
lv_obj_t* label_len_1;
lv_obj_t* label_len_10;

LV_IMG_DECLARE(back);
LV_IMG_DECLARE(Home);
LV_IMG_DECLARE(Positionting);
LV_IMG_DECLARE(Unlock);
LV_IMG_DECLARE(X_N);			//先申明此图片
LV_IMG_DECLARE(X_P);			//先申明此图片
LV_IMG_DECLARE(Y_N);			//先申明此图片
LV_IMG_DECLARE(Y_P);			//先申明此图片

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
		//MKS_GRBL_CMD_SEND((uint8_t *)"$J=G91X-10.0F300\n");

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
		// MKS_GRBL_CMD_SEND("$J=G91Y10.0F300\n");

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

// static void event_handler_z_n(lv_obj_t* obj, lv_event_t event) {

// 	if (event == LV_EVENT_RELEASED) {
// 		if(mks_grbl.move_dis == M_0_1_MM) {
// 			MKS_GRBL_CMD_SEND("$J=G91Z0.1F1000\n");
// 		}
// 		else if (mks_grbl.move_dis == M_1_MM) {
// 			MKS_GRBL_CMD_SEND("$J=G91Z1.0F1000\n");
// 		}
// 		else if (mks_grbl.move_dis == M_10_MM) {
// 			MKS_GRBL_CMD_SEND("$J=G91Z10.0F1000\n");
// 		}
// 	}
// }

// static void event_handler_z_p(lv_obj_t* obj, lv_event_t event) {

// 	if (event == LV_EVENT_RELEASED) {
// 		if(mks_grbl.move_dis == M_0_1_MM) {
// 			MKS_GRBL_CMD_SEND("$J=G91Z-0.1F1000\n");
// 		}
// 		else if (mks_grbl.move_dis == M_1_MM) {
// 			MKS_GRBL_CMD_SEND("$J=G91Z-1.0F1000\n");
// 		}
// 		else if (mks_grbl.move_dis == M_10_MM) {
// 			MKS_GRBL_CMD_SEND("$J=G91Z-10.0F1000\n");
// 		}
// 	}
// }

static void event_handler_len(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if (mks_grbl.move_dis == M_0_1_MM) {
			//len = lv_imgbtn_creat_mks(scr, len, &Len_0_1mm, &Len_0_1mm, LV_ALIGN_CENTER, 180, -70, event_handler_len);
			mks_grbl.move_dis = M_1_MM;
			lv_label_set_text(Label_len, "1mm");
		}else if(mks_grbl.move_dis == M_1_MM) {
			//len = lv_imgbtn_creat_mks(scr, len, &Len_1mm, &Len_1mm, LV_ALIGN_CENTER, 180, -70, event_handler_len);
			mks_grbl.move_dis = M_10_MM;
			lv_label_set_text(Label_len, "10mm");
		}else if(mks_grbl.move_dis == M_10_MM) {
			//len = lv_imgbtn_creat_mks(scr, len, &Len_10mm, &Len_10mm, LV_ALIGN_CENTER, 180, -70, event_handler_len);
			mks_grbl.move_dis = M_0_1_MM;
			lv_label_set_text(Label_len, "0.1mm");
		}
	}
}

static void event_handler_unlock(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        // mks_clear_move();
	}
}

static void event_handler_home(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
       MKS_GRBL_CMD_SEND("$J=G90X0Y0F346\n");
	}
}

static void event_handler_pos(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
       	Serial.printf("G92 X0 Y0 Z0\n");
    	MKS_GRBL_CMD_SEND("G92 X0 Y0 Z0\n");
        // mks_draw_pos_pupop();
	}
}

static void event_handler_dis_0_1(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_clear_move();
        mks_draw_ready();
	}
}

void mks_draw_move(void) {
 
	mks_src = lv_obj_create(NULL, NULL);
	mks_src = lv_scr_act();

	/* 背景层 */
	tool_scr = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(tool_scr, 460, 90);
    lv_obj_set_pos(tool_scr, 10, 10);

	move_scr = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(move_scr, 270, 200);
    lv_obj_set_pos(move_scr, 10, 110);

	dist_scr = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(dist_scr, 180, 200);
    lv_obj_set_pos(dist_scr, 290, 110);

	/* 背景层样式 */
	lv_style_copy(&mbk_color, &lv_style_scr);
    mbk_color.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    mbk_color.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    mbk_color.text.color = LV_COLOR_WHITE;
    mbk_color.body.radius = 17;
    lv_obj_set_style(move_scr, &mbk_color);
	lv_obj_set_style(dist_scr, &mbk_color);
	lv_obj_set_style(tool_scr, &mbk_color);

	

	lv_imgbtn_creat_mks(tool_scr, Back, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10 , event_handler_back);
    lv_imgbtn_creat_mks(tool_scr, m_unlock, &Unlock, &Unlock, LV_ALIGN_CENTER, -10, -10, event_handler_unlock);
	lv_imgbtn_creat_mks(tool_scr, home, &Home, &Home, LV_ALIGN_CENTER, 90, -10, event_handler_home);
	lv_imgbtn_creat_mks(tool_scr, postivs, &Positionting, &Positionting, LV_ALIGN_CENTER, 190, -10, event_handler_pos);

	lv_imgbtn_creat_mks(move_scr, x_n, &X_N, &X_N, LV_ALIGN_CENTER, 0, -50, event_handler_x_n);
    lv_imgbtn_creat_mks(move_scr, x_p, &X_P, &X_P, LV_ALIGN_CENTER, 0, 50, event_handler_x_p);
    lv_imgbtn_creat_mks(move_scr, y_n, &Y_N, &Y_N, LV_ALIGN_CENTER, 90, 0, event_handler_y_n);
    lv_imgbtn_creat_mks(move_scr, y_p, &Y_P, &Y_P, LV_ALIGN_CENTER, -90, 0, event_handler_y_p);

	/* 按键样式 */
	lv_style_copy(&btn_color, &lv_style_scr);
    btn_color.body.main_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    btn_color.body.grad_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    btn_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_color.text.color = LV_COLOR_WHITE;
	btn_color.body.radius = 10;

	/* 按键创建 */
	btn_len_0_1 = mks_lv_btn_set(dist_scr, btn_len_0_1, 80, 40, 50, 20, event_handler_dis_0_1);
	btn_len_1 = mks_lv_btn_set(dist_scr, btn_len_1, 80, 40, 50, 80, event_handler_dis_0_1);
	btn_len_10 = mks_lv_btn_set(dist_scr, btn_len_10, 80, 40, 50, 140, event_handler_dis_0_1);

	lv_btn_set_style(btn_len_0_1, LV_BTN_STYLE_REL, &btn_color);
    lv_btn_set_style(btn_len_0_1,LV_BTN_STYLE_PR,&btn_color);
	lv_btn_set_style(btn_len_1, LV_BTN_STYLE_REL, &btn_color);
    lv_btn_set_style(btn_len_1,LV_BTN_STYLE_PR,&btn_color);
	lv_btn_set_style(btn_len_10, LV_BTN_STYLE_REL, &btn_color);
    lv_btn_set_style(btn_len_10,LV_BTN_STYLE_PR,&btn_color);

	mks_lvgl_long_sroll_label_with_wight_set_center(tool_scr, Label_back, 17, 65, "Back", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(tool_scr, Label_unlock, 196, 65, "Unlock", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(tool_scr, Label_home, 300, 65, "Home", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(tool_scr, Label_postivs, 390, 65, "Position", 100);

	mks_lvgl_long_sroll_label_with_wight_set_center(btn_len_0_1, label_len_0_1, 0, 0, "0.1mm", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(btn_len_1, label_len_1, 0, 0, "1mm", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(btn_len_10, label_len_10, 0, 0, "10mm", 50);
}

void mks_clear_move(void) {
	lv_obj_clean(mks_src);
}





#include "MKS_draw_inFile.h"

inFILE_PAGE_T infile_page;

LV_IMG_DECLARE(X_N);			
LV_IMG_DECLARE(X_P);			
LV_IMG_DECLARE(Y_N);			
LV_IMG_DECLARE(Y_P);
LV_IMG_DECLARE(back);

LV_IMG_DECLARE(png_infile_cave);
LV_IMG_DECLARE(png_infile_pos);
LV_IMG_DECLARE(png_infile_frame);

	
LV_IMG_DECLARE(png_m_up);
LV_IMG_DECLARE(png_m_right);		
LV_IMG_DECLARE(png_m_left);		
LV_IMG_DECLARE(png_m_down);

LV_IMG_DECLARE(png_infile_pos_pre);
LV_IMG_DECLARE(png_infile_frame_pre);
LV_IMG_DECLARE(png_infile_cave_pre);

static void event_handler_cancle(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
#if defined(USR_RELASE)
		lv_obj_clean(mks_src);
#else 
		lv_obj_clean(mks_global.mks_src);
#endif
		mks_draw_ready();
	}
}


static void event_handler_frame_yes(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		lv_obj_clean(mks_global.mks_src);
		mks_draw_frame();
		// lv_refr_now(lv_refr_get_disp_refreshing());
		// mks_run_frame(frame_ctrl.file_name);
	}
}

static void event_handler_frame_no(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		
		global_popup_del();
	}

}

static void event_handler_frame(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		// uint32_t file_size = mks_file_list.file_size[mks_file_list.file_choose];   
		mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;

		// if(file_size >= 1024*1024) {
		if(frame_ctrl.file_size >= 1024*1024) {
			mks_draw_common_popup("Warning", "File is more than 1M", "Do you want to continue?", event_handler_frame_yes, event_handler_frame_no);
		}else {
			frame_ctrl.is_use_same_file = false;
			lv_obj_clean(mks_global.mks_src);
			mks_draw_frame();
		}
	}
}

static void event_handler_sure(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
#if defined(USR_RELASE)
		lv_obj_clean(mks_src);
#else 
		lv_obj_clean(mks_global.mks_src);
#endif
		start_print();
	}
}

static void event_handler_x_n(lv_obj_t* obj, lv_event_t event){

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
		// MKS_GRBL_CMD_SEND("$J=G91X10F1000\n");
	}
}

static void event_handler_x_p(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.move_dis == M_0_1_MM) {
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91X-0.1F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-0.1F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-0.1F2000\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91X-1.0F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-1.0F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-1.0F2000\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91X-10F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-10F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91X-10F2000\n");
		}
		// MKS_GRBL_CMD_SEND("$J=G91X-10F1000\n");
	}
}

static void event_handler_y_n(lv_obj_t* obj, lv_event_t event){

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
		// MKS_GRBL_CMD_SEND("$J=G91Y10F1000\n");
	}
}

static void event_handler_y_p(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.move_dis == M_0_1_MM) {
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91Y-0.1F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-0.1F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-0.1F2000\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91Y-1.0F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-1.0F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-1.0F2000\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			if(mks_grbl.move_speed == LOW_SPEED) MKS_GRBL_CMD_SEND("$J=G91Y-10F500\n");
			else if(mks_grbl.move_speed == MID_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-10F1000\n");
			else if(mks_grbl.move_speed == HIGHT_SPEED)	MKS_GRBL_CMD_SEND("$J=G91Y-10F2000\n");
		}
		// MKS_GRBL_CMD_SEND("$J=G91Y-10F1000\n");
	}
}

static void event_handler_com_info(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {
		common_popup_com_del();
	}
}

static void event_handler_pos(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
 
		if(sys.state == State::Idle && mks_get_motor_status() ) {
			MKS_GRBL_CMD_SEND("G92X0Y0Z0\n");
			mks_draw_common_popup_info_com("Info", " ", "Positioning success", event_handler_com_info);

		}else {
			mks_draw_common_popup_info_com("Info", " ", "Please wait machine stop!", event_handler_com_info);
		}
	}
}

static void event_handler_move_set(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {

		infile_clean_obj(mks_global.mks_src_3);
		mks_draw_setting();

	}
}

static void event_handler_carve_set(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {
		infile_clean_obj(mks_global.mks_src_3);
		mks_draw_freaure();
	}
}


void mks_draw_inFile(char *fn) {

	/* 背景层 */
	mks_global.mks_src_1 = lv_obj_create(mks_global.mks_src, NULL);
	lv_obj_set_size(mks_global.mks_src_1, 460, 90);
    lv_obj_set_pos(mks_global.mks_src_1, 10, 10);

	mks_global.mks_src_2 = lv_obj_create(mks_global.mks_src, NULL);
	lv_obj_set_size(mks_global.mks_src_2, 270, 200);
    lv_obj_set_pos(mks_global.mks_src_2, 10, 110);


	lv_obj_set_style(mks_global.mks_src_1, &mks_global.mks_src_1_style);
	lv_obj_set_style(mks_global.mks_src_2, &mks_global.mks_src_2_style);

	lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.x_n, &png_m_right, &X_N, LV_ALIGN_CENTER, 90, 0, event_handler_x_n);  
    lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.x_p, &png_m_left, &X_P, LV_ALIGN_CENTER, -90, 0, event_handler_x_p);
    lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.y_n, &png_m_up, &Y_N, LV_ALIGN_CENTER, 0, -50, event_handler_y_n);
    lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.y_p, &png_m_down, &Y_P, LV_ALIGN_CENTER, 0, 50, event_handler_y_p);

	infile_page.btn_pos = lv_imgbtn_creat_mks(mks_global.mks_src_1, infile_page.btn_pos, &png_infile_pos_pre, &png_infile_pos, LV_ALIGN_CENTER, 90,-15, event_handler_pos);
	infile_page.btn_frame = lv_imgbtn_creat_mks(mks_global.mks_src_1, infile_page.btn_frame, &png_infile_frame_pre, &png_infile_frame, LV_ALIGN_CENTER, 0,-15, event_handler_frame);	
	infile_page.btn_sure_print = lv_imgbtn_creat_mks(mks_global.mks_src_1, infile_page.btn_sure_print, &png_infile_cave_pre, &png_infile_cave, LV_ALIGN_CENTER, 180,-15, event_handler_sure);

	/* 按键样式 */
	lv_style_copy(&infile_page.btn_color, &lv_style_scr);
    infile_page.btn_color.body.main_color = LV_COLOR_MAKE(0x3f, 0x47, 0x66);
    infile_page.btn_color.body.grad_color = LV_COLOR_MAKE(0x3f, 0x47, 0x66);
    infile_page.btn_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    infile_page.btn_color.text.color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
	infile_page.btn_color.body.radius = 10;

	lv_style_copy(&infile_page.btn_press_color, &lv_style_scr);
    infile_page.btn_press_color.body.main_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    infile_page.btn_press_color.body.grad_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    infile_page.btn_press_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    infile_page.btn_press_color.text.color = LV_COLOR_BLACK;
	infile_page.btn_press_color.body.radius = 10;

	infile_page.btn_cancle = lv_imgbtn_creat_mks(mks_global.mks_src_1, 
									infile_page.btn_cancle, 
									&back, 
									&back, 
									LV_ALIGN_IN_LEFT_MID,
									10, 
									-15 , 
									event_handler_cancle);
	mks_draw_setting();
	
	//	记录文件名
	memset(frame_ctrl.file_name, 0, sizeof(frame_ctrl.file_name));
	memcpy(frame_ctrl.file_name, fn, 128);
	//	记录文件大小
	frame_ctrl.file_size = mks_file_list.file_size[mks_file_list.file_choose]; 

	// 显示label
	if(fn[0] == '/') fn[0] = ' ';
	label_for_imgbtn_name(mks_global.mks_src_1, infile_page.label_cancle, infile_page.btn_cancle, 0, 0, "Cancel");
	label_for_imgbtn_name(mks_global.mks_src_1, infile_page.label_sure_print, infile_page.btn_sure_print, 0, 0, "Cavre");
	label_for_imgbtn_name(mks_global.mks_src_1, infile_page.label_pos, infile_page.btn_pos, 0, 0, "Position");
	label_for_imgbtn_name(mks_global.mks_src_1, infile_page.label_frame, infile_page.btn_frame, 0, 0, "Frame");
	// label_for_screen(mks_global.mks_src_1, infile_page.label_file_name, -100, 0, fn);




	label_for_infile_name(mks_global.mks_src_1, infile_page.label_file_name, -100, 0, fn);
	mks_ui_page.mks_ui_page = MKS_UI_inFile;
}


static void event_handler_len_set(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {
		if (mks_grbl.move_dis == M_0_1_MM) {
			mks_grbl.move_dis = M_1_MM;
			lv_label_set_text(infile_page.label_len, "1mm");
		}else if(mks_grbl.move_dis == M_1_MM) {
			mks_grbl.move_dis = M_10_MM;
			lv_label_set_text(infile_page.label_len, "10mm");
		}else if(mks_grbl.move_dis == M_10_MM) {
			mks_grbl.move_dis = M_0_1_MM;
			lv_label_set_text(infile_page.label_len, "0.1mm");
		}
	}
}

static void event_handler_speed(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.move_speed == LOW_SPEED) {
			mks_grbl.move_speed = MID_SPEED;
			mks_lv_label_updata(infile_page.label_speed, "Mid Speed");
		}else if(mks_grbl.move_speed == MID_SPEED) {
			mks_grbl.move_speed = HIGHT_SPEED;
			mks_lv_label_updata(infile_page.label_speed, "High Speed");
		}else if(mks_grbl.move_speed == HIGHT_SPEED) {
			mks_grbl.move_speed = LOW_SPEED;
			mks_lv_label_updata(infile_page.label_speed, "Low Speed");
		}
	}
}

void mks_draw_setting(void) {

	mks_global.mks_src_3 = lv_obj_create(mks_global.mks_src, NULL);
	lv_obj_set_size(mks_global.mks_src_3, 180, 200);
    lv_obj_set_pos(mks_global.mks_src_3, 290, 110);
	lv_obj_set_style(mks_global.mks_src_3, &mks_global.mks_src_3_style);

	infile_page.btn_len = mks_lv_btn_set_for_screen(mks_global.mks_src_3, infile_page.btn_len, 120, 50, 0, -40, event_handler_len_set);
	infile_page.btn_speed = mks_lv_btn_set_for_screen(mks_global.mks_src_3, infile_page.btn_speed, 120, 50, 0, 40, event_handler_speed);
	
	lv_btn_set_style(infile_page.btn_len, LV_BTN_STYLE_REL, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_len, LV_BTN_STYLE_PR, &infile_page.btn_press_color);  

	lv_btn_set_style(infile_page.btn_speed, LV_BTN_STYLE_REL, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_speed, LV_BTN_STYLE_PR, &infile_page.btn_press_color);

	if(mks_grbl.move_dis == M_0_1_MM) {
		infile_page.label_len = label_for_btn_name(infile_page.btn_len, infile_page.label_len, 0, 0, "0.1mm");
	}else if(mks_grbl.move_dis == M_1_MM) {
		infile_page.label_len = label_for_btn_name(infile_page.btn_len, infile_page.label_len, 0, 0, "1mm");
	}else if(mks_grbl.move_dis == M_10_MM) {
		infile_page.label_len = label_for_btn_name(infile_page.btn_len, infile_page.label_len, 0, 0, "10mm");
	}

	if(mks_grbl.move_speed == LOW_SPEED) {
		infile_page.label_speed = label_for_btn_name(infile_page.btn_speed, infile_page.label_speed, 0, 0, "Low Speed"); //l:500, m:1000, h:2000
	}else if(mks_grbl.move_speed == MID_SPEED) {
		infile_page.label_speed = label_for_btn_name(infile_page.btn_speed, infile_page.label_speed, 0, 0, "Mid Speed");
	}else if(mks_grbl.move_speed == HIGHT_SPEED) {
		infile_page.label_speed = label_for_btn_name(infile_page.btn_speed, infile_page.label_speed, 0, 0, "High Speed");
	}	
}

void mks_draw_freaure(void) {

	mks_global.mks_src_3 = lv_obj_create(mks_global.mks_src, NULL);
	lv_obj_set_size(mks_global.mks_src_3, 180, 200);
    lv_obj_set_pos(mks_global.mks_src_3, 290, 110);
	lv_obj_set_style(mks_global.mks_src_3, &mks_global.mks_src_3_style);
	
	// infile_page.btn_pos = mks_lv_btn_set(mks_global.mks_src_3, 
	// 								infile_page.btn_pos, 
	// 								inFILE_BTN_SIZE_X, 
	// 								inFILE_BTN_SIZE_Y, 
	// 								inFILE_BTN_X, 
	// 								inFILE_BTN_Y, 
	// 								event_handler_pos);  
	
	// infile_page.btn_frame = mks_lv_btn_set(mks_global.mks_src_3, 
	// 								infile_page.btn_frame, 
	// 								inFILE_BTN_SIZE_X, 
	// 								inFILE_BTN_SIZE_Y, 
	// 								inFILE_BTN_X, 
	// 								inFILE_BTN_Y + inFILE_BTN_Y_OFFSET*1, 
	// 								event_handler_frame);
	
	// infile_page.btn_sure_print = mks_lv_btn_set(mks_global.mks_src_3, 
	// 								infile_page.btn_sure_print, 
	// 								inFILE_BTN_SIZE_X, 
	// 								inFILE_BTN_SIZE_Y, 
	// 								inFILE_BTN_X, 
	// 								inFILE_BTN_Y + inFILE_BTN_Y_OFFSET*2, 
	// 								event_handler_sure);

	// label_for_btn_name(infile_page.btn_frame, infile_page.label_frame, 0, 0, "Frame");
	// label_for_btn_name(infile_page.btn_sure_print, infile_page.label_cancle, 0, 0, "Crave");
	// label_for_btn_name(infile_page.btn_pos, infile_page.label_cancle, 0, 0, "Postive");

	// lv_btn_set_style(infile_page.btn_frame, LV_BTN_STYLE_PR, &infile_page.btn_color);
	// lv_btn_set_style(infile_page.btn_frame, LV_BTN_STYLE_REL, &infile_page.btn_color);

	// lv_btn_set_style(infile_page.btn_sure_print, LV_BTN_STYLE_PR, &infile_page.btn_color);
	// lv_btn_set_style(infile_page.btn_sure_print, LV_BTN_STYLE_REL, &infile_page.btn_color);

	// lv_btn_set_style(infile_page.btn_pos, LV_BTN_STYLE_PR, &infile_page.btn_color);
	// lv_btn_set_style(infile_page.btn_pos, LV_BTN_STYLE_REL, &infile_page.btn_color);
}

void infile_clean_obj(lv_obj_t *obj_src) {

	lv_obj_clean(obj_src);
}



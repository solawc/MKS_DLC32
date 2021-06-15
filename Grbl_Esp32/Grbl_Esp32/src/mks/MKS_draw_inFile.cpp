#include "MKS_draw_inFile.h"

inFILE_PAGE_T infile_page;



LV_IMG_DECLARE(X_N);			
LV_IMG_DECLARE(X_P);			
LV_IMG_DECLARE(Y_N);			
LV_IMG_DECLARE(Y_P);
LV_IMG_DECLARE(back);

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

static void event_handler_frame(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
#if defined(USR_RELASE)
		lv_obj_clean(mks_src);
#else 
		lv_obj_clean(mks_global.mks_src);
#endif
		mks_draw_frame();
		lv_refr_now(lv_refr_get_disp_refreshing());
		mks_run_frame(frame_ctrl.file_name);
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
		MKS_GRBL_CMD_SEND("$J=G91X10F1000\n");
	}
}

static void event_handler_x_p(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("$J=G91X-10F1000\n");
	}
}

static void event_handler_y_n(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("$J=G91Y10F1000\n");
	}
}

static void event_handler_y_p(lv_obj_t* obj, lv_event_t event){

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("$J=G91Y-10F1000\n");
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

#if defined(USE_RELASE)
	/* 背景层 */
	infile_page.inFile_src1 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(infile_page.inFile_src1, 460, 90);
    lv_obj_set_pos(infile_page.inFile_src1, 10, 10);

	infile_page.inFile_src2 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(infile_page.inFile_src2, 270, 200);
    lv_obj_set_pos(infile_page.inFile_src2, 10, 110);

	infile_page.inFile_src3 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(infile_page.inFile_src3, 180, 200);
    lv_obj_set_pos(infile_page.inFile_src3, 290, 110);
#else 
	/* 背景层 */
	mks_global.mks_src_1 = lv_obj_create(mks_global.mks_src, NULL);
	lv_obj_set_size(mks_global.mks_src_1, 460, 90);
    lv_obj_set_pos(mks_global.mks_src_1, 10, 10);

	mks_global.mks_src_2 = lv_obj_create(mks_global.mks_src, NULL);
	lv_obj_set_size(mks_global.mks_src_2, 270, 200);
    lv_obj_set_pos(mks_global.mks_src_2, 10, 110);

#endif

#if defined(USE_RELASE)

	lv_style_copy(&infile_page.src_color, &lv_style_scr);
    infile_page.src_color.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    infile_page.src_color.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    infile_page.src_color.text.color = LV_COLOR_WHITE;
    infile_page.src_color.body.radius = 17;

    lv_obj_set_style(infile_page.inFile_src1, &infile_page.src_color);
	lv_obj_set_style(infile_page.inFile_src2, &infile_page.src_color);
	lv_obj_set_style(infile_page.inFile_src3, &infile_page.src_color);
#else 
	lv_obj_set_style(mks_global.mks_src_1, &mks_global.mks_src_1_style);
	lv_obj_set_style(mks_global.mks_src_2, &mks_global.mks_src_2_style);
#endif

	lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.x_n, &X_N, &X_N, LV_ALIGN_CENTER, 90, 0, event_handler_x_n);
    lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.x_p, &X_P, &X_P, LV_ALIGN_CENTER, -90, 0, event_handler_x_p);
    lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.y_n, &Y_N, &Y_N, LV_ALIGN_CENTER, 0, -50, event_handler_y_n);
    lv_imgbtn_creat_mks(mks_global.mks_src_2, move_page.y_p, &Y_P, &Y_P, LV_ALIGN_CENTER, 0, 50, event_handler_y_p);

	/* 按键样式 */
	lv_style_copy(&infile_page.btn_color, &lv_style_scr);
    infile_page.btn_color.body.main_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    infile_page.btn_color.body.grad_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    infile_page.btn_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    infile_page.btn_color.text.color = LV_COLOR_BLACK;
	infile_page.btn_color.body.radius = 10;

	infile_page.btn_cancle = lv_imgbtn_creat_mks(mks_global.mks_src_1, 
									infile_page.btn_cancle, 
									&back, 
									&back, 
									LV_ALIGN_IN_LEFT_MID,
									10, 
									-10 , 
									event_handler_cancle);
	
	infile_page.btn_set_move = mks_lv_btn_set_for_screen(mks_global.mks_src_2, infile_page.btn_set_move, 50, 50, -80, 70, event_handler_move_set);
	infile_page.btn_set_carve = mks_lv_btn_set_for_screen(mks_global.mks_src_2, infile_page.btn_set_carve, 50, 50, 80, 70, event_handler_carve_set);
	lv_btn_set_style(infile_page.btn_set_move, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_set_move, LV_BTN_STYLE_REL, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_set_carve, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_set_carve, LV_BTN_STYLE_REL, &infile_page.btn_color);
	mks_draw_freaure();
	
	
	
	memset(frame_ctrl.file_name, 0, sizeof(frame_ctrl.file_name));
	memcpy(frame_ctrl.file_name, fn, 128);

	if(fn[0] == '/') fn[0] = ' ';
	label_for_imgbtn_name(mks_global.mks_src_1, infile_page.label_cancle, infile_page.btn_cancle, 0, 0, "Cancel");
	label_for_btn_name(infile_page.btn_set_move, infile_page.label_frame, 0, 0, "M");
	label_for_btn_name(infile_page.btn_set_carve, infile_page.label_frame, 0, 0, "C");
	label_for_screen(mks_global.mks_src_1, infile_page.label_file_name, 0, 0, fn);

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
	
	lv_btn_set_style(infile_page.btn_len, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_len, LV_BTN_STYLE_REL, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_speed, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_speed, LV_BTN_STYLE_REL, &infile_page.btn_color);

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

	infile_page.btn_pos = mks_lv_btn_set(mks_global.mks_src_3, 
									infile_page.btn_pos, 
									inFILE_BTN_SIZE_X, 
									inFILE_BTN_SIZE_Y, 
									inFILE_BTN_X, 
									inFILE_BTN_Y, 
									event_handler_pos);  
	
	infile_page.btn_frame = mks_lv_btn_set(mks_global.mks_src_3, 
									infile_page.btn_frame, 
									inFILE_BTN_SIZE_X, 
									inFILE_BTN_SIZE_Y, 
									inFILE_BTN_X, 
									inFILE_BTN_Y + inFILE_BTN_Y_OFFSET*1, 
									event_handler_frame);
	
	infile_page.btn_sure_print = mks_lv_btn_set(mks_global.mks_src_3, 
									infile_page.btn_sure_print, 
									inFILE_BTN_SIZE_X, 
									inFILE_BTN_SIZE_Y, 
									inFILE_BTN_X, 
									inFILE_BTN_Y + inFILE_BTN_Y_OFFSET*2, 
									event_handler_sure);

	label_for_btn_name(infile_page.btn_frame, infile_page.label_frame, 0, 0, "Frame");
	label_for_btn_name(infile_page.btn_sure_print, infile_page.label_cancle, 0, 0, "Crave");
	label_for_btn_name(infile_page.btn_pos, infile_page.label_cancle, 0, 0, "Postive");

	lv_btn_set_style(infile_page.btn_frame, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_frame, LV_BTN_STYLE_REL, &infile_page.btn_color);

	lv_btn_set_style(infile_page.btn_sure_print, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_sure_print, LV_BTN_STYLE_REL, &infile_page.btn_color);

	lv_btn_set_style(infile_page.btn_pos, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_pos, LV_BTN_STYLE_REL, &infile_page.btn_color);
}

void infile_clean_obj(lv_obj_t *obj_src) {

	lv_obj_clean(obj_src);
}



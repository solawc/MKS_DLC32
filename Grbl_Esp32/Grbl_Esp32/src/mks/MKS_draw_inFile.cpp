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
		lv_obj_clean(mks_src);
		mks_draw_ready();
	}
}

static void event_handler_frame(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
		lv_obj_clean(mks_src);
		mks_draw_frame();
		lv_refr_now(lv_refr_get_disp_refreshing());
		mks_run_frame(frame_ctrl.file_name);
	}
}

static void event_handler_sure(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
		lv_obj_clean(mks_src);
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

static void event_handler_pos(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
 
		if(sys.state == State::Idle && mks_get_motor_status() ) {
			MKS_GRBL_CMD_SEND("G92X0Y0Z0\n");
			draw_pos_popup("Positioning success");
		}else {
			draw_pos_popup("Please wait machine stop!");
		}
	}
}



void mks_draw_inFile(char *fn) {


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

	lv_style_copy(&infile_page.src_color, &lv_style_scr);
    infile_page.src_color.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    infile_page.src_color.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    infile_page.src_color.text.color = LV_COLOR_WHITE;
    infile_page.src_color.body.radius = 17;
    lv_obj_set_style(infile_page.inFile_src1, &infile_page.src_color);
	lv_obj_set_style(infile_page.inFile_src2, &infile_page.src_color);
	lv_obj_set_style(infile_page.inFile_src3, &infile_page.src_color);

	lv_imgbtn_creat_mks(infile_page.inFile_src2, move_page.x_n, &X_N, &X_N, LV_ALIGN_CENTER, 90, 0, event_handler_x_n);
    lv_imgbtn_creat_mks(infile_page.inFile_src2, move_page.x_p, &X_P, &X_P, LV_ALIGN_CENTER, -90, 0, event_handler_x_p);
    lv_imgbtn_creat_mks(infile_page.inFile_src2, move_page.y_n, &Y_N, &Y_N, LV_ALIGN_CENTER, 0, -50, event_handler_y_n);
    lv_imgbtn_creat_mks(infile_page.inFile_src2, move_page.y_p, &Y_P, &Y_P, LV_ALIGN_CENTER, 0, 50, event_handler_y_p);

	/* 按键样式 */
	lv_style_copy(&infile_page.btn_color, &lv_style_scr);
    infile_page.btn_color.body.main_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    infile_page.btn_color.body.grad_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    infile_page.btn_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    infile_page.btn_color.text.color = LV_COLOR_BLACK;
	infile_page.btn_color.body.radius = 10;


	// infile_page.btn_cancle = mks_lv_btn_set(infile_page.inFile_src, infile_page.btn_cancle, inFILE_BTN_SIZE_X, inFILE_BTN_SIZE_Y, inFILE_BTN_X+inFILE_BTN_OFFSET*2, inFILE_BTN_Y, event_handler_cancle);
	infile_page.btn_cancle = lv_imgbtn_creat_mks(infile_page.inFile_src1, 
									infile_page.btn_cancle, 
									&back, 
									&back, 
									LV_ALIGN_IN_LEFT_MID,
									10, 
									-10 , 
									event_handler_cancle);

	infile_page.btn_pos = mks_lv_btn_set(infile_page.inFile_src3, 
									infile_page.btn_pos, 
									inFILE_BTN_SIZE_X, 
									inFILE_BTN_SIZE_Y, 
									inFILE_BTN_X, 
									inFILE_BTN_Y, 
									event_handler_pos);  
	
	infile_page.btn_frame = mks_lv_btn_set(infile_page.inFile_src3, 
									infile_page.btn_frame, 
									inFILE_BTN_SIZE_X, 
									inFILE_BTN_SIZE_Y, 
									inFILE_BTN_X, 
									inFILE_BTN_Y + inFILE_BTN_Y_OFFSET*1, 
									event_handler_frame);
	
	infile_page.btn_sure_print = mks_lv_btn_set(infile_page.inFile_src3, 
									infile_page.btn_sure_print, 
									inFILE_BTN_SIZE_X, 
									inFILE_BTN_SIZE_Y, 
									inFILE_BTN_X, 
									inFILE_BTN_Y + inFILE_BTN_Y_OFFSET*2, 
									event_handler_sure);
	

	lv_btn_set_style(infile_page.btn_frame, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_frame, LV_BTN_STYLE_REL, &infile_page.btn_color);

	lv_btn_set_style(infile_page.btn_sure_print, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_sure_print, LV_BTN_STYLE_REL, &infile_page.btn_color);

	lv_btn_set_style(infile_page.btn_pos, LV_BTN_STYLE_PR, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_pos, LV_BTN_STYLE_REL, &infile_page.btn_color);
	
	memset(frame_ctrl.file_name, 0, sizeof(frame_ctrl.file_name));
	memcpy(frame_ctrl.file_name, fn, 128);

	if(fn[0] == '/') fn[0] = ' ';

	mks_lvgl_long_sroll_label_with_wight_set_center(infile_page.inFile_src1, infile_page.label_cancle, 10, 50, "Cancel", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(infile_page.btn_frame, infile_page.label_frame, 0, 0, "Frame", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(infile_page.btn_sure_print, infile_page.label_cancle, 0, 0, "Crave", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(infile_page.btn_pos, infile_page.label_cancle, 0, 0, "Postive", 50);
	// mks_lvgl_long_sroll_label_with_wight_set_center(infile_page.inFile_src1, infile_page.label_file_name, 200, 30, fn, 256);
	label_for_screen(infile_page.inFile_src1, infile_page.label_file_name, 0, 0, fn);

	mks_ui_page.mks_ui_page = MKS_UI_inFile;
}




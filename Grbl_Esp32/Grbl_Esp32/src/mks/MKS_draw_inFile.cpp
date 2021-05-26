#include "MKS_draw_inFile.h"

inFILE_PAGE_T infile_page;




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



void mks_draw_inFile(char *fn) {

	infile_page.inFile_src = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(infile_page.inFile_src, inFILE_SRC_SIZE_X, inFILE_SRC_SIZE_Y);
    lv_obj_set_pos(infile_page.inFile_src, inFILE_SRC_X, inFILE_SRC_Y);

	lv_style_copy(&infile_page.src_color, &lv_style_scr);
    infile_page.src_color.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    infile_page.src_color.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    infile_page.src_color.text.color = LV_COLOR_WHITE;
    infile_page.src_color.body.radius = 17;
	lv_obj_set_style(infile_page.inFile_src, &infile_page.src_color);

	/* 按键样式 */
	lv_style_copy(&infile_page.btn_color, &lv_style_scr);
    infile_page.btn_color.body.main_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    infile_page.btn_color.body.grad_color = LV_COLOR_MAKE(0x5C, 0xE6, 0x93);
    infile_page.btn_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    infile_page.btn_color.text.color = LV_COLOR_BLACK;
	infile_page.btn_color.body.radius = 10;


		infile_page.btn_cancle = mks_lv_btn_set(infile_page.inFile_src, infile_page.btn_cancle, inFILE_BTN_SIZE_X, inFILE_BTN_SIZE_Y, inFILE_BTN_X+inFILE_BTN_OFFSET*2, inFILE_BTN_Y, event_handler_cancle);
			infile_page.btn_sure_print = mks_lv_btn_set(infile_page.inFile_src, infile_page.btn_sure_print, inFILE_BTN_SIZE_X, inFILE_BTN_SIZE_Y, inFILE_BTN_X, inFILE_BTN_Y, event_handler_sure);
	// infile_page.btn_cancle = mks_lv_btn_set(infile_page.inFile_src, infile_page.btn_cancle, inFILE_BTN_SIZE_X, inFILE_BTN_SIZE_Y, inFILE_BTN_X, inFILE_BTN_Y, event_handler_cancle);
	infile_page.btn_frame = mks_lv_btn_set(infile_page.inFile_src, infile_page.btn_frame, inFILE_BTN_SIZE_X, inFILE_BTN_SIZE_Y, inFILE_BTN_X+inFILE_BTN_OFFSET, inFILE_BTN_Y, event_handler_frame);
	// infile_page.btn_sure_print = mks_lv_btn_set(infile_page.inFile_src, infile_page.btn_sure_print, inFILE_BTN_SIZE_X, inFILE_BTN_SIZE_Y, inFILE_BTN_X+inFILE_BTN_OFFSET*2, inFILE_BTN_Y, event_handler_sure);

	lv_btn_set_style(infile_page.btn_cancle, LV_BTN_STYLE_REL, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_frame, LV_BTN_STYLE_REL, &infile_page.btn_color);
	lv_btn_set_style(infile_page.btn_sure_print, LV_BTN_STYLE_REL, &infile_page.btn_color);
	

	memset(frame_ctrl.file_name, 0, sizeof(frame_ctrl.file_name));
	memcpy(frame_ctrl.file_name, fn, 128);

	if(fn[0] == '/') fn[0] = ' ';

	mks_lvgl_long_sroll_label_with_wight_set_center(infile_page.btn_cancle, infile_page.label_cancle, 17, 65, "Cancel", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(infile_page.btn_frame, infile_page.label_frame, 17, 65, "Frame", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(infile_page.btn_sure_print, infile_page.label_cancle, 17, 65, "Yes", 50);
	mks_lvgl_long_sroll_label_with_wight_set_center(infile_page.inFile_src, infile_page.label_file_name, 150, 65, fn, 256);

	mks_ui_page.mks_ui_page = MKS_UI_inFile;
}




#include "MKS_draw_about.h"

/* Screan Build */
// static lv_obj_t* scr;

/* imgbtn */
lv_obj_t* about_btn_back;

/* Label */
lv_obj_t* Label_board_version;
lv_obj_t* Label_Firmware_version;
static lv_obj_t* Label_back;


// LV_IMG_DECLARE(back);			//先申明此图片

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_about();
		mks_draw_tool();
	}
}

void mks_draw_about(void) {

	mks_src = lv_obj_create(NULL, NULL);
	mks_src = lv_scr_act();

	// lv_imgbtn_creat_mks(scr, about_btn_back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);
	about_btn_back =  mks_lv_btn_set(mks_src, about_btn_back,   100, 40, 400, 250 ,event_handler_back);  

	mks_lvgl_long_sroll_label_set(mks_src, Label_board_version, 120, 120, "Board:MKS DLC32 V1.06, VN:6");
	mks_lvgl_long_sroll_label_set(mks_src, Label_Firmware_version, 120, 140, "Firmware:MKS DLC32 V1.0 SDK-1.3.0");
}

void mks_clear_about(void) {
	lv_obj_clean(mks_src);
}

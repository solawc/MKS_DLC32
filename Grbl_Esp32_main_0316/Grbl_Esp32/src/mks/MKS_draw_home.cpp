#include "MKS_draw_home.h"
#include "mks_ctrl.h"
#include "../Grbl.h"
#include "../Report.h"
#include "../GCode.h"
#include "../System.h"
/* Screan Build */
static lv_obj_t* scr;

/* imgbtn */
lv_obj_t* homg_xy;
lv_obj_t* x_home;
lv_obj_t* y_home;
lv_obj_t* btn_bltouch;
static lv_obj_t* Back;

/* Label */
static lv_obj_t* Label_homg_xy;
static lv_obj_t* Label_x_home;
static lv_obj_t* Label_y_home;
static lv_obj_t* Label_Back;

LV_IMG_DECLARE(Home_XY);		//先申明此图片
LV_IMG_DECLARE(X_home);			//先申明此图片
LV_IMG_DECLARE(Y_home);			//先申明此图片
LV_IMG_DECLARE(back);			//先申明此图片


static void event_handler_homg_xy(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("$J=G90X0Y0F346\n");
	}
}

static void event_handler_x_home(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("$J=G90X0F346\n");
	}
}

static void event_handler_y_home(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("$J=G90Y0F346\n");
	}
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clean_home();
		lv_draw_tool();
	}
}

// static uint8_t sss = 0;
// static void event_handler_bltouch(lv_obj_t* obj, lv_event_t event) {

// 	if (event == LV_EVENT_RELEASED) {

// 		// if(sss==0) {
// 		// 	BLTOUCH_push_up();
// 		// 	grbl_send(CLIENT_SERIAL, "touch 0");
// 		// 	sss = 1-sss;
// 		// }
// 		// else {
// 		// 	BLTOUCH_push_down();
// 		// 	grbl_send(CLIENT_SERIAL, "touch 1");
// 		// 	sss = 1-sss;
// 		// }

// 		BLtouch_reset_and_push_up();
// 		BLTOUCH_push_down();
// 		grbl_send(CLIENT_SERIAL, "reset");
// 	}
// }

void mks_draw_home(void) {

	scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

	lv_imgbtn_creat_mks(scr, homg_xy, &Home_XY, &Home_XY, LV_ALIGN_CENTER, -180, -70, event_handler_homg_xy);
	lv_imgbtn_creat_mks(scr, x_home, &X_home, &X_home, LV_ALIGN_CENTER, -60, -70, event_handler_x_home);
	lv_imgbtn_creat_mks(scr, y_home, &Y_home, &Y_home, LV_ALIGN_CENTER, 60, -70, event_handler_y_home);
	lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);

	// mks_lv_btn_set(scr ,btn_bltouch, 50,50,60,90,event_handler_bltouch);

	mks_lvgl_label_set(scr, Label_homg_xy, 30, 120, "XY Home");
	mks_lvgl_label_set(scr, Label_x_home, 160, 120, "X Home");
	mks_lvgl_label_set(scr, Label_y_home, 270, 120, "Y Home");
	mks_lvgl_label_set(scr, Label_Back, 390, 300, "Back");
}

void mks_clean_home(void) {
	lv_obj_clean(scr);
}
#include "MKS_draw_home.h"

/* Screan Build */
static lv_obj_t* scr;

/* imgbtn */
lv_obj_t* homg_xy;
lv_obj_t* x_home;
lv_obj_t* y_home;
static lv_obj_t* Back;

/* Label */
lv_obj_t* Label_homg_xy;
lv_obj_t* Label_x_home;
lv_obj_t* Label_y_home;
static lv_obj_t* Label_Back;

LV_IMG_DECLARE(Home_XY);		//先申明此图片
LV_IMG_DECLARE(X_home);			//先申明此图片
LV_IMG_DECLARE(Y_home);			//先申明此图片
LV_IMG_DECLARE(back);			//先申明此图片

static void event_handler_homg_xy(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_x_home(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_y_home(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clean_home();
		lv_draw_tool();
	}
}

void mks_draw_home(void) {

	scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

	lv_imgbtn_creat_mks(scr, homg_xy, &Home_XY, &Home_XY, LV_ALIGN_CENTER, -180, -70, event_handler_homg_xy);
	lv_imgbtn_creat_mks(scr, x_home, &X_home, &X_home, LV_ALIGN_CENTER, -60, -70, event_handler_x_home);
	lv_imgbtn_creat_mks(scr, y_home, &Y_home, &Y_home, LV_ALIGN_CENTER, 60, -70, event_handler_y_home);
	lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);

	mks_lvgl_label_set(scr, Label_homg_xy, 30, 120, "#ffffff Home#");
	mks_lvgl_label_set(scr, Label_x_home, 140, 120, "#ffffff Positioning#");
	mks_lvgl_label_set(scr, Label_y_home, 280, 120, "#ffffff Move#");
	mks_lvgl_label_set(scr, Label_Back, 390, 300, "#ffffff Back#");
}

void mks_clean_home(void) {
	lv_obj_clean(scr);
}
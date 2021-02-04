#include "MKS_draw_power.h"


/* Screan Build */
static lv_obj_t* scr;

/* imgbtn */
lv_obj_t* add;
lv_obj_t* dec;
lv_obj_t* pwr_len;
static lv_obj_t* Back;

/* imgbtn */
lv_obj_t* Label_add;
lv_obj_t* Label_dec;
lv_obj_t* Label_pwr_len;
static lv_obj_t* Label_Back;
lv_obj_t* Label_power_on_off;
lv_obj_t* Label_pwr_persen;

LV_IMG_DECLARE(Add);			//先申明此图片
LV_IMG_DECLARE(Dec);			//先申明此图片
LV_IMG_DECLARE(Pwr_1);			//先申明此图片
LV_IMG_DECLARE(Pwr_10);			//先申明此图片
LV_IMG_DECLARE(back);			//先申明此图片


static void event_handler_add(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_dec(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_motor_off(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_Back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_power();
		lv_draw_tool();
	}
}

void mks_draw_power(void) {

	scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

	lv_imgbtn_creat_mks(scr, add, &Add, &Add, LV_ALIGN_CENTER, -180, -50, event_handler_add);
	lv_imgbtn_creat_mks(scr, dec, &Dec, &Dec, LV_ALIGN_CENTER, 180, -50, event_handler_dec);
	lv_imgbtn_creat_mks(scr, pwr_len, &Pwr_1, &Pwr_1, LV_ALIGN_CENTER, -60, 90, event_handler_motor_off);
	lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_Back);

	mks_lvgl_label_set(scr, Label_add, 40, 140, "#ffffff Add#");
	mks_lvgl_label_set(scr, Label_dec, 390, 140, "#ffffff Dec#");
	mks_lvgl_label_set(scr, Label_pwr_len, 260, 100, "#ffffff OFF#"); 
	mks_lvgl_label_set(scr, Label_power_on_off, 180, 100, "#ffffff POWER:#");
	mks_lvgl_label_set(scr, Label_pwr_persen, 160, 280, "#ffffff 1%#");
	mks_lvgl_label_set(scr, Label_Back, 390, 280, "#ffffff Back#");
} 

void mks_clear_power(void) {
	lv_obj_clean(scr);
}
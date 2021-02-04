#include "MKS_draw_language.h"


/* Screan Build */
static lv_obj_t* scr;

/* imgbtn */
lv_obj_t* simple_chinese;
static lv_obj_t* Back;

/* Label */
lv_obj_t* Label_simple_chinese;
static lv_obj_t* Label_back;

LV_IMG_DECLARE(SimpleChinene);			//先申明此图片
LV_IMG_DECLARE(SinpleChinese_P);		//先申明此图片
LV_IMG_DECLARE(back);					//先申明此图片

static void event_handler_sch(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_language();
		lv_draw_ready();
	}
}

void mks_draw_language(void) {

	scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();
	lv_imgbtn_creat_mks(scr, simple_chinese, &SimpleChinene, &SimpleChinene, LV_ALIGN_CENTER, -180, -70, event_handler_sch);
	lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);

	mks_lvgl_label_set(scr, Label_simple_chinese, 20, 120, "#ffffff Simple_CH#");
	mks_lvgl_label_set(scr, Label_back, 400, 280, "#ffffff Back#");
}

void mks_clear_language(void) {
	lv_obj_clean(scr);
}






#include "MKS_draw_setting.h"

/* Screan Build */
static lv_obj_t* scr;

/* imgbtn */
static lv_obj_t* languages;
static lv_obj_t* about;
static lv_obj_t* config;
static lv_obj_t* wifi_set;
static lv_obj_t* Back;

/* Label */
static lv_obj_t *label_wifi;
static lv_obj_t* Label_languages;
static lv_obj_t* Label_about;
static lv_obj_t* Label_config;
static lv_obj_t* Label_back;

// LV_IMG_DECLARE(About);			//先申明此图片
// LV_IMG_DECLARE(Languages);		//先申明此图片
// LV_IMG_DECLARE(Config);			//先申明此图片
// LV_IMG_DECLARE(back);			//先申明此图片
// LV_IMG_DECLARE(WIFI);			//先申明此图片

LV_IMG_DECLARE(LA);			//先申明此图片

static void event_handler_language(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_setting();
		mks_draw_language();
	}
}

static void event_handler_about(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_setting();
		mks_draw_about();
	}
}

static void event_handler_config(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_setting();
		mks_draw_config_main_page();
	}
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_setting();
		// lv_draw_ready();
	}
}

static void event_handler_wifi(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
		mks_clear_setting();
		#if defined(USE_WIFI)
		mks_draw_wifi();
		#endif
	}
}

void mks_draw_setting(void) {



}

void mks_clear_setting(void) {
	lv_obj_clean(scr);
}




#include "MKS_draw_carving.h"


 /* Screan Build */
static lv_obj_t* scr;

/* imgbtn */
lv_obj_t* up;
lv_obj_t* next;
lv_obj_t* Cback;

LV_IMG_DECLARE(Up);			//先申明此图片
LV_IMG_DECLARE(Next);		//先申明此图片
LV_IMG_DECLARE(cback);			//先申明此图片


static void event_handler_up(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_next(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_cback(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		mks_clear_craving();
		lv_draw_ready();
	}
}


void mks_draw_craving(void) {

	scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

	lv_imgbtn_creat_mks(scr, up, &Up, &Up, LV_ALIGN_CENTER, 180, -70, event_handler_up);
	lv_imgbtn_creat_mks(scr, next, &Next, &Next, LV_ALIGN_CENTER, 180, 20, event_handler_next);
	lv_imgbtn_creat_mks(scr, Cback, &cback, &cback, LV_ALIGN_CENTER, 180, 110, event_handler_cback);

}

void mks_clear_craving(void) {
	lv_obj_clean(scr);
}

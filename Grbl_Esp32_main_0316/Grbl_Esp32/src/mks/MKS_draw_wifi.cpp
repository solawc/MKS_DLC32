#include "mks_draw_wifi.h"


static lv_obj_t *scr;

static lv_obj_t* Back;
static lv_obj_t* Label_back;


static lv_obj_t *label_wifi_ip;                     // 显示wifi ip
static lv_obj_t *label_wifi_mode;                   // 显示wifi 当前的模式：sta/ap  端口：8080

LV_IMG_DECLARE(back);			//先申明此图片



static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_wifi();
		mks_draw_setting();
	}
}

void mks_draw_wifi(void) { 

    char wifi_ip[20];
    char wifi_mode[] = "Mode:";

    scr = lv_obj_create(NULL, NULL);
    scr = lv_scr_act();

    lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);


    label_wifi_ip = mks_lvgl_label_with_long_set(scr, label_wifi_ip, 180, 130, "192.168.2.131", 200);
    label_wifi_mode = mks_lvgl_label_with_long_set(scr, label_wifi_mode, 180, 160, "Mode: STA", 200);
    
    
    mks_lvgl_label_set(scr, Label_back, 400, 280, "#ffffff Back#");
} 


void mks_clear_wifi(void) {
	lv_obj_clean(scr);
}




#include "mks_draw_wifi.h"


static lv_obj_t *scr;

static lv_obj_t* Back;
static lv_obj_t* Label_back;


static lv_obj_t *label_wifi_ip;                     // 显示wifi ip
static lv_obj_t *label_wifi_mode;                   // 显示wifi 当前的模式：sta/ap  端口：8080
static lv_obj_t *label_wifi_connect_status;         // wifi 連接狀態顯示

LV_IMG_DECLARE(back);			//先申明此图片



static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_wifi();
		mks_draw_setting();
	}
}

void mks_widi_show_ip(IPAddress ip) { 

    char ip_str[40] = "IP:";
    strcat(ip_str, ip.toString().c_str());
    label_wifi_ip = mks_lvgl_label_with_long_set(scr, label_wifi_ip, 0, 30, ip_str , 200); 

    if(WiFi.getMode() == WIFI_STA)
        label_wifi_mode = mks_lvgl_label_with_long_set(scr, label_wifi_mode, 0, 60, "Mode: STA", 200);
    else 
        label_wifi_mode = mks_lvgl_label_with_long_set(scr, label_wifi_mode, 0, 60, "Mode: AP", 200);
}


void mks_draw_wifi(void) { 

    char wifi_ip[20];
    char wifi_mode[] = "Mode:";

    mks_grbl.wifi_check_status = true;

    scr = lv_obj_create(NULL, NULL);
    scr = lv_scr_act();

    lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);
    
    /* get wifi ip */
    mks_widi_show_ip(WiFi.getMode() == WIFI_STA ? WiFi.localIP() : WiFi.softAPIP());
    
    if(mks_grbl.wifi_connect_status == true)
        label_wifi_connect_status = mks_lvgl_label_with_long_set(scr, label_wifi_connect_status, 0, 90, "connect", 200);
    else if(mks_grbl.wifi_connect_status == false)
        label_wifi_connect_status = mks_lvgl_label_with_long_set(scr, label_wifi_connect_status, 0, 90, "disconnect", 200);

    mks_lvgl_label_set(scr, Label_back, 400, 280, "#ffffff Back#");
} 

void mks_wifi_connect_check(void) { 
    if(mks_grbl.wifi_check_status == true) {
        if(mks_grbl.wifi_connect_status == true)
            lv_label_set_text(label_wifi_connect_status, "Status:connect");
        else if(mks_grbl.wifi_connect_status == false)
            lv_label_set_text(label_wifi_connect_status, "Status:disconnect");
    }
    else if (mks_grbl.wifi_check_status == false) {
        return;
    }
}

void mks_clear_wifi(void) {
    mks_grbl.wifi_check_status = false;
	lv_obj_clean(scr);
}




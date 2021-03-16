#include "MKS_draw_wifi.h"


static lv_obj_t *scr;

static lv_obj_t *label_wifi_ip;

/* btn */
static lv_obj_t *wifi_test;
/* key board */
static lv_obj_t *kb_wifi_usernames;
static lv_obj_t *kb_wifi_password;


// LV_IMG_DECLARE(WIFI);			//先申明此图片

static void event_handler_wifi_btn(lv_obj_t* obj, lv_event_t event) {

    char addr[20];
	if (event == LV_EVENT_RELEASED) {
        // sprintf(addr, "addr = %d\n", WiFi.localIP());
        // grbl_send(CLIENT_SERIAL, addr);
	}
}


void mks_draw_wifi(void) { 

    bool ip_flag = true;
    char ip_addr[20];

    scr = lv_obj_create(NULL,NULL);
    scr = lv_scr_act();

    /* get wifi ip */
    //WiFi.getMode() == WIFI_STA ? WiFi.localIP() : WiFi.softAPIP();

    // if(WiFi.getMode() == WIFI_STA)  
    //     ip_flag = true;
    // else 
    //     ip_flag = false;

    // if(ip_flag)

    wifi_test = mks_lv_btn_set(scr, wifi_test, 30, 30, 100, 100, event_handler_wifi_btn);
}




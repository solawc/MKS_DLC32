#include "mks_draw_wifi.h"
#include "../WebUI/WifiConfig.h"

static lv_obj_t *scr;
static lv_obj_t *wifi_load_popup;


static lv_obj_t* btn_wifi_begin;
static lv_obj_t* btn_wifi_end;

static lv_obj_t *btn_popup_sure;

static lv_obj_t *btn_wifi_user_name;
static lv_obj_t *btn_wifi_user_password;

static lv_obj_t* Back;
static lv_obj_t* Label_back;
static lv_obj_t* label_wifi_begin;
static lv_obj_t* label_wifi_end;
static lv_obj_t* Label_popup;

static lv_obj_t *label_wifi_ip;                     // 显示wifi ip
static lv_obj_t *label_wifi_mode;                   // 显示wifi 当前的模式：sta/ap  端口：8080
static lv_obj_t *label_wifi_connect_status;         // wifi 連接狀態顯示

static lv_obj_t *label_wifi_user_name;
static lv_obj_t *label_wifi_user_password;

static lv_obj_t *kb_wifi;
static lv_obj_t *ta_wifi_username;
static lv_obj_t *ta_wifi_password;

wifi_kb_flag_t wifi_kb_flag = wifi_none_flag;
char wifi_username_str[65];
char wifi_password_str[65];

LV_IMG_DECLARE(back);			//先申明此图片

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_wifi();
		mks_draw_setting();
	}
}


static void event_handler_wifi_begin(lv_obj_t* obj, lv_event_t event) {

    char username_cmd[65] = "[ESP100]";
    char password_cmd[65] = "[ESP101]";
	if (event == LV_EVENT_RELEASED) {
        // draw_wifi_loading();
        WebUI::wifi_config.begin();
        // lv_obj_del(wifi_load_popup);
        mks_wifi_connect_check(WiFi.getMode() == WIFI_STA ? WiFi.localIP() : WiFi.softAPIP());
	}
}

static void event_handler_wifi_end(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        WebUI::wifi_config.end();
        mks_wifi_connect_check(WiFi.getMode() == WIFI_STA ? WiFi.localIP() : WiFi.softAPIP());
	}
}

static void event_handler_wifi_kb_cb(lv_obj_t* obj, lv_event_t event) {

    char username_cmd[65] = "[ESP100]";
    char password_cmd[65] = "[ESP101]";

    if(obj == kb_wifi) {
        lv_kb_def_event_cb(obj, event);
        if(event == LV_EVENT_VALUE_CHANGED) {
            
        }else if(event == LV_EVENT_APPLY) {
            if(wifi_kb_flag == wifi_username_flag) {
                strcpy(wifi_username_str,lv_ta_get_text(ta_wifi_username));   
                strcat(username_cmd, wifi_username_str);
                strcat(username_cmd, "\n");
                MKS_GRBL_CMD_SEND(username_cmd);
            }else if(wifi_kb_flag == wifi_password_flag) {
                strcpy(wifi_password_str,lv_ta_get_text(ta_wifi_password));
                strcat(password_cmd, wifi_password_str);
                strcat(password_cmd, "\n");
                MKS_GRBL_CMD_SEND(password_cmd);
            }

            lv_obj_del(kb_wifi);
            if(wifi_kb_flag == wifi_username_flag) {
                lv_obj_del(ta_wifi_username);
            }else if(wifi_kb_flag == wifi_password_flag) {
                lv_obj_del(ta_wifi_password);
            }
        }
    }
}

static void event_handler_wifi_username(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

        wifi_kb_flag = wifi_username_flag;
        kb_wifi = mks_lv_set_kb(scr, kb_wifi, event_handler_wifi_kb_cb);
        ta_wifi_username = mks_lv_set_ta(scr ,ta_wifi_username, kb_wifi);
	}
}

static void event_handler_wifi_password(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

        wifi_kb_flag = wifi_password_flag;
        kb_wifi = mks_lv_set_kb(scr, kb_wifi, event_handler_wifi_kb_cb);
        ta_wifi_password = mks_lv_set_ta(scr ,ta_wifi_username, kb_wifi);
	}
}




// static void event_btn_sure(lv_obj_t* obj, lv_event_t event) {

//     if (event == LV_EVENT_RELEASED) {

// 	}
// }


void mks_widi_show_ip(IPAddress ip) { 

    char ip_str[40] = "IP:";
    strcat(ip_str, ip.toString().c_str());
    label_wifi_ip = mks_lvgl_label_with_long_set(scr, label_wifi_ip, 0, 30, ip_str , 200); 

    if(WiFi.getMode() == WIFI_STA)
        label_wifi_mode = mks_lvgl_label_with_long_set(scr, label_wifi_mode, 0, 60, "Mode: STA", 100);
    else 
        label_wifi_mode = mks_lvgl_label_with_long_set(scr, label_wifi_mode, 0, 60, "Mode: AP", 100);
}


void mks_wifi_connect_check(IPAddress ip) { 

    char ip_str[40] = "IP:";
    strcat(ip_str, ip.toString().c_str());

    lv_label_set_text(label_wifi_ip, ip_str);

    if(mks_grbl.wifi_connect_status == true)
        lv_label_set_text(label_wifi_connect_status, "Connect Status:connect");
    else if(mks_grbl.wifi_connect_status == false)
        lv_label_set_text(label_wifi_connect_status, "Connect Status:disconnect");

    if(WiFi.getMode() == WIFI_STA)
        lv_label_set_text(label_wifi_mode, "Mode: STA");
    else 
       lv_label_set_text(label_wifi_mode, "Mode: AP");
}


void mks_draw_wifi(void) { 

    char wifi_ip[20];
    char wifi_mode[] = "Mode:";

    mks_grbl.wifi_check_status = true;

    scr = lv_obj_create(NULL, NULL);
    scr = lv_scr_act();

    lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);


    btn_wifi_user_name = mks_lv_btn_set(scr, btn_wifi_user_name, 200, 40, 0, 150, event_handler_wifi_username);
    btn_wifi_user_password = mks_lv_btn_set(scr, btn_wifi_user_password, 200, 40, 0, 200, event_handler_wifi_password);


    btn_wifi_begin = mks_lv_btn_set(scr,btn_wifi_begin, 100, 40, 30, 280, event_handler_wifi_begin);
    btn_wifi_end = mks_lv_btn_set(scr,btn_wifi_end, 100, 40, 150, 280, event_handler_wifi_end);

    /* get wifi ip */
    mks_widi_show_ip(WiFi.getMode() == WIFI_STA ? WiFi.localIP() : WiFi.softAPIP());
    
    if(mks_grbl.wifi_connect_status == true)
        label_wifi_connect_status = mks_lvgl_label_with_long_set(scr, label_wifi_connect_status, 0, 90, "Connect Status:connect", 200);
    else if(mks_grbl.wifi_connect_status == false)
        label_wifi_connect_status = mks_lvgl_label_with_long_set(scr, label_wifi_connect_status, 0, 90, "Connect Status:disconnect", 200);
    mks_lvgl_label_set(scr, Label_back, 400, 280, "Back");

    label_wifi_begin = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi_begin, label_wifi_begin, 0,0,"connect", 80);
    label_wifi_end = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi_end, label_wifi_begin, 0,0,"disconnect", 80);

    label_wifi_user_name = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi_user_name, label_wifi_user_name, 0,0,"username", 120);
    label_wifi_user_password = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi_user_password, label_wifi_user_password, 0,0,"password", 120);
} 


void draw_wifi_loading(void) {

    wifi_load_popup = lv_obj_create(scr, NULL);
    lv_obj_set_size(wifi_load_popup ,350, 200);
	lv_obj_set_pos(wifi_load_popup, 80,50);
    mks_lvgl_long_sroll_label_with_wight_set(wifi_load_popup, Label_popup, 100, 80, "wifi connectting",150);
}



void mks_clear_wifi(void) {
    mks_grbl.wifi_check_status = false;
	lv_obj_clean(scr);
}



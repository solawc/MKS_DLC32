#include "mks_draw_wifi.h"
#include "../WebUI/WifiConfig.h"

// static lv_obj_t *scr;
// static lv_obj_t *wifi_load_popup;


// static lv_obj_t* btn_wifi_begin;
// static lv_obj_t* btn_wifi_end;

// static lv_obj_t *btn_popup_sure;

// static lv_obj_t *btn_wifi_user_name;
// static lv_obj_t *btn_wifi_user_password;

// static lv_obj_t* Back;
// static lv_obj_t* Label_back;
// static lv_obj_t* label_wifi_begin;
// static lv_obj_t* label_wifi_end;
// static lv_obj_t* Label_popup;

// static lv_obj_t *label_wifi_ip;                     // 显示wifi ip
// static lv_obj_t *label_wifi_mode;                   // 显示wifi 当前的模式：sta/ap  端口：8080
// static lv_obj_t *label_wifi_connect_status;         // wifi 連接狀態顯示

// static lv_obj_t *label_wifi_user_name;
// static lv_obj_t *label_wifi_user_password;

// static lv_obj_t *kb_wifi;
// static lv_obj_t *ta_wifi_username;
// static lv_obj_t *ta_wifi_password;

// wifi_kb_flag_t wifi_kb_flag = wifi_none_flag;
// char wifi_username_str[65];
// char wifi_password_str[65];

// LV_IMG_DECLARE(back);			//先申明此图片

// static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

// 	if (event == LV_EVENT_RELEASED) {
// 		mks_clear_wifi();
// 		mks_draw_setting();
// 	}
// }


// static void event_handler_wifi_begin(lv_obj_t* obj, lv_event_t event) {

//     char username_cmd[65] = "[ESP100]";
//     char password_cmd[65] = "[ESP101]";
// 	if (event == LV_EVENT_RELEASED) {
//         // draw_wifi_loading();
//         WebUI::wifi_config.begin();
//         // lv_obj_del(wifi_load_popup);
//         mks_wifi_connect_check(WiFi.getMode() == WIFI_STA ? WiFi.localIP() : WiFi.softAPIP());
// 	}
// }

// static void event_handler_wifi_end(lv_obj_t* obj, lv_event_t event) {

// 	if (event == LV_EVENT_RELEASED) {
//         WebUI::wifi_config.end();
//         mks_wifi_connect_check(WiFi.getMode() == WIFI_STA ? WiFi.localIP() : WiFi.softAPIP());
// 	}
// }

// static void event_handler_wifi_kb_cb(lv_obj_t* obj, lv_event_t event) {

//     char username_cmd[65] = "[ESP100]";
//     char password_cmd[65] = "[ESP101]";

//     if(obj == kb_wifi) {
//         lv_kb_def_event_cb(obj, event);
//         if(event == LV_EVENT_VALUE_CHANGED) {
            
//         }else if(event == LV_EVENT_APPLY) {
//             if(wifi_kb_flag == wifi_username_flag) {
//                 strcpy(wifi_username_str,lv_ta_get_text(ta_wifi_username));   
//                 strcat(username_cmd, wifi_username_str);
//                 strcat(username_cmd, "\n");
//                 MKS_GRBL_CMD_SEND(username_cmd);
//             }else if(wifi_kb_flag == wifi_password_flag) {
//                 strcpy(wifi_password_str,lv_ta_get_text(ta_wifi_password));
//                 strcat(password_cmd, wifi_password_str);
//                 strcat(password_cmd, "\n");
//                 MKS_GRBL_CMD_SEND(password_cmd);
//             }

//             lv_obj_del(kb_wifi);
//             if(wifi_kb_flag == wifi_username_flag) {
//                 lv_obj_del(ta_wifi_username);
//             }else if(wifi_kb_flag == wifi_password_flag) {
//                 lv_obj_del(ta_wifi_password);
//             }
//         }
//     }
// }

// static void event_handler_wifi_username(lv_obj_t* obj, lv_event_t event) {

// 	if (event == LV_EVENT_RELEASED) {

//         wifi_kb_flag = wifi_username_flag;
//         kb_wifi = mks_lv_set_kb(scr, kb_wifi, event_handler_wifi_kb_cb);
//         ta_wifi_username = mks_lv_set_ta(scr ,ta_wifi_username, kb_wifi);
// 	}
// }

// static void event_handler_wifi_password(lv_obj_t* obj, lv_event_t event) {

// 	if (event == LV_EVENT_RELEASED) {

//         wifi_kb_flag = wifi_password_flag;
//         kb_wifi = mks_lv_set_kb(scr, kb_wifi, event_handler_wifi_kb_cb);
//         ta_wifi_password = mks_lv_set_ta(scr ,ta_wifi_username, kb_wifi);
// 	}
// }




// // static void event_btn_sure(lv_obj_t* obj, lv_event_t event) {

// //     if (event == LV_EVENT_RELEASED) {

// // 	}
// // }


// void mks_widi_show_ip(IPAddress ip) { 

//     char ip_str[40] = "IP:";
//     strcat(ip_str, ip.toString().c_str());
//     label_wifi_ip = mks_lvgl_label_with_long_set(scr, label_wifi_ip, 0, 30, ip_str , 200); 

//     if(WiFi.getMode() == WIFI_STA)
//         label_wifi_mode = mks_lvgl_label_with_long_set(scr, label_wifi_mode, 0, 60, "Mode: STA", 100);
//     else 
//         label_wifi_mode = mks_lvgl_label_with_long_set(scr, label_wifi_mode, 0, 60, "Mode: AP", 100);
// }


// void mks_wifi_connect_check(IPAddress ip) { 

//     char ip_str[40] = "IP:";
//     strcat(ip_str, ip.toString().c_str());

//     lv_label_set_text(label_wifi_ip, ip_str);

//     if(mks_grbl.wifi_connect_status == true)
//         lv_label_set_text(label_wifi_connect_status, "Connect Status:connect");
//     else if(mks_grbl.wifi_connect_status == false)
//         lv_label_set_text(label_wifi_connect_status, "Connect Status:disconnect");

//     if(WiFi.getMode() == WIFI_STA)
//         lv_label_set_text(label_wifi_mode, "Mode: STA");
//     else 
//        lv_label_set_text(label_wifi_mode, "Mode: AP");
// }


// void mks_draw_wifi(void) { 

//     char wifi_ip[20];
//     char wifi_mode[] = "Mode:";

//     mks_grbl.wifi_check_status = true;

//     scr = lv_obj_create(NULL, NULL);
//     scr = lv_scr_act();

//     lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);


//     btn_wifi_user_name = mks_lv_btn_set(scr, btn_wifi_user_name, 200, 40, 0, 150, event_handler_wifi_username);
//     btn_wifi_user_password = mks_lv_btn_set(scr, btn_wifi_user_password, 200, 40, 0, 200, event_handler_wifi_password);


//     btn_wifi_begin = mks_lv_btn_set(scr,btn_wifi_begin, 100, 40, 30, 280, event_handler_wifi_begin);
//     btn_wifi_end = mks_lv_btn_set(scr,btn_wifi_end, 100, 40, 150, 280, event_handler_wifi_end);

//     /* get wifi ip */
//     mks_widi_show_ip(WiFi.getMode() == WIFI_STA ? WiFi.localIP() : WiFi.softAPIP());
    
//     if(mks_grbl.wifi_connect_status == true)
//         label_wifi_connect_status = mks_lvgl_label_with_long_set(scr, label_wifi_connect_status, 0, 90, "Connect Status:connect", 200);
//     else if(mks_grbl.wifi_connect_status == false)
//         label_wifi_connect_status = mks_lvgl_label_with_long_set(scr, label_wifi_connect_status, 0, 90, "Connect Status:disconnect", 200);
//     mks_lvgl_label_set(scr, Label_back, 400, 280, "Back");

//     label_wifi_begin = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi_begin, label_wifi_begin, 0,0,"connect", 80);
//     label_wifi_end = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi_end, label_wifi_begin, 0,0,"disconnect", 80);

//     label_wifi_user_name = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi_user_name, label_wifi_user_name, 0,0,"username", 120);
//     label_wifi_user_password = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi_user_password, label_wifi_user_password, 0,0,"password", 120);
// } 


// void draw_wifi_loading(void) {

//     wifi_load_popup = lv_obj_create(scr, NULL);
//     lv_obj_set_size(wifi_load_popup ,350, 200);
// 	lv_obj_set_pos(wifi_load_popup, 80,50);
//     mks_lvgl_long_sroll_label_with_wight_set(wifi_load_popup, Label_popup, 100, 80, "wifi connectting",150);
// }

static lv_style_t btn_press_style;
static lv_style_t line_style;
lv_style_t wifi_scr1_style;
lv_obj_t *wifi_src1;

lv_obj_t *wifi_btn_line1; 
lv_obj_t *wifi_btn_line2; 
lv_obj_t *wifi_btn_line3; 
lv_obj_t *wifi_btn_line4; 
lv_obj_t *wifi_btn_line5; 
lv_obj_t *wifi_btn_line6; 
lv_obj_t *wifi_btn_line7; 
lv_obj_t *wifi_btn_line8; 

lv_obj_t *wifi_line1;
lv_obj_t *wifi_line2;
lv_obj_t *wifi_line3;
lv_obj_t *wifi_line4;
lv_obj_t *wifi_line5;
lv_obj_t *wifi_line6;
lv_obj_t *wifi_line7;
lv_obj_t *wifi_line8;
lv_point_t wifi_line_points1[] = {{0,45},{470,45}};
lv_point_t wifi_line_points2[] = {{0,95},{470,95}};
lv_point_t wifi_line_points3[] = {{0,145},{470,145}};
lv_point_t wifi_line_points4[] = {{0,195},{470,195}};

lv_point_t wifi_line_points[8][2] = {
    {{wifi_first_line_x, wifi_first_line_y},
    {wifi_first_line_x+200, wifi_first_line_y}},

    {{wifi_first_line_x, wifi_first_line_y+50},
    {wifi_first_line_x+200, wifi_first_line_y+50}},
    
    {{wifi_first_line_x, wifi_first_line_y+100},
    {wifi_first_line_x+200, wifi_first_line_y+100}},

    {{wifi_first_line_x, wifi_first_line_y+150},
    {wifi_first_line_x+200, wifi_first_line_y+150}},

    {{wifi_first_line_x+220, wifi_first_line_y},
    {wifi_first_line_x+220+200, wifi_first_line_y}},

    {{wifi_first_line_x+220, wifi_first_line_y+50},
    {wifi_first_line_x+220+200, wifi_first_line_y+50}},

    {{wifi_first_line_x+220, wifi_first_line_y+100},
    {wifi_first_line_x+220+200, wifi_first_line_y+100}},

    {{wifi_first_line_x+220, wifi_first_line_y+150},
    {wifi_first_line_x+220+200, wifi_first_line_y+150}},
};

lv_obj_t *wifi_up;
lv_obj_t *wifi_next;
lv_obj_t *wifi_back;

lv_obj_t *wifi_label_back;
lv_obj_t *wifi_label_line1; 
lv_obj_t *wifi_label_line2; 
lv_obj_t *wifi_label_line3; 
lv_obj_t *wifi_label_line4; 
lv_obj_t *wifi_label_line5; 
lv_obj_t *wifi_label_line6;
lv_obj_t *wifi_label_line7; 
lv_obj_t *wifi_label_line8;

LV_IMG_DECLARE(back);			//先申明此图片
LV_IMG_DECLARE(Next);			//先申明此图片
LV_IMG_DECLARE(Previous);			//先申明此图片


static void event_handler_wifi_up(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

        if(mks_wifi.wifi_show_page == 1) {

        }else{
            mks_wifi_del_label();
            mks_wifi_scanf();
            mks_wifi_show_label();
            mks_wifi.wifi_show_page--;
        }
	}
}

static void event_handler_wifi_next(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_wifi_del_label();
        mks_wifi_scanf();
        mks_wifi_show_label();
        mks_wifi.wifi_show_page++;
	}
}

static void event_handler_wifi_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_clear_wifi();
        mks_draw_tool();
	}
}

static void event_handler_wifi_bt1(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        grbl_send(CLIENT_SERIAL ,"wifi connect\n");
        mks_wifi_connect();
	}
}

static void event_handler_wifi_bt2(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_wifi_bt3(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_wifi_bt4(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_wifi_bt5(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_wifi_bt6(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_wifi_bt7(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_wifi_bt8(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

void mks_draw_wifi(void) {

    mks_src = lv_obj_create(NULL, NULL);
	mks_src = lv_scr_act();

    wifi_src1 = lv_obj_create(mks_src, NULL);
    lv_obj_set_size(wifi_src1, wifi_src1_x_size, wifi_src1_y_size);
    lv_obj_set_pos(wifi_src1, wifi_src1_x, wifi_src1_y);

    lv_style_copy(&wifi_scr1_style, &lv_style_scr);
    wifi_scr1_style.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    wifi_scr1_style.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    wifi_scr1_style.text.color = LV_COLOR_WHITE;
    wifi_scr1_style.body.radius = 17;
    lv_obj_set_style(wifi_src1, &wifi_scr1_style);

    lv_style_copy(&btn_press_style, &lv_style_scr);
    btn_press_style.body.main_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    btn_press_style.body.grad_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    btn_press_style.body.opa = LV_OPA_COVER;        //设置背景色完全不透明
    btn_press_style.text.color = LV_COLOR_WHITE;




    /* 创建按键 */
    wifi_btn_line1 = mks_lv_btn_set(mks_src, wifi_btn_line1,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x, wifi_first_btn_y ,event_handler_wifi_bt1);
    wifi_btn_line2 = mks_lv_btn_set(mks_src, wifi_btn_line2,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x, wifi_first_btn_y+50 ,event_handler_wifi_bt2);
    wifi_btn_line3 = mks_lv_btn_set(mks_src, wifi_btn_line3,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x, wifi_first_btn_y+100 ,event_handler_wifi_bt3);
    wifi_btn_line4 = mks_lv_btn_set(mks_src, wifi_btn_line4,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x, wifi_first_btn_y+150 ,event_handler_wifi_bt4);
    wifi_btn_line5 = mks_lv_btn_set(mks_src, wifi_btn_line5,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x+230, wifi_first_btn_y ,event_handler_wifi_bt5);
    wifi_btn_line6 = mks_lv_btn_set(mks_src, wifi_btn_line6,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x+230, wifi_first_btn_y+50 ,event_handler_wifi_bt6);
    wifi_btn_line7 = mks_lv_btn_set(mks_src, wifi_btn_line7,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x+230, wifi_first_btn_y+100 ,event_handler_wifi_bt7);
    wifi_btn_line8 = mks_lv_btn_set(mks_src, wifi_btn_line8,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x+230, wifi_first_btn_y+150 ,event_handler_wifi_bt8);
    
    lv_imgbtn_creat_mks(wifi_src1, wifi_up, &Previous, &Previous, LV_ALIGN_CENTER, 50, -10, event_handler_wifi_up);
	lv_imgbtn_creat_mks(wifi_src1, wifi_next, &Next, &Next, LV_ALIGN_CENTER, 100, -10, event_handler_wifi_next);
    wifi_back = lv_imgbtn_creat_mks(wifi_src1, wifi_back, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10, event_handler_wifi_back);

    lv_btn_set_style(wifi_btn_line1, LV_BTN_STYLE_REL, &btn_press_style);
    lv_btn_set_style(wifi_btn_line1,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_btn_line2,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_btn_line2,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_btn_line3,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_btn_line3,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_btn_line4,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_btn_line4,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_btn_line5,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_btn_line5,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_btn_line6,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_btn_line6,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_btn_line7,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_btn_line7,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_btn_line8,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_btn_line8,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_back,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_back,LV_BTN_STYLE_PR,&btn_press_style);

    lv_style_copy(&line_style, &lv_style_plain);
    line_style.line.color = LV_COLOR_MAKE(0x00, 0x3b, 0x75);
    line_style.line.width = 1;
    line_style.line.rounded = 1;

    wifi_line1 = mks_lv_set_line(mks_src, wifi_line1, wifi_line_points[0]);
    lv_line_set_style(wifi_line1, LV_LINE_STYLE_MAIN, &line_style);
    wifi_line2 = mks_lv_set_line(mks_src, wifi_line2, wifi_line_points[1]);
    lv_line_set_style(wifi_line2, LV_LINE_STYLE_MAIN, &line_style);
    wifi_line3 = mks_lv_set_line(mks_src, wifi_line3, wifi_line_points[2]);
    lv_line_set_style(wifi_line3, LV_LINE_STYLE_MAIN, &line_style);
    wifi_line4 = mks_lv_set_line(mks_src, wifi_line4, wifi_line_points[3]);
    lv_line_set_style(wifi_line4, LV_LINE_STYLE_MAIN, &line_style);
    wifi_line5 = mks_lv_set_line(mks_src, wifi_line5, wifi_line_points[4]);
    lv_line_set_style(wifi_line5, LV_LINE_STYLE_MAIN, &line_style);
    wifi_line6 = mks_lv_set_line(mks_src, wifi_line6, wifi_line_points[5]);
    lv_line_set_style(wifi_line6, LV_LINE_STYLE_MAIN, &line_style);
    wifi_line7 = mks_lv_set_line(mks_src, wifi_line7, wifi_line_points[6]);
    lv_line_set_style(wifi_line7, LV_LINE_STYLE_MAIN, &line_style);
    wifi_line8 = mks_lv_set_line(mks_src, wifi_line8, wifi_line_points[7]);
    lv_line_set_style(wifi_line8, LV_LINE_STYLE_MAIN, &line_style);

    mks_wifi.wifi_show_page = 1;
    mks_wifi.begin_scanf_num = 0;
    mks_wifi_scanf();

    // /* 创建label */
    // wifi_label_line1 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line1, wifi_label_line1, 0, 0,"WIFI NAME 1",wifi_btn_label_size);
    // wifi_label_line2 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line2, wifi_label_line2, 0, 0, "WIFI NAME 2", wifi_btn_label_size);
    // wifi_label_line3 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line3, wifi_label_line3, 0, 0, "WIFI NAME 3",wifi_btn_label_size);
    // wifi_label_line4 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line4, wifi_label_line4, 0, 0,"WIFI NAME 4",wifi_btn_label_size);
    // wifi_label_line5 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line5, wifi_label_line5, 0,0, "WIFI NAME 5", wifi_btn_label_size);
    // wifi_label_line6 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line6, wifi_label_line6, 0, 0, "WIFI NAME 6",wifi_btn_label_size);
    // wifi_label_line7 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line7, wifi_label_line7, 0,0, "WIFI NAME 7", wifi_btn_label_size);
    // wifi_label_line8 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line8, wifi_label_line8, 0, 0, "WIFI NAME 8",wifi_btn_label_size);

    wifi_label_line1 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line1, wifi_label_line1, 0, 0, mks_wifi.wifi_name_str[0], wifi_btn_label_size);
    wifi_label_line2 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line2, wifi_label_line2, 0, 0, mks_wifi.wifi_name_str[1], wifi_btn_label_size);
    wifi_label_line3 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line3, wifi_label_line3, 0, 0, mks_wifi.wifi_name_str[2], wifi_btn_label_size);
    wifi_label_line4 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line4, wifi_label_line4, 0, 0, mks_wifi.wifi_name_str[3], wifi_btn_label_size);
    wifi_label_line5 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line5, wifi_label_line5, 0, 0, mks_wifi.wifi_name_str[4], wifi_btn_label_size);
    wifi_label_line6 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line6, wifi_label_line6, 0, 0, mks_wifi.wifi_name_str[5], wifi_btn_label_size);
    wifi_label_line7 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line7, wifi_label_line7, 0, 0, mks_wifi.wifi_name_str[6], wifi_btn_label_size);
    wifi_label_line8 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line8, wifi_label_line8, 0, 0, mks_wifi.wifi_name_str[7], wifi_btn_label_size);

    mks_lvgl_long_sroll_label_with_wight_set_center(wifi_src1, wifi_label_back, 20, 50, "Back", 60);
}


void mks_wifi_show_label(void) {

    wifi_label_line1 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line1, wifi_label_line1, 0, 0, mks_wifi.wifi_name_str[0], wifi_btn_label_size);
    wifi_label_line2 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line2, wifi_label_line2, 0, 0, mks_wifi.wifi_name_str[1], wifi_btn_label_size);
    wifi_label_line3 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line3, wifi_label_line3, 0, 0, mks_wifi.wifi_name_str[2], wifi_btn_label_size);
    wifi_label_line4 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line4, wifi_label_line4, 0, 0, mks_wifi.wifi_name_str[3], wifi_btn_label_size);
    wifi_label_line5 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line5, wifi_label_line5, 0, 0, mks_wifi.wifi_name_str[4], wifi_btn_label_size);
    wifi_label_line6 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line6, wifi_label_line6, 0, 0, mks_wifi.wifi_name_str[5], wifi_btn_label_size);
    wifi_label_line7 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line7, wifi_label_line7, 0, 0, mks_wifi.wifi_name_str[6], wifi_btn_label_size);
    wifi_label_line8 = mks_lvgl_long_sroll_label_with_wight_set(wifi_btn_line8, wifi_label_line8, 0, 0, mks_wifi.wifi_name_str[7], wifi_btn_label_size);
}

void mks_wifi_del_label(void) { 

	lv_obj_del(wifi_label_line1);
	lv_obj_del(wifi_label_line2);
	lv_obj_del(wifi_label_line3);
	lv_obj_del(wifi_label_line4);
	lv_obj_del(wifi_label_line5);
	lv_obj_del(wifi_label_line6);
	lv_obj_del(wifi_label_line7);
	lv_obj_del(wifi_label_line8);
}

void mks_clear_wifi(void) {
    // mks_grbl.wifi_check_status = false;
	lv_obj_clean(mks_src);
}




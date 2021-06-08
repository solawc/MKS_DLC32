#include "mks_draw_wifi.h"
#include "../WebUI/WifiConfig.h"


#if defined(USE_WIFI)
static lv_style_t btn_press_style;
static lv_style_t line_style;

MKS_WIFI_PAGE_T wifi_src;


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

char wifi_send_username[128];
char wifi_send_password[128];

LV_IMG_DECLARE(back);			//先申明此图片
LV_IMG_DECLARE(Next);			//先申明此图片
LV_IMG_DECLARE(Previous);			//先申明此图片


static void event_handler_wifi_up(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        if(mks_wifi.wifi_show_page == 1) {

        }else{
            mks_wifi_del_label();
            // mks_wifi_scanf();
           
            if(mks_wifi.wifi_show_page == 2) {
                mks_wifi.wifi_show_page = 1;
            }else if(mks_wifi.wifi_show_page == 1) {
            
            }
            mks_wifi_show_label();
            // mks_wifi.wifi_show_page--;
        }
	}
}

static void event_handler_wifi_scanf(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        mks_lv_clean_ui();
        mks_draw_wifi_scanf();
    }
}

static void event_handler_wifi_next(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_wifi_del_label();
        if(mks_wifi.wifi_show_page == 1) {
                mks_wifi.wifi_show_page = 2;
        }else if(mks_wifi.wifi_show_page == 2) {

        }
        mks_wifi_show_label();
	}
}

static void event_handler_wifi_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_clear_wifi();

        if(mks_grbl.wifi_back_from == 0) {
            mks_draw_ready();
        }else if(mks_grbl.wifi_back_from == 1) {
            mks_draw_tool();
        }
	}
}

static void event_handler_wifi_disconnect(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_lv_clean_ui();
        mks_draw_wifi_disconnrcting();
        wifi_src.wifi_kb_flag = wifi_kb_send_wifi_disconnect;
	}
}
#endif


#if defined(USE_WIFI)
static void event_handler_wifi_bt1(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        wifi_src.wifi_send_num = 1+(mks_wifi.wifi_show_page-1)*8;
        mks_wifi.wifi_choose = wifi_src.wifi_send_num-1;
        draw_pos_wifi_popup("Please enter password to connect",mks_wifi.wifi_name_str[wifi_src.wifi_send_num - 1]);
	}
}

static void event_handler_wifi_bt2(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        wifi_src.wifi_send_num = 2+(mks_wifi.wifi_show_page-1)*8;
        mks_wifi.wifi_choose = wifi_src.wifi_send_num-1;
        draw_pos_wifi_popup("Please enter password to connect",mks_wifi.wifi_name_str[wifi_src.wifi_send_num - 1]);
	}
}

static void event_handler_wifi_bt3(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        wifi_src.wifi_send_num = 3+(mks_wifi.wifi_show_page-1)*8;
        mks_wifi.wifi_choose = wifi_src.wifi_send_num-1;
        draw_pos_wifi_popup("Please enter password to connect",mks_wifi.wifi_name_str[wifi_src.wifi_send_num - 1]);
	}
}

static void event_handler_wifi_bt4(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        wifi_src.wifi_send_num = 4+(mks_wifi.wifi_show_page-1)*8;
        mks_wifi.wifi_choose = wifi_src.wifi_send_num-1;
        draw_pos_wifi_popup("Please enter password to connect",mks_wifi.wifi_name_str[wifi_src.wifi_send_num - 1]);
	}
}

static void event_handler_wifi_bt5(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        wifi_src.wifi_send_num = 5+(mks_wifi.wifi_show_page-1)*8;
        mks_wifi.wifi_choose = wifi_src.wifi_send_num-1;
        draw_pos_wifi_popup("Please enter password to connect",mks_wifi.wifi_name_str[wifi_src.wifi_send_num - 1]);
	}
}

static void event_handler_wifi_bt6(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

        wifi_src.wifi_send_num = 6+(mks_wifi.wifi_show_page-1)*8;
        mks_wifi.wifi_choose = wifi_src.wifi_send_num-1;
        draw_pos_wifi_popup("Please enter password to connect",mks_wifi.wifi_name_str[wifi_src.wifi_send_num - 1]);
	}
}

static void event_handler_wifi_bt7(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        wifi_src.wifi_send_num = 7+(mks_wifi.wifi_show_page-1)*8;
        mks_wifi.wifi_choose = wifi_src.wifi_send_num-1;
        draw_pos_wifi_popup("Please enter password to connect",mks_wifi.wifi_name_str[wifi_src.wifi_send_num - 1]);
	}
}

static void event_handler_wifi_bt8(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        wifi_src.wifi_send_num = 8+mks_wifi.wifi_show_page*8;
        mks_wifi.wifi_choose = wifi_src.wifi_send_num-1;
        draw_pos_wifi_popup("Please enter password to connect",mks_wifi.wifi_name_str[wifi_src.wifi_send_num - 1]);
	}
}

static void event_handler_wifi_kb_event(lv_obj_t* obj, lv_event_t event) {

    char username_cmd[128] = "[ESP100]";
    char password_cmd[128] = "[ESP101]";
    char enter_cmd[2] = "\n";

    if(obj == wifi_src.wifi_kb) {

        lv_kb_def_event_cb(obj, event);

        if(event == LV_EVENT_VALUE_CHANGED) {
            
        }else if(event == LV_EVENT_APPLY) {
            
            // strcpy(wifi_send_username, mks_wifi.wifi_name_str[wifi_src.wifi_send_num]);
            // strcpy(wifi_send_password, lv_ta_get_text(wifi_src.wifi_tb));

            // strcat(username_cmd, mks_wifi.wifi_name_str[wifi_src.wifi_send_num-1]);
            // strcat(password_cmd, lv_ta_get_text(wifi_src.wifi_tb));
            // strcat(username_cmd,enter_cmd);
            // strcat(password_cmd,enter_cmd);

            // strcpy(wifi_send_username, username_cmd);
            // strcpy(wifi_send_password, password_cmd);

            // wifi_src.wifi_kb_flag = wifi_kb_send_wifi_username;
         
            // lv_obj_del(wifi_src.wifi_kb); // 删除键盘
            // lv_obj_del(wifi_src.wifi_tb); // 删除文本框
            // lv_obj_del(wifi_src.wifi_kb_src_1); // 删除键盘界面
            
        }
        else if(event == LV_EVENT_CANCEL) {
            mks_lv_clean_ui();
            mks_draw_wifi();
        }
    }
}

void mks_draw_wifi(void) {

    // mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING; 
	// mks_ui_page.wait_count = DEFAULT_UI_COUNT;
    
    if(mks_get_wifi_status() == false) {    // 进入没有连接的页面

        mks_wifi_scanf();
        if(mks_wifi.wifi_scanf_status == wifi_scanf_begin || mks_wifi.wifi_scanf_status == wifi_scanf_waitting) {
            mks_draw_wifi_scanf();
        }else {
            mks_draw_wifi_show();
        }
    }else { // 进入已经连接的页面
        mks_draw_wifi_had_connect();
    }

    mks_ui_page.mks_ui_page = MKS_UI_Wifi; 
}


void mks_draw_wifi_scanf(void) { 
    wifi_src.wifi_label_info = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, wifi_src.wifi_label_scanf, 200, 150, "Wifi Scanf....", 0);
    mks_wifi.wifi_scanf_status = wifi_scanf_begin;
}

void mks_draw_wifi_connecting(void) { 
    wifi_src.wifi_label_info = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, wifi_src.wifi_label_scanf, 200, 150, "Wifi Connecting....", 0);
    mks_wifi.wifi_scanf_status = wifi_connecting;
}

void mks_draw_wifi_disconnrcting(void) {
    wifi_src.wifi_label_info = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, wifi_src.wifi_label_scanf, 200, 150, "Wifi Disconnecting....", 0);
    mks_wifi.wifi_scanf_status = wifi_disconnecting;
}


void mks_draw_wifi_show(void) {

    wifi_src.wifi_kb_flag = wifi_kb_none_flag;   // 清空wifi连接状态

    wifi_src.wifi_src_1 = lv_obj_create(mks_src, NULL);
    lv_obj_set_size( wifi_src.wifi_src_1, wifi_src1_x_size, wifi_src1_y_size);
    lv_obj_set_pos( wifi_src.wifi_src_1, wifi_src1_x, wifi_src1_y);

    lv_style_copy(&wifi_src.wifi_scr1_style, &lv_style_scr);
    wifi_src.wifi_scr1_style.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    wifi_src.wifi_scr1_style.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    wifi_src.wifi_scr1_style.text.color = LV_COLOR_WHITE;
    wifi_src.wifi_scr1_style.body.radius = 17;
    lv_obj_set_style(wifi_src.wifi_src_1, &wifi_src.wifi_scr1_style);

    lv_style_copy(&btn_press_style, &lv_style_scr);
    btn_press_style.body.main_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    btn_press_style.body.grad_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    btn_press_style.body.opa = LV_OPA_COVER;        //设置背景色完全不透明
    btn_press_style.text.color = LV_COLOR_WHITE;

    /* 创建按键 */
    wifi_src.wifi_btn_line1 = mks_lv_btn_set(mks_src, wifi_src.wifi_btn_line1,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x, wifi_first_btn_y ,event_handler_wifi_bt1);
    wifi_src.wifi_btn_line2 = mks_lv_btn_set(mks_src, wifi_src.wifi_btn_line2,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x, wifi_first_btn_y+50 ,event_handler_wifi_bt2);
    wifi_src.wifi_btn_line3 = mks_lv_btn_set(mks_src, wifi_src.wifi_btn_line3,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x, wifi_first_btn_y+100 ,event_handler_wifi_bt3);
    wifi_src.wifi_btn_line4 = mks_lv_btn_set(mks_src, wifi_src.wifi_btn_line4,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x, wifi_first_btn_y+150 ,event_handler_wifi_bt4);
    wifi_src.wifi_btn_line5 = mks_lv_btn_set(mks_src, wifi_src.wifi_btn_line5,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x+230, wifi_first_btn_y ,event_handler_wifi_bt5);
    wifi_src.wifi_btn_line6 = mks_lv_btn_set(mks_src, wifi_src.wifi_btn_line6,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x+230, wifi_first_btn_y+50 ,event_handler_wifi_bt6);
    wifi_src.wifi_btn_line7 = mks_lv_btn_set(mks_src, wifi_src.wifi_btn_line7,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x+230, wifi_first_btn_y+100 ,event_handler_wifi_bt7);
    wifi_src.wifi_btn_line8 = mks_lv_btn_set(mks_src, wifi_src.wifi_btn_line8,  wifi_btn_w, wifi_btn_h, wifi_first_btn_x+230, wifi_first_btn_y+150 ,event_handler_wifi_bt8);

    wifi_src.wifi_btn_scanf = mks_lv_btn_set(wifi_src.wifi_src_1, wifi_src.wifi_btn_scanf, 100, 40, 80, 25, event_handler_wifi_scanf);
    wifi_src.wifi_btn_up = mks_lv_btn_set(wifi_src.wifi_src_1, wifi_src.wifi_btn_up, 100, 40, 200, 25, event_handler_wifi_up);
    wifi_src.wifi_btn_next = mks_lv_btn_set(wifi_src.wifi_src_1, wifi_src.wifi_btn_next, 100, 40, 320, 25, event_handler_wifi_next);

    wifi_src.wifi_imgbtn_back = lv_imgbtn_creat_mks(wifi_src.wifi_src_1, wifi_src.wifi_imgbtn_back, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10, event_handler_wifi_back);

    lv_btn_set_style(wifi_src.wifi_btn_line1, LV_BTN_STYLE_REL, &btn_press_style);
    lv_btn_set_style(wifi_src.wifi_btn_line1,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_src.wifi_btn_line2,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_src.wifi_btn_line2,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_src.wifi_btn_line3,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_src.wifi_btn_line3,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_src.wifi_btn_line4,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_src.wifi_btn_line4,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_src.wifi_btn_line5,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_src.wifi_btn_line5,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_src.wifi_btn_line6,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_src.wifi_btn_line6,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_src.wifi_btn_line7,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_src.wifi_btn_line7,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_src.wifi_btn_line8,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_src.wifi_btn_line8,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(wifi_src.wifi_imgbtn_back,LV_BTN_STYLE_REL,&btn_press_style);
    lv_btn_set_style(wifi_src.wifi_imgbtn_back,LV_BTN_STYLE_PR,&btn_press_style);

    lv_style_copy(&line_style, &lv_style_plain);
    line_style.line.color = LV_COLOR_MAKE(0x00, 0x3b, 0x75);
    line_style.line.width = 1;
    line_style.line.rounded = 1;

    wifi_src.wifi_line1 = mks_lv_set_line(mks_src, wifi_src.wifi_line1, wifi_line_points[0]);
    lv_line_set_style(wifi_src.wifi_line1, LV_LINE_STYLE_MAIN, &line_style);
    wifi_src.wifi_line2 = mks_lv_set_line(mks_src, wifi_src.wifi_line2, wifi_line_points[1]);
    lv_line_set_style(wifi_src.wifi_line2, LV_LINE_STYLE_MAIN, &line_style);
    wifi_src.wifi_line3 = mks_lv_set_line(mks_src, wifi_src.wifi_line3, wifi_line_points[2]);
    lv_line_set_style(wifi_src.wifi_line3, LV_LINE_STYLE_MAIN, &line_style);
    wifi_src.wifi_line4 = mks_lv_set_line(mks_src, wifi_src.wifi_line4, wifi_line_points[3]);
    lv_line_set_style(wifi_src.wifi_line4, LV_LINE_STYLE_MAIN, &line_style);
    wifi_src.wifi_line5 = mks_lv_set_line(mks_src, wifi_src.wifi_line5, wifi_line_points[4]);
    lv_line_set_style(wifi_src.wifi_line5, LV_LINE_STYLE_MAIN, &line_style);
    wifi_src.wifi_line6 = mks_lv_set_line(mks_src, wifi_src.wifi_line6, wifi_line_points[5]);
    lv_line_set_style(wifi_src.wifi_line6, LV_LINE_STYLE_MAIN, &line_style);
    wifi_src.wifi_line7 = mks_lv_set_line(mks_src, wifi_src.wifi_line7, wifi_line_points[6]);
    lv_line_set_style(wifi_src.wifi_line7, LV_LINE_STYLE_MAIN, &line_style);
    wifi_src.wifi_line8 = mks_lv_set_line(mks_src, wifi_src.wifi_line8, wifi_line_points[7]);
    lv_line_set_style(wifi_src.wifi_line8, LV_LINE_STYLE_MAIN, &line_style);

    mks_wifi.wifi_show_page = 1;
    mks_wifi.begin_scanf_num = 0;

    wifi_src.wifi_label_line1 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line1, wifi_src.wifi_label_line1, 0, 0, mks_wifi.wifi_name_str[0], wifi_btn_label_size);
    wifi_src.wifi_label_line2 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line2, wifi_src.wifi_label_line2, 0, 0, mks_wifi.wifi_name_str[1], wifi_btn_label_size);
    wifi_src.wifi_label_line3 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line3, wifi_src.wifi_label_line3, 0, 0, mks_wifi.wifi_name_str[2], wifi_btn_label_size);
    wifi_src.wifi_label_line4 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line4, wifi_src.wifi_label_line4, 0, 0, mks_wifi.wifi_name_str[3], wifi_btn_label_size);
    wifi_src.wifi_label_line5 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line5, wifi_src.wifi_label_line5, 0, 0, mks_wifi.wifi_name_str[4], wifi_btn_label_size);
    wifi_src.wifi_label_line6 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line6, wifi_src.wifi_label_line6, 0, 0, mks_wifi.wifi_name_str[5], wifi_btn_label_size);
    wifi_src.wifi_label_line7 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line7, wifi_src.wifi_label_line7, 0, 0, mks_wifi.wifi_name_str[6], wifi_btn_label_size);
    wifi_src.wifi_label_line8 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line8, wifi_src.wifi_label_line8, 0, 0, mks_wifi.wifi_name_str[7], wifi_btn_label_size);

    mks_lvgl_long_sroll_label_with_wight_set_center(wifi_src.wifi_src_1, wifi_src.wifi_label_back, 20, 50, "Back", 60);
    wifi_src.wifi_label_up = mks_lvgl_long_sroll_label_with_wight_set_center(wifi_src.wifi_btn_up, wifi_src.wifi_label_up, 0, 0, "UP", 60);
	wifi_src.wifi_label_next = mks_lvgl_long_sroll_label_with_wight_set_center(wifi_src.wifi_btn_next, wifi_src.wifi_label_next, 0, 0, "Next", 60);
    wifi_src.wifi_label_scanf = mks_lvgl_long_sroll_label_with_wight_set_center(wifi_src.wifi_btn_scanf, wifi_src.wifi_label_scanf, 0, 0, "Scanf", 60);

    mks_ui_page.mks_ui_page = MKS_UI_Wifi; 
	mks_ui_page.wait_count = DEFAULT_UI_COUNT;
}

void mks_draw_wifi_had_connect(void) {

    char us_str[255]="WIFI:";
    char ip_str[255]="IP:";

    wifi_src.wifi_btn_disconnect = mks_lv_btn_set(mks_src, wifi_src.wifi_btn_disconnect, 100, 50,  480-120, 10, event_handler_wifi_disconnect);
    label_for_app_name(wifi_src.wifi_btn_disconnect, wifi_src.wifi_label_back, 0, 0, "Disconnect");

    wifi_src.wifi_imgbtn_back = mks_lv_btn_set(mks_src, wifi_src.wifi_imgbtn_back, 100, 50,  480-120, 320-60, event_handler_wifi_back);
    label_for_app_name(wifi_src.wifi_imgbtn_back, wifi_src.wifi_label_back, 0, 0, "Back");

    strcat(us_str, mks_wifi.wifi_name_connect);
    strcat(ip_str, WiFi.localIP().toString().c_str());
    wifi_src.wifi_label_username = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, wifi_src.wifi_label_username, 10, 10, us_str, 0);
    wifi_src.wifi_label_ip = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, wifi_src.wifi_label_ip, 10, 30, ip_str , 0);

    mks_ui_page.mks_ui_page = MKS_UI_Wifi; 
	mks_ui_page.wait_count = DEFAULT_UI_COUNT;
}

static void event_handler_wifi_connnect(lv_obj_t* obj, lv_event_t event) {

    char username_cmd[128] = "[ESP100]";
    char password_cmd[128] = "[ESP101]";
    char enter_cmd[2] = "\n";
    
	if (event == LV_EVENT_RELEASED) {
        
        memset(mks_wifi.wifi_name_connect, 0, sizeof(mks_wifi.wifi_name_connect));
        memset(wifi_send_username, 0, sizeof(wifi_send_username));
        memset(wifi_send_password, 0, sizeof(wifi_send_password));

        strcpy(mks_wifi.wifi_name_connect, mks_wifi.wifi_name_str[mks_wifi.wifi_choose]);

        strcat(username_cmd, mks_wifi.wifi_name_str[wifi_src.wifi_send_num-1]);
        strcat(password_cmd, lv_ta_get_text(wifi_src.wifi_tb));

        strcat(username_cmd,enter_cmd);
        strcat(password_cmd,enter_cmd);

        strcpy(wifi_send_username, username_cmd);
        strcpy(wifi_send_password, password_cmd);

        mks_lv_clean_ui();
        mks_draw_wifi_connecting();

        wifi_src.wifi_kb_flag = wifi_kb_send_wifi_username;
	}
}

uint8_t wifi_div(int32_t rssi) {

    if (rssi <= -100) {
            return 0;
        }
        if (rssi >= -50) {
            return 100;
        }
    return 2 * (rssi + 100);
}



void mks_draw_wifi_kb(char *username) {
    char un_str[138]="username:";
    char rssi_str[138];
    uint8_t get_rssi = 0;

    wifi_src.wifi_kb_src_1 = lv_obj_create(mks_src, NULL);
    lv_obj_set_size(wifi_src.wifi_kb_src_1, wifi_src_kb_x_size, wifi_src_kb_y_size);
    lv_obj_set_pos(wifi_src.wifi_kb_src_1, wifi_src_kb_x, wifi_src_kb_y);

    lv_style_copy(&wifi_src.wifi_src_style, &lv_style_scr);
	wifi_src.wifi_src_style.body.main_color = LV_COLOR_MAKE(0x13, 0x12, 0x1a); 
    wifi_src.wifi_src_style.body.grad_color = LV_COLOR_MAKE(0x13, 0x12, 0x1a); 
    wifi_src.wifi_src_style.text.color = LV_COLOR_WHITE;
    wifi_src.wifi_src_style.body.radius = 17;
	lv_obj_set_style(wifi_src.wifi_kb_src_1, &wifi_src.wifi_src_style);

    wifi_src.wifi_kb = mks_lv_set_kb(wifi_src.wifi_kb_src_1, wifi_src.wifi_kb, event_handler_wifi_kb_event);
    wifi_src.wifi_tb = mks_lv_set_ta(wifi_src.wifi_kb_src_1 ,wifi_src.wifi_tb, wifi_src.wifi_kb);

    wifi_src.wifi_btn_connect = mks_lv_btn_set(wifi_src.wifi_kb_src_1, wifi_src.wifi_btn_connect,80, 80, 300, 10, event_handler_wifi_connnect);

    strcat(un_str, username);

    get_rssi = wifi_div(mks_wifi.wifi_rssi[mks_wifi.wifi_choose]);
    sprintf(rssi_str, "RSSI:%d%%", get_rssi);

    wifi_src.wifi_label_username = mks_lvgl_long_sroll_label_with_wight_set_center(wifi_src.wifi_kb_src_1, wifi_src.wifi_label_username, 10, 5, un_str, 0);
    wifi_src.wifi_label_password = mks_lvgl_long_sroll_label_with_wight_set_center(wifi_src.wifi_kb_src_1, wifi_src.wifi_label_password, 10, 30,"password:", 0);
    wifi_src.wifi_label_riss = mks_lvgl_long_sroll_label_with_wight_set_center(wifi_src.wifi_kb_src_1, wifi_src.wifi_label_riss, 10, 55, rssi_str , 0);
    wifi_src.wifi_label_connect = mks_lvgl_long_sroll_label_with_wight_set_center(wifi_src.wifi_btn_connect, wifi_src.wifi_label_connect, 0, 0,"Connect", 0);
}

void mks_wifi_show_label(void) {
    wifi_src.wifi_label_line1 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line1, wifi_src.wifi_label_line1, 0, 0, mks_wifi.wifi_name_str[0+(mks_wifi.wifi_show_page - 1)*8], wifi_btn_label_size);
    wifi_src.wifi_label_line2 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line2, wifi_src.wifi_label_line2, 0, 0, mks_wifi.wifi_name_str[1+(mks_wifi.wifi_show_page - 1)*8], wifi_btn_label_size);
    wifi_src.wifi_label_line3 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line3, wifi_src.wifi_label_line3, 0, 0, mks_wifi.wifi_name_str[2+(mks_wifi.wifi_show_page - 1)*8], wifi_btn_label_size);
    wifi_src.wifi_label_line4 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line4, wifi_src.wifi_label_line4, 0, 0, mks_wifi.wifi_name_str[3+(mks_wifi.wifi_show_page - 1)*8], wifi_btn_label_size);
    wifi_src.wifi_label_line5 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line5, wifi_src.wifi_label_line5, 0, 0, mks_wifi.wifi_name_str[4+(mks_wifi.wifi_show_page - 1)*8], wifi_btn_label_size);
    wifi_src.wifi_label_line6 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line6, wifi_src.wifi_label_line6, 0, 0, mks_wifi.wifi_name_str[5+(mks_wifi.wifi_show_page - 1)*8], wifi_btn_label_size);
    wifi_src.wifi_label_line7 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line7, wifi_src.wifi_label_line7, 0, 0, mks_wifi.wifi_name_str[6+(mks_wifi.wifi_show_page - 1)*8], wifi_btn_label_size);
    wifi_src.wifi_label_line8 = mks_lvgl_long_sroll_label_with_wight_set(wifi_src.wifi_btn_line8, wifi_src.wifi_label_line8, 0, 0, mks_wifi.wifi_name_str[7+(mks_wifi.wifi_show_page - 1)*8], wifi_btn_label_size);
}

void mks_wifi_del_label(void) { 
	lv_obj_del(wifi_src.wifi_label_line1);
	lv_obj_del(wifi_src.wifi_label_line2);
	lv_obj_del(wifi_src.wifi_label_line3);
	lv_obj_del(wifi_src.wifi_label_line4);
	lv_obj_del(wifi_src.wifi_label_line5);
	lv_obj_del(wifi_src.wifi_label_line6);
	lv_obj_del(wifi_src.wifi_label_line7);
	lv_obj_del(wifi_src.wifi_label_line8);
}


static void event_handler_wifi_popup_sure(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

        wifi_src.wifi_kb_flag = wifi_kb_send_wifi_username;
        lv_obj_del(wifi_src.wifi_popup_scr_1);
	}
}

static void event_handler_wifi_popup_cancle(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        lv_obj_del(wifi_src.wifi_popup_scr_1);
	}
}

static void event_handler_wifi_popup_pw_enter(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        // mks_draw_wifi_kb();
	}
}


void draw_pos_wifi_popup(const char *text, char *file_name) {
    char get_name[128];
    strcpy(get_name, file_name);
    mks_lv_clean_ui();
    mks_draw_wifi_kb(get_name);
}

void mks_wifi_connect(char *username, char *password) {

    if(wifi_src.wifi_kb_flag == wifi_kb_send_wifi_username) {
        MKS_GRBL_CMD_SEND(username);
        wifi_src.wifi_kb_flag = wifi_kb_send_wifi_STA_mode;
    }
    else if(wifi_src.wifi_kb_flag == wifi_kb_send_wifi_STA_mode) {
        MKS_GRBL_CMD_SEND("[ESP110]STA\n");
        wifi_src.wifi_kb_flag = wifi_kb_send_wifi_PORT;
    }
    else if(wifi_src.wifi_kb_flag == wifi_kb_send_wifi_PORT) {
        MKS_GRBL_CMD_SEND("[ESP131]8080\n");
        wifi_src.wifi_kb_flag = wifi_kb_send_wifi_password;
    }
    else if(wifi_src.wifi_kb_flag == wifi_kb_send_wifi_password) {
        MKS_GRBL_CMD_SEND(password);
        wifi_src.wifi_kb_flag = wifi_kb_send_wifi_connect;
    }
    else if(wifi_src.wifi_kb_flag == wifi_kb_send_wifi_connect) {
        // WebUI::wifi_config.begin();
        MKS_GRBL_CMD_SEND("[ESP115]ON\n");
        wifi_src.wifi_kb_flag = wifi_kb_none_flag;
    }
    else if(wifi_src.wifi_kb_flag == wifi_kb_send_wifi_disconnect) {
        MKS_GRBL_CMD_SEND("[ESP115]OFF\n");
        wifi_src.wifi_kb_flag = wifi_kb_none_flag;
    }
}

void mks_clear_wifi(void) {
	lv_obj_clean(mks_src);
}


#endif


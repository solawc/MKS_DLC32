#include "MKS_draw_ready.h"

MKS_PAGE_READY ready_src;
lv_style_t bkl_color;    // main

LV_IMG_DECLARE(Adjustment);  
LV_IMG_DECLARE(Control);  
LV_IMG_DECLARE(Sculpture);	
LV_IMG_DECLARE(Tool);	

LV_IMG_DECLARE(X_POS);	
LV_IMG_DECLARE(Y_POS);	
LV_IMG_DECLARE(Z_POS);	
LV_IMG_DECLARE(wifi_status);	
LV_IMG_DECLARE(me_status);	
LV_IMG_DECLARE(M_pwr);	

static void event_handler_Adjustment(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        mks_lv_clean_ui();
        mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_power();
	}
}

static void event_handler_Control(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        mks_lv_clean_ui();
        mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_move();
	}
}


static void event_handler_Sculpture(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        mks_lv_clean_ui();
        mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        file_popup_select_flag = false;
        mks_draw_craving();
	}
}

static void event_handler_Tool(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        mks_lv_clean_ui();
        mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_tool();
	}
}

static void event_handler_wifi(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
#if defined(USE_WIFI)
        mks_lv_clean_ui();
        mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_grbl.wifi_back_from = 0;
        mks_draw_wifi();
#endif
	}
}

static void event_handler_none(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {

	}
}

// char xpos_str[50] = "0.00";
// char status_str[50];
// char ypos_str[50] = "0.00";
// char zpos_str[50] = "0.00";
// char mpwr_str[50] = "100%";
// char wifi_status_str[50];
// char wifi_ip_str[100];


void mks_draw_ready(void) {

    mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;

    mks_src = lv_obj_create(NULL, NULL);
	mks_src = lv_scr_act();

    ready_src.ready_src_1 = lv_obj_create(mks_src, NULL);
    lv_obj_set_size(ready_src.ready_src_1, READY_src1_x_size, READY_src1_y_size);
    lv_obj_set_pos(ready_src.ready_src_1, READY_src1_x, READY_src1_y);

    lv_style_copy(&bkl_color, &lv_style_scr);
    bkl_color.body.grad_color = LV_COLOR_MAKE(0x13, 0x12, 0x1a);
	bkl_color.body.main_color = LV_COLOR_MAKE(0x13, 0x12, 0x1a);
    bkl_color.text.color = LV_COLOR_WHITE;
	lv_obj_set_style(mks_src ,&bkl_color);

    lv_style_copy(&ready_src.ready_src1_style, &lv_style_scr);
    ready_src.ready_src1_style.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    ready_src.ready_src1_style.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    ready_src.ready_src1_style.text.color = LV_COLOR_WHITE;
    ready_src.ready_src1_style.body.radius = 17;
    lv_obj_set_style(ready_src.ready_src_1, &ready_src.ready_src1_style);
    
    lv_imgbtn_creat_mks(ready_src.ready_src_1, ready_src.ready_imgbtn_Adjustment, &Adjustment, &Adjustment, LV_ALIGN_CENTER, -150, -10, event_handler_Adjustment);
    lv_imgbtn_creat_mks(ready_src.ready_src_1, ready_src.ready_imgbtn_Control, &Control, &Control, LV_ALIGN_CENTER,-50, -10, event_handler_Control);
    lv_imgbtn_creat_mks(ready_src.ready_src_1, ready_src.ready_imgbtn_Sculpture, &Sculpture, &Sculpture, LV_ALIGN_CENTER, 50, -10, event_handler_Sculpture);
    lv_imgbtn_creat_mks(ready_src.ready_src_1, ready_src.ready_imgbtn_Tool, &Tool, &Tool, LV_ALIGN_CENTER, 150, -10, event_handler_Tool);

    lv_imgbtn_creat_n_mks(mks_src ,ready_src.ready_imgbtn_xpos, &X_POS,  &X_POS, READY_FIRST_IMG_X+30, READY_FIRST_IMG_Y + 40, event_handler_none);
    lv_imgbtn_creat_n_mks(mks_src ,ready_src.ready_imgbtn_ypos, &Y_POS,  &Y_POS, READY_FIRST_IMG_X+160, READY_FIRST_IMG_Y + 40, event_handler_none);
    lv_imgbtn_creat_n_mks(mks_src ,ready_src.ready_imgbtn_zpos, &Z_POS,  &Z_POS, READY_FIRST_IMG_X+290, READY_FIRST_IMG_Y + 40, event_handler_none);
    lv_imgbtn_creat_n_mks(mks_src ,ready_src.ready_imgbtn_pwr,  &M_pwr,  &M_pwr, READY_FIRST_IMG_X+30, READY_FIRST_IMG_Y + 80, event_handler_none);
    lv_imgbtn_creat_n_mks(mks_src ,ready_src.ready_imgbtn_wifi_status, &wifi_status, &wifi_status, READY_FIRST_IMG_X+160, READY_FIRST_IMG_Y + 80, event_handler_none);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    lv_style_copy(&ready_src.ready_btn_wifi_style, &lv_style_scr); 
    ready_src.ready_btn_wifi_style.body.main_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    ready_src.ready_btn_wifi_style.body.grad_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    ready_src.ready_btn_wifi_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    ready_src.ready_btn_wifi_style.text.color = LV_COLOR_WHITE;

    ready_src.ready_btn_wifi = mks_lv_btn_set(mks_src, ready_src.ready_btn_wifi, 150, 30, READY_FIRST_LABEL_X+195, READY_FIRST_LABEL_Y+80, event_handler_wifi);
    lv_btn_set_style(ready_src.ready_btn_wifi, LV_BTN_STYLE_REL, &ready_src.ready_btn_wifi_style);
    lv_btn_set_style(ready_src.ready_btn_wifi,LV_BTN_STYLE_PR, &ready_src.ready_btn_wifi_style);

    mks_lvgl_long_sroll_label_with_wight_set_center(ready_src.ready_src_1, ready_src.ready_label_Adjustment, 40, 80, "Adjustment", 100);
    mks_lvgl_long_sroll_label_with_wight_set_center(ready_src.ready_src_1, ready_src.ready_label_Control,150, 80, "Control", 100);
    mks_lvgl_long_sroll_label_with_wight_set_center(ready_src.ready_src_1, ready_src.ready_label_Sculpture, 250, 80, "Sculpture", 100);
    mks_lvgl_long_sroll_label_with_wight_set_center(ready_src.ready_src_1, ready_src.ready_label_Tool, 360, 80, "Tool", 100);

    ready_src.ready_label_status = mks_lv_static_label(mks_src, ready_src.ready_label_status, READY_FIRST_LABEL_X, READY_FIRST_LABEL_Y+110, " ", 50);
    ready_src.ready_label_xpos = mks_lv_static_label(mks_src, ready_src.ready_label_xpos, READY_FIRST_LABEL_X+60, READY_FIRST_LABEL_Y+45, "0", 50);
    ready_src.ready_label_ypos = mks_lv_static_label(mks_src, ready_src.ready_label_ypos, READY_FIRST_LABEL_X+190,READY_FIRST_LABEL_Y+45, "0", 50);
    ready_src.ready_label_zpos = mks_lv_static_label(mks_src, ready_src.ready_label_zpos, READY_FIRST_LABEL_X+320,READY_FIRST_LABEL_Y+45, "0", 50);
    ready_src.ready_label_mpwr = mks_lv_static_label(mks_src, ready_src.ready_label_mpwr, READY_FIRST_LABEL_X+60, READY_FIRST_LABEL_Y+85, "0", 50);

    // ready_src.ready_label_xpos = mks_lv_static_label(mks_src, ready_src.ready_label_xpos, READY_FIRST_LABEL_X+60, READY_FIRST_LABEL_Y+45, xpos_str, 50);
    // ready_src.ready_label_ypos = mks_lv_static_label(mks_src, ready_src.ready_label_ypos, READY_FIRST_LABEL_X+190,READY_FIRST_LABEL_Y+45, ypos_str, 50);
    // ready_src.ready_label_zpos = mks_lv_static_label(mks_src, ready_src.ready_label_zpos, READY_FIRST_LABEL_X+320,READY_FIRST_LABEL_Y+45, zpos_str, 50);
    // ready_src.ready_label_mpwr = mks_lv_static_label(mks_src, ready_src.ready_label_mpwr, READY_FIRST_LABEL_X+60, READY_FIRST_LABEL_Y+85, mpwr_str, 50);


    if (mks_grbl.wifi_connect_status == true) {
        if(WiFi.getMode() == WIFI_STA) {
                ready_src.ready_label_wifi_status = mks_lv_static_label(ready_src.ready_btn_wifi, ready_src.ready_label_wifi_status, 40, 0, WiFi.localIP().toString().c_str(), 130);
        }else{
                ready_src.ready_label_wifi_status = mks_lv_static_label(ready_src.ready_btn_wifi, ready_src.ready_label_wifi_status, 40, 0, WiFi.softAPIP().toString().c_str(), 130);
            }
    } 
    else if (mks_grbl.wifi_connect_status == false) {
        ready_src.ready_label_wifi_status = mks_lv_static_label(ready_src.ready_btn_wifi, ready_src.ready_label_wifi_status, 40, 0, "Disconnect", 110);
    }  

    lv_refr_now(lv_refr_get_disp_refreshing());
    mks_ui_page.mks_ui_page = MKS_UI_Ready;
    mks_ui_page.wait_count = 1;
}

char xpos_str[50] = "0.0";
char status_str[50];
char ypos_str[50] = "0.0";
char zpos_str[50] = "0.0";
char mpwr_str[50] = "100%";
char wifi_status_str[50];
char wifi_ip_str[100];

void mks_widi_show_ip(IPAddress ip, uint8_t p) { 
    if(p) {
        strcat(wifi_ip_str, ip.toString().c_str());
        // label_wifi_ip = mks_lv_label_updata(label_wifi_ip, wifi_ip_str);
    }else {
    }
}


void ready_data_updata(void) {

    static uint8_t wifi_ref_count = 0;
    static float mks_print_position[MAX_N_AXIS];

    system_convert_array_steps_to_mpos(mks_print_position, sys_position);

    sprintf(xpos_str, "%.1f", mks_print_position[0]);
    sprintf(ypos_str, "%.1f", mks_print_position[1]);
    sprintf(zpos_str, "%.1f", mks_print_position[2]);
    // sprintf(mpwr_str, "%.d%%",  sys_rt_s_override);
    sprintf(mpwr_str, "%d",  sys.spindle_speed);
    
    
    lv_label_set_static_text(ready_src.ready_label_xpos, xpos_str);
    lv_label_set_static_text(ready_src.ready_label_ypos, ypos_str);
    lv_label_set_static_text(ready_src.ready_label_zpos, zpos_str);
    lv_label_set_static_text(ready_src.ready_label_mpwr, mpwr_str);
    
    // wifi_ref_count++;
    // if(wifi_ref_count == 20) {

    //     if (mks_grbl.wifi_connect_status == true) {
    //         if(WiFi.getMode() == WIFI_STA) {
    //                 strcpy(wifi_ip_str, WiFi.localIP().toString().c_str());
    //                 ready_src.ready_label_wifi_status = mks_lv_label_updata(ready_src.ready_label_wifi_status, wifi_ip_str);
    //         }else{
    //                 strcpy(wifi_ip_str, WiFi.softAPIP().toString().c_str());
    //                 ready_src.ready_label_wifi_status = mks_lv_label_updata(ready_src.ready_label_wifi_status, WiFi.softAPIP().toString().c_str());
    //             }
    //         } 
    //         else if (mks_grbl.wifi_connect_status == false) {
    //             ready_src.ready_label_wifi_status = mks_lv_label_updata(ready_src.ready_label_wifi_status, "Disconnect");
    //         }  
    //     wifi_ref_count = 0;
    // }
     if (mks_get_wifi_status() == false){
        ready_src.ready_label_wifi_status = mks_lv_label_updata(ready_src.ready_label_wifi_status, "Disconnect");
     }
    else {
        ready_src.ready_label_wifi_status = mks_lv_label_updata(ready_src.ready_label_wifi_status, "Connect");
    }
}





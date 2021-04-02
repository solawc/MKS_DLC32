#include "MKS_draw_ready.h"


ready_data_t ready_data;

lv_obj_t* ready_scr1;
lv_style_t bkl_color;
lv_style_t bkl_color1;
lv_style_t btn_wifi_color;

lv_obj_t* imgbtn_Adjustment;
lv_obj_t* imgbtn_Control;
lv_obj_t* imgbtn_Sculpture;
lv_obj_t* imgbtn_Tool;

lv_obj_t* btn_wifi;

lv_obj_t* label_Adjustment;
lv_obj_t* label_Control;
lv_obj_t* label_Sculpture;
lv_obj_t* label_Tool;

lv_obj_t* icon_status;
lv_obj_t* icon_xpos;
lv_obj_t* icon_ypos;
lv_obj_t* icon_zpos;
lv_obj_t* icon_wifi_status;

lv_obj_t* label_status;
lv_obj_t* label_xpos;
lv_obj_t* label_ypos;
lv_obj_t* label_zpos;
lv_obj_t* label_wifi_status;

LV_IMG_DECLARE(Adjustment);  
LV_IMG_DECLARE(Control);  
LV_IMG_DECLARE(Sculpture);	
LV_IMG_DECLARE(Tool);	

LV_IMG_DECLARE(X_POS);	
LV_IMG_DECLARE(Y_POS);	
LV_IMG_DECLARE(Z_POS);	
LV_IMG_DECLARE(wifi_status);	
LV_IMG_DECLARE(me_status);	

static void event_handler_Adjustment(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        lv_clean_curren_screen();
        mks_ui_page.mks_ui_page = MKS_UI_Adjust;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_power();
	}
}

static void event_handler_Control(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        lv_clean_curren_screen();
        mks_ui_page.mks_ui_page = MKS_UI_Control;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_move();
	}
}


static void event_handler_Sculpture(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        lv_clean_curren_screen();
        mks_ui_page.mks_ui_page = MKS_UI_Caving;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_craving();
	}
}


static void event_handler_Tool(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        lv_clean_curren_screen();
        mks_ui_page.mks_ui_page = MKS_UI_Tool;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_tool();
	}
}


static void event_handler_wifi(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        lv_clean_curren_screen();
        mks_ui_page.mks_ui_page = MKS_UI_Wifi;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_draw_wifi();
	}
}

void mks_draw_ready(void) {

    mks_src = lv_obj_create(NULL, NULL);
	mks_src = lv_scr_act();

    ready_scr1 = lv_obj_create(mks_src, NULL);
    lv_obj_set_size(ready_scr1, READY_src1_x_size, READY_src1_y_size);
    lv_obj_set_pos(ready_scr1, READY_src1_x, READY_src1_y);

    lv_style_copy(&bkl_color, &lv_style_scr);
    bkl_color.body.grad_color = LV_COLOR_MAKE(0x13, 0x12, 0x1a);
	bkl_color.body.main_color = LV_COLOR_MAKE(0x13, 0x12, 0x1a);
    bkl_color.text.color = LV_COLOR_WHITE;
	lv_obj_set_style(mks_src ,&bkl_color);

    lv_style_copy(&bkl_color1, &lv_style_scr);
    bkl_color1.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    bkl_color1.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    bkl_color1.text.color = LV_COLOR_WHITE;
    bkl_color1.body.radius = 17;
    lv_obj_set_style(ready_scr1, &bkl_color1);
    
    lv_imgbtn_creat_mks(ready_scr1, imgbtn_Adjustment, &Adjustment, &Adjustment, LV_ALIGN_CENTER, -150, -10, event_handler_Adjustment);
    lv_imgbtn_creat_mks(ready_scr1, imgbtn_Control, &Control, &Control, LV_ALIGN_CENTER,-50, -10, event_handler_Control);
    lv_imgbtn_creat_mks(ready_scr1, imgbtn_Sculpture, &Sculpture, &Sculpture, LV_ALIGN_CENTER, 50, -10, event_handler_Sculpture);
    lv_imgbtn_creat_mks(ready_scr1, imgbtn_Tool, &Tool, &Tool, LV_ALIGN_CENTER, 150, -10, event_handler_Tool);

    mks_lvgl_img_set(mks_src ,icon_status, &me_status, READY_FIRST_IMG_X, READY_FIRST_IMG_Y);
    mks_lvgl_img_set(mks_src ,icon_xpos, &X_POS, READY_FIRST_IMG_X, READY_FIRST_IMG_Y + 40);
    mks_lvgl_img_set(mks_src ,icon_ypos, &Y_POS, READY_FIRST_IMG_X, READY_FIRST_IMG_Y + 80);
    mks_lvgl_img_set(mks_src ,icon_zpos, &Z_POS, READY_FIRST_IMG_X, READY_FIRST_IMG_Y + 120);
    mks_lvgl_img_set(mks_src ,label_wifi_status, &wifi_status, READY_FIRST_IMG_X, READY_FIRST_IMG_Y + 160);

    
    lv_style_copy(&btn_wifi_color, &lv_style_scr);
    btn_wifi_color.body.main_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    btn_wifi_color.body.grad_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    btn_wifi_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_wifi_color.text.color = LV_COLOR_WHITE;
    btn_wifi = mks_lv_btn_set(mks_src, btn_wifi, 200,30, READY_FIRST_IMG_X + 40 ,READY_FIRST_IMG_Y + 160, event_handler_wifi);
    lv_btn_set_style(btn_wifi, LV_BTN_STYLE_REL, &btn_wifi_color);
    lv_btn_set_style(btn_wifi,LV_BTN_STYLE_PR,&btn_wifi_color);

    mks_lvgl_long_sroll_label_with_wight_set_center(ready_scr1, label_Adjustment, 40, 80, "Adjustment", 100);
    mks_lvgl_long_sroll_label_with_wight_set_center(ready_scr1, label_Control,150, 80, "Control", 100);
    mks_lvgl_long_sroll_label_with_wight_set_center(ready_scr1, label_Sculpture, 250, 80, "Sculpture", 100);
    mks_lvgl_long_sroll_label_with_wight_set_center(ready_scr1, label_Tool, 360, 80, "Tool", 100);


    // label_status = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_status, READY_FIRST_LABEL_X, READY_FIRST_LABEL_Y, "IDLE", 100);
    // label_xpos = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_xpos, READY_FIRST_LABEL_X, READY_FIRST_LABEL_Y+40, "0", 100);
    // label_ypos = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_ypos, READY_FIRST_LABEL_X,READY_FIRST_LABEL_Y+80, "0", 100);
    // label_zpos = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_zpos, READY_FIRST_LABEL_X,READY_FIRST_LABEL_Y+120, "0", 100);
    // label_wifi_status = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi, label_wifi_status, 0, 0, "DISCONNECT", 200);

    label_status = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_status, READY_FIRST_LABEL_X, READY_FIRST_LABEL_Y, " ", 100);
    label_xpos = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_xpos, READY_FIRST_LABEL_X, READY_FIRST_LABEL_Y+40, " ", 100);
    label_ypos = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_ypos, READY_FIRST_LABEL_X,READY_FIRST_LABEL_Y+80, " ", 100);
    label_zpos = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_zpos, READY_FIRST_LABEL_X,READY_FIRST_LABEL_Y+120, " ", 100);
    label_wifi_status = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi, label_wifi_status, 0, 0, " ", 200);
}


void ready_data_updata(void) {

    char xpos_str[10];
    char ypos_str[10];
    char zpos_str[10];

         if (sys.state == State::Alarm)         lv_label_set_text(label_status, "Alarm");
    else if (sys.state == State::Idle)          lv_label_set_text(label_status, "Idle");
    else if (sys.state == State::CheckMode)     lv_label_set_text(label_status, "CheckMode");
    else if (sys.state == State::Homing)        lv_label_set_text(label_status, "Homing");
    else if (sys.state == State::Cycle)         lv_label_set_text(label_status, "Cycle");
    else if (sys.state == State::Hold)          lv_label_set_text(label_status, "Hold");
    else if (sys.state == State::Jog)           lv_label_set_text(label_status, "Jog");
    else if (sys.state == State::SafetyDoor)    lv_label_set_text(label_status, "SafetyDoor");
    else if (sys.state == State::Sleep)         lv_label_set_text(label_status, "Sleep");

    sprintf(xpos_str, "%d", sys_position[0]);
    sprintf(ypos_str, "%d", sys_position[1]);
    sprintf(zpos_str, "%d", sys_position[2]);
    lv_label_set_text(label_xpos, xpos_str);
    lv_label_set_text(label_ypos, ypos_str);
    lv_label_set_text(label_zpos, zpos_str);

         if (mks_grbl.wifi_connect_status == true) lv_label_set_text(label_wifi_status, "Connect");
    else if (mks_grbl.wifi_connect_status == false) lv_label_set_text(label_wifi_status, "Disconnect");
}

void lv_clean_curren_screen(void) {
    lv_obj_clean(mks_src);
}




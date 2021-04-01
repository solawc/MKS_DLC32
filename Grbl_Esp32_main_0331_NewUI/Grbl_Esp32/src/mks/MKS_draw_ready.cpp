#include "MKS_draw_ready.h"


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


lv_obj_t* label_status;
lv_obj_t* label_xpos;
lv_obj_t* label_ypos;
lv_obj_t* label_wifi_status;

LV_IMG_DECLARE(Adjustment);  
LV_IMG_DECLARE(Control);  
LV_IMG_DECLARE(Sculpture);	
LV_IMG_DECLARE(Tool);	


static void event_handler_Adjustment(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        lv_clean_curren_screen();
        mks_draw_power();
	}
}

static void event_handler_Control(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        lv_clean_curren_screen();
        mks_draw_move();
	}
}


static void event_handler_Sculpture(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {

	}
}


static void event_handler_Tool(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {
        lv_clean_curren_screen();
        mks_draw_tool();
	}
}


static void event_handler_wifi(lv_obj_t* obj, lv_event_t event) { 
	
	if (event == LV_EVENT_RELEASED) {

	}
}

void mks_draw_ready(void) {

    mks_src = lv_obj_create(NULL, NULL);
	mks_src = lv_scr_act();

    ready_scr1 = lv_obj_create(mks_src, NULL);
    lv_obj_set_size(ready_scr1, 459, 109);
    lv_obj_set_pos(ready_scr1, 10, 200);

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

    lv_style_copy(&btn_wifi_color, &lv_style_scr);
    btn_wifi_color.body.main_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    btn_wifi_color.body.grad_color = LV_COLOR_MAKE(0x13, 0x12, 0x1A);
    btn_wifi_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_wifi_color.text.color = LV_COLOR_WHITE;
    btn_wifi = mks_lv_btn_set(mks_src, btn_wifi, 200,30, 20 ,0, event_handler_wifi);
    lv_btn_set_style(btn_wifi, LV_BTN_STYLE_REL, &btn_wifi_color);
    lv_btn_set_style(btn_wifi,LV_BTN_STYLE_PR,&btn_wifi_color);

    mks_lvgl_long_sroll_label_with_wight_set_center(ready_scr1, label_Adjustment, 40, 80, "Adjustment", 100);
    mks_lvgl_long_sroll_label_with_wight_set_center(ready_scr1, label_Control,150, 80, "Control", 100);
    mks_lvgl_long_sroll_label_with_wight_set_center(ready_scr1, label_Sculpture, 250, 80, "Sculpture", 100);
    mks_lvgl_long_sroll_label_with_wight_set_center(ready_scr1, label_Tool, 360, 80, "Tool", 100);

    label_status = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_status, 20, 90, "STATUS:IDLE", 100);
    label_xpos = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_xpos, 20, 60, "XPOS:0", 100);
    label_ypos = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, label_ypos, 20,30, "YPOS:0", 100);

    label_wifi_status = mks_lvgl_long_sroll_label_with_wight_set_center(btn_wifi, label_wifi_status, 0, 0, "WIFI STATUS:DISCONNECT", 200);
}

void lv_clean_curren_screen(void) {
    lv_obj_clean(mks_src);
}




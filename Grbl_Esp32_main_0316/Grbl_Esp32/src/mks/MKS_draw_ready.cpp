#include "MKS_draw_ready.h"

/* Screan Build */
// static lv_obj_t *scr;
lv_style_t bkl_color;
/* Lable */
lv_obj_t *lable_setting;   
lv_obj_t *lable_tool;
lv_obj_t *label_Carving;

lv_obj_t *setting_btn;
lv_obj_t *tool_btn;
lv_obj_t *carve_btn;

LV_IMG_DECLARE(Setting);    //先申明此图片
LV_IMG_DECLARE(Craving);    //先申明此图片
LV_IMG_DECLARE(Tool);       //先申明此图片

enum {
    ID_TOOL     = 1,
    ID_SETTING,
    ID_CARVING,
};

static void event_handler(lv_obj_t *obj, lv_event_t event) {

    if(event == LV_EVENT_PRESSED) {
        lv_clean_curren_screen();
        mks_draw_craving();
    }
}

static void event_handler_setting(lv_obj_t *obj, lv_event_t event) {
    
    if(event == LV_EVENT_PRESSED) {
        lv_clean_curren_screen();
        mks_draw_setting();
    }
}

static void event_handler_tool(lv_obj_t *obj, lv_event_t event) {

    if(event == LV_EVENT_PRESSED) {
        lv_clean_curren_screen();
        lv_draw_tool();
    }
}

void lv_draw_ready(void) {

    mks_src = lv_obj_create(NULL,NULL);
    mks_src = lv_scr_act();

    lv_style_copy(&bkl_color, &lv_style_scr);
	bkl_color.body.grad_color = LV_COLOR_MAKE(0X1A,0X1A,0X1A);
	bkl_color.body.main_color = LV_COLOR_MAKE(0X1A,0X1A,0X1A);
    bkl_color.text.color = LV_COLOR_WHITE;
	lv_obj_set_style(mks_src ,&bkl_color);
    
    lv_imgbtn_creat_mks(mks_src, tool_btn, &Tool, &Tool, LV_ALIGN_CENTER, -170, 0, event_handler_tool);
    lv_imgbtn_creat_mks(mks_src, setting_btn, &Setting, &Setting, LV_ALIGN_CENTER, 0, 0, event_handler_setting);
    lv_imgbtn_creat_mks(mks_src, carve_btn, &Craving, &Craving, LV_ALIGN_CENTER, 170, 0, event_handler);

    // mks_lvgl_label_set(scr, lable_tool, 50, 200, "#ffffff Tool#");
    // mks_lvgl_label_set(scr, lable_setting, 210, 200, "#ffffff Setting#");
    // mks_lvgl_label_set(scr, label_Carving, 380, 200, "#ffffff Carving#");
    mks_lvgl_label_set(mks_src, lable_tool, 50, 200, "Tool");
    mks_lvgl_label_set(mks_src, lable_setting, 210, 200, "Setting");
    mks_lvgl_label_set(mks_src, label_Carving, 380, 200, "Carving");
}

void lv_clean_curren_screen(void) {
    lv_obj_clean(mks_src);
}




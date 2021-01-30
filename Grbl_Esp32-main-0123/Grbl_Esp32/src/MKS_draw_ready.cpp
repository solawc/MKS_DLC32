#include "MKS_draw_ready.h"

/* Screan Build */
static lv_obj_t *scr;
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
            lv_draw_tool();
    }
}

static void event_handler_setting(lv_obj_t *obj, lv_event_t event) {
    
    if(event == LV_EVENT_PRESSED) {
        Serial.printf("setting btn press\n");
    }
}

static void event_handler_tool(lv_obj_t *obj, lv_event_t event) {

    if(event == LV_EVENT_PRESSED) {
        Serial.printf("tool btn press\n");
    }
}


void lv_draw_ready(void) {
    scr = lv_obj_create(NULL, NULL);
    scr = lv_scr_act();
    
    lv_imgbtn_creat_mks(scr, setting_btn, &Setting, &Setting, LV_ALIGN_CENTER, -120, 0, event_handler_setting);
    lv_imgbtn_creat_mks(scr, tool_btn, &Tool, &Tool, LV_ALIGN_CENTER, 0, 0, event_handler_tool);
    lv_imgbtn_creat_mks(scr, carve_btn, &Craving, &Craving, LV_ALIGN_CENTER, 120, 0, event_handler);

    mks_lvgl_label_set(scr, lable_setting, 90, 200,    "#ffffff Setting#"  );
    mks_lvgl_label_set(scr, lable_tool,    220, 200,   "#ffffff Tool#"     );
    mks_lvgl_label_set(scr, label_Carving, 330, 200,   "#ffffff Carving#"  );
}

void lv_clean_curren_screen(void) {
    // lv_obj_del();
    lv_obj_clean(scr);
}




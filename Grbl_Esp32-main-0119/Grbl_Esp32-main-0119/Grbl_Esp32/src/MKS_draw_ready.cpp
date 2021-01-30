#include "MKS_draw_ready.h"


/* Lable */
lv_obj_t *lable_setting;   
lv_obj_t *lable_tool;
lv_obj_t *label_Carving;

enum {

    ID_TOOL     = 1,
    ID_SETTING,
    ID_CARVING,
};

static void event_handler(lv_obj_t *obj, lv_event_t event) {
    if (event != LV_EVENT_RELEASED) return ;

    switch(obj->mks_obj_id) {

        case ID_TOOL: 
        break;

        case ID_SETTING:
        break;

        case ID_CARVING:
        break;
    }
}


void mks_lvgl_label_set(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text) {
    lab = lv_label_create(scr, NULL);                                                             // 创建标签
    lv_label_set_long_mode(lab, LV_LABEL_LONG_BREAK);                                       //设置长文本模式
    lv_obj_set_width(lab, 80);
    lv_obj_set_height(lab,20);
    lv_obj_set_pos(lab, x, y);
    lv_label_set_recolor(lab, true);                                                        // 使能重繪色
    lv_label_set_text(lab, text);
}

void lv_draw_ready(void) {
    lv_obj_t *scr = lv_scr_act();  //获取当前活跃的屏幕对象
    mks_lvgl_label_set(scr, lable_setting, 100, 210,    "#ff0000 Setting#"  );
    mks_lvgl_label_set(scr, lable_tool,    210, 210,    "#ff0000 Tool#"     );
    mks_lvgl_label_set(scr, label_Carving, 300, 210,    "#ff0000 Carving#"  );
}

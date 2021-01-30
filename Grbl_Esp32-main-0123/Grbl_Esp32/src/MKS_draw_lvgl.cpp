#include "MKS_draw_lvgl.h"


void mks_lvgl_label_set(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text) {
    lab = lv_label_create(scr, NULL);                                                          
    lv_label_set_long_mode(lab, LV_LABEL_LONG_BREAK);                                    
    lv_obj_set_width(lab, 80);
    lv_obj_set_height(lab,20);
    lv_obj_set_pos(lab, x, y);
    lv_label_set_recolor(lab, true);                                                  
    lv_label_set_text(lab, text);
}

void mks_lvgl_img_set(lv_obj_t *scr ,lv_obj_t *img, const void * src_img, lv_coord_t x_mod, lv_coord_t y_mod) {
    img = lv_img_create(scr, NULL);
    lv_img_set_src(img, src_img);
    lv_obj_align(img, NULL, LV_ALIGN_CENTER, x_mod, y_mod);
}

void lv_imgbtn_creat_mks(lv_obj_t *scr ,lv_obj_t *imgbtn, const void * img_pr, const void * img_rel, lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod, lv_event_cb_t event_cb) {
    imgbtn = lv_imgbtn_create(scr, NULL);
    lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_PR, img_pr);
    lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_REL, img_rel);
    lv_imgbtn_set_state(imgbtn, LV_BTN_STATE_REL);
    lv_obj_align(imgbtn, NULL, align,x_mod, y_mod);
    lv_obj_set_event_cb(imgbtn, event_cb);
}



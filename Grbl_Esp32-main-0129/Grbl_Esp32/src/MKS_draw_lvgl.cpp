#include "MKS_draw_lvgl.h"

/* 
 * Author   :MKS
 * Describe :Set gradient background (support LVGL V6, can not use v7)
 * Data     :2021/01/30
*/
lv_obj_t* mks_lvgl_draw_bk(lv_obj_t * scr, lv_style_t * dest_style, const lv_style_t * src_style, lv_color_t gcolor, lv_color_t mcolor) {

    lv_style_copy(dest_style, src_style);
	dest_style->body.grad_color = gcolor;
	dest_style->body.main_color = mcolor;
	lv_obj_set_style(scr ,dest_style);
    return scr;
}


/* 
 * Author   :MKS
 * Describe :Set monochrome background
 * Data     :2021/01/30
*/
lv_obj_t* mks_lvgl_draw_bk_both(lv_obj_t * scr, lv_style_t * dest_style, const lv_style_t * src_style, lv_color_t color) {

    lv_style_copy(dest_style, src_style);
	dest_style->body.grad_color = color;
	dest_style->body.main_color = color;
	lv_obj_set_style(scr ,dest_style);
    return scr;
}

/* 
 * Author   :MKS
 * Describe :Set wrap label
 * Data     :2021/01/30
*/
lv_obj_t* mks_lvgl_label_set(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text) {
    lab = lv_label_create(scr, NULL);                                                          
    lv_label_set_long_mode(lab, LV_LABEL_LONG_BREAK);                                    
    lv_obj_set_width(lab, 80);
    lv_obj_set_height(lab,20);
    lv_obj_set_pos(lab, x, y);
    lv_label_set_recolor(lab, true);                                                  
    lv_label_set_text(lab, text);
    return lab;
}

/* 
 * Author   :MKS
 * Describe :Set wrap label
 * Data     :2021/01/30
*/
lv_obj_t* mks_lvgl_label_with_long_set(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text, lv_coord_t w) {
    lab = lv_label_create(scr, NULL);                                                          
    lv_label_set_long_mode(lab, LV_LABEL_LONG_BREAK);                                    
    lv_obj_set_width(lab, w);
    lv_obj_set_height(lab,20);
    lv_obj_set_pos(lab, x, y);
    lv_label_set_recolor(lab, true);                                                  
    lv_label_set_text(lab, text);
    return lab;
}

/* 
 * Author   :MKS
 * Describe :Set the label to scroll back and forth
 * Data     :2021/01/30
*/
lv_obj_t* mks_lvgl_long_sroll_label_set(lv_obj_t* scr, lv_obj_t* lab, lv_coord_t x, lv_coord_t y, const char* text) {
    lab = lv_label_create(scr, NULL);
    lv_label_set_long_mode(lab, LV_LABEL_LONG_SROLL);
    lv_obj_set_width(lab, 200);
    lv_obj_set_height(lab, 20);
    lv_obj_set_pos(lab, x, y);
    lv_label_set_recolor(lab, true);
    lv_label_set_text(lab, text);
    return lab;
}

/* 
 * Author   :MKS
 * Describe :Set the label to scroll back and forth
 * Data     :2021/01/30
*/
lv_obj_t* mks_lvgl_long_sroll_label_with_wight_set(lv_obj_t* scr, lv_obj_t* lab, lv_coord_t x, lv_coord_t y, const char* text, lv_coord_t w) {
    lab = lv_label_create(scr, NULL);
    lv_label_set_long_mode(lab, LV_LABEL_LONG_SROLL);
    lv_obj_set_width(lab, w);
    lv_obj_set_height(lab, 20);
    lv_obj_set_pos(lab, x, y);
    lv_label_set_recolor(lab, true);
    lv_label_set_text(lab, text);
    return lab;
}

/* 
 * Author   :MKS
 * Describe :Set up Img display
 * Data     :2021/01/30
*/
lv_obj_t* mks_lvgl_img_set(lv_obj_t *scr ,lv_obj_t *img, const void * src_img, lv_coord_t x_mod, lv_coord_t y_mod) {
    img = lv_img_create(scr, NULL);
    lv_img_set_src(img, src_img);
    lv_obj_align(img, NULL, LV_ALIGN_CENTER, x_mod, y_mod);
    return img;
}

/* 
 * Author   :MKS
 * Describe :Create Img button
 * Data     :2021/01/30
*/
lv_obj_t* lv_imgbtn_creat_mks(lv_obj_t *scr ,lv_obj_t *imgbtn, const void * img_pr, const void * img_rel, lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod, lv_event_cb_t event_cb) {
    imgbtn = lv_imgbtn_create(scr, NULL);
    lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_PR, img_pr);
    lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_REL, img_rel);
    lv_imgbtn_set_state(imgbtn, LV_BTN_STATE_REL);
    lv_obj_align(imgbtn, NULL, align,x_mod, y_mod);
    lv_obj_set_event_cb(imgbtn, event_cb);
    return imgbtn;
}

/* 
 * Author   :MKS
 * Describe :Create Img button
 * Data     :2021/02/23
*/
lv_obj_t* mks_lv_btn_set(lv_obj_t* scr, lv_obj_t* btn, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y, lv_event_cb_t event_cb) {

    btn = lv_btn_create(scr, NULL);
    lv_obj_set_size(btn, btn_w, btn_h);
    lv_obj_set_pos(btn, x, y);
    lv_obj_set_event_cb(btn, event_cb);
    return btn;
}

/* 
 * Author   :MKS
 * Describe :Create Img button
 * Data     :2021/02/23
*/
lv_obj_t* mks_lv_bar_set(lv_obj_t* scr, lv_obj_t* bar, lv_coord_t bar_w, lv_coord_t bar_h, lv_coord_t x, lv_coord_t y, uint8_t val) {

    bar = lv_bar_create(scr, NULL);
    lv_obj_set_size(bar, 200, 30);
    lv_obj_align(bar, NULL, LV_ALIGN_CENTER, x, y);
    //lv_bar_set_anim_time(bar, 1000);
    lv_bar_set_value(bar, val, LV_ANIM_ON);
    return bar;
}

/* 
 * Author   :MKS
 * Describe :Updata bar value
 * Data     :2021/03/11
*/
lv_obj_t* mks_lv_bar_updata(lv_obj_t* bar, int16_t value) { 

    lv_bar_set_value(bar, value, LV_ANIM_ON);
    return bar;
}








#include "MKS_draw_lvgl.h"

lv_obj_t *mks_src;          // 主背景页

// lv_obj_t *global_popup;     // 全局提示
// lv_obj_t *global_popup_btn_sure;     
// lv_obj_t *global_popup_label_sure;     
// lv_obj_t *global_popup_label_text;  
// lv_style_t p_global_popup_color;
// lv_style_t p_global_popup_btn_color;

COMMON_POPUP_T com_p1;
COMMON_POPUP_T com_p2;

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
 * Data     :2021/03/02
*/
lv_obj_t* mks_lvgl_label_set_align_center(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text, lv_coord_t w) {
    lab = lv_label_create(scr, NULL);                                                          
    lv_label_set_long_mode(lab, LV_LABEL_LONG_BREAK);                               
    lv_obj_set_width(lab, w);
    lv_obj_set_height(lab,20);
    // lv_label_set_align(lab, LV_ALIGN_CENTER);
    lv_obj_align(lab, scr, LV_ALIGN_CENTER, x, y);
    // lv_obj_set_pos(lab, x, y);
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
    lv_label_set_long_mode(lab, LV_LABEL_LONG_BREAK);
    lv_obj_set_width(lab, w);
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
lv_obj_t* mks_lvgl_long_sroll_label_with_wight_set_center(lv_obj_t* scr, lv_obj_t* lab, lv_coord_t x, lv_coord_t y, const char* text, lv_coord_t w) {
    lab = lv_label_create(scr, NULL);
    lv_label_set_long_mode(lab, LV_LABEL_LONG_EXPAND);
    // lv_obj_set_width(lab, w);
    lv_label_set_align(lab, LV_ALIGN_CENTER);
    // lv_obj_set_height(lab, 20);
    lv_obj_set_pos(lab, x, y);
    lv_label_set_recolor(lab, true);
    lv_label_set_text(lab, text);
    return lab;
}

lv_obj_t* mks_lv_static_label(lv_obj_t* scr, lv_obj_t* lab, lv_coord_t x, lv_coord_t y, const char* text, lv_coord_t w) {

    lab = lv_label_create(scr, NULL);
    lv_label_set_long_mode(lab, LV_LABEL_LONG_BREAK);
    lv_obj_set_width(lab, w);
    lv_obj_set_height(lab, 20);
    lv_obj_set_pos(lab, x, y);
    lv_label_set_recolor(lab, true);
    // lv_label_set_text(lab, text);
    lv_label_set_static_text(lab, text);
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
    lv_obj_set_pos(img, x_mod, y_mod);
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

lv_obj_t* lv_imgbtn_creat_n_mks(lv_obj_t *scr ,lv_obj_t *imgbtn, const void * img_pr, const void * img_rel, lv_coord_t x_mod, lv_coord_t y_mod, lv_event_cb_t event_cb) {

    imgbtn = lv_imgbtn_create(scr, NULL);
    lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_PR, img_pr);
    lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_REL, img_rel);
    lv_imgbtn_set_state(imgbtn, LV_BTN_STATE_REL);
    lv_obj_set_pos(imgbtn, x_mod, y_mod);
    lv_obj_set_event_cb(imgbtn, event_cb);
    return imgbtn;

}

/* 
 * Author   :MKS
 * Describe :Create Img button
 * Data     :2021/03/16
*/
lv_obj_t* lv_imgbtn_img_set(lv_obj_t *imgbtn, const void * img_pr, const void * img_rel) {

    lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_PR, img_pr);
    lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_REL, img_rel);

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

// lv_obj_t* mks_lv_btn_style_set() { 


//     return ;
// }


/* 
 * Author   :MKS
 * Describe :Create Bar
 * Data     :2021/02/23
*/
lv_obj_t* mks_lv_bar_set(lv_obj_t* scr, lv_obj_t* bar, lv_coord_t bar_w, lv_coord_t bar_h, lv_coord_t x, lv_coord_t y, uint8_t val) {

    bar = lv_bar_create(scr, NULL);
    lv_obj_set_size(bar, bar_w, bar_h);
    // lv_obj_align(bar, NULL, LV_ALIGN_CENTER, x, y);
    lv_obj_set_pos(bar, x, y);
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

lv_obj_t* mks_lv_label_updata(lv_obj_t* lab, const char *str) {
    lv_label_set_static_text(lab ,str);
    return lab;
}

/* 
 * Author   :MKS
 * Describe :Updata bar value
 * Data     :2021/03/17
*/
lv_obj_t* mks_lv_set_kb(lv_obj_t* scr, lv_obj_t *kb, lv_event_cb_t event_cb) { 

    static lv_style_t rel_style, pr_style;

    lv_style_copy(&rel_style, &lv_style_btn_rel);
    rel_style.body.radius = 0;
    rel_style.body.border.width = 1;

    lv_style_copy(&pr_style, &lv_style_btn_pr);
    pr_style.body.radius = 0;
    pr_style.body.border.width = 1;

    kb = lv_kb_create(scr, NULL);
    lv_kb_set_cursor_manage(kb, true);
    lv_kb_set_style(kb, LV_KB_STYLE_BG, &lv_style_transp_tight);
    lv_kb_set_style(kb, LV_KB_STYLE_BTN_REL, &rel_style);
    lv_kb_set_style(kb, LV_KB_STYLE_BTN_PR, &pr_style);
    lv_obj_set_event_cb(kb, event_cb);
}

lv_obj_t* mks_lv_set_ta(lv_obj_t* scr, lv_obj_t *ta, lv_obj_t *kb) { 

    ta = lv_ta_create(scr, NULL); 
    // lv_obj_align(ta, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);
    lv_obj_set_pos(ta, 90, 30);
    lv_obj_set_size(ta, 200, 20);
    lv_ta_set_text(ta, "");
    lv_kb_set_ta(kb, ta);
    return ta;
}


lv_obj_t* mks_lv_set_line(lv_obj_t* scr, lv_obj_t * line, lv_point_t *line_points) { 

    /*Copy the previous line and apply the new style*/
    line = lv_line_create(scr, NULL);
    lv_line_set_points(line, line_points, 2);     /*Set the points*/
    
    // lv_obj_align(line, NULL, LV_ALIGN_CENTER, 0, 0);

    return line;
}

void mks_lv_clean_ui(void) { 

    mks_grbl.popup_1_flag = false;
    lv_obj_clean(mks_src);
}


static void event_handler_globel_popup_sure(lv_obj_t* obj, lv_event_t event) { 

    if (event == LV_EVENT_RELEASED) { 
        lv_obj_del(com_p2.com_popup_src);

        if(mks_ui_page.mks_ui_page == MKS_UI_Frame) {
            frame_ctrl.out = false;
            mks_lv_clean_ui();
            mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
            mks_draw_ready();
        }
        mks_grbl.popup_1_flag = false;
        frame_ctrl.is_begin_run = false;
    }
}

void draw_global_popup(const char *text) {

    if(mks_grbl.popup_1_flag == true) return;
    mks_grbl.popup_1_flag = true;

	com_p2.com_popup_src = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(com_p2.com_popup_src, move_popup_size_x, move_popup_size_y);
    lv_obj_set_pos(com_p2.com_popup_src, move_popup_x, move_popup_y);

	lv_style_copy(&com_p2.com_popup_sytle, &lv_style_scr);
	com_p2.com_popup_sytle.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    com_p2.com_popup_sytle.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    com_p2.com_popup_sytle.text.color = LV_COLOR_BLACK;
    com_p2.com_popup_sytle.body.radius = 17;
	lv_obj_set_style(com_p2.com_popup_src, &com_p2.com_popup_sytle);

	lv_style_copy(&com_p2.com_btn_sytle, &lv_style_scr);
	com_p2.com_btn_sytle.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    com_p2.com_btn_sytle.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    com_p2.com_btn_sytle.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    com_p2.com_btn_sytle.text.color = LV_COLOR_WHITE;
	com_p2.com_btn_sytle.body.radius = 10;

	com_p2.btn_yes = mks_lv_btn_set(com_p2.com_popup_src, 
                                    com_p2.btn_yes, 
                                    move_popup_btn_size_x, 
                                    move_popup_btn_size_y,
                                    move_popup_btn_x, 
                                    move_popup_btn_y, 
                                    event_handler_globel_popup_sure);
	lv_btn_set_style(com_p2.btn_yes, LV_BTN_STYLE_REL, &com_p2.com_btn_sytle);
	lv_btn_set_style(com_p2.btn_yes,LV_BTN_STYLE_PR, &com_p2.com_btn_sytle);

	com_p2.label_line1 = mks_lvgl_label_set_align_center(com_p2.com_popup_src, com_p2.label_line1, 0, -30, text, 16*sizeof(com_p1.label_line1)+1);
	com_p2.label_yes = mks_lvgl_long_sroll_label_with_wight_set_center(com_p2.btn_yes, com_p2.label_yes, 50, 0, "Yes",50);
}


void mks_draw_common_popup(char *title, char *line1, char *line2, lv_event_cb_t event_cb_yes, lv_event_cb_t event_cancle) {

	com_p1.com_popup_src = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(com_p1.com_popup_src ,350, 200);
	lv_obj_set_pos(com_p1.com_popup_src, 80,50);

	lv_style_copy(&com_p1.com_popup_sytle, &lv_style_scr);
	com_p1.com_popup_sytle.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    com_p1.com_popup_sytle.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
	com_p1.com_popup_sytle.text.color = LV_COLOR_BLACK;
	com_p1.com_popup_sytle.body.radius = 17;
	lv_obj_set_style(com_p1.com_popup_src, &com_p1.com_popup_sytle);
	
	lv_style_copy(&com_p1.com_btn_sytle, &lv_style_scr);
    com_p1.com_btn_sytle.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    com_p1.com_btn_sytle.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
	com_p1.com_btn_sytle.body.radius = 10;
    com_p1.com_btn_sytle.body.opa = LV_OPA_COVER; // 设置背景色完全不透明
    com_p1.com_btn_sytle.text.color = LV_COLOR_WHITE;
	
	com_p1.btn_yes = mks_lv_btn_set(com_p1.com_popup_src, com_p1.btn_yes, 100,40,10,130, event_cb_yes);
	lv_btn_set_style(com_p1.btn_yes, LV_BTN_STYLE_REL, &com_p1.com_btn_sytle);
    lv_btn_set_style(com_p1.btn_yes,LV_BTN_STYLE_PR,&com_p1.com_btn_sytle);
	mks_lvgl_long_sroll_label_with_wight_set_center(com_p1.btn_yes, com_p1.label_yes, 50, 0, "Yes",50);

	com_p1.btn_cancle = mks_lv_btn_set(com_p1.com_popup_src, com_p1.btn_cancle, 100,40,240,130, event_cancle);
	lv_btn_set_style(com_p1.btn_cancle, LV_BTN_STYLE_REL, &com_p1.com_btn_sytle);
    lv_btn_set_style(com_p1.btn_cancle,LV_BTN_STYLE_PR, &com_p1.com_btn_sytle);
	mks_lvgl_long_sroll_label_with_wight_set_center(com_p1.btn_cancle, com_p1.label_cancle, 50, 0, "Cancel",50);

	mks_lvgl_label_set_align_center(com_p1.com_popup_src, com_p1.label_title, 0, -60, title, 16*sizeof(com_p1.label_title));
	mks_lvgl_label_set_align_center(com_p1.com_popup_src, com_p1.label_line1, 0, -20, line1,16*sizeof(com_p1.label_line1)*3);
    mks_lvgl_label_set_align_center(com_p1.com_popup_src, com_p1.label_line2, 0, 0, line2,16*sizeof(com_p1.label_line2)*3);
}











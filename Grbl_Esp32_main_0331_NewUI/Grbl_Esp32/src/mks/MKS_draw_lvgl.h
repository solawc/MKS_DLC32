#ifndef __MKS_DRAW_LVGL_H 
#define __MKS_DRAW_LVGL_H

#include "lvgl.h"
#include "../Grbl.h"
#include "SPIFFS.h"

#include "MKS_draw_ready.h"
#include "MKS_draw_tool.h"
#include "MKS_draw_carving.h"
#include "MKS_draw_setting.h"
#include "MKS_draw_home.h"
#include "MKS_draw_move.h"
#include "MKS_draw_power.h"
#include "MKS_draw_language.h"
#include "MKS_draw_about.h"
#include "MKS_draw_print.h"
#include "MKS_draw_config.h"
#include "MKS_draw_wifi.h"

extern lv_obj_t *mks_src;


/* draw screen setting */
lv_obj_t* mks_lvgl_draw_bk(lv_obj_t * scr, lv_style_t * dest_style, const lv_style_t * src_style, lv_color_t gcolor, lv_color_t mcolor);
lv_obj_t* mks_lvgl_draw_bk_both(lv_obj_t * scr, lv_style_t * dest_style, const lv_style_t * src_style, lv_color_t color);

/* label settings */
lv_obj_t* mks_lvgl_label_set(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text);
lv_obj_t* mks_lvgl_label_with_long_set(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text, lv_coord_t w);
lv_obj_t* mks_lvgl_long_sroll_label_set(lv_obj_t* scr, lv_obj_t* lab, lv_coord_t x, lv_coord_t y, const char* text);
lv_obj_t* mks_lvgl_long_sroll_label_with_wight_set(lv_obj_t* scr, lv_obj_t* lab, lv_coord_t x, lv_coord_t y, const char* text, lv_coord_t w);
lv_obj_t* mks_lvgl_long_sroll_label_with_wight_set_center(lv_obj_t* scr, lv_obj_t* lab, lv_coord_t x, lv_coord_t y, const char* text, lv_coord_t w);
lv_obj_t* mks_lvgl_label_set_align_center(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text);
lv_obj_t* mks_lv_label_updata(lv_obj_t* lab, const char *str);

/* img settings */
lv_obj_t* mks_lvgl_img_set(lv_obj_t *scr ,lv_obj_t *img, const void * src_img, lv_coord_t x_mod, lv_coord_t y_mod);

/* imgbtn settings */
lv_obj_t* lv_imgbtn_img_set(lv_obj_t *scr, lv_obj_t *imgbtn, const void * img_pr, const void * img_rel);
lv_obj_t* lv_imgbtn_creat_mks(lv_obj_t *scr ,lv_obj_t *imgbtn, const void * img_pr, const void * img_rel, lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod, lv_event_cb_t event_cb);
lv_obj_t* lv_imgbtn_img_set(lv_obj_t *imgbtn, const void * img_pr, const void * img_rel);

/* buttom settings */
lv_obj_t* mks_lv_btn_set(lv_obj_t* scr, lv_obj_t* btn, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y, lv_event_cb_t event_cb);

/* Bar settings */
lv_obj_t* mks_lv_bar_set(lv_obj_t* scr, lv_obj_t* bar, lv_coord_t bar_w, lv_coord_t bar_h, lv_coord_t x, lv_coord_t y, uint8_t val);
lv_obj_t* mks_lv_bar_updata(lv_obj_t* bar, int16_t value);

/* key board */
lv_obj_t* mks_lv_set_kb(lv_obj_t* scr, lv_obj_t *kb, lv_event_cb_t event_cb);
lv_obj_t* mks_lv_set_ta(lv_obj_t* scr, lv_obj_t *ta, lv_obj_t *kb);

/* line */
lv_obj_t* mks_lv_set_line(lv_obj_t* scr, lv_obj_t * line, lv_point_t *line_points);


#endif 

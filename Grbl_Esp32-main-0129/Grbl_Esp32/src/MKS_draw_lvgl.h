#ifndef __MKS_DRAW_LVGL_H 
#define __MKS_DRAW_LVGL_H

#include "lvgl.h"
#include "Grbl.h"

#include "MKS_draw_ready.h"
#include "MKS_draw_tool.h"
#include "MKS_draw_carving.h"
#include "MKS_draw_setting.h"
#include "MKS_draw_home.h"
#include "MKS_draw_move.h"
#include "MKS_draw_power.h"
#include "MKS_draw_language.h"
#include "MKS_draw_about.h"

lv_obj_t* mks_lvgl_draw_bk(lv_obj_t * scr, lv_style_t * dest_style, const lv_style_t * src_style, lv_color_t gcolor, lv_color_t mcolor);
lv_obj_t* mks_lvgl_draw_bk_both(lv_obj_t * scr, lv_style_t * dest_style, const lv_style_t * src_style, lv_color_t color);
lv_obj_t* mks_lvgl_label_set(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text);
lv_obj_t* mks_lvgl_long_sroll_label_set(lv_obj_t* scr, lv_obj_t* lab, lv_coord_t x, lv_coord_t y, const char* text);
lv_obj_t* mks_lvgl_img_set(lv_obj_t *scr ,lv_obj_t *img, const void * src_img, lv_coord_t x_mod, lv_coord_t y_mod);
lv_obj_t* lv_imgbtn_creat_mks(lv_obj_t *scr ,lv_obj_t *imgbtn, const void * img_pr, const void * img_rel, lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod, lv_event_cb_t event_cb);
lv_obj_t* lv_imgbtn_img_set(lv_obj_t *scr, lv_obj_t *imgbtn, const void * img_pr, const void * img_rel);
#endif 

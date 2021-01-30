#ifndef __MKS_DRAW_LVGL_H 
#define __MKS_DRAW_LVGL_H

#include "lvgl.h"
#include "Grbl.h"

#include "MKS_draw_ready.h"
#include "MKS_draw_tool.h"





void mks_lvgl_label_set(lv_obj_t *scr, lv_obj_t *lab, lv_coord_t x, lv_coord_t y, const char *text);
void mks_lvgl_img_set(lv_obj_t *scr ,lv_obj_t *img, const void * src_img, lv_coord_t x_mod, lv_coord_t y_mod);
void lv_imgbtn_creat_mks(lv_obj_t *scr ,lv_obj_t *imgbtn, const void * img_pr, const void * img_rel, lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod, lv_event_cb_t event_cb);
#endif 

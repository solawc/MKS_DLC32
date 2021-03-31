#ifndef __MKS_DRAW_READY_H
#define __MKS_DRAW_READY_H

#include "lvgl.h"
#include "../Grbl.h"
#include "MKS_draw_lvgl.h"

#define LV_DESKTOP      lv_disp_get_scr_act(NULL)



void mks_draw_ready(void);
void lv_clean_curren_screen(void);
#endif

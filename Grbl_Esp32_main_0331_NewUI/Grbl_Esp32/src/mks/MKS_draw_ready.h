#ifndef __MKS_DRAW_READY_H
#define __MKS_DRAW_READY_H

#include "lvgl.h"
#include "../Grbl.h"
#include "MKS_draw_lvgl.h"

#define LV_DESKTOP      lv_disp_get_scr_act(NULL)

typedef enum {

    READY_src1_x = 10,
    READY_src1_y = 200,
    READY_src1_x_size = 460,
    READY_src1_y_size = 110,

    READY_FIRST_IMG_X = 60,
    READY_FIRST_IMG_Y = 10,

    READY_FIRST_LABEL_X = 60,
    READY_FIRST_LABEL_Y = 20,

    READY_first_btn_x = 10,
    READY_first_btn_y = 120,
    READY_btn_w = 220,
    READY_btn_h = 30,
    READY_btn_label_size = 220,

}READY_XY_POS_t;

typedef struct {
    uint32_t mks_x_pos;
    uint32_t mks_y_pos;
    uint32_t mks_z_pos;
}ready_data_t;
extern ready_data_t ready_data;


void mks_draw_ready(void);
void lv_clean_curren_screen(void);
void ready_data_updata(void);
#endif

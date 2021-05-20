#ifndef __mks_draw_frame_h
#define __mks_draw_frame_h

#include "MKS_draw_lvgl.h"

typedef enum {

    FRAME_SRC_X = 0,
    FRAME_SRC_Y = 0,
    FRAME_SRC_SIZE_X = 480-1,
    FRAME_SRC_SIZE_Y = 320-1,

}FRAM_XY_POS;


typedef struct {

    lv_obj_t *frame_src;
    lv_style_t frame_src_style;
    lv_obj_t *btn_cancle;
    lv_obj_t *label_cancle;
    lv_obj_t *label_text;
}FRAME_PAGE_T;


typedef enum {
    FRAME_NONE,
    FRAWM_READ_SD,
    FRAM_RUN,
    FRAM_END,
}FRAME_STATUS;


#define FRAME_BUFF_SIZE             128
typedef struct {

    FRAME_STATUS frame_starus;
    float x_max;
    float y_max;
    float x_min;
    float y_min;
    float x_temp;
    float y_temp;
    uint8_t have_g0;
    uint8_t have_g1;
    uint32_t safe_count;
    char *x_or_y;
    char file_name[128];
    char x_value[10];
    char y_value[10];
}FRAME_CRTL_T;
extern FRAME_CRTL_T frame_ctrl;


void mks_draw_frame(void);
void mks_run_frame(char *parameter);
#endif

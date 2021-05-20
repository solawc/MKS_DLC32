#ifndef __mks_draw_inFile_h
#define __mks_draw_inFile_h

#include "MKS_draw_lvgl.h"


typedef enum {

    inFILE_SRC_X = 0,
    inFILE_SRC_Y = 0,
    inFILE_SRC_SIZE_X = 480-1,
    inFILE_SRC_SIZE_Y = 320-1,

    inFILE_BTN_X = 50,
    inFILE_BTN_Y = 180,
    inFILE_BTN_SIZE_X = 100,
    inFILE_BTN_SIZE_Y = 50,
    inFILE_BTN_OFFSET = inFILE_BTN_SIZE_X + 30,

}inFILE_XY_POS;



typedef struct {

    lv_obj_t *inFile_src;

    lv_obj_t *btn_sure_print;
    lv_obj_t *btn_frame;
    lv_obj_t *btn_cancle;

    lv_style_t src_color;
    lv_style_t btn_color;

    lv_obj_t *label_sure_print;
    lv_obj_t *label_frame;
    lv_obj_t *label_cancle;
    lv_obj_t *label_file_name;
    lv_obj_t *label_file_size;

}inFILE_PAGE_T;


void mks_draw_inFile(char *fn);


#endif
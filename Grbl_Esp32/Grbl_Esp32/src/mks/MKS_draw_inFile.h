#ifndef __mks_draw_inFile_h
#define __mks_draw_inFile_h

#include "MKS_draw_lvgl.h"


typedef enum {

    inFILE_SRC_X = 0,
    inFILE_SRC_Y = 0,
    inFILE_SRC_SIZE_X = 480-1,
    inFILE_SRC_SIZE_Y = 320-1,

    inFILE_SRC1_X = 0,
    inFILE_SRC1_Y = 0,
    inFILE_SRC1_SIZE_X = 480-1,
    inFILE_SRC1_SIZE_Y = 320-1,

    inFILE_SRC2_X = 0,
    inFILE_SRC2_Y = 0,
    inFILE_SRC2_SIZE_X = 480-1,
    inFILE_SRC2_SIZE_Y = 320-1,

    inFILE_SRC3_X = 0,
    inFILE_SRC3_Y = 0,
    inFILE_SRC3_SIZE_X = 480-1,
    inFILE_SRC3_SIZE_Y = 320-1,


    inFILE_BTN_X = 30,
    inFILE_BTN_Y = 10,
    inFILE_BTN_SIZE_X = 120,
    inFILE_BTN_SIZE_Y = 50,
    inFILE_BTN_X_OFFSET = inFILE_BTN_SIZE_X + 0,
    inFILE_BTN_Y_OFFSET = inFILE_BTN_SIZE_Y + 10,
}inFILE_XY_POS;



typedef struct {

    // lv_obj_t *inFile_src;

    lv_obj_t *inFile_src1;          // 顶部
    lv_obj_t *inFile_src2;          // 左边
    lv_obj_t *inFile_src3;          // 右边

    lv_obj_t *btn_pos;              // 定点
    lv_obj_t *btn_sure_print;       // 打印
    lv_obj_t *btn_frame;            // 巡边
    lv_obj_t *btn_cancle;           // 返回

    lv_obj_t *imgbtn_X_N;
    lv_obj_t *imgbtn_X_P;
    lv_obj_t *imgbtn_Y_N;
    lv_obj_t *imgbtn_Y_P;


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
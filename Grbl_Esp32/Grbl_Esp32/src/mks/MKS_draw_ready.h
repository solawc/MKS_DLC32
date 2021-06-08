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
    READY_FIRST_LABEL_Y = 10,

    READY_first_btn_x = 10,
    READY_first_btn_y = 120,
    READY_btn_w = 220,
    READY_btn_h = 30,
    READY_btn_label_size = 220,

}READY_XY_POS_t;


typedef struct {

#if defined(USE_RELASE)
    lv_obj_t *ready_src_1;      //用于放应用选择

    lv_style_t ready_src1_style;        //用于样式
    lv_style_t ready_btn_wifi_style;
#endif

    lv_obj_t* ready_imgbtn_Adjustment;  //用于创建图片按键
    lv_obj_t* ready_imgbtn_Control;
    lv_obj_t* ready_imgbtn_Sculpture;
    lv_obj_t* ready_imgbtn_Tool;
    
    lv_obj_t* ready_imgbtn_status;
    lv_obj_t* ready_imgbtn_xpos;
    lv_obj_t* ready_imgbtn_ypos;
    lv_obj_t* ready_imgbtn_zpos;
    lv_obj_t* ready_imgbtn_pwr;
    lv_obj_t* ready_imgbtn_wifi_status;

    lv_obj_t* ready_btn_wifi;           //用于创建按键

    lv_obj_t* ready_label_Adjustment;   //用于功能label
    lv_obj_t* ready_label_Control;
    lv_obj_t* ready_label_Sculpture;
    lv_obj_t* ready_label_Tool;

    lv_obj_t* ready_label_status;   //用于显示label
    lv_obj_t* ready_label_xpos;
    lv_obj_t* ready_label_ypos;
    lv_obj_t* ready_label_zpos;
    lv_obj_t* ready_label_mpwr;
    lv_obj_t* ready_label_wifi_status;
}MKS_PAGE_READY;




void mks_draw_ready(void);
void ready_data_updata(void);
void mks_draw_logo(void);
void mks_global_style_init(void);
#endif

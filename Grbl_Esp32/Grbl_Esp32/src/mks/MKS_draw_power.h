#ifndef __mks_draw_power_h
#define __mks_draw_power_h

#include "MKS_draw_lvgl.h"


typedef struct {


    lv_obj_t* p_scr1;
    lv_obj_t* p_scr2;
    lv_obj_t* p_popup;

    lv_obj_t* pwr_high;
    lv_obj_t* pwr_low;
    lv_obj_t* pwr_off;
    lv_obj_t* cailb;
    lv_obj_t* Back;

    lv_obj_t* btn_sure;
    lv_obj_t* label_sure;
    lv_obj_t* label_popup;


    lv_obj_t* pwr_label_high;
    lv_obj_t* pwr_label_low;
    lv_obj_t* pwr_label_off;
    lv_obj_t* label_cailb;
    lv_obj_t* label_Back;


    lv_style_t p_bkl_color;
    lv_style_t p_popup_color;
    lv_style_t p_popup_btn_color;

}POWER_PAGE_T;




void mks_draw_power(void);
void mks_clear_power(void);
void mks_power_set(uint8_t val);
void draw_pwr_popup_1(const char *text);
#endif

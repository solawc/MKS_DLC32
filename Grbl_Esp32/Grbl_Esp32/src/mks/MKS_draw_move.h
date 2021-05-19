#ifndef __mks_draw_move_h
#define __mks_draw_move_h


#include "MKS_draw_lvgl.h"
#include "MKS_LVGL.h"


typedef enum {

    move_popup_x = 75,
    move_popup_y = 70,
    move_popup_size_x = 330,
    move_popup_size_y = 180,

    move_popup_btn_x = 120,
    move_popup_btn_y = 120,
    move_popup_btn_size_x = 100,
    move_popup_btn_size_y = 40,

}MOVE_XY_t;

typedef struct {

    /* Screan Build */
    lv_obj_t* move_scr;
    lv_obj_t* dist_scr;
    lv_obj_t* tool_scr;

    lv_style_t mbk_color;
    lv_style_t btn_color;

    /* imgbtn */
    lv_obj_t* x_n;			//+
    lv_obj_t* x_p;			//-
    lv_obj_t* y_n;			//+
    lv_obj_t* y_p;			//-

    lv_obj_t* m_unlock;
    lv_obj_t* postivs;
    lv_obj_t* home;
    lv_obj_t* hhome;

    lv_obj_t* btn_len_0_1;
    lv_obj_t* btn_len_1;
    lv_obj_t* btn_len_10;
    lv_obj_t* Back;

    /* Label */
    lv_obj_t* Label_len;
    lv_obj_t* Label_back;
    lv_obj_t* Label_unlock;
    lv_obj_t* Label_postivs;
    lv_obj_t* Label_home;

    lv_obj_t* label_len_0_1;
    lv_obj_t* label_len_1;
    lv_obj_t* label_len_10;

}MKS_MOVE_PAGE;



typedef enum {
    HOMING_NONE,
    HOMING_START,
    HOMING_RUNNING,
    HOMING_SUCCEED,
    HOMING_FAIL,
}MKS_HOMING_T;

typedef struct{

    MKS_HOMING_T hard_homing_status;    // 硬限位回零配置
    MKS_HOMING_T soft_homing_status;    // 软限位回零配置
    
}MKS_MOVE_CTRL_T;



void mks_draw_move(void);
// void draw_pos_popup(void);
void mks_clear_move(void);
void draw_pos_popup(const char *text);
void draw_pos_popup_1(const char *text);
void hard_home_check(void);
void soft_home_check(void);
void draw_pos_popup_2(const char *text);
#endif

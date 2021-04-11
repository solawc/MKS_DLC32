#ifndef __mks_draw_wifi_h
#define __mks_draw_wifi_h

#include "mks_draw_lvgl.h"

typedef enum {

    wifi_src1_x = 10,
    wifi_src1_y = 10,
    wifi_src1_x_size = 460,
    wifi_src1_y_size = 90,

    wifi_first_line_x = 10,
    wifi_first_line_y = 150,

    wifi_first_btn_x = 10,
    wifi_first_btn_y = 120,
    wifi_btn_w = 220,
    wifi_btn_h = 30,
    wifi_btn_label_size = 220,

    wifi_popup_btn_sure_x = 120,
    wifi_popup_btn_sure_y = 120,
    wifi_popup_btn_sure_size_x = 100,
    wifi_popup_btn_sure_size_y = 40,

    wifi_popup_btn_cancle_x = 120,
    wifi_popup_btn_cancle_y = 120,
    wifi_popup_btn_cancle_size_x = 100,
    wifi_popup_btn_cancle_size_y = 40,

}WIFI_XY_POS_t;

typedef enum{
    wifi_kb_none_flag,
    wifi_kb_username_flag,
    wifi_kb_password_flag,
}wifi_kb_flag_t;


typedef struct {

    lv_obj_t *wifi_src_1;               // wifi应用部分被
    lv_obj_t *wifi_kb_src_1;            // 键盘的界面
    lv_obj_t *wifi_popup_scr_1;         // 弹窗1

    lv_style_t wifi_scr1_style;         // 样式
    lv_style_t wifi_kb_src_style;
    lv_style_t wifi_popup_scr_1_style;
    lv_style_t wifi_popup_btn_style;
    lv_style_t wifi_line_style;

    lv_obj_t *wifi_btn_line1;           // wifi行按键
    lv_obj_t *wifi_btn_line2; 
    lv_obj_t *wifi_btn_line3; 
    lv_obj_t *wifi_btn_line4; 
    lv_obj_t *wifi_btn_line5; 
    lv_obj_t *wifi_btn_line6; 
    lv_obj_t *wifi_btn_line7; 
    lv_obj_t *wifi_btn_line8; 

    lv_obj_t *wifi_popup_btn_sure; 
    lv_obj_t *wifi_popup_btn_cancle; 

    lv_obj_t *wifi_line1;               // wifi绘制线
    lv_obj_t *wifi_line2;
    lv_obj_t *wifi_line3;
    lv_obj_t *wifi_line4;
    lv_obj_t *wifi_line5;
    lv_obj_t *wifi_line6;
    lv_obj_t *wifi_line7;
    lv_obj_t *wifi_line8;

    lv_obj_t *wifi_kb;                  // wifi键盘
    lv_obj_t *wifi_tb;

    lv_obj_t *wifi_imgbtn_up;           // 图片按键
    lv_obj_t *wifi_imgbtn_next;
    lv_obj_t *wifi_imgbtn_back;

    lv_obj_t *wifi_label_line1;         // label
    lv_obj_t *wifi_label_line2; 
    lv_obj_t *wifi_label_line3; 
    lv_obj_t *wifi_label_line4; 
    lv_obj_t *wifi_label_line5; 
    lv_obj_t *wifi_label_line6;
    lv_obj_t *wifi_label_line7; 
    lv_obj_t *wifi_label_line8;
    lv_obj_t *wifi_label_up;
    lv_obj_t *wifi_label_next;
    lv_obj_t *wifi_label_back;
    lv_obj_t *wifi_popup_label;
    lv_obj_t *wifi_popup_file_name_label;
    lv_obj_t *wifi_btn_popup_sure_label;
    lv_obj_t *wifi_btn_popup_cancle_label;
}MKS_WIFI_PAGE_T;



void mks_draw_wifi(void);
void mks_clear_wifi(void);
void mks_wifi_connect_check(IPAddress ip);
void draw_wifi_loading(void);
void mks_wifi_del_label(void);
void mks_wifi_show_label(void);

#endif

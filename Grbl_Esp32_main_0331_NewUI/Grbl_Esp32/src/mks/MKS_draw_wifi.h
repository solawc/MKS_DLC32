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

}WIFI_XY_POS_t;

typedef enum{
    wifi_none_flag,
    wifi_username_flag,
    wifi_password_flag,

}wifi_kb_flag_t;

void mks_draw_wifi(void);
void mks_clear_wifi(void);
void mks_wifi_connect_check(IPAddress ip);
void draw_wifi_loading(void);
void mks_wifi_del_label(void);
void mks_wifi_show_label(void);

#endif

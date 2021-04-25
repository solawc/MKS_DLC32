#ifndef mks_draw_tool_h
#define mks_draw_tool_h

#include "MKS_draw_lvgl.h"

typedef enum {

    about_src1_x = 10,
    about_src1_y = 10,
    about_src1_x_size = 460,
    about_src1_y_size = 90,

    about_first_line_x = 10,
    about_first_line_y = 150,

    // about_first_btn_x = 10,
    // about_first_btn_y = 120,
    // about_btn_w = 220,
    // about_btn_h = 30,
    // about_btn_label_size = 220,

}ABOUT_XY_POS_t;


// void lv_draw_tool(void);
void mks_draw_tool(void);
void mks_clear_tool(void);
void light_img_change(uint8_t status);
void mks_draw_pos_pupop(void);

#endif

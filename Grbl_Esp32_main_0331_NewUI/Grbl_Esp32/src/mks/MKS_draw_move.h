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


void mks_draw_move(void);
// void draw_pos_popup(void);
void mks_clear_move(void);
void draw_pos_popup(const char *text);
#endif

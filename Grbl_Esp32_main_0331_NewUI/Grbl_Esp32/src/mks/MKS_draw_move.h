#ifndef __mks_draw_move_h
#define __mks_draw_move_h


#include "MKS_draw_lvgl.h"
#include "MKS_LVGL.h"


typedef enum {

    move_popup_x = 100,
    move_popup_y = 100,
    move_popup_size_x = 300,
    move_popup_size_y = 200,
    move_popup_btn_x = 10,
    move_popup_btn_y = 10,
    move_popup_btn_size_x = 50,
    move_popup_btn_size_y = 20,

}MOVE_XY_t;


void mks_draw_move(void);
void draw_pos_popup(void);
void mks_clear_move(void);

#endif

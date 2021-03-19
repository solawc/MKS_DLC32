#ifndef __MKS_draw_print_h
#define __MKS_draw_print_h

#include "mks_draw_lvgl.h"



void mks_clear_print(void);
void mks_draw_print(void);
void mks_draw_print_popup(const char* text);
void mks_del_obj(lv_obj_t *obj);
void mks_draw_finsh_pupop(void);
void mks_print_bar_updata(void);
void mks_draw_operation(void);
#endif // !MKS_draw_print_h
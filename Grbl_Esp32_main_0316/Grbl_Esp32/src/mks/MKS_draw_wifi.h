#ifndef __mks_draw_wifi_h
#define __mks_draw_wifi_h

#include "mks_draw_lvgl.h"



void mks_draw_wifi(void);
void mks_clear_wifi(void);
void mks_wifi_connect_check(IPAddress ip);
void draw_wifi_loading(void);
#endif

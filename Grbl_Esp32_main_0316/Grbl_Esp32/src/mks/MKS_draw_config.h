#ifndef __MKS_draw_config_h
#define __MKS_draw_config_h

//#include "MKS_LVGL.h"
#include "MKS_draw_lvgl.h"

typedef enum {

    KB_NONE,
    /* MT Motor */
    KB_MT_RPM_MAX,
    KB_MT_RPM_MIN,
    KB_MT_X_PLUSE,
    KB_MT_Y_PLUSE,
    KB_MT_Z_PLUSE,
    KB_MT_X_MAXSPEED,
    KB_MT_Y_MAXSPEED,
    KB_MT_Z_MAXSPEED,
    KB_MT_X_ACC,
    KB_MT_Y_ACC,
    KB_MT_Z_ACC,
    KB_MT_X_MAX_TRAVE,
    KB_MT_Y_MAX_TRAVE,
    KB_MT_Z_MAX_TRAVE,

    /* WIFI */
    // MT_WIFI_IP,
    KB_WIFI_USERBANE,
    KB_WIFI_PASSWORD,
}kb_event_flag;


void mks_draw_config_main_page(void);
void mks_draw_Mechan(void);
void mks_draw_motor_parameters(void);

void mks_clean_main_page(void);

#endif /* __MKS_draw_config_h */

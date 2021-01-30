#ifndef __MKS_DRAW_READY_H
#define __MKS_DRAW_READY_H

#include "lvgl.h"
#include "Grbl.h"
#include "MKS_draw_lvgl.h"

#define LV_DESKTOP      lv_disp_get_scr_act(NULL)


typedef enum
{
    SETTING_LAB_CD_X    = 100,
    SETTING_LAB_CD_Y    = 210, 
    SETTING_PIC_X       = -100,
    SETTING_PIC_Y       = 0,    

    TOOL_LAB_CD_X       = 210,
    TOOL_LAB_CD_Y       = 210, 
    TOOL_PIC_X          = -100,
    TOOL_PIC_Y          = 0,    

    CARVING_LAB_CD_X    = 300,
    CARVING_LAB_CD_Y    = 210, 
    CARVING_PIC_X       = -100,
    CARVING_PIC_Y       = 0,    
}Draw_Read_Coordinate;


void lv_draw_ready(void);
void lv_clean_curren_screen(void);
#endif

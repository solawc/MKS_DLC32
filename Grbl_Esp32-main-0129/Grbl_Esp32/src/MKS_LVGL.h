#ifndef __MKS_LVGL_H
#define __MKS_LVGL_H

#include "MKS_TS35.h"
#include "lvgl.h"
#include "MKS_FREERTOS_TASK.h"
#include "Serial.h"

#define MKS_GRBL_CMD_SEND(A)        serila_write_into_buffer((uint8_t *)A)

typedef enum {
    M_0_1_MM,           // move 0.1mm
    M_1_MM,             // move 1mm
    M_10_MM,            // move 10mm
}GRBL_MOVE_DIS;

typedef enum {
    SimpleChinese,      
    Chinese,
    English,
}GRBL_Language;

typedef enum {
    GRBL_Light_On,
    GRBL_Light_Off,
}GRBL_LIGHT_STATUS;

typedef enum {
    P_1_PERSEN,
    P_10_PERSEN,
}GRBL_POWER;

typedef struct{
    GRBL_MOVE_DIS               move_dis;
    GRBL_Language               language;
    GRBL_LIGHT_STATUS           light_status;
    GRBL_POWER                  power_length;
    uint8_t                     power_persen;
}GRBL_CRTL;
extern GRBL_CRTL mks_grbl;

void mks_lvgl_init(void);
void lvgl_test(void);

#endif

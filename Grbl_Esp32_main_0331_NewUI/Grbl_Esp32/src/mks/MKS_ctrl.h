#ifndef __MKS_CTRL_H
#define __MKS_CTRL_H

// #include "GCode.h"
// #include "Report.h"
#include "../grbl.h"

typedef enum {

    BL_NONE,
    BL_BEGIN,           //开始调整
    BL_ADJ_ING,         //正在调整
    BL_ADJ_END,         //调整结束

}BLTOUCH_STATUS;


typedef enum {
    sp_none,    // 开始没状态
    sp_begin,   // 电机开始空闲
    sp_load,    // 装载start的时间值
    sp_wait,    // 等待时间到
    sp_end,     // 激光头关闭后
}spindle_check_status;

typedef struct {
    uint32_t                    tick_start;
    uint32_t                    tick_end;
    spindle_check_status        spindle_status;
    uint32_t                    out_time;
}mks_spindle_t;
extern mks_spindle_t mks_spindle;


typedef enum {

    wifi_none,
    wifi_scanfing,

}mks_wifi_status_t;


#define MKS_WIFI_NUM            8
#define MKS_WIFI_NAME_LEN       128
typedef struct {

    char wifi_name_str[MKS_WIFI_NUM][MKS_WIFI_NAME_LEN];
    
    uint8_t begin_scanf_num;        // 每次记录都从0开始    
    uint8_t wifi_show_page;         // 记录WiFi显示的页码          

}MKS_WIFI_t;
extern MKS_WIFI_t mks_wifi;


void bltouch_init(void);
void mks_motor_move(void);
void bltouch_duty(uint32_t duty);
void BLTOUCH_push_down(void);
void BLTOUCH_push_up(void);
void BLtouch_reset_and_push_up(void);

void spindle_check_init(void);
void spindle_check(void);


void mks_wifi_scanf(void);
#endif

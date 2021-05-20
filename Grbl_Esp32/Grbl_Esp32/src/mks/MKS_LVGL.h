#ifndef __MKS_LVGL_H
#define __MKS_LVGL_H

#include "MKS_TS35.h"
#include "MKS_FREERTOS_TASK.h"
#include "MKS_ctrl.h"
#include "lvgl.h"
#include "../Serial.h"
#include "MKS_SDCard.h"


#define MKS_GRBL_CMD_SEND(A)            serila_write_into_buffer((uint8_t *)A)   

#define MKS_GRBL_WEB_CMD_SEND(A)        serial_web_input_into_buffer((uint8_t *)A)
#define MKS_GRBL_WEB_HEX_CMD_SEND(A)    serial_web_input_into_hex(A)

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
    P_0_PERSEN,
}GRBL_POWER;

typedef enum {
    GRBL_RUN,
    GRBL_PAUSE,
    GRBL_STOP,          
    GRBL_RESTARTING,
}GRBL_RUN_STATUS_t;

typedef enum {

    BL_NONE,
    BL_BEGIN,           //开始调整
    BL_UP,
    BL_DOWN,
    BL_ADJ_ING,         //正在调整
    BL_ADJ_END,         //调整结束

}BLTOUCH_STATUS;

typedef struct{
    GRBL_MOVE_DIS               move_dis;           // 移动距离
    GRBL_Language               language;           // 语言设置
    GRBL_LIGHT_STATUS           light_status;       // 灯状态
    GRBL_POWER                  power_persen;       // 功率步长设置
    BLTOUCH_STATUS              bl_status;          // BLTOUCH运行状态
    // GRBL_RUN_STATUS_t           run_status;         // 运行状态
    // uint8_t                     power_persen;       // 功率百分比
    uint16_t                    cave_speed;         // 雕刻速度
    uint16_t                    move_speed;         // 移动速度
    uint16_t                    X_Pos;              // x坐标
    uint16_t                    Y_Pos;              // y坐标
    uint8_t                     mks_sd_status;      // sd卡是否插入, 0:没检测到SD卡， 1:检测到SD卡
    uint16_t                    mks_sd_file_times;  // 读取时，以6个文件为基础，从times*6开始显示文件名
    bool                        is_mks_ts35_flag;   // 是否是通过TS35执行的雕刻功能
    bool                        wifi_connect_status;// wifi連接轉態檢測
    bool                        wifi_check_status;  // 是否需要檢測wifi連接
    uint8_t                     wifi_back_from;     // 判断wifi界面是从哪里进去的 0=主界面， 1=关于界面
    bool                        wifi_connect_enable;// 允许wifi自动连接
    bool                        popup_1_flag;
}GRBL_CRTL;
extern GRBL_CRTL mks_grbl;

typedef enum {

    MKS_UI_PAGE_LOADING,

    MKS_UI_Ready,
    MKS_UI_Adjust,
    MKS_UI_Control,
    MKS_UI_Caving,
    MKS_UI_Pring,
    MKS_UI_Tool,
    MKS_UI_Wifi,
    MKS_UI_Frame,
    MKS_UI_inFile,

}mks_ui_page_t;


#define DEFAULT_UI_COUNT    1
typedef struct {

    mks_ui_page_t mks_ui_page;
    uint8_t wait_count;             // 等待LVGL事件生成缓冲，用于界面数据更新

}LVGL_UI_PAGE_t;
extern LVGL_UI_PAGE_t mks_ui_page;


// typedef enum {

//     ui_main_imgbtn_first_pos_x = -170,
//     ui_main_imgbtn_first_pos_y = 0,

//     ui_main_imgbtn_second_pos_x = 0,
//     ui_main_imgbtn_second_pos_y = 0,

//     ui_main_imgbtn_third_pos_x = 170,
//     ui_main_imgbtn_third_pos_y = 0,

// }MKS_UI_POS_t;

// typedef struct {
//     MKS_UI_POS_t ui_pos;


// }MKS_LV_DRAW_UI_t;


#define SD_FILE_NAME_LENGTH     64      //文件名长度
#define SD_FILE_PAGE_NUM        6       //一页能显示的文件个数
#define SD_FILE_PAGE            50*6    //允许最多50页，每页6个文件，允许总文件数为 50*6 = 300个 

typedef struct {
    char sd_file_name[SD_FILE_PAGE];                            //建立非文件夹二维数组
    char sd_dir_num[255];                                       //文件夹下标（最大允许255个文件夹）
    char sd_file_num;                                           //文件个数
}MKS_SD_t;
extern MKS_SD_t mks_sd;



void mks_lvgl_init(void);
void lvgl_test(void);
SDState mks_readSD_Status(void);
float mks_caving_persen(void);
void mks_grbl_parg_init(void);
#endif

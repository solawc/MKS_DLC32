#include "MKS_FREERTOS_TASK.h"


#define DISP_TASK_STACK             4096*2
#define DISP_TASK_PRO               5
#define DISP_TASK_CORE              1

TaskHandle_t lv_disp_tcb = NULL;
static void mks_page_data_updata(void);

void lvgl_disp_task(void *parg) { 

    TickType_t       xLastWakeTime;
    const TickType_t xDisplayFrequency = 5;                  // in ticks (typically ms)
    xLastWakeTime                      = xTaskGetTickCount();  // Initialise the xLastWakeTime variable with the current time.
    // vTaskDelay(1000);

    mks_lvgl_init();
    mks_draw_ready();
    mks_grbl.wifi_connect_enable = true;
    LCD_BLK_OFF;

    while(1) {
        lv_task_handler();
        mks_page_data_updata();
        // vTaskDelay(5); // 5ms
        vTaskDelayUntil(&xLastWakeTime, xDisplayFrequency);
    }
}

uint8_t count_updata = 0;
uint8_t fram_count = 0;
static void mks_page_data_updata(void) { 

    if(mks_ui_page.mks_ui_page == MKS_UI_PAGE_LOADING) {
        /* Do not updata */
        return ;
    }
    else if (mks_ui_page.mks_ui_page == MKS_UI_Ready) {  //只有在当前页面才更新数据

        if((count_updata == 20) || (count_updata > 20) ) {        // 20*5=100ms
            if(SD_ready_next == false) ready_data_updata();
            count_updata = 0;
        }
    }
    else if(mks_ui_page.mks_ui_page == MKS_UI_Pring) { // 雕刻界面更新数据

        if((count_updata == 200) || (count_updata > 200) ) { // 200*5=1000ms = 1s
            if(SD_ready_next == false) {
                mks_print_data_updata();
                if(sys.state == State::Idle) {
                    MKS_GRBL_CMD_SEND("~");
                }
            } 
            count_updata = 0;
        }
    }
    else if(mks_ui_page.mks_ui_page == MKS_UI_Control) {  //控制界面

        if((count_updata == 20) || (count_updata > 20) ) { // 20*5=100ms = 1s
            hard_home_check();
            soft_home_check();
            count_updata = 0;
        }
    }
    else if(mks_ui_page.mks_ui_page == MKS_UI_Frame) { 
        
        if((count_updata == 100) || (count_updata > 100) ) { // 100*5=100ms = 1s
            if(frame_ctrl.is_begin_run == true) {

                    if(mks_get_frame_status() == true) {
                        if(fram_count == 10) {
                            frame_finsh_popup();
                            frame_ctrl.is_begin_run = false;
                            fram_count = 0;
                        }
                        fram_count++;
                    }else {
                        fram_count = 0;
                    }
            }
        }
    }
    else if(mks_ui_page.mks_ui_page == MKS_UI_Wifi) {
        if((mks_wifi.wifi_scanf_status == wifi_scanf_begin) || (mks_wifi.wifi_scanf_status == wifi_scanf_waitting)) {
            mks_wifi_scanf();
        }else if(mks_wifi.wifi_scanf_status == wifi_scanf_succeed){
            mks_lv_clean_ui();
            mks_draw_wifi_show();
            mks_wifi.wifi_scanf_status = wifi_none;
        }else if(mks_wifi.wifi_scanf_status == wifi_connecting) {
            if(mks_grbl.wifi_connect_status == true) {
                mks_lv_clean_ui();
                mks_draw_wifi();
                mks_wifi.wifi_scanf_status = wifi_none;
            }
        }
        else if(mks_wifi.wifi_scanf_status == wifi_scanf_fail) {
            mks_lv_clean_ui();
            mks_draw_wifi();
            mks_wifi.wifi_scanf_status = wifi_none;
        }
    }
    
    count_updata++;
}

// // tskNO_AFFINIT 
void disp_task_init(void) {

    xTaskCreatePinnedToCore(lvgl_disp_task,     // task
                            "lvglTask",         // name for task
                            DISP_TASK_STACK,    // size of task stack
                            NULL,               // parameters
                            DISP_TASK_PRO,      // priority
                            // nullptr,
                            &lv_disp_tcb,
                            DISP_TASK_CORE      // must run the task on same core
                                                // core
    );
}
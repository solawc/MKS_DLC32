#include "MKS_FREERTOS_TASK.h"

#define DISP_TASK_STACK             4096
#define DISP_TASK_PRO               5
#define DISP_TASK_CORE              1

void lvgl_disp_task(void *parg) { 
    mks_lvgl_init();
    // lv_draw_ready();
    mks_draw_ready();
    disp_task_data_updata();
    LCD_BLK_ON;
    while(1) {
        // if(!SPI.is_spi_inTranscation()) {
        //     lv_task_handler();
        // }
        lv_task_handler();
        vTaskDelay(5); // 5ms
    }
}

// tskNO_AFFINIT
void disp_task_init(void) {

    xTaskCreatePinnedToCore(lvgl_disp_task,     // task
                            "lvglTask",         // name for task
                            DISP_TASK_STACK,    // size of task stack
                            NULL,               // parameters
                            DISP_TASK_PRO,      // priority
                            nullptr,
                            DISP_TASK_CORE      // must run the task on same core
                                                // core
    );
}


#define DISP_UPDATA_TASK_STACK             4096
#define DISP_UPDATA_TASK_PRO               1
#define DISP_UPDATA_TASK_CORE              1

void lvgl_disp_data_updata(void *parg) { 

    while(1) {
        if (mks_ui_page.mks_ui_page == MKS_UI_Ready) {  //只有在当前页面才更新数据
            ready_data_updata();
        }
        vTaskDelay(500); // 500ms
    }
}


void disp_task_data_updata(void) {

    xTaskCreatePinnedToCore(lvgl_disp_data_updata,     // task
                            "updata disp",         // name for task
                            DISP_UPDATA_TASK_STACK,    // size of task stack
                            NULL,               // parameters
                            DISP_UPDATA_TASK_PRO,      // priority
                            nullptr,
                            DISP_UPDATA_TASK_CORE      // must run the task on same core
                                                // core
    );
}



#include "MKS_FREERTOS_TASK.h"

#define DISP_TASK_STACK             4096
#define DISP_TASK_PRO               1
#define DISP_TASK_CORE              0

// portMUX_TYPE lvMutex = portMUX_INITIALIZER_UNLOCKED;

void lvgl_disp_task(void *parg) {
    mks_lvgl_init();
    lv_draw_ready();
    LCD_BLK_ON;
    while(1) {
        // if(!SPI.is_spi_inTranscation()) {
        //     lv_task_handler();
        // }
        lv_task_handler();
        vTaskDelay(5); // 5ms
    }
}

//tskNO_AFFINITY
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


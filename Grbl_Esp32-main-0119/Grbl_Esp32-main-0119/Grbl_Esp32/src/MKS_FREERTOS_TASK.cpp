#include "MKS_FREERTOS_TASK.h"

#define DISP_TASK_STACK             4096
#define DISP_TASK_PRO               1
#define DISP_TASK_CORE              CONFIG_ARDUINO_RUNNING_CORE

void lvgl_disp_task(void *parg) {
    mks_lvgl_init();
    lv_draw_ready();
    while(1) {
        // lv_tick_inc(10);
        // lv_task_handler();
        // delay(10); //10ms
        vTaskDelay(100);
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


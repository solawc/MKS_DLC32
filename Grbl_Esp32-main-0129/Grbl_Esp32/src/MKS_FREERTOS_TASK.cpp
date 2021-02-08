#include "MKS_FREERTOS_TASK.h"

#define DISP_TASK_STACK             4096*4
#define DISP_TASK_PRO               1
#define DISP_TASK_CORE              CONFIG_ARDUINO_RUNNING_CORE

// portMUX_TYPE lvMutex = portMUX_INITIALIZER_UNLOCKED;

void lvgl_disp_task(void *parg) {
    Serial.printf("Enter LVGL");
    mks_lvgl_init();
    // lvgl_test();
    lv_draw_ready();

    while(1) {
        if(!SPI.is_spi_inTranscation()) {
            lv_task_handler();
        }
        vTaskDelay(10);
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


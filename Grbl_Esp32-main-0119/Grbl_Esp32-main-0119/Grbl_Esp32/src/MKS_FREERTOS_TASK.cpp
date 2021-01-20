#include "MKS_FREERTOS_TASK.h"

#define DISP_TASK_STACK             1024*60
#define DISP_TASK_PRO               8
static TaskHandle_t lvTaskHandle = NULL;
void lvgl_disp_task(void *parg) {
    printf(" Freertos task---->lvgl task");
    lv_init();
    mks_lvgl_init();

    while(1) {
        // lv_tick_inc(1);
        lv_task_handler();
        delay(10);
    }
}

void disp_task_init(void) {

    // xTaskCreate(
    //         lvgl_disp_task,             /*任务函数*/
    //         "lvgl_disp_task",           /*带任务名称的字符串*/
    //         DISP_TASK_STACK,            /*堆栈大小，单位为字节*/
    //         NULL,                       /*作为任务输入传递的参数*/
    //         DISP_TASK_PRO,              /*任务的优先级*/
    //         NULL);                      /*任务句柄*/

    xTaskCreatePinnedToCore(lvgl_disp_task,     // task
                            "serialCheckTask",  // name for task
                            DISP_TASK_STACK,    // size of task stack
                            NULL,               // parameters
                            DISP_TASK_PRO,      // priority
                            &lvTaskHandle,
                            SUPPORT_TASK_CORE   // must run the task on same core
                                                // core
    );
}

#define lvgl_TASK_STACK             4096
#define lvgl_TASK_PRO               7
void lvgl_task(void *parg) {
    
    while(1) {
        ts32_touch_read();
        lv_task_handler();
        delay(5);
    }
}

void lvgl_task_init(void) {
    xTaskCreate(
            lvgl_task,                  /*任务函数*/
            "lvgl_task",                /*带任务名称的字符串*/
            DISP_TASK_STACK,            /*堆栈大小，单位为字节*/
            NULL,                       /*作为任务输入传递的参数*/
            DISP_TASK_PRO,              /*任务的优先级*/
            NULL);                      /*任务句柄*/
}

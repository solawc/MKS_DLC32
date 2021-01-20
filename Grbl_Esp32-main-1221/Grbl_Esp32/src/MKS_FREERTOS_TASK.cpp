#include "MKS_FREERTOS_TASK.h"


void lvgl_disp_task(void *parg) {

    while(1) {
        lv_tick_inc(1);
        // delay(1);
        vTaskDelay(1);
    }
}


void lvgl_touch_task(void *parg) {

   while(1) {


   } 
}



void disp_task_init(void) {

    xTaskCreate(
              lvgl_disp_task,           /*任务函数*/
              "lvgl_disp_task",         /*带任务名称的字符串*/
              512,                      /*堆栈大小，单位为字节*/
              NULL,                     /*作为任务输入传递的参数*/
              1,                        /*任务的优先级*/
              NULL);                    /*任务句柄*/
}
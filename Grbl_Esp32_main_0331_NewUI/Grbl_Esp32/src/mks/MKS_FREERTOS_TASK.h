#ifndef __MKS_FREERTOS_TASK_
#define __MKS_FREERTOS_TASK_

#include "FreeRTOS.h"
#include "MKS_LVGL.h"
#include "MKS_draw_ready.h"



void disp_task_init(void);
void disp_task_data_updata(void);
#endif

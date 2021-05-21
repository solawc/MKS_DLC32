#include "MKS_FREERTOS_TASK.h"


#define DISP_TASK_STACK             4096*2
#define DISP_TASK_PRO               5
#define DISP_TASK_CORE              1

TaskHandle_t lv_disp_tcb = NULL;
static void mks_page_data_updata(void);

void lvgl_disp_task(void *parg) { 
    mks_lvgl_init();
    // lv_draw_ready();
    mks_draw_ready();
    // disp_task_data_updata();
    // uint8_t count = 0;
    mks_grbl.wifi_connect_enable = true;
    // LCD_BLK_ON;
    LCD_BLK_OFF;
    while(1) {

        lv_task_handler();

        mks_page_data_updata();

        vTaskDelay(5); // 5ms
    }
}

uint8_t count_updata = 0;
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
                    // MKS_GRBL_CMD_SEND("M3 S0\n");
                    MKS_GRBL_CMD_SEND("~");
                    // mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                    // mks_clear_print();
                    // mks_draw_ready();
                }
            } 
            count_updata = 0;
        }
    }
    else if(mks_ui_page.mks_ui_page == MKS_UI_Control) {  //控制界面

        if((count_updata == 20) || (count_updata > 20) ) { // 200*5=1000ms = 1s
            hard_home_check();
            soft_home_check();
            count_updata = 0;
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


// #define DISP_UPDATA_TASK_STACK             4096
// #define DISP_UPDATA_TASK_PRO               6
// #define DISP_UPDATA_TASK_CORE              1

// TaskHandle_t lv_data_updata_tcb = NULL;

// void lvgl_disp_data_updata(void *parg) { 

//     while(1) {

//         // if(mks_ui_page.mks_ui_page == MKS_UI_PAGE_LOADING) {
//         //     /* Do not updata */
//         // }
//         // else if (mks_ui_page.mks_ui_page == MKS_UI_Ready) {  //只有在当前页面才更新数据
//         //     if(SD_ready_next == false) ready_data_updata();
//         // }
//         // else if(mks_ui_page.mks_ui_page == MKS_UI_Pring) { // 雕刻界面更新数据

//         //     if(SD_ready_next == false)  mks_print_data_updata();
//         // }
//         vTaskDelay(1000); // 500ms
//     }
// }
           
// void disp_task_data_updata(void) {

//     xTaskCreatePinnedToCore(lvgl_disp_data_updata,     // task
//                             "updata disp",              // name for task
//                             DISP_UPDATA_TASK_STACK,    // size of task stack
//                             NULL,               // parameters
//                             DISP_UPDATA_TASK_PRO,      // priority
//                             // nullptr,
//                             &lv_data_updata_tcb,
//                             DISP_UPDATA_TASK_CORE      // must run the task on same core
//                                                 // core
//     );
// }

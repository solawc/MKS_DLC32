#include "mks_test.h"







void test_task(void *parg) {

    static uint8_t motor_status = 0;
    static uint8_t laser_status = 0;
    static uint8_t count = 0;

    while(1) {
    
    grbl_sendf(CLIENT_SERIAL, "test send\n");

        if(motor_status == 0) {
            grbl_sendf(CLIENT_SERIAL, "Motro T\n");

            if(!count) {
                MKS_GRBL_CMD_SEND("$J=G91X1000.0Y1000.0Z1000.0F5000\n");     
            }
                   
        }
        else{
            grbl_sendf(CLIENT_SERIAL, "Motro E\n");
            if(!count) {
                MKS_GRBL_CMD_SEND("$J=G91X-1000.0Y-1000.0Z-1000.0F5000\n");     
            } 
        }
        
        count++;
        if(count == 25) {
            motor_status = 1 - motor_status;
            count = 0;
        }

        if(laser_status == 0) {
            grbl_sendf(CLIENT_SERIAL, "laser off\n");
            MKS_GRBL_CMD_SEND("M3 S0\n");  
            laser_status = 1;
        }else {
            grbl_sendf(CLIENT_SERIAL, "laser on\n");
            MKS_GRBL_CMD_SEND("M3 S1000\n");  
            laser_status = 0;
        }

        vTaskDelay(1000); // 1s
    }
}

// tskNO_AFFINITY
void test_task_init(void) {

    xTaskCreatePinnedToCore(test_task,     // task
                            "dlc test",         // name for task
                            4096,    // size of task stack
                            NULL,               // parameters
                            5,      // priority
                            nullptr,
                            1      // must run the task on same core
                                                // core
    );
}

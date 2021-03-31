#include "MKS_ctrl.h"

#define BLTOUCH_FREQ           50   //HZ
#define RESOLUTION             16   //分辨率
#define BLTOUCH_CHANNEL         1


void bltouch_interrupt_call_back(void) {

    BLtouch_reset_and_push_up();
    grbl_sendf(CLIENT_SERIAL, "interrupt");
    sys_rt_exec_state.bit.motionCancel = true;
}

void bltouch_init(void) {
    pinMode(BLTOUCH_READ, INPUT_PULLDOWN);
    attachInterrupt(BLTOUCH_READ ,bltouch_interrupt_call_back, RISING);  //RISING
    ledcSetup(BLTOUCH_CHANNEL, BLTOUCH_FREQ, RESOLUTION); // 设置通道
    ledcAttachPin(BLTOUCH_PWM, BLTOUCH_CHANNEL);  // 将通道与对应的引脚连接
}

void bltouch_duty(uint32_t duty) {

    ledcWrite(BLTOUCH_CHANNEL, duty);
}


int bltouch_read(void) { 

    int status = 0;

    status = digitalRead(BLTOUCH_READ);    

    return status;
}

void BLTOUCH_push_down(void) { 
    bltouch_duty(2120);
}

void BLTOUCH_push_up(void) { 
    bltouch_duty(4826);
}

void BLtouch_reset_and_push_up(void) { 
    bltouch_duty(7189);
}

mks_spindle_t mks_spindle;
void spindle_check_init(void) { 
    /*
        - 默认激光头空闲关使能
        - 默认起始时间0
        - 默认结束时间0
        - 默认等待时间30s
    */
    mks_spindle.spindle_status = sp_none;
    mks_spindle.tick_start = 0;
    mks_spindle.tick_end = 0;
    mks_spindle.out_time = 30*1000000; //30s
}

void spindle_check(void) {

    switch(mks_spindle.spindle_status) {

        case sp_none:
            mks_spindle.spindle_status = sp_begin;
        break;

        case sp_begin:
            if(stepper_idle) {
                mks_spindle.spindle_status = sp_load;
            }
        break;

        case sp_load:
            if(stepper_idle) {
                mks_spindle.tick_start = esp_timer_get_time();
                mks_spindle.spindle_status = sp_wait;
            }else {
                mks_spindle.spindle_status = sp_begin;
            }
        break;

        case sp_wait:
            if(stepper_idle) {
                mks_spindle.tick_end = esp_timer_get_time();

                if(mks_spindle.tick_end <= mks_spindle.tick_start) {   // 时间防止溢出
                    mks_spindle.tick_start = esp_timer_get_time();
                }
                else if((mks_spindle.tick_end - mks_spindle.tick_start) > mks_spindle.out_time) {
                    spindle->stop();
                    mks_spindle.spindle_status = sp_end;
                }
            }else {
                mks_spindle.spindle_status = sp_begin; // 重头开始
            }
        break;

        case sp_end:
            mks_spindle.tick_start = 0;
            mks_spindle.tick_end = 0;
            mks_spindle.spindle_status = sp_begin; // 重头开始
        break;
    }
}



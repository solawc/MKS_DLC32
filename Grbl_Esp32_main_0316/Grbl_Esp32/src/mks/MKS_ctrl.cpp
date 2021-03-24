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



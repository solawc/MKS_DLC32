#include "MKS_ctrl.h"

#define BLTOUCH_FREQ           50   //HZ
#define RESOLUTION             16   //分辨率
#define BLTOUCH_CHANNEL         1

void bltouch_init(void) {

    pinMode(BLTOUCH_READ, INPUT_PULLUP);
    ledcSetup(BLTOUCH_CHANNEL, BLTOUCH_FREQ, RESOLUTION); // 设置通道
    ledcAttachPin(BLTOUCH_PWM, BLTOUCH_CHANNEL);  // 将通道与对应的引脚连接
}

void bltouch_duty(uint32_t duty) {

    ledcWrite(BLTOUCH_CHANNEL, duty);
}


bool bltouch_read(void) { 

    bool status = false;

    

    return status;
}



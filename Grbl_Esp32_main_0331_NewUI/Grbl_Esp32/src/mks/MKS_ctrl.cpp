#include "MKS_ctrl.h"
#include "../WebUI/WebSettings.h"
#include "../WebUI/WifiConfig.h"


#define BLTOUCH_FREQ           50   //HZ
#define RESOLUTION             16   //分辨率
#define BLTOUCH_CHANNEL        15
#define BLTOUCH_RESET          978   //HZ

void bltouch_interrupt_call_back(void) {
    BLtouch_reset_and_push_up();
    mks_grbl.bl_status = BL_UP;
    grbl_sendf(CLIENT_SERIAL, "interrupt");
    sys_rt_exec_state.bit.motionCancel = true;
}

void bltouch_init(void) {
    pinMode(BLTOUCH_READ, INPUT_PULLDOWN);
    attachInterrupt(BLTOUCH_READ ,bltouch_interrupt_call_back, RISING);  //RISING
    ledcSetup(BLTOUCH_CHANNEL, BLTOUCH_FREQ, RESOLUTION); // 设置通道
    ledcAttachPin(BLTOUCH_PWM, BLTOUCH_CHANNEL);  // 将通道与对应的引脚连接
    mks_grbl.bl_status = BL_NONE;
}

void bltouch_reset(void) { 
    ledcSetup(BLTOUCH_CHANNEL, BLTOUCH_RESET, RESOLUTION); // 设置通道
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
    mks_grbl.bl_status = BL_DOWN;
    bltouch_duty(2120);
}

void BLTOUCH_push_up(void) {
    mks_grbl.bl_status = BL_UP; 
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

/***********************************************************************MKS WIFI*************************************************************/
MKS_WIFI_t mks_wifi;
const char mks_ssid[] = "MAKERBASE3D";
const char mks_password[] = "makerbase3d";

char WIFI_SSID_CMD[128]="ESP100";
char WIFI_PASSWORD_CMD[128]="ESP101";
char WIFI_CONNECT_CMD[]="ESP210";
char mks_wifi_send[128];

void mks_wifi_scanf(void) {
    int n = WiFi.scanComplete();
    mks_wifi.begin_scanf_num = 0;
    switch (n) {
        case -2:                      // Scan not triggered
            WiFi.scanNetworks(true);  // Begin async scan
            grbl_send(CLIENT_SERIAL ,"scanNetworks\n\n");
            break;
        case -1:  // Scan in progress
            grbl_send(CLIENT_SERIAL ,"waitting\n\n");
            break;
        default:
            // 获取16个wifi名
            for (int i = 0; i < MKS_WIFI_NUM; ++i) {   
                // if( (i >= ((mks_wifi.wifi_show_page * MKS_WIFI_NUM) - MKS_WIFI_NUM)) && (i <= (mks_wifi.wifi_show_page * MKS_WIFI_NUM)) ) {
                //     memcpy(mks_wifi.wifi_name_str[mks_wifi.begin_scanf_num], WiFi.SSID(i).c_str(), 128);
                //     mks_wifi.begin_scanf_num++;
                // }
                // if(i > (mks_wifi.wifi_show_page * MKS_WIFI_NUM)) break;

                memcpy(mks_wifi.wifi_name_str[mks_wifi.begin_scanf_num], WiFi.SSID(i).c_str(), 128);
                mks_wifi.begin_scanf_num++;
            }

            WiFi.scanDelete();
            // Restart the scan in async mode so new data will be available
            // when we ask again.
            n = WiFi.scanComplete();
            if (n == -2) {
                WiFi.scanNetworks(true);
            }
            break;
        }
}


void mks_wifi_connect(void) { 

    WebUI::wifi_sta_ssid->setStringValue("MAKERBASE3D");
    WebUI::wifi_sta_password->setStringValue("makerbase3d");
    WiFi.enableAP(false);
    WiFi.mode(WIFI_STA);
    WebUI::wifi_config.begin();
}

void mks_wifi_connect_test(char *ssid, char *password) {

    WebUI::wifi_sta_ssid->setStringValue(ssid);
    WebUI::wifi_sta_password->setStringValue(password);
    WiFi.enableAP(false);
    WiFi.mode(WIFI_STA);
    WebUI::wifi_config.begin();
}


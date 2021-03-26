# 1 "C:\\Users\\Administrator\\AppData\\Local\\Temp\\tmpc_j68bt6"
#include <Arduino.h>
# 1 "E:/Github/Makerbase/ESP32/DLC32/MKS_DLC32/Grbl_Esp32_main_0316/Grbl_Esp32/Grbl_Esp32.ino"
# 21 "E:/Github/Makerbase/ESP32/DLC32/MKS_DLC32/Grbl_Esp32_main_0316/Grbl_Esp32/Grbl_Esp32.ino"
#include "src/Grbl.h"
void setup();
void loop();
#line 23 "E:/Github/Makerbase/ESP32/DLC32/MKS_DLC32/Grbl_Esp32_main_0316/Grbl_Esp32/Grbl_Esp32.ino"
void setup() {
    grbl_init();
}

void loop() {
    run_once();
}
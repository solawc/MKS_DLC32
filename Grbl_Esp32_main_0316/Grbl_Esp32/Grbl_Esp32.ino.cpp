# 1 "C:\\Users\\sola\\AppData\\Local\\Temp\\tmpu6oklyja"
#include <Arduino.h>
# 1 "E:/my_workspace/Makerbase/MKS_DLC32/Grbl_Esp32_main_0316/Grbl_Esp32/Grbl_Esp32.ino"
# 21 "E:/my_workspace/Makerbase/MKS_DLC32/Grbl_Esp32_main_0316/Grbl_Esp32/Grbl_Esp32.ino"
#include "src/Grbl.h"
void setup();
void loop();
#line 23 "E:/my_workspace/Makerbase/MKS_DLC32/Grbl_Esp32_main_0316/Grbl_Esp32/Grbl_Esp32.ino"
void setup() {
    grbl_init();
}

void loop() {
    run_once();
}
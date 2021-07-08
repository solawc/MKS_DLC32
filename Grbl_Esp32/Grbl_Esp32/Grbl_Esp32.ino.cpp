# 1 "C:\\Users\\SOLA\\AppData\\Local\\Temp\\tmp4lf9e80a"
#include <Arduino.h>
# 1 "F:/sola_github/ESP32/ESP_DLC32/MKS_DLC32/Grbl_Esp32/Grbl_Esp32/Grbl_Esp32.ino"
# 21 "F:/sola_github/ESP32/ESP_DLC32/MKS_DLC32/Grbl_Esp32/Grbl_Esp32/Grbl_Esp32.ino"
#include "src/Grbl.h"
void setup();
void loop();
#line 23 "F:/sola_github/ESP32/ESP_DLC32/MKS_DLC32/Grbl_Esp32/Grbl_Esp32/Grbl_Esp32.ino"
void setup() {
    grbl_init();
}

void loop() {
    run_once();
}
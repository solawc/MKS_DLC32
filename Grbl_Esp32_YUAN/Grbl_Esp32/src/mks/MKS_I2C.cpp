#include "MKS_I2C.h"
#include "Wire.h"

void I2C_init(void) {
    Wire.begin(IIC_SDA,IIC_SCL,400000);
    Wire.beginTransmission(0x70);
    Wire.endTransmission();
}
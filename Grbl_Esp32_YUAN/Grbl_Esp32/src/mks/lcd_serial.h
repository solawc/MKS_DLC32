#ifndef __lcd_serial_h
#define __lcd_serial_h

#include "MKS_LVGL.h"
#include "../report.h"


namespace WebUI { 
    class LCD_Server {

    static const int TXBUFFERSIZE = 1200;
    static const int RXBUFFERSIZE = 256;
    static const int FLUSHTIMEOUT = 500;

public:

void   begin();
void   end();
void   write(const uint8_t *buffer, size_t size);
int    read(void);


private:

    uint8_t  _TXbuffer[TXBUFFERSIZE];
    uint16_t _TXbufferSize;

    uint8_t  _RXbuffer[RXBUFFERSIZE];
    uint16_t _RXbufferSize;
    uint16_t _RXbufferpos;
    };

    extern LCD_Server mks_lcd;
}





#endif

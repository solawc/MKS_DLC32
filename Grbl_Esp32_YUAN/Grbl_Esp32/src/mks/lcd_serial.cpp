#include "lcd_serial.h"



namespace WebUI { 

    class LCD_Server mks_lcd;

    void LCD_Server::begin() {
        _TXbufferSize = 0;
        _RXbufferSize = 0;
        _RXbufferpos  = 0;
    }

    void LCD_Server::end() {
        _TXbufferSize = 0;
        _RXbufferSize = 0;
        _RXbufferpos  = 0;
    }

    void LCD_Server::write(const uint8_t *buffer, size_t size) {

        if ((buffer == NULL))  return; 
        
        for (int i = 0; i < 1; i++) {
            _TXbuffer[_TXbufferSize] = buffer[i];
            _TXbufferSize++;
        }
    }

    int LCD_Server::read(void) {
        if (_RXbufferSize > 0) {
            int v = _RXbuffer[_RXbufferpos];
            _RXbufferpos++;

            if (_RXbufferpos > (RXBUFFERSIZE - 1)) {
                    _RXbufferpos = 0;
            }
            _RXbufferSize--;
            return v;
        }else {
            return -1;
        }
    }
}





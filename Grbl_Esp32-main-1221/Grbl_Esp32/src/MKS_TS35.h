#ifndef __MKS_TS35_H
#define __MKS_TS35_H

#include "Grbl.h"
#include "SPI.h" 

#define LCD_WIDTH       480
#define LCD_HEIGHT      320


#define TFT_COLOR_RED		0xF800
#define TFT_COLOR_GREEN		0x07E0
#define TFT_COLOR_BLUE		0x001F
#define TFT_COLOR_BLACK		0x0000
#define TFT_COLOR_WHITE		0xFFFF
#define TFT_COLOR_YELLOW    0xFFE0


void TS32_Init(void);

void TFT_DisplayOn(void);
void TFT_DisplayOff(void);
void TFT_DrawPoint(uint16_t x,uint16_t y,uint16_t color);
void TFT_Fill(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
#endif


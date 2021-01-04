#include "MKS_TS35.h"

TS35_DEF ESP_TS35;

static void LCD_WR_REG(uint8_t cmd) {
    
    digitalWrite(LCD_CS, LOW); 
    digitalWrite(LCD_RS, LOW); 
    delayMicroseconds(6);
    LCD_SPI.transfer(cmd);
    digitalWrite(LCD_CS, HIGH); 
    delayMicroseconds(6);
}

static void LCD_WR_DATA(uint8_t data) {

    digitalWrite(LCD_CS, LOW); 
    digitalWrite(LCD_RS, HIGH); 
    delayMicroseconds(6);
    LCD_SPI.transfer(data);
    digitalWrite(LCD_CS, HIGH); 
    delayMicroseconds(6);
}

static uint8_t LCD_Read(uint8_t sdata) {

    uint16_t data;
    return  LCD_SPI.transfer(sdata);;
}

void LCD_Clear(void) {
    TFT_Clear();
}

void TS32_Init(void) {
    
    LCD_SPI.begin(LCD_SCK,LCD_MISO,LCD_MOSI,LCD_CS);     
    /* Init GPIO Pin */
    // pinMode(LCD_CS,OUTPUT);  // LCD CS
    // pinMode(LCD_RS,OUTPUT);  // LCD RS
    // pinMode(LCD_EN,OUTPUT);  // LCD EN
    // pinMode(LCD_RST,OUTPUT); // LCD RST 

    ESP_TS35.LCD_H = LCD_HEIGHT;
    ESP_TS35.LCD_W = LCD_WIDTH;
    ESP_TS35.LCD_COLOR = TFT_COLOR_RED;


    /* Set GPIO pin status */
    digitalWrite(LCD_CS, HIGH); 
    digitalWrite(TOUCH_CS, HIGH); 
    digitalWrite(LCD_RS, HIGH); 
    digitalWrite(LCD_EN, LOW);      //Disable LCD BackLight
    digitalWrite(LCD_RST, HIGH);

    delay_ms(150);
    digitalWrite(LCD_RST, LOW);
    delay_ms(150);
    digitalWrite(LCD_RST, HIGH);

    // TP_SPI.begin(LCD_SCK,LCD_MISO,LCD_MOSI,TOUCH_CS);         
    LCD_SPI.setFrequency(1000000);     //set SPI Freq = 2M
    LCD_SPI.setClockDivider(SPI_CLOCK_DIV16);
    LCD_SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));

    delay_ms(120);
    LCD_WR_REG(0x11);
    delay_ms(120);

    LCD_WR_REG(0x36);

    LCD_WR_REG(0xF0);
    LCD_WR_DATA(0xC3);
    LCD_WR_REG(0xF0);
    LCD_WR_DATA(0x96);

    LCD_WR_REG(0x36);
    // LCD_WR_DATA(0xE8);
    LCD_WR_DATA(0x28);
    LCD_WR_DATA(0x28);
    LCD_WR_REG(0x3A);
    LCD_WR_DATA(0x55);
    LCD_WR_REG(0xB4);
    LCD_WR_DATA(0x01);
    LCD_WR_REG(0xB7);
    LCD_WR_DATA(0xC6);
    LCD_WR_REG(0xE8);
    LCD_WR_DATA(0x40);
    LCD_WR_DATA(0x8A);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x29);
    LCD_WR_DATA(0x19);
    LCD_WR_DATA(0xA5);
    LCD_WR_DATA(0x33);
    LCD_WR_REG(0xC1);
    LCD_WR_DATA(0x06);
    LCD_WR_REG(0xC2);
    LCD_WR_DATA(0xA7);
    LCD_WR_REG(0xC5);
    LCD_WR_DATA(0x18);
    LCD_WR_REG(0xE0);     // Positive Voltage Gamma Control
    LCD_WR_DATA(0xF0);
    LCD_WR_DATA(0x09);
    LCD_WR_DATA(0x0B);
    LCD_WR_DATA(0x06);
    LCD_WR_DATA(0x04);
    LCD_WR_DATA(0x15);
    LCD_WR_DATA(0x2F);
    LCD_WR_DATA(0x54);
    LCD_WR_DATA(0x42);
    LCD_WR_DATA(0x3C);
    LCD_WR_DATA(0x17);
    LCD_WR_DATA(0x14);
    LCD_WR_DATA(0x18);
    LCD_WR_DATA(0x1B);
    LCD_WR_REG(0xE1);     // Negative Voltage Gamma Control
    LCD_WR_DATA(0xF0);
    LCD_WR_DATA(0x09);
    LCD_WR_DATA(0x0B);
    LCD_WR_DATA(0x06);
    LCD_WR_DATA(0x04);
    LCD_WR_DATA(0x03);
    LCD_WR_DATA(0x2D);
    LCD_WR_DATA(0x43);
    LCD_WR_DATA(0x42);
    LCD_WR_DATA(0x3B);
    LCD_WR_DATA(0x16);
    LCD_WR_DATA(0x14);
    LCD_WR_DATA(0x17);
    LCD_WR_DATA(0x1B);
    LCD_WR_REG(0xF0);
    LCD_WR_DATA(0x3C);
    LCD_WR_REG(0xF0);
    LCD_WR_DATA(0x69);
    delay_ms(120);          // Delay 120ms
    LCD_WR_REG(0x29);        // Display ON
  
    // LCD_SPI.endTransaction();
    LCD_Clear();
    digitalWrite(LCD_EN, HIGH);
    delay_ms(1000);
    // TFT_Fill(0,0,100,100,TFT_COLOR_GREEN); 
}

void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	x2 = x2>LCD_WIDTH ? LCD_WIDTH:x2;
	y2 = y2>LCD_WIDTH ? LCD_HEIGHT:y2;

    LCD_WR_REG(0x2a);//列地址设置
    LCD_WR_DATA(x1>>8);
    LCD_WR_DATA(x1);
    LCD_WR_DATA(x2>>8);
    LCD_WR_DATA(x2);

    LCD_WR_REG(0x2b);//行地址设置
    LCD_WR_DATA(y1>>8);
    LCD_WR_DATA(y1);
    LCD_WR_DATA(y2>>8);
    LCD_WR_DATA(y2);
    LCD_WR_REG(0x2c);//储存器写
}

uint16_t LCD_RD_ID(void) {
	uint8_t id1,id2;
    digitalWrite(LCD_CS, LOW); 
    digitalWrite(LCD_RS, LOW); 
	LCD_WR_DATA(0xd3);
    digitalWrite(LCD_RS, HIGH); 
	LCD_Read(0xff);
	id1 = LCD_Read(0xff);
	id2 = LCD_Read(0xff);
	digitalWrite(LCD_CS, HIGH); 
	return (id1<<8|id2);
}


void TFT_DisplayOn(void) {
	LCD_WR_REG(0x29);
}

void TFT_DisplayOff(void) {
	LCD_WR_REG(0x28);
}

void TFT_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
{
    LCD_Address_Set(x,y,x,y);//设置光标位置
    LCD_WR_DATA(color>>8);
    LCD_WR_DATA(color);
}

void TFT_Fill(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
    uint16_t x,y;
    LCD_Address_Set(x1,y1,x2,y2);      //设置光标位置
    for(x=x1; x<x2; x++){
        for(y=y1; y<y2; y++){
			LCD_WR_DATA(color>>8); //设置光标位置
			LCD_WR_DATA(color); //设置光标位置
		}
    }
}

void TFT_Clear(void)
{
    TFT_Fill(0,0,LCD_WIDTH,LCD_HEIGHT,TFT_COLOR_GREEN);
}

void TS35_Test(void) {

    digitalWrite(LCD_CS, LOW);
    LCD_SPI.transfer(0X11);
    digitalWrite(LCD_CS, HIGH); 
    LCD_SPI.endTransaction();
}

/**************************************************TOUCH****************************************************/
void ts35_touch_init(void) {

    ESP_TS35.TOUCH_X = 0;
    ESP_TS35.TOUCH_Y = 0;
}

uint8_t touch_read_write_byte(uint8_t sdata) {

    uint8_t rdata = 0;

    TFT_LCD_CS_H;
    TFT_TOUCH_CS_L;
    delayMicroseconds(6);
    rdata = LCD_SPI.transfer(sdata);
    TFT_TOUCH_CS_H;
    delayMicroseconds(6);
    return rdata;
}

// uint16_t X_Addata=0,Y_Addata=0;
void XPT2046_Rd_Addata(void)
{
    uint16_t temp;
    //delay_ms(1);
    touch_read_write_byte( CHX ) ;
    //delay_ms(1);
    temp=0;//相当于简短的延时啦
    temp= touch_read_write_byte(0x00) ;
    ESP_TS35.TOUCH_Y = temp<<8;
    temp= touch_read_write_byte(0x00) ;
    ESP_TS35.TOUCH_Y |=temp;
    ESP_TS35.TOUCH_Y >>=3;
    ESP_TS35.TOUCH_Y &= 0XFFF;
    //GPIO_SetBits(GPIOC, GPIO_Pin_9);
    
    //GPIO_ResetBits(GPIOC, GPIO_Pin_9);
    //delay_ms(1);
    touch_read_write_byte( CHY) ;
    temp=0;
    //delay_ms(1);
    temp= touch_read_write_byte(0x00);
    ESP_TS35.TOUCH_X=temp<<8;
    temp= touch_read_write_byte(0x00);
    ESP_TS35.TOUCH_X |=temp;
    ESP_TS35.TOUCH_X >>=3;
    ESP_TS35.TOUCH_X &=0XFFF;
}











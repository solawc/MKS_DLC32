/*
This is a sketch to calibrate the screem and list the values to use in the
setCal() function.

The calibration report is sent to the Serial port at 38400 baud.

Designed for use with the TFT_ILI9341 library
https://github.com/Bodmer/TFT_ILI9341

Uses font 2 only.

Created by Rowboteer for the ILI9341 3.4" 320 x 240 TFT touch display: 22/11/15
*/

// TFT Screen pixel resolution in landscape orientation, change these to suit your display
// Defined in landscape orientation !
#define HRES 480
#define VRES 320

// Call up the TFT driver library
#include <SPI.h>
#include <TFT_Touch.h>


// These are the pins I used to interface between the 2046 touch controller and Arduino Mega
// they can be changed to other digital pins

#define DOUT 14  /* Data out pin (T_DO) of touch screen */
#define DIN  27  /* Data in pin (T_DIN) of touch screen */
#define DCS  26  /* Chip select pin (T_CS) of touch screen */
#define DCLK 25  /* Clock pin (T_CLK) of touch screen */
//                  The touch screen interrupt request pin (T_IRQ) is not used

/* Create an instance of the touch screen library */
TFT_Touch touch = TFT_Touch(DCS, DCLK, DIN, DOUT);

int X_Raw = 0, Y_Raw = 0;

void setup()
{
  // Messages are sent to the serial port
  Serial.begin(115200);
  Serial.printf("开始喽！");
  //This is the calibration line produced by the TFT_Touch_Calibrate_v2 sketch
  touch.setCal(481, 3395, 755, 3487, 480, 320, 1);
  touch.setRotation(1);
}

/* Main program */
void loop()
{
  int X_RawData;
  int Y_RawData;
  int X_Coord;
  int Y_Coord;

  // Check if the touch screen is currently pressed
  // Raw and coordinate values are stored within library at this instant
  // for later retrieval by GetRaw and GetCoord functions.

  if (touch.Pressed()) // Note this function updates coordinates stored within library variables
  {
    // Read the current X and Y axis as co-ordinates at the last touch time
    // The values were captured when Pressed() was called!
    X_Coord = touch.X();
    Y_Coord = touch.Y();

    Serial.print(X_Coord); Serial.print(","); Serial.println(Y_Coord);
  }
}
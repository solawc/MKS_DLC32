#pragma once
// clang-format off

/*
    i2s_out_xyz_mks_dlc32.h
    Part of Grbl_ESP32
    Pin assignments for the ESP32 I2S 6-axis board
    2018    - Bart Dring
    2020    - Mitch Bradley
    2020    - Michiyasu Odaki
    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME            "MKS DLC32 V1.0"

#ifdef N_AXIS
    #undef N_AXIS
#endif
#define N_AXIS 3


#ifdef ENABLE_SD_CARD
    #undef ENABLE_SD_CARD
#endif

// I2S (steppers & other output-only pins)
#define USE_I2S_OUT
#define USE_I2S_STEPS
//#define DEFAULT_STEPPER ST_I2S_STATIC

#define I2S_OUT_BCK                 GPIO_NUM_16
#define I2S_OUT_WS                  GPIO_NUM_17
#define I2S_OUT_DATA                GPIO_NUM_21
    
#define X_DISABLE_PIN               I2SO(0)
#define X_DIRECTION_PIN             I2SO(2)
#define X_STEP_PIN                  I2SO(1)
    
#define Y_DISABLE_PIN               I2SO(0)
#define Y_DIRECTION_PIN             I2SO(6)
#define Y_STEP_PIN                  I2SO(5)
    
#define Z_DISABLE_PIN               I2SO(7)
#define Z_DIRECTION_PIN             I2SO(4)
#define Z_STEP_PIN                  I2SO(3)

#define SPINDLE_TYPE                SpindleType::LASER // only one spindle at a time
#define LASER_OUTPUT_PIN            GPIO_NUM_22

#define X_LIMIT_PIN                 GPIO_NUM_33
#define Y_LIMIT_PIN                 GPIO_NUM_35
#define Z_LIMIT_PIN                 GPIO_NUM_34

#define PROBE_PIN                   GPIO_NUM_2//GPIO_NUM_32

#define LCD_SCK				        GPIO_NUM_18
#define LCD_MISO				    GPIO_NUM_19
#define LCD_MOSI				    GPIO_NUM_23
#define LCD_RS					    GPIO_NUM_33
#define LCD_EN					    GPIO_NUM_5      //I2SO(5)
#define LCD_RST					    GPIO_NUM_27     //I2SO(6)
#define LCD_CS					    GPIO_NUM_25

#define TOUCH_CS				    GPIO_NUM_26
#define BEEPER					    I2SO(7)

#define IIC_SCL                     GPIO_NUM_4
#define IIC_SDA                     GPIO_NUM_0

// #define BTN_EN1					GPIO_NUM_34
// #define BTN_EN2					GPIO_NUM_35
// #define BTN_ENC					GPIO_NUM_36

//sd card spi
#define GRBL_SPI_SCK 			    GPIO_NUM_14
#define GRBL_SPI_MISO 			    GPIO_NUM_13
#define GRBL_SPI_MOSI 			    GPIO_NUM_12
#define GRBL_SPI_SS 			    GPIO_NUM_15
#define GRBL_SPI_FREQ 			    4000000
#define SDCARD_DET_PIN 			    GPIO_NUM_39

//#define TMC_X_UART			    GPIO_NUM_18
//#define TMC_Y_UART			    GPIO_NUM_23
//#define TMC_Z_UART			    GPIO_NUM_27

// === Default settings
#define DEFAULT_STEP_PULSE_MICROSECONDS I2S_OUT_USEC_PER_PULSE

// The default value in config.h is wrong for this controller
//#ifdef INVERT_CONTROL_PIN_MASK
//    #undef INVERT_CONTROL_PIN_MASK
//#endif

//#define INVERT_CONTROL_PIN_MASK B1110


#define DEFAULT_STEP_PULSE_MICROSECONDS     3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME      255 //  255 = Keep steppers on

#define DEFAULT_STEPPING_INVERT_MASK    	0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK   	0 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE        	0 // boolean
#define DEFAULT_INVERT_LIMIT_PINS       	1 // boolean
#define DEFAULT_INVERT_PROBE_PIN        	0 // boolean

#define DEFAULT_STATUS_REPORT_MASK 			1

#define DEFAULT_JUNCTION_DEVIATION  		0.01 // mm
#define DEFAULT_ARC_TOLERANCE       		0.002 // mm
#define DEFAULT_REPORT_INCHES       		0 // false

#define DEFAULT_SOFT_LIMIT_ENABLE 			0 // false
#define DEFAULT_HARD_LIMIT_ENABLE 			0  // false

#define DEFAULT_HOMING_ENABLE           	1  // false
#define DEFAULT_HOMING_DIR_MASK         	3 // move positive dir Z,negative X,Y
#define DEFAULT_HOMING_FEED_RATE        	100.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE        	200.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY   	250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF          	2.0 // mm

#ifdef USE_SPINDLE_RELAY
    #define DEFAULT_SPINDLE_RPM_MAX 1.0 // must be 1 so PWM duty is alway 100% to prevent relay damage
#else
    #define DEFAULT_SPINDLE_RPM_MAX 1000.0 // can be change to your spindle max
#endif

#define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm

#define DEFAULT_LASER_MODE 1 // false

#define DEFAULT_X_STEPS_PER_MM 80.0
#define DEFAULT_Y_STEPS_PER_MM 80.0
#define DEFAULT_Z_STEPS_PER_MM 80.0

#define DEFAULT_X_MAX_RATE 3000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 3000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 3000.0 // mm/min

#define DEFAULT_X_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Y_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 100.0 // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL 500.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 500.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL 80.0 // mm NOTE: Must be a positive value.

/*
  Grbl.cpp - Initialization and main loop for Grbl
  Part of Grbl
  Copyright (c) 2014-2016 Sungeun K. Jeon for Gnea Research LLC

	2018 -	Bart Dring This file was modifed for use on the ESP32
					CPU. Do not use this with Grbl for atMega328P

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Grbl.h"
#include <WiFi.h>

#include "mks/MKS_TS35.h"
#include "mks/MKS_LVGL.h"
#include "mks/MKS_draw_ready.h"
#include "mks/MKS_ctrl.h"
#include "mks/MKS_SDCard.h"

void grbl_init() {

    pinMode(LCD_EN, OUTPUT);
    LCD_BLK_ON;
    
#ifdef USE_I2S_OUT

    pinMode(I2S_OUT_BCK, OUTPUT);
    pinMode(I2S_OUT_WS, OUTPUT);
    pinMode(I2S_OUT_DATA, OUTPUT);

    gpio_set_level(I2S_OUT_BCK, 0);
    gpio_set_level(I2S_OUT_WS, 0);
    gpio_set_level(I2S_OUT_DATA, 0);
    // digitalWrite(I2S_OUT_BCK, HIGH);
    // digitalWrite(I2S_OUT_WS, HIGH);
    // digitalWrite(I2S_OUT_DATA, HIGH);

    i2s_out_init();  // The I2S out must be initialized before it can access the expanded GPIO port
#endif
    WiFi.persistent(false);
    WiFi.disconnect(true);
    WiFi.enableSTA(false);
    WiFi.enableAP(false);
    WiFi.mode(WIFI_OFF);
    client_init();  // Setup serial baud rate and interrupts
    display_init();
    // grbl_msg_sendf(CLIENT_SERIAL, MsgLevel::Info, "Grbl_ESP32 Ver %s Date %s", GRBL_VERSION, GRBL_VERSION_BUILD);  // print grbl_esp32 verion info
    // grbl_msg_sendf(CLIENT_SERIAL, MsgLevel::Info, "Compiled with ESP32 SDK:%s", ESP.getSdkVersion());              // print the SDK version
    // grbl_msg_sendf(CLIENT_SERIAL, MsgLevel::Info, "MKS DLC32 Version:s, Buile %s", GRBL_VERSION, GRBL_VERSION_BUILD);  // print grbl_esp32 verion info
    // grbl_msg_sendf(CLIENT_SERIAL, MsgLevel::Info, "Compiled with ESP32 SDK:%s", ESP.getSdkVersion());              // print the SDK version

// show the map name at startup
#ifdef MACHINE_NAME
    // report_machine_type(CLIENT_SERIAL);
#endif
    settings_init();  // Load Grbl settings from non-volatile storage
    stepper_init();   // Configure stepper pins and interrupt timers
    system_ini();     // Configure pinout pins and pin-change interrupt (Renamed due to conflict with esp32 files)
    init_motors();
    memset(sys_position, 0, sizeof(sys_position));  // Clear machine position.
    machine_init();                                 // weak definition in Grbl.cpp does nothing
    // Initialize system state.
#ifdef FORCE_INITIALIZATION_ALARM
    // Force Grbl into an ALARM state upon a power-cycle or hard reset.
    sys.state = State::Alarm;
#else
    sys.state = State::Idle;
#endif
    // Check for power-up and set system alarm if homing is enabled to force homing cycle
    // by setting Grbl's alarm state. Alarm locks out all g-code commands, including the
    // startup scripts, but allows access to settings and internal commands. Only a homing
    // cycle '$H' or kill alarm locks '$X' will disable the alarm.
    // NOTE: The startup script will run after successful completion of the homing cycle, but
    // not after disabling the alarm locks. Prevents motion startup blocks from crashing into
    // things uncontrollably. Very bad.
#ifdef HOMING_INIT_LOCK
    if (homing_enable->get()) {
        sys.state = State::Alarm;
    }
#endif
    Spindles::Spindle::select();
#ifdef ENABLE_WIFI
    // WebUI::wifi_config.begin();
#endif
#ifdef ENABLE_BLUETOOTH
    WebUI::bt_config.begin();
#endif
    WebUI::inputBuffer.begin();
}

static void reset_variables() {
    // Reset system variables.
    static bool lcd_init_status = false;
    State prior_state = sys.state;
    memset(&sys, 0, sizeof(system_t));  // Clear system struct variable.
    sys.state             = prior_state;
    sys.f_override        = FeedOverride::Default;              // Set to 100%
    sys.r_override        = RapidOverride::Default;             // Set to 100%
    sys.spindle_speed_ovr = SpindleSpeedOverride::Default;      // Set to 100%
    memset(sys_probe_position, 0, sizeof(sys_probe_position));  // Clear probe position.

    sys_probe_state                      = Probe::Off;
    sys_rt_exec_state.value              = 0;
    sys_rt_exec_accessory_override.value = 0;
    sys_rt_exec_alarm                    = ExecAlarm::None;
    cycle_stop                           = false;
    sys_rt_f_override                    = FeedOverride::Default;
    sys_rt_r_override                    = RapidOverride::Default;
    sys_rt_s_override                    = SpindleSpeedOverride::Default;

    // Reset Grbl primary systems.
    client_reset_read_buffer(CLIENT_ALL);
    gc_init();  // Set g-code parser to default state
    spindle->stop();
    coolant_init();
    limits_init();
    probe_init();
    plan_reset();  // Clear block buffer and planner variables
    st_reset();    // Clear stepper subsystem variables
    // Sync cleared gcode and planner positions to current system position.
    plan_sync_position();
    gc_sync_position();
    report_init_message(CLIENT_ALL);

    // used to keep track of a jog command sent to mc_line() so we can cancel it.
    // this is needed if a jogCancel comes along after we have already parsed a jog and it is in-flight.
    sys_pl_data_inflight = NULL;

     /*LCD---GUI*/
    if(!lcd_init_status) {
        lcd_init_status = true;

        /* SD cfg updata */
        mks_updata_init();

        /* LCD */
        tft_TS35_init();
        disp_task_init();
        mks_grbl_parg_init();
        
#if defined(USE_BL_TOUCH)
        BLTOUCH_push_up();
        delay_ms(100);
        BLTOUCH_push_down();
#endif
    }
    mks_motor_unclock();
    spindle_check_init();
    rb_init(&rb_sd);
}

void run_once() {
    reset_variables();
    // Start Grbl main loop. Processes program inputs and executes them.
    // This can exit on a system abort condition, in which case run_once()
    // is re-executed by an enclosing loop.
    protocol_main_loop();
}

void __attribute__((weak)) machine_init() {}

void __attribute__((weak)) display_init() {}

void __attribute__((weak)) user_m30() {}

void __attribute__((weak)) user_tool_change(uint8_t new_tool) {}

/*
  setup() and loop() in the Arduino .ino implements this control flow:

  void main() {
     init();          // setup()
     while (1) {      // loop()
         run_once();
     }
  }
*/

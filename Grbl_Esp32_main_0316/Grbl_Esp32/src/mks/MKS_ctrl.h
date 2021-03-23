#ifndef __MKS_CTRL_H
#define __MKS_CTRL_H

// #include "GCode.h"
// #include "Report.h"
#include "../grbl.h"


void bltouch_init(void);
void mks_motor_move(void);
void bltouch_duty(uint32_t duty);
#endif

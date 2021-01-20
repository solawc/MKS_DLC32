#include "MKS_LVGL.h"


/* LVGL TIMER DEF */
hw_timer_t *timer = NULL;
#define ESP_LVGL_TIMER                  0
#define ESP_LVGL_TIMER_FRQE             240

static lv_disp_buf_t disp_buf;
static lv_color_t bmp_public_buf[14 * LV_HOR_RES_MAX];
/* Function */
void   IRAM_ATTR Timer_ESP_LVGL_TIMER_CallBack();
void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
bool my_indev_touch(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

// 1ms
void ESP_TIM_Init(void) {

    timer = timerBegin(ESP_LVGL_TIMER, ESP_LVGL_TIMER_FRQE, true);          //set time div 80, count_mode_up
    timerAttachInterrupt(timer,Timer_ESP_LVGL_TIMER_CallBack, true );       // function callback
    timerAlarmWrite(timer, 1000, false);                                     // Handle time : 1ms
    timerAlarmEnable(timer);                                                // begin count
}   

void IRAM_ATTR Timer_ESP_LVGL_TIMER_CallBack() {

    // lv_tick_inc(1); // Jump 1ms
    printf("\r\n enter tim handle\n\r");
}

void mks_lvgl_init(void) {

    TS35_init();
    TS35_touch_init();
    printf("TS35 Init succeed\n");

    lv_disp_buf_init(&disp_buf, bmp_public_buf, nullptr, LV_HOR_RES_MAX * 14); // Initialize the display buffer
    printf("lv men init succeed\n");

    /* display driver register */
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);
    printf("lv disp init succeed\n");

    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);  
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_indev_touch;
    lv_indev_drv_register(&indev_drv);
}

void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p) {

    LCD_Color_Fill(area->x1,area->y1,area->x2,area->y2,(uint16_t*)color_p);
    lv_disp_flush_ready(disp);
}

bool my_indev_touch(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {

    // static uint16_t last_x = 0;
    // static uint16_t last_y = 0;

    if((ESP_TS35.TOUCH_Y <10) || (ESP_TS35.TOUCH_Y == 0)) {
        return false;
    }
    data->point.x = ESP_TS35.TOUCH_X;
    data->point.y = ESP_TS35.TOUCH_Y;
    return false;
}   


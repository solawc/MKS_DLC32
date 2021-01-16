#include "MKS_LVGL.h"


/* LVGL TIMER DEF */
hw_timer_t *timer = NULL;
#define ESP_LVGL_TIMER                  0
#define ESP_LVGL_TIMER_FRQE             240

static lv_disp_buf_t disp_buf;
uint8_t bmp_public_buf[14 * 1024];
/* Function */
void IRAM_ATTR Timer_ESP_LVGL_TIMER_CallBack(void);
static void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
static bool my_indev_touch(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

// 1ms
void ESP_TIM_Init(void) {

    timer = timerBegin(ESP_LVGL_TIMER, ESP_LVGL_TIMER_FRQE, true);          //set time div 80, count_mode_up
    timerAttachInterrupt(timer,Timer_ESP_LVGL_TIMER_CallBack, true );       // function callback
    timerAlarmWrite(timer, 1000, false);                                     // Handle time : 1ms
    timerAlarmEnable(timer);                                                // begin count
}   

void IRAM_ATTR Timer_ESP_LVGL_TIMER_CallBack(void) {

    // lv_tick_inc(1); // Jump 1ms
    printf("\r\n enter tim handle\n\r");
}

void mks_lvgl_init(void) {

    TS32_Init();
    ts35_touch_init();

    // lv_disp_buf_init(&disp_buf, bmp_public_buf, nullptr, LV_HOR_RES_MAX * 14); // Initialize the display buffer

    // /* display driver register */
    // lv_disp_drv_t disp_drv;
    // lv_disp_drv_init(&disp_drv);
    // disp_drv.flush_cb = my_disp_flush;
    // disp_drv.buffer = &disp_buf;
    // lv_disp_drv_register(&disp_drv);

    // lv_indev_drv_t indev_drv;
    // lv_indev_drv_init(&indev_drv);  
    // indev_drv.type = LV_INDEV_TYPE_POINTER;
    // indev_drv.read_cb = my_indev_touch;
    // lv_indev_drv_register(&indev_drv);
}


static void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p) {

    // uint16_t width = area->x2 - area->x1 + 1,
    //          height = area->y2 - area->y1 + 1;
    // TFT_DrawPoint(area->x1,area->y1,&color_p);

    TFT_Fill(area->x1,area->y1,area->x2,area->y2, (uint16_t)(color_p->full));
    lv_disp_flush_ready(disp);
}

static bool my_indev_touch(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {

    // static uint16_t last_x = 0;
    // static uint16_t last_y = 0;

    if((ESP_TS35.TOUCH_Y <10) || (ESP_TS35.TOUCH_Y == 0)) {
        return false;
    }
    data->point.x = ESP_TS35.TOUCH_X;
    data->point.y = ESP_TS35.TOUCH_Y;
    return false;
}   
















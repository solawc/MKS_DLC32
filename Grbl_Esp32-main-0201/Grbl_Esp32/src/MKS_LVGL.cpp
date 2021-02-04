#include "MKS_LVGL.h"
#include "TFT_eSPI.h"
// #include "lv_examples/lv_apps/demo/demo.h"
// #include "lv_examples/lv_tests/lv_test_theme/lv_test_theme_1.h"

#define LV_BUF_SIZE             10 * LV_HOR_RES_MAX

static lv_disp_buf_t    disp_buf;
static lv_color_t       bmp_public_buf[LV_BUF_SIZE];

/* Function */
void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
bool my_indev_touch(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

// 1ms
void mks_lvgl_init(void) {

    lv_init();
    lv_disp_buf_init(&disp_buf, bmp_public_buf, nullptr, LV_BUF_SIZE); // Initialize the display buffer

    /* display driver register */
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);  
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_indev_touch;
    lv_indev_drv_register(&indev_drv);
}

void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p) {

    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors(&color_p->full, w * h, true);
    tft.endWrite();
    lv_disp_flush_ready(disp);
}

bool my_indev_touch(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {

    uint16_t touchX=0, touchY=0;
    static uint16_t last_x = 0;
    static uint16_t last_y = 0;
    boolean touched = tft.getTouch(&touchY, &touchX);

    if(touchX > 480) {
        touchX = 480;
    }
    touchX = 480 - touchX;
    touchY = 320 - touchY;
    if( touched != false ) {
        Serial.print("touchX:");
        Serial.print(touchX);
        Serial.print("\n");

        Serial.print("touchY:");
        Serial.print(touchY);
        Serial.print("\n");

        last_x = touchX;
        last_y = touchY;
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_PR;
    }
    else {
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_REL;
    }
    
    return false;
}   

#if USE_LV_LOG != 0
/* Serial debugging */
void my_print(lv_log_level_t level, const char * file, uint32_t line, const char * dsc)
{
    Serial.printf("%s@%d->%s\r\n", file, line, dsc);
    Serial.flush();
}
#endif

lv_obj_t *lable1;   
lv_obj_t *lable2;

void lvgl_test(void) {
    // lv_obj_t *scr = lv_scr_act();   //获取当前活跃的屏幕对象
    // lable1 = lv_label_create(scr, NULL); // 创建标签
    // lv_label_set_long_mode(lable1, LV_LABEL_LONG_BREAK); //设置长文本模式
    // lv_obj_set_width(lable1, 200);
    // lv_obj_set_height(lable1,200);
    // lv_obj_set_pos(lable1, 50, 50);
    // lv_label_set_recolor(lable1, true);
    // lv_label_set_text(lable1, "#ff0000 Setting#");
    // lv_label_set_align(lable1, LV_LABEL_ALIGN_CENTER); //中间对齐
    // lv_test_theme_1(lv_theme_night_init(210, NULL));
}   

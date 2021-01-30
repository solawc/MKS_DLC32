#include "MKS_LVGL.h"

#define LV_BUF_SIZE             10 * LV_HOR_RES_MAX
lv_disp_buf_t  disp_buf;
lv_color_t  bmp_public_buf[LV_BUF_SIZE];

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

lv_obj_t *lable1;   
lv_obj_t *lable2;


// void event_hander(lv_obj_t *obj, lv_event_t event) {

//     // 按键释放
//     if(event == LV_EVENT_RELEASED) {
        
//         lv_label_set_long_mode(lable1, LV_LABEL_LONG_EXPAND);

//     }
// }


void lvgl_test(void) {
    lv_obj_t *scr = lv_scr_act();   //获取当前活跃的屏幕对象
    lable1 = lv_label_create(scr, NULL); // 创建标签
    lv_label_set_long_mode(lable1, LV_LABEL_LONG_BREAK); //设置长文本模式
    lv_obj_set_width(lable1, 200);
    lv_obj_set_height(lable1,200);
    lv_obj_set_pos(lable1, 50, 50);
    lv_label_set_recolor(lable1, true);
    lv_label_set_text(lable1, "#ff0000 Setting#");
    lv_label_set_align(lable1, LV_LABEL_ALIGN_CENTER); //中间对齐
}   

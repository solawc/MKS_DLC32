#ifndef __MKS_draw_print_h
#define __MKS_draw_print_h

#include "mks_draw_lvgl.h"


typedef enum {

    print_src1_x = 10,
    print_src1_y = 10,
    print_src1_size_x = 460,
    print_src1_size_y = 90, 

    print_src2_x = 10,
    print_src2_y = 110,
    print_src2_size_x = 460,
    print_src2_size_y = 200, 

    print_popup_x = 80,
    print_popup_y = 50,
    print_popup_size_x = 350,
    print_popup_size_y = 200,    

    print_popup_sure_btn_x = 120,
    print_popup_sure_btn_y = 120,
    print_popup_sure_btn_size_x = 100,
    print_popup_sure_btn_size_y = 40,

    print_popup_cancle_btn_x = 10,
    print_popup_cancle_btn_y = 130,
    print_popup_cancle_btn_size_x = 100,
    print_popup_cancle_btn_size_y = 40,

    print_pwr_popup_x = 80,
    print_pwr_popup_y = 50,
    print_pwr_popup_size_x = 350,
    print_pwr_popup_size_y = 200,    

    print_pwr_popup_add_btn_x = 30,
    print_pwr_popup_add_btn_y = 60,
    print_pwr_popup_add_btn_size_x = 100,
    print_pwr_popup_add_btn_size_y = 40,

    print_bar_pic_x = 10,
    print_bar_pic_y = 10,

    print_first_data_label_x = 10,
    print_first_data_label_y = 100,

    print_src1_first_pic_x = 100,
    print_src1_first_pic_y = 20,

    print_src2_first_pic_x = 70,
    print_src2_first_pic_y = 95,

}PRINT_XY_t;



typedef enum {
    PWR_1_PERSEN,
    PWR_10_PERSEN,
}PWR_LEN_t;

typedef struct {

    PWR_LEN_t pwr_len;

}PWR_CTRL_t;

typedef enum {
    SPEED_1_PERSEN,
    SPEED_10_PERSEN,
}SPEED_LEN_t;

typedef struct {

    SPEED_LEN_t pwr_len;

}SPEED_CTRL_t;




void mks_clear_print(void);
void mks_draw_print(void);
void mks_draw_print_popup(const char* text);
void mks_del_obj(lv_obj_t *obj);
void mks_draw_finsh_pupop(void);
void mks_print_bar_updata(void);
void mks_draw_operation(void);
void mks_print_pwr_set(void);
void mks_print_speed_set(void);
void mks_print_data_updata(void);
#endif // !MKS_draw_print_h

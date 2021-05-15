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

    print_src1_first_pic_x = 90,
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
    SPEED_LEN_t speed_len;
}SPEED_CTRL_t;


typedef struct {

    /* 底图显示 */
    lv_obj_t* print_scr1;           //上面部分
    lv_obj_t* print_scr2;           //下面部分
    
    lv_obj_t* print_stop_popup;
    lv_obj_t* print_finsh_popup;
    lv_obj_t *print_pwr_speed_src;

    /* btn */
    lv_obj_t *print_btn_1_mm;
    lv_obj_t *print_btn_10_mm;

    /* imgbtn */
    lv_obj_t* print_imgbtn_suspend;
    lv_obj_t* print_imgbtn_stop;
    lv_obj_t* print_imgbtn_pwr;
    lv_obj_t* print_imgbtn_speed;

    lv_obj_t *print_sp_imgbtn_add;
    lv_obj_t *print_sp_imgbtn_dec;
    lv_obj_t *print_sp_btn_sure;

    /* bar */
    lv_obj_t* print_bar_print;  //打印进度条
    lv_obj_t* print_bar_print_percen;  //打印进度

    //样式
    lv_style_t printf_src_bg;   
    lv_style_t printf_popup_style;
    lv_style_t print_popup_btn_style;    // 对话框按键样式
    lv_style_t print_mm_btn1_style;
    lv_style_t print_mm_btn2_style;
    lv_style_t print_bar_bg_style;
    lv_style_t print_bar_indic_style;

    /* Label*/
    lv_obj_t* print_Label_power;
    lv_obj_t* print_Label_caveSpeed;

    lv_obj_t* print_Label_p_suspend;
    lv_obj_t* print_Label_p_stop;
    lv_obj_t* print_Label_p_power;
    lv_obj_t* print_Label_p_caveSpeed;

    lv_obj_t* print_Label_x_pos;
    lv_obj_t* print_Label_y_pos;
    lv_obj_t* print_Label_z_pos;
    lv_obj_t* print_Label_popup;
    lv_obj_t* print_Label_popup_sure;
    lv_obj_t* print_Label_popup_cancel;

    lv_obj_t *print_label_1_mm;
    lv_obj_t *print_label_10_mm;

    /* icon */
    lv_obj_t* print_icon_X;
    lv_obj_t* print_icon_Y;
    lv_obj_t* print_icon_Z;
    lv_obj_t* print_icon_PWR;
    lv_obj_t* print_icon_SPEED;
    
}MKS_PRINT_PAGE_t;
extern MKS_PRINT_PAGE_t print_src;

typedef struct {

    char print_xpos_str[10];
    char print_ypos_str[10];
    char print_zpos_str[10];
    char print_pwr_str[10];
    char print_speed_str[10];
    
    float x_pos = 0;
    float y_pos = 0;
    float z_pos = 0;

    float last_x_pos = 0;
    float last_y_pos = 0;
    float last_z_pos = 0;

}MKS_PRINT_DATA_UPDATA_t;



extern String ddxd;

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
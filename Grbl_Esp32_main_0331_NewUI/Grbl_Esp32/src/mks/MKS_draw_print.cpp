#include "MKS_draw_print.h"


PWR_CTRL_t mks_pwr_ctrl;
SPEED_CTRL_t mks_speed_ctrl;
/* scr */
static lv_obj_t* scr;
static lv_obj_t* print_scr1;
static lv_obj_t* print_scr2;


static lv_obj_t* stop_popup;
static lv_obj_t* scr_op;
static lv_obj_t* finsh_popup;

/* style */
static lv_style_t btn_style;
static lv_style_t print_src_style;

static lv_style_t popup_style;

/* bar */
lv_obj_t* bar_print;  //打印进度条

/* btn */
static lv_obj_t* btn_popup_cancle;
static lv_obj_t* btn_popup_sure;


// static lv_obj_t* btn_finsh_popup_cancle;
static lv_obj_t* btn_finsh_popup_sure;

static lv_obj_t* imgbtn_suspend;
static lv_obj_t* imgbtn_stop;
static lv_obj_t* imgbtn_pwr;
static lv_obj_t* imgbtn_speed;
static lv_obj_t* imgbtn_popup_op;
static lv_obj_t* imgbtn_op_back;

/* imgbtn */
static lv_obj_t* imgbtn_power_add;
static lv_obj_t* imgbtn_power_dec;
static lv_obj_t* imgbtn_cave_speed_add;
static lv_obj_t* imgbtn_cave_speed_dec;
static lv_obj_t* imgbtn_move_speed_add;
static lv_obj_t* imgbtn_move_speed_dec;


/* label */
static lv_obj_t* Label_suspend;
static lv_obj_t* Label_stop;
static lv_obj_t* Label_power;
static lv_obj_t* Label_caveSpeed;

// static lv_obj_t* label_operation;
// static lv_obj_t* Label_file_name;
static lv_obj_t* Label_moveSpeed;
static lv_obj_t* Label_x_pos;
static lv_obj_t* Label_y_pos;
static lv_obj_t* Label_print_persen;
static lv_obj_t* Label_popup_cancel;
static lv_obj_t* Label_popup_sure;
static lv_obj_t* Label_popup;
static lv_obj_t* Label_op_back;

// LV_IMG_DECLARE(mAdd);  //先申明此图片
// LV_IMG_DECLARE(mDec);  //先申明此图片
// LV_IMG_DECLARE(back);  //先申明此图片

LV_IMG_DECLARE(M_Pause);  // 暂停
LV_IMG_DECLARE(M_start);  // 开始
LV_IMG_DECLARE(M_Stop);  // 停止
LV_IMG_DECLARE(M_PWRr);  // 功率
LV_IMG_DECLARE(M_SPEED);  // 速度
LV_IMG_DECLARE(back);  // 速度

LV_IMG_DECLARE(add);  // 加
LV_IMG_DECLARE(confirm);  // 确认
LV_IMG_DECLARE(reduce);  // 减

static void event_handler_suspend(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        if(mks_grbl.run_status == GRBL_RUN) {
            // mks_grbl.run_status = GRBL_PAUSE;
            sys_rt_exec_accessory_override.bit.spindleOvrStop = false;
            lv_imgbtn_set_src(imgbtn_suspend, LV_BTN_STATE_PR, &M_Pause);
            lv_imgbtn_set_src(imgbtn_suspend, LV_BTN_STATE_REL, &M_Pause);
            // lv_label_set_text(Label_suspend, "Run");
        } else if(mks_grbl.run_status == GRBL_PAUSE) {
            mks_grbl.run_status = GRBL_RUN;
            lv_imgbtn_set_src(imgbtn_suspend, LV_BTN_STATE_PR, &M_start);
            lv_imgbtn_set_src(imgbtn_suspend, LV_BTN_STATE_REL, &M_start);
            // lv_label_set_text(Label_suspend, "Pause");
        }
    }
}

static void event_handler_stop(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        mks_draw_print_popup("Do you want to stop print?");
    }
}

static void event_handler_pwr_set(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        mks_print_pwr_set();
    }
}

static void event_handler_speed_set(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        mks_print_speed_set();
    }
}



static void event_handler_op(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        mks_clear_print();
        mks_draw_operation();
    }
}


static void event_handler_op_back(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        mks_del_obj(scr_op);
    }
}


void mks_draw_print(void) {
	
    char power_str[20];
    char x_pos_str[30];
    char y_pos_str[30];
    char cave_s_str[50];
    char move_s_str[50];

    mks_pwr_ctrl.pwr_len = PWR_1_PERSEN;
    mks_speed_ctrl.pwr_len = SPEED_1_PERSEN;

    print_scr1 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(print_scr1, print_src1_size_x, print_src1_size_y);
    lv_obj_set_pos(print_scr1, print_src1_x, print_src1_y);

    print_scr2 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(print_scr2, print_src2_size_x, print_src2_size_y);
    lv_obj_set_pos(print_scr2, print_src2_x, print_src2_y);

    lv_style_copy(&print_src_style, &lv_style_scr);
	print_src_style.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    print_src_style.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    print_src_style.text.color = LV_COLOR_WHITE;
    print_src_style.body.radius = 17;
	lv_obj_set_style(print_scr1, &print_src_style);
    lv_obj_set_style(print_scr2, &print_src_style);

    imgbtn_suspend = lv_imgbtn_creat_mks(print_scr1, 
                                         imgbtn_suspend, 
                                         &M_Pause, 
                                         &M_Pause, 
                                         LV_ALIGN_IN_LEFT_MID, 
                                         print_src1_first_pic_x,
                                         print_src1_first_pic_y,
                                         event_handler_suspend);

    imgbtn_stop = lv_imgbtn_creat_mks(print_scr1, 
                                     imgbtn_stop, 
                                     &M_Stop, 
                                     &M_Stop, 
                                     LV_ALIGN_IN_LEFT_MID, 
                                     print_src1_first_pic_x + 80, 
                                     print_src1_first_pic_y, 
                                     event_handler_stop);

    imgbtn_pwr = lv_imgbtn_creat_mks(print_scr1, 
                                     imgbtn_pwr, 
                                     &M_PWRr,
                                     &M_PWRr, 
                                     LV_ALIGN_IN_LEFT_MID, 
                                     print_src1_first_pic_x + 160, 
                                     print_src1_first_pic_y, 
                                     event_handler_pwr_set);
    
    imgbtn_speed = lv_imgbtn_creat_mks(print_scr1, 
                                        imgbtn_speed, 
                                        &M_SPEED, 
                                        &M_SPEED, 
                                        LV_ALIGN_IN_LEFT_MID, 
                                        print_src1_first_pic_x + 240, 
                                        print_src1_first_pic_y, 
                                        event_handler_speed_set);

    bar_print = mks_lv_bar_set(print_scr2, bar_print, 440, 30, print_bar_pic_x, print_bar_pic_y, 0);

    sprintf(power_str, "Power: %d", mks_grbl.power_persen);
    Label_power = mks_lvgl_long_sroll_label_with_wight_set_center(print_scr2, Label_power, print_first_data_label_x, print_first_data_label_y, power_str, 200);

    sprintf(cave_s_str, "Cave Speed: %d", mks_grbl.cave_speed);
    Label_caveSpeed = mks_lvgl_long_sroll_label_with_wight_set_center(print_scr2, Label_caveSpeed, print_first_data_label_x, print_first_data_label_y+30, cave_s_str, 200);

    sprintf(move_s_str, "Move Speed: %d", mks_grbl.move_speed);
    Label_moveSpeed = mks_lvgl_long_sroll_label_with_wight_set_center(print_scr2, Label_moveSpeed, print_first_data_label_x, print_first_data_label_y+60, move_s_str, 200);

    sprintf(x_pos_str, "X POS: %d", mks_grbl.X_Pos);
    Label_x_pos = mks_lvgl_long_sroll_label_with_wight_set_center(print_scr2, Label_x_pos, print_first_data_label_x+200, print_first_data_label_y, x_pos_str, 200);

    sprintf(y_pos_str, "Y POS: %d", mks_grbl.Y_Pos);
    Label_y_pos = mks_lvgl_long_sroll_label_with_wight_set_center(print_scr2, Label_y_pos, print_first_data_label_x+200, print_first_data_label_y+30, y_pos_str, 200);
}

static void event_btn_cancle(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(stop_popup);
    }
}

static void event_btn_sure(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        closeFile();
        spindle->stop();
        mks_grbl.run_status = GRBL_RESTARTING;
        // lv_obj_del(stop_popup);
        mks_clear_print();
        mks_ui_page.mks_ui_page = MKS_UI_Ready;
        mks_ui_page.wait_count = 1;
        mks_draw_ready();
    }
}

static void event_btn_printdon(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(finsh_popup);
        mks_grbl.run_status = GRBL_RESTARTING; 
        mks_clear_print();
        mks_ui_page.mks_ui_page = MKS_UI_Ready;
        mks_ui_page.wait_count = 1;
        mks_draw_ready();
    }
}

void mks_draw_print_popup(const char* text) {

    stop_popup = lv_obj_create(mks_src, NULL);
    lv_obj_set_size(stop_popup, print_popup_size_x, print_popup_size_y);
    lv_obj_set_pos(stop_popup, print_popup_x, print_popup_y);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5);
    popup_style.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5);
    popup_style.text.color = LV_COLOR_BLACK;
    popup_style.body.radius = 17;
    lv_obj_set_style(stop_popup, &popup_style);

    lv_style_copy(&btn_style, &lv_style_scr);
    btn_style.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    btn_style.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_style.text.color = LV_COLOR_WHITE;
    btn_style.body.radius = 10; 

    btn_popup_sure = mks_lv_btn_set(stop_popup, btn_popup_sure, 100,40,10,130,event_btn_sure);
	lv_btn_set_style(btn_popup_sure, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(btn_popup_sure,LV_BTN_STYLE_PR,&btn_style);
	mks_lvgl_long_sroll_label_with_wight_set_center(btn_popup_sure, Label_popup_sure, 0, 0, "Yes",40);

	btn_popup_cancle = mks_lv_btn_set(stop_popup, btn_popup_cancle, 100,40,240,130,event_btn_cancle);
	lv_btn_set_style(btn_popup_cancle, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(btn_popup_cancle,LV_BTN_STYLE_PR,&btn_style);
	mks_lvgl_long_sroll_label_with_wight_set_center(btn_popup_cancle, Label_popup_sure, 0, 0, "Cancle",40);

    mks_lvgl_long_sroll_label_with_wight_set(stop_popup, Label_popup, 100, 80, text, 150);
}

void mks_draw_finsh_pupop(void) { 

    finsh_popup = lv_obj_create(scr, NULL);
    lv_obj_set_size(finsh_popup, 350, 200);
    lv_obj_set_pos(finsh_popup, 80, 50);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5);
    popup_style.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5);
    popup_style.text.color = LV_COLOR_WHITE;
    popup_style.body.radius = 17;
    lv_obj_set_style(finsh_popup, &popup_style);

    lv_style_copy(&btn_style, &lv_style_scr);
    btn_style.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    btn_style.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_style.text.color = LV_COLOR_WHITE;
    btn_style.body.radius = 10; 

    btn_finsh_popup_sure = lv_btn_create(finsh_popup, NULL);
    lv_obj_set_size(btn_finsh_popup_sure,   100, 50);
    lv_obj_set_pos(btn_finsh_popup_sure,    120, 130);
    lv_obj_set_event_cb(btn_finsh_popup_sure, event_btn_printdon);
    mks_lvgl_label_set(btn_finsh_popup_sure, Label_popup_sure, 80, 10, "Yes");

    lv_btn_set_style(btn_finsh_popup_sure, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(btn_finsh_popup_sure,LV_BTN_STYLE_PR,&btn_style);

    mks_lvgl_long_sroll_label_with_wight_set(finsh_popup, Label_popup, 100, 80, "File is print done!", 150);
}

void mks_print_bar_updata(void) {

    bar_print = mks_lv_bar_updata(bar_print, (uint16_t)sd_report_perc_complete());
}



lv_obj_t *pwr_src;
lv_obj_t *pwr_1_mm;
lv_obj_t *pwr_10_mm;
lv_obj_t *pwr_label_1_mm;
lv_obj_t *pwr_label_10_mm;
lv_obj_t *pwr_imgbtn_add;
lv_obj_t *pwr_imgbtn_dec;
lv_obj_t *pwr_btn_sure;

static void event_pwr_setting_add(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        
        if(mks_pwr_ctrl.pwr_len == PWR_1_PERSEN) {
            sys_rt_s_override += SpindleSpeedOverride::FineIncrement;
            if (sys_rt_s_override > SpindleSpeedOverride::Max) {
                sys_rt_s_override = SpindleSpeedOverride::Max;
            }
        }else if(mks_pwr_ctrl.pwr_len == PWR_10_PERSEN) {
            sys_rt_s_override += SpindleSpeedOverride::CoarseIncrement;
            if (sys_rt_s_override > SpindleSpeedOverride::Max) {
                sys_rt_s_override = SpindleSpeedOverride::Max;
            }
        }
    }
}

static void event_pwr_setting_dec(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        
        if(mks_pwr_ctrl.pwr_len == PWR_1_PERSEN) {
            sys_rt_s_override -= SpindleSpeedOverride::FineIncrement;
        if (sys_rt_s_override < SpindleSpeedOverride::Min) {
            sys_rt_s_override = SpindleSpeedOverride::Min;
        }
        }else if(mks_pwr_ctrl.pwr_len == PWR_10_PERSEN) {
            sys_rt_s_override -= SpindleSpeedOverride::CoarseIncrement;
            if (sys_rt_s_override < SpindleSpeedOverride::Min) {
                sys_rt_s_override = SpindleSpeedOverride::Min;
            }
        }
    }
}

static void event_btn_pwr_1mm(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {

        if(mks_pwr_ctrl.pwr_len == PWR_10_PERSEN) {
            mks_pwr_ctrl.pwr_len = PWR_1_PERSEN;
            lv_label_set_text(pwr_label_1_mm, "#000000 1% #");
            lv_label_set_text(pwr_label_10_mm, "#ffffff 10% #");
        }
    }
}

static void event_btn_pwr_10mm(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {

        if(mks_pwr_ctrl.pwr_len == PWR_1_PERSEN) {
            mks_pwr_ctrl.pwr_len = PWR_10_PERSEN;
            lv_label_set_text(pwr_label_1_mm, "#ffffff 1% #");
            lv_label_set_text(pwr_label_10_mm, "#000000 10% #");
        }
    }
}


static void event_pwr_setting_confirm(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(pwr_src);
    }
}

void mks_print_pwr_set(void) { 

    pwr_src = lv_obj_create(mks_src, NULL);
    lv_obj_set_size(pwr_src, 350, 200);
    lv_obj_set_pos(pwr_src, 75, 50);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5);
    popup_style.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5);
    popup_style.text.color = LV_COLOR_BLACK;
    popup_style.body.radius = 17;
    lv_obj_set_style(pwr_src, &popup_style);

    lv_style_copy(&btn_style, &lv_style_scr);
    btn_style.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    btn_style.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_style.text.color = LV_COLOR_WHITE;
    btn_style.body.radius = 10; 

    pwr_1_mm = mks_lv_btn_set(pwr_src, pwr_1_mm, 100, 40, 40, 50, event_btn_pwr_1mm);
    pwr_10_mm = mks_lv_btn_set(pwr_src, pwr_10_mm, 100, 40, 200, 50, event_btn_pwr_10mm);

	lv_btn_set_style(pwr_1_mm, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(pwr_1_mm,LV_BTN_STYLE_PR,&btn_style);

	lv_btn_set_style(pwr_10_mm, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(pwr_10_mm,LV_BTN_STYLE_PR,&btn_style);

    pwr_label_1_mm = mks_lvgl_long_sroll_label_with_wight_set_center(pwr_1_mm, pwr_label_1_mm, 0, 0, "#000000 1%#", 100);
    pwr_label_10_mm = mks_lvgl_long_sroll_label_with_wight_set_center(pwr_10_mm, pwr_label_10_mm, 0, 0, "#ffffff 10% #", 100);

    pwr_imgbtn_add = lv_imgbtn_creat_mks(pwr_src, pwr_imgbtn_add, &add, &add, LV_ALIGN_IN_LEFT_MID, print_pwr_popup_add_btn_x,print_pwr_popup_add_btn_y, event_pwr_setting_add);
    pwr_imgbtn_dec = lv_imgbtn_creat_mks(pwr_src, pwr_imgbtn_dec, &reduce, &reduce, LV_ALIGN_IN_LEFT_MID, print_pwr_popup_add_btn_x+80,print_pwr_popup_add_btn_y, event_pwr_setting_dec);
    pwr_btn_sure = lv_imgbtn_creat_mks(pwr_src, pwr_imgbtn_dec, &confirm, &confirm, LV_ALIGN_IN_LEFT_MID, print_pwr_popup_add_btn_x+160,print_pwr_popup_add_btn_y, event_pwr_setting_confirm);
}


lv_obj_t *speed_src;
lv_obj_t *speed_1_mm;
lv_obj_t *speed_10_mm;
lv_obj_t *speed_label_1_mm;
lv_obj_t *speed_label_10_mm;
lv_obj_t *speed_imgbtn_add;
lv_obj_t *speed_imgbtn_dec;
lv_obj_t *speed_btn_sure;

static void event_speed_setting_add(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        
        if(mks_pwr_ctrl.pwr_len == PWR_1_PERSEN) {

        }else if(mks_pwr_ctrl.pwr_len == PWR_10_PERSEN) {

        }
    }
}

static void event_speed_setting_dec(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        
        if(mks_pwr_ctrl.pwr_len == PWR_1_PERSEN) {

        }else if(mks_pwr_ctrl.pwr_len == PWR_10_PERSEN) {

        }
    }
}

static void event_speed_setting_confirm(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(speed_src);
    }
}

static void event_btn_speed_1mm(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {

        if(mks_pwr_ctrl.pwr_len == PWR_10_PERSEN) {
            mks_pwr_ctrl.pwr_len = PWR_1_PERSEN;
        }
    }
}

static void event_btn_speed_10mm(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {

        if(mks_pwr_ctrl.pwr_len == PWR_1_PERSEN) {
            mks_pwr_ctrl.pwr_len = PWR_10_PERSEN;
        }
    }
}

void mks_print_speed_set(void) { 

    speed_src = lv_obj_create(mks_src, NULL);
    lv_obj_set_size(pwr_src, 350, 200);
    lv_obj_set_pos(pwr_src, 80, 50);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5);
    popup_style.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5);
    popup_style.text.color = LV_COLOR_BLACK;
    popup_style.body.radius = 17;
    lv_obj_set_style(speed_src, &popup_style);

    lv_style_copy(&btn_style, &lv_style_scr);
    btn_style.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    btn_style.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_style.text.color = LV_COLOR_WHITE;
    btn_style.body.radius = 10; 

    speed_1_mm = mks_lv_btn_set(speed_src, speed_1_mm, 100,40,40,130,event_btn_speed_1mm);
	lv_btn_set_style(speed_1_mm, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(speed_1_mm,LV_BTN_STYLE_PR,&btn_style);

    speed_10_mm = mks_lv_btn_set(speed_src, speed_10_mm, 100,40,200,130,event_btn_speed_10mm);
	lv_btn_set_style(speed_10_mm, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(speed_10_mm,LV_BTN_STYLE_PR,&btn_style);

    speed_label_1_mm = mks_lvgl_long_sroll_label_with_wight_set_center(speed_1_mm, speed_label_1_mm, 0, 0, "#000000 1%#", 100);
    speed_label_10_mm = mks_lvgl_long_sroll_label_with_wight_set_center(speed_10_mm, speed_label_10_mm, 0, 0, "#ffffff 10% #", 100);

    speed_imgbtn_add = lv_imgbtn_creat_mks(speed_src, speed_imgbtn_add, &add, &add, LV_ALIGN_IN_LEFT_MID, print_pwr_popup_add_btn_x,print_pwr_popup_add_btn_y, event_speed_setting_add);
    speed_imgbtn_dec = lv_imgbtn_creat_mks(speed_src, speed_imgbtn_dec, &reduce, &reduce, LV_ALIGN_IN_LEFT_MID, print_pwr_popup_add_btn_x+80,50, event_speed_setting_dec);
    speed_btn_sure = lv_imgbtn_creat_mks(speed_src, speed_imgbtn_dec, &confirm, &confirm, LV_ALIGN_IN_LEFT_MID, print_pwr_popup_add_btn_x+160,50, event_pwr_setting_confirm);
}



void mks_clear_print(void) {
    lv_obj_clean(mks_src);
}

void mks_del_obj(lv_obj_t *obj) { 
    lv_obj_del(obj);
}
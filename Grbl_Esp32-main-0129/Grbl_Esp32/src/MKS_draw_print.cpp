#include "MKS_draw_print.h"

/* scr */
static lv_obj_t* scr;
static lv_obj_t* stop_popup;
static lv_obj_t* scr_op;
static lv_obj_t* finsh_popup;

/* style */
lv_style_t btn_style;
lv_style_t popup_style;

/* bar */
lv_obj_t* bar_print;  //打印进度条

/* btn */
static lv_obj_t* btn_popup_cancle;
static lv_obj_t* btn_popup_sure;


// static lv_obj_t* btn_finsh_popup_cancle;
static lv_obj_t* btn_finsh_popup_sure;

static lv_obj_t* btn_suspend;
static lv_obj_t* btn_stop;
static lv_obj_t* btn_popup_op;
static lv_obj_t* btn_op_back;

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
static lv_obj_t* label_operation;
static lv_obj_t* Label_file_name;
static lv_obj_t* Label_power;
static lv_obj_t* Label_caveSpeed;
static lv_obj_t* Label_moveSpeed;
static lv_obj_t* Label_x_pos;
static lv_obj_t* Label_y_pos;
static lv_obj_t* Label_print_persen;
static lv_obj_t* Label_popup_cancel;
static lv_obj_t* Label_popup_sure;
static lv_obj_t* Label_popup;
static lv_obj_t* Label_op_back;

LV_IMG_DECLARE(mAdd);  //先申明此图片
LV_IMG_DECLARE(mDec);  //先申明此图片
LV_IMG_DECLARE(back);			//先申明此图片

static void event_handler_suspend(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        if(mks_grbl.run_status == GRBL_RUN) {
            mks_grbl.run_status = GRBL_PAUSE;
            sys_rt_exec_accessory_override.bit.spindleOvrStop = false;
            lv_label_set_text(Label_suspend, "#fad509 Run#");
        } else if(mks_grbl.run_status == GRBL_PAUSE) {
            mks_grbl.run_status = GRBL_RUN;
            sys_rt_exec_accessory_override.bit.spindleOvrStop = true;
            lv_label_set_text(Label_suspend, "#fad509 Pause#");
        }
    }
}

static void event_handler_stop(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        mks_draw_print_popup("Do you want to stop print?");
    }
}

static void event_handler_op(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        
    }
}

static void event_handler_op_back(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        mks_del_obj(scr_op);
    }
}



// static void event_handle_power_mAdd(lv_obj_t* obj, lv_event_t event) {
//     char str[20];
//     if (event == LV_EVENT_RELEASED) {
//         if (mks_grbl.power_length == P_1_PERSEN) {
//             mks_grbl.power_persen++;
//             if (mks_grbl.power_persen > 100) {
//                 mks_grbl.power_persen = 100;
//             }
//         } else {
//             mks_grbl.power_persen = mks_grbl.power_persen + 10;
//             if (mks_grbl.power_persen > 100) {
//                 mks_grbl.power_persen = 100;
//             }
//         }
//         mks_power_set(mks_grbl.power_persen);
//         sprintf(str, "M3 S%d\n", mks_grbl.power_persen);
//         MKS_GRBL_CMD_SEND(str);
//     }
// }

// static void event_handle_power_mDec(lv_obj_t* obj, lv_event_t event) {
//     char str[20];
//     if (event == LV_EVENT_RELEASED) { 
//         if (mks_grbl.power_length == P_1_PERSEN) {
//             mks_grbl.power_persen--;
//             if ((mks_grbl.power_persen < 0) || (mks_grbl.power_persen > 100)) {
//                 mks_grbl.power_persen = 0;
//             }
//         } else {
//             mks_grbl.power_persen = mks_grbl.power_persen - 10;
//             if ((mks_grbl.power_persen < 0) || (mks_grbl.power_persen > 100)) {
//                 mks_grbl.power_persen = 0;
//             }
//         }
//         mks_power_set(mks_grbl.power_persen);
//         sprintf(str, "M3 S%d\n", mks_grbl.power_persen);
//         MKS_GRBL_CMD_SEND(str);
//     }
// }

// static void event_handler_cave_speed_mAdd(lv_obj_t* obj, lv_event_t event) {
//     if (event == LV_EVENT_RELEASED) {
//         mks_grbl.cave_speed++;
//         if ((mks_grbl.cave_speed > 100)) {
//             mks_grbl.cave_speed = 100;
//         }
//     }
// }

// static void event_handler_cave_speed_mDec(lv_obj_t* obj, lv_event_t event) {
//     if (event == LV_EVENT_RELEASED) {}
// }

// static void event_handler_move_speed_mAdd(lv_obj_t* obj, lv_event_t event) {
//     if (event == LV_EVENT_RELEASED) {}
// }

// static void event_handler_move_speed_mDec(lv_obj_t* obj, lv_event_t event) {
//     if (event == LV_EVENT_RELEASED) {}
// }

void mks_draw_print(void) {
	
    char power_str[20];
    char x_pos_str[30];
    char y_pos_str[30];
    char cave_s_str[50];
    char move_s_str[50];

    scr = lv_obj_create(NULL, NULL);
    scr = lv_scr_act();

    mks_lv_btn_set(scr, btn_suspend,    144, 50, 10, 260, event_handler_suspend);
    mks_lv_btn_set(scr, btn_stop,       144, 50, 164, 260, event_handler_stop);
    mks_lv_btn_set(scr, btn_popup_op,   144, 50, 318, 260, event_handler_op);
    /*  
        30, 275,
        180, 275
        300, 275
    */
    mks_lvgl_long_sroll_label_set(scr, Label_file_name,         30, 40, file_print_send);

    Label_suspend   = mks_lvgl_label_set_align_center(scr, Label_suspend,     50, 275,     "#fad509 Pause#");
    Label_stop      = mks_lvgl_label_set_align_center(scr, Label_stop,        210, 275,    "#fad509 Stop#");
    label_operation = mks_lvgl_label_set_align_center(scr, label_operation,   350, 275,    "#fad509 Option#");

    // btn_style.body.grad_color = LV_COLOR_MAKE(0x3a,0x2a,0xd9);
    // btn_style.body.main_color = LV_COLOR_MAKE(0x3a,0x2a,0xd9);
    // lv_obj_set_style(Label_suspend ,&btn_style);
    // lv_obj_set_style(Label_stop ,&btn_style);
    // lv_obj_set_style(label_operation ,&btn_style);

    // lv_imgbtn_creat_mks(scr, imgbtn_power_add, &mAdd, &mAdd, LV_ALIGN_CENTER, 100, -50, event_handle_power_mAdd);
    // lv_imgbtn_creat_mks(scr, imgbtn_cave_speed_add, &mAdd, &mAdd, LV_ALIGN_CENTER, 100, 0, event_handler_cave_speed_mAdd);
    // lv_imgbtn_creat_mks(scr, imgbtn_move_speed_add, &mAdd, &mAdd, LV_ALIGN_CENTER, 100, 50, event_handler_move_speed_mAdd);

    // lv_imgbtn_creat_mks(scr, imgbtn_power_dec, &mDec, &mDec, LV_ALIGN_CENTER, 180, -50, event_handle_power_mDec);
    // lv_imgbtn_creat_mks(scr, imgbtn_cave_speed_dec, &mDec, &mDec, LV_ALIGN_CENTER, 180, 0, event_handler_cave_speed_mDec);
    // lv_imgbtn_creat_mks(scr, imgbtn_move_speed_dec, &mDec, &mDec, LV_ALIGN_CENTER, 180, 50, event_handler_move_speed_mDec);

    sprintf(power_str, "Power: %d", mks_grbl.power_persen);
    Label_power = mks_lvgl_label_with_long_set(scr, Label_power, 30, 120, power_str, 200);

    sprintf(cave_s_str, "Cave Speed: %d", mks_grbl.cave_speed);
    Label_caveSpeed = mks_lvgl_label_with_long_set(scr, Label_caveSpeed, 30, 150, cave_s_str, 200);

    sprintf(move_s_str, "Move Speed: %d", mks_grbl.move_speed);
    Label_moveSpeed = mks_lvgl_label_with_long_set(scr, Label_moveSpeed, 30, 180, move_s_str, 200);

    sprintf(x_pos_str, "X POS: %d", mks_grbl.X_Pos);
    Label_x_pos = mks_lvgl_label_with_long_set(scr, Label_x_pos, 30, 210, x_pos_str, 200);

    sprintf(y_pos_str, "Y POS: %d", mks_grbl.Y_Pos);
    Label_y_pos = mks_lvgl_label_with_long_set(scr, Label_y_pos, 160, 210, y_pos_str, 200);

    bar_print = mks_lv_bar_set(scr, bar_print, 456, 40, 0, -80, 0);
}

static void event_btn_cancle(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(stop_popup);
    }
}

static void event_btn_sure(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        closeFile();
        mks_grbl.run_status = GRBL_RESTARTING;
        lv_obj_del(stop_popup);
        mks_clear_print();
        lv_draw_ready();
    }
}

static void event_btn_printdon(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(finsh_popup);
        mks_grbl.run_status = GRBL_RESTARTING; 
        mks_clear_print();
        lv_draw_ready();
    }
}

void mks_draw_print_popup(const char* text) {
    stop_popup = lv_obj_create(scr, NULL);
    lv_obj_set_size(stop_popup, 350, 200);
    lv_obj_set_pos(stop_popup, 80, 50);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_GRAY;
    popup_style.body.grad_color = LV_COLOR_GRAY;
    lv_obj_set_style(stop_popup, &popup_style);

    btn_popup_cancle = lv_btn_create(stop_popup, NULL);
    lv_obj_set_size(btn_popup_cancle, 100, 50);
    lv_obj_set_pos(btn_popup_cancle, 240, 130);
    lv_obj_set_event_cb(btn_popup_cancle, event_btn_cancle);
    mks_lvgl_label_set(stop_popup, Label_popup_cancel, 250, 150, "Cancle");

    btn_popup_sure = lv_btn_create(stop_popup, NULL);
    lv_obj_set_size(btn_popup_sure, 100, 50);
    lv_obj_set_pos(btn_popup_sure, 10, 130);
    lv_obj_set_event_cb(btn_popup_sure, event_btn_sure);
    mks_lvgl_label_set(stop_popup, Label_popup_sure, 20, 150, "Yes");

    mks_lvgl_long_sroll_label_with_wight_set(stop_popup, Label_popup, 100, 80, "Is Caving this File?", 150);
}

void mks_draw_finsh_pupop(void) { 

    finsh_popup = lv_obj_create(scr, NULL);
    lv_obj_set_size(finsh_popup, 350, 200);
    lv_obj_set_pos(finsh_popup, 80, 50);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_GRAY;
    popup_style.body.grad_color = LV_COLOR_GRAY;
    lv_obj_set_style(finsh_popup, &popup_style);

    btn_finsh_popup_sure = lv_btn_create(finsh_popup, NULL);
    lv_obj_set_size(btn_finsh_popup_sure,   100, 50);
    lv_obj_set_pos(btn_finsh_popup_sure,    120, 130);
    lv_obj_set_event_cb(btn_finsh_popup_sure, event_btn_printdon);
    mks_lvgl_label_set(btn_finsh_popup_sure, Label_popup_sure, 80, 10, "Yes");

    mks_lvgl_long_sroll_label_with_wight_set(finsh_popup, Label_popup, 100, 80, "File is print done!", 150);
}

void mks_x_y_pos_updata() { 
    
}

void mks_print_bar_updata(void) {

    uint16_t val = 50;  

    bar_print = mks_lv_bar_updata(bar_print, (uint16_t)sd_report_perc_complete());
}

void mks_draw_operation(void) {
    scr_op = lv_obj_create(scr, NULL);
    lv_obj_set_size(stop_popup, 480, 320);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_GRAY;
    popup_style.body.grad_color = LV_COLOR_GRAY;
    lv_obj_set_style(scr_op, &popup_style);

    btn_op_back = lv_imgbtn_creat_mks(scr_op, btn_op_back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_op_back);
    Label_op_back = mks_lvgl_label_set(scr, Label_op_back, 390, 280, "Back");


    /* power */

    /* move speed */

    /* care speed */
}

void mks_clear_print(void) {
    lv_obj_clean(scr);
}

void mks_del_obj(lv_obj_t *obj) { 
    lv_obj_del(obj);
}
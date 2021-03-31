#include "MKS_draw_print.h"

/* scr */
static lv_obj_t* scr;
static lv_obj_t* stop_popup;
static lv_obj_t* scr_op;
static lv_obj_t* finsh_popup;

/* style */
static lv_style_t btn_style;
static lv_style_t popup_style;

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
            lv_label_set_text(Label_suspend, "Run");
        } else if(mks_grbl.run_status == GRBL_PAUSE) {
            mks_grbl.run_status = GRBL_RUN;
            sys_rt_exec_accessory_override.bit.spindleOvrStop = true;
            lv_label_set_text(Label_suspend, "Pause");
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

    scr = lv_obj_create(NULL, NULL);
    scr = lv_scr_act();

    lv_style_copy(&btn_style, &lv_style_scr);
    btn_style.body.main_color = LV_COLOR_MAKE(0Xff, 0XE9, 0X85);
    btn_style.body.grad_color = LV_COLOR_MAKE(0XFA, 0X74, 0X2B);
    btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_style.body.radius = 4;
    btn_style.text.color = LV_COLOR_WHITE;

    btn_suspend = mks_lv_btn_set(scr, btn_suspend,    144, 40, 10, 260, event_handler_suspend);
    btn_stop = mks_lv_btn_set(scr, btn_stop,       144, 40, 164, 260, event_handler_stop);
    // btn_popup_op = mks_lv_btn_set(scr, btn_popup_op,   144, 40, 318, 260, event_handler_op);

    lv_btn_set_style(btn_suspend, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(btn_suspend,LV_BTN_STYLE_PR,&btn_style);

    lv_btn_set_style(btn_stop, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(btn_stop,LV_BTN_STYLE_PR,&btn_style);

    // lv_btn_set_style(btn_popup_op, LV_BTN_STYLE_REL, &btn_style);
    // lv_btn_set_style(btn_popup_op,LV_BTN_STYLE_PR,&btn_style);

    Label_suspend = mks_lvgl_long_sroll_label_with_wight_set_center(btn_suspend, Label_suspend, 0, 0, "Pause",50);
    Label_stop = mks_lvgl_long_sroll_label_with_wight_set_center(btn_stop, Label_stop, 0, 0, "Stop",50);
    // mks_lvgl_long_sroll_label_with_wight_set_center(btn_popup_op, label_operation, 0, 0, "Option",50);

    /*  
        30, 275,
        180, 275
        300, 275
    */
    mks_lvgl_long_sroll_label_set(scr, Label_file_name,         30, 40, file_print_send);

    // Label_suspend   = mks_lvgl_label_set_align_center(scr, Label_suspend,     50, 275,     "#fad509 Pause#");
    // Label_stop      = mks_lvgl_label_set_align_center(scr, Label_stop,        210, 275,    "#fad509 Stop#");
    // label_operation = mks_lvgl_label_set_align_center(scr, label_operation,   350, 275,    "#fad509 Option#");

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
        spindle->stop();
        mks_grbl.run_status = GRBL_RESTARTING;
        lv_obj_del(stop_popup);
        mks_clear_print();
        // lv_draw_ready();
    }
}

static void event_btn_printdon(lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(finsh_popup);
        mks_grbl.run_status = GRBL_RESTARTING; 
        mks_clear_print();
        // lv_draw_ready();
    }
}

void mks_draw_print_popup(const char* text) {
    stop_popup = lv_obj_create(scr, NULL);
    lv_obj_set_size(stop_popup, 350, 200);
    lv_obj_set_pos(stop_popup, 80, 50);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_MAKE(0XFD, 0X65, 0X85);
    popup_style.body.grad_color = LV_COLOR_MAKE(0X0d, 0X25, 0Xb9);
    popup_style.text.color = LV_COLOR_WHITE;
    popup_style.body.radius = 10;
    lv_obj_set_style(stop_popup, &popup_style);

    lv_style_copy(&btn_style, &lv_style_scr);
    btn_style.body.main_color = LV_COLOR_MAKE(0Xff, 0XE9, 0X85);
    btn_style.body.grad_color = LV_COLOR_MAKE(0XFA, 0X74, 0X2B);
    btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_style.text.color = LV_COLOR_WHITE;
    btn_style.body.radius = 4;

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

void mks_print_bar_updata(void) {

    bar_print = mks_lv_bar_updata(bar_print, (uint16_t)sd_report_perc_complete());

    mks_grbl.power_persen = gc_state.feed_rate;

}

void mks_draw_operation(void) {
    scr_op = lv_obj_create(scr, NULL);
    lv_obj_set_size(stop_popup, 480, 320);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_GRAY;
    popup_style.body.grad_color = LV_COLOR_GRAY;
    lv_obj_set_style(scr_op, &popup_style);

    btn_op_back   = lv_imgbtn_creat_mks(scr_op, btn_op_back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_op_back);
    Label_op_back = mks_lvgl_label_set(scr, Label_op_back, 390, 280, "Back");

    /* power */
    // imgbtn_power_add = mks_imgbtn_set(scr,)
    /* move speed */

    /* care speed */
}

void mks_clear_print(void) {
    lv_obj_clean(scr);
}

void mks_del_obj(lv_obj_t *obj) { 
    lv_obj_del(obj);
}
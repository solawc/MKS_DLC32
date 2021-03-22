#include "MKS_draw_tool.h"

/* Screan Build */
static lv_obj_t* scr;
static lv_obj_t* postiv_popup;

static lv_style_t btn_style;

/* imgbtn */
static lv_obj_t* home;
static lv_obj_t* positioning;
static lv_obj_t* move;
static lv_obj_t* light_on;
static lv_obj_t* power;
static lv_obj_t* Back;

/* btn */
static lv_obj_t* btn_popup_cancle;
static lv_obj_t* btn_popup_sure;

static lv_obj_t* btn_pos_popup_sure;


static lv_style_t popup_style;

/* label */
static lv_obj_t *Label_home;
static lv_obj_t *Label_positioning;
static lv_obj_t *Label_move;
static lv_obj_t *Label_light_on;
static lv_obj_t *Label_power;
static lv_obj_t *Label_back;
static lv_obj_t* Label_popup_cancel;
static lv_obj_t* Label_popup_sure;
static lv_obj_t* Label_popup;

LV_IMG_DECLARE(Home);           //先申明此图片
LV_IMG_DECLARE(Move);           //先申明此图片
LV_IMG_DECLARE(back);           //先申明此图片
LV_IMG_DECLARE(Light_on);
LV_IMG_DECLARE(Light_off);
LV_IMG_DECLARE(Power);
LV_IMG_DECLARE(Positionin);

static void event_handler_home(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        mks_clear_tool();
        mks_draw_home();
    }
}

static void event_handler_positioning(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        Serial.printf("G92 X0 Y0 Z0\n");
        MKS_GRBL_CMD_SEND("G92 X0 Y0 Z0\n");
        mks_draw_pos_pupop();
    }
}

static void event_handler_move(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        mks_clear_tool();
        mks_draw_move();
    }
}

static void event_handler_light(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        if(mks_grbl.light_status == GRBL_Light_On) 
            mks_grbl.light_status = GRBL_Light_Off;
        else if (mks_grbl.light_status == GRBL_Light_Off)
            mks_grbl.light_status = GRBL_Light_On;
        
        if(mks_grbl.light_status == GRBL_Light_On) {
            light_img_change(1);
            mks_grbl.power_persen = 100;
            MKS_GRBL_CMD_SEND("M3 S1000\n");
        }
        else {
            light_img_change(0);
            mks_grbl.power_persen = 0;
            MKS_GRBL_CMD_SEND("M3 S0\n"); 
        }    
    }
}

static void event_handler_power(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        mks_clear_tool();
        mks_draw_power();
    }
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        mks_clear_tool();
        lv_draw_ready();
    }
}

static void event_btn_cancle(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {

    }
}

static void event_btn_sure(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {

    }
}

static void event_btn_pos_sure(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        lv_obj_del(postiv_popup);
    }
}

void lv_draw_tool(void) {
    
    scr = lv_obj_create(NULL,NULL);
    scr = lv_scr_act();

    lv_imgbtn_creat_mks(scr, home, &Home, &Home, LV_ALIGN_CENTER, -180, -70, event_handler_home);
    lv_imgbtn_creat_mks(scr, positioning, &Positionin, &Positionin, LV_ALIGN_CENTER, -60, -70, event_handler_positioning);
    lv_imgbtn_creat_mks(scr, move, &Move, &Move, LV_ALIGN_CENTER,60, -70, event_handler_move);

    if(mks_grbl.light_status == GRBL_Light_On) 
        light_on = lv_imgbtn_creat_mks(scr, light_on, &Light_on, &Light_on, LV_ALIGN_CENTER, 180, -70, event_handler_light);
    else
        light_on = lv_imgbtn_creat_mks(scr, light_on, &Light_off, &Light_off, LV_ALIGN_CENTER, 180, -70, event_handler_light);

    lv_imgbtn_creat_mks(scr, power, &Power, &Power, LV_ALIGN_CENTER,-180,90, event_handler_power);
    lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);

    mks_lvgl_label_set(scr, Label_home,        30, 120,    "Home");
    mks_lvgl_label_set(scr, Label_positioning, 140, 120,   "Positioning");
    mks_lvgl_label_set(scr, Label_move,        280, 120,   "Move"  );
    mks_lvgl_label_set(scr, Label_power,       30, 280,    "Power");
    mks_lvgl_label_set(scr, Label_back,        400, 280,   "Back");

    if(mks_grbl.light_status == GRBL_Light_On) 
        Label_light_on = mks_lvgl_label_set(scr, Label_light_on, 390, 120, "Light_on");
    else 
        Label_light_on = mks_lvgl_label_set(scr, Label_light_on, 390, 120, "Light_off");
}

void light_img_change(uint8_t status) {
    if(status == 0) {
        lv_imgbtn_set_src(light_on, LV_BTN_STATE_PR, &Light_off);
        lv_imgbtn_set_src(light_on, LV_BTN_STATE_REL, &Light_off);
        lv_label_set_text(Label_light_on,"Light_off");
    }
    else if (status == 1) {
        lv_imgbtn_set_src(light_on, LV_BTN_STATE_PR, &Light_on);
        lv_imgbtn_set_src(light_on, LV_BTN_STATE_REL, &Light_on);
        lv_label_set_text(Label_light_on, "Light_on");
    }
}

void mks_draw_pos_pupop(void) { 

    postiv_popup = lv_obj_create(scr, NULL);
    lv_obj_set_size(postiv_popup, 350, 200);
    lv_obj_set_pos(postiv_popup, 80, 50);

    lv_style_copy(&popup_style, &lv_style_scr);
    popup_style.body.main_color = LV_COLOR_MAKE(0XFD, 0X65, 0X85);  // FD6585
    popup_style.body.grad_color = LV_COLOR_MAKE(0X0d, 0X25, 0Xb9);  // 0D25B9
    popup_style.text.color = LV_COLOR_WHITE;
    popup_style.body.radius = 10;
    lv_obj_set_style(postiv_popup, &popup_style);


    lv_style_copy(&btn_style, &lv_style_scr);
    btn_style.body.main_color = LV_COLOR_MAKE(0Xff, 0XE9, 0X85);  // #FFE985   #FA742B
    btn_style.body.grad_color = LV_COLOR_MAKE(0XFA, 0X74, 0X2B);
    // btn_style.body.grad_color = LV_COLOR_MAKE(0X1A, 0X1A, 0X1A);
    btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_style.text.color = LV_COLOR_WHITE;
    btn_style.body.radius = 4;
    
    btn_pos_popup_sure = mks_lv_btn_set(postiv_popup, btn_pos_popup_sure,100, 40, 120, 130, event_btn_pos_sure);
    lv_btn_set_style(btn_pos_popup_sure, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(btn_pos_popup_sure,LV_BTN_STYLE_PR,&btn_style);
    mks_lvgl_long_sroll_label_with_wight_set_center(btn_pos_popup_sure, Label_popup_sure, 0, 0, "Yes", 30);
    mks_lvgl_long_sroll_label_with_wight_set(postiv_popup, Label_popup, 100, 80, "Positioning done!", 150);
}

void mks_clear_tool(void) {
    lv_obj_clean(scr);
}



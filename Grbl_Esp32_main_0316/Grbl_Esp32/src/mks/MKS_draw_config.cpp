#include "MKS_draw_config.h"

static lv_obj_t *scr;

static kb_event_flag kb_flag = KB_NONE;

static lv_style_t btn_press_style;
static lv_style_t btn_relase_style;
static lv_style_t style_line;

/* page main */
static lv_obj_t *btn_Mechanical_parameters;
static lv_obj_t *btn_Motor_parameters;
static lv_obj_t *btn_Mode; 
static lv_obj_t *btn_format;            // FFS

/* page  mechanical parameters */
static lv_obj_t *btn_pulse_h_l;         // $2
static lv_obj_t *btn_limit;             // $5      
static lv_obj_t *btn_Probe_level;       // $6
static lv_obj_t *btn_Node_deviation;    // $11
static lv_obj_t *btn_Arc_tolerance;     // $12
static lv_obj_t *btn_Software_limit;    // $20
static lv_obj_t *btn_Limit_switch;      // $21
static lv_obj_t *btn_Laser_mode;        // $32
 

static lv_obj_t *keyboard;
static lv_obj_t *ta;

/* Motor parameters */
static lv_obj_t *btn_RPM_MAX;            // $30
static lv_obj_t *btn_RPM_Min;            // $31

static lv_obj_t *btn_X_Pluse;            // $100
static lv_obj_t *btn_Y_Pluse;            // $101
static lv_obj_t *btn_Z_Pluse;            // $102

static lv_obj_t *btn_X_MaxSpeed;         // $110
static lv_obj_t *btn_Y_MaxSpeed;         // $111
static lv_obj_t *btn_Z_MaxSpeed;         // $112

static lv_obj_t *btn_X_Acc;              // $120
static lv_obj_t *btn_Y_Acc;              // $121
static lv_obj_t *btn_Z_Acc;              // $122

static lv_obj_t *btn_X_MaxTrave;         // $130     
static lv_obj_t *btn_Y_MaxTrave;         // $131  
static lv_obj_t *btn_Z_MaxTrave;         // $132

// static lv_obj_t *btn_Step_pulse;


static lv_obj_t* btn_page_main_back;

static lv_obj_t *label_Mechanical_parameters;
static lv_obj_t *label_Motor_parameters;
static lv_obj_t *label_Mode;
static lv_obj_t *Label_format;
static lv_obj_t *Label_back;


lv_obj_t *line1;
lv_obj_t *line2;
lv_obj_t *line3;
lv_obj_t *line4;
lv_point_t line_points1[] = {{0,45},{470,45}};
lv_point_t line_points2[] = {{0,95},{470,95}};
lv_point_t line_points3[] = {{0,145},{470,145}};
lv_point_t line_points4[] = {{0,195},{470,195}};
// lv_point_t line_points5[] = {{0,0},{470,0}};


/* imgbtn */
static void event_handler_Me_par(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_clean_main_page();
        mks_draw_Mechan();
	}
}

static void event_handler_MT_par(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_clean_main_page();
        mks_draw_motor_parameters();
	}
}

static void event_handler_MD_par(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_format(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        SPIFFS.format();
	}
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clean_main_page();
		mks_draw_setting();
	}
}


/* keyboard call back */
static void event_hanler_kb_callback(lv_obj_t* obj, lv_event_t event) { 

    if(event == LV_EVENT_APPLY) {

        const char *ret_ta_txt = lv_ta_get_text(ta);
        if(kb_flag == KB_NONE) {
            return;
        }
        else if(kb_flag == KB_MT_RPM_MAX) {

        }
    }   
}

void mks_draw_config_main_page(void) { 

    scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

    lv_style_copy(&btn_press_style, &lv_style_scr);
    btn_press_style.body.main_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    btn_press_style.body.grad_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    btn_press_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_press_style.text.color = LV_COLOR_WHITE;

    /* 创建按键 */
    btn_Mechanical_parameters = mks_lv_btn_set(scr, btn_Mechanical_parameters,  470, 40, 0, 0 , event_handler_Me_par);
    btn_Motor_parameters =      mks_lv_btn_set(scr, btn_Motor_parameters,       470, 40, 0, 50 ,event_handler_MT_par);
    btn_Mode =                  mks_lv_btn_set(scr, btn_Mode,                   470, 40, 0, 100 ,event_handler_MD_par);
    btn_format =                mks_lv_btn_set(scr, btn_format,                 470, 40, 0, 150 ,event_handler_format);
    btn_page_main_back =        mks_lv_btn_set(scr, btn_page_main_back,         100, 40, 400, 250 ,event_handler_back);

    lv_btn_set_style(btn_Mechanical_parameters, LV_BTN_STYLE_REL, &btn_press_style);
    lv_btn_set_style(btn_Mechanical_parameters,LV_BTN_STYLE_PR,&btn_press_style);
    
    lv_btn_set_style(btn_Motor_parameters, LV_BTN_STYLE_REL, &btn_press_style);
    lv_btn_set_style(btn_Motor_parameters,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(btn_Mode, LV_BTN_STYLE_REL, &btn_press_style);
    lv_btn_set_style(btn_Mode,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(btn_format, LV_BTN_STYLE_REL, &btn_press_style);
    lv_btn_set_style(btn_format,LV_BTN_STYLE_PR,&btn_press_style);

    lv_btn_set_style(btn_page_main_back, LV_BTN_STYLE_REL, &btn_press_style);
    lv_btn_set_style(btn_page_main_back,LV_BTN_STYLE_PR,&btn_press_style);

    lv_style_copy(&style_line, &lv_style_plain);
    style_line.line.color = LV_COLOR_MAKE(0x00, 0x3b, 0x75);
    style_line.line.width = 1;
    style_line.line.rounded = 1;
    line1 = mks_lv_set_line(scr, line1, line_points1);

    lv_line_set_style(line1, LV_LINE_STYLE_MAIN, &style_line);

    line2 = mks_lv_set_line(scr, line2, line_points2);
    line3 = mks_lv_set_line(scr, line3, line_points3);
    line4 = mks_lv_set_line(scr, line4, line_points4);

    /* 创建label */
    mks_lvgl_long_sroll_label_with_wight_set_center(btn_Mechanical_parameters, label_Mechanical_parameters, -240, 0,"Mechanical parameters",470);
    mks_lvgl_long_sroll_label_with_wight_set_center(btn_Motor_parameters, label_Mechanical_parameters, -240, 0, "Motor_parameters", 470);
    mks_lvgl_long_sroll_label_with_wight_set_center(btn_Mode, label_Mechanical_parameters, -240, 0, "Mode",470);
    mks_lvgl_long_sroll_label_with_wight_set_center(btn_format, Label_format, -240, 0, "Format", 470);
    mks_lvgl_long_sroll_label_with_wight_set_center(btn_page_main_back, Label_back, 0, 0, "Return", 100);
}

static void event_handler_ME_back(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		mks_clean_main_page();
		mks_draw_config_main_page();
	}
}

/* 机械参数 */
void mks_draw_Mechan(void) {

    scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

    lv_style_copy(&btn_press_style, &lv_style_scr);
    btn_press_style.body.main_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    btn_press_style.body.grad_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    btn_press_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_press_style.text.color = LV_COLOR_WHITE;

    // /* 创建按键 */
    btn_Mechanical_parameters = mks_lv_btn_set(scr, btn_Mechanical_parameters,  250, 40, 10, 0   ,event_handler_Me_par);
    btn_Motor_parameters =      mks_lv_btn_set(scr, btn_Motor_parameters,       250, 40, 10, 50  ,event_handler_Me_par);
    btn_Mode =                  mks_lv_btn_set(scr, btn_Mode,                   250, 40, 10, 100 ,event_handler_Me_par);
    btn_page_main_back =        mks_lv_btn_set(scr, btn_page_main_back,         250, 40, 10, 250 ,event_handler_ME_back);

    lv_btn_set_style(btn_Mechanical_parameters, LV_BTN_STYLE_REL, &btn_press_style);
    lv_btn_set_style(btn_Mechanical_parameters,LV_BTN_STYLE_PR,&btn_press_style);
    
    // /* 创建label */
    // mks_lvgl_long_sroll_label_with_wight_set(btn_Mechanical_parameters, label_Mechanical_parameters, 0, 0,"",250);
    // mks_lvgl_long_sroll_label_with_wight_set(btn_Motor_parameters, label_Mechanical_parameters, 0,0, "Motor_parameters", 250);
    // mks_lvgl_long_sroll_label_with_wight_set(btn_Mode, label_Mechanical_parameters, 0, 0, "Laser Mode",250);
    // mks_lvgl_long_sroll_label_with_wight_set(btn_page_main_back, Label_back, 0, 0, "Return", 250);
}

static void event_handler_MP_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clean_main_page();
		mks_draw_Mechan();
	}
}

/* 电机参数 */
void mks_draw_motor_parameters(void) { 

    scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();


    btn_page_main_back =  mks_lv_btn_set(scr, btn_page_main_back,         250, 40, 0, 250 ,event_handler_MP_back);
    Label_back = mks_lvgl_long_sroll_label_with_wight_set(btn_page_main_back, Label_back, 0, 0, "Return", 250);
}

void mks_clean_main_page(void) {
	lv_obj_clean(scr);
}








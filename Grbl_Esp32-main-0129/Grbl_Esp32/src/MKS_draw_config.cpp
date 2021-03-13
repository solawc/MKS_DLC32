#include "MKS_draw_config.h"

static lv_obj_t *scr;

static lv_style_t btn_style;

/* page main */
static lv_obj_t *btn_Mechanical_parameters;
static lv_obj_t *btn_Motor_parameters;
static lv_obj_t *btn_Mode;

static lv_obj_t* btn_page_main_back;

static lv_obj_t *label_Mechanical_parameters;
static lv_obj_t *label_Motor_parameters;
static lv_obj_t *label_Mode;


/* imgbtn */

static void event_handler_Me_par(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clean_main_page();
		mks_draw_setting();
	}
}


void mks_draw_config_main_page(void) { 

    scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

    /* 创建按键 */
    btn_Mechanical_parameters = mks_lv_btn_set(scr, btn_Mechanical_parameters, 250, 40, 0, 0 ,event_handler_Me_par);
    btn_Motor_parameters = mks_lv_btn_set(scr, btn_Motor_parameters, 250, 40, 0, 50 ,event_handler_Me_par);
    label_Mode = mks_lv_btn_set(scr, label_Mode, 250, 40, 0, 100 ,event_handler_Me_par);
    btn_page_main_back = mks_lv_btn_set(scr, btn_page_main_back, 250, 40, 0, 250 ,event_handler_back);

    /* 创建label */
    mks_lvgl_long_sroll_label_with_wight_set(btn_Mechanical_parameters, label_Mechanical_parameters, 0, 0,"Mechanical parameters",250);
    mks_lvgl_long_sroll_label_with_wight_set(btn_Motor_parameters, label_Mechanical_parameters, 0,0, "Motor_parameters", 250);
    mks_lvgl_long_sroll_label_with_wight_set(label_Mode, label_Mechanical_parameters, 0, 0, "Mode",250);
    mks_lvgl_long_sroll_label_with_wight_set(btn_page_main_back, Label_back, 0, 0, "Return", 250);
}


void mks_draw_Mechan(void) {

    /**/

}


void mks_clean_main_page(void) {
	lv_obj_clean(scr);
}








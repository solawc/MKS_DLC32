#include "MKS_draw_power.h"
#include "MKS_LVGL.h"

POWER_PAGE_T power_page;

/* Screan Build */
// static lv_obj_t* scr;
// lv_obj_t* p_scr1;
// lv_obj_t* p_scr2;

// lv_style_t p_bkl_color;


// lv_obj_t* pwr_high;
// lv_obj_t* pwr_low;
// lv_obj_t* pwr_off;
// lv_obj_t* cailb;
// static lv_obj_t* Back;


// lv_obj_t* pwr_label_high;
// lv_obj_t* pwr_label_low;
// lv_obj_t* pwr_label_off;
// lv_obj_t* label_cailb;
// static lv_obj_t* label_Back;


LV_IMG_DECLARE(SP_H_UP);			//强光
LV_IMG_DECLARE(SPD_H_PRE);			//强光

LV_IMG_DECLARE(SP_L_UP);			//弱光
LV_IMG_DECLARE(SP_L_PRE);			//弱光
LV_IMG_DECLARE(SP_ON);				//开
LV_IMG_DECLARE(SP_OFF);				//关

LV_IMG_DECLARE(Calibration);			//Z回零
LV_IMG_DECLARE(back);			//返回

static void event_handler_pwr_on_off(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {

		// if(sys.state != State::Idle) {
		// 	draw_pwr_popup_1("Please wait machine idle!");
		// 	return ;
		// }

		mks_grbl.power_persen = P_0_PERSEN;
		lv_imgbtn_set_src(power_page.pwr_off, LV_BTN_STATE_PR, &SP_ON);
		lv_imgbtn_set_src(power_page.pwr_off, LV_BTN_STATE_REL, &SP_ON);
		lv_imgbtn_set_src(power_page.pwr_high, LV_BTN_STATE_PR, &SP_H_UP);
		lv_imgbtn_set_src(power_page.pwr_high, LV_BTN_STATE_REL, &SP_H_UP);
		lv_imgbtn_set_src(power_page.pwr_low, LV_BTN_STATE_PR, &SP_L_UP);
		lv_imgbtn_set_src(power_page.pwr_low, LV_BTN_STATE_REL, &SP_L_UP);
		MKS_GRBL_CMD_SEND("M3 S0\n");
	}
}

static void event_handler_pwr_l(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(sys.state != State::Idle) {
			draw_pwr_popup_1("Please wait machine idle!");
			return ;
		}

		mks_grbl.power_persen = P_1_PERSEN;
		lv_imgbtn_set_src(power_page.pwr_high, LV_BTN_STATE_PR, &SP_H_UP);
		lv_imgbtn_set_src(power_page.pwr_high, LV_BTN_STATE_REL, &SP_H_UP);

		lv_imgbtn_set_src(power_page.pwr_low, LV_BTN_STATE_PR, &SP_L_PRE);
		lv_imgbtn_set_src(power_page.pwr_low, LV_BTN_STATE_REL, &SP_L_PRE);

		lv_imgbtn_set_src(power_page.pwr_off, LV_BTN_STATE_PR, &SP_OFF);
		lv_imgbtn_set_src(power_page.pwr_off, LV_BTN_STATE_REL, &SP_OFF);
		MKS_GRBL_CMD_SEND("M3 S50\n");
		MKS_GRBL_CMD_SEND("$J=G91X0.01F1000\n");
	}
}

static void event_handler_pwr_h(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		if(sys.state != State::Idle) {
			draw_pwr_popup_1("Please wait machine idle!");
			return ;
		}

		mks_grbl.power_persen = P_10_PERSEN;
		lv_imgbtn_set_src(power_page.pwr_high, LV_BTN_STATE_PR, &SPD_H_PRE);
		lv_imgbtn_set_src(power_page.pwr_high, LV_BTN_STATE_REL, &SPD_H_PRE);
		lv_imgbtn_set_src(power_page.pwr_low, LV_BTN_STATE_PR, &SP_L_UP);
		lv_imgbtn_set_src(power_page.pwr_low, LV_BTN_STATE_REL, &SP_L_UP);
		lv_imgbtn_set_src(power_page.pwr_off, LV_BTN_STATE_PR, &SP_OFF);
		lv_imgbtn_set_src(power_page.pwr_off, LV_BTN_STATE_REL, &SP_OFF);
		MKS_GRBL_CMD_SEND("M3 S500\n");
		MKS_GRBL_CMD_SEND("$J=G91X0.01F1000\n");
	}
}

static void event_handler_cailb(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("$J=G91Z20F346\n");
	}
}

static void event_handler_Back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_power();
		mks_ui_page.mks_ui_page = MKS_UI_Ready;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
		mks_draw_ready();
	}
}


void mks_draw_power(void) {

	power_page.p_scr1 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(power_page.p_scr1, 460, 90);
    lv_obj_set_pos(power_page.p_scr1, 10, 10);

	power_page.p_scr2 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(power_page.p_scr2, 460, 200);
    lv_obj_set_pos(power_page.p_scr2, 10, 110);

	mks_ui_page.mks_ui_page = MKS_UI_Adjust;
    mks_ui_page.wait_count = DEFAULT_UI_COUNT;

	/* 设置背景样式 */
	lv_style_copy(&power_page.p_bkl_color, &lv_style_scr);
    power_page.p_bkl_color.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    power_page.p_bkl_color.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    power_page.p_bkl_color.text.color = LV_COLOR_WHITE;
    power_page.p_bkl_color.body.radius = 17;
    lv_obj_set_style(power_page.p_scr1, &power_page.p_bkl_color);
	lv_obj_set_style(power_page.p_scr2, &power_page.p_bkl_color);

	power_page.Back = lv_imgbtn_creat_mks(power_page.p_scr1, power_page.Back, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10, event_handler_Back);

#if defined(USE_BL_TOUCH)
	cailb = lv_imgbtn_creat_mks(p_scr1, cailb, &Calibration, &Calibration, LV_ALIGN_CENTER,150, -10, event_handler_cailb);
#endif


	if(mks_grbl.power_persen == P_10_PERSEN) {
		power_page.pwr_high = lv_imgbtn_creat_n_mks(power_page.p_scr2, power_page.pwr_high, &SPD_H_PRE, &SPD_H_PRE,10, 35, event_handler_pwr_h);
		power_page.pwr_low = lv_imgbtn_creat_n_mks(power_page.p_scr2, power_page.pwr_low, &SP_L_UP, &SP_L_UP,160, 35, event_handler_pwr_l);
		power_page.pwr_off = lv_imgbtn_creat_n_mks(power_page.p_scr2, power_page.pwr_low, &SP_OFF, &SP_OFF, 310, 35, event_handler_pwr_on_off);
	}
	else if(mks_grbl.power_persen == P_1_PERSEN) {
		power_page.pwr_high = lv_imgbtn_creat_n_mks(power_page.p_scr2, power_page.pwr_high, &SP_H_UP, &SP_H_UP,10, 35, event_handler_pwr_h);
		power_page.pwr_low = lv_imgbtn_creat_n_mks(power_page.p_scr2, power_page.pwr_low, &SP_L_PRE, &SP_L_PRE,160, 35, event_handler_pwr_l);
		power_page.pwr_off = lv_imgbtn_creat_n_mks(power_page.p_scr2, power_page.pwr_low, &SP_OFF, &SP_OFF, 310, 35, event_handler_pwr_on_off);
	}else if(mks_grbl.power_persen == P_0_PERSEN) {
		power_page.pwr_high = lv_imgbtn_creat_n_mks(power_page.p_scr2, power_page.pwr_high, &SP_H_UP, &SP_H_UP,10, 35, event_handler_pwr_h);
		power_page.pwr_low = lv_imgbtn_creat_n_mks(power_page.p_scr2, power_page.pwr_low, &SP_L_UP, &SP_L_UP,160, 35, event_handler_pwr_l);
		power_page.pwr_off = lv_imgbtn_creat_n_mks(power_page.p_scr2, power_page.pwr_low, &SP_ON, &SP_ON, 310, 35, event_handler_pwr_on_off);
	}

	power_page.label_Back = mks_lvgl_long_sroll_label_with_wight_set_center(power_page.p_scr1, power_page.label_Back, 20,60, "Back", 50);

#if defined(USE_BL_TOUCH)
	label_cailb = mks_lvgl_long_sroll_label_with_wight_set_center(p_scr1, label_cailb, 350, 60, "Z Home", 60);
#endif

	power_page.pwr_label_high = mks_lvgl_long_sroll_label_with_wight_set_center(power_page.p_scr2, power_page.pwr_label_high, 60,170, "50%", 50);
	power_page.pwr_label_low = mks_lvgl_long_sroll_label_with_wight_set_center(power_page.p_scr2, power_page.pwr_label_low, 210,170, "5%", 50);
	power_page.pwr_label_off = mks_lvgl_long_sroll_label_with_wight_set_center(power_page.p_scr2, power_page.pwr_label_off, 360,170, "OFF", 50);

	mks_ui_page.mks_ui_page = MKS_UI_Adjust;
} 


static void event_handler_popup_sure_1(lv_obj_t* obj, lv_event_t event) { 

	if(event == LV_EVENT_RELEASED) {

		lv_obj_del(power_page.p_popup);
	}
}


void draw_pwr_popup_1(const char *text) {

	// lv_obj_set_click(move_page.Back, false);
	// lv_obj_set_click(move_page.m_unlock, false);
	// lv_obj_set_click(move_page.home, false);
	// lv_obj_set_click(move_page.postivs, false);
	// lv_obj_set_click(move_page.hhome, false);

	power_page.p_popup = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(power_page.p_popup, move_popup_size_x, move_popup_size_y);
    lv_obj_set_pos(power_page.p_popup, move_popup_x, move_popup_y);

	lv_style_copy(&power_page.p_popup_color, &lv_style_scr);
	power_page.p_popup_color.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    power_page.p_popup_color.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    power_page.p_popup_color.text.color = LV_COLOR_BLACK;
    power_page.p_popup_color.body.radius = 17;
	lv_obj_set_style(power_page.p_popup, &power_page.p_popup_color);

	lv_style_copy(&power_page.p_popup_btn_color, &lv_style_scr);
	power_page.p_popup_btn_color.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    power_page.p_popup_btn_color.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    power_page.p_popup_btn_color.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    power_page.p_popup_btn_color.text.color = LV_COLOR_WHITE;
	power_page.p_popup_btn_color.body.radius = 10;

	power_page.btn_sure = mks_lv_btn_set(power_page.p_popup, 
										power_page.btn_sure, 
										move_popup_btn_size_x, 
										move_popup_btn_size_y, 
										move_popup_btn_x,
										 move_popup_btn_y, 
										 event_handler_popup_sure_1);
	lv_btn_set_style(power_page.btn_sure, LV_BTN_STYLE_REL, &power_page.p_popup_btn_color);
	lv_btn_set_style(power_page.btn_sure,LV_BTN_STYLE_PR, &power_page.p_popup_btn_color);

	power_page.label_sure = mks_lvgl_long_sroll_label_with_wight_set_center(power_page.p_popup, power_page.label_sure, 100, 50, text, 200);
	power_page.label_popup = mks_lvgl_long_sroll_label_with_wight_set_center(power_page.p_popup, power_page.label_popup, 50, 0, "YES",50);
}










lv_obj_t *bl_src;
lv_obj_t *bl_dis_label;
lv_style_t bl_style;

void mks_draw_bl_touch(void) { 

	bl_src = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(bl_src, 460, 90);
    lv_obj_set_pos(bl_src, 10, 10);

	bl_style.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    bl_style.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
	bl_style.text.color = LV_COLOR_BLACK;
	bl_style.body.radius = 17;
	lv_obj_set_style(bl_src, &bl_style);

	bl_dis_label = mks_lv_static_label(bl_src, bl_dis_label, 30, 30, "BLtouch is Working!", 100);
}

void bl_touch_run(void) {
	mks_draw_bl_touch();
	MKS_GRBL_CMD_SEND("G91Z10F100\n");  //Z抬升10
	BLTOUCH_push_down();					//弹出探针
	MKS_GRBL_CMD_SEND("G91Z-30F100\n"); //Z下降30
	mks_grbl.bl_status = BL_ADJ_ING;
}

void bl_touch_check(void) {

	if(mks_grbl.bl_status == BL_ADJ_ING) {

		if(stepper_idle) {   //检测到没有电机动了

			if(mks_grbl.bl_status == BL_ADJ_ING) { //再次确认bltouch

			}
		}
	}
}

void mks_clear_power(void) {
	lv_obj_clean(mks_src);
}
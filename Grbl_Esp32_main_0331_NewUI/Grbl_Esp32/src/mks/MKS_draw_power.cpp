#include "MKS_draw_power.h"
#include "MKS_LVGL.h"

/* Screan Build */
// static lv_obj_t* scr;
lv_obj_t* p_scr1;
lv_obj_t* p_scr2;

lv_style_t p_bkl_color;

/* imgbtn */
// lv_obj_t* add;
// lv_obj_t* dec;
// lv_obj_t* pwr_len;

lv_obj_t* pwr_on_off;
lv_obj_t* pwr_h_l;
lv_obj_t* cailb;
static lv_obj_t* Back;

/* label */
// lv_obj_t* Label_add;
// lv_obj_t* Label_dec;
// lv_obj_t* Label_pwr_len;
// static lv_obj_t* Label_Back;
// lv_obj_t* Label_power_on_off;
// lv_obj_t* Label_pwr_persen;

lv_obj_t* label_cailb;
static lv_obj_t* label_Back;



LV_IMG_DECLARE(glare);			//强光
LV_IMG_DECLARE(Low_light);		//弱光
LV_IMG_DECLARE(pwroff);			//开
LV_IMG_DECLARE(pwron);			//关
LV_IMG_DECLARE(Calibration);			//Z回零
LV_IMG_DECLARE(back);			//返回


// static void event_handler_add(lv_obj_t* obj, lv_event_t event) {
// 	char str[20];
// 	if (event == LV_EVENT_RELEASED) {

// 		if(mks_grbl.power_length == P_1_PERSEN) {
// 			mks_grbl.power_persen++;
// 			if (mks_grbl.power_persen >100 ) 
// 				mks_grbl.power_persen = 100;
// 		}else if(mks_grbl.power_length == P_10_PERSEN) {
// 			mks_grbl.power_persen = mks_grbl.power_persen + 10;
// 			if (mks_grbl.power_persen >100 ) 
// 				mks_grbl.power_persen = 100;
// 		}
// 		mks_power_set(mks_grbl.power_persen);
// 		sprintf(str, "M3 S%d\n", mks_grbl.power_persen);
// 		MKS_GRBL_CMD_SEND(str);
// 	}
// }

// static void event_handler_dec(lv_obj_t* obj, lv_event_t event) {
// 	char str[20];
// 	if (event == LV_EVENT_RELEASED) {
// 		if(mks_grbl.power_length == P_1_PERSEN) {
// 			mks_grbl.power_persen--;
// 			if (mks_grbl.power_persen <0 || mks_grbl.power_persen >100 ) 
// 				mks_grbl.power_persen = 0;
// 		}else if(mks_grbl.power_length == P_10_PERSEN) {
// 			mks_grbl.power_persen = mks_grbl.power_persen - 10;
// 			if (mks_grbl.power_persen <0 || mks_grbl.power_persen >100 ) 
// 				mks_grbl.power_persen = 0;
// 		}
// 		mks_power_set(mks_grbl.power_persen);
// 		sprintf(str, "M3 S%d\n", mks_grbl.power_persen);
// 		MKS_GRBL_CMD_SEND(str);
// 	}
// }

// static void event_handler_pwr_set(lv_obj_t* obj, lv_event_t event) {

// 	if (event == LV_EVENT_RELEASED) {
// 		if(mks_grbl.power_length == P_1_PERSEN) {
// 			mks_grbl.power_length = P_10_PERSEN;
// 			lv_imgbtn_set_src(pwr_len, LV_BTN_STATE_PR, &Pwr_10);
//     		lv_imgbtn_set_src(pwr_len, LV_BTN_STATE_REL, &Pwr_10);
// 			lv_label_set_text(Label_pwr_persen, "10%");
// 		}else if(mks_grbl.power_length == P_10_PERSEN) {
// 			mks_grbl.power_length = P_1_PERSEN;
// 			lv_imgbtn_set_src(pwr_len, LV_BTN_STATE_PR, &Pwr_1);
//     		lv_imgbtn_set_src(pwr_len, LV_BTN_STATE_REL, &Pwr_1);
// 			lv_label_set_text(Label_pwr_persen, "1%");
// 		}
// 	}
// }

static void event_handler_pwr_on_off(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		
		if(mks_grbl.light_status == GRBL_Light_On) { 
			mks_grbl.light_status = GRBL_Light_Off;
			lv_imgbtn_set_src(pwr_on_off, LV_BTN_STATE_PR, &pwroff);
    		lv_imgbtn_set_src(pwr_on_off, LV_BTN_STATE_REL, &pwroff);
		}
		else if(mks_grbl.light_status == GRBL_Light_Off) {
			mks_grbl.light_status = GRBL_Light_On;
			lv_imgbtn_set_src(pwr_on_off, LV_BTN_STATE_PR, &pwron);
    		lv_imgbtn_set_src(pwr_on_off, LV_BTN_STATE_REL, &pwron);
		}
	}
}

static void event_handler_pwr_h_l(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.power_persen == P_1_PERSEN) { 
			mks_grbl.power_persen = P_10_PERSEN;
			lv_imgbtn_set_src(pwr_h_l, LV_BTN_STATE_PR, &glare);
    		lv_imgbtn_set_src(pwr_h_l, LV_BTN_STATE_REL, &glare);
			if(mks_grbl.light_status == GRBL_Light_On) MKS_GRBL_CMD_SEND("M3 S500\n");
		}
		else if(mks_grbl.power_persen == P_10_PERSEN) {
			mks_grbl.power_persen = P_1_PERSEN;
			lv_imgbtn_set_src(pwr_h_l, LV_BTN_STATE_PR, &Low_light);
    		lv_imgbtn_set_src(pwr_h_l, LV_BTN_STATE_REL, &Low_light);
			if(mks_grbl.light_status == GRBL_Light_On) MKS_GRBL_CMD_SEND("M3 S5\n");
		}
	}
}

static void event_handler_cailb(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

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

	// char str[25];
	mks_src = lv_obj_create(NULL, NULL);
	mks_src = lv_scr_act();

	p_scr1 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(p_scr1, 460, 90);
    lv_obj_set_pos(p_scr1, 10, 10);

	p_scr2 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(p_scr2, 459, 200);
    lv_obj_set_pos(p_scr2, 10, 110);

	/* 设置背景样式 */
	lv_style_copy(&p_bkl_color, &lv_style_scr);
    p_bkl_color.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    p_bkl_color.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    p_bkl_color.text.color = LV_COLOR_WHITE;
    p_bkl_color.body.radius = 17;
    lv_obj_set_style(p_scr1, &p_bkl_color);
	lv_obj_set_style(p_scr2, &p_bkl_color);

	Back = lv_imgbtn_creat_mks(p_scr1, Back, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10, event_handler_Back);
	cailb = lv_imgbtn_creat_mks(p_scr1, cailb, &Calibration, &Calibration, LV_ALIGN_CENTER,150, -10, event_handler_cailb);

	
	if(mks_grbl.power_persen == P_1_PERSEN)
		pwr_h_l = lv_imgbtn_creat_mks(p_scr2, pwr_h_l, &Low_light, &Low_light, LV_ALIGN_CENTER,-80, 0, event_handler_pwr_h_l);
	else 
		pwr_h_l = lv_imgbtn_creat_mks(p_scr2, pwr_h_l, &glare, &glare, LV_ALIGN_CENTER,-80, 0, event_handler_pwr_h_l);

	if(mks_grbl.light_status == GRBL_Light_On)
		pwr_on_off = lv_imgbtn_creat_mks(p_scr2, pwr_on_off, &pwron, &pwron, LV_ALIGN_CENTER,80, 0, event_handler_pwr_on_off);
	else 
		pwr_on_off = lv_imgbtn_creat_mks(p_scr2, pwr_on_off, &pwroff, &pwroff, LV_ALIGN_CENTER,80, 0, event_handler_pwr_on_off);

	label_Back = mks_lvgl_long_sroll_label_with_wight_set_center(p_scr1, label_Back, 20,60, "Back", 50);
	label_cailb = mks_lvgl_long_sroll_label_with_wight_set_center(p_scr1, label_cailb, 350, 60, "Z Home", 60);

} 

void mks_clear_power(void) {
	lv_obj_clean(mks_src);
}
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

lv_obj_t* pwr_high;
lv_obj_t* pwr_low;
lv_obj_t* pwr_off;
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


LV_IMG_DECLARE(SP_H_UP);			//强光
LV_IMG_DECLARE(SPD_H_PRE);			//强光

LV_IMG_DECLARE(SP_L_UP);			//弱光
LV_IMG_DECLARE(SP_L_PRE);			//弱光
LV_IMG_DECLARE(SP_ON);				//开
LV_IMG_DECLARE(SP_OFF);				//关

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
			lv_imgbtn_set_src(pwr_off, LV_BTN_STATE_PR, &SP_OFF);
    		lv_imgbtn_set_src(pwr_off, LV_BTN_STATE_REL, &SP_OFF);
			MKS_GRBL_CMD_SEND("M3 S0\n");
		}else if(mks_grbl.light_status == GRBL_Light_Off) {
			mks_grbl.light_status = GRBL_Light_On;
			lv_imgbtn_set_src(pwr_off, LV_BTN_STATE_PR, &SP_ON);
    		lv_imgbtn_set_src(pwr_off, LV_BTN_STATE_REL, &SP_ON);

			if(mks_grbl.power_persen == P_1_PERSEN) {
				lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_PR, &SPD_H_PRE);
				lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_REL, &SPD_H_PRE);
				lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_PR, &SP_L_UP);
				lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_REL, &SP_L_UP);
				MKS_GRBL_CMD_SEND("M3 S5\n");
			}else if(mks_grbl.power_persen == P_10_PERSEN) {
				lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_PR, &SP_H_UP);
				lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_REL, &SP_H_UP);
				lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_PR, &SP_L_PRE);
				lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_REL, &SP_L_PRE);
				MKS_GRBL_CMD_SEND("M3 S500\n");
			}
		}
	}
}

static void event_handler_pwr_h_l(lv_obj_t* obj, lv_event_t event) {

	if(mks_grbl.light_status == GRBL_Light_On) {

		if(mks_grbl.power_persen == P_1_PERSEN) {
			lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_PR, &SPD_H_PRE);
    		lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_REL, &SPD_H_PRE);
			lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_PR, &SP_L_UP);
    		lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_REL, &SP_L_UP);
			MKS_GRBL_CMD_SEND("M3 S5\n");
		}else if(mks_grbl.power_persen == P_10_PERSEN) {
			lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_PR, &SP_H_UP);
    		lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_REL, &SP_H_UP);
			lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_PR, &SP_L_PRE);
    		lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_REL, &SP_L_PRE);
			MKS_GRBL_CMD_SEND("M3 S500\n");
		}
	}else{
		lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_PR, &SP_H_UP);
    	lv_imgbtn_set_src(pwr_high, LV_BTN_STATE_REL, &SP_H_UP);
		lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_PR, &SP_L_UP);
    	lv_imgbtn_set_src(pwr_low, LV_BTN_STATE_REL, &SP_L_UP);
		MKS_GRBL_CMD_SEND("M3 S0\n");
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

	if((mks_grbl.power_persen == P_10_PERSEN) && (mks_grbl.light_status == GRBL_Light_On))
		pwr_high = lv_imgbtn_creat_n_mks(p_scr2, pwr_high, &SPD_H_PRE, &SPD_H_PRE,10, 20, event_handler_pwr_h_l);
	else 
		pwr_high = lv_imgbtn_creat_n_mks(p_scr2, pwr_high, &SP_H_UP, &SP_H_UP,10, 20, event_handler_pwr_h_l);

	if((mks_grbl.power_persen == P_1_PERSEN) && (mks_grbl.light_status == GRBL_Light_On))
		pwr_low = lv_imgbtn_creat_n_mks(p_scr2, pwr_low, &SP_L_PRE, &SP_L_PRE,120, 0, event_handler_pwr_h_l);
	else 
		pwr_low = lv_imgbtn_creat_n_mks(p_scr2, pwr_low, &SP_L_UP, &SP_L_UP,120, 0, event_handler_pwr_h_l);

	if(mks_grbl.light_status == GRBL_Light_On)
		pwr_off = lv_imgbtn_creat_n_mks(p_scr2, pwr_low, &SP_ON, &SP_ON, 300, 0, event_handler_pwr_on_off);
	else 
		pwr_off = lv_imgbtn_creat_n_mks(p_scr2, pwr_low, &SP_OFF, &SP_OFF, 300, 0, event_handler_pwr_on_off);


	label_Back = mks_lvgl_long_sroll_label_with_wight_set_center(p_scr1, label_Back, 20,60, "Back", 50);
	label_cailb = mks_lvgl_long_sroll_label_with_wight_set_center(p_scr1, label_cailb, 350, 60, "Z Home", 60);

} 

void mks_clear_power(void) {
	lv_obj_clean(mks_src);
}
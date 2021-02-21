#include "MKS_draw_power.h"
#include "MKS_LVGL.h"

/* Screan Build */
static lv_obj_t* scr;

/* imgbtn */
lv_obj_t* add;
lv_obj_t* dec;
lv_obj_t* pwr_len;
static lv_obj_t* Back;

/* imgbtn */
lv_obj_t* Label_add;
lv_obj_t* Label_dec;
lv_obj_t* Label_pwr_len;
static lv_obj_t* Label_Back;
lv_obj_t* Label_power_on_off;
lv_obj_t* Label_pwr_persen;

LV_IMG_DECLARE(Add);			//先申明此图片
LV_IMG_DECLARE(Dec);			//先申明此图片
LV_IMG_DECLARE(Pwr_1);			//先申明此图片
LV_IMG_DECLARE(Pwr_10);			//先申明此图片
LV_IMG_DECLARE(back);			//先申明此图片


static void event_handler_add(lv_obj_t* obj, lv_event_t event) {
	char str[20];
	if (event == LV_EVENT_RELEASED) {

		if(mks_grbl.power_length == P_1_PERSEN) {
			mks_grbl.power_persen++;
			if (mks_grbl.power_persen >100 ) 
				mks_grbl.power_persen = 100;
		}else if(mks_grbl.power_length == P_10_PERSEN) {
			mks_grbl.power_persen = mks_grbl.power_persen + 10;
			if (mks_grbl.power_persen >100 ) 
				mks_grbl.power_persen = 100;
		}
		mks_power_set(mks_grbl.power_persen);
		sprintf(str, "M3 S%d\n", mks_grbl.power_persen);
		MKS_GRBL_CMD_SEND(str);
	}
}

static void event_handler_dec(lv_obj_t* obj, lv_event_t event) {
	char str[20];
	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.power_length == P_1_PERSEN) {
			mks_grbl.power_persen--;
			if (mks_grbl.power_persen <0 || mks_grbl.power_persen >100 ) 
				mks_grbl.power_persen = 0;
		}else if(mks_grbl.power_length == P_10_PERSEN) {
			mks_grbl.power_persen = mks_grbl.power_persen - 10;
			if (mks_grbl.power_persen <0 || mks_grbl.power_persen >100 ) 
				mks_grbl.power_persen = 0;
		}
		mks_power_set(mks_grbl.power_persen);
		sprintf(str, "M3 S%d\n", mks_grbl.power_persen);
		MKS_GRBL_CMD_SEND(str);
	}
}

static void event_handler_pwr_set(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.power_length == P_1_PERSEN) {
			mks_grbl.power_length = P_10_PERSEN;
			lv_imgbtn_set_src(pwr_len, LV_BTN_STATE_PR, &Pwr_10);
    		lv_imgbtn_set_src(pwr_len, LV_BTN_STATE_REL, &Pwr_10);
			lv_label_set_text(Label_pwr_persen, "#ffffff 10%#");
		}else if(mks_grbl.power_length == P_10_PERSEN) {
			mks_grbl.power_length = P_1_PERSEN;
			lv_imgbtn_set_src(pwr_len, LV_BTN_STATE_PR, &Pwr_1);
    		lv_imgbtn_set_src(pwr_len, LV_BTN_STATE_REL, &Pwr_1);
			lv_label_set_text(Label_pwr_persen, "#ffffff 1%#");
		}
	}
}

static void event_handler_Back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		mks_clear_power();
		lv_draw_tool();
	}
}

void mks_draw_power(void) {

	char str[25];
	scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

	lv_imgbtn_creat_mks(scr, add, &Add, &Add, LV_ALIGN_CENTER, -180, -50, event_handler_add);
	lv_imgbtn_creat_mks(scr, dec, &Dec, &Dec, LV_ALIGN_CENTER, 180, -50, event_handler_dec);
	lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_Back);

	if(mks_grbl.power_length == P_1_PERSEN)
		pwr_len = lv_imgbtn_creat_mks(scr, pwr_len, &Pwr_1, &Pwr_1, LV_ALIGN_CENTER, -60, 90, event_handler_pwr_set);
	else if (mks_grbl.power_length == P_10_PERSEN)
		pwr_len = lv_imgbtn_creat_mks(scr, pwr_len, &Pwr_10, &Pwr_10, LV_ALIGN_CENTER, -60, 90, event_handler_pwr_set);

	mks_lvgl_label_set(scr, Label_add, 40, 140, "#ffffff Add#");
	mks_lvgl_label_set(scr, Label_dec, 390, 140, "#ffffff Dec#");
	mks_lvgl_label_set(scr, Label_power_on_off, 180, 100, "#ffffff POWER:#");
	mks_lvgl_label_set(scr, Label_Back, 390, 280, "#ffffff Back#");

	if(mks_grbl.power_persen != 0) {
		sprintf(str,"#ffffff %d#", mks_grbl.power_persen);
		Label_pwr_len = mks_lvgl_label_set(scr, Label_pwr_len, 260, 100, str); 
	}else {
		Label_pwr_len = mks_lvgl_label_set(scr, Label_pwr_len, 260, 100, "#ffffff OFF#"); 
	}

	if(mks_grbl.power_length == P_1_PERSEN)
		Label_pwr_persen = mks_lvgl_label_set(scr, Label_pwr_persen, 160, 280, "#ffffff 1%#");
	else if(mks_grbl.power_length == P_10_PERSEN)
		Label_pwr_persen = mks_lvgl_label_set(scr, Label_pwr_persen, 160, 280, "#ffffff 10%#");
} 

void mks_power_set(uint8_t val) { 
	char str[25];
	if (val == 0) {
		lv_label_set_text(Label_pwr_len, "#ffffff OFF#");
	}else {
		sprintf(str, "#ffffff %d#",val);
		lv_label_set_text(Label_pwr_len, str);
	}
}

void mks_clear_power(void) {
	lv_obj_clean(scr);
}
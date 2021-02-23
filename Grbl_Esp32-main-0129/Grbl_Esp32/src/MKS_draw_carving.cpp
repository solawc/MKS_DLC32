#include "MKS_draw_carving.h"
#include "MKS_LVGL.h"
#include "FS.h"

 /* Screan Build */
static lv_obj_t* scr;
static lv_obj_t* caving_Popup;

/* style */
lv_style_t popup_style;

/* BTN */
lv_obj_t* btn_popup_cancle;
lv_obj_t* btn_popup_sure;

/* imgbtn */
lv_obj_t* up;
lv_obj_t* next;
lv_obj_t* Cback;

lv_obj_t* file_0;
lv_obj_t* file_1;
lv_obj_t* file_2;
lv_obj_t* file_3;
lv_obj_t* file_4;
lv_obj_t* file_5;

/* Label */
lv_obj_t* Label_file_0;
lv_obj_t* Label_file_1;
lv_obj_t* Label_file_2;
lv_obj_t* Label_file_3;
lv_obj_t* Label_file_4;
lv_obj_t* Label_file_5;
lv_obj_t* Label_NoFile;
lv_obj_t* Label_popup_cancel;
lv_obj_t* Label_popup_sure;
lv_obj_t* Label_popup;
lv_obj_t* Label_popup_file_name;

LV_IMG_DECLARE(Up);			//先申明此图片
LV_IMG_DECLARE(Next);		//先申明此图片
LV_IMG_DECLARE(cback);		//先申明此图片
LV_IMG_DECLARE(Files);		//先申明此图片
LV_IMG_DECLARE(FileDir);		//先申明此图片

static void event_handler_up(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("[ESP220] /lib4.nc\n");
	}
}

static void event_handler_next(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_cback(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		mks_clear_craving();
		lv_draw_ready();
	}
}


static void event_handler_file0(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		mks_draw_caving_popup();
	}
}


static void event_handler_file1(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		mks_draw_caving_popup();
	}
}


static void event_handler_file2(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		mks_draw_caving_popup();
	}
}


static void event_handler_file3(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		mks_draw_caving_popup();
	}
}


static void event_handler_file4(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		mks_draw_caving_popup();
	}
}

static void event_handler_file5(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		mks_draw_caving_popup();
	}
}




void mks_draw_craving(void) {

	scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

	lv_imgbtn_creat_mks(scr, up, &Up, &Up, LV_ALIGN_CENTER, 180, -70, event_handler_up);
	lv_imgbtn_creat_mks(scr, next, &Next, &Next, LV_ALIGN_CENTER, 180, 20, event_handler_next);
	lv_imgbtn_creat_mks(scr, Cback, &cback, &cback, LV_ALIGN_CENTER, 180, 110, event_handler_cback);

	
	
	if(mks_readSD_Status() == SDCARD_NOT_PRESENT) 
	{
		mks_lvgl_long_sroll_label_set(scr, Label_NoFile, 200, 150, "#ffffff No SD Card#");
	}else {

		mks_listDir(SD, "/",1);
	}	

	for(uint8_t i=0;i<6;i++) {

		mks_draw_sd_file(1,i);
	}
}


void mks_draw_sd_file(uint8_t status, uint8_t file_num) { 

	switch(file_num) {
		case 0: 
			if(status == 0) 
				file_0 = lv_imgbtn_creat_mks(scr, file_0, &FileDir, &FileDir, LV_ALIGN_CENTER, -180, -70, event_handler_file0);
			else 
				file_0 = lv_imgbtn_creat_mks(scr, file_0, &Files, &Files, LV_ALIGN_CENTER, -180, -70, event_handler_file0);
		break;
		case 1:
			if(status == 0) 
				file_1 = lv_imgbtn_creat_mks(scr, file_0, &FileDir, &FileDir, LV_ALIGN_CENTER, -60, -70, event_handler_file1);
			else 
				file_1 = lv_imgbtn_creat_mks(scr, file_0, &Files, &Files, LV_ALIGN_CENTER, -60, -70, event_handler_file1);
		break;
		case 2:
			if(status == 0) 
				file_2 = lv_imgbtn_creat_mks(scr, file_0, &FileDir, &FileDir, LV_ALIGN_CENTER, 60, -70, event_handler_file2);
			else 
				file_2 = lv_imgbtn_creat_mks(scr, file_0, &Files, &Files, LV_ALIGN_CENTER, 60, -70, event_handler_file2);
		break;
		case 3:
			if(status == 0) 
				file_3 = lv_imgbtn_creat_mks(scr, file_0, &FileDir, &FileDir, LV_ALIGN_CENTER, -180, 90, event_handler_file3);
			else 
				file_3 = lv_imgbtn_creat_mks(scr, file_0, &Files, &Files, LV_ALIGN_CENTER, -180, 90, event_handler_file3);
		break;
		case 4:
			if(status == 0) 
				file_4 = lv_imgbtn_creat_mks(scr, file_0, &FileDir, &FileDir, LV_ALIGN_CENTER, -60, 90, event_handler_file4);
			else 
				file_4 = lv_imgbtn_creat_mks(scr, file_0, &Files, &Files, LV_ALIGN_CENTER, -60, 90, event_handler_file4);
		break;
		case 5:
			if(status == 0) 
				file_5 = lv_imgbtn_creat_mks(scr, file_0, &FileDir, &FileDir, LV_ALIGN_CENTER, 60, 90, event_handler_file5);
			else 
				file_5 = lv_imgbtn_creat_mks(scr, file_0, &Files, &Files, LV_ALIGN_CENTER, 60, 90, event_handler_file5);
		break;
	}
}


static void event_btn_cancle(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(caving_Popup);
	}
}

static void event_btn_sure(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(caving_Popup);
	}
}



void mks_draw_caving_popup(void) {
	caving_Popup = lv_obj_create(scr, NULL);
	lv_obj_set_size(caving_Popup ,350, 200);
	lv_obj_set_pos(caving_Popup, 80,50);

	lv_style_copy(&popup_style, &lv_style_scr);
	popup_style.body.main_color = LV_COLOR_GRAY;
	popup_style.body.grad_color = LV_COLOR_GRAY;
	lv_obj_set_style(caving_Popup, &popup_style);

	btn_popup_cancle = lv_btn_create(caving_Popup,NULL);
    lv_obj_set_size(btn_popup_cancle, 100,50);
    lv_obj_set_pos(btn_popup_cancle, 240,130);
    lv_obj_set_event_cb(btn_popup_cancle, event_btn_cancle);
	mks_lvgl_label_set(caving_Popup, Label_popup_cancel,250,150, "Cancle");

	btn_popup_sure = lv_btn_create(caving_Popup,NULL);
    lv_obj_set_size(btn_popup_sure, 100,50);
    lv_obj_set_pos(btn_popup_sure, 10,130);
    lv_obj_set_event_cb(btn_popup_sure, event_btn_cancle);
	mks_lvgl_label_set(caving_Popup, Label_popup_sure, 20, 150, "Yes");

	mks_lvgl_label_set(caving_Popup, Label_popup, 40, 70, "Is Caving this File?");
	
	
}


void mks_clear_craving(void) {
	lv_obj_clean(scr);
}

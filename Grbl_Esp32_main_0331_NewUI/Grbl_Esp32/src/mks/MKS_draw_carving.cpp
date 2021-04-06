#include "MKS_draw_carving.h"
#include "MKS_LVGL.h"
#include "FS.h"
#include "../SDCard.h"

 /* Screan Build */
// static lv_obj_t* scr;

MKS_FILE_LIST_t mks_file_list;

lv_obj_t* caving_src1;
static lv_obj_t* caving_Popup;

/* style */
static lv_style_t popup_style;
static lv_style_t btn_style;
static lv_style_t caving_src1_style;
/* BTN */
static lv_obj_t* btn_popup_cancle;
static lv_obj_t* btn_popup_sure;

/* imgbtn */
lv_obj_t* up;
lv_obj_t* next;
lv_obj_t* Cback;

lv_obj_t* label_up;
lv_obj_t* label_next;
lv_obj_t* label_Cback;

lv_obj_t* file_0;
lv_obj_t* file_1;
lv_obj_t* file_2;
lv_obj_t* file_3;
lv_obj_t* file_4;
lv_obj_t* file_5;
lv_obj_t* file_6;
lv_obj_t* file_7;

/* Label */
lv_obj_t* Label_file_0;
lv_obj_t* Label_file_1;
lv_obj_t* Label_file_2;
lv_obj_t* Label_file_3;
lv_obj_t* Label_file_4;
lv_obj_t* Label_file_5;
lv_obj_t* Label_file_6;
lv_obj_t* Label_file_7;

lv_obj_t* Label_NoFile;
lv_obj_t* Label_popup_cancel;
lv_obj_t* Label_popup_sure;
lv_obj_t* Label_popup;
lv_obj_t* Label_popup_file_name;

LV_IMG_DECLARE(Previous);		//先申明此图片
LV_IMG_DECLARE(Next);			//先申明此图片
LV_IMG_DECLARE(back);			//先申明此图片
LV_IMG_DECLARE(file);			//先申明此图片
LV_IMG_DECLARE(FileDir);		//先申明此图片

// char file0_name[40];
// char file1_name[40];
// char file2_name[40];
// char file3_name[40];
// char file4_name[40];
// char file5_name[40];
char file_print_send[40];


#define FILE_NUM		8
#define FIEL_NAME		128
char filename[FILE_NUM][FIEL_NAME];

static void event_handler_up(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

		char p[30];

		if(mks_readSD_Status() == SDState::NotPresent)  // check sdcard is work
		{
		}
		else{
			if(mks_file_list.file_page == 1) {

			}else {
				mks_file_list.file_begin_num = 0;
				mks_file_list.file_count = 0;
				mks_file_list.file_page--;

				sprintf(p, "file page = %d", mks_file_list.file_page);
				grbl_send(CLIENT_SERIAL, p);

				mks_del_file_obj();
				mks_listDir(SD, "/",MKS_FILE_DEEP);
				draw_file_btmimg();
			}
		}
	}
}

static void event_handler_next(lv_obj_t* obj, lv_event_t event) {

	if(mks_readSD_Status() == SDState::NotPresent)  // check sdcard is work
	{ 
		
	}
	else {
		if (event == LV_EVENT_RELEASED) {


			if(mks_file_list.file_begin_num >= MKS_FILE_NUM) {
				mks_file_list.file_begin_num = 0;
				mks_file_list.file_count = 0;
				mks_file_list.file_page++;

				mks_del_file_obj();
				mks_listDir(SD, "/",MKS_FILE_DEEP);
				draw_file_btmimg();
			}
		}
	}
	
}

static void event_handler_cback(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		mks_clear_craving();
		mks_ui_page.mks_ui_page = MKS_UI_Ready;
        mks_ui_page.wait_count = DEFAULT_UI_COUNT;
		mks_draw_ready();
	}
}

static void event_handler_file0(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		// grbl_sendf(CLIENT_SERIAL, "file0_name111:%s\n",file0_name);
		mks_file_list.file_choose = 0;
		mks_draw_caving_popup(mks_file_list.file_begin_num, mks_file_list.filename_str[0]);
	}
}

static void event_handler_file1(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		// mks_draw_caving_popup(file1_name);
		mks_file_list.file_choose = 1;
		mks_draw_caving_popup(mks_file_list.file_begin_num, mks_file_list.filename_str[1]);
	}
}

static void event_handler_file2(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		// mks_draw_caving_popup(file2_name);
		mks_file_list.file_choose = 2;
		mks_draw_caving_popup(mks_file_list.file_begin_num, mks_file_list.filename_str[2]);
	}
}

static void event_handler_file3(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		// mks_draw_caving_popup(file3_name);
		mks_file_list.file_choose = 3;
		mks_draw_caving_popup(mks_file_list.file_begin_num, mks_file_list.filename_str[3]);
	}
}

static void event_handler_file4(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		// mks_draw_caving_popup(file4_name);
		mks_file_list.file_choose = 4;
		mks_draw_caving_popup(mks_file_list.file_begin_num, mks_file_list.filename_str[4]);
	}
}

static void event_handler_file5(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		// mks_draw_caving_popup(file5_name);
		mks_file_list.file_choose = 5;
		mks_draw_caving_popup(mks_file_list.file_begin_num, mks_file_list.filename_str[5]);
	}
}

static void event_handler_file6(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		// mks_draw_caving_popup(file6_name);
		mks_file_list.file_choose = 6;
		mks_draw_caving_popup(mks_file_list.file_begin_num, mks_file_list.filename_str[6]);
	}
}

static void event_handler_file7(lv_obj_t* obj, lv_event_t event) {
	if (event == LV_EVENT_RELEASED) {
		// mks_draw_caving_popup(file7_name);
		mks_file_list.file_choose = 7;
		mks_draw_caving_popup(mks_file_list.file_begin_num, mks_file_list.filename_str[7]);
	}
}


void mks_draw_craving(void) {

	mks_src = lv_obj_create(NULL, NULL);
	mks_src = lv_scr_act();

	lv_style_copy(&caving_src1_style, &lv_style_scr);
    caving_src1_style.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    caving_src1_style.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    caving_src1_style.text.color = LV_COLOR_WHITE;
    caving_src1_style.body.radius = 17;
    
	caving_src1 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(caving_src1 ,caving_src1_size_x, caving_src1_size_y);
	lv_obj_set_pos(caving_src1, caving_src1_x, caving_src1_y);
	lv_obj_set_style(caving_src1, &caving_src1_style);

	lv_imgbtn_creat_mks(caving_src1, up, &Previous, &Previous, LV_ALIGN_CENTER, 50, -10, event_handler_up);
	lv_imgbtn_creat_mks(caving_src1, next, &Next, &Next, LV_ALIGN_CENTER, 100, -10, event_handler_next);
	lv_imgbtn_creat_mks(caving_src1, Cback, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10, event_handler_cback);

	label_Cback = mks_lvgl_long_sroll_label_with_wight_set_center(caving_src1, label_Cback, caving_back_x,caving_back_y, "Back", 60);
	label_up = mks_lvgl_long_sroll_label_with_wight_set_center(caving_src1, label_up, caving_up_x, caving_up_y, "UP", 60);
	label_next = mks_lvgl_long_sroll_label_with_wight_set_center(caving_src1, label_next, caving_next_x, caving_next_y, "Next", 60);

	if(mks_readSD_Status() == SDState::NotPresent)  // check sdcard is work
	{
		mks_grbl.mks_sd_status = 0;	// no sd insert
		mks_lvgl_long_sroll_label_set(mks_src, Label_NoFile, 200, 150, "No SD Card");
	}else {
		mks_file_list.file_begin_num = 0;
		mks_file_list.file_count = 0;
		mks_file_list.file_page = 1;

		mks_grbl.mks_sd_status = 1; // sd had inserted
		mks_listDir(SD, "/",MKS_FILE_DEEP);
		draw_file_btmimg();
	}	
}


void draw_file_btmimg(void) {

	if(mks_file_list.file_begin_num == 1) {
		file_0 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y, event_handler_file0);
		Label_file_0 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_0, caving_first_file_label_x, caving_first_file_label_y, mks_file_list.filename_str[0], 50);
	}
	else if(mks_file_list.file_begin_num == 2) {
		file_0 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y, event_handler_file0);
		Label_file_0 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_0, caving_first_file_label_x, caving_first_file_label_y, mks_file_list.filename_str[0], 50);

		file_1 = lv_imgbtn_creat_mks(mks_src, file_1, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y, event_handler_file1);
		Label_file_1 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_1, caving_first_file_label_x + 120, caving_first_file_label_y, mks_file_list.filename_str[1], 50);	
	}
	else if(mks_file_list.file_begin_num == 3) {

		file_0 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y, event_handler_file0);
		Label_file_0 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_0, caving_first_file_label_x, caving_first_file_label_y, mks_file_list.filename_str[0], 50);

		file_1 = lv_imgbtn_creat_mks(mks_src, file_1, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y, event_handler_file1);
		Label_file_1 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_1, caving_first_file_label_x + 120, caving_first_file_label_y, mks_file_list.filename_str[1], 50);

		file_2 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 240, caving_first_file_y, event_handler_file2);
		Label_file_2 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_2, caving_first_file_label_x + 240, caving_first_file_label_y, mks_file_list.filename_str[2], 50);
	}
	else if(mks_file_list.file_begin_num == 4) {

		file_0 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y, event_handler_file0);
		Label_file_0 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_0, caving_first_file_label_x, caving_first_file_label_y, mks_file_list.filename_str[0], 50);

		file_1 = lv_imgbtn_creat_mks(mks_src, file_1, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y, event_handler_file1);
		Label_file_1 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_1, caving_first_file_label_x + 120, caving_first_file_label_y, mks_file_list.filename_str[1], 50);

		file_2 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 240, caving_first_file_y, event_handler_file2);
		Label_file_2 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_2, caving_first_file_label_x + 240, caving_first_file_label_y, mks_file_list.filename_str[2], 50);

		file_3 = lv_imgbtn_creat_mks(mks_src, file_3, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 360, caving_first_file_y, event_handler_file3);
		Label_file_3 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_3, caving_first_file_label_x + 360, caving_first_file_label_y, mks_file_list.filename_str[3], 50);
	}
	else if(mks_file_list.file_begin_num == 5) {
		file_0 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y, event_handler_file0);
		Label_file_0 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_0, caving_first_file_label_x, caving_first_file_label_y, mks_file_list.filename_str[0], 50);

		file_1 = lv_imgbtn_creat_mks(mks_src, file_1, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y, event_handler_file1);
		Label_file_1 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_1, caving_first_file_label_x + 120, caving_first_file_label_y, mks_file_list.filename_str[1], 50);

		file_2 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 240, caving_first_file_y, event_handler_file2);
		Label_file_2 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_2, caving_first_file_label_x + 240, caving_first_file_label_y, mks_file_list.filename_str[2], 50);

		file_3 = lv_imgbtn_creat_mks(mks_src, file_3, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 360, caving_first_file_y, event_handler_file3);
		Label_file_3 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_3, caving_first_file_label_x + 360, caving_first_file_label_y, mks_file_list.filename_str[3], 50);

		file_4 = lv_imgbtn_creat_mks(mks_src, file_4, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y + 105, event_handler_file4);
		Label_file_4 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_4, caving_first_file_label_x, caving_first_file_label_y + 105, mks_file_list.filename_str[4], 50);
	}
	else if(mks_file_list.file_begin_num == 6) {

		file_0 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y, event_handler_file0);
		Label_file_0 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_0, caving_first_file_label_x, caving_first_file_label_y, mks_file_list.filename_str[0], 50);

		file_1 = lv_imgbtn_creat_mks(mks_src, file_1, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y, event_handler_file1);
		Label_file_1 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_1, caving_first_file_label_x + 120, caving_first_file_label_y, mks_file_list.filename_str[1], 50);

		file_2 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 240, caving_first_file_y, event_handler_file2);
		Label_file_2 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_2, caving_first_file_label_x + 240, caving_first_file_label_y, mks_file_list.filename_str[2], 50);

		file_3 = lv_imgbtn_creat_mks(mks_src, file_3, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 360, caving_first_file_y, event_handler_file3);
		Label_file_3 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_3, caving_first_file_label_x + 360, caving_first_file_label_y, mks_file_list.filename_str[3], 50);

		file_4 = lv_imgbtn_creat_mks(mks_src, file_4, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y + 105, event_handler_file4);
		Label_file_4 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_4, caving_first_file_label_x, caving_first_file_label_y + 105, mks_file_list.filename_str[4], 50);

		file_5 = lv_imgbtn_creat_mks(mks_src, file_5, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y + 105, event_handler_file5);
		Label_file_5 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_5, caving_first_file_label_x + 120, caving_first_file_label_y + 105, mks_file_list.filename_str[5], 50);
	}
	else if(mks_file_list.file_begin_num == 7) {
		file_0 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y, event_handler_file0);
		Label_file_0 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_0, caving_first_file_label_x, caving_first_file_label_y, mks_file_list.filename_str[0], 50);

		file_1 = lv_imgbtn_creat_mks(mks_src, file_1, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y, event_handler_file1);
		Label_file_1 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_1, caving_first_file_label_x + 120, caving_first_file_label_y, mks_file_list.filename_str[1], 50);

		file_2 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 240, caving_first_file_y, event_handler_file2);
		Label_file_2 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_2, caving_first_file_label_x + 240, caving_first_file_label_y, mks_file_list.filename_str[2], 50);

		file_3 = lv_imgbtn_creat_mks(mks_src, file_3, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 360, caving_first_file_y, event_handler_file3);
		Label_file_3 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_3, caving_first_file_label_x + 360, caving_first_file_label_y, mks_file_list.filename_str[3], 50);

		file_4 = lv_imgbtn_creat_mks(mks_src, file_4, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y + 105, event_handler_file4);
		Label_file_4 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_4, caving_first_file_label_x, caving_first_file_label_y + 105, mks_file_list.filename_str[4], 50);

		file_5 = lv_imgbtn_creat_mks(mks_src, file_5, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y + 105, event_handler_file5);
		Label_file_5 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_5, caving_first_file_label_x + 120, caving_first_file_label_y + 105, mks_file_list.filename_str[5], 50);

		file_6 = lv_imgbtn_creat_mks(mks_src, file_6, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 240, caving_first_file_y + 105, event_handler_file6);
		Label_file_6 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_6, caving_first_file_label_x + 240, caving_first_file_label_y + 105, mks_file_list.filename_str[6], 50);
	}
	else if(mks_file_list.file_begin_num == 8) {
		file_0 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y, event_handler_file0);
		Label_file_0 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_0, caving_first_file_label_x, caving_first_file_label_y, mks_file_list.filename_str[0], 50);

		file_1 = lv_imgbtn_creat_mks(mks_src, file_1, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y, event_handler_file1);
		Label_file_1 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_1, caving_first_file_label_x + 120, caving_first_file_label_y, mks_file_list.filename_str[1], 50);

		file_2 = lv_imgbtn_creat_mks(mks_src, file_0, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 240, caving_first_file_y, event_handler_file2);
		Label_file_2 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_2, caving_first_file_label_x + 240, caving_first_file_label_y, mks_file_list.filename_str[2], 50);

		file_3 = lv_imgbtn_creat_mks(mks_src, file_3, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 360, caving_first_file_y, event_handler_file3);
		Label_file_3 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_3, caving_first_file_label_x + 360, caving_first_file_label_y, mks_file_list.filename_str[3], 50);

		file_4 = lv_imgbtn_creat_mks(mks_src, file_4, &file, &file, LV_ALIGN_CENTER, caving_first_file_x, caving_first_file_y + 105, event_handler_file4);
		Label_file_4 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_4, caving_first_file_label_x, caving_first_file_label_y + 105, mks_file_list.filename_str[4], 50);

		file_5 = lv_imgbtn_creat_mks(mks_src, file_5, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 120, caving_first_file_y + 105, event_handler_file5);
		Label_file_5 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_5, caving_first_file_label_x + 120, caving_first_file_label_y + 105, mks_file_list.filename_str[5], 50);

		file_6 = lv_imgbtn_creat_mks(mks_src, file_6, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 240, caving_first_file_y + 105, event_handler_file6);
		Label_file_6 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_6, caving_first_file_label_x + 240, caving_first_file_label_y + 105, mks_file_list.filename_str[6], 50);

		file_7 = lv_imgbtn_creat_mks(mks_src, file_7, &file, &file, LV_ALIGN_CENTER, caving_first_file_x + 360, caving_first_file_y + 105, event_handler_file7);
		Label_file_7 = mks_lvgl_long_sroll_label_with_wight_set_center(mks_src, Label_file_7, caving_first_file_label_x + 360, caving_first_file_label_y + 105, mks_file_list.filename_str[7], 50);
	}
}

void mks_del_file_obj(void) {

	lv_obj_del(file_0);
	lv_obj_del(file_1);
	lv_obj_del(file_2);
	lv_obj_del(file_3);
	lv_obj_del(file_4);
	lv_obj_del(file_5);
	lv_obj_del(file_6);
	lv_obj_del(file_7); 

	lv_obj_del(Label_file_0);
	lv_obj_del(Label_file_1);
	lv_obj_del(Label_file_2);
	lv_obj_del(Label_file_3);
	lv_obj_del(Label_file_4);
	lv_obj_del(Label_file_5);
	lv_obj_del(Label_file_6);
	lv_obj_del(Label_file_7);
}


static void event_btn_cancle(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(caving_Popup);
	}
}

static void event_btn_sure(lv_obj_t* obj, lv_event_t event) {
	char str_cmd[255] = "[ESP220]";
    if (event == LV_EVENT_RELEASED) {
		mks_grbl.run_status = GRBL_RUN;
		mks_grbl.is_mks_ts35_flag = true;
        lv_obj_del(caving_Popup);
		mks_clear_craving();
		// strcat(str_cmd,(char*)&filename[mks_file_list.file_choose]);
		strcat(str_cmd,file_print_send);
		MKS_GRBL_CMD_SEND(str_cmd);
		MKS_GRBL_CMD_SEND("\n");
		grbl_send(CLIENT_SERIAL, str_cmd);
		grbl_send(CLIENT_SERIAL, "\n");

		mks_ui_page.mks_ui_page = MKS_UI_Pring;  //进入雕刻界面
		mks_ui_page.wait_count = DEFAULT_UI_COUNT;
		mks_draw_print();
	}
}

void mks_draw_caving_popup(uint8_t text, char *srt) {
	caving_Popup = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(caving_Popup ,350, 200);
	lv_obj_set_pos(caving_Popup, 80,50);

	lv_style_copy(&popup_style, &lv_style_scr);
	// popup_style.body.main_color = LV_COLOR_MAKE(0x06, 0x08, 0x37);
	// popup_style.body.grad_color = LV_COLOR_MAKE(0x06, 0x08, 0x37);
	popup_style.body.main_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
    popup_style.body.grad_color = LV_COLOR_MAKE(0xCE, 0xD6, 0xE5); 
	popup_style.text.color = LV_COLOR_BLACK;
	popup_style.body.radius = 17;
	lv_obj_set_style(caving_Popup, &popup_style);
	
	lv_style_copy(&btn_style, &lv_style_scr);
    btn_style.body.main_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
    btn_style.body.grad_color = LV_COLOR_MAKE(0x3F, 0x46, 0x66);
	btn_style.body.radius = 10;
    btn_style.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    btn_style.text.color = LV_COLOR_WHITE;

	btn_popup_sure = mks_lv_btn_set(caving_Popup, btn_popup_sure, 100,40,10,130,event_btn_sure);
	lv_btn_set_style(btn_popup_sure, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(btn_popup_sure,LV_BTN_STYLE_PR,&btn_style);
	mks_lvgl_long_sroll_label_with_wight_set_center(btn_popup_sure, Label_popup_sure, 20, 0, "Yes",100);

	btn_popup_cancle = mks_lv_btn_set(caving_Popup, btn_popup_cancle, 100,40,240,130,event_btn_cancle);
	lv_btn_set_style(btn_popup_cancle, LV_BTN_STYLE_REL, &btn_style);
    lv_btn_set_style(btn_popup_cancle,LV_BTN_STYLE_PR,&btn_style);
	mks_lvgl_long_sroll_label_with_wight_set_center(btn_popup_cancle, Label_popup_sure, 20, 0, "Cancle",100);

	memcpy(file_print_send, srt, MKS_FILE_NAME_LENGTH);
	// grbl_sendf(CLIENT_SERIAL, "text:%s\n",text);
	grbl_sendf(CLIENT_SERIAL, "file_print_send:%s\n", mks_file_list.filename_str[text]);
	grbl_sendf(CLIENT_SERIAL, "file_print_send:%s\n", file_print_send);
	// grbl_sendf(CLIENT_SERIAL, "file_print_send:%s\n", file_print_send);
	mks_lvgl_long_sroll_label_with_wight_set(caving_Popup, Label_popup_file_name, 100, 40, file_print_send, 256);
	mks_lvgl_long_sroll_label_with_wight_set(caving_Popup, Label_popup, 100, 60, "Is Caving this File?",256);
}

void mks_clear_craving(void) {
	lv_obj_clean(mks_src);
}

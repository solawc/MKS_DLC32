#include "MKS_draw_move.h"


/* Screan Build */
static lv_obj_t* scr;

/* imgbtn */
lv_obj_t* x_n;			//+
lv_obj_t* x_p;			//-
lv_obj_t* y_n;			//+
lv_obj_t* y_p;			//-
lv_obj_t* z_n;			//+
lv_obj_t* z_p;			//-
lv_obj_t* len;
static lv_obj_t* Back;
/* Label */
lv_obj_t* Label_x_n;			//+
lv_obj_t* Label_x_p;			//-
lv_obj_t* Label_y_n;			//+
lv_obj_t* Label_y_p;			//-
lv_obj_t* Label_z_n;			//+
lv_obj_t* Label_z_p;			//-
lv_obj_t* Label_len;
lv_obj_t* Label_back;

LV_IMG_DECLARE(X_N);			//先申明此图片
LV_IMG_DECLARE(X_P);		//先申明此图片
LV_IMG_DECLARE(Y_N);			//先申明此图片
LV_IMG_DECLARE(Y_P);			//先申明此图片
LV_IMG_DECLARE(Z_N);			//先申明此图片
LV_IMG_DECLARE(Z_P);		//先申明此图片
LV_IMG_DECLARE(Len_0_1mm);			//先申明此图片
LV_IMG_DECLARE(Len_1mm);			//先申明此图片
LV_IMG_DECLARE(Len_10mm);			//先申明此图片
LV_IMG_DECLARE(back);			//先申明此图片

static void event_handler_x_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_x_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_y_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_y_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
	}
}

static void event_handler_z_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_z_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_len(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {

	}
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
        mks_clear_move();
        lv_draw_tool();
	}
}


void mks_draw_move(void) {

	scr = lv_obj_create(NULL, NULL);
	scr = lv_scr_act();

	lv_imgbtn_creat_mks(scr, x_n, &X_N, &X_N, LV_ALIGN_CENTER, -180, -70, event_handler_x_n);
	lv_imgbtn_creat_mks(scr, x_p, &X_P, &X_P, LV_ALIGN_CENTER, -180, 90, event_handler_x_p);
	lv_imgbtn_creat_mks(scr, y_n, &Y_N, &Y_N, LV_ALIGN_CENTER, -60, -70, event_handler_y_n);
	lv_imgbtn_creat_mks(scr, y_p, &Y_P, &Y_P, LV_ALIGN_CENTER, -60, 90, event_handler_y_p);
	lv_imgbtn_creat_mks(scr, z_n, &Z_N, &Z_N, LV_ALIGN_CENTER, 60, -70, event_handler_z_n);
	lv_imgbtn_creat_mks(scr, z_p, &Z_P, &Z_P, LV_ALIGN_CENTER, 60, 90, event_handler_z_p);
	lv_imgbtn_creat_mks(scr, len, &Len_0_1mm, &Len_0_1mm, LV_ALIGN_CENTER, 180, -70, event_handler_len);
	lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);

	mks_lvgl_label_set(scr, Label_x_n, 50, 120, "#ffffff X+#");
	mks_lvgl_label_set(scr, Label_x_p, 50, 280, "#ffffff X-#");
	mks_lvgl_label_set(scr, Label_y_n, 160, 120, "#ffffff Y+#");
	mks_lvgl_label_set(scr, Label_y_p, 160, 280, "#ffffff Y-#");
	mks_lvgl_label_set(scr, Label_z_n, 290, 120, "#ffffff Z+#");
	mks_lvgl_label_set(scr, Label_z_p, 290, 280, "#ffffff Z-#");
	mks_lvgl_label_set(scr, Label_len, 390, 120, "#ffffff 0.1mm#");
	mks_lvgl_label_set(scr, Label_back, 390, 280, "#ffffff Back#");
}

void mks_clear_move(void) {
	lv_obj_clean(scr);
}





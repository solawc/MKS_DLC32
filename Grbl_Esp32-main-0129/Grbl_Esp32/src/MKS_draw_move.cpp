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
LV_IMG_DECLARE(X_P);			//先申明此图片
LV_IMG_DECLARE(Y_N);			//先申明此图片
LV_IMG_DECLARE(Y_P);			//先申明此图片
LV_IMG_DECLARE(Z_N);			//先申明此图片
LV_IMG_DECLARE(Z_P);			//先申明此图片
LV_IMG_DECLARE(Len_0_1mm);		//先申明此图片
LV_IMG_DECLARE(Len_1mm);		//先申明此图片
LV_IMG_DECLARE(Len_10mm);		//先申明此图片
LV_IMG_DECLARE(back);			//先申明此图片

static void event_handler_x_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		// serila_write_into_buffer((uint8_t *)"$J=G91X10.0F300\n");
		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X0.1F500\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X1.0F500\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X10.0F500\n");
		}
	}
}

static void event_handler_x_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND((uint8_t *)"$J=G91X-10.0F300\n");

		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X-0.1F500\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X-1.0F500\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91X-10.0F300\n");
		}
	}
}

static void event_handler_y_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		MKS_GRBL_CMD_SEND("$J=G91Y10.0F300\n");

		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y0.1F500\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y1.0F500\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y10.0F500\n");
		}
	}
}

static void event_handler_y_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y-0.1F500\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y-1.0F500\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Y-10.0F500\n");
		}
	}
}

static void event_handler_z_n(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Z0.1F500\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Z1.0F500\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Z10.0F500\n");
		}
	}
}

static void event_handler_z_p(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if(mks_grbl.move_dis == M_0_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Z-0.1F500\n");
		}
		else if (mks_grbl.move_dis == M_1_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Z-1.0F500\n");
		}
		else if (mks_grbl.move_dis == M_10_MM) {
			MKS_GRBL_CMD_SEND("$J=G91Z-10.0F500\n");
		}
	}
}

static void event_handler_len(lv_obj_t* obj, lv_event_t event) {

	if (event == LV_EVENT_RELEASED) {
		if (mks_grbl.move_dis == M_0_1_MM) {
			len = lv_imgbtn_creat_mks(scr, len, &Len_0_1mm, &Len_0_1mm, LV_ALIGN_CENTER, 180, -70, event_handler_len);
			mks_grbl.move_dis = M_1_MM;
		}else if(mks_grbl.move_dis == M_1_MM) {
			len = lv_imgbtn_creat_mks(scr, len, &Len_1mm, &Len_1mm, LV_ALIGN_CENTER, 180, -70, event_handler_len);
			mks_grbl.move_dis = M_10_MM;
		}else if(mks_grbl.move_dis == M_10_MM) {
			len = lv_imgbtn_creat_mks(scr, len, &Len_10mm, &Len_10mm, LV_ALIGN_CENTER, 180, -70, event_handler_len);
			mks_grbl.move_dis = M_0_1_MM;
		}
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
	lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);
	
	mks_lvgl_label_set(scr, Label_x_n, 50, 120, "X+");
	mks_lvgl_label_set(scr, Label_x_p, 50, 280, "X-");
	mks_lvgl_label_set(scr, Label_y_n, 160, 120, "Y+");
	mks_lvgl_label_set(scr, Label_y_p, 160, 280, "Y-");
	mks_lvgl_label_set(scr, Label_z_n, 290, 120, "Z+");
	mks_lvgl_label_set(scr, Label_z_p, 290, 280, "Z-");
	mks_lvgl_label_set(scr, Label_len, 390, 120, "0.1mm");
	mks_lvgl_label_set(scr, Label_back, 390, 280, "Back");
}





void mks_clear_move(void) {
	lv_obj_clean(scr);
}





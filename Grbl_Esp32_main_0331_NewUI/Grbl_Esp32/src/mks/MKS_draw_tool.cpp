#include "MKS_draw_tool.h"

lv_style_t about_src1_style;
lv_style_t btn_tool_style;
static lv_style_t style_line;

lv_obj_t *about_src1; 



lv_obj_t *tool_img_back; 
lv_obj_t *tool_img_wifi; 

lv_obj_t *tool_label_line1; 
lv_obj_t *tool_label_line2; 
lv_obj_t *tool_label_line3; 
lv_obj_t *label_tool_back; 
lv_obj_t *label_tool_wifi; 

lv_obj_t *tool_line1;
lv_obj_t *tool_line2;
lv_obj_t *tool_line3;
// lv_point_t tool_line_points1[] = {{0,45},{470,45}};
// lv_point_t tool_line_points2[] = {{0,95},{470,95}};

lv_point_t tool_line_points[3][2] = {

    { {about_first_line_x, about_first_line_y}, {about_first_line_x+460, about_first_line_y} },
    { {about_first_line_x, about_first_line_y+50}, {about_first_line_x+460, about_first_line_y+50} },
    { {about_first_line_x, about_first_line_y+100}, {about_first_line_x+460, about_first_line_y+100} },
};

LV_IMG_DECLARE(back);	
LV_IMG_DECLARE(wifi_log);	


static void event_btn_tool_wifi(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        mks_clear_tool();
        mks_draw_wifi();
    }
}


static void event_btn_tool_back(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        mks_clear_tool();
        mks_draw_ready();
    }
}

void mks_draw_tool(void) {

    mks_src = lv_obj_create(NULL, NULL);
	mks_src = lv_scr_act();

    about_src1 = lv_obj_create(mks_src, NULL);
	lv_obj_set_size(about_src1, about_src1_x_size, about_src1_y_size);
    lv_obj_set_pos(about_src1, about_src1_x, about_src1_y);

    lv_style_copy(&about_src1_style, &lv_style_scr);
    about_src1_style.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    about_src1_style.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    about_src1_style.text.color = LV_COLOR_WHITE;
    about_src1_style.body.radius = 17;
    lv_obj_set_style(about_src1, &about_src1_style);

    lv_imgbtn_creat_mks(about_src1, tool_img_back, &back, &back, LV_ALIGN_IN_LEFT_MID, 10, -10, event_btn_tool_back);
    lv_imgbtn_creat_mks(about_src1, tool_img_wifi, &wifi_log, &wifi_log, LV_ALIGN_CENTER, 50, -10, event_btn_tool_wifi);

    lv_style_copy(&style_line, &lv_style_plain);
    style_line.line.color = LV_COLOR_MAKE(0x00, 0x3b, 0x75);
    style_line.line.width = 1;
    style_line.line.rounded = 1;
    tool_line1 = mks_lv_set_line(mks_src, tool_line1, tool_line_points[0]);
    lv_line_set_style(tool_line1, LV_LINE_STYLE_MAIN, &style_line);
    tool_line2 = mks_lv_set_line(mks_src, tool_line2, tool_line_points[1]);
    lv_line_set_style(tool_line2, LV_LINE_STYLE_MAIN, &style_line);
    tool_line3 = mks_lv_set_line(mks_src, tool_line3, tool_line_points[2]);
    lv_line_set_style(tool_line3, LV_LINE_STYLE_MAIN, &style_line);
    
    mks_lvgl_long_sroll_label_with_wight_set_center(about_src1, label_tool_back, 20, 50, "Back", 60);
    mks_lvgl_long_sroll_label_with_wight_set_center(about_src1, label_tool_wifi, 250, 50, "Wifi", 60);
}


void mks_clear_tool(void) {
    lv_obj_clean(mks_src);
}


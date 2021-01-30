#include "MKS_draw_tool.h"

/* Screan Build */
static lv_obj_t* scr;
/* imgbtn */
lv_obj_t* home;
lv_obj_t* positioning;
lv_obj_t* move;
lv_obj_t* light_on;
lv_obj_t* power;
lv_obj_t* Back;

/* label */
lv_obj_t *Label_home;
lv_obj_t *Label_positioning;
lv_obj_t *Label_move;
lv_obj_t *Label_light_on;
lv_obj_t *Label_power;
lv_obj_t *Label_back;

LV_IMG_DECLARE(Home);           //先申明此图片
LV_IMG_DECLARE(Move);           //先申明此图片
LV_IMG_DECLARE(back);           //先申明此图片
LV_IMG_DECLARE(Light_on);
LV_IMG_DECLARE(Light_off);
LV_IMG_DECLARE(Power);
LV_IMG_DECLARE(Positionin);

static void event_handler_home(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {

    }
}

static void event_handler_positioning(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {

    }
}

static void event_handler_move(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {

    }
}

static void event_handler_light(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {

    }
}

static void event_handler_power(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {

    }
}

static void event_handler_back(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_PRESSED) {
        mks_clear_tool();
        lv_draw_ready();
    }
}


void lv_draw_tool(void) {
    
    scr = lv_obj_create(NULL,NULL);
    scr = lv_scr_act();

    // lv_imgbtn_creat_mks(scr, home, &Setting, &Setting, LV_ALIGN_CENTER,0,0, event_handler);
    // lv_imgbtn_creat_mks(scr, positioning, &Tool, &Tool, LV_ALIGN_CENTER,-120, 0, event_handler);
    // lv_imgbtn_creat_mks(scr, move, &Craving, &Craving, LV_ALIGN_OUT_TOP_MID,0, 0, event_handler);
    // lv_imgbtn_creat_mks(scr, light_on, &Craving, &Craving, LV_ALIGN_OUT_TOP_RIGHT, 0, 0, event_handler);
    // lv_imgbtn_creat_mks(scr, power, &Craving, &Craving, LV_ALIGN_OUT_BOTTOM_LEFT,0,0, event_handler);
    // lv_imgbtn_creat_mks(scr, back, &Craving, &Craving,LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 0, event_handler);

    // mks_lvgl_label_set(scr, Label_home, 90, 200,    "#ffffff Home#"  );
    // mks_lvgl_label_set(scr, Label_positioning, 220, 200,   "#ffffff Positioning#");
    // mks_lvgl_label_set(scr, Label_move, 330, 200,   "#ffffff Move#"  );
    // mks_lvgl_label_set(scr, Label_light_on, 90, 200,    "#ffffff Light_on#");
    // mks_lvgl_label_set(scr, Label_power, 220, 200,   "#ffffff Power#");
    // mks_lvgl_label_set(scr, Label_back, 330, 200,   "#ffffff Back#");

    lv_imgbtn_creat_mks(scr, home, &Home, &Home, LV_ALIGN_CENTER, -180, -90, event_handler_home);
    lv_imgbtn_creat_mks(scr, positioning, &Positionin, &Positionin, LV_ALIGN_CENTER, -60, -90, event_handler_positioning);
    lv_imgbtn_creat_mks(scr, move, &Move, &Move, LV_ALIGN_CENTER,60, -90, event_handler_move);
    lv_imgbtn_creat_mks(scr, light_on, &Light_on, &Light_on, LV_ALIGN_CENTER, 180, -90, event_handler_light);
    lv_imgbtn_creat_mks(scr, power, &Power, &Power, LV_ALIGN_CENTER,-180,90, event_handler_power);
    lv_imgbtn_creat_mks(scr, Back, &back, &back, LV_ALIGN_CENTER, 180, 90, event_handler_back);

    mks_lvgl_label_set(scr, Label_home,             30, 120,    "#ffffff Home#");
    mks_lvgl_label_set(scr, Label_positioning,      140, 120,   "#ffffff Positioning#");
    mks_lvgl_label_set(scr, Label_move,             280, 120,   "#ffffff Move#"  );
    mks_lvgl_label_set(scr, Label_light_on,         390, 120,   "#ffffff Light_on#");
    mks_lvgl_label_set(scr, Label_power,            30, 300,    "#ffffff Power#");
    mks_lvgl_label_set(scr, Label_back,             390, 300,   "#ffffff Back#");
}

void mks_clear_tool(void) {
    lv_obj_clean(scr);
}



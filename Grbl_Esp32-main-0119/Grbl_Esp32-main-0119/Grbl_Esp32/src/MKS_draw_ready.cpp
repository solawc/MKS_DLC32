#include "MKS_draw_ready.h"


static lv_obj_t *scr;

enum {

    ID_TOOL     = 1,
    ID_SETTING,
    ID_CARVING,
};

static void event_handler(lv_obj_t *obj, lv_event_t event) {
    if (event != LV_EVENT_RELEASED) return ;

    switch(obj->mks_obj_id) {

        case ID_TOOL: 
        break;

        case ID_SETTING:
        break;

        case ID_CARVING:
        break;
    }
}

void lv_draw_ready(void) {

    
}

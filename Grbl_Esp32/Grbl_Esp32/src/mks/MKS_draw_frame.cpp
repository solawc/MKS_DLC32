#include "MKS_draw_frame.h"
#include "../WebUI/WebSettings.h"
#include "../WebUI/ESPResponse.h"
#include "../SDCard.h"


FRAME_CRTL_T frame_ctrl;
FRAME_PAGE_T frame_page;


LV_IMG_DECLARE(back);		

static void event_handler_cancle(lv_obj_t* obj, lv_event_t event) {

    if(event == LV_EVENT_RELEASED) {
        
        if(frame_ctrl.cancle_enable == true) {
            mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
            mks_ui_page.wait_count = 1;
            lv_obj_clean(mks_src);
            mks_draw_ready();
        }
    }
}

void mks_draw_frame(void) { 

    mks_frame_init();

    lv_style_copy(&frame_page.frame_src_style, &lv_style_scr);
    frame_page.frame_src_style.body.main_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    frame_page.frame_src_style.body.grad_color = LV_COLOR_MAKE(0x1F, 0x23, 0x33); 
    frame_page.frame_src_style.text.color = LV_COLOR_WHITE;
    frame_page.frame_src_style.body.radius = 17;

    frame_page.frame_src = lv_obj_create(mks_src, NULL);
    lv_obj_set_size(frame_page.frame_src ,FRAME_SRC_SIZE_X, FRAME_SRC_SIZE_Y);
	lv_obj_set_pos(frame_page.frame_src, FRAME_SRC_X, FRAME_SRC_Y);
	lv_obj_set_style(frame_page.frame_src, &frame_page.frame_src_style);

    // lv_imgbtn_creat_n_mks(frame_page.frame_src, 
    //                     frame_page.label_cancle, 
    //                     &back, &back, 
    //                     // LV_ALIGN_IN_LEFT_MID, 
    //                     FRAME_IMGBTN_X, 
    //                     FRAME_IMGBTN_Y, 
    //                     event_handler_cancle);
    
    // frame_page.label_cancle = mks_lvgl_long_sroll_label_with_wight_set_center(frame_page.frame_src, 
    //                                                                         frame_page.label_cancle, 
    //                                                                         FRAME_IMGBTN_X, 
    //                                                                         FRAME_IMGBTN_Y+50, 
    //                                                                         "Cancel", 
    //                                                                         102);
    
    frame_page.label_text = mks_lvgl_long_sroll_label_with_wight_set_center(frame_page.frame_src, 
                                                                            frame_page.label_text, 
                                                                            FRAME_LABEL_RUN_STATUS_X, 
                                                                            FRAME_LABEL_RUN_STATUS_Y+10, 
                                                                            "Wait draw frame...", 
                                                                            255);
    mks_ui_page.mks_ui_page = MKS_UI_Frame;
    mks_ui_page.wait_count = 1;
}


void frame_status_dis(FRAME_STATUS status) { 
    char buf[255];
    switch(status) {

        case FRAME_NONE:
            sprintf(buf, "Wait draw frame...");
        break;

        case FRAWM_READ_SD:
            sprintf(buf, "Reading file...");
        break;

        case FRAM_RUN:
            sprintf(buf, "Machine run...");
        break;

        case FRAM_END:
            sprintf(buf, "Finsh...");
        break;

        case FRAWM_READ_SD_BUSY:
            sprintf(buf, "SDcard is busy..");
        break;
        mks_lv_label_updata(frame_page.label_text, buf);
    }
}

void mks_openSDFile(char* parameter) {
    if (*parameter == '\0') {    // 用来判断文件名是否为空

        return;
    }

    String path = trim(parameter);

    // if (path[0] != '/') {   // 为文件名添加'/'
    //     path = "/" + path;
    // }
    SDState state = get_sd_state(true);
    if (state != SDState::Idle) {
        if (state == SDState::NotPresent) {
            // webPrintln("No SD Card");
            return;
        } 
        else 
        {
            // webPrintln("SD Card Busy");
            return;
        }
    }

    if (!openFile(SD, path.c_str())) {
        
        return;
    }
}


// bool lb_flag = false;

void polocte_cmd(char *str) {
    
    if(strstr(str ,"Bounds")) {
        frame_ctrl.lb_flag == true;
    }

    if(strstr(str, "G0")) {
        frame_ctrl.have_g0 = 1;
    }
    else if(strstr(str, "G1")) {
        frame_ctrl.have_g1 = 1;
    }

    
    while( *str != '\0' && frame_ctrl.safe_count < FRAME_BUFF_SIZE -1 ) {      
        if((frame_ctrl.have_g0 == 1)||(frame_ctrl.have_g1==1)) {
            
            if(*str == 'X') {
                str++;
                memset(frame_ctrl.x_value, '\0', sizeof(frame_ctrl.x_value));
                frame_ctrl.x_or_y = &frame_ctrl.x_value[0];
                while(*str !=' ' && *str!='\r' && *str!='\n') {
                    
                    *frame_ctrl.x_or_y = *str;

                    str++;
                    frame_ctrl.x_or_y++;
                }
                frame_ctrl.x_temp = atof(frame_ctrl.x_value);

                if(frame_ctrl.lb_flag) frame_ctrl.x_first_pos = frame_ctrl.x_temp;  // 判断是否是相对坐标
                
                if(frame_ctrl.x_temp > frame_ctrl.x_max) frame_ctrl.x_max = frame_ctrl.x_temp;

                if(frame_ctrl.x_temp < frame_ctrl.x_min) frame_ctrl.x_min = frame_ctrl.x_temp;
                else if(frame_ctrl.x_min == 0) frame_ctrl.x_min = frame_ctrl.x_temp;
            }
            
            if(*str == 'Y') {
                str++;
                memset(frame_ctrl.y_value, '\0', sizeof(frame_ctrl.x_value));
                frame_ctrl.x_or_y = &frame_ctrl.y_value[0];
                while(*str !=' ' && *str!='\r' && *str!='\n') {
                    
                    *frame_ctrl.x_or_y = *str;
                    str++;
                    frame_ctrl.x_or_y++;
                }
                frame_ctrl.y_temp = atof(frame_ctrl.y_value);

                if(frame_ctrl.lb_flag) frame_ctrl.y_first_pos = frame_ctrl.y_temp; // 判断是否是相对坐标

                if(frame_ctrl.y_temp > frame_ctrl.y_max) frame_ctrl.y_max = frame_ctrl.y_temp;

                if(frame_ctrl.y_temp < frame_ctrl.y_min) frame_ctrl.y_min = frame_ctrl.y_temp;
                else if(frame_ctrl.y_min == 0) frame_ctrl.y_min = frame_ctrl.y_temp;
            }

            if(frame_ctrl.lb_flag) {
                
                if(*str == 'X') {
                    str++;
                    memset(frame_ctrl.x_value, '\0', sizeof(frame_ctrl.x_value));
                    frame_ctrl.x_or_y = &frame_ctrl.x_value[0];
                    while(*str !=' ' && *str!='\r' && *str!='\n') {
                        
                        *frame_ctrl.x_or_y = *str;

                        str++;
                        frame_ctrl.x_or_y++;
                    }
                    frame_ctrl.x_temp = atof(frame_ctrl.x_value);
                    if(frame_ctrl.lb_flag) frame_ctrl.x_last_pos = frame_ctrl.x_temp;  // 判断是否是相对坐标
                
                }

                if(*str == 'Y') {
                    str++;
                    memset(frame_ctrl.y_value, '\0', sizeof(frame_ctrl.x_value));
                    frame_ctrl.x_or_y = &frame_ctrl.y_value[0];
                    while(*str !=' ' && *str!='\r' && *str!='\n') {
                        
                        *frame_ctrl.x_or_y = *str;
                        str++;
                        frame_ctrl.x_or_y++;
                    }
                    frame_ctrl.y_temp = atof(frame_ctrl.y_value);
                    if(frame_ctrl.lb_flag) frame_ctrl.y_last_pos = frame_ctrl.y_temp; // 判断是否是相对坐标
                }
            } 
        } // end
        str++;
    }
}

void mks_frame_init(void) { 
    frame_ctrl.x_max = 0;
    frame_ctrl.x_min = 0;
    frame_ctrl.y_max = 0;
    frame_ctrl.y_min = 0;
    frame_ctrl.y_temp = 0;
    frame_ctrl.x_temp = 0;
    frame_ctrl.have_g0 = 0;
    frame_ctrl.have_g1 = 0;
    frame_ctrl.cancle_enable = false;
    frame_ctrl.lb_flag = false;
}


void event_handle_yes(lv_obj_t* obj, lv_event_t event) {

    if(event == LV_EVENT_RELEASED) {
        lv_obj_del(com_p1.com_popup_src);
        frame_ctrl.out = false;
        mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING; 
	    mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        mks_lv_clean_ui();
        start_print();
    }
}

void event_handle_no(lv_obj_t* obj, lv_event_t event) {

    if(event == LV_EVENT_RELEASED) {
        lv_obj_del(com_p1.com_popup_src);
        mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING; 
	    mks_ui_page.wait_count = DEFAULT_UI_COUNT;
        frame_ctrl.out = false;
        mks_lv_clean_ui();
        mks_draw_craving();
    }
}


void mks_run_frame(char *parameter) {

    char frame_cmd[20];

    frame_ctrl.cancle_enable = true;
    frame_ctrl.out = true;

    grbl_send(CLIENT_SERIAL ,"run frame\n");
    if (sys.state != State::Idle && sys.state != State::Alarm) {    // 判断SD卡状态
        mks_lv_label_updata(frame_page.label_text, "SD is busy...");
        lv_refr_now(lv_refr_get_disp_refreshing());
        frame_ctrl.cancle_enable = true;
        return ;
    }

    mks_lv_label_updata(frame_page.label_text, "Loading file...");
    lv_refr_now(lv_refr_get_disp_refreshing());

    // grbl_send(CLIENT_SERIAL ,"open file\n");
    mks_openSDFile(parameter);

    // grbl_send(CLIENT_SERIAL ,"begin po\n");
    char fileLine[255];
    uint8_t point_last_num = 1;
    uint32_t point_count = 0;

    while (readFileLine(fileLine, 255)) {

        if(point_count == 255*6) {
            switch(point_last_num) {
            case 1: 
                mks_lv_label_updata(frame_page.label_text, "Loading file.");
                lv_refr_now(lv_refr_get_disp_refreshing());
            break;

            case 2: 
                mks_lv_label_updata(frame_page.label_text, "Loading file..");
                lv_refr_now(lv_refr_get_disp_refreshing());
            break;

            case 3: 
                mks_lv_label_updata(frame_page.label_text, "Loading file...");
                lv_refr_now(lv_refr_get_disp_refreshing());
            break;
            }

            point_last_num++;
            if( point_last_num >= 3) {
                point_last_num = 1;
            } 
            point_count = 0;
        }
        point_count++;
        polocte_cmd(fileLine);
    }
    closeFile();
    mks_lv_label_updata(frame_page.label_text, "Running...");
    lv_refr_now(lv_refr_get_disp_refreshing());

    MKS_GRBL_CMD_SEND("M3 S5\n");

    if(!frame_ctrl.lb_flag) {
        sprintf(frame_cmd, "G1 Y%f F1000\n",frame_ctrl.y_max);  // point 1
        MKS_GRBL_CMD_SEND(frame_cmd);

        sprintf(frame_cmd, "G1 X%f F1000\n", frame_ctrl.x_max);  // point 2
        MKS_GRBL_CMD_SEND(frame_cmd);

        sprintf(frame_cmd, "G1 Y%f F1000\n", frame_ctrl.y_min); // point 3
        MKS_GRBL_CMD_SEND(frame_cmd);

        sprintf(frame_cmd, "G1 X%f F1000\n", frame_ctrl.x_min);// point 4 
        MKS_GRBL_CMD_SEND(frame_cmd);
    }else {

        sprintf(frame_cmd, "G1 Y%f F1000\n",abs(frame_ctrl.y_max - frame_ctrl.y_min));  // point 1
        MKS_GRBL_CMD_SEND(frame_cmd);

        sprintf(frame_cmd, "G1 X%f F1000\n", abs(frame_ctrl.x_max - frame_ctrl.x_min));  // point 2
        MKS_GRBL_CMD_SEND(frame_cmd);

        sprintf(frame_cmd, "G1 Y%f F1000\n", -(abs(frame_ctrl.y_max - frame_ctrl.y_min))); // point 3
        MKS_GRBL_CMD_SEND(frame_cmd);

        sprintf(frame_cmd, "G1 X%f F1000\n", -(abs(frame_ctrl.x_max - frame_ctrl.x_min)));// point 4 
        MKS_GRBL_CMD_SEND(frame_cmd);
    }
    
    MKS_GRBL_CMD_SEND("M5\n");
    MKS_GRBL_CMD_SEND("G0 X0 Y0 F300\n");

    frame_ctrl.is_begin_run = true;
    frame_ctrl.cancle_enable = true;

    return ;
}

void frame_finsh_popup(void) {

    

    mks_draw_common_popup("Info", 
                        "Do you want to carve?",
                        " ",
                        event_handle_yes,
                        event_handle_no);
}

bool mks_get_frame_status(void) { 

    if(sys.state == State::Idle) {
        frame_ctrl.is_finsh_run = true;
    }else{
        frame_ctrl.is_finsh_run = false;
    }
    return frame_ctrl.is_finsh_run;
}





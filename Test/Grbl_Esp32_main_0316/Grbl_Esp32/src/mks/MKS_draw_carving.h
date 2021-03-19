#ifndef __MKS_draw_carving_h
#define __MKS_draw_carving_h

#include "MKS_draw_lvgl.h"

extern char file0_name[40];
extern char file1_name[40];
extern char file2_name[40];
extern char file3_name[40];
extern char file4_name[40];
extern char file5_name[40];
extern char file_print_send[40];


void mks_draw_craving(void);
void mks_clear_craving(void);
void mks_draw_sd_file(uint8_t status, uint8_t file_num, const char *filename);
void mks_draw_caving_popup(char* text);
void mks_del_file_obj(void);
#endif

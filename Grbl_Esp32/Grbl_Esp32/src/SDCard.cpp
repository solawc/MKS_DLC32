/*
  SDCard.cpp - Adds SD Card Features to Grbl_ESP32
  Part of Grbl_ESP32

  Copyright (c) 2018 Barton Dring Buildlog.net

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Config.h"
#include "mks/MKS_LVGL.h"
#ifdef ENABLE_SD_CARD
#    include "SDCard.h"

File                       myFile;
bool                       SD_ready_next = false;  // Grbl has processed a line and is waiting for another
uint8_t                    SD_client     = CLIENT_SERIAL;
// uint8_t                    SD_client     = CLIENT_SD;
WebUI::AuthenticationLevel SD_auth_level = WebUI::AuthenticationLevel::LEVEL_GUEST;
uint32_t                   sd_current_line_number;     // stores the most recent line number read from the SD
static char                comment[LINE_BUFFER_SIZE];  // Line to be executed. Zero-terminated.

// attempt to mount the SD card
/*bool sd_mount()
{
  if(!SD.begin()) {
    report_status_message(Error::FsFailedMount, CLIENT_SERIAL);
    return false;
  }
  return true;
}*/

bool filename_check(char *str, uint16_t num) {

    if(num > 128) return false;
    if(((str[num-1]=='c')||(str[num-1]='C')) && ((str[num-2] == 'n')||(str[num-2] == 'N'))) return true;
    else return false;
}

char filename_check_str[255];
void listDir(fs::FS& fs, const char* dirname, uint8_t levels, uint8_t client) {
    //char temp_filename[128]; // to help filter by extension	TODO: 128 needs a definition based on something
    File root = fs.open(dirname);
    if (!root) {
        report_status_message(Error::FsFailedOpenDir, client);
        return;
    }
    if (!root.isDirectory()) {
        report_status_message(Error::FsDirNotFound, client);
        return;
    }
    File file = root.openNextFile();
    while (file) {
        if (file.isDirectory()) {
            if (levels) {
                listDir(fs, file.name(), levels - 1, client);
            }
        } else {
            memset(filename_check_str, 0, sizeof(filename_check_str));
            strcpy(filename_check_str, file.name());
            if(filename_check(filename_check_str, strlen(filename_check_str)) == true) {
                grbl_sendf(CLIENT_ALL, "[FILE:%s|SIZE:%d]\r\n", file.name(), file.size());
                // grbl_send(CLIENT_ALL, "check\n");
            }
        }
        file = root.openNextFile();
    }
}

char mks_filename_check_str[255];
void mks_listDir(fs::FS& fs, const char* dirname, uint8_t levels) { 

    File root = fs.open(dirname);    //建立文件根目录并打开文件系统

    // root 为空时判断为文件系统打开失败
    if(!root) {
        //...提示文件系统打开失败
        return;
    }

    if (!root.isDirectory()) {
        // ...找不到文件夹（根文件夹）
        return;
    }
    File file = root.openNextFile(); 
    
    while(file) {

        if (file.isDirectory()) {
            if (levels) {
                mks_listDir(fs, file.name(), levels - 1);
            }
        } else {

            // strcpy(mks_filename_check_str, file.name());
            // memset(mks_filename_check_str, 0, sizeof(mks_filename_check_str));
            memcpy(mks_filename_check_str, file.name(), 255);
            strcpy(mks_filename_check_str, file.name());

            if(filename_check(mks_filename_check_str, strlen(mks_filename_check_str)) == true) {
                if((mks_file_list.file_count >= ((mks_file_list.file_page * MKS_FILE_NUM)-(MKS_FILE_NUM))) 
                    && (mks_file_list.file_count < (mks_file_list.file_page * MKS_FILE_NUM))) {
                    memset(mks_file_list.filename_str[mks_file_list.file_begin_num], 0, sizeof(mks_file_list.filename_str[mks_file_list.file_begin_num]));
                    strcpy(mks_file_list.filename_str[mks_file_list.file_begin_num], mks_filename_check_str);
                    mks_file_list.file_begin_num++;
                }
                mks_file_list.file_count++;
                if(mks_file_list.file_count >= (mks_file_list.file_page * MKS_FILE_NUM)) return;
            }
        }
       file =  root.openNextFile();
    }
}

boolean openFile(fs::FS& fs, const char* path) {
    myFile = fs.open(path);
    if (!myFile) {
        //report_status_message(Error::FsFailedRead, CLIENT_SERIAL);
        return false;
    }
    set_sd_state(SDState::BusyPrinting);
    SD_ready_next          = false;  // this will get set to true when Grbl issues "ok" message
    sd_current_line_number = 0;
    return true;
}

boolean closeFile() {
    if (!myFile) {
        return false;
    }
    set_sd_state(SDState::Idle);
    SD_ready_next          = false;
    sd_current_line_number = 0;
    myFile.close();
    SD.end();
    return true;
}

/*
  read a line from the SD card
  strip whitespace
  strip comments per http://linuxcnc.org/docs/ja/html/gcode/overview.html#gcode:comments
  make uppercase
  return true if a line is
*/
boolean readFileLine(char* line, int maxlen) {
    if (!myFile) {
        report_status_message(Error::FsFailedRead, SD_client);
        return false;
    }
    sd_current_line_number += 1;
    int len = 0;
    while (myFile.available()) {
        if (len >= maxlen) {
            return false;
        }
        char c = myFile.read();
        if (c == '\n') {
            break;
        }
        line[len++] = c;
    }
    line[len] = '\0';
    return len || myFile.available();
}

// return a percentage complete 50.5 = 50.5%
float sd_report_perc_complete() {
    if (!myFile) {
        return 0.0;
    }
    return (float)myFile.position() / (float)myFile.size() * 100.0f;
}

uint32_t sd_get_current_line_number() {
    return sd_current_line_number;
}

SDState sd_state = SDState::Idle;

SDState get_sd_state(bool refresh) {
    if (SDCARD_DET_PIN != UNDEFINED_PIN) {
        if (digitalRead(SDCARD_DET_PIN) != SDCARD_DET_VAL) {
            sd_state = SDState::NotPresent;
            return sd_state;
            //no need to go further if SD detect is not correct
        }
    }

    //if busy doing something return state
    if (!((sd_state == SDState::NotPresent) || (sd_state == SDState::Idle))) {
        return sd_state;
    }
    if (!refresh) {
        return sd_state;  //to avoid refresh=true + busy to reset SD and waste time
    }

    //SD is idle or not detected, let see if still the case
    SD.end();
    sd_state = SDState::NotPresent;
    //using default value for speed ? should be parameter
    //refresh content if card was removed
    if (SD.begin((GRBL_SPI_SS == -1) ? SS : GRBL_SPI_SS, SPI, GRBL_SPI_FREQ, "/sd", 2)) {
        if (SD.cardSize() > 0) {
            sd_state = SDState::Idle;
        }
    }
    return sd_state;
}

SDState set_sd_state(SDState state) {
    sd_state = state;
    return sd_state;
}

void sd_get_current_filename(char* name) {
    if (myFile) {
        strcpy(name, myFile.name());
    } else {
        name[0] = 0;
    }
}
#endif  //ENABLE_SD_CARD

#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2019-10-16 16:04:47

#include "Arduino.h"
#include <Cylinder.h>
#include <Nextion.h>
#include <Insomnia.h>
#include <Controllino.h>

void setup() ;
void loop() ;
void setup_eeprom_counter()  ;
void eeprom_counter() ;
int lights() ;
int run_main_test_cycle() ;
int send_to_nextion() ;
void nextion_setup()     ;
void nextion_loop()  ;
void nex_switch_play_pausePushCallback(void *ptr) ;
void nex_switch_modePushCallback(void *ptr) ;
void nex_but_stepbackPushCallback(void *ptr) ;
void nex_but_stepnxtPushCallback(void *ptr) ;
void nex_but_reset_cyclePushCallback(void *ptr) ;
void nex_zyl_feder_zuluftPushCallback(void *ptr) ;
void nex_zyl_feder_abluftPushCallback(void *ptr) ;
void nex_zyl_klemmblockPushCallback(void *ptr) ;
void nex_zyl_wippenhebelPushCallback(void *ptr) ;
void nex_zyl_wippenhebelPopCallback(void *ptr) ;
void nex_mot_band_untenPushCallback(void *ptr) ;
void nex_mot_band_untenPopCallback(void *ptr) ;
void nex_zyl_schweisstastePushCallback(void *ptr) ;
void nex_zyl_schweisstastePopCallback(void *ptr) ;
void nex_zyl_messerPushCallback(void *ptr) ;
void nex_zyl_messerPopCallback(void *ptr) ;
void nex_einschaltventilPushCallback(void *ptr) ;
void nex_but_slider1_leftPushCallback(void *ptr) ;
void nex_but_slider1_rightPushCallback(void *ptr) ;
void nex_but_reset_shorttime_counterPushCallback(void *ptr) ;
void nex_but_reset_shorttime_counterPopCallback(void *ptr) ;
void nex_page0PushCallback(void *ptr) ;
void nex_page1PushCallback(void *ptr) ;
void nex_page2PushCallback(void *ptr) ;
void nex_page3PushCallback(void *ptr) ;
int read_n_toggle() ;

#include "BXT_800_RIG.ino"

#include "eeprom_storage.ino"
#include "lights.ino"
#include "main_cycle.ino"
#include "nextion.ino"
#include "read_n_toggle.ino"

#endif
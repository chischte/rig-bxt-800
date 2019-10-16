//PROGRAM TO CONTROL A NEXTION 5" DISPLAY
//Created by Michi, November 2018

//#include "Cylinder.h"
//#include "Nextion.h"

// Include the nextion library (the official one) https://github.com/itead/ITEADLIB_Arduino_Nextion
// Make sure you edit the NexConfig.h file on the library folder to set the correct serial port for the display.

//***************************************************************************
//VARIOUS COMMANDS
//***************************************************************************
// Serial2.print("click bt1,1");//CLICK BUTTON
// send_to_nextion();
// A switch (Dual State Button)will be toggled with this command, a Button wil be set permanently pressed)

// Serial2.print("vis t0,0");//HIDE OBJECT
// send_to_nextion();

// Serial2.print("t0.txt=");//WRITE TEXT:
// Serial2.print("\"");
// Serial2.print("SCHNEIDEN");
// Serial2.print("\"");
// send_to_nextion();
//***************************************************************************
//DECLARATION OF VARIABLES
//***************************************************************************
int CurrentPage;
String cycle_name[] = { "1 AUFWECKEN", "2 VORSCHIEBEN", "3 SCHNEIDEN", "4 FESTKLEMMEN",
    "5 KRAFTAUFBAU", "6 SPANNEN", "7 SCHWEISSEN", "8 ABKUELHEN", "9 ENTSPANNEN", "10 ENTKLEMMEN",
    "11 ZURUECKFAHREN", "12 PAUSE" };
//***************************************************************************
//NEXTION SWITCH STATES LIST
//Every nextion switch button (dualstate) needs a switchstate variable to control switchtoggle
//Nextion buttons(momentary) need a variable too, to prevent screen flickering

bool nex_state_einschaltventil;
bool nex_state_zyl_feder_zuluft;
bool nex_state_zyl_feder_abluft;
bool nex_state_zyl_klemmblock;
bool nex_state_zyl_wippenhebel;
bool nex_state_zyl_spanntaste;
bool nex_state_zyl_messer;
bool nex_state_zyl_schweisstaste;
bool nex_state_machine_running;
bool nex_state_band_vorhanden = 1;
//***************************************************************************
bool nex_prev_step_mode = true;
bool stopwatch_running;
bool reset_stopwatch_active;

byte nex_prev_cycle_step;

unsigned int nex_prev_startfuelldauer;
unsigned int nex_prev_federkraft_int;
unsigned int nex_prev_federdruck;
unsigned long nex_prev_restpausenzeit;
unsigned long nex_prev_shorttime_counter;
unsigned long nex_prev_longtime_counter;
unsigned long button_push_stopwatch;
unsigned long counter_reset_stopwatch;
unsigned long nex_update_timer;
//***************************************************************************
//***************************************************************************
//DECLARATION OF OBJECTS TO BE READ FROM NEXTION
//***************************************************************************

//PAGE 0:
NexPage nex_page0 = NexPage(0, 0, "page0");

//PAGE 1 - LEFT SIDE:
NexPage nex_page1 = NexPage(1, 0, "page1");
NexButton nex_but_stepback = NexButton(1, 6, "b1");
NexButton nex_but_stepnxt = NexButton(1, 7, "b2");
NexButton nex_but_reset_cycle = NexButton(1, 5, "b0");
NexDSButton nex_switch_play_pause = NexDSButton(1, 2, "bt0");
NexDSButton nex_switch_mode = NexDSButton(1, 4, "bt1");

//PAGE 1 - RIGHT SIDE
NexDSButton nex_zyl_feder_zuluft = NexDSButton(1, 14, "bt5");
NexDSButton nex_zyl_feder_abluft = NexDSButton(1, 13, "bt4");
NexDSButton nex_zyl_klemmblock = NexDSButton(1, 12, "bt3");
NexButton nex_zyl_wippenhebel = NexButton(1, 11, "b5");
NexButton nex_mot_band_unten = NexButton(1, 10, "b4");
NexDSButton nex_zyl_messer = NexDSButton(1, 17, "b6");
NexButton nex_zyl_schweisstaste = NexButton(1, 8, "b3");
NexButton nex_einschaltventil = NexButton(1, 16, "bt6");

//PAGE 2 - LEFT SIDE:
NexPage nex_page2 = NexPage(2, 0, "page2");
NexButton nex_but_slider1_left = NexButton(2, 5, "b1");
NexButton nex_but_slider1_right = NexButton(2, 6, "b2");

//PAGE 2 - RIGHT SIDE:
NexButton nex_but_reset_shorttime_counter = NexButton(2, 15, "b4");

//PAGE 3:
NexPage nex_page3 = NexPage(3, 0, "page3");
NexWaveform waveform = NexWaveform(3, 1, "s0"); //DECLARATION OF WAVEFORM GRAPH

//***************************************************************************
//END OF OBJECT DECLARATION
//***************************************************************************

char buffer[100] = { 0 }; // This is needed only if you are going to receive a text from the display. You can remove it otherwise.

//***************************************************************************
//TOUCH EVENT LIST //DECLARATION OF TOUCH EVENTS TO BE MONITORED
//***************************************************************************
NexTouch *nex_listen_list[] = { &nex_page0, &nex_page1, &nex_page2, &nex_page3,
    &nex_but_reset_shorttime_counter, &nex_but_stepback, &nex_but_stepnxt, &nex_but_reset_cycle,
    &nex_but_slider1_left, &nex_but_slider1_right, &nex_switch_play_pause, &nex_switch_mode,
    &nex_zyl_messer, &nex_zyl_klemmblock, &nex_zyl_feder_zuluft, &nex_zyl_feder_abluft,
    &nex_zyl_wippenhebel, &nex_mot_band_unten, &nex_zyl_schweisstaste, &nex_einschaltventil,

    NULL //String terminated
        };
//***************************************************************************
//END OF TOUCH EVENT LIST
//***************************************************************************

//***************************************************************************
int send_to_nextion() {
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}
//***************************************************************************
//***************************************************************************
//***************************************************************************
//***************************************************************************
void nextion_setup()
//***************************************************************************
//***************************************************************************
//***************************************************************************
//***************************************************************************
{ //START NEXTION SETUP
  Serial2.begin(9600);  // Start serial comunication at baud=9600

  //***************************************************************************
  //INCREASE BAUD RATE
  //***************************************************************************
  /*
   delay(500);
   Serial2.print("baud=38400");
   send_to_nextion();
   Serial2.end();
   Serial2.begin(38400);
   */
  //***************************************************************************
  //REGISTER THE EVENT CALLBACK FUNCTIONS
  //***************************************************************************
  nex_page0.attachPush(nex_page0PushCallback);
  nex_page1.attachPush(nex_page1PushCallback);
  nex_page2.attachPush(nex_page2PushCallback);
  nex_page3.attachPush(nex_page3PushCallback);
  nex_but_stepback.attachPush(nex_but_stepbackPushCallback);
  nex_but_stepnxt.attachPush(nex_but_stepnxtPushCallback);
  nex_zyl_klemmblock.attachPush(nex_zyl_klemmblockPushCallback);
  nex_but_reset_cycle.attachPush(nex_but_reset_cyclePushCallback);
  nex_but_slider1_left.attachPush(nex_but_slider1_leftPushCallback);
  nex_but_slider1_right.attachPush(nex_but_slider1_rightPushCallback);
  nex_but_stepback.attachPush(nex_but_stepbackPushCallback);
  nex_but_stepnxt.attachPush(nex_but_stepnxtPushCallback);
  nex_switch_mode.attachPush(nex_switch_modePushCallback);
  nex_switch_play_pause.attachPush(nex_switch_play_pausePushCallback);
  nex_zyl_klemmblock.attachPush(nex_zyl_klemmblockPushCallback);
  nex_zyl_feder_zuluft.attachPush(nex_zyl_feder_zuluftPushCallback);
  nex_zyl_feder_abluft.attachPush(nex_zyl_feder_abluftPushCallback);
  nex_einschaltventil.attachPush(nex_einschaltventilPushCallback);

  //*****PUSH+POP:
  nex_zyl_wippenhebel.attachPush(nex_zyl_wippenhebelPushCallback);
  nex_zyl_wippenhebel.attachPop(nex_zyl_wippenhebelPopCallback);
  nex_mot_band_unten.attachPush(nex_mot_band_untenPushCallback);
  nex_mot_band_unten.attachPop(nex_mot_band_untenPopCallback);
  nex_zyl_schweisstaste.attachPush(nex_zyl_schweisstastePushCallback);
  nex_zyl_schweisstaste.attachPop(nex_zyl_schweisstastePopCallback);
  nex_zyl_messer.attachPush(nex_zyl_messerPushCallback);
  nex_zyl_messer.attachPop(nex_zyl_messerPopCallback);
  nex_but_reset_shorttime_counter.attachPush(nex_but_reset_shorttime_counterPushCallback);
  nex_but_reset_shorttime_counter.attachPop(nex_but_reset_shorttime_counterPopCallback);

  //***************************************************************************
  //END OF REGISTER
  //***************************************************************************
  delay(3000);
  sendCommand("page 1");  //SWITCH NEXTION TO PAGE X
  send_to_nextion();

}  //END OF NEXTION SETUP

//***************************************************************************
void nextion_loop()
//***************************************************************************
{ //START NEXTION LOOP

  nexLoop(nex_listen_list); //check for any touch event
  //***************************************************************************
  if (CurrentPage == 1)  //START PAGE 1
          {
    //*******************
    //PAGE 1 - LEFT SIDE:
    //*******************
    //UPDATE SWITCHSTATE "PLAY"/"PAUSE"
    if (nex_state_machine_running != machine_running) {
      Serial2.print("click bt0,1");    //CLICK BUTTON
      send_to_nextion();
      nex_state_machine_running = !nex_state_machine_running;
    }

    //UPDATE SWITCHSTATE "STEP"/"AUTO"-MODE

    if (step_mode != nex_prev_step_mode) {
      if (step_mode == true) {
        Serial2.print("click bt1,1");    //CLICK BUTTON
        send_to_nextion();
      } else {
        Serial2.print("click bt1,1");    //CLICK BUTTON
        send_to_nextion();
      }
      nex_prev_step_mode = step_mode;
    }

    //DISPLAY IF NO STRAP DETECTED
    if (nex_state_band_vorhanden != band_vorhanden) {
      if (band_vorhanden == false) {
        Serial2.print("t4.txt=");
        Serial2.print("\"");
        Serial2.print("BAND LEER!");
        Serial2.print("\"");
        send_to_nextion();
      } else {
        Serial2.print("t4.txt=");
        Serial2.print("\"");
        Serial2.print("");    //ERASE TEXT
        Serial2.print("\"");
        send_to_nextion();
      }
      nex_state_band_vorhanden = band_vorhanden;
    }

    if (band_vorhanden == true) {
      if (nex_prev_restpausenzeit != restpausenzeit)
        if (restpausenzeit > 0 && restpausenzeit < 1000) {
          Serial2.print("t4.txt=");
          Serial2.print("\"");
          Serial2.print("PAUSE: ");
          Serial2.print(restpausenzeit);    //SHOW REMAINING PAUSE TIME
          Serial2.print("s");

          Serial2.print("\"");
          send_to_nextion();
          nex_prev_restpausenzeit = restpausenzeit;
        } else {
          Serial2.print("t4.txt=");
          Serial2.print("\"");
          Serial2.print("");    //ERASE TEXT
          Serial2.print("\"");
          send_to_nextion();
        }
    }

    //*******************
    //PAGE 1 - RIGHT SIDE:
    //*******************
    //UPDATE CYCLE NAME
    if (nex_prev_cycle_step != cycle_step) {
      Serial2.print("t0.txt=");
      Serial2.print("\"");
      Serial2.print(cycle_name[cycle_step - 1]);
      Serial2.print("\"");
      send_to_nextion();
      nex_prev_cycle_step = cycle_step;
    }
    //UPDATE SWITCHBUTTON (dual state):
    if (zyl_feder_zuluft.request_state() != nex_state_zyl_feder_zuluft) {
      Serial2.print("click bt5,1");    //CLICK BUTTON
      send_to_nextion();
      nex_state_zyl_feder_zuluft = !nex_state_zyl_feder_zuluft;
    }
    //UPDATE SWITCHBUTTON (dual state):
    if (zyl_feder_abluft.request_state() != nex_state_zyl_feder_abluft) {
      Serial2.print("click bt4,1");    //CLICK BUTTON
      send_to_nextion();
      nex_state_zyl_feder_abluft = !nex_state_zyl_feder_abluft;
    }
    //UPDATE SWITCHBUTTON (dual state):
    if (zyl_klemmblock.request_state() != nex_state_zyl_klemmblock) {
      Serial2.print("click bt3,1");    //CLICK BUTTON
      send_to_nextion();
      nex_state_zyl_klemmblock = !nex_state_zyl_klemmblock;
    }

    //UPDATE BUTTON (momentary)
    if (zyl_wippenhebel.request_state() != nex_state_zyl_wippenhebel) {
      Serial2.print("click b5,");
      Serial2.print(zyl_wippenhebel.request_state());    //PUSH OR RELEASE BUTTON
      send_to_nextion();
      nex_state_zyl_wippenhebel = zyl_wippenhebel.request_state();
    }

    //UPDATE BUTTON (momentary)
    if (zyl_spanntaste.request_state() != nex_state_zyl_spanntaste) {
      Serial2.print("click b4,");
      Serial2.print(zyl_spanntaste.request_state());    //PUSH OR RELEASE BUTTON
      send_to_nextion();
      nex_state_zyl_spanntaste = zyl_spanntaste.request_state();
    }

    //UPDATE SWITCHBUTTON (dual state):
    if (zyl_messer.request_state() != nex_state_zyl_messer) {
      Serial2.print("click b6,");
      Serial2.print(zyl_messer.request_state());    //PUSH OR RELEASE BUTTON
      send_to_nextion();
      nex_state_zyl_messer = zyl_messer.request_state();
    }
    //UPDATE BUTTON (momentary)
    if (zyl_schweisstaste.request_state() != nex_state_zyl_schweisstaste) {
      Serial2.print("click b3,");
      Serial2.print(zyl_schweisstaste.request_state());    //PUSH OR RELEASE BUTTON
      send_to_nextion();
      nex_state_zyl_schweisstaste = zyl_schweisstaste.request_state();
    }

    //UPDATE BUTTON (momentary button used as dual state toggle)
    if (einschaltventil.request_state() != nex_state_einschaltventil) {
      Serial2.print("click bt6,1");    //CLICK BUTTON
      send_to_nextion();
      nex_state_einschaltventil = einschaltventil.request_state();
    }

  }    //END PAGE 1
       //***************************************************************************
  if (CurrentPage == 2)  //START PAGE 2
          {
    //*******************
    //PAGE 2 - LEFT SIDE
    //*******************

    if (nex_prev_startfuelldauer != startfuelldauer) {
      send_to_nextion();
      Serial2.print("t4.txt=");
      Serial2.print("\"");
      Serial2.print(startfuelldauer);
      Serial2.print(" ms");
      Serial2.print("\"");
      send_to_nextion();
      nex_prev_startfuelldauer = startfuelldauer;
    }

    if (nex_prev_federkraft_int != federkraft_int && millis() > nex_update_timer) {
      //update force:
      Serial2.print("h1.val=");
      Serial2.print(federkraft_int);
      send_to_nextion();

      Serial2.print("t6.txt=");
      Serial2.print("\"");
      Serial2.print(federkraft_int);
      Serial2.print(" N");
      Serial2.print("\"");
      send_to_nextion();
      nex_prev_federkraft_int = federkraft_int;

      //update pressure:
      Serial2.print("t8.txt=");
      Serial2.print("\"");
      Serial2.print(federdruck_float, 1);
      Serial2.print(" bar");
      Serial2.print("\"");
      send_to_nextion();
      nex_prev_federdruck = federdruck_float;

      nex_update_timer = millis() + 200;
    }

    //*******************
    //PAGE 2 - RIGHT SIDE
    //*******************

    if (nex_prev_longtime_counter != longtime_counter) {
      Serial2.print("t10.txt=");
      Serial2.print("\"");
      Serial2.print(longtime_counter);
      Serial2.print("\"");
      send_to_nextion();
      nex_prev_longtime_counter = longtime_counter;
    }
    if (nex_prev_shorttime_counter != shorttime_counter) {
      Serial2.print("t12.txt=");
      Serial2.print("\"");
      Serial2.print(shorttime_counter);
      Serial2.print("\"");
      send_to_nextion();
      nex_prev_shorttime_counter = shorttime_counter;
    }
    if (reset_stopwatch_active == true) {
      if (millis() - counter_reset_stopwatch > 5000) {
        shorttime_counter = 0;
        longtime_counter = 0;
      }
    }

  }    //END PAGE 2
       //***************************************************************************
}  //END OF NEXTION LOOP
//***************************************************************************

//***************************************************************************
//TOUCH EVENT FUNCTIONS //PushCallback = Press event //PopCallback = Release event
//***************************************************************************
//*************************************************
//TOUCH EVENT FUNCTIONS PAGE 1 - LEFT SIDE
//*************************************************
void nex_switch_play_pausePushCallback(void *ptr) {
  machine_running = !machine_running;
  if (machine_running == true) {
    clearance_next_step = true;
  }
  nex_state_machine_running = !nex_state_machine_running;
}
void nex_switch_modePushCallback(void *ptr) {
  step_mode = !step_mode;
  Serial2.print("click bt1,1");  //CLICK BUTTON
  send_to_nextion();
}
void nex_but_stepbackPushCallback(void *ptr) {
  if (cycle_step > 1) {
    cycle_step--;
    machine_running = false;
  }
}
void nex_but_stepnxtPushCallback(void *ptr) {
  if (cycle_step < 11) {
    cycle_step++;
    machine_running = false;
  }
}
void nex_but_reset_cyclePushCallback(void *ptr) {
  cycle_step = 1;
  step_mode = true;
}
//*************************************************
//TOUCH EVENT FUNCTIONS PAGE 1 - RIGHT SIDE
//*************************************************
void nex_zyl_feder_zuluftPushCallback(void *ptr) {
  zyl_feder_zuluft.toggle();
  nex_state_zyl_feder_zuluft = !nex_state_zyl_feder_zuluft;
}

void nex_zyl_feder_abluftPushCallback(void *ptr) {
  zyl_feder_abluft.toggle();
  nex_state_zyl_feder_abluft = !nex_state_zyl_feder_abluft;
}

void nex_zyl_klemmblockPushCallback(void *ptr) {
  zyl_klemmblock.toggle();
  nex_state_zyl_klemmblock = !nex_state_zyl_klemmblock;
}

void nex_zyl_wippenhebelPushCallback(void *ptr) {
  zyl_wippenhebel.set(1);
}

void nex_zyl_wippenhebelPopCallback(void *ptr) {
  zyl_wippenhebel.set(0);
}

void nex_mot_band_untenPushCallback(void *ptr) {
  zyl_spanntaste.set(1);
}
void nex_mot_band_untenPopCallback(void *ptr) {
  zyl_spanntaste.set(0);
}
void nex_zyl_schweisstastePushCallback(void *ptr) {
  zyl_schweisstaste.set(1);
}
void nex_zyl_schweisstastePopCallback(void *ptr) {
  zyl_schweisstaste.set(0);
}
void nex_zyl_messerPushCallback(void *ptr) {
  zyl_messer.set(1);
}
void nex_zyl_messerPopCallback(void *ptr) {
  zyl_messer.set(0);
}
void nex_einschaltventilPushCallback(void *ptr) {
  einschaltventil.toggle();
  nex_state_einschaltventil = !nex_state_einschaltventil;
}

//*************************************************
//TOUCH EVENT FUNCTIONS PAGE 2 - LEFT SIDE
//*************************************************

void nex_but_slider1_leftPushCallback(void *ptr) {

  startfuelldauer -= 500;
  if (startfuelldauer < 0) {
    startfuelldauer = 0;
  }
}

void nex_but_slider1_rightPushCallback(void *ptr) {
  startfuelldauer += 500;
  if (startfuelldauer > 7000) {
    startfuelldauer = 7000;
  }
}

//*************************************************
//TOUCH EVENT FUNCTIONS PAGE 2 - RIGHT SIDE
//*************************************************
void nex_but_reset_shorttime_counterPushCallback(void *ptr) {
  shorttime_counter = 0;
  //RESET LONGTIME COUNTER IF RESET BUTTON IS PRESSED LONG ENOUGH:
  counter_reset_stopwatch = millis();
  reset_stopwatch_active = true;
}

void nex_but_reset_shorttime_counterPopCallback(void *ptr) {
  reset_stopwatch_active = false;
}
//*************************************************
//TOUCH EVENT FUNCTIONS PAGE CHANGES
//*************************************************
void nex_page0PushCallback(void *ptr) {
  CurrentPage = 0;

}
void nex_page1PushCallback(void *ptr) {
  CurrentPage = 1;

  //REFRESH BUTTON STATES:
  nex_prev_cycle_step = 0;
  nex_prev_step_mode = true;

  nex_state_zyl_feder_zuluft = 0;
  nex_state_zyl_feder_abluft = 1;  //INVERTED VALVE LOGIC
  nex_state_zyl_klemmblock = 0;
  nex_state_zyl_wippenhebel = 0;
  nex_state_zyl_spanntaste = 0;
  nex_state_zyl_messer = 0;
  nex_state_zyl_schweisstaste = 0;
  nex_state_machine_running = 0;
  nex_state_band_vorhanden = !band_vorhanden;
  nex_state_einschaltventil = 0;
}

void nex_page2PushCallback(void *ptr) {
  CurrentPage = 2;
  //REFRESH BUTTON STATES:
  nex_prev_startfuelldauer = 0;
  nex_prev_shorttime_counter = 0;
  nex_prev_longtime_counter = 0;
  nex_prev_federkraft_int = 0;
  nex_prev_federdruck = 10000;
}

void nex_page3PushCallback(void *ptr) {
  CurrentPage = 3;
  //REFRESH BUTTON STATES:
  nex_prev_startfuelldauer = 0;
  nex_prev_shorttime_counter = 0;
  nex_prev_longtime_counter = 0;
}
//***************************************************************************
//END OF TOUCH EVENT FUNCTIONS
//***************************************************************************

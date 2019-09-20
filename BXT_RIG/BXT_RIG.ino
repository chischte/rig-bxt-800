
/*
 * *****************************************************************************
 * BXT_RIG
 * *****************************************************************************
 * Program to control a test rig
 * *****************************************************************************
 * Michael Wettstein
 * November 2018, Zürich
 * *****************************************************************************
 * https://github.com/chischte/bxt-rig
 * *****************************************************************************
 * TODO:
 * AUSSTEHENDE TASKS:
 * BANDVORSCHUBDAUER AUF DISPLAY EINSTELLBAR MACHEN
 * ZYKLEN/PAUSENSTEUERUNG AUF DISPLAY EINSTELLBAR MACHEN
 * *****************************************************************************
 */

#include <Cylinder.h>    // https://github.com/chischte/cylinder-library
#include <Nextion.h>     // https://github.com/itead/ITEADLIB_Arduino_Nextion 
#include <Timeout.h>     // https://github.com/chischte/timeout-library.git
#include <Controllino.h>

//=============================================================================
//
// EINSTELLPARAMETER FÜR TESTZYKLUS:
byte Zyklenanzahl = 4;//HIER ANZAHL ZYKLEN EINGEBEN // NACH DEM LETZTEN ZYKLUS FOLGT EINE PAUSE
unsigned long Pausenzeit = 300;//[s] HIER PAUSENZEIT IN SEKUNDEN EINGEBEN
int Bandvorschubdauer=7000;//[ms] HIER BANDVORSCHUBDAUER IN MILLISEKUNDEN EINGEBEN
//
//=============================================================================

//*****************************************************************************
// PRE-SETUP SECTION / PIN LAYOUT
//*****************************************************************************

// KNOBS AND POTENTIOMETERS:
#define start_button CONTROLLINO_A6
#define stop_button CONTROLLINO_A5
#define green_light CONTROLLINO_D9
#define red_light CONTROLLINO_D8

// SENSORS:
#define bandsensor_oben CONTROLLINO_A0
#define bandsensor_unten CONTROLLINO_A1
#define taster_startposition CONTROLLINO_A2
#define taster_endposition CONTROLLINO_A3
#define drucksensor CONTROLLINO_A7 // 0-10V = 0-12barg

// VALVES / MOTORS:
Cylinder einschaltventil(CONTROLLINO_D7);
Cylinder zyl_feder_abluft(CONTROLLINO_D1);
Cylinder zyl_feder_zuluft(CONTROLLINO_D0);
Cylinder zyl_klemmblock(CONTROLLINO_D2);
Cylinder zyl_wippenhebel(CONTROLLINO_D5);
Cylinder zyl_spanntaste(CONTROLLINO_D3);
Cylinder zyl_messer(CONTROLLINO_D6);
Cylinder zyl_schweisstaste(CONTROLLINO_D4);
Cylinder zyl_loescherblink(CONTROLLINO_D11);

//*****************************************************************************
// DECLARATION OF VARIABLES / DATA TYPES
//*****************************************************************************
// boolean (1/0 or true/false)
// byte (0-255)
// int   (-32,768 to 32,767) / unsigned int: 0 to 65,535
// long  (-2,147,483,648 to 2,147,483,647)
// float (6-7 Digits)
//*****************************************************************************
boolean machine_running = false;
boolean step_mode = true;
boolean clearance_next_step = false;
boolean error_blink = false;
boolean band_vorhanden = false;
boolean startposition_erreicht;
boolean endposition_erreicht;
boolean startfuellung_running = false;

byte Testzyklenzaehler;
byte cycle_step = 1;

int calmcounter;
unsigned long timer_next_step;

int startfuelldauer;
unsigned int federdruck_beruhigt;
unsigned int prev_federdruck_beruhigt;

unsigned long shorttime_counter;
unsigned long longtime_counter;

unsigned long restpausenzeit;
unsigned long timer_error_blink;
unsigned long runtime;
unsigned long runtime_stopwatch;
unsigned long startfuelltimer;
unsigned long prev_time;
long calmcountersum;

// DRUCKRECHNUNG:
float federdruck_float;
float federdruck_smoothed;
unsigned long federdruck_mbar;
unsigned int federdruck_mbar_int;

// KRAFTRECHNUNG:
float federkraft;
unsigned long federkraft_smoothed;
unsigned int federkraft_int;

//*****************************************************************************
//******************######**#######*#######*#******#*######********************
//*****************#********#**********#****#******#*#*****#*******************
//******************####****#####******#****#******#*######********************
//***********************#**#**********#****#******#*#*************************
//*****************######***######*****#*****######**#*************************
//*****************************************************************************
void setup() {

	Serial.begin(500000);//start serial connection

	nextion_setup();
	setup_eeprom_counter();

	pinMode(stop_button, INPUT);
	pinMode(start_button, INPUT);
	pinMode(bandsensor_oben, INPUT);
	pinMode(bandsensor_unten, INPUT);
	pinMode(taster_startposition, INPUT);
	pinMode(taster_endposition, INPUT);
	pinMode(drucksensor, INPUT);

	pinMode(green_light, OUTPUT);
	pinMode(red_light, OUTPUT);
	delay(2000);

	einschaltventil.set(1); //ÖFFNET DAS HAUPTLUFTVENTIL

	Serial.println("EXIT SETUP");

}//END MAIN SETUP

//*****************************************************************************
//********************#*********#####***#####***######*************************
//********************#********#*****#*#*****#**#*****#************************
//********************#********#*****#*#*****#**######*************************
//********************#********#*****#*#*****#**#******************************
//********************#######***#####***#####***#******************************
//*****************************************************************************

void loop() {

	read_n_toggle();
	lights();

	if (machine_running == true)
	{
		run_main_test_cycle();
	}

	nextion_loop();
	eeprom_counter();

	//runtime = millis() - runtime_stopwatch;
	//Serial.println(runtime);
	//runtime_stopwatch = millis();

}//END MAIN LOOP
//*****************************************************************************

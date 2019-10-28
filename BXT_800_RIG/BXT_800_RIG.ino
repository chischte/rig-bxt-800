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
 * Variablen umbenennen
 * Alle Schalter und Taster debouncen
 * Timer durch insomniatimer ersetzen
 * Globale Variablen minimieren
 * Kommentare und Anmerkungen an Style Guide anpassen und vereinheitlichen
 * Compiler Warnungen anschauen
 * Step/ Auto logik vereinfachen
 * Reset button soll auch Zylinder abstellen
 * Insomnia library timeout für main cycle verwenden
 * Restpausenzeit direkt von insomnia library abfragen.
 * Bug beheben auf Page 2 wird die bandvorschubdauer angezeigt oben rechts...
 * ...beim Wechsel von Seite 3 auf 2
 * IMPLEMENT NEW LOGIC FOR MAIN CYCLE:
 * run if: (autoMode && autoModeRunning) || (!autoMode && stepModeRunning)
 * *****************************************************************************
 */

#include <Cylinder.h>       // https://github.com/chischte/cylinder-library
#include <Nextion.h>        // https://github.com/itead/ITEADLIB_Arduino_Nextion
#include <Insomnia.h>       // https://github.com/chischte/insomnia-delay-library
#include <Controllino.h>    // https://github.com/CONTROLLINO-PLC/CONTROLLINO_Library
#include <EEPROM_Counter.h> // https://github.com/chischte/eeprom-counter-library

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

Insomnia errorBlinkTimer;

//*****************************************************************************
// DECLARATION OF VARIABLES / DATA TYPES
//*****************************************************************************
// bool (1/0 or true/false)
// byte (0-255)
// int   (-32,768 to 32,767) / unsigned int: 0 to 65,535
// long  (-2,147,483,648 to 2,147,483,647)
// float (6-7 Digits)
//*****************************************************************************
bool machine_running = false;
bool step_mode = true;
bool clearance_next_step = false;
bool error_blink = false;
bool band_vorhanden = false;
bool startposition_erreicht;
bool endposition_erreicht;
bool startfuellung_running = false;

//byte Testzyklenzaehler;
byte cycle_step = 0;

int calmcounter;
unsigned long timer_next_step;

unsigned int federdruck_beruhigt;
unsigned int prev_federdruck_beruhigt;

unsigned long restpausenzeit;
unsigned long timer_error_blink;
unsigned long runtime;
unsigned long runtime_stopwatch;
unsigned long startfuelltimer;
unsigned long prev_time;
long bandVorschubDauer;
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

// SET UP EEPROM COUNTER:
enum eepromCounter {
  startfuelldauer,
  shorttimeCounter,
  longtimeCounter,
  cyclesInARow,
  longCooldownTime,
  strapEjectFeedTime,
  endOfEepromEnum
};
int numberOfEepromValues = endOfEepromEnum;
int eepromMinAddress = 0;
int eepromMaxAddress = 4095;
EEPROM_Counter eepromCounter;

//*****************************************************************************
// DEFINE NAMES AND SEQUENCE OF STEPS FOR THE MAIN CYCLE:
//*****************************************************************************
enum mainCycleSteps {
  AUFWECKEN,
  VORSCHIEBEN,
  SCHNEIDEN,
  FESTKLEMMEN,
  STARTDRUCK,
  SPANNEN,
  SCHWEISSEN,
  ABKUEHLEN,
  ENTSPANNEN,
  WIPPENHEBEL,
  ZURUECKFAHREN,
  PAUSE,
  endOfMainCycleEnum
};

int numberOfMainCycleSteps = endOfMainCycleEnum;
// DEFINE NAMES TO DISPLAY ON THE TOUCH SCREEN:
String cycle_name[] = { "AUFWECKEN", "VORSCHIEBEN", "SCHNEIDEN", "FESTKLEMMEN", "STARTDRUCK",
    "SPANNEN", "SCHWEISSEN", "ABKUELHEN", "ENTSPANNEN", "WIPPENHEBEL", "ZURUECKFAHREN", "PAUSE" };

void SwitchToNextStep() {
  clearance_next_step = false;
  cycle_step++;
  if (cycle_step == numberOfMainCycleSteps) {
    cycle_step = 0;
  }
}

//*****************************************************************************
//******************######**#######*#######*#******#*######********************
//*****************#********#**********#****#******#*#*****#*******************
//******************####****#####******#****#******#*######********************
//***********************#**#**********#****#******#*#*************************
//*****************######***######*****#*****######**#*************************
//*****************************************************************************
void setup() {
  eepromCounter.setup(eepromMinAddress, eepromMaxAddress, numberOfEepromValues);
  Serial.begin(115200); //start serial connection

  nextion_setup();

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

} //END MAIN SETUP

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
  nextion_loop();

  // HIER NEUE LOGIK IMPLEMENTIEREN:
  // machineRunning = ((autoMode && autoModeRunning) || (stepMode && stepModeRunning)

  if (machine_running) {
    // HIER NEUE LOGIK IMPLEMENTIEREN:
    // if (machineRunning && nextStepTimer.timedOut)

    restpausenzeit = (timer_next_step - (millis() - prev_time)) / 1000; //[s]calculates remaining pause time for the display

    if (clearance_next_step && (millis() - prev_time) > timer_next_step) {

      switch (cycle_step) {

      case AUFWECKEN: // GERÄT AUFWECKEN (WIPPENHEBEL ZIEHEN):
        zyl_wippenhebel.stroke(1500, 1000);     //(Ausfahrzeit,Einfahrzeit)

        if (zyl_wippenhebel.stroke_completed()) {
          SwitchToNextStep();
        }
        break;

      case VORSCHIEBEN: // BAND VORSCHIEBEN:
        bandVorschubDauer = eepromCounter.getValue(strapEjectFeedTime) * 1000;
        zyl_spanntaste.stroke(bandVorschubDauer, 300);      //(Vorschubdauer,Pause)

        if (zyl_spanntaste.stroke_completed()) {
          SwitchToNextStep();
        }
        break;

      case SCHNEIDEN: // BAND SCHNEIDEN:
        zyl_messer.stroke(1500, 500);

        if (zyl_messer.stroke_completed()) {
          SwitchToNextStep();
        }
        break;

      case FESTKLEMMEN: // BAND IM KLEMMBLOCK FESTKLEMMEN:
        zyl_klemmblock.set(1);
        {
          prev_time = millis();
          timer_next_step = 500;
          SwitchToNextStep();
        }
        break;

      case STARTDRUCK: // STARTKRAFT AUFBAUEN:
        if (!startfuellung_running) {
          startfuellung_running = true;
          startfuelltimer = millis();
        }
        zyl_feder_zuluft.set(1); //1=füllen 0=geschlossen
        zyl_feder_abluft.set(1); //1=geschlossen 0=entlüften
        if ((millis() - startfuelltimer) > eepromCounter.getValue(startfuelldauer)) {
          zyl_feder_zuluft.set(0); //1=füllen 0=geschlossen
          startfuellung_running = false;
          SwitchToNextStep();
        }
        break;

      case SPANNEN: // BAND SPANNEN:
        zyl_spanntaste.set(1);      //Spanntaste betätigen
        if (endposition_erreicht) {
          prev_time = millis();
          timer_next_step = 500; //Spanntaste bleibt noch kurz betätigt, damit das Gerät die Maximalkraft aufbaut
          SwitchToNextStep();
        }
        break;

      case SCHWEISSEN: // BAND SCHWEISSEN:
        zyl_spanntaste.set(0);      //Spanntaste lösen
        zyl_schweisstaste.stroke(1000, 2000); //Schweisstaste betätigen

        if (zyl_schweisstaste.stroke_completed()) {
          SwitchToNextStep();
        }
        break;

      case ABKUEHLEN: // ZYLINDER ENTLÜFTEN und ABKÜHLEN:
        zyl_feder_zuluft.set(0); //1=füllen 0=geschlossen
        zyl_feder_abluft.set(0); //1=geschlossen 0=entlüften

        if (federdruck_float < 0.1) //warten bis der Druck ist abgebaut
                {
          SwitchToNextStep();
          prev_time = millis();
          timer_next_step = 4000; //Restluft kann entweichen
        }
        break;

      case ENTSPANNEN: // KLEMMBLOCK LöSEN:
        zyl_klemmblock.set(0);
        SwitchToNextStep();
        prev_time = millis();
        timer_next_step = 500;
        break;

      case WIPPENHEBEL: // BANDSPANNUNG LÖSEN:
        zyl_wippenhebel.stroke(1500, 1000);

        if (zyl_wippenhebel.stroke_completed()) {
          SwitchToNextStep();
        }
        break;

      case ZURUECKFAHREN: // BREMSZYLINDER ZURÜCKFAHREN:
        zyl_feder_zuluft.set(1);      // 1=füllen 0=geschlossen
        zyl_feder_abluft.set(0);      // 1=geschlossen 0=entlüften

        if (startposition_erreicht) {
          zyl_feder_zuluft.set(0);      // 1=füllen 0=geschlossen
          zyl_feder_abluft.set(0);      // 1=geschlossen 0=entlüften
          if (federdruck_float < 0.1) // warten bis der Druck abgebaut ist
                  {
            SwitchToNextStep();
            prev_time = millis();
            timer_next_step = 2000; // Restluft kann entweichen
            eepromCounter.countOneUp(shorttimeCounter);
            eepromCounter.countOneUp(longtimeCounter);
          }
        }
        break;

      case PAUSE: // Abkuehlpause
        static byte testZyklenZaehler;
        testZyklenZaehler++;
        if (testZyklenZaehler == eepromCounter.getValue(cyclesInARow)) {
          prev_time = millis();
          timer_next_step = eepromCounter.getValue(longCooldownTime) * 1000;  // Gerät kann abkühlen
          testZyklenZaehler = 0;
        }
        SwitchToNextStep();
        break;
      } //END switch (cycle_step)
    }
  }

  //runtime = millis() - runtime_stopwatch;
  //Serial.println(runtime);
  //runtime_stopwatch = millis();

}

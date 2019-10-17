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
 * Timer durch insomniatimer ersetzen
 * Globale Variablen minimieren
 * Kommentare und Anmerkungen an Style Guide anpassen und vereinheitlichen
 * Compiler Warnungen anschauen
 * Step/ Auto logik vereinfachen
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
int cycle_step = 1;

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
int eepromSize = 4096;
EEPROM_Counter eepromCounter(eepromSize, numberOfEepromValues);

void SwitchToNextStep() {
  clearance_next_step = false;
  cycle_step++;
}

//*****************************************************************************
//******************######**#######*#######*#******#*######********************
//*****************#********#**********#****#******#*#*****#*******************
//******************####****#####******#****#******#*######********************
//***********************#**#**********#****#******#*#*************************
//*****************######***######*****#*****######**#*************************
//*****************************************************************************
void setup() {

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

  if (machine_running) {
    restpausenzeit = (timer_next_step - (millis() - prev_time)) / 1000; //[s]calculates remaining pause time for the display

    if (clearance_next_step && millis() - prev_time > timer_next_step) {
      switch (cycle_step) {
      //***************************************************************************
      case 1: // GERÄT AUFWECKEN (WIPPENHEBEL ZIEHEN):
        //***************************************************************************
        zyl_wippenhebel.stroke(1500, 1000);     //(Ausfahrzeit,Einfahrzeit)

        if (zyl_wippenhebel.stroke_completed()) {
          SwitchToNextStep();
        }
        break;
        //***************************************************************************
      case 2: // BAND VORSCHIEBEN:
        //***************************************************************************
        unsigned long bandVorschubDauer = eepromCounter.getValue(strapEjectFeedTime);
        zyl_spanntaste.stroke(bandVorschubDauer, 300);      //(Vorschubdauer,Pause)

        if (zyl_spanntaste.stroke_completed()) {
          SwitchToNextStep();
        }
        break;
        //***************************************************************************
      case 3: // BAND SCHNEIDEN:
        //***************************************************************************
        zyl_messer.stroke(1500, 500);

        if (zyl_messer.stroke_completed()) {
          SwitchToNextStep();
        }
        break;
        //***************************************************************************
      case 4: // BAND IM KLEMMBLOCK FESTKLEMMEN:
        //***************************************************************************
        zyl_klemmblock.set(1);
        {
          prev_time = millis();
          timer_next_step = 500;
          SwitchToNextStep();
        }
        break;
        //***************************************************************************
      case 5: // STARTKRAFT AUFBAUEN:
        //***************************************************************************
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
        //***************************************************************************
      case 6: // BAND SPANNEN:
        //***************************************************************************
        zyl_spanntaste.set(1);      //Spanntaste betätigen
        if (endposition_erreicht) {
          prev_time = millis();
          timer_next_step = 500; //spanntaste bleibt noch kurz betätigt, damit das Gerät die Maximalkraft aufbaut
          SwitchToNextStep();
        }

        break;
        //***************************************************************************
      case 7: // BAND SCHWEISSEN:
        //***************************************************************************
        zyl_spanntaste.set(0);      //Spanntaste lösen
        zyl_schweisstaste.stroke(800, 0); //Schweisstaste betätigen

        if (zyl_schweisstaste.stroke_completed()) {
          SwitchToNextStep();
        }
        break;
        //***************************************************************************
      case 8: // ZYLINDER ENTLÜFTEN und ABKÜHLEN:
        //***************************************************************************
        zyl_feder_zuluft.set(0); //1=füllen 0=geschlossen
        zyl_feder_abluft.set(0); //1=geschlossen 0=entlüften

        if (federdruck_float < 0.1) //warten bis der Druck ist abgebaut
                {
          SwitchToNextStep();
          prev_time = millis();
          timer_next_step = 4000; //Restluft kann entweichen
        }
        break;
        //***************************************************************************
      case 9: // KLEMMBLOCK LöSEN:
        //***************************************************************************
        zyl_klemmblock.set(0);
        SwitchToNextStep();
        prev_time = millis();
        timer_next_step = 500;
        break;
        //***************************************************************************
      case 10: // BANDSPANNUNG LÖSEN:
        //***************************************************************************
        zyl_wippenhebel.stroke(1500, 1000);

        if (zyl_wippenhebel.stroke_completed()) {
          SwitchToNextStep();
        }
        break;
        //***************************************************************************
      case 11: // BREMSZYLINDER ZURÜCKFAHREN:
        //***************************************************************************
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
        //***************************************************************************
      case 12: // Abkuehlpause
        //***************************************************************************
        static byte testZyklenZaehler;
        testZyklenZaehler++;
        if (testZyklenZaehler == eepromCounter.getValue(cyclesInARow)) {
          prev_time = millis();
          timer_next_step = eepromCounter.getValue(longCooldownTime) * 1000;  // Gerät kann abkühlen
          testZyklenZaehler = 0;
        }
        SwitchToNextStep();
        cycle_step = 1;     // Testzyklus kann wieder von vorne beginnen
        break;
        //***************************************************************************
      } //END switch (cycle_step)
    }
  }

  //runtime = millis() - runtime_stopwatch;
  //Serial.println(runtime);
  //runtime_stopwatch = millis();

}

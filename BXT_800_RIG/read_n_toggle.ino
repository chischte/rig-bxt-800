int read_n_toggle() {

  //IN AUTO MODE, MACHINE RUNS FROM STEP TO STEP AUTOMATICALLY:
  if (step_mode == false)  //=AUTO MODE
          {
    clearance_next_step = true;
  }

  //IN STEP MODE, MACHINE STOPS AFTER EVERY COMPLETED CYCLYE:
  if (step_mode == true && clearance_next_step == false) {
    machine_running = false;
  }

  //START TEST RIG:
  if (digitalRead(start_button) == HIGH) {
    machine_running = true;
    clearance_next_step = true;
  }

  //STOP TEST_RIG:
  if (digitalRead(stop_button) == HIGH) {
    machine_running = false;
  }

  //BANDSENSOREN ABFRAGEN:

  if (digitalRead(bandsensor_oben) == HIGH && digitalRead(bandsensor_unten) == HIGH) {
    band_vorhanden = true;
    error_blink = false;
  } else {
    band_vorhanden = false;
    error_blink = true;
    clearance_next_step = false;
    machine_running = false;
  }

  //START- UND ENDPOSITIONSSCHALTER ABFRAGEN:
  startposition_erreicht = digitalRead(taster_startposition);
  endposition_erreicht = digitalRead(taster_endposition);

  //*****************************************************************************
  //READ PRESSURE SENSOR AND CALCULATE PRESSURE AND AIR-SPRING-FORCE:
  //DRUCKSENSOR 0-10V => 0-12bar
  //CONTROLLINO ANALOG INPUT VALUE 0-1023, 30mV per digit (controlino.biz)
  //10V   => analogRead 333.3 (10V/30mV)
  //12bar => anlaogRead 333.3
  //1bar  => analogRead 27.778

  federdruck_float = analogRead(drucksensor) / 27.778; //[bar]

  //SMOOTH VALUES:
  federdruck_smoothed = ((federdruck_smoothed * 4 + federdruck_float) / 5);
  //CONVERT TO INT AND [mbar]:
  federdruck_mbar_int = federdruck_smoothed * 1000; //[mbar]

  //CALM FUNCTION:
  //To prevent flickering, the pressure value will only be updated
  //if there's a higher or lower value five times in a row

  if (federdruck_mbar_int > federdruck_beruhigt) {
    if (calmcounter >= 0) {
      calmcounter++;
      calmcountersum = calmcountersum + federdruck_mbar_int;
    }
    if (calmcounter < 0)  //RESET CALMCOUNTER
            {
      calmcounter = 0;
      calmcountersum = 0;
    }
  }
  if (federdruck_mbar_int < federdruck_beruhigt) {
    if (calmcounter <= 0) {
      calmcounter--;
      calmcountersum = calmcountersum + federdruck_mbar_int;
    }
    if (calmcounter > 0) //RESET CALMCOUNTER
            {
      calmcounter = 0;
      calmcountersum = 0;
    }
  }
  if (abs(calmcounter) == 5) //abs()=> Absolutwert
          {
    //update value only if there is a significant difference to the previous value:
    if (abs(calmcountersum / abs(calmcounter) - prev_federdruck_beruhigt) > 50) {
      federdruck_beruhigt = calmcountersum / abs(calmcounter);
      prev_federdruck_beruhigt = federdruck_beruhigt;
    }
    calmcounter = 0;
    calmcountersum = 0;
  }

  //GO BACK TO FLOAT TO GET A "X.X bar" PRINT ON THE DISPLAY:

  federdruck_float = federdruck_beruhigt;
  federdruck_float = federdruck_float / 1000; //[bar]

  //CALCULATE FORCE:
  federkraft_int = federdruck_float * 1472.6; //1bar  => 1472.6N (Dauertest BXT 3-32 Zylinderkraft.xlsx)

  //SET LAST DIGIT ZERO
  federkraft_int = federkraft_int / 10;
  federkraft_int = federkraft_int * 10;

} //END OF READ_N_TOGGLE

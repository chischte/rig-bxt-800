void lights() {
  //*****************************************************************************
  //GREEN LIGHT:

  if (!step_mode)  //IN AUTOMATIC MODE THE GREEN LIGHT IS ON PERMANENTLY
          {
    if (machine_running) {
      digitalWrite((green_light), HIGH);
    } else {
      digitalWrite((green_light), LOW);
    }
  }

  if (step_mode)  //IN STEP MODE THE GREEN IS OFF BETWEEN STEPS
    if (machine_running == true && clearance_next_step == true) {
      digitalWrite((green_light), HIGH);
    } else {
      digitalWrite((green_light), LOW);
    }

  //*****************************************************************************
  //RED LIGHT / ERROR BLINKER:

  if (error_blink) {
    if (errorBlinkTimer.delayTimeUp(700)) {
      digitalWrite((red_light), !(digitalRead(red_light)));
    }
  } else {
    digitalWrite((red_light), LOW);
  }
  //*****************************************************************************
}  //END OF LIGHTS

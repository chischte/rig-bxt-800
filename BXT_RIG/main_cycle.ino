int run_main_test_cycle()
{
	restpausenzeit=(timer_next_step-(millis()-prev_time))/1000;//[s]calculates remaining pause time
	//restpausenzeit=500;
	if (clearance_next_step == true && millis() - prev_time > timer_next_step)
	{
		switch (cycle_step)
		{
			//***************************************************************************
		case 1://GERÄT AUFWECKEN (WIPPENHEBEL ZIEHEN)
		  //***************************************************************************
			zyl_wippenhebel.stroke(1500, 1000);//(Ausfahrzeit,Einfahrzeit)

			if (zyl_wippenhebel.stroke_completed() == true)
			{
				cycle_step++;
				clearance_next_step = false;
			}
			break;
			//***************************************************************************
		case 2://BAND VORSCHIEBEN
		  //***************************************************************************
			zyl_spanntaste.stroke(Bandvorschubdauer, 300);//(Vorschubdauer,Pause)

			if (zyl_spanntaste.stroke_completed() == true)
			{
				cycle_step++;
				clearance_next_step = false;
			}
			break;
			//***************************************************************************
		case 3://BAND SCHNEIDEN
		  //***************************************************************************
			zyl_messer.stroke(1500, 500);

			if (zyl_messer.stroke_completed() == true)
			{
				cycle_step++;
				clearance_next_step = false;
			}
			break;
			//***************************************************************************
		case 4://BAND IM KLEMMBLOCK FESTKLEMMEN
		  //***************************************************************************
			zyl_klemmblock.set(1);
			{
				prev_time = millis();
				timer_next_step = 500;
				clearance_next_step = false;
				cycle_step++;
			}
			break;
			//***************************************************************************
		case 5://STARTKRAFT AUFBAUEN
		  //***************************************************************************
			if (startfuellung_running == false)
			{
				startfuellung_running = true;
				startfuelltimer = millis();
			}
			zyl_feder_zuluft.set(1); //1=füllen 0=geschlossen
			zyl_feder_abluft.set(1);//1=geschlossen 0=entlüften
			if (millis() - startfuelltimer > startfuelldauer)
			{
				zyl_feder_zuluft.set(0); //1=füllen 0=geschlossen
				startfuellung_running = false;
				clearance_next_step = false;
				cycle_step++;
			}
			break;
			//***************************************************************************
		case 6://BAND SPANNEN
		  //***************************************************************************

		  //********
		  //HIER FALLS ERFORDERLICH REGELALGORITHMUS EINBAUEN
		  //********

			zyl_spanntaste.set(1);//Spanntaste betätigen
			if (endposition_erreicht == true)
			{
				prev_time = millis();
				timer_next_step = 500;//spanntaste bleibt noch kurz betätigt, damit das Gerät die Maximalkraft aufbaut
				clearance_next_step = false;
				cycle_step++;
			}

			break;
			//***************************************************************************
		case 7://BAND SCHWEISSEN
		  //***************************************************************************
			zyl_spanntaste.set(0);//Spanntaste lösen
			zyl_schweisstaste.stroke(800, 0); //Schweisstaste betätigen

			if (zyl_schweisstaste.stroke_completed() == true)
			{
				cycle_step++;
				clearance_next_step = false;
			}
			break;
			//***************************************************************************
		case 8://ZYLINDER ENTLÜFTEN und ABKÜHLEN
		  //***************************************************************************
			zyl_feder_zuluft.set(0); //1=füllen 0=geschlossen
			zyl_feder_abluft.set(0);//1=geschlossen 0=entlüften

			if (federdruck_float < 0.1) //warten bis der Druck ist abgebaut
			{
				cycle_step++;
				clearance_next_step = false;
				prev_time = millis();
				timer_next_step = 4000;//Restluft kann entweichen
			}
			break;
			//***************************************************************************
		case 9://KLEMMBLOCK LöSEN
		  //***************************************************************************
			zyl_klemmblock.set(0);
			cycle_step++;
			clearance_next_step = false;
			prev_time = millis();
			timer_next_step = 500;
			break;
			//***************************************************************************
		case 10://BANDSPANNUNG LÖSEN (zyl_wippenhebel)
		  //***************************************************************************
			zyl_wippenhebel.stroke(1500, 1000);

			if (zyl_wippenhebel.stroke_completed() == true)
			{
				cycle_step++;
				clearance_next_step = false;
			}
			break;
			//***************************************************************************
		case 11://BREMSZYLINDER ZURÜCKFAHREN
		  //***************************************************************************
			zyl_feder_zuluft.set(1);//1=füllen 0=geschlossen
			zyl_feder_abluft.set(0);//1=geschlossen 0=entlüften

			if (startposition_erreicht == true)
			{
				zyl_feder_zuluft.set(0);//1=füllen 0=geschlossen
				zyl_feder_abluft.set(0);//1=geschlossen 0=entlüften
				if (federdruck_float < 0.1) //warten bis der Druck abgebaut ist
				{
					cycle_step++;
					clearance_next_step = false;
					prev_time = millis();
					timer_next_step = 2000;//Restluft kann entweichen
					shorttime_counter++;
					longtime_counter++;
				}
			}
			break;
			//***************************************************************************
		case 12://Abkuehlpause
		  //***************************************************************************
			Testzyklenzaehler++;
			if (Testzyklenzaehler == Zyklenanzahl)
			{
				prev_time = millis();
				timer_next_step = Pausenzeit*1000;//Gerät kann abkühlen
				Testzyklenzaehler = 0;
			}
			cycle_step = 1;//Testzyklus kann wieder von vorne beginnen
			clearance_next_step = false;
			break;
			//***************************************************************************
		} //END switch (cycle_step)
	}
}//END MAIN TEST CYCLE

//PROGRAM TO STORE VALUES ON EEPROM
//Created by Michi, November 2018
//EEPROM size:4096 bytes ATmega2560.
//The EEPROM memory has a specified lifetime of 100,000 write/erase cycles
//THE STORAGE LOCATION WILL BE CHANGED AFTER 100,000 CYCLES
//Storage data Type unsigned long, 4Bytes, value range 0 to 4,294,967,295 (2^32 - 1).

//#include <avr/eeprom.h>

//*****************************************************************************
//STORAGE VARIABLES AND ADRESSES:
//*****************************************************************************
int STORELOCATION = 1; //after 100.000 writes a new STORELOCATION will be defined automatically.
//**********************************
//long will be stored to STORELOCATION+0/1/2/3
long eeprom_save_counter;
//**********************************
//int will be stored to adress STORELOCATION+4/5
//int startkraft;
int eeprom_prev_startfuelldauer;
//**********************************
//int will be stored to adress STORELOCATION+6/7
//int lower_feedtime;
//int eeprom_prev_lower_feedtime;
//**********************************
//long will be stored to STORELOCATION+8/9/10/11
//long shorttime_counter;
long eeprom_prev_shorttime_counter;
//**********************************
//long will be stored to STORELOCATION+12/13/14/15
//long longtime_counter;
long eeprom_prev_longtime_counter;
//*****************************************************************************

//*****************************************************************************
void setup_eeprom_counter()
//*****************************************************************************
{
  //FIND OUT WHERE THE VALUES ARE STORED:
  eeprom_read_block((void*)&STORELOCATION, (void*)0, sizeof(2)); // destination / source / size

  //READ STORED VALUES:
  eeprom_read_block((void*)&eeprom_save_counter, (void*)STORELOCATION, 4); // destination / source / size
  eeprom_read_block((void*)&startfuelldauer, (void*) (STORELOCATION + 4), 2);      // destination / source / size
  //eeprom_read_block((void*)&lower_feedtime, (void*)(STORELOCATION + 6), 2);   // destination / source / size
  eeprom_read_block((void*)&shorttime_counter, (void*)(STORELOCATION +  8), 4);  // destination / source / size
  eeprom_read_block((void*)&longtime_counter, (void*) (STORELOCATION + 13), 4); //// destination / source / size

}//END SETUP EEPROM_COUNTER
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
void eeprom_counter() {

  //*****************************************************************************
  //UPDATE CHANGED_VALUES:
  //*****************************************************************************
  if (eeprom_prev_startfuelldauer != startfuelldauer)
  {
    eeprom_write_block((void*)&startfuelldauer, (void*)(STORELOCATION + 4), 2); // source / destination / size
    eeprom_prev_startfuelldauer = startfuelldauer;
  }
  //********************************
  if (eeprom_prev_shorttime_counter != shorttime_counter)
  {
    eeprom_write_block((void*)&shorttime_counter, (void*)(STORELOCATION + 8), 4); // source / destination / size
    eeprom_prev_shorttime_counter = shorttime_counter;
  }
  //********************************
  if (eeprom_prev_longtime_counter != longtime_counter)
  {
    eeprom_write_block((void*)&longtime_counter, (void*)(STORELOCATION + 13), 4); // source / destination / size
    eeprom_prev_longtime_counter = longtime_counter;
    eeprom_save_counter++;
    eeprom_write_block((void*)&eeprom_save_counter, (void*)(STORELOCATION + 0), 4); // source / destination / size
  }
  //*****************************************************************************
  //IF STORELOCATION IS AT THE END OF LIFECYCLE, ASSIGN A NEW STORELOCATION //UPDATE NEW STORELOCATION
  //*****************************************************************************
  if (eeprom_save_counter >= 100000) //STORELOCATION IS AT THE END OF LIFECYCLE
  {
    STORELOCATION = STORELOCATION + 16; //ASSIGNS A NEW STORELOCATION
    if (STORELOCATION >= 1000)
    {
      STORELOCATION = 1;
    }
    eeprom_write_block((void*)&STORELOCATION, (void*)0, 2); // source / destination / size
    eeprom_save_counter = 0;
    eeprom_write_block((void*)&eeprom_save_counter, (void*)(STORELOCATION + 0), 4); // source / destination / size
    eeprom_write_block((void*)&startfuelldauer, (void*)(STORELOCATION + 4), 2); // source / destination / size
    eeprom_write_block((void*)&shorttime_counter, (void*)(STORELOCATION + 8), 4); // source / destination / size
    eeprom_write_block((void*)&longtime_counter, (void*)(STORELOCATION + 13), 4); // source / destination / size
  }
}//END EEPROM_COUNTER LOOP
//*****************************************************************************

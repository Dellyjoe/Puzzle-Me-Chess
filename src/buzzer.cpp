#include <Arduino.h>
#include <Buzzer.h>

//******************************************Setup******************************//
void Buzzer::init_buzzer(int pinnumber)
{ 
  buzzer_pin_number = pinnumber;
  pinMode(pinnumber,OUTPUT); // sets the digital pin pinnumber1 as Output
} // end init_buzzer

//*****************************************Functions***************************//
void Buzzer::write_buzzer()
{
  digitalWrite(buzzer_pin_number, HIGH);
} // end write_buzzer

void Buzzer::turn_off_buzzer()
{
  digitalWrite(buzzer_pin_number, LOW);
} // end turn_off_buzzer
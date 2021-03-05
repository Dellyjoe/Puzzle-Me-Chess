#include <Arduino.h>
#include <Buzzer.h>
#include <Define.h>

//******************************************Setup******************************//
void Buzzer::init_buzzer(int pinnumber)
{
  buzzer_pin_number = pinnumber;
  pinMode(buzzer_pin_number, OUTPUT); // sets the digital pin pinnumber1 as Output
} // end init_buzzer

//*****************************************Functions***************************//
void Buzzer::write_buzzer()
{
  digitalWrite(buzzer_pin_number, HIGH);

  if (test_code_buzzer == true)
  {
    Serial.println("Buzzer is on!");
  }
} // end write_buzzer

void Buzzer::turn_off_buzzer()
{
  digitalWrite(buzzer_pin_number, LOW);

  if (test_code_buzzer == true)
  {
    Serial.println("Buzzer is off");
  }
} // end turn_off_buzzer
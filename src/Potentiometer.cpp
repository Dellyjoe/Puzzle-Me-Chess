#include <Arduino.h>
#include <Potentiometer.h>
#include <Define.h>

//******************************************Setup******************************//
void Potentiometer::init_pot(int pinnumber, int low, int high)
{
  pot_pin_number = pinnumber;
  mapp_low = low;
  mapp_high = high;
  pinMode(pot_pin_number, INPUT); // pin A0 mapped to an INPUT --> r_pot
} // end init_pot

//*****************************************Functions***************************//
int Potentiometer::r_pot()
{
  int pot1 = analogRead(pot_pin_number);                 // private variable on pinnumber
  int potmap1 = map(pot1, 0, 1023, mapp_low, mapp_high); // map values
  
 //***************************************Test Code***************************//
 if (test_code_potentiometer == true)
 {
    Serial.println("Pot Vaule = ");
    Serial.println(potmap1);                             // print pot vaule in terminal 
    return (potmap1);
 } // end test_code_potentiometer == true
  return (potmap1);
} // end r_pot

void Potentiometer::disable_pot()
{
  pinMode(pot_pin_number, OUTPUT);
  digitalWrite(pot_pin_number,LOW);
} // end disable_pot
#include <Arduino.h>
#include <Potentiometer.h>

//*****************************************Functions**************************//
int Potentiometer::r_pot()
{
  int potmap1 = map(pot1, 0, 1023, 1, 3); // map values 1-3 
  return (potmap1);
} // end r_pot

void Potentiometer::init_pot()
{
  pinMode(0, INPUT); // pin A0 mapped to an INPUT --> r_pot 
} // end init_pot
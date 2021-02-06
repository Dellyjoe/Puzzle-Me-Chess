#include <Arduino.h>
#include <Potentiometer.h>

//*****************************************Functions**************************//
int Potentiometer::getpot1()
{
  int potmap1 = map(pot1, 0, 1023, 1, 10); // map values 1-10 to set timer length
  return (potmap1);
} // Close int getpot

int Potentiometer::getpot2()
{
  int potmap2 = map(pot2, 0, 1023, 0, 15); // map values 0-15 to set timer alarm
  return (potmap2);
} // Close int getpot

#include <Arduino.h>
#include <LED.h>

//******************************************Declare****************************//
#define CHARLIE_24 24 // pin number
#define CHARLIE_25 25
#define CHARLIE_26 26
#define CHARLIE_27 27
#define CHARLIE_28 28
#define CHARLIE_29 29
#define CHARLIE_30 30
#define CHARLIE_31 31
#define CHARLIE_32 32

//******************************************Setup******************************//
void LED::init_LED(){

  //******************************************Inputs***************************//
  pinMode(CHARLIE_24, OUTPUT);
  pinMode(CHARLIE_25, OUTPUT);
  pinMode(CHARLIE_26, OUTPUT);
  pinMode(CHARLIE_27, OUTPUT);
  pinMode(CHARLIE_28, OUTPUT);
  pinMode(CHARLIE_29, OUTPUT);
  pinMode(CHARLIE_30, OUTPUT);
  pinMode(CHARLIE_31, OUTPUT);
  pinMode(CHARLIE_32, OUTPUT);
  } // end init_LED

void LED::charlie(int LEDarry[] ) // ,int d, int e, int f, int g, int H,
{
  index = LEDarry[0]; // Starts at A

  if(index < 0){
    pinMode(CHARLIE_24, INPUT);
  } else {
    pinMode(CHARLIE_24, OUTPUT);
    digitalWrite(CHARLIE_24, index);
  }

  index = LEDarry[1];

   if(index < 0){
    pinMode(CHARLIE_25, INPUT);
  } else {
    pinMode(CHARLIE_25, OUTPUT);
    digitalWrite(CHARLIE_25, index);
  }

  index = LEDarry[2];

   if(index < 0){
    pinMode(CHARLIE_26, INPUT);
  } else {
    pinMode(CHARLIE_26, OUTPUT);
    digitalWrite(CHARLIE_26, index);
  }
} // end class charlie
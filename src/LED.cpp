#include <Arduino.h>
#include <LED.h>

//******************************************Declare****************************//
#define CHARLIE_A 24 // pin number
#define CHARLIE_B 25
#define CHARLIE_C 26

//******************************************Setup******************************//
void LED::init_LED(){

  //******************************************Inputs***************************//
  pinMode(CHARLIE_A, OUTPUT);
  pinMode(CHARLIE_B, OUTPUT);
  pinMode(CHARLIE_C, OUTPUT);

  }

void LED::charlie(int a, int b, int c ) // ,int d, int e, int f, int g, int H,
{
  if(a < 0){
    pinMode(CHARLIE_A, INPUT);
  } else {
    pinMode(CHARLIE_A, OUTPUT);
    digitalWrite(CHARLIE_A, a);
  }

   if(b < 0){
    pinMode(CHARLIE_B, INPUT);
  } else {
    pinMode(CHARLIE_B, OUTPUT);
    digitalWrite(CHARLIE_B, b);
  }

   if(c < 0){
    pinMode(CHARLIE_C, INPUT);
  } else {
    pinMode(CHARLIE_C, OUTPUT);
    digitalWrite(CHARLIE_C, c);
  }
}
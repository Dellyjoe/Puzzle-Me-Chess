#include <Arduino.h>
#include <LED.h>

//******************************************Declare****************************//
// #define CHARLIE_24 24 // pin number
// #define CHARLIE_25 25
// #define CHARLIE_26 26
// #define CHARLIE_27 27
// #define CHARLIE_28 28
// #define CHARLIE_29 29
// #define CHARLIE_30 30
// #define CHARLIE_31 31
// #define CHARLIE_32 32

#define LED_Channel_1 1 // pin number
#define LED_Channel_2 2
#define LED_Channel_3 3
#define LED_Channel_4 4
#define LED_Channel_5 5
#define LED_Channel_6 6

//******************************************Setup******************************//
void LED::init_LED(){

  //******************************************Inputs***************************//
  pinMode(LED_Channel_1, OUTPUT);
  pinMode(LED_Channel_2, OUTPUT);
  pinMode(LED_Channel_3, OUTPUT);
  pinMode(LED_Channel_4, OUTPUT);
  pinMode(LED_Channel_5, OUTPUT);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);

} // end init_LED

void LED::LED_on_off(int LEDarry[])
{

  pinMode(LED_Channel_1, LEDarry[0]);
  pinMode(LED_Channel_2, LEDarry[1]);
  pinMode(LED_Channel_3, LEDarry[2]);
  pinMode(LED_Channel_4, LEDarry[3]);
  pinMode(LED_Channel_5, LEDarry[4]);
  digitalWrite(LEDarry[5], HIGH);
  digitalWrite(LEDarry[6], LOW);
  delay(1);

} // end LED_on

// void LED::charlie(int LEDarry[] ) // ,int d, int e, int f, int g, int H,
// {
//   index = LEDarry[0]; // Starts at A

//   if(index < 0){
//     pinMode(CHARLIE_24, INPUT);
//   } else {
//     pinMode(CHARLIE_24, OUTPUT);
//     digitalWrite(CHARLIE_24, index);
//   }

//   index = LEDarry[1];

//    if(index < 0){
//     pinMode(CHARLIE_25, INPUT);
//   } else {
//     pinMode(CHARLIE_25, OUTPUT);
//     digitalWrite(CHARLIE_25, index);
//   }

//   index = LEDarry[2];

//    if(index < 0){
//     pinMode(CHARLIE_26, INPUT);
//   } else {
//     pinMode(CHARLIE_26, OUTPUT);
//     digitalWrite(CHARLIE_26, index);
//   }
//   delay(1); // adds 1ms delay to allow for caps to discharge
// } // end class charlie
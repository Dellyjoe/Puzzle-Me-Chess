#include <Arduino.h>
#include <LED.h>

//******************************************Declare****************************//
//******************Row****************// 
#define LED_Channel_1 1 // pin number
#define LED_Channel_2 2
#define LED_Channel_3 3
#define LED_Channel_4 4
#define LED_Channel_5 5
#define LED_Channel_6 6
#define LED_Channel_7 7
#define LED_Channel_8 8
//******************Col****************//
#define LED_Channel_9 9 // pin number
#define LED_Channel_10 10
#define LED_Channel_11 11
#define LED_Channel_12 12
#define LED_Channel_24 24
#define LED_Channel_25 25
#define LED_Channel_26 26
#define LED_Channel_27 27

//******************************************Setup******************************//
void LED::init_LED(){
  pinMode(LED_Channel_1, OUTPUT);
  pinMode(LED_Channel_2, OUTPUT);
  pinMode(LED_Channel_3, OUTPUT);
  pinMode(LED_Channel_4, OUTPUT);
  pinMode(LED_Channel_5, OUTPUT);
  pinMode(LED_Channel_6, OUTPUT);
  pinMode(LED_Channel_7, OUTPUT);
  pinMode(LED_Channel_8, OUTPUT);
  pinMode(LED_Channel_9, OUTPUT);
  pinMode(LED_Channel_10, OUTPUT);
  pinMode(LED_Channel_11, OUTPUT);
  pinMode(LED_Channel_12, OUTPUT);
  pinMode(LED_Channel_24, OUTPUT);
  pinMode(LED_Channel_25, OUTPUT);
  pinMode(LED_Channel_26, OUTPUT);
  pinMode(LED_Channel_27, OUTPUT);

  digitalWrite(LED_Channel_1, HIGH);
  digitalWrite(LED_Channel_2, HIGH);
  digitalWrite(LED_Channel_3, HIGH);
  digitalWrite(LED_Channel_4, HIGH);
  digitalWrite(LED_Channel_5, HIGH);
  digitalWrite(LED_Channel_6, HIGH);
  digitalWrite(LED_Channel_7, HIGH);
  digitalWrite(LED_Channel_8, HIGH);
  digitalWrite(LED_Channel_9, HIGH);
  digitalWrite(LED_Channel_10, HIGH);
  digitalWrite(LED_Channel_11, HIGH);
  digitalWrite(LED_Channel_12, HIGH);
  digitalWrite(LED_Channel_24, HIGH);
  digitalWrite(LED_Channel_25, HIGH);
  digitalWrite(LED_Channel_26, HIGH);
  digitalWrite(LED_Channel_27, HIGH);

} // end init_LED

void LED::LED_on_off(int LEDarry[])
{

  pinMode(LED_Channel_1, LEDarry[0]);
  pinMode(LED_Channel_2, LEDarry[1]);
  pinMode(LED_Channel_3, LEDarry[2]);
  pinMode(LED_Channel_4, LEDarry[3]);
  pinMode(LED_Channel_5, LEDarry[4]);
  pinMode(LED_Channel_6, LEDarry[5]);
  pinMode(LED_Channel_7, LEDarry[6]);
  pinMode(LED_Channel_8, LEDarry[7]);
  pinMode(LED_Channel_9, LEDarry[8]);
  pinMode(LED_Channel_10, LEDarry[9]);
  pinMode(LED_Channel_11, LEDarry[10]); 
  pinMode(LED_Channel_12, LEDarry[11]);
  pinMode(LED_Channel_24, LEDarry[12]);
  pinMode(LED_Channel_25, LEDarry[13]);
  pinMode(LED_Channel_26, LEDarry[14]);
  pinMode(LED_Channel_27, LEDarry[15]);
  
  digitalWrite(LEDarry[16], HIGH);
  digitalWrite(LEDarry[17], LOW);
  delay(1);

} // end LED_on_off
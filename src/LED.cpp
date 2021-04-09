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

void LED::test_all_LEDs ()
{
  LED_on_off(LEDA1); delay(500); LED_on_off(LEDA2); delay(500); LED_on_off(LEDA3); delay(500); LED_on_off(LEDA4); delay(500); 
  LED_on_off(LEDA5); delay(500); LED_on_off(LEDA6); delay(500); LED_on_off(LEDA7); delay(500); LED_on_off(LEDA8); delay(500);

  LED_on_off(LEDB1); delay(500); LED_on_off(LEDB2); delay(500); LED_on_off(LEDB3); delay(500); LED_on_off(LEDB4); delay(500); 
  LED_on_off(LEDB5); delay(500); LED_on_off(LEDB6); delay(500); LED_on_off(LEDB7); delay(500); LED_on_off(LEDB8); delay(500);

  LED_on_off(LEDC1); delay(500); LED_on_off(LEDC2); delay(500); LED_on_off(LEDC3); delay(500); LED_on_off(LEDC4); delay(500); 
  LED_on_off(LEDC5); delay(500); LED_on_off(LEDC6); delay(500); LED_on_off(LEDC7); delay(500); LED_on_off(LEDC8); delay(500);

  LED_on_off(LEDD1); delay(500); LED_on_off(LEDD2); delay(500); LED_on_off(LEDD3); delay(500); LED_on_off(LEDD4); delay(500); 
  LED_on_off(LEDD5); delay(500); LED_on_off(LEDD6); delay(500); LED_on_off(LEDD7); delay(500); LED_on_off(LEDD8); delay(500);

  LED_on_off(LEDE1); delay(500); LED_on_off(LEDE2); delay(500); LED_on_off(LEDE3); delay(500); LED_on_off(LEDE4); delay(500); 
  LED_on_off(LEDE5); delay(500); LED_on_off(LEDE6); delay(500); LED_on_off(LEDE7); delay(500); LED_on_off(LEDE8); delay(500);

  LED_on_off(LEDF1); delay(500); LED_on_off(LEDF2); delay(500); LED_on_off(LEDF3); delay(500); LED_on_off(LEDF4); delay(500); 
  LED_on_off(LEDF5); delay(500); LED_on_off(LEDF6); delay(500); LED_on_off(LEDF7); delay(500); LED_on_off(LEDF8); delay(500);

  LED_on_off(LEDG1); delay(500); LED_on_off(LEDG2); delay(500); LED_on_off(LEDG3); delay(500); LED_on_off(LEDG4); delay(500); 
  LED_on_off(LEDG5); delay(500); LED_on_off(LEDG6); delay(500); LED_on_off(LEDG7); delay(500); LED_on_off(LEDG8); delay(500);

  LED_on_off(LEDH1); delay(500); LED_on_off(LEDH2); delay(500); LED_on_off(LEDH3); delay(500); LED_on_off(LEDH4); delay(500); 
  LED_on_off(LEDH5); delay(500); LED_on_off(LEDH6); delay(500); LED_on_off(LEDH7); delay(500); LED_on_off(LEDH8); delay(1000);
} // end test_all_LEDs
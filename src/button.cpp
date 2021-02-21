#include <Arduino.h> 
#include <Button.h>

void Button::init_button()
{
pinMode(1, INPUT_PULLUP); // sets the digital pin 1 as input
} // end init_button

int Button::r_button()
{
buttonstate1 = digitalRead(button1);
// if (digitalRead(buttonstate1) == HIGH) {
//     Serial.println("Button is not pressed...");
//   } else {
//     Serial.println("Button pressed!!!");
//   }
return (buttonstate1);
} // end r_button
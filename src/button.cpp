#include <Arduino.h>
#include <Button.h>

//******************************************Setup******************************//
void Button::init_button(int pinnumber)
{
  button_pin_number = pinnumber;
  pinMode(pinnumber, INPUT); // sets the digital pin pinnumber1 as input
} // end init_button

//*****************************************Functions***************************//
int Button::r_button()
{
  buttonstate = digitalRead(button_pin_number);
  // if (buttonstate == HIGH)
  // {
  //   Serial.println("Button is not pressed...");
  // }
  // else
  // {
  //   Serial.println("Button pressed!");
  // }
  return (buttonstate);
} // end r_button
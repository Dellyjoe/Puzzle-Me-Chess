#include <Arduino.h>
#include <Button.h>
#include <Define.h>

//******************************************Setup******************************//
void Button::init_button(int pinnumber)
{
  button_pin_number = pinnumber;
  pinMode(button_pin_number, INPUT); // sets the digital pin pinnumber1 as input
} // end init_button

//*****************************************Functions***************************//
int Button::r_button()
{
  buttonstate = digitalRead(button_pin_number);
  //***************************************Test Code***************************//
  if (test_code_button == true)
  {
    if (buttonstate == HIGH)
    {
      Serial.println("Button is not pressed...");
      return (buttonstate);
    }
    else
    {
      Serial.println("Button pressed!");
      return (buttonstate);
    }
  }
} // end r_button
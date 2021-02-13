#include <Arduino.h> 
#include <Button.h>

void Button::init_button()
{
pinMode(2, INPUT); // sets the digital pin 0 as input
} // end init_button

int Button::r_button()
{
int buttonstate1 = 1; 
buttonstate1 = digitalRead(button1);
return (buttonstate1);
} // end r_button
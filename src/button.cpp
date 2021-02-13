#include <Arduino.h> 
#include <Button.h>

void Button::initbutton()
{
    pinMode(2, INPUT);    // sets the digital pin 0 as input

}


int Button::r_button()
{
int buttonstate1 = 0; 
buttonstate1 = digitalRead(button1);
Serial.print(buttonstate1);
delay(2000);
return (buttonstate1);
}
#include <Arduino.h>
#include <Switch.h>

//******************************************Setup******************************//
void Switch::init_switch(int pinnumber)
{
    switch_pin_number = pinnumber;
    pinMode(pinnumber, INPUT);
} // end init_switch

//*****************************************Functions***************************//
int Switch::r_switch()
{
    switchstate = digitalRead(switch_pin_number);
    // if (switchstate == HIGH)
    // {
    //     Serial.println("Switch is On!"); // switch to left = High
    // }
    // else
    // {
    //     Serial.println("Switch Off"); // switch to Right = Low
    // }
     return (switchstate);
} // end r_switch
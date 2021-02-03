// Programmer: Joseph __Vitale
// Start Date: 02/08/2021
// Completion Date: 05/10/2021
// Create a physical chess puzzle on a chess board. This board will
// have user checkability and software mapped defined chess puzzles.
// At first there will be 3 different chess puzzles ranging from easy
// to hard. There will be an OLED screen to show the user where to put
// the prices to set up the chess puzzle. This project will also have
// a feature to show user hint or show asnwer. After completing the
// puzzle a sound will play to tell the user he/she has completed the puzzle.

#include <Arduino.h>
#include <Potentiometer.h>
#include <OLED_RTC.h>
#include <timer.h>
#include <avr/io.h>        // interrupt
#include <avr/interrupt.h> // interrupt

//******************************************Declare*****************************//
Timerhour Timerhour0;      // Setting Object 0 for Timer12hour0
OLED OLED0;                // Setting Object 0 for OLED
struct timeralarmpara tap; // Struct Declare for timeralarmpara

//******************************************Setup*****************************//
void setup()
{

  Timerhour0.setuptimer();
  OLED0.intdisplay();
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  attachInterrupt(digitalPinToInterrupt(0), OLEDflag, HIGH);       // Setting interrupt pin D0
  attachInterrupt(digitalPinToInterrupt(1), SendValuesflag, HIGH); // Setting interrupt pin D1
  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP); // Below is setting alarm funtion

  attachInterrupt(digitalPinToInterrupt(2), alarm_now, LOW); // setting interrupt pin D2
} // end setup

void loop()
{
  OLED0.OLEDdraw(Timerhour0.timer(tap), Timerhour0.getRelayString());
  // map Timerhour0.timer(Tap) return to currenttimer , map Timerhour0.getRelayString() return to Relaystring
  Timerhour0.timer(tap);
} //end void loop
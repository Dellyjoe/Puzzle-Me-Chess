// Programmer: Joseph __Vitale
// Start Date: 02/08/2021
// Completion Date: 05/10/2021
// Create a physical chess puzzle on a chess board. This board will
// have user checkability and software mapped defined chess puzzles.
// At first there will be 3 different chess puzzles ranging from easy
// to hard. There will be an OLED screen to show the user where to put
// the prices to set up the chess puzzle. This project will also have
// a feature to show user hint or show asnwer. After completing the
// puzzle a sound will play to tell the user has completed the puzzle.

#include <Arduino.h>
#include <Potentiometer.h>
#include <Display.h>
#include <avr/io.h>        // interrupt
#include <avr/interrupt.h> // interrupt
#include <SDcard.h> 

//******************************************Declare****************************//
Display Display0; // Setting Object 0 for OLED
SDCARD SDCARD0; // setting object 0 for SDReader
Potentiometer Potentiometer1;
//******************************************Setup******************************//
void setup()
{
  Display0.intdisplay();
  SDCARD0.intSDReader();
  SDCARD0.openread();
//******************************************Inputs*****************************//
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  //****************************************Interrputs*************************//
  attachInterrupt(digitalPinToInterrupt(0), OLEDflag, HIGH); // Setting interrupt pin D0
  //pinMode(2, INPUT_PULLUP); // Input for Blue Botton 
} // end setup

void loop()
{
  Display0.OLEDdraw(Potentiometer1.getpot1());
} //end void loop
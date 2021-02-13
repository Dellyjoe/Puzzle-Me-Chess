//*************************************************************************
// Programmer: Joseph __Vitale                                            *
// Start Date: 02/08/2021                                                 *
// Completion Date: 05/10/2021                                            *
// Create a physical chess puzzle on a chess board. This board will       *
// have user checkability and software mapped defined chess puzzles.      *
// At first there will be 3 different chess puzzles ranging from easy     *
// to hard. There will be an OLED screen to show the user where to put    *
// the prices to set up the chess puzzle. This project will also have     *
// a feature to show user hint or show asnwer. After completing the       *
// puzzle a sound will play to tell the user has completed the puzzle.    *
//*************************************************************************
#include <Arduino.h>
#include <Potentiometer.h>
#include <Display.h>
#include <avr/io.h>        // interrupt
#include <avr/interrupt.h> // interrupt
#include <SDcard.h> 
#include <Button.h>

//******************************************Declare****************************//
Display Display0; // Setting Object 0 for OLED
SDCARD SDCARD0; // Setting object 0 for SDReader
Button Button0; // Setting object 0 for Button
//******************************************Setup******************************//
void setup()
{
  Display0.int_display();
  SDCARD0.int_SD();
  SDCARD0.open();
//******************************************Inputs*****************************//
  Button0.initbutton(); //setting A0 to button
  pinMode(0, INPUT); // pin A0 mapped to an INPUT --> r_pot 
  //pinMode(1, INPUT);
  //****************************************Interrputs*************************//
  // attachInterrupt(digitalPinToInterrupt(0), OLEDflag, HIGH); // Setting interrupt pin D0
  //pinMode(2, INPUT_PULLUP); // Input for Blue Botton 
} // end setup

void loop()
{
Button Button1;
Button1.r_button();
//Button0.buttonstate = digitalRead(button1);

  // while (buttonstate ==0)
  // {
  // Potentiometer Potentiometer1; // moved from declare b/c I need to pull value continuous
  // Display0.print(45, 30, Potentiometer1.r_pot() );

  // }

  // you need to add a while loop that is ture is the button is not pressed which will show select 
  //puzzle and then allow you to use the pot to select which puzzle you want.
  // after selecting the puzzle hitting the butotn will send the code to exit this loop and move on
  // to mapping the vaule to the sd card. 

} //end void loop
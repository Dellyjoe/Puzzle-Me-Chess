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
Display Display0; // Setting Object 0 for Display
SDcard SDcard0; // Setting object 0 for SDcard
Button Button0; // Setting object 0 for Button
Potentiometer Potentiometer0; // Setting oject 0 for P
//******************************************Setup******************************//
void setup()
{
  Display0.int_display();
  SDcard0.int_SD();
  //SDcard0.open();
//******************************************Inputs*****************************//
  Button0.init_button(); //setting D0 to button
  Potentiometer0.init_pot(); // setting A0 to pot
} // end setup

void loop()
{
//******************************************Declare****************************//
Button Button1;
Potentiometer Potentiometer2;
Display Display1;

//***************************************Start of Code*************************//
// do {
//   Potentiometer Potentiometer1; // moved from declare b/c I need to pull value continuous
//   Display1.print_select_puzzle(45, 30, Potentiometer1.r_pot());
// } while (Button1.r_button() == 1);
while (Button1.r_button() == 1)
{
  Potentiometer Potentiometer1; // moved from declare b/c I need to pull value continuous
  Display0.print_select_puzzle(45, 30, Potentiometer1.r_pot());
}
  Display1.print_user_puzzle(45,30, Potentiometer2.r_pot());
  // you need to add a while loop that is ture is the button is not pressed which will show select 
  //puzzle and then allow you to use the pot to select which puzzle you want.
  // after selecting the puzzle hitting the butotn will send the code to exit this loop and move on
  // to mapping the vaule to the sd card. 

} //end void loop
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
#include <SDcard.h> 
#include <Button.h>

//******************************************Declare****************************//
Display Display0; // Setting Object 0 for Display
SDcard SDcard0; 
Button Button0;
Potentiometer Potentiometer0; 
//******************************************Setup******************************//
void setup()
{
  Display0.int_display();
  SDcard0.int_SD();
 // SDcard0.print_SD_info(); //uncomment to print SD info
  SDcard0.printfiles();
  Serial.begin(9600);
//******************************************Inputs*****************************//
  Button0.init_button(); //setting D0 to button
  Potentiometer0.init_pot(0, 1,3); // setting A0 to pot
} // end setup

void loop()
{
//***************************************Start of Code*************************//

while (Button0.r_button() == 1)
 {
  Display0.clear();
  Display0.print_select_puzzle(45, 30, Potentiometer0.r_pot());
  Display0.draw();
 }

  delay(1000); //--> to allow for button press

  Display0.clear();
  Display0.print_user_puzzle(0,30, Potentiometer0.r_pot());
  Display0.draw();
  
  SDcard0.openfile();

  delay(5000);

// change the open and close on the SDcard methods
// make an if funtion that pulls out the 1-3 vaule on the pot and opens that file to that number
// after selecting the puzzle hitting the butotn will send the code to exit this loop and move on
// to mapping the vaule to the sd card. 

} //end void loop
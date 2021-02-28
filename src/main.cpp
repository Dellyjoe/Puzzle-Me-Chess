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
#include <Switch.h>
#include <LED.h>
#include <Charlieplex.h>

//******************************************Declare****************************//
Display Display0; // Setting Object 0 for Display
SDcard SDcard0;
Button Button0;
Potentiometer Potentiometer0;
Switch Switch0;
LED LED0;
//*************************************Charlieplexing_Declare******************//
#define NUMBER_OF_PINS 3
byte pins[] = {24,25,26}; // 0 , 1 , 2
Charlieplex charlieplex = Charlieplex(pins,NUMBER_OF_PINS);
//individual 'pins' , address charlieplex pins as you would address an array
charliePin led1 = { 0 , 1}; //led1 is indicated by current flow from 24 to 25
charliePin led2 = { 1 , 2 };
charliePin led3 = { 0 , 2 };
charliePin led4 = { 1 , 0 };
charliePin led5 = { 2 , 1 };
charliePin led6 = { 2 , 0 };
boolean singleOn = false;

//******************************************Setup******************************//
void setup()
{
  Display0.int_display();
  SDcard0.int_SD();
  //SDcard0.print_SD_info(); //uncomment to print SD info
  SDcard0.print_directory();
  Serial.begin(9600);
  //******************************************Inputs***************************//
  Button0.init_button(1);           //setting D1 to button
  Potentiometer0.init_pot(0, 1, 3); // setting A0 to pot
  Switch0.init_switch(0);           // seeting D0 to switch
} // end setup


void loop()
{
  //***************************************Test Code***************************//
  // Potentiometer0.r_pot();
  // Button0.r_button();
  // Switch0.r_switch();
  //***************************************Start of Code***********************//

  while (Button0.r_button() == HIGH)
  {
    Display0.clear();
    Display0.print_select_puzzle(45, 30, Potentiometer0.r_pot());
    Display0.draw();
  }

  delay(1000); //--> to allow for button press

  Display0.clear();
  Display0.print_user_puzzle(58, 43, Potentiometer0.r_pot());
  Display0.draw();

  switch (Potentiometer0.r_pot())
  {
  case 1:
  
    Serial.println("Opening File 1015704.CSV"); // prints index 0 in const char array
    Serial.println("___________________");      // line breakup for readability
    SDcard0.open_file(0);                       // Open File indexer 0
    Serial.println("___________________"); 
    break;
  case 2:
    Serial.println("Opening File 561534.CSV");
    Serial.println("___________________");
    SDcard0.open_file(1);
    Serial.println("___________________");
    break;
  case 3:
    Serial.println("Opening File 1036958.CSV");
    Serial.println("___________________"); 
    SDcard0.open_file(2);
    Serial.println("___________________");
    break;
  }

  while (Button0.r_button() == HIGH)
  {
    LED0.charlie(HIGH,LOW, -1); // -1 = setting pin to input
    delay(1);
    // charlie(LOW,HIGH, -1);
    // delay(1);
    // charlie(HIGH,-1, LOW);
    // delay(1);
    LED0.charlie(LOW,-1, HIGH);
    delay(1);
    // charlie(-1,HIGH, LOW);
    // delay(1);
    // charlie(-1,LOW, HIGH);
    // delay(1);
  }
charlieplex.clear(); // turning off all LEDs
delay(1000); // allow for button press

  // look into making a grid for the board that will use your Muxltiplexers
  // to turn on or off leds and also read in voltage levels
  // look into maybe just using a 1d arry, instead of a 2d arry --> this might be easier in the long run

  // change the open and close on the SDcard methods
  // make an if funtion that pulls out the 1-3 vaule on the pot and opens that file to that number
  // after selecting the puzzle hitting the butotn will send the code to exit this loop and move on
  // to mapping the vaule to the sd card.
} //end void loop
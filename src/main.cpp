//*****************************************************************************//
// Programmer: Joseph __Vitale                                                 //
// Start Date: 02/08/2021                                                      //
// Phase #1 Completion Date:                                                   //
// Create a physical chess puzzle on a chess board. This board will            //
// have user checkability and software mapped defined chess puzzles.           //
// At first there will be 3 different chess puzzles ranging from easy          //
// to hard. There will be an OLED screen to show the user where to put         //
// the prices to set up the chess puzzle. This project will also have          //
// a feature to show user hint or show asnwer. After completing the            //
// puzzle a sound will play to tell the user has completed the puzzle.         //
//*****************************************************************************//
#include <Arduino.h>
#include <Define.h>
#include <Display.h>
#include <SDcard.h>
#include <Button.h>
#include <Potentiometer.h>
#include <Buzzer.h>
#include <Switch.h>
#include <LED.h>
#include <Mulitiplexer.h>

//******************************************Declare****************************//
Display Display0; // Setting Object 0 for Display
SDcard SDcard0;
Button Button0;
Potentiometer Potentiometer0;
Buzzer Buzzer0;
Switch Switch0;
LED LED0;
Mulitiplexer Mulitiplexer0;

//******************************************Setup******************************//
void setup()
{
  Display0.int_display();
  SDcard0.int_SD();
  //SDcard0.print_SD_info(); //uncomment to print SD info
  SDcard0.print_directory();
  Serial.begin(9600);
  SDcard0.readchesspuzzle();
  //******************************************Inputs***************************//
  Button0.init_button(22);                                       // setting D1 to button
  Potentiometer0.init_pot(23, 1, 3);                             // setting A9 to pot/Enabling pot
  Switch0.init_switch(21);                                       // seeting D0 to switch
  Mulitiplexer0.init_muxs_input(37, 38, 39, 39, 13, 14, 15, 16); 
  //******************************************Outputs**************************//
  Buzzer0.init_buzzer(21);                    // setting A1 to buzzer
  Mulitiplexer0.init_muxs_output(35, 34, 33); // setting output channels s1 = a, s2 = b, s3 = c
  Mulitiplexer0.init_enable(36);
  LED0.init_LED(); 
  
} // end setup

void loop()
{
  // //***************************************Test Code***************************//
  if (test_code == true)
  {
    if (test_code_potentiometer == true)
    {
     Potentiometer0.r_pot();
    }

    if (test_code_button == true)
    {
     Button0.r_button();
    }

    if (test_code_switch == true)
    {
     Switch0.r_switch();
    }

    if (test_code_mulitiplexer_channel == true)
    {
     Mulitiplexer0.set_enable(0);
    }
    
     while ((Button0.r_button() == HIGH) & (test_code_buzzer == true))
      {
        Buzzer0.write_buzzer();
        delay(1000);
        Buzzer0.turn_off_buzzer();
        delay(1000);
      }
      Buzzer0.turn_off_buzzer();

      delay(1000);//--> to allow for button press

    if (test_code_LED == true)
    {
      LED0.LED_on_off(LED0.LEDG1);
      delay(1000);
      LED0.LED_on_off(LED0.LEDG2);
      delay(1000);
      LED0.LED_on_off(LED0.LEDG3);
      delay(1000);
      LED0.LED_on_off(LED0.LEDG4);
      delay(1000);
      LED0.LED_on_off(LED0.LEDG5);
      delay(1000);
      LED0.LED_on_off(LED0.LEDG6);
      delay(1000);
      LED0.LED_on_off(LED0.LEDG7);
      delay(1000);
      LED0.LED_on_off(LED0.LEDG8);
      delay(1000);
    }
     

    while ((Button0.r_button() == HIGH) & (test_code_mulitiplexer_checkoutput == true))
    {
      Mulitiplexer0.channel_select(0, 0, 0);
      Serial.println("Block A1");
      Mulitiplexer0.r_mux_A_channel();
      Serial.println("Block B1");
      Mulitiplexer0.r_mux_B_channel();
      Serial.println("Block C1");
      Mulitiplexer0.r_mux_C_channel();
      Serial.println("Block D1");
      Mulitiplexer0.r_mux_D_channel();
      Serial.println("Block E1");
      Mulitiplexer0.r_mux_E_channel();
      Serial.println("Block F1");
      Mulitiplexer0.r_mux_F_channel();
      Serial.println("Block G1");
      Mulitiplexer0.r_mux_G_channel();
      Serial.println("Block H1");
      Mulitiplexer0.r_mux_H_channel();
  
      Mulitiplexer0.channel_select(1, 0, 0);
      Serial.println("Block A2");
      Mulitiplexer0.r_mux_A_channel();
      delay(4000);
    } // end test for mux circuit

    delay(1000); //--> to allow for button press

  }

  //***************************************Start of Code***********************//
  if (test_code == false)
  {
    while (Button0.r_button() == HIGH)
    {
      Display0.clear();
      Display0.print_select_puzzle(60, 30, Potentiometer0.r_pot());
      Display0.draw();
    }
    
    delay(1000); //--> to allow for button press
    const int constpot = Potentiometer0.r_pot(); // making pot cost for remaining of loop

    Display0.clear();
    Display0.print_user_puzzle(58, 43, constpot);
    Display0.draw();

    switch (constpot)
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

    while ((Button0.r_button() == HIGH) & (constpot == 1)) // to set up Puzzle #1015704
    {
      LED0.LED_on_off(LED0.LEDA1);
      LED0.LED_on_off(LED0.LEDA2);
      LED0.LED_on_off(LED0.LEDA3);
    }

    while ((Button0.r_button() == HIGH) & (constpot == 2)) // to set up Puzzle #561534
    {
      LED0.LED_on_off(LED0.LEDA2);
      LED0.LED_on_off(LED0.LEDA4);
      LED0.LED_on_off(LED0.LEDA6);
    }

    while ((Button0.r_button() == HIGH) & (constpot == 3)) // to set up Puzzle #1036958
    {
      LED0.LED_on_off(LED0.LEDA2);
    }

    LED0.LED_on_off(LED0.LEDclear); // clears all LEDs
    delay(1000);                 // allow for button press
  } // end  if (test_code == false)

} //end void loop
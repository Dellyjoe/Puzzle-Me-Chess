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
  Mulitiplexer0.init_muxs_input(15, 14, 32, 39, 38, 37, 16, 17); 
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

    while((Button0.r_button() == HIGH) & (test_code_LED == true))
    {
      LED0.LED_on_off(LED0.LEDA1); delay(15); LED0.LED_on_off(LED0.LEDA2); delay(15); LED0.LED_on_off(LED0.LEDA3); delay(15); LED0.LED_on_off(LED0.LEDA4); delay(15); 
      LED0.LED_on_off(LED0.LEDA5); delay(15); LED0.LED_on_off(LED0.LEDA6); delay(15); LED0.LED_on_off(LED0.LEDA7); delay(15); LED0.LED_on_off(LED0.LEDA8); delay(15);

      LED0.LED_on_off(LED0.LEDB1); delay(15); LED0.LED_on_off(LED0.LEDB2); delay(15); LED0.LED_on_off(LED0.LEDB3); delay(15); LED0.LED_on_off(LED0.LEDB4); delay(15); 
      LED0.LED_on_off(LED0.LEDB5); delay(15); LED0.LED_on_off(LED0.LEDB6); delay(15); LED0.LED_on_off(LED0.LEDB7); delay(15); LED0.LED_on_off(LED0.LEDB8); delay(15);

      LED0.LED_on_off(LED0.LEDC1); delay(15); LED0.LED_on_off(LED0.LEDC2); delay(15); LED0.LED_on_off(LED0.LEDC3); delay(15); LED0.LED_on_off(LED0.LEDC4); delay(15); 
      LED0.LED_on_off(LED0.LEDC5); delay(15); LED0.LED_on_off(LED0.LEDC6); delay(15); LED0.LED_on_off(LED0.LEDC7); delay(15); LED0.LED_on_off(LED0.LEDC8); delay(15);

      LED0.LED_on_off(LED0.LEDD1); delay(15); LED0.LED_on_off(LED0.LEDD2); delay(15); LED0.LED_on_off(LED0.LEDD3); delay(15); LED0.LED_on_off(LED0.LEDD4); delay(15); 
      LED0.LED_on_off(LED0.LEDD5); delay(15); LED0.LED_on_off(LED0.LEDD6); delay(15); LED0.LED_on_off(LED0.LEDD7); delay(15); LED0.LED_on_off(LED0.LEDD8); delay(15);

      LED0.LED_on_off(LED0.LEDE1); delay(15); LED0.LED_on_off(LED0.LEDE2); delay(15); LED0.LED_on_off(LED0.LEDE3); delay(15); LED0.LED_on_off(LED0.LEDE4); delay(15); 
      LED0.LED_on_off(LED0.LEDE5); delay(15); LED0.LED_on_off(LED0.LEDE6); delay(15); LED0.LED_on_off(LED0.LEDE7); delay(15); LED0.LED_on_off(LED0.LEDE8); delay(15);

      LED0.LED_on_off(LED0.LEDF1); delay(15); LED0.LED_on_off(LED0.LEDF2); delay(15); LED0.LED_on_off(LED0.LEDF3); delay(15); LED0.LED_on_off(LED0.LEDF4); delay(15); 
      LED0.LED_on_off(LED0.LEDF5); delay(15); LED0.LED_on_off(LED0.LEDF6); delay(15); LED0.LED_on_off(LED0.LEDF7); delay(15); LED0.LED_on_off(LED0.LEDF8); delay(15);

      LED0.LED_on_off(LED0.LEDG1); delay(15); LED0.LED_on_off(LED0.LEDG2); delay(15); LED0.LED_on_off(LED0.LEDG3); delay(15); LED0.LED_on_off(LED0.LEDG4); delay(15); 
      LED0.LED_on_off(LED0.LEDG5); delay(15); LED0.LED_on_off(LED0.LEDG6); delay(15); LED0.LED_on_off(LED0.LEDG7); delay(15); LED0.LED_on_off(LED0.LEDG8); delay(15);

      LED0.LED_on_off(LED0.LEDH1); delay(15); LED0.LED_on_off(LED0.LEDH2); delay(15); LED0.LED_on_off(LED0.LEDH3); delay(15); LED0.LED_on_off(LED0.LEDH4); delay(15); 
      LED0.LED_on_off(LED0.LEDH5); delay(15); LED0.LED_on_off(LED0.LEDH6); delay(15); LED0.LED_on_off(LED0.LEDH7); delay(15); LED0.LED_on_off(LED0.LEDH8); delay(1000);
     }

    while ((Button0.r_button() == HIGH) & (test_code_mulitiplexer_checkoutput == true))
    {
      Mulitiplexer0.channel_select(0, 0, 0); // 000
      Serial.println("Block A1");
      Mulitiplexer0.r_mux_A_channel();
       delay(10);
      Mulitiplexer0.channel_select(1, 0, 0); // 100
       Serial.println("Block B2");
       Mulitiplexer0.r_mux_B_channel();
      delay(10);
       Mulitiplexer0.channel_select(0, 1, 0); // 010
       Serial.println("Block C3");
       Mulitiplexer0.r_mux_C_channel();
       delay(10);
       Mulitiplexer0.channel_select(1, 1, 0); // 110
       Serial.println("Block D4");
       Mulitiplexer0.r_mux_D_channel();
       delay(10);
       Mulitiplexer0.channel_select(0, 0, 1); // 001
       Serial.println("Block E5");
       Mulitiplexer0.r_mux_E_channel();
       delay(10);
       Mulitiplexer0.channel_select(1, 0, 1); // 101
       Serial.println("Block F6");
       Mulitiplexer0.r_mux_F_channel();
       delay(10);
       Mulitiplexer0.channel_select(0, 1, 1); // 011
       Serial.println("Block G7");
       Mulitiplexer0.r_mux_G_channel();
       delay(10);
       Mulitiplexer0.channel_select(1, 1, 1); // 111
       Serial.println("Block H8");
       Mulitiplexer0.r_mux_H_channel();
       Serial.println("_____________________");
      delay(1000);
    } // end test for mux circuit

    delay(1000); //--> to allow for button press

  }

  //***************************************Start of Code***********************//
  if (test_code == false)
  LED0.LED_on_off(LED0.LEDA1); delay(15); LED0.LED_on_off(LED0.LEDA2); delay(15); LED0.LED_on_off(LED0.LEDA3); delay(15); LED0.LED_on_off(LED0.LEDA4); delay(15); 
  LED0.LED_on_off(LED0.LEDA5); delay(15); LED0.LED_on_off(LED0.LEDA6); delay(15); LED0.LED_on_off(LED0.LEDA7); delay(15); LED0.LED_on_off(LED0.LEDA8); delay(15);

  LED0.LED_on_off(LED0.LEDB1); delay(15); LED0.LED_on_off(LED0.LEDB2); delay(15); LED0.LED_on_off(LED0.LEDB3); delay(15); LED0.LED_on_off(LED0.LEDB4); delay(15); 
  LED0.LED_on_off(LED0.LEDB5); delay(15); LED0.LED_on_off(LED0.LEDB6); delay(15); LED0.LED_on_off(LED0.LEDB7); delay(15); LED0.LED_on_off(LED0.LEDB8); delay(15);

  LED0.LED_on_off(LED0.LEDC1); delay(15); LED0.LED_on_off(LED0.LEDC2); delay(15); LED0.LED_on_off(LED0.LEDC3); delay(15); LED0.LED_on_off(LED0.LEDC4); delay(15); 
  LED0.LED_on_off(LED0.LEDC5); delay(15); LED0.LED_on_off(LED0.LEDC6); delay(15); LED0.LED_on_off(LED0.LEDC7); delay(15); LED0.LED_on_off(LED0.LEDC8); delay(15);

  LED0.LED_on_off(LED0.LEDD1); delay(15); LED0.LED_on_off(LED0.LEDD2); delay(15); LED0.LED_on_off(LED0.LEDD3); delay(15); LED0.LED_on_off(LED0.LEDD4); delay(15); 
  LED0.LED_on_off(LED0.LEDD5); delay(15); LED0.LED_on_off(LED0.LEDD6); delay(15); LED0.LED_on_off(LED0.LEDD7); delay(15); LED0.LED_on_off(LED0.LEDD8); delay(15);

  LED0.LED_on_off(LED0.LEDE1); delay(15); LED0.LED_on_off(LED0.LEDE2); delay(15); LED0.LED_on_off(LED0.LEDE3); delay(15); LED0.LED_on_off(LED0.LEDE4); delay(15); 
  LED0.LED_on_off(LED0.LEDE5); delay(15); LED0.LED_on_off(LED0.LEDE6); delay(15); LED0.LED_on_off(LED0.LEDE7); delay(15); LED0.LED_on_off(LED0.LEDE8); delay(15);

  LED0.LED_on_off(LED0.LEDF1); delay(15); LED0.LED_on_off(LED0.LEDF2); delay(15); LED0.LED_on_off(LED0.LEDF3); delay(15); LED0.LED_on_off(LED0.LEDF4); delay(15); 
  LED0.LED_on_off(LED0.LEDF5); delay(15); LED0.LED_on_off(LED0.LEDF6); delay(15); LED0.LED_on_off(LED0.LEDF7); delay(15); LED0.LED_on_off(LED0.LEDF8); delay(15);

  LED0.LED_on_off(LED0.LEDG1); delay(15); LED0.LED_on_off(LED0.LEDG2); delay(15); LED0.LED_on_off(LED0.LEDG3); delay(15); LED0.LED_on_off(LED0.LEDG4); delay(15); 
  LED0.LED_on_off(LED0.LEDG5); delay(15); LED0.LED_on_off(LED0.LEDG6); delay(15); LED0.LED_on_off(LED0.LEDG7); delay(15); LED0.LED_on_off(LED0.LEDG8); delay(15);

  LED0.LED_on_off(LED0.LEDH1); delay(15); LED0.LED_on_off(LED0.LEDH2); delay(15); LED0.LED_on_off(LED0.LEDH3); delay(15); LED0.LED_on_off(LED0.LEDH4); delay(15); 
  LED0.LED_on_off(LED0.LEDH5); delay(15); LED0.LED_on_off(LED0.LEDH6); delay(15); LED0.LED_on_off(LED0.LEDH7); delay(15); LED0.LED_on_off(LED0.LEDH8); delay(15);

  LED0.LED_on_off(LED0.LEDA8); delay(15); LED0.LED_on_off(LED0.LEDH8); delay(15); LED0.LED_on_off(LED0.LEDA1); delay(15); LED0.LED_on_off(LED0.LEDH8); delay(15); 
  LED0.LED_on_off(LED0.LEDB7); delay(15); LED0.LED_on_off(LED0.LEDG7); delay(15); LED0.LED_on_off(LED0.LEDB2); delay(15); LED0.LED_on_off(LED0.LEDG2); delay(15); 
  LED0.LED_on_off(LED0.LEDC6); delay(15); LED0.LED_on_off(LED0.LEDF6); delay(15); LED0.LED_on_off(LED0.LEDC3); delay(15); LED0.LED_on_off(LED0.LEDF3); delay(15);

  
  for(int i = 1; i<600; i++)
  {
    LED0.LED_on_off(LED0.LEDD5); 
    LED0.LED_on_off(LED0.LEDE5); 
    LED0.LED_on_off(LED0.LEDD4); 
    LED0.LED_on_off(LED0.LEDE4);  
  }

  LED0.LED_on_off(LED0.LEDclear);

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
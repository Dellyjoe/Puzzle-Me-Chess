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
      LED0.test_all_LEDs();
    }

    while((Button0.r_button() == HIGH) & (test_code_mulitiplexer_checkoutput == true))
    {
      while(Mulitiplexer0.r_mux_A_channel() == false)
      {
        LED0.LED_on_off(LED0.LEDA2); // Turning on Master key LEDs
        LED0.LED_on_off(LED0.LEDA7); 
        LED0.LED_on_off(LED0.LEDA8); 
    
        if (Mulitiplexer0.r_mux_A_channel() == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          // call display funtion that will tell the user which peices go where. 
        }
      }// end of while loop Mux A

      while ((Button0.r_button() == HIGH)) // change this when you set up Mux B
      {
        LED0.LED_on_off(LED0.LEDB2); LED0.LED_on_off(LED0.LEDB7);
      } // end of while loop Mux B

      delay(1000); //--> to allow for button press
    } // end test_code_mulitiplexer_checkoutput == true
  } // end  if (test_code == true)

  //***************************************Start of Code***********************//
  if (test_code == false)
  {
    //*************LED Start up code*************//
    for(int i = 1; i<200; i++)
    {
      LED0.LED_on_off(LED0.LEDA8); 
      LED0.LED_on_off(LED0.LEDH8); 
      LED0.LED_on_off(LED0.LEDA1); 
      LED0.LED_on_off(LED0.LEDH1); 
    } // end of for loop
      
    for(int i = 1; i<200; i++)
    {
      LED0.LED_on_off(LED0.LEDB7); 
      LED0.LED_on_off(LED0.LEDG7);  
      LED0.LED_on_off(LED0.LEDB2); 
      LED0.LED_on_off(LED0.LEDG2); 
    } // end of for loop

    for(int i = 1; i<200; i++)
    {
      LED0.LED_on_off(LED0.LEDC6); 
      LED0.LED_on_off(LED0.LEDF6); 
      LED0.LED_on_off(LED0.LEDC3); 
      LED0.LED_on_off(LED0.LEDF3);
    } // end of for loop

    for(int i = 1; i<450; i++)
    {
      LED0.LED_on_off(LED0.LEDD5); 
      LED0.LED_on_off(LED0.LEDE5); 
      LED0.LED_on_off(LED0.LEDD4); 
      LED0.LED_on_off(LED0.LEDE4);  
    } // end of for loop

    LED0.LED_on_off(LED0.LEDclear);
    //*******End of LED Start up code code*******//
    
    //*******User Picks which puzzle he/she would like to do*******//
    while (Button0.r_button() == HIGH)
    {
      Display0.clear();
      Display0.print_select_puzzle(60, 30, Potentiometer0.r_pot());
      Display0.draw();
    }
    
    delay(1000); //--> to allow for button press
    const int constpot = Potentiometer0.r_pot(); // making pot cost for remaining of loop

    switch (constpot)
    {
    case 1:
      Serial.println("Opening File 10500704.CSV"); // prints index 0 in const char array
      Serial.println("___________________");      // line breakup for readability
      SDcard0.open_file(0);                       // Open File indexer 0
      Serial.println("___________________");
      break;
    case 2:
      Serial.println("Opening File 5650034.CSV");
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

    Display0.clear();
    Display0.print_user_puzzle(58, 43, constpot);
    Display0.draw();
    delay(3000); // to allow for user to view OLED

    if(constpot == 1) // to set up Puzzle #136829
    {

      while(Mulitiplexer0.r_mux_A_channel() == false)
      {
        // Turning on Master key LEDs
        LED0.LED_on_off(LED0.LEDA2); LED0.LED_on_off(LED0.LEDA7); LED0.LED_on_off(LED0.LEDA8); 
    
        if (Mulitiplexer0.r_mux_A_channel() == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          // call display funtion that will tell the user which peices go where. 
        }
      }// end of while loop Mux A

      while (Mulitiplexer0.r_mux_B_channel() == false)
      {
        LED0.LED_on_off(LED0.LEDB2); LED0.LED_on_off(LED0.LEDB7);

        if (Mulitiplexer0.r_mux_B_channel() == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          // call display funtion that will tell the user which peices go where. 
        }
      } // end of while loop Mux B

      while (Mulitiplexer0.r_mux_C_channel() == false)
      {
        LED0.LED_on_off(LED0.LEDC1); LED0.LED_on_off(LED0.LEDC2); LED0.LED_on_off(LED0.LEDC3); LED0.LED_on_off(LED0.LEDC4); LED0.LED_on_off(LED0.LEDC6); LED0.LED_on_off(LED0.LEDC7);  LED0.LED_on_off(LED0.LEDC8);
       
        if (Mulitiplexer0.r_mux_C_channel() == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          // call display funtion that will tell the user which peices go where. 
        }
      } // end of while loop Mux C
     
      while (Mulitiplexer0.r_mux_D_channel() == false)
      {
        LED0.LED_on_off(LED0.LEDD1); LED0.LED_on_off(LED0.LEDD2); LED0.LED_on_off(LED0.LEDD7); LED0.LED_on_off(LED0.LEDD8);
      
        if (Mulitiplexer0.r_mux_D_channel() == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          // call display funtion that will tell the user which peices go where. 
        }
      } // end of while loop Mux D
    
      while (Mulitiplexer0.r_mux_E_channel() == false)
      {
        LED0.LED_on_off(LED0.LEDE4); LED0.LED_on_off(LED0.LEDE8);
      
        if (Mulitiplexer0.r_mux_E_channel() == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          // call display funtion that will tell the user which peices go where. 
        }
      } // end of while loop Mux E

      while (Mulitiplexer0.r_mux_F_channel() == false)
      {
        LED0.LED_on_off(LED0.LEDF2); LED0.LED_on_off(LED0.LEDF7);
      
        if (Mulitiplexer0.r_mux_F_channel() == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          // call display funtion that will tell the user which peices go where. 
        }
      } // end of while loop Mux F

      while (Mulitiplexer0.r_mux_G_channel() == false)
      {
        LED0.LED_on_off(LED0.LEDG2); LED0.LED_on_off(LED0.LEDG5); LED0.LED_on_off(LED0.LEDG6); LED0.LED_on_off(LED0.LEDG7);
      
        if (Mulitiplexer0.r_mux_G_channel() == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          // call display funtion that will tell the user which peices go where. 
        }
      } // end of while loop Mux G

      while (Mulitiplexer0.r_mux_H_channel() == false)
      {
        LED0.LED_on_off(LED0.LEDH1); LED0.LED_on_off(LED0.LEDH2); LED0.LED_on_off(LED0.LEDH7); LED0.LED_on_off(LED0.LEDH8);

        if (Mulitiplexer0.r_mux_H_channel() == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          // call display funtion that will tell the user which peices go where. 
        }
      } // end of while loop Mux H
    } // end constpot == 1

    while ((Button0.r_button() == HIGH) & (constpot == 2)) // to set up Puzzle #5650034
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
    
  } // end  if (test_code == false)
} //end void loop
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
#include <avr/io.h>
#include <avr/interrupt.h>

//******************************************Declare****************************//
Display Display0; // Setting Object 0 for Display
SDcard SDcard0;
Button Button0;
Potentiometer Potentiometer0;
Buzzer Buzzer0;
Switch Switch0;
LED LED0;
Mulitiplexer Mulitiplexer0;
int constpot = 0;


//************************************Interrupt Funtions***********************//
void show_answer()
{
  if (constpot == 1)
  {
     if(Mulitiplexer0.r_mux_F_channel(Mulitiplexer0.colmF_master_1[0], Mulitiplexer0.colmF_master_1[1], Mulitiplexer0.colmF_master_1[2], Mulitiplexer0.colmF_master_1[3],
                                      Mulitiplexer0.colmF_master_1[4], Mulitiplexer0.colmF_master_1[5], Mulitiplexer0.colmF_master_1[6], Mulitiplexer0.colmF_master_1[7]) == true)
     {
       LED0.LED_on_off(LED0.LEDF7); LED0.LED_on_off(LED0.LEDG8); 
     }
     else if (Mulitiplexer0.r_mux_G_channel(Mulitiplexer0.colmG_Master_1_M1_2[0], Mulitiplexer0.colmG_Master_1_M1_2[1], Mulitiplexer0.colmG_Master_1_M1_2[2], Mulitiplexer0.colmG_Master_1_M1_2[3],
                                            Mulitiplexer0.colmG_Master_1_M1_2[4], Mulitiplexer0.colmG_Master_1_M1_2[5], Mulitiplexer0.colmG_Master_1_M1_2[6], Mulitiplexer0.colmG_Master_1_M1_2[7]) == true) 
     {
       LED0.LED_on_off(LED0.LEDG5); LED0.LED_on_off(LED0.LEDF7);
     }
     else
     {
       Display0.clear();
       Display0.print_piece_location("Error State", "Please", "Restart Puzzle", "");
       Display0.draw();
     }
  }
  else if (constpot == 2)
  {
    Display0.clear();
    Display0.print_piece_location("This is Show", "Answer Interrupt", "constpot = ", "2");
    Display0.draw();
  }
  else if (constpot == 3)
  {
    Display0.clear();
    Display0.print_piece_location("This is Show", "Answer Interrupt", "constpot = ", "3");
    Display0.draw();
  }
  else
  {
    Display0.clear();
    Display0.print_piece_location("error", "", "", "");
    Display0.draw();
  }
  LED0.LED_on_off(LED0.LEDclear);
} // end show_answer

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
  //Switch0.init_switch(21);                                       // seeting D0 to switch
  Mulitiplexer0.init_muxs_input(15, 14, 32, 39, 38, 37, 16, 17); 
  //******************************************Outputs**************************//
  Buzzer0.init_buzzer(31);                    // setting A1 to buzzer
  Mulitiplexer0.init_muxs_output(35, 34, 33); // setting output channels s1 = a, s2 = b, s3 = c
  Mulitiplexer0.init_enable(36);
  LED0.init_LED(); 
  //******************************************Interrupts***********************//
  pinMode(21, INPUT);
  attachInterrupt(digitalPinToInterrupt(20), show_answer, HIGH);
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
    
    while ((Button0.r_button() == HIGH) && (test_code_buzzer == true))
    {
      Buzzer0.write_buzzer();
      delay(1000);
      Buzzer0.turn_off_buzzer();
      delay(1000);
    }
    Buzzer0.turn_off_buzzer();

    delay(1000);//--> to allow for button press

    while((Button0.r_button() == HIGH) && (test_code_LED == true))
    {
      LED0.test_all_LEDs();
    }

    while(test_code_mulitiplexer_checkoutput == true)
    {
      Display0.clear();
      Display0.print_piece_location("Set up Complete", "White to move", "", "");
      Display0.draw();

      while((Button0.r_button() == HIGH))
      {
    
        if (Mulitiplexer0.read_chess_board(Mulitiplexer0.colmA_Master_1_M1[0], Mulitiplexer0.colmA_Master_1_M1[1], Mulitiplexer0.colmA_Master_1_M1[2], Mulitiplexer0.colmA_Master_1_M1[3],
                                           Mulitiplexer0.colmA_Master_1_M1[4], Mulitiplexer0.colmA_Master_1_M1[5], Mulitiplexer0.colmA_Master_1_M1[6], Mulitiplexer0.colmA_Master_1_M1[7],
                                           Mulitiplexer0.colmB_Master_1_M1[0], Mulitiplexer0.colmB_Master_1_M1[1], Mulitiplexer0.colmB_Master_1_M1[2], Mulitiplexer0.colmB_Master_1_M1[3],
                                           Mulitiplexer0.colmB_Master_1_M1[4], Mulitiplexer0.colmB_Master_1_M1[5], Mulitiplexer0.colmB_Master_1_M1[6], Mulitiplexer0.colmB_Master_1_M1[7],
                                           Mulitiplexer0.colmC_Master_1_M1[0], Mulitiplexer0.colmC_Master_1_M1[1], Mulitiplexer0.colmC_Master_1_M1[2], Mulitiplexer0.colmC_Master_1_M1[3],
                                           Mulitiplexer0.colmC_Master_1_M1[4], Mulitiplexer0.colmC_Master_1_M1[5], Mulitiplexer0.colmC_Master_1_M1[6], Mulitiplexer0.colmC_Master_1_M1[7],
                                           Mulitiplexer0.colmD_Master_1_M1[0], Mulitiplexer0.colmD_Master_1_M1[1], Mulitiplexer0.colmD_Master_1_M1[2], Mulitiplexer0.colmD_Master_1_M1[3],
                                           Mulitiplexer0.colmD_Master_1_M1[4], Mulitiplexer0.colmD_Master_1_M1[5], Mulitiplexer0.colmD_Master_1_M1[6], Mulitiplexer0.colmD_Master_1_M1[7],
                                           Mulitiplexer0.colmE_Master_1_M1[0], Mulitiplexer0.colmE_Master_1_M1[1], Mulitiplexer0.colmE_Master_1_M1[2], Mulitiplexer0.colmE_Master_1_M1[3],
                                           Mulitiplexer0.colmE_Master_1_M1[4], Mulitiplexer0.colmE_Master_1_M1[5], Mulitiplexer0.colmE_Master_1_M1[6], Mulitiplexer0.colmE_Master_1_M1[7],
                                           Mulitiplexer0.colmF_Master_1_M1[0], Mulitiplexer0.colmF_Master_1_M1[1], Mulitiplexer0.colmF_Master_1_M1[2], Mulitiplexer0.colmF_Master_1_M1[3],
                                           Mulitiplexer0.colmF_Master_1_M1[4], Mulitiplexer0.colmF_Master_1_M1[5], Mulitiplexer0.colmF_Master_1_M1[6], Mulitiplexer0.colmF_Master_1_M1[7],
                                           Mulitiplexer0.colmG_Master_1_M1[0], Mulitiplexer0.colmG_Master_1_M1[1], Mulitiplexer0.colmG_Master_1_M1[2], Mulitiplexer0.colmG_Master_1_M1[3],
                                           Mulitiplexer0.colmG_Master_1_M1[4], Mulitiplexer0.colmG_Master_1_M1[5], Mulitiplexer0.colmG_Master_1_M1[6], Mulitiplexer0.colmG_Master_1_M1[7],
                                           Mulitiplexer0.colmH_Master_1_M1[0], Mulitiplexer0.colmH_Master_1_M1[1], Mulitiplexer0.colmH_Master_1_M1[2], Mulitiplexer0.colmH_Master_1_M1[3],
                                           Mulitiplexer0.colmH_Master_1_M1[4], Mulitiplexer0.colmH_Master_1_M1[5], Mulitiplexer0.colmH_Master_1_M1[6], Mulitiplexer0.colmH_Master_1_M1[7]) == true)
        {
          Display0.clear();
          Display0.print_piece_location("Correct Move Now", "Press,", "Blue Button", "");
          Display0.draw();
        }
        else
        {
          Display0.clear();
          Display0.print_piece_location("Waiting for ", "Correct Move,", "", "");
          Display0.draw();
          delay(1000);
        }
      }// end Button0.r_button() == HIGH

     delay(1000); // allow for button press

        while((Button0.r_button() == HIGH))
      {
        if (Mulitiplexer0.read_chess_board(Mulitiplexer0.colmA_Master_1_M1_2[0], Mulitiplexer0.colmA_Master_1_M1_2[1], Mulitiplexer0.colmA_Master_1_M1_2[2], Mulitiplexer0.colmA_Master_1_M1_2[3],
                                           Mulitiplexer0.colmA_Master_1_M1_2[4], Mulitiplexer0.colmA_Master_1_M1_2[5], Mulitiplexer0.colmA_Master_1_M1_2[6], Mulitiplexer0.colmA_Master_1_M1_2[7],
                                           Mulitiplexer0.colmB_Master_1_M1_2[0], Mulitiplexer0.colmB_Master_1_M1_2[1], Mulitiplexer0.colmB_Master_1_M1_2[2], Mulitiplexer0.colmB_Master_1_M1_2[3],
                                           Mulitiplexer0.colmB_Master_1_M1_2[4], Mulitiplexer0.colmB_Master_1_M1_2[5], Mulitiplexer0.colmB_Master_1_M1_2[6], Mulitiplexer0.colmB_Master_1_M1_2[7],
                                           Mulitiplexer0.colmC_Master_1_M1_2[0], Mulitiplexer0.colmC_Master_1_M1_2[1], Mulitiplexer0.colmC_Master_1_M1_2[2], Mulitiplexer0.colmC_Master_1_M1_2[3],
                                           Mulitiplexer0.colmC_Master_1_M1_2[4], Mulitiplexer0.colmC_Master_1_M1_2[5], Mulitiplexer0.colmC_Master_1_M1_2[6], Mulitiplexer0.colmC_Master_1_M1_2[7],
                                           Mulitiplexer0.colmD_Master_1_M1_2[0], Mulitiplexer0.colmD_Master_1_M1_2[1], Mulitiplexer0.colmD_Master_1_M1_2[2], Mulitiplexer0.colmD_Master_1_M1_2[3],
                                           Mulitiplexer0.colmD_Master_1_M1_2[4], Mulitiplexer0.colmD_Master_1_M1_2[5], Mulitiplexer0.colmD_Master_1_M1_2[6], Mulitiplexer0.colmD_Master_1_M1_2[7],
                                           Mulitiplexer0.colmE_Master_1_M1_2[0], Mulitiplexer0.colmE_Master_1_M1_2[1], Mulitiplexer0.colmE_Master_1_M1_2[2], Mulitiplexer0.colmE_Master_1_M1_2[3],
                                           Mulitiplexer0.colmE_Master_1_M1_2[4], Mulitiplexer0.colmE_Master_1_M1_2[5], Mulitiplexer0.colmE_Master_1_M1_2[6], Mulitiplexer0.colmE_Master_1_M1_2[7],
                                           Mulitiplexer0.colmF_Master_1_M1_2[0], Mulitiplexer0.colmF_Master_1_M1_2[1], Mulitiplexer0.colmF_Master_1_M1_2[2], Mulitiplexer0.colmF_Master_1_M1_2[3],
                                           Mulitiplexer0.colmF_Master_1_M1_2[4], Mulitiplexer0.colmF_Master_1_M1_2[5], Mulitiplexer0.colmF_Master_1_M1_2[6], Mulitiplexer0.colmF_Master_1_M1_2[7],
                                           Mulitiplexer0.colmG_Master_1_M1_2[0], Mulitiplexer0.colmG_Master_1_M1_2[1], Mulitiplexer0.colmG_Master_1_M1_2[2], Mulitiplexer0.colmG_Master_1_M1_2[3],
                                           Mulitiplexer0.colmG_Master_1_M1_2[4], Mulitiplexer0.colmG_Master_1_M1_2[5], Mulitiplexer0.colmG_Master_1_M1_2[6], Mulitiplexer0.colmG_Master_1_M1_2[7],
                                           Mulitiplexer0.colmH_Master_1_M1_2[0], Mulitiplexer0.colmH_Master_1_M1_2[1], Mulitiplexer0.colmH_Master_1_M1_2[2], Mulitiplexer0.colmH_Master_1_M1_2[3],
                                           Mulitiplexer0.colmH_Master_1_M1_2[4], Mulitiplexer0.colmH_Master_1_M1_2[5], Mulitiplexer0.colmH_Master_1_M1_2[6], Mulitiplexer0.colmH_Master_1_M1_2[7]) == true)
                                           {
                                              Display0.clear();
                                              Display0.print_piece_location("Correct Move Now", "Press,", "Blue Button", "");
                                              Display0.draw();
                                           }
                                           else
                                           {
                                             Display0.clear();
                                             Display0.print_piece_location("Correct Move: ", "now move", "Black", "RF8 to G8");
                                             Display0.draw();
                                             delay(1000);
                                           }

      }
      
      delay(1000); // allow for button press

      while ((Button0.r_button() == HIGH)) // change this when you set up Mux B
      {
        if (Mulitiplexer0.read_chess_board(Mulitiplexer0.colmA_Master_1_M2[0], Mulitiplexer0.colmA_Master_1_M2[1], Mulitiplexer0.colmA_Master_1_M2[2], Mulitiplexer0.colmA_Master_1_M2[3],
                                           Mulitiplexer0.colmA_Master_1_M2[4], Mulitiplexer0.colmA_Master_1_M2[5], Mulitiplexer0.colmA_Master_1_M2[6], Mulitiplexer0.colmA_Master_1_M2[7],
                                           Mulitiplexer0.colmB_Master_1_M2[0], Mulitiplexer0.colmB_Master_1_M2[1], Mulitiplexer0.colmB_Master_1_M2[2], Mulitiplexer0.colmB_Master_1_M2[3],
                                           Mulitiplexer0.colmB_Master_1_M2[4], Mulitiplexer0.colmB_Master_1_M2[5], Mulitiplexer0.colmB_Master_1_M2[6], Mulitiplexer0.colmB_Master_1_M2[7],
                                           Mulitiplexer0.colmC_Master_1_M2[0], Mulitiplexer0.colmC_Master_1_M2[1], Mulitiplexer0.colmC_Master_1_M2[2], Mulitiplexer0.colmC_Master_1_M2[3],
                                           Mulitiplexer0.colmC_Master_1_M2[4], Mulitiplexer0.colmC_Master_1_M2[5], Mulitiplexer0.colmC_Master_1_M2[6], Mulitiplexer0.colmC_Master_1_M2[7],
                                           Mulitiplexer0.colmD_Master_1_M2[0], Mulitiplexer0.colmD_Master_1_M2[1], Mulitiplexer0.colmD_Master_1_M2[2], Mulitiplexer0.colmD_Master_1_M2[3],
                                           Mulitiplexer0.colmD_Master_1_M2[4], Mulitiplexer0.colmD_Master_1_M2[5], Mulitiplexer0.colmD_Master_1_M2[6], Mulitiplexer0.colmD_Master_1_M2[7],
                                           Mulitiplexer0.colmE_Master_1_M2[0], Mulitiplexer0.colmE_Master_1_M2[1], Mulitiplexer0.colmE_Master_1_M2[2], Mulitiplexer0.colmE_Master_1_M2[3],
                                           Mulitiplexer0.colmE_Master_1_M2[4], Mulitiplexer0.colmE_Master_1_M2[5], Mulitiplexer0.colmE_Master_1_M2[6], Mulitiplexer0.colmE_Master_1_M2[7],
                                           Mulitiplexer0.colmF_Master_1_M2[0], Mulitiplexer0.colmF_Master_1_M2[1], Mulitiplexer0.colmF_Master_1_M2[2], Mulitiplexer0.colmF_Master_1_M2[3],
                                           Mulitiplexer0.colmF_Master_1_M2[4], Mulitiplexer0.colmF_Master_1_M2[5], Mulitiplexer0.colmF_Master_1_M2[6], Mulitiplexer0.colmF_Master_1_M2[7],
                                           Mulitiplexer0.colmG_Master_1_M2[0], Mulitiplexer0.colmG_Master_1_M2[1], Mulitiplexer0.colmG_Master_1_M2[2], Mulitiplexer0.colmG_Master_1_M2[3],
                                           Mulitiplexer0.colmG_Master_1_M2[4], Mulitiplexer0.colmG_Master_1_M2[5], Mulitiplexer0.colmG_Master_1_M2[6], Mulitiplexer0.colmG_Master_1_M2[7],
                                           Mulitiplexer0.colmH_Master_1_M2[0], Mulitiplexer0.colmH_Master_1_M2[1], Mulitiplexer0.colmH_Master_1_M2[2], Mulitiplexer0.colmH_Master_1_M2[3],
                                           Mulitiplexer0.colmH_Master_1_M2[4], Mulitiplexer0.colmH_Master_1_M2[5], Mulitiplexer0.colmH_Master_1_M2[6], Mulitiplexer0.colmH_Master_1_M2[7]) == true)
        {
          Display0.clear();
          Display0.print_piece_location("Check Mate", "Press Blue Button", "To Complete", "Puzzle");
          Display0.draw();
          Buzzer0.write_buzzer();
          delay(1000);
          Buzzer0.turn_off_buzzer();
          delay(1000);
          Buzzer0.write_buzzer();
          
        }
        else
        {
          Display0.clear();
          Display0.print_piece_location("Whites Move:", "Waiting for", "Correct Move", "");
          Display0.draw();
          delay(1000);
        }
      } // end of while loop Mux B
      
      Buzzer0.turn_off_buzzer();
      LED0.LED_on_off(LED0.LEDclear);
      delay(1000); //--> to allow for button press
    } // end test_code_mulitiplexer_checkoutput == true

    while ((Button0.r_button() == HIGH) && (test_code_Display == true))
    {
     Display0.clear();
     Display0.print_piece_location("Colm A Placement", "WB23, WB23, WB23,", "WB23, WB23, WB23,", "BB23, BB23");
     Display0.draw();
    } // end of While Loop Display
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
    constpot = Potentiometer0.r_pot(); // making pot cost for remaining of loop

    switch (constpot)
    {
    case 1:
      Serial.println("Opening File 136829.CSV"); // prints index 0 in const char array
      Serial.println("___________________");       // line breakup for readability
      SDcard0.open_file(0);                        // Open File indexer 0
      Serial.println("___________________");
      break;
    case 2:
      Serial.println("Opening File 1022136.CSV");
      Serial.println("___________________");
      SDcard0.open_file(1);
      Serial.println("___________________");
      break;
    case 3:
      Serial.println("Opening File 764878.CSV");
      Serial.println("___________________");
      SDcard0.open_file(2);
      Serial.println("___________________");
      break;
    }

    Display0.clear();
    Display0.print_user_puzzle(58, 43, constpot);
    Display0.draw();
    delay(3000); // to allow for user to view OLED

    //***********************Puzzle 1*******************************************//
    if(constpot == 1) // to set up Puzzle #136829
    {
      Display0.clear();
      Display0.print_piece_location("Colm A Placement", "WPA2", "BPA7, BRA8", " ");
      Display0.draw();

      while(Mulitiplexer0.r_mux_A_channel(Mulitiplexer0.colmA_master_1[0], Mulitiplexer0.colmA_master_1[1], Mulitiplexer0.colmA_master_1[2], Mulitiplexer0.colmA_master_1[3],
                                          Mulitiplexer0.colmA_master_1[4], Mulitiplexer0.colmA_master_1[5], Mulitiplexer0.colmA_master_1[6], Mulitiplexer0.colmA_master_1[7]) == false)
      {
        // Turning on Master key LEDs
        LED0.LED_on_off(LED0.LEDA2); LED0.LED_on_off(LED0.LEDA7); LED0.LED_on_off(LED0.LEDA8); 
    
        if (Mulitiplexer0.r_mux_A_channel(Mulitiplexer0.colmA_master_1[0], Mulitiplexer0.colmA_master_1[1], Mulitiplexer0.colmA_master_1[2], Mulitiplexer0.colmA_master_1[3],
                                          Mulitiplexer0.colmA_master_1[4], Mulitiplexer0.colmA_master_1[5], Mulitiplexer0.colmA_master_1[6], Mulitiplexer0.colmA_master_1[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          
        }
      }// end of while loop Mux A

      Display0.clear();
      Display0.print_piece_location("Colm B Placement", "WPB2", "BPA7", " ");
      Display0.draw(); 

      while (Mulitiplexer0.r_mux_B_channel(Mulitiplexer0.colmB_master_1[0], Mulitiplexer0.colmB_master_1[1], Mulitiplexer0.colmB_master_1[2], Mulitiplexer0.colmB_master_1[3],
                                           Mulitiplexer0.colmB_master_1[4], Mulitiplexer0.colmB_master_1[5], Mulitiplexer0.colmB_master_1[6], Mulitiplexer0.colmB_master_1[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDB2); LED0.LED_on_off(LED0.LEDB7);

        if (Mulitiplexer0.r_mux_B_channel(Mulitiplexer0.colmB_master_1[0], Mulitiplexer0.colmB_master_1[1], Mulitiplexer0.colmB_master_1[2], Mulitiplexer0.colmB_master_1[3],
                                          Mulitiplexer0.colmB_master_1[4], Mulitiplexer0.colmB_master_1[5], Mulitiplexer0.colmB_master_1[6], Mulitiplexer0.colmB_master_1[7])== true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          
        }
      } // end of while loop Mux B

      Display0.clear();
      Display0.print_piece_location("Colm C Placement", "WKC1, WPC2, WNC3", "WBC4, BNC6", "BPC7, BBC8 ");
      Display0.draw();

      while (Mulitiplexer0.r_mux_C_channel(Mulitiplexer0.colmC_master_1[0], Mulitiplexer0.colmC_master_1[1], Mulitiplexer0.colmC_master_1[2], Mulitiplexer0.colmC_master_1[3],
                                           Mulitiplexer0.colmC_master_1[4], Mulitiplexer0.colmC_master_1[5], Mulitiplexer0.colmC_master_1[6], Mulitiplexer0.colmC_master_1[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDC1); LED0.LED_on_off(LED0.LEDC2); LED0.LED_on_off(LED0.LEDC3); LED0.LED_on_off(LED0.LEDC4); LED0.LED_on_off(LED0.LEDC6); LED0.LED_on_off(LED0.LEDC7);  LED0.LED_on_off(LED0.LEDC8);
       
        if (Mulitiplexer0.r_mux_C_channel(Mulitiplexer0.colmC_master_1[0], Mulitiplexer0.colmC_master_1[1], Mulitiplexer0.colmC_master_1[2], Mulitiplexer0.colmC_master_1[3],
                                          Mulitiplexer0.colmC_master_1[4], Mulitiplexer0.colmC_master_1[5], Mulitiplexer0.colmC_master_1[6], Mulitiplexer0.colmC_master_1[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          
        }
      } // end of while loop Mux C

      Display0.clear();
      Display0.print_piece_location("Colm D Placement", "WRD1, WBD2", "BPD7, DQD8", "");
      Display0.draw();

      while (Mulitiplexer0.r_mux_D_channel(Mulitiplexer0.colmD_master_1[0], Mulitiplexer0.colmD_master_1[1], Mulitiplexer0.colmD_master_1[2], Mulitiplexer0.colmD_master_1[3],
                                           Mulitiplexer0.colmD_master_1[4], Mulitiplexer0.colmD_master_1[5], Mulitiplexer0.colmD_master_1[6], Mulitiplexer0.colmD_master_1[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDD1); LED0.LED_on_off(LED0.LEDD2); LED0.LED_on_off(LED0.LEDD7); LED0.LED_on_off(LED0.LEDD8);
      
        if (Mulitiplexer0.r_mux_D_channel(Mulitiplexer0.colmD_master_1[0], Mulitiplexer0.colmD_master_1[1], Mulitiplexer0.colmD_master_1[2], Mulitiplexer0.colmD_master_1[3],
                                          Mulitiplexer0.colmD_master_1[4], Mulitiplexer0.colmD_master_1[5], Mulitiplexer0.colmD_master_1[6], Mulitiplexer0.colmD_master_1[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
         
        }
      } // end of while loop Mux D

      Display0.clear();
      Display0.print_piece_location("Colm E Placement", "WPE4", "", "");
      Display0.draw();
    
      while (Mulitiplexer0.r_mux_E_channel(Mulitiplexer0.colmE_master_1[0], Mulitiplexer0.colmE_master_1[1], Mulitiplexer0.colmE_master_1[2], Mulitiplexer0.colmE_master_1[3],
                                           Mulitiplexer0.colmE_master_1[4], Mulitiplexer0.colmE_master_1[5], Mulitiplexer0.colmE_master_1[6], Mulitiplexer0.colmE_master_1[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDE4);
      
        if (Mulitiplexer0.r_mux_E_channel(Mulitiplexer0.colmE_master_1[0], Mulitiplexer0.colmE_master_1[1], Mulitiplexer0.colmE_master_1[2], Mulitiplexer0.colmE_master_1[3],
                                          Mulitiplexer0.colmE_master_1[4], Mulitiplexer0.colmE_master_1[5], Mulitiplexer0.colmE_master_1[6], Mulitiplexer0.colmE_master_1[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
        
        }
      } // end of while loop Mux E

      Display0.clear();
      Display0.print_piece_location("Colm F Placement", "BNF2, WQF7", "BRF8", "");
      Display0.draw(); 

      while (Mulitiplexer0.r_mux_F_channel(Mulitiplexer0.colmF_master_1[0], Mulitiplexer0.colmF_master_1[1], Mulitiplexer0.colmF_master_1[2], Mulitiplexer0.colmF_master_1[3],
                                           Mulitiplexer0.colmF_master_1[4], Mulitiplexer0.colmF_master_1[5], Mulitiplexer0.colmF_master_1[6], Mulitiplexer0.colmF_master_1[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDF2); LED0.LED_on_off(LED0.LEDF7); LED0.LED_on_off(LED0.LEDF8);
      
        if (Mulitiplexer0.r_mux_F_channel(Mulitiplexer0.colmF_master_1[0], Mulitiplexer0.colmF_master_1[1], Mulitiplexer0.colmF_master_1[2], Mulitiplexer0.colmF_master_1[3],
                                          Mulitiplexer0.colmF_master_1[4], Mulitiplexer0.colmF_master_1[5], Mulitiplexer0.colmF_master_1[6], Mulitiplexer0.colmF_master_1[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
        
        }
      } // end of while loop Mux F
      
      Display0.clear();
      Display0.print_piece_location("Colm G Placement", "WPG2, WNG5", "BPG6, BBG7", "");
      Display0.draw(); 

      while (Mulitiplexer0.r_mux_G_channel(Mulitiplexer0.colmG_master_1[0], Mulitiplexer0.colmG_master_1[1], Mulitiplexer0.colmG_master_1[2], Mulitiplexer0.colmG_master_1[3],
                                           Mulitiplexer0.colmG_master_1[4], Mulitiplexer0.colmG_master_1[5], Mulitiplexer0.colmG_master_1[6], Mulitiplexer0.colmG_master_1[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDG2); LED0.LED_on_off(LED0.LEDG5); LED0.LED_on_off(LED0.LEDG6); LED0.LED_on_off(LED0.LEDG7);
      
        if (Mulitiplexer0.r_mux_G_channel(Mulitiplexer0.colmG_master_1[0], Mulitiplexer0.colmG_master_1[1], Mulitiplexer0.colmG_master_1[2], Mulitiplexer0.colmG_master_1[3],
                                          Mulitiplexer0.colmG_master_1[4], Mulitiplexer0.colmG_master_1[5], Mulitiplexer0.colmG_master_1[6], Mulitiplexer0.colmG_master_1[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
        
        }
      } // end of while loop Mux G

      Display0.clear();
      Display0.print_piece_location("Colm H Placement", "WRH1, WPH2", "BPH7, BKH8", "");
      Display0.draw();

      while (Mulitiplexer0.r_mux_H_channel(Mulitiplexer0.colmH_master_1[0], Mulitiplexer0.colmH_master_1[1], Mulitiplexer0.colmH_master_1[2], Mulitiplexer0.colmH_master_1[3],
                                           Mulitiplexer0.colmH_master_1[4], Mulitiplexer0.colmH_master_1[5], Mulitiplexer0.colmH_master_1[6], Mulitiplexer0.colmH_master_1[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDH1); LED0.LED_on_off(LED0.LEDH2); LED0.LED_on_off(LED0.LEDH7); LED0.LED_on_off(LED0.LEDH8);

        if (Mulitiplexer0.r_mux_H_channel(Mulitiplexer0.colmH_master_1[0], Mulitiplexer0.colmH_master_1[1], Mulitiplexer0.colmH_master_1[2], Mulitiplexer0.colmH_master_1[3],
                                          Mulitiplexer0.colmH_master_1[4], Mulitiplexer0.colmH_master_1[5], Mulitiplexer0.colmH_master_1[6], Mulitiplexer0.colmH_master_1[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
           
        }
      } // end of while loop Mux H

      LED0.LED_on_off(LED0.LEDclear);
      //*********Move one*************//
      Display0.clear();
      Display0.print_piece_location("Set up Complete", "White to move", "", "");
      Display0.draw();

      while((Button0.r_button() == HIGH))
      {
    
        if (Mulitiplexer0.read_chess_board(Mulitiplexer0.colmA_Master_1_M1[0], Mulitiplexer0.colmA_Master_1_M1[1], Mulitiplexer0.colmA_Master_1_M1[2], Mulitiplexer0.colmA_Master_1_M1[3],
                                           Mulitiplexer0.colmA_Master_1_M1[4], Mulitiplexer0.colmA_Master_1_M1[5], Mulitiplexer0.colmA_Master_1_M1[6], Mulitiplexer0.colmA_Master_1_M1[7],
                                           Mulitiplexer0.colmB_Master_1_M1[0], Mulitiplexer0.colmB_Master_1_M1[1], Mulitiplexer0.colmB_Master_1_M1[2], Mulitiplexer0.colmB_Master_1_M1[3],
                                           Mulitiplexer0.colmB_Master_1_M1[4], Mulitiplexer0.colmB_Master_1_M1[5], Mulitiplexer0.colmB_Master_1_M1[6], Mulitiplexer0.colmB_Master_1_M1[7],
                                           Mulitiplexer0.colmC_Master_1_M1[0], Mulitiplexer0.colmC_Master_1_M1[1], Mulitiplexer0.colmC_Master_1_M1[2], Mulitiplexer0.colmC_Master_1_M1[3],
                                           Mulitiplexer0.colmC_Master_1_M1[4], Mulitiplexer0.colmC_Master_1_M1[5], Mulitiplexer0.colmC_Master_1_M1[6], Mulitiplexer0.colmC_Master_1_M1[7],
                                           Mulitiplexer0.colmD_Master_1_M1[0], Mulitiplexer0.colmD_Master_1_M1[1], Mulitiplexer0.colmD_Master_1_M1[2], Mulitiplexer0.colmD_Master_1_M1[3],
                                           Mulitiplexer0.colmD_Master_1_M1[4], Mulitiplexer0.colmD_Master_1_M1[5], Mulitiplexer0.colmD_Master_1_M1[6], Mulitiplexer0.colmD_Master_1_M1[7],
                                           Mulitiplexer0.colmE_Master_1_M1[0], Mulitiplexer0.colmE_Master_1_M1[1], Mulitiplexer0.colmE_Master_1_M1[2], Mulitiplexer0.colmE_Master_1_M1[3],
                                           Mulitiplexer0.colmE_Master_1_M1[4], Mulitiplexer0.colmE_Master_1_M1[5], Mulitiplexer0.colmE_Master_1_M1[6], Mulitiplexer0.colmE_Master_1_M1[7],
                                           Mulitiplexer0.colmF_Master_1_M1[0], Mulitiplexer0.colmF_Master_1_M1[1], Mulitiplexer0.colmF_Master_1_M1[2], Mulitiplexer0.colmF_Master_1_M1[3],
                                           Mulitiplexer0.colmF_Master_1_M1[4], Mulitiplexer0.colmF_Master_1_M1[5], Mulitiplexer0.colmF_Master_1_M1[6], Mulitiplexer0.colmF_Master_1_M1[7],
                                           Mulitiplexer0.colmG_Master_1_M1[0], Mulitiplexer0.colmG_Master_1_M1[1], Mulitiplexer0.colmG_Master_1_M1[2], Mulitiplexer0.colmG_Master_1_M1[3],
                                           Mulitiplexer0.colmG_Master_1_M1[4], Mulitiplexer0.colmG_Master_1_M1[5], Mulitiplexer0.colmG_Master_1_M1[6], Mulitiplexer0.colmG_Master_1_M1[7],
                                           Mulitiplexer0.colmH_Master_1_M1[0], Mulitiplexer0.colmH_Master_1_M1[1], Mulitiplexer0.colmH_Master_1_M1[2], Mulitiplexer0.colmH_Master_1_M1[3],
                                           Mulitiplexer0.colmH_Master_1_M1[4], Mulitiplexer0.colmH_Master_1_M1[5], Mulitiplexer0.colmH_Master_1_M1[6], Mulitiplexer0.colmH_Master_1_M1[7]) == true)
        {
          Display0.clear();
          Display0.print_piece_location("Correct Move Now", "Press,", "Blue Button", "");
          Display0.draw();
        }
        else
        {
          Display0.clear();
          Display0.print_piece_location("Set up Complete", "White to Move,", "Waiting for", "Correct Move");
          Display0.draw();
          delay(1000);
        }
      }// end Button0.r_button() == HIGH

     delay(1000); // allow for button press

        while((Button0.r_button() == HIGH))
      {
        if (Mulitiplexer0.read_chess_board(Mulitiplexer0.colmA_Master_1_M1_2[0], Mulitiplexer0.colmA_Master_1_M1_2[1], Mulitiplexer0.colmA_Master_1_M1_2[2], Mulitiplexer0.colmA_Master_1_M1_2[3],
                                           Mulitiplexer0.colmA_Master_1_M1_2[4], Mulitiplexer0.colmA_Master_1_M1_2[5], Mulitiplexer0.colmA_Master_1_M1_2[6], Mulitiplexer0.colmA_Master_1_M1_2[7],
                                           Mulitiplexer0.colmB_Master_1_M1_2[0], Mulitiplexer0.colmB_Master_1_M1_2[1], Mulitiplexer0.colmB_Master_1_M1_2[2], Mulitiplexer0.colmB_Master_1_M1_2[3],
                                           Mulitiplexer0.colmB_Master_1_M1_2[4], Mulitiplexer0.colmB_Master_1_M1_2[5], Mulitiplexer0.colmB_Master_1_M1_2[6], Mulitiplexer0.colmB_Master_1_M1_2[7],
                                           Mulitiplexer0.colmC_Master_1_M1_2[0], Mulitiplexer0.colmC_Master_1_M1_2[1], Mulitiplexer0.colmC_Master_1_M1_2[2], Mulitiplexer0.colmC_Master_1_M1_2[3],
                                           Mulitiplexer0.colmC_Master_1_M1_2[4], Mulitiplexer0.colmC_Master_1_M1_2[5], Mulitiplexer0.colmC_Master_1_M1_2[6], Mulitiplexer0.colmC_Master_1_M1_2[7],
                                           Mulitiplexer0.colmD_Master_1_M1_2[0], Mulitiplexer0.colmD_Master_1_M1_2[1], Mulitiplexer0.colmD_Master_1_M1_2[2], Mulitiplexer0.colmD_Master_1_M1_2[3],
                                           Mulitiplexer0.colmD_Master_1_M1_2[4], Mulitiplexer0.colmD_Master_1_M1_2[5], Mulitiplexer0.colmD_Master_1_M1_2[6], Mulitiplexer0.colmD_Master_1_M1_2[7],
                                           Mulitiplexer0.colmE_Master_1_M1_2[0], Mulitiplexer0.colmE_Master_1_M1_2[1], Mulitiplexer0.colmE_Master_1_M1_2[2], Mulitiplexer0.colmE_Master_1_M1_2[3],
                                           Mulitiplexer0.colmE_Master_1_M1_2[4], Mulitiplexer0.colmE_Master_1_M1_2[5], Mulitiplexer0.colmE_Master_1_M1_2[6], Mulitiplexer0.colmE_Master_1_M1_2[7],
                                           Mulitiplexer0.colmF_Master_1_M1_2[0], Mulitiplexer0.colmF_Master_1_M1_2[1], Mulitiplexer0.colmF_Master_1_M1_2[2], Mulitiplexer0.colmF_Master_1_M1_2[3],
                                           Mulitiplexer0.colmF_Master_1_M1_2[4], Mulitiplexer0.colmF_Master_1_M1_2[5], Mulitiplexer0.colmF_Master_1_M1_2[6], Mulitiplexer0.colmF_Master_1_M1_2[7],
                                           Mulitiplexer0.colmG_Master_1_M1_2[0], Mulitiplexer0.colmG_Master_1_M1_2[1], Mulitiplexer0.colmG_Master_1_M1_2[2], Mulitiplexer0.colmG_Master_1_M1_2[3],
                                           Mulitiplexer0.colmG_Master_1_M1_2[4], Mulitiplexer0.colmG_Master_1_M1_2[5], Mulitiplexer0.colmG_Master_1_M1_2[6], Mulitiplexer0.colmG_Master_1_M1_2[7],
                                           Mulitiplexer0.colmH_Master_1_M1_2[0], Mulitiplexer0.colmH_Master_1_M1_2[1], Mulitiplexer0.colmH_Master_1_M1_2[2], Mulitiplexer0.colmH_Master_1_M1_2[3],
                                           Mulitiplexer0.colmH_Master_1_M1_2[4], Mulitiplexer0.colmH_Master_1_M1_2[5], Mulitiplexer0.colmH_Master_1_M1_2[6], Mulitiplexer0.colmH_Master_1_M1_2[7]) == true)
                                           {
                                              Display0.clear();
                                              Display0.print_piece_location("Correct Move Now", "Press,", "Blue Button", "");
                                              Display0.draw();
                                           }
                                           else
                                           {
                                             Display0.clear();
                                             Display0.print_piece_location("Now Move ", "Black Bishop", "On F8 to G8", "");
                                             Display0.draw();
                                             delay(1000);
                                           }

      }
      
      delay(1000); // allow for button press

      while ((Button0.r_button() == HIGH)) // change this when you set up Mux B
      {
        if (Mulitiplexer0.read_chess_board(Mulitiplexer0.colmA_Master_1_M2[0], Mulitiplexer0.colmA_Master_1_M2[1], Mulitiplexer0.colmA_Master_1_M2[2], Mulitiplexer0.colmA_Master_1_M2[3],
                                           Mulitiplexer0.colmA_Master_1_M2[4], Mulitiplexer0.colmA_Master_1_M2[5], Mulitiplexer0.colmA_Master_1_M2[6], Mulitiplexer0.colmA_Master_1_M2[7],
                                           Mulitiplexer0.colmB_Master_1_M2[0], Mulitiplexer0.colmB_Master_1_M2[1], Mulitiplexer0.colmB_Master_1_M2[2], Mulitiplexer0.colmB_Master_1_M2[3],
                                           Mulitiplexer0.colmB_Master_1_M2[4], Mulitiplexer0.colmB_Master_1_M2[5], Mulitiplexer0.colmB_Master_1_M2[6], Mulitiplexer0.colmB_Master_1_M2[7],
                                           Mulitiplexer0.colmC_Master_1_M2[0], Mulitiplexer0.colmC_Master_1_M2[1], Mulitiplexer0.colmC_Master_1_M2[2], Mulitiplexer0.colmC_Master_1_M2[3],
                                           Mulitiplexer0.colmC_Master_1_M2[4], Mulitiplexer0.colmC_Master_1_M2[5], Mulitiplexer0.colmC_Master_1_M2[6], Mulitiplexer0.colmC_Master_1_M2[7],
                                           Mulitiplexer0.colmD_Master_1_M2[0], Mulitiplexer0.colmD_Master_1_M2[1], Mulitiplexer0.colmD_Master_1_M2[2], Mulitiplexer0.colmD_Master_1_M2[3],
                                           Mulitiplexer0.colmD_Master_1_M2[4], Mulitiplexer0.colmD_Master_1_M2[5], Mulitiplexer0.colmD_Master_1_M2[6], Mulitiplexer0.colmD_Master_1_M2[7],
                                           Mulitiplexer0.colmE_Master_1_M2[0], Mulitiplexer0.colmE_Master_1_M2[1], Mulitiplexer0.colmE_Master_1_M2[2], Mulitiplexer0.colmE_Master_1_M2[3],
                                           Mulitiplexer0.colmE_Master_1_M2[4], Mulitiplexer0.colmE_Master_1_M2[5], Mulitiplexer0.colmE_Master_1_M2[6], Mulitiplexer0.colmE_Master_1_M2[7],
                                           Mulitiplexer0.colmF_Master_1_M2[0], Mulitiplexer0.colmF_Master_1_M2[1], Mulitiplexer0.colmF_Master_1_M2[2], Mulitiplexer0.colmF_Master_1_M2[3],
                                           Mulitiplexer0.colmF_Master_1_M2[4], Mulitiplexer0.colmF_Master_1_M2[5], Mulitiplexer0.colmF_Master_1_M2[6], Mulitiplexer0.colmF_Master_1_M2[7],
                                           Mulitiplexer0.colmG_Master_1_M2[0], Mulitiplexer0.colmG_Master_1_M2[1], Mulitiplexer0.colmG_Master_1_M2[2], Mulitiplexer0.colmG_Master_1_M2[3],
                                           Mulitiplexer0.colmG_Master_1_M2[4], Mulitiplexer0.colmG_Master_1_M2[5], Mulitiplexer0.colmG_Master_1_M2[6], Mulitiplexer0.colmG_Master_1_M2[7],
                                           Mulitiplexer0.colmH_Master_1_M2[0], Mulitiplexer0.colmH_Master_1_M2[1], Mulitiplexer0.colmH_Master_1_M2[2], Mulitiplexer0.colmH_Master_1_M2[3],
                                           Mulitiplexer0.colmH_Master_1_M2[4], Mulitiplexer0.colmH_Master_1_M2[5], Mulitiplexer0.colmH_Master_1_M2[6], Mulitiplexer0.colmH_Master_1_M2[7]) == true)
        {
          Display0.clear();
          Display0.print_piece_location("Check Mate", "Congratulations", "You Compelted", "The Puzzle");
          Display0.draw();
          Buzzer0.write_buzzer();
          delay(1000);
          Buzzer0.turn_off_buzzer();
          delay(1000);
          Buzzer0.write_buzzer();
          delay(1000);
          Buzzer0.turn_off_buzzer();
          break;
        }
        else
        {
          Display0.clear();
          Display0.print_piece_location("Whites Move:", "Waiting for", "Correct Move", "");
          Display0.draw();
          delay(1000);
        }
      } // end of while loop Mux B
      
      Buzzer0.turn_off_buzzer();
      LED0.LED_on_off(LED0.LEDclear);
      delay(1000); //--> to allow for button press
      
    } // end constpot == 1

     //***********************Puzzle 2*******************************************//
    if(constpot == 2) // to set up Puzzle #1022136
    {
      Display0.clear();
      Display0.print_piece_location("Colm B Placement", "BRB2", "WPB3, WRB7", " ");
      Display0.draw(); 

      while (Mulitiplexer0.r_mux_B_channel(Mulitiplexer0.colmB_master_2[0], Mulitiplexer0.colmB_master_2[1], Mulitiplexer0.colmB_master_2[2], Mulitiplexer0.colmB_master_2[3],
                                           Mulitiplexer0.colmB_master_2[4], Mulitiplexer0.colmB_master_2[5], Mulitiplexer0.colmB_master_2[6], Mulitiplexer0.colmB_master_2[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDB2); LED0.LED_on_off(LED0.LEDB3); LED0.LED_on_off(LED0.LEDB7);

        if (Mulitiplexer0.r_mux_B_channel(Mulitiplexer0.colmB_master_2[0], Mulitiplexer0.colmB_master_2[1], Mulitiplexer0.colmB_master_2[2], Mulitiplexer0.colmB_master_2[3],
                                          Mulitiplexer0.colmB_master_2[4], Mulitiplexer0.colmB_master_2[5], Mulitiplexer0.colmB_master_2[6], Mulitiplexer0.colmB_master_2[7])== true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          
        }
      } // end of while loop Mux B

      Display0.clear();
      Display0.print_piece_location("Colm C Placement", "BPC5", "", "");
      Display0.draw();

      while (Mulitiplexer0.r_mux_C_channel(Mulitiplexer0.colmC_master_2[0], Mulitiplexer0.colmC_master_2[1], Mulitiplexer0.colmC_master_2[2], Mulitiplexer0.colmC_master_2[3],
                                           Mulitiplexer0.colmC_master_2[4], Mulitiplexer0.colmC_master_2[5], Mulitiplexer0.colmC_master_2[6], Mulitiplexer0.colmC_master_2[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDC5);
        if (Mulitiplexer0.r_mux_C_channel(Mulitiplexer0.colmC_master_2[0], Mulitiplexer0.colmC_master_2[1], Mulitiplexer0.colmC_master_2[2], Mulitiplexer0.colmC_master_2[3],
                                          Mulitiplexer0.colmC_master_2[4], Mulitiplexer0.colmC_master_2[5], Mulitiplexer0.colmC_master_2[6], Mulitiplexer0.colmC_master_2[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
          
        }
      } // end of while loop Mux C

      Display0.clear();
      Display0.print_piece_location("Colm E Placement", "WBE2", "", "");
      Display0.draw();
    
      while (Mulitiplexer0.r_mux_E_channel(Mulitiplexer0.colmE_master_2[0], Mulitiplexer0.colmE_master_2[1], Mulitiplexer0.colmE_master_2[2], Mulitiplexer0.colmE_master_2[3],
                                           Mulitiplexer0.colmE_master_2[4], Mulitiplexer0.colmE_master_2[5], Mulitiplexer0.colmE_master_2[6], Mulitiplexer0.colmE_master_2[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDE2);
      
        if (Mulitiplexer0.r_mux_E_channel(Mulitiplexer0.colmE_master_2[0], Mulitiplexer0.colmE_master_2[1], Mulitiplexer0.colmE_master_2[2], Mulitiplexer0.colmE_master_2[3],
                                          Mulitiplexer0.colmE_master_2[4], Mulitiplexer0.colmE_master_2[5], Mulitiplexer0.colmE_master_2[6], Mulitiplexer0.colmE_master_2[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
        
        }
      } // end of while loop Mux E

      Display0.clear();
      Display0.print_piece_location("Colm F Placement", "BBF8", "", "");
      Display0.draw(); 

      while (Mulitiplexer0.r_mux_F_channel(Mulitiplexer0.colmF_master_2[0], Mulitiplexer0.colmF_master_2[1], Mulitiplexer0.colmF_master_2[2], Mulitiplexer0.colmF_master_2[3],
                                           Mulitiplexer0.colmF_master_2[4], Mulitiplexer0.colmF_master_2[5], Mulitiplexer0.colmF_master_2[6], Mulitiplexer0.colmF_master_2[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDF8); 
      
        if (Mulitiplexer0.r_mux_F_channel(Mulitiplexer0.colmF_master_2[0], Mulitiplexer0.colmF_master_2[1], Mulitiplexer0.colmF_master_2[2], Mulitiplexer0.colmF_master_2[3],
                                          Mulitiplexer0.colmF_master_2[4], Mulitiplexer0.colmF_master_2[5], Mulitiplexer0.colmF_master_2[6], Mulitiplexer0.colmF_master_2[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
        
        }
      } // end of while loop Mux F
      
      Display0.clear();
      Display0.print_piece_location("Colm G Placement", "WNG4, WBG6", "BPG7, BKG8", "");
      Display0.draw(); 

      while (Mulitiplexer0.r_mux_G_channel(Mulitiplexer0.colmG_master_2[0], Mulitiplexer0.colmG_master_2[1], Mulitiplexer0.colmG_master_2[2], Mulitiplexer0.colmG_master_2[3],
                                           Mulitiplexer0.colmG_master_2[4], Mulitiplexer0.colmG_master_2[5], Mulitiplexer0.colmG_master_2[6], Mulitiplexer0.colmG_master_2[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDG4); LED0.LED_on_off(LED0.LEDG6); LED0.LED_on_off(LED0.LEDG7); LED0.LED_on_off(LED0.LEDG8);
      
        if (Mulitiplexer0.r_mux_G_channel(Mulitiplexer0.colmG_master_2[0], Mulitiplexer0.colmG_master_2[1], Mulitiplexer0.colmG_master_2[2], Mulitiplexer0.colmG_master_2[3],
                                          Mulitiplexer0.colmG_master_2[4], Mulitiplexer0.colmG_master_2[5], Mulitiplexer0.colmG_master_2[6], Mulitiplexer0.colmG_master_2[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
        
        }
      } // end of while loop Mux G

      Display0.clear();
      Display0.print_piece_location("Colm H Placement", "WKH1, WPH3", "", "");
      Display0.draw();

      while (Mulitiplexer0.r_mux_H_channel(Mulitiplexer0.colmH_master_2[0], Mulitiplexer0.colmH_master_2[1], Mulitiplexer0.colmH_master_2[2], Mulitiplexer0.colmH_master_2[3],
                                           Mulitiplexer0.colmH_master_2[4], Mulitiplexer0.colmH_master_2[5], Mulitiplexer0.colmH_master_2[6], Mulitiplexer0.colmH_master_2[7]) == false)
      {
        LED0.LED_on_off(LED0.LEDH1); LED0.LED_on_off(LED0.LEDH3);

        if (Mulitiplexer0.r_mux_H_channel(Mulitiplexer0.colmH_master_2[0], Mulitiplexer0.colmH_master_2[1], Mulitiplexer0.colmH_master_2[2], Mulitiplexer0.colmH_master_2[3],
                                          Mulitiplexer0.colmH_master_2[4], Mulitiplexer0.colmH_master_2[5], Mulitiplexer0.colmH_master_2[6], Mulitiplexer0.colmH_master_2[7]) == true)
        {
          LED0.LED_on_off(LED0.LEDclear);
        }
        else
        {
           
        }
      } // end of while loop Mux H

      LED0.LED_on_off(LED0.LEDclear);
      //*********Move one*************//
      Display0.clear();
      Display0.print_piece_location("Set up Complete", "White to move", "", "");
      Display0.draw();
      delay(1000); // take out after testing is completed
    } // end constpot == 2

    //***********************Puzzle 3*******************************************//
    if(constpot == 3) // to set up Puzzle #****
    {
      while ((Button0.r_button() == HIGH) && (constpot == 3)) // to set up Puzzle #1036958
      {
        LED0.LED_on_off(LED0.LEDA2);
      }
    } // end constpot == 3

    LED0.LED_on_off(LED0.LEDclear); // clears all LEDs
  } // end  if (test_code == false)
} //end void loop
#include <Arduino.h>
#include <Mulitiplexer.h>
#include <Define.h>

//******************************************Setup******************************//
void Mulitiplexer::init_enable(int pinnumber)
{
  enable_pin_number = pinnumber;
  pinMode(pinnumber, OUTPUT);
} // end init_enable

void Mulitiplexer::init_muxs_input(int pinnumber_mux_a, int pinnumber_mux_b, int pinnumber_mux_c, int pinnumber_mux_d, int pinnumber_mux_e,
                                   int pinnumber_mux_f, int pinnumber_mux_g, int pinnumber_mux_h)
{
  mux_input_pin_a = pinnumber_mux_a;
  mux_input_pin_b = pinnumber_mux_b;
  mux_input_pin_c = pinnumber_mux_c;
  mux_input_pin_d = pinnumber_mux_d;
  mux_input_pin_e = pinnumber_mux_e;
  mux_input_pin_f = pinnumber_mux_f;
  mux_input_pin_g = pinnumber_mux_g;
  mux_input_pin_h = pinnumber_mux_h;

  pinMode(pinnumber_mux_a, INPUT);
  pinMode(pinnumber_mux_b, INPUT);
  pinMode(pinnumber_mux_c, INPUT);
  pinMode(pinnumber_mux_d, INPUT);
  pinMode(pinnumber_mux_e, INPUT);
  pinMode(pinnumber_mux_f, INPUT);
  pinMode(pinnumber_mux_g, INPUT);
  pinMode(pinnumber_mux_h, INPUT);
  //***************************************Test Code***************************//
  if (test_code_mulitiplexer_channel == true)
  {
    Serial.println("Mux A input pin is");
    Serial.println(pinnumber_mux_a);
    Serial.println("Mux b input pin is");
    Serial.println(pinnumber_mux_b);
    Serial.println("Mux c input pin is");
    Serial.println(pinnumber_mux_c);
    Serial.println("Mux d input pin is");
    Serial.println(pinnumber_mux_d);
    Serial.println("Mux e input pin is");
    Serial.println(pinnumber_mux_e);
    Serial.println("Mux f input pin is");
    Serial.println(pinnumber_mux_f);
    Serial.println("Mux g input pin is");
    Serial.println(pinnumber_mux_g);
    Serial.println("Mux h input pin is");
    Serial.println(pinnumber_mux_h);
  } // end test_code_mulitiplexer_channel == true
} // end init_Muxs

void Mulitiplexer::init_muxs_output(int pinnumber_s1, int pinnumber_s2, int pinnumber_s3)
{
  output_pin_channel_s1 = pinnumber_s1;
  output_pin_channel_s2 = pinnumber_s2;
  output_pin_channel_s3 = pinnumber_s3;

  pinMode(output_pin_channel_s1, OUTPUT);
  pinMode(output_pin_channel_s2, OUTPUT);
  pinMode(output_pin_channel_s3, OUTPUT);
} // end init_Muxs_output

//*****************************************Functions***************************//
void Mulitiplexer::set_enable(int enable_HL)
{
  set_enable_HL = enable_HL;
  digitalWrite(enable_pin_number, set_enable_HL);
  //***************************************Test Code***************************//
  if (test_code_mulitiplexer_channel == true)
  {
    if (set_enable_HL == HIGH)
    {
      Serial.println("Mux's are turned off");
    }
    else
    {
      Serial.println("Mux's are on");
    }
  } // end test_code_mulitiplexer_channel == true
} // end set_enable

void Mulitiplexer::channel_select(int s1, int s2, int s3)
{
  channel_select_s1 = s1;
  channel_select_s2 = s2;
  channel_select_s3 = s3;

  digitalWrite(output_pin_channel_s1, channel_select_s1);
  digitalWrite(output_pin_channel_s2, channel_select_s2);
  digitalWrite(output_pin_channel_s3, channel_select_s3);

  //***************************************Test Code***************************//
   if (test_code_mulitiplexer_channel == true)
  {
    Serial.println("output pin for channel s1 is");
    Serial.println(output_pin_channel_s1);
    Serial.println("output pin for channel s2 is");
    Serial.println(output_pin_channel_s2);
    Serial.println("output pin for channel s3 is");
    Serial.println(output_pin_channel_s3);

    Serial.println("output s1 is set to");
    Serial.println(channel_select_s1);
    Serial.println("output s2 is set to");
    Serial.println(channel_select_s2);
    Serial.println("output s3 is set to");
    Serial.println(channel_select_s3);
  } // end test_code_mulitiplexer_channel == true
  delay(1); // adds 1ms delay to allow for caps to discharge
} // end channels_select

int Mulitiplexer::r_mux_A_channel(int comlA_array0, int comlA_array1, int comlA_array2, int comlA_array3,
                                  int comlA_array4, int comlA_array5, int comlA_array6, int comlA_array7)
{
  channel_select(0, 0, 0); // 000
  Serial.println("Block A1");
  read_a = digitalRead(mux_input_pin_a);
  colmA_key_1[0] = read_a;
  Serial.println(colmA_key_1[0]);

  channel_select(1, 0, 0); // 100
  Serial.println("Block A2");
  read_a = digitalRead(mux_input_pin_a);
  colmA_key_1[1]  = read_a;
  Serial.println(colmA_key_1[1]);

  channel_select(0, 1, 0); // 010
  Serial.println("Block A3");
  read_a = digitalRead(mux_input_pin_a);
  colmA_key_1[2] = read_a;
  Serial.println(colmA_key_1[2]);

  channel_select(1, 1, 0); // 110
  Serial.println("Block A4");
  read_a = digitalRead(mux_input_pin_a);
  colmA_key_1[3] = read_a;
  Serial.println(colmA_key_1[3]);

  channel_select(0, 0, 1); // 001
  Serial.println("Block A5");
  read_a = digitalRead(mux_input_pin_a);
  colmA_key_1[4]= read_a;
  Serial.println(colmA_key_1[4]);

  channel_select(1, 0, 1); // 101
  Serial.println("Block A6");
  read_a = digitalRead(mux_input_pin_a);
  colmA_key_1[5] = read_a;
  Serial.println(colmA_key_1[5]);

  channel_select(0, 1, 1); // 011
  Serial.println("Block A7");
  read_a = digitalRead(mux_input_pin_a);
  colmA_key_1[6] = read_a;
  Serial.println(colmA_key_1[6]);

  channel_select(1, 1, 1); // 111
  Serial.println("Block A8");
  read_a = digitalRead(mux_input_pin_a);
  colmA_key_1[7] = read_a;
  Serial.println(colmA_key_1[7]);
  Serial.println("_____________________");
 
  if ((colmA_key_1[0] == comlA_array0) & (colmA_key_1[1] == comlA_array1) & (colmA_key_1[2] == comlA_array2) & (colmA_key_1[3] == comlA_array3) &
      (colmA_key_1[4] == comlA_array4) & (colmA_key_1[5] == comlA_array5) & (colmA_key_1[6] == comlA_array6) & (colmA_key_1[7] == comlA_array7))
  {
    Serial.println("Colm A is equal turn off all LEDs");
    return (true) ;
  }
  else
  {
    return(false);
  }
} // end r_mux_A_channel

int Mulitiplexer::r_mux_B_channel(int comlB_array0, int comlB_array1, int comlB_array2, int comlB_array3,
                                  int comlB_array4, int comlB_array5, int comlB_array6, int comlB_array7)
{
  channel_select(0, 0, 0); // 000
  read_b = digitalRead(mux_input_pin_b);
  colmB_key_1[0] = read_b;

  channel_select(1, 0, 0); // 100
  read_b = digitalRead(mux_input_pin_b);
  colmB_key_1[1] = read_b;

  channel_select(0, 1, 0); // 010
  read_b = digitalRead(mux_input_pin_b);
  colmB_key_1[2] = read_b;

  channel_select(1, 1, 0); // 110
  read_b = digitalRead(mux_input_pin_b);
  colmB_key_1[3] = read_b;

  channel_select(0, 0, 1); // 001
  read_b = digitalRead(mux_input_pin_b);
  colmB_key_1[4] = read_b;

  channel_select(1, 0, 1); // 101
  read_b = digitalRead(mux_input_pin_b);
  colmB_key_1[5] = read_b;

  channel_select(0, 1, 1); // 011
  read_b = digitalRead(mux_input_pin_b);
  colmB_key_1[6] = read_b;

  channel_select(1, 1, 1); // 111
  read_b = digitalRead(mux_input_pin_b);
  colmB_key_1[7] = read_b;
 
  if ((colmB_key_1[0] == comlB_array0) & (colmB_key_1[1] == comlB_array1) & (colmB_key_1[2] == comlB_array2) & (colmB_key_1[3] == comlB_array3) &
      (colmB_key_1[4] == comlB_array4) & (colmB_key_1[5] == comlB_array5) & (colmB_key_1[6] == comlB_array6) & (colmB_key_1[7] == comlB_array7))
  {
    Serial.println("Colm B is equal turn off all LEDs");
    return (true) ;
  }
  else
  {
    return(false);
  }
} // end r_mux_B_channel

int Mulitiplexer::r_mux_C_channel(int comlC_array0, int comlC_array1, int comlC_array2, int comlC_array3,
                                  int comlC_array4, int comlC_array5, int comlC_array6, int comlC_array7)
{
  channel_select(0, 0, 0); // 000
  read_c = digitalRead(mux_input_pin_c);
  colmC_key_1[0] = read_c;

  channel_select(1, 0, 0); // 100
  read_c = digitalRead(mux_input_pin_c);
  colmC_key_1[1] = read_c;

  channel_select(0, 1, 0); // 010
  read_c = digitalRead(mux_input_pin_c);
  colmC_key_1[2] = read_c;

  channel_select(1, 1, 0); // 110
  read_c = digitalRead(mux_input_pin_c);
  colmC_key_1[3] = read_c;

  channel_select(0, 0, 1); // 001
  read_c = digitalRead(mux_input_pin_c);
  colmC_key_1[4] = read_c;

  channel_select(1, 0, 1); // 101
  read_c = digitalRead(mux_input_pin_c);
  colmC_key_1[5] = read_c;

  channel_select(0, 1, 1); // 011
  read_c = digitalRead(mux_input_pin_c);
  colmC_key_1[6] = read_c;

  channel_select(1, 1, 1); // 111
  read_c = digitalRead(mux_input_pin_c);
  colmC_key_1[7] = read_c;
 
  if ((colmC_key_1[0] == comlC_array0) & (colmC_key_1[1] == comlC_array1) & (colmC_key_1[2] == comlC_array2) & (colmC_key_1[3] == comlC_array3) &
      (colmC_key_1[4] == comlC_array4) & (colmC_key_1[5] == comlC_array5) & (colmC_key_1[6] == comlC_array6) & (colmC_key_1[7] == comlC_array7))
  {
    Serial.println("Colm C is equal turn off all LEDs");
    return (true) ;
  }
  else
  {
    return(false);
  }
} // end r_mux_C_channel

int Mulitiplexer::r_mux_D_channel(int comlD_array0, int comlD_array1, int comlD_array2, int comlD_array3,
                                  int comlD_array4, int comlD_array5, int comlD_array6, int comlD_array7)
{
  channel_select(0, 0, 0); // 000
  read_d = digitalRead(mux_input_pin_d);
  colmD_key_1[0] = read_d;

  channel_select(1, 0, 0); // 100
  read_d = digitalRead(mux_input_pin_d);
  colmD_key_1[1] = read_d;

  channel_select(0, 1, 0); // 010
  read_d = digitalRead(mux_input_pin_d);
  colmD_key_1[2] = read_d;

  channel_select(1, 1, 0); // 110
  read_d = digitalRead(mux_input_pin_d);
  colmD_key_1[3] = read_d;

  channel_select(0, 0, 1); // 001
  read_d = digitalRead(mux_input_pin_d);
  colmD_key_1[4] = read_d;

  channel_select(1, 0, 1); // 101
  read_d = digitalRead(mux_input_pin_d);
  colmD_key_1[5] = read_d;

  channel_select(0, 1, 1); // 011
  read_d = digitalRead(mux_input_pin_d);
  colmD_key_1[6] = read_d;

  channel_select(1, 1, 1); // 111
  read_d = digitalRead(mux_input_pin_d);
  colmD_key_1[7] = read_d;
 
  if ((colmD_key_1[0] == comlD_array0) & (colmD_key_1[1] == comlD_array1) & (colmD_key_1[2] == comlD_array2) & (colmD_key_1[3] == comlD_array3) &
      (colmD_key_1[4] == comlD_array4) & (colmD_key_1[5] == comlD_array5) & (colmD_key_1[6] == comlD_array6) & (colmD_key_1[7] == comlD_array7))
  {
    Serial.println("Colm D is equal turn off all LEDs");
    return (true);
  }
  else
  {
    return(false);
  }
} // end r_mux_D_channel

int Mulitiplexer::r_mux_E_channel(int comlE_array0, int comlE_array1, int comlE_array2, int comlE_array3,
                                  int comlE_array4, int comlE_array5, int comlE_array6, int comlE_array7)
{
  channel_select(0, 0, 0); // 000
  read_e = digitalRead(mux_input_pin_e);
  colmE_key_1[0] = read_e;

  channel_select(1, 0, 0); // 100
  read_e = digitalRead(mux_input_pin_e);
  colmE_key_1[1] = read_e;

  channel_select(0, 1, 0); // 010
  read_e = digitalRead(mux_input_pin_e);
  colmE_key_1[2] = read_e;

  channel_select(1, 1, 0); // 110
  read_e = digitalRead(mux_input_pin_e);
  colmE_key_1[3] = read_e;

  channel_select(0, 0, 1); // 001
  read_e = digitalRead(mux_input_pin_e);
  colmE_key_1[4] = read_e;

  channel_select(1, 0, 1); // 101
  read_e = digitalRead(mux_input_pin_e);
  colmE_key_1[5] = read_e;

  channel_select(0, 1, 1); // 011
  read_e = digitalRead(mux_input_pin_e);
  colmE_key_1[6] = read_e;

  channel_select(1, 1, 1); // 111
  read_e = digitalRead(mux_input_pin_e);
  colmE_key_1[7] = read_e;
 
  if ((colmE_key_1[0] == comlE_array0) & (colmE_key_1[1] == comlE_array1) & (colmE_key_1[2] == comlE_array2) & (colmE_key_1[3] == comlE_array3) &
      (colmE_key_1[4] == comlE_array4) & (colmE_key_1[5] == comlE_array5) & (colmE_key_1[6] == comlE_array6) & (colmE_key_1[7] == comlE_array7))
  {
    Serial.println("Colm E is equal turn off all LEDs");
    return (true) ;
  }
  else
  {
    return(false);
  }
} // end r_mux_E_channel

int Mulitiplexer::r_mux_F_channel(int comlF_array0, int comlF_array1, int comlF_array2, int comlF_array3,
                                  int comlF_array4, int comlF_array5, int comlF_array6, int comlF_array7)
{
  channel_select(0, 0, 0); // 000
  read_f = digitalRead(mux_input_pin_f);
  colmF_key_1[0] = read_f;

  channel_select(1, 0, 0); // 100
  read_f = digitalRead(mux_input_pin_f);
  colmF_key_1[1] = read_f;

  channel_select(0, 1, 0); // 010
  read_f = digitalRead(mux_input_pin_f);
  colmF_key_1[2] = read_f;

  channel_select(1, 1, 0); // 110
  read_f = digitalRead(mux_input_pin_f);
  colmF_key_1[3] = read_f;

  channel_select(0, 0, 1); // 001
  read_f = digitalRead(mux_input_pin_f);
  colmF_key_1[4] = read_f;

  channel_select(1, 0, 1); // 101
  read_f = digitalRead(mux_input_pin_f);
  colmF_key_1[5] = read_f;

  channel_select(0, 1, 1); // 011
  read_f = digitalRead(mux_input_pin_f);
  colmF_key_1[6] = read_f;

  channel_select(1, 1, 1); // 111
  read_f = digitalRead(mux_input_pin_f);
  colmF_key_1[7] = read_f;
 
  if ((colmF_key_1[0] == comlF_array0) & (colmF_key_1[1] == comlF_array1) & (colmF_key_1[2] == comlF_array2) & (colmF_key_1[3] == comlF_array3) &
      (colmF_key_1[4] == comlF_array4) & (colmF_key_1[5] == comlF_array5) & (colmF_key_1[6] == comlF_array6) & (colmF_key_1[7] == comlF_array7))
  {
    Serial.println("Colm F is equal turn off all LEDs");
    return (true) ;
  }
  else
  {
    return(false);
  }
} // end r_mux_F_channel

int Mulitiplexer::r_mux_G_channel(int comlG_array0, int comlG_array1, int comlG_array2, int comlG_array3,
                                  int comlG_array4, int comlG_array5, int comlG_array6, int comlG_array7)
{
  channel_select(0, 0, 0); // 000
  read_g = digitalRead(mux_input_pin_g);
  colmG_key_1[0] = read_g;

  channel_select(1, 0, 0); // 100
  read_g = digitalRead(mux_input_pin_g);
  colmG_key_1[1] = read_g;

  channel_select(0, 1, 0); // 010
  read_g = digitalRead(mux_input_pin_g);
  colmG_key_1[2] = read_g;

  channel_select(1, 1, 0); // 110
  read_g = digitalRead(mux_input_pin_g);
  colmG_key_1[3] = read_g;

  channel_select(0, 0, 1); // 001
  read_g = digitalRead(mux_input_pin_g);
  colmG_key_1[4] = read_g;

  channel_select(1, 0, 1); // 101
  read_g = digitalRead(mux_input_pin_g);
  colmG_key_1[5] = read_g;

  channel_select(0, 1, 1); // 011
  read_g = digitalRead(mux_input_pin_g);
  colmG_key_1[6] = read_g;

  channel_select(1, 1, 1); // 111
  read_g = digitalRead(mux_input_pin_g);
  colmG_key_1[7] = read_g;
 
  if ((colmG_key_1[0] == comlG_array0) & (colmG_key_1[1] == comlG_array1) & (colmG_key_1[2] == comlG_array2) & (colmG_key_1[3] == comlG_array3) &
      (colmG_key_1[4] == comlG_array4) & (colmG_key_1[5] == comlG_array5) & (colmG_key_1[6] == comlG_array6) & (colmG_key_1[7] == comlG_array7))
  {
    Serial.println("Colm G is equal turn off all LEDs");
    return (true) ;
  }
  else
  {
    return(false);
  }
} // end r_mux_G_channel

int Mulitiplexer::r_mux_H_channel(int comlH_array0, int comlH_array1, int comlH_array2, int comlH_array3,
                                  int comlH_array4, int comlH_array5, int comlH_array6, int comlH_array7)
{
  channel_select(0, 0, 0); // 000
  read_h = digitalRead(mux_input_pin_h);
  colmH_key_1[0] = read_h;

  channel_select(1, 0, 0); // 100
  read_h = digitalRead(mux_input_pin_h);
  colmH_key_1[1] = read_h;

  channel_select(0, 1, 0); // 010
  read_h = digitalRead(mux_input_pin_h);
  colmH_key_1[2] = read_h;

  channel_select(1, 1, 0); // 110
  read_h = digitalRead(mux_input_pin_h);
  colmH_key_1[3] = read_h;

  channel_select(0, 0, 1); // 001
  read_h = digitalRead(mux_input_pin_h);
  colmH_key_1[4] = read_h;

  channel_select(1, 0, 1); // 101
  read_h = digitalRead(mux_input_pin_h);
  colmH_key_1[5] = read_h;

  channel_select(0, 1, 1); // 011
  read_h = digitalRead(mux_input_pin_h);
  colmH_key_1[6] = read_h;

  channel_select(1, 1, 1); // 111
  read_h = digitalRead(mux_input_pin_h);
  colmH_key_1[7] = read_h;
 
  if ((colmH_key_1[0] == comlH_array0) & (colmH_key_1[1] == comlH_array1) & (colmH_key_1[2] == comlH_array2) & (colmH_key_1[3] == comlH_array3) &
      (colmH_key_1[4] == comlH_array4) & (colmH_key_1[5] == comlH_array5) & (colmH_key_1[6] == comlH_array6) & (colmH_key_1[7] == comlH_array7))
  {
    Serial.println("Colm H is equal turn off all LEDs");
    return (true) ;
  }
  else
  {
    return(false);
  }
} // end r_mux_H_channel

int Mulitiplexer::read_chess_board(int comlA_array0, int comlA_array1, int comlA_array2, int comlA_array3, int comlA_array4, int comlA_array5, int comlA_array6, int comlA_array7,
                                   int comlB_array0, int comlB_array1, int comlB_array2, int comlB_array3, int comlB_array4, int comlB_array5, int comlB_array6, int comlB_array7)
{
    
  if ((r_mux_G_channel(comlA_array0, comlA_array1, comlA_array2, comlA_array3, comlA_array4, comlA_array5, comlA_array6, comlA_array7) == true) &
      (r_mux_F_channel(comlB_array0, comlB_array1, comlB_array2, comlB_array3, comlB_array4, comlB_array5, comlB_array6, comlB_array7) == true))
  {
    Serial.println("This is working");
    return (true) ;
  }
  else
  {
      Serial.println("Not Working");
      return (false) ;
  }

}// end read_chess_board
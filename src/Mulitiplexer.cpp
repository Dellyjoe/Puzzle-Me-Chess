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
  }
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
  }
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
  }
  delay(1); // adds 1ms delay to allow for caps to discharge
} // end channels_select

int Mulitiplexer::r_mux_A_channel()
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
 
  if ((colmA_key_1[0] == colmA_master_1[0]) & (colmA_key_1[1] == colmA_master_1[1]) & (colmA_key_1[2] == colmA_master_1[2]) & (colmA_key_1[3] == colmA_master_1[3]) &
      (colmA_key_1[4] == colmA_master_1[4]) & (colmA_key_1[5] == colmA_master_1[5]) & (colmA_key_1[6] == colmA_master_1[6]) & (colmA_key_1[7] == colmA_master_1[7]))
  {
    Serial.println("ColmA is equal turn off all LEDs");
    return (true) ;
  }
  else
  {
    Serial.println("Master Key requirements not met");
    return(false);
  }
} // end r_mux_A_channel

int Mulitiplexer::r_mux_B_channel()
{
  read_b = digitalRead(mux_input_pin_b);
  //***************************************Test Code***************************//
  if (test_code_mulitiplexer_checkoutput == true)
  {
    if (read_b == HIGH)
    {
      
    }
    else
    {
      Serial.println("Chess Peice is on square");
    }
    return (read_b);
  }
  return (read_b);
} // end r_mux_B_channel

int Mulitiplexer::r_mux_C_channel()
{
  read_c = digitalRead(mux_input_pin_c);
  //***************************************Test Code***************************//
  if (test_code_mulitiplexer_checkoutput == true)
  {
    if (read_c == HIGH)
    {
      
    }
    else
    {
      Serial.println("Chess Peice is on square");
    }
    return (read_c);
  }
  return (read_c);
} // end r_mux_C_channel

int Mulitiplexer::r_mux_D_channel()
{
  read_d = digitalRead(mux_input_pin_d);
  //***************************************Test Code***************************//
  if (test_code_mulitiplexer_checkoutput == true)
  {
    if (read_d == HIGH)
    {
      
    }
    else
    {
      Serial.println("Chess Peice is on square");
    }
    return (read_d);
  }
  return (read_d);
} // end r_mux_D_channel

int Mulitiplexer::r_mux_E_channel()
{
  read_e = digitalRead(mux_input_pin_e);
  //***************************************Test Code***************************//
  if (test_code_mulitiplexer_checkoutput == true)
  {
    if (read_e == HIGH)
    {
      
    }
    else
    {
      Serial.println("Chess Peice is on square");
    }
    return (read_e);
  }
  return (read_e);
} // end r_mux_E_channel

int Mulitiplexer::r_mux_F_channel()
{
  read_f = digitalRead(mux_input_pin_f);
  //***************************************Test Code***************************//
  if (test_code_mulitiplexer_checkoutput == true)
  {
    if (read_f == HIGH)
    {
      
    }
    else
    {
      Serial.println("Chess Peice is on square");
    }
    return (read_f);
  }
  return (read_f);
} // end r_mux_F_channel

int Mulitiplexer::r_mux_G_channel()
{
  read_g = digitalRead(mux_input_pin_g);
  //***************************************Test Code***************************//
  if (test_code_mulitiplexer_checkoutput == true)
  {
    if (read_g == HIGH)
    {
      
    }
    else
    {
      Serial.println("Chess Peice is on square");
    }
    return (read_g);
  }
  return (read_g);
} // end r_mux_G_channel

int Mulitiplexer::r_mux_H_channel()
{
  read_h = digitalRead(mux_input_pin_h);
  //***************************************Test Code***************************//
  if (test_code_mulitiplexer_checkoutput == true)
  {
    if (read_h == HIGH)
    {
      
    }
    else
    {
      Serial.println("Chess Peice is on square");
    }
    return (read_h);
  }
  return (read_h);
} // end r_mux_H_channel



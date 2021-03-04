#include <Arduino.h>
#include <Mulitiplexer.h>

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
//   Serial.println("Mux A input pin is");
//   Serial.println(pinnumber_mux_a);
//   Serial.println("Mux b input pin is");
//   Serial.println(pinnumber_mux_b);
//   Serial.println("Mux c input pin is");
//   Serial.println(pinnumber_mux_c);
//   Serial.println("Mux d input pin is");
//   Serial.println(pinnumber_mux_d);
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
  digitalWrite(enable_pin_number,set_enable_HL );
//***************************************Test Code***************************//
//   if (set_enable_HL == HIGH)
//   {
//     Serial.println("Mux's are turned off");
//   }
//   else
//   {
//     Serial.println("Mux's are on");
//   }
} // end set_enable

int Mulitiplexer::r_mux_channel()
{
  read_a = digitalRead(mux_input_pin_a);
   if (read_a == HIGH)
  {
    Serial.println("Nothing on square");
  }
  else
  {
    Serial.println("Chess Peice is on square");
  }

    return(read_a);
} // end r_mux_channel

void Mulitiplexer::channel_select(int s1, int s2, int s3)
{   
  channel_select_s1 = s1;
  channel_select_s2 = s2;
  channel_select_s3 = s3;

  digitalWrite(output_pin_channel_s1,channel_select_s1 );
  digitalWrite(output_pin_channel_s2,channel_select_s2 );
  digitalWrite(output_pin_channel_s3,channel_select_s3 );

//***************************************Test Code***************************//
//   Serial.println("output pin for channel s1 is");
//   Serial.println(output_pin_channel_s1);
//   Serial.println("output pin for channel s2 is");
//   Serial.println(output_pin_channel_s2);
//   Serial.println("output pin for channel s3 is");
//   Serial.println(output_pin_channel_s3);

//   Serial.println("output s1 is set to");
//   Serial.println(channel_select_s1);
//   Serial.println("output s2 is set to");
//   Serial.println(channel_select_s2);
//   Serial.println("output s3 is set to");
//   Serial.println(channel_select_s3);
} // end channels_select

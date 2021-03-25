#include <Arduino.h>
// Output of the MUX is an input to my Teensy

#define TurnOnChannel1 (0 0 0) // Really channel 0; Set input State C = 0 B = 0 A = 0
#define TurnOnChannel2 (1 0 0) // Really channel 0; Set input State C = 0 B = 0 A = 1

//#define MuxA mux_input_pin_a
// ...
class Mulitiplexer
{
private:
    int enable_pin_number;
    int set_enable_HL;
    int mux_input_pin_a;
    int mux_input_pin_b;
    int mux_input_pin_c;
    int mux_input_pin_d;
    int mux_input_pin_e;
    int mux_input_pin_f;
    int mux_input_pin_g;
    int mux_input_pin_h;
    int output_pin_channel_s1;
    int output_pin_channel_s2;
    int output_pin_channel_s3;
    int channel_select_s1;
    int channel_select_s2;
    int channel_select_s3;
    int read_a;
    int read_b;
    int read_c;
    int read_d;
    int read_e;
    int read_f;
    int read_g;
    int read_h;
    
public:
    void init_enable(int pinnumber); // set a int = 1 to enable -- enabling will turn output off Mux
    void init_muxs_input(int pinnumber_mux_a, int pinnumber_mux_b, int pinnumber_mux_c, int pinnumber_mux_d, int pinnumber_mux_e, 
                   int pinnumber_mux_f, int pinnumber_mux_g, int pinnumber_mux_h); // output of the Mux
    void init_muxs_output(int pinnumber_s1, int pinnumber_s2, int pinnumber_s3);
    void set_enable(int enable_HL); // enable High or Low
    int r_mux_A_channel();
    int r_mux_B_channel(); 
    int r_mux_C_channel(); 
    int r_mux_D_channel(); 
    int r_mux_E_channel(); 
    int r_mux_F_channel();
    int r_mux_G_channel(); 
    int r_mux_H_channel(); 
    void channel_select(int s1, int s2, int s3);  // s1,s2,s3 are selectors for mux channels

}; // end Class Mulitiplexer

//******************************************Output*****************************//
// a = 0, b = 0 , c = 0 channel 0 
// a = 1, b = 0 , c = 0 channel 1
// a = 0, b = 1 , c = 0 channel 2
// a = 0, b = 0 , c = 1 channel 3
// a = 1, b = 0 , c = 0 channel 4
// a = 1, b = 0 , c = 1 channel 5
// a = 1, b = 1 , c = 0 channel 6
// a = 1, b = 1 , c = 1 channel 7
// a = x, b = x , c = x channel none Enable = 1
//*****************************************************************************//

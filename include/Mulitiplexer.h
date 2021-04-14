#include <Arduino.h>
// Output of the MUX is an input to my Teensy

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
    void channel_select(int s1, int s2, int s3);  // s1,s2,s3 are selectors for mux channels
    int r_mux_A_channel(int comlA_array0, int comlA_array1, int comlA_array2, int comlA_array3,
                        int comlA_array4, int comlA_array5, int comlA_array6, int comlA_array7);
    int r_mux_B_channel(int comlB_array0, int comlB_array1, int comlB_array2, int comlB_array3,
                        int comlB_array4, int comlB_array5, int comlB_array6, int comlB_array7); 
    int r_mux_C_channel(int comlC_array0, int comlC_array1, int comlC_array2, int comlC_array3,
                        int comlC_array4, int comlC_array5, int comlC_array6, int comlC_array7); 
    int r_mux_D_channel(int comlD_array0, int comlD_array1, int comlD_array2, int comlD_array3,
                        int comlD_array4, int comlD_array5, int comlD_array6, int comlD_array7); 
    int r_mux_E_channel(int comlE_array0, int comlE_array1, int comlE_array2, int comlE_array3,
                        int comlE_array4, int comlE_array5, int comlE_array6, int comlE_array7); 
    int r_mux_F_channel(int comlF_array0, int comlF_array1, int comlF_array2, int comlF_array3,
                        int comlF_array4, int comlF_array5, int comlF_array6, int comlF_array7);
    int r_mux_G_channel(int comlG_array0, int comlG_array1, int comlG_array2, int comlG_array3,
                        int comlG_array4, int comlG_array5, int comlG_array6, int comlG_array7); 
    int r_mux_H_channel(int comlH_array0, int comlH_array1, int comlH_array2, int comlH_array3,
                        int comlH_array4, int comlH_array5, int comlH_array6, int comlH_array7); 
    int read_chess_board(int comlA_array0, int comlA_array1, int comlA_array2, int comlA_array3, int comlA_array4, int comlA_array5, int comlA_array6, int comlA_array7,
                         int comlB_array0, int comlB_array1, int comlB_array2, int comlB_array3, int comlB_array4, int comlB_array5, int comlB_array6, int comlB_array7,
                         int comlC_array0, int comlC_array1, int comlC_array2, int comlC_array3, int comlC_array4, int comlC_array5, int comlC_array6, int comlC_array7,
                         int comlD_array0, int comlD_array1, int comlD_array2, int comlD_array3, int comlD_array4, int comlD_array5, int comlD_array6, int comlD_array7,
                         int comlE_array0, int comlE_array1, int comlE_array2, int comlE_array3, int comlE_array4, int comlE_array5, int comlE_array6, int comlE_array7,
                         int comlF_array0, int comlF_array1, int comlF_array2, int comlF_array3, int comlF_array4, int comlF_array5, int comlF_array6, int comlF_array7,
                         int comlG_array0, int comlG_array1, int comlG_array2, int comlG_array3, int comlG_array4, int comlG_array5, int comlG_array6, int comlG_array7,
                         int comlH_array0, int comlH_array1, int comlH_array2, int comlH_array3, int comlH_array4, int comlH_array5, int comlH_array6, int comlH_array7);
    
    int colmA_key[8];
    int colmB_key[8];
    int colmC_key[8];
    int colmD_key[8];
    int colmE_key[8];
    int colmF_key[8];
    int colmG_key[8];
    int colmH_key[8];
    //**************Puzzle 1*************************************//
    //*********Start up position*********//
    int colmA_master_1[8] = {1, 0, 1, 1, 1, 1, 0, 0}; // 0 = Peice is on Chess board
    int colmB_master_1[8] = {1, 0, 1, 1, 1, 1, 0, 1}; 
    int colmC_master_1[8] = {0, 0, 0, 0, 1, 0, 0, 0}; 
    int colmD_master_1[8] = {0, 0, 1, 1, 1, 1, 0, 0}; 
    int colmE_master_1[8] = {1, 1, 1, 0, 1, 1, 1, 1}; 
    int colmF_master_1[8] = {1, 0, 1, 1, 1, 1, 0, 0}; 
    int colmG_master_1[8] = {1, 0, 1, 1, 0, 0, 0, 1}; 
    int colmH_master_1[8] = {0, 0, 1, 1, 1, 1, 0, 0}; 
    
    //*********Turn one White*************//
    int colmA_Master_1_M1[8] = {1, 0, 1, 1, 1, 1, 0, 0};
    int colmB_Master_1_M1[8] = {1, 0, 1, 1, 1, 1, 0, 1}; 
    int colmC_Master_1_M1[8] = {0, 0, 0, 0, 1, 0, 0, 0}; 
    int colmD_Master_1_M1[8] = {0, 0, 1, 1, 1, 1, 0, 0}; 
    int colmE_Master_1_M1[8] = {1, 1, 1, 0, 1, 1, 1, 1}; 
    int colmF_Master_1_M1[8] = {1, 0, 1, 1, 1, 1, 1, 0}; 
    int colmG_Master_1_M1[8] = {1, 0, 1, 1, 0, 0, 0, 0}; 
    int colmH_Master_1_M1[8] = {0, 0, 1, 1, 1, 1, 0, 0}; 
    //*********Turn one Black*************//
    int colmA_Master_1_M1_2[8] = {1, 0, 1, 1, 1, 1, 0, 0};
    int colmB_Master_1_M1_2[8] = {1, 0, 1, 1, 1, 1, 0, 1}; 
    int colmC_Master_1_M1_2[8] = {0, 0, 0, 0, 1, 0, 0, 0}; 
    int colmD_Master_1_M1_2[8] = {0, 0, 1, 1, 1, 1, 0, 0}; 
    int colmE_Master_1_M1_2[8] = {1, 1, 1, 0, 1, 1, 1, 1}; 
    int colmF_Master_1_M1_2[8] = {1, 0, 1, 1, 1, 1, 1, 1}; 
    int colmG_Master_1_M1_2[8] = {1, 0, 1, 1, 0, 0, 0, 0}; 
    int colmH_Master_1_M1_2[8] = {0, 0, 1, 1, 1, 1, 0, 0}; 
    //*********Turn two*************//
    int colmA_Master_1_M2[8] = {1, 0, 1, 1, 1, 1, 0, 0};
    int colmB_Master_1_M2[8] = {1, 0, 1, 1, 1, 1, 0, 1}; 
    int colmC_Master_1_M2[8] = {0, 0, 0, 0, 1, 0, 0, 0}; 
    int colmD_Master_1_M2[8] = {0, 0, 1, 1, 1, 1, 0, 0}; 
    int colmE_Master_1_M2[8] = {1, 1, 1, 0, 1, 1, 1, 1}; 
    int colmF_Master_1_M2[8] = {1, 0, 1, 1, 1, 1, 0, 1}; 
    int colmG_Master_1_M2[8] = {1, 0, 1, 1, 1, 0, 0, 0}; 
    int colmH_Master_1_M2[8] = {0, 0, 1, 1, 1, 1, 0, 0};

    //**************Puzzle 2*************************************//
    //*********Start up position*********//
    int colmA_master_2[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmB_master_2[8] = {1, 0, 0, 1, 1, 1, 0, 1}; 
    int colmC_master_2[8] = {1, 1, 1, 1, 0, 1, 1, 1}; 
    int colmD_master_2[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmE_master_2[8] = {1, 0, 1, 1, 1, 1, 1, 1}; 
    int colmF_master_2[8] = {1, 1, 1, 1, 1, 1, 1, 0}; 
    int colmG_master_2[8] = {1, 1, 1, 0, 1, 0, 0, 0}; 
    int colmH_master_2[8] = {0, 1, 0, 1, 1, 1, 1, 1}; 
    //*********Turn one White*************//
    int colmA_master_2_M1[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmB_master_2_M1[8] = {1, 0, 0, 1, 1, 1, 0, 1}; 
    int colmC_master_2_M1[8] = {1, 1, 1, 1, 0, 1, 1, 1}; 
    int colmD_master_2_M1[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmE_master_2_M1[8] = {1, 0, 1, 1, 1, 1, 1, 1}; 
    int colmF_master_2_M1[8] = {1, 1, 1, 1, 1, 0, 1, 0}; 
    int colmG_master_2_M1[8] = {1, 1, 1, 1, 1, 0, 0, 0}; 
    int colmH_master_2_M1[8] = {0, 1, 0, 1, 1, 1, 1, 1};
    //*********Turn one Black*************//
    int colmA_master_2_M1_2[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmB_master_2_M1_2[8] = {1, 0, 0, 1, 1, 1, 0, 1}; 
    int colmC_master_2_M1_2[8] = {1, 1, 1, 1, 0, 1, 1, 1}; 
    int colmD_master_2_M1_2[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmE_master_2_M1_2[8] = {1, 0, 1, 1, 1, 1, 1, 1}; 
    int colmF_master_2_M1_2[8] = {1, 1, 1, 1, 1, 0, 1, 0}; 
    int colmG_master_2_M1_2[8] = {1, 1, 1, 1, 1, 0, 0, 1}; 
    int colmH_master_2_M1_2[8] = {0, 1, 0, 1, 1, 1, 1, 0};
    //*********Turn Two White*************//
    int colmA_master_2_M2[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmB_master_2_M2[8] = {1, 0, 0, 1, 1, 1, 0, 1}; 
    int colmC_master_2_M2[8] = {1, 1, 1, 1, 0, 1, 1, 1}; 
    int colmD_master_2_M2[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmE_master_2_M2[8] = {1, 0, 1, 1, 1, 1, 1, 1}; 
    int colmF_master_2_M2[8] = {1, 1, 1, 1, 1, 0, 1, 0}; 
    int colmG_master_2_M2[8] = {1, 1, 1, 1, 1, 1, 0, 1}; 
    int colmH_master_2_M2[8] = {0, 1, 0, 1, 1, 0, 1, 0};
    //*********Turn Two Black*************//
    int colmA_master_2_M2_2[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmB_master_2_M2_2[8] = {1, 0, 0, 1, 1, 1, 0, 1}; 
    int colmC_master_2_M2_2[8] = {1, 1, 1, 1, 0, 1, 1, 1}; 
    int colmD_master_2_M2_2[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmE_master_2_M2_2[8] = {1, 0, 1, 1, 1, 1, 1, 1}; 
    int colmF_master_2_M2_2[8] = {1, 1, 1, 1, 1, 0, 1, 0}; 
    int colmG_master_2_M2_2[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmH_master_2_M2_2[8] = {0, 1, 0, 1, 1, 0, 1, 0};
    //*********Turn Three White***********//
    int colmA_master_2_M3[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmB_master_2_M3[8] = {1, 0, 0, 1, 1, 1, 1, 1}; 
    int colmC_master_2_M3[8] = {1, 1, 1, 1, 0, 1, 1, 1}; 
    int colmD_master_2_M3[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmE_master_2_M3[8] = {1, 0, 1, 1, 1, 1, 1, 1}; 
    int colmF_master_2_M3[8] = {1, 1, 1, 1, 1, 0, 1, 0}; 
    int colmG_master_2_M3[8] = {1, 1, 1, 1, 1, 1, 1, 1}; 
    int colmH_master_2_M3[8] = {0, 0, 0, 1, 1, 0, 1, 0};

    //**************Puzzle 3*************************************//
    //*********Start up position*********//
}; // end Class Mulitiplexer

//******************************************Output*****************************//
// a = 0, b = 0 , c = 0 channel 0 
// a = 1, b = 0 , c = 0 channel 1
// a = 0, b = 1 , c = 0 channel 2
// a = 1, b = 1 , c = 0 channel 3
// a = 0, b = 0 , c = 1 channel 4
// a = 1, b = 0 , c = 1 channel 5
// a = 0, b = 1 , c = 1 channel 6
// a = 1, b = 1 , c = 1 channel 7
// a = x, b = x , c = x channel none Enable = 1
//*****************************************************************************//

// Output of the MUX is an input to my Teensy

#define TurnOnChannel1 // Really channel 0; Set input State C = 0 B = 0 A = 0
#define TurnOnChannel2 // Really channel 0; Set input State C = 0 B = 0 A = 1
// ...
class MULITIPLEXER
{
private:
public:
    void enable();
    void r_input_A();
    void r_input_B();
    void r_input_C();
    void r_input_D();
    void r_input_E();
    void r_input_F();
    void r_input_G();
    void r_input_H();
    void r_output(int x, int y, int Z); // <-- change to match the datasheet

}; // end Class MULITIPLEXER
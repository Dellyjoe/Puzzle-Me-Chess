#include <Arduino.h>

class Switch
{
private:
    int switch_pin_number;
    int switchstate;
    
public:
    void init_switch(int pinnumber);
    int r_switch();
}; // end Class SWITCH
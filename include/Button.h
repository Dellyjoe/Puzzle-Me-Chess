#include <Arduino.h>

class Button
{
private:
    int button_pin_number;
    int buttonstate;

public:
    int r_button();
    void init_button(int pinnumber);
}; // end Class BUTTON
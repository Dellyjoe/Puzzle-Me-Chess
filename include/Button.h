#include <Arduino.h>

class Button
{
private:
    int button_pin_number;
    int buttonstate;

public:
    void init_button(int pinnumber);
    int r_button();
}; // end Class BUTTON7
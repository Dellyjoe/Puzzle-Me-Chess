#include <Arduino.h>

class Button
{
private:
const int button1 = 1;
int buttonstate1 = 0; 
public:
int r_button();
void init_button();
}; // end Class BUTTON
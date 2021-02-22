#include <Arduino.h>

class Potentiometer
{
private:
  int pot_pin_number;
  int mapp_low;
  int mapp_high;
public:
  int r_pot();
  void init_pot(int pinnumber, int low, int high);
}; // end Class Potentiometer
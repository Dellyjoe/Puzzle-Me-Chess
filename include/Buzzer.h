#include <Arduino.h>

class Buzzer
{
private:
  int buzzer_pin_number;

public:
  void init_buzzer(int pinnumber);
  void write_buzzer();
  void turn_off_buzzer();
}; // end Class Potentiometer
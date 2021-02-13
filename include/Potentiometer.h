#include <Arduino.h>

class Potentiometer
{
private:
  const int pot1 = analogRead(0); // Local variable  pot on pin A0
public:
  int r_pot();
  void init_pot();
}; // end Class Potentiometer
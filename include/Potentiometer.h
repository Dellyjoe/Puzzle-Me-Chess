#include <Arduino.h>

class Potentiometer
{
private:
  const int pot1 = analogRead(0); // Local varable pot on pin A0
public:
  int r_pot();
}; // end Class Potentiometerread
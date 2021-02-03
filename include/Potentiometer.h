#include <Arduino.h>

class Potentiometer
{
private:
  const int pot1 = analogRead(0); // Local varable pot on pin A0
  const int pot2 = analogRead(2); // Local varable pot on pin A2
public:
  int getpot1();
  int getpot2();
}; // end Class Potentiometerread
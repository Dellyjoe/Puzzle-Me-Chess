#include <Arduino.h>

class Potentiometer
{
private:
  const int pot1 = analogRead(0); // Local varable pot on pin A0
  const int pot2 = analogRead(2); // Local varable pot on pin A2
public:
  void potread();
  void mapp();

  int getpot1(); //<-- See if you need this 
  int getpot2(); //<-- See if you need this 
}; // end Class Potentiometerread
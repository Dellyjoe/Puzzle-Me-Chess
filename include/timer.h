#include <Arduino.h>
#include <G_structure.h>
class Timerhour
{
private:
  const int relay = 13;
  int runingtimer;
  int replaystate = LOW;            // init state for the relay
  unsigned long previousMillis = 0; // stores last updated vaule of relay
  unsigned int timerinterval;       // Interval for relay blink

public:
  void setuptimer();
  int timer(struct timeralarmpara &Timervalues);
  String getRelayString();
  void alarm();
}; // end class LED
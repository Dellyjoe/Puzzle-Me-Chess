#include <timer.h>
#include <OLED_RTC.h>
#include <Wire.h>

//******************************************Setup*****************************//
void Timerhour::setuptimer()
{
  pinMode(relay, OUTPUT); // setting pin 13 to an output pin
} //end setup

//*****************************************Functions**************************//

int Timerhour::timer(struct timeralarmpara &Timervalues)
{
  timerinterval = Timervalues.timer;
  // if (Timervalues.timer != timerinterval)
  // {
  //  timerinterval = Timervalues.timer;
  //  return (timerinterval);
  //}
  //else
  //{
  //  //do nothing
  //}

  //Serial.print(Timervalues.timer);
  //Serial.println();
  //delay(1000);

  //check to see if it is time to turn on the relay
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillis) >= timerinterval)
  {
    // save the last time you turned on the relay
    previousMillis = currentMillis;

    // if the relay is off turn it on and vice-versa:
    if (replaystate == LOW)
    {

      replaystate = HIGH;
    }
    else
    {

      replaystate = LOW;
    }
    digitalWrite(relay, replaystate); // setting the relay state to the relay pinout
  }
  runingtimer = (currentMillis - previousMillis) / 1000;

  return (runingtimer);
} // end timer

String Timerhour::getRelayString()
{
  if (replaystate == LOW)
  {
    return "OFF";
  }
  else if (replaystate == HIGH)
  {
    return "ON";
  }
  else
  {
    return "UNKNOWN";
  }
}

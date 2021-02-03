#include <U8g2lib.h> // OLED
#ifdef U8X8_HAVE_HW_I2C
#endif
#include <Wire.h>
#include "RTClib.h"

class OLED
{
private:
public:
  void intdisplay();
  void OLEDdraw(int currenttimer, String RelayString);
  void clocktimerset(int potvalue1, int potvalue2);
  void sendvaluestimer(struct timeralarmpara &Timervalues, int potvalue1, int potvalue2);
};                     // end class OLED
void OLEDflag();       //interrupt function is a global function
void SendValuesflag(); //interrupt function is a global function
void alarm_now();

#include <U8g2lib.h> // Display
#ifdef U8X8_HAVE_HW_I2C
#endif
#include <Wire.h>


class Display
{
private:

public:
  void int_display();
  void clear();
  void print(int x , int y, int value); //<-- fix inputs //int x, int y, int vaule
  void clocktimerset(int potvalue1); //< -- get ride of 
};                     // end class Display
void OLEDflag();       //interrupt function is a global function<-- move this to the correct part
void SendValuesflag(); //interrupt function is a global function <-- move to the button h file 


//class DisplaySM::DisplaySM : Display

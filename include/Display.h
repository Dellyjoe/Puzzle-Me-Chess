#include <U8g2lib.h> // OLED
#ifdef U8X8_HAVE_HW_I2C
#endif
#include <Wire.h>


class Display
{
private:

public:
  void int_display();
  void draw();
  void clear();
  void print(int x, int y, int vaule); //<-- fix inputs 
  void clocktimerset(int potvalue1, int potvalue2); //< -- get ride of 
  void sendvaluestimer(struct timeralarmpara &Timervalues, int potvalue1, int potvalue2); //< -- get ride of 
};                     // end class OLED
void OLEDflag();       //interrupt function is a global function<-- move this to the correct part
void SendValuesflag(); //interrupt function is a global function <-- move to the button h file 


//class DisplaySM::DisplaySM : Display

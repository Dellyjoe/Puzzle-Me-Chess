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
  void draw();
  void print_select_puzzle(int x, int y, int value); //<-- fix inputs //int x, int y, int vaule
  void print_user_puzzle(int a, int b, int value1);
  void print_piece_location(String line_one, String line_two, String line_three, String line_four);
}; // end class Display

//class DisplaySM::DisplaySM : Display

class Smdisplay : public Display
{
private:
public:
}; // end sub class Smdisplay

class Bigdisplay : public Display
{
private:
public:
}; // end sub class Bigdisplay
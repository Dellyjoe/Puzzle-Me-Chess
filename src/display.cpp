#include <Display.h>
#include <Potentiometer.h>

//******************************************Declare*****************************//
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
//******************************************Setup*****************************//
void Display::int_display()
{
    u8g2.begin(); // Start the Library code for the Display
} // end void int_display
//*****************************************Functions**************************//
void Display::print_select_puzzle(int x, int y, int value)
{   
    u8g2.setFlipMode(1);             // Flips display 180 (1) = True
    u8g2.setFont(u8g2_font_9x18_tf); // choose a suitable font
    u8g2.drawStr(0, 12, "Select Puzzle");
    u8g2.drawStr(x, y, "#");
    u8g2.setCursor(60, 30); // set cursor location
    u8g2.print(value);
} // end void print_select_puzzle

void Display::print_user_puzzle(int a, int b, int value1)
{
u8g2.setFlipMode(1);
u8g2.setFont(u8g2_font_9x18_tf); 
u8g2.drawStr(0, 12, "User Selected");
u8g2.drawStr(a, b, "#");
u8g2.setCursor(15, 30); 
u8g2.print(value1);
u8g2.drawStr(30, 30, "Puzzle");
} // end void print_user_puzzle

void Display::clear() 
{
 u8g2.clearBuffer(); // clear the internal memory
} // end void clear

void Display::draw() 
{
 u8g2.sendBuffer(); // transfer internal memory to the display
} // end void clear
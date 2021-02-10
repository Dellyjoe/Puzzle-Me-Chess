#include <Display.h>
#include <Potentiometer.h>

//******************************************Declare*****************************//
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
//******************************************Setup*****************************//
void Display::int_display()
{
    u8g2.begin(); // Start the Library code for the OLED
} // end void intdisplay
//*****************************************Functions**************************//
void Display::print(int x, int y, int value)
{   

    u8g2.clearBuffer();              // clear the internal memory
    u8g2.setFlipMode(1);             // Flips display 180 (1) = True
    u8g2.setFont(u8g2_font_9x18_tf); // choose a suitable font
    u8g2.drawStr(0, 12, "Select Puzzle");
    u8g2.drawStr(x, y, "#");
    u8g2.setCursor(60, 30); // set cursor location
    u8g2.print(value);
    u8g2.sendBuffer(); // transfer internal memory to the display
} // end void OLEDdraw

// void OLEDflag() // Switch Flag
// {
//     while (digitalRead(0) == HIGH)
//     {
//         Display Display1;
//         Potentiometer potentiometer1; // why should I use a different Object here ? is it because it is a saporate .cpp file?
//         Display1.clocktimerset(potentiometer1.mapp1());
//     }
// } // end void OLEDflag

// void Display::clocktimerset(int potvalue1)
// {
//     u8g2.clearBuffer();                 // clear the internal memory
//     u8g2.setFont(u8g2_font_helvB12_te); // choose a suitable font
//     u8g2.clearBuffer();                 // clears current display
//     u8g2.drawStr(0, 20, "Timer:");
//     u8g2.drawStr(75, 20, "Hours");
//     u8g2.setCursor(53, 20); // set cursor location
//     u8g2.print(potvalue1);
//     u8g2.sendBuffer();
    
//} //end void clocktimerset

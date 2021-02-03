#include <G_structure.h>
#include <OLED_RTC.h>
#include <Potentiometer.h>

//******************************************Declare*****************************//
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
RTC_DS3231 rtc;
//******************************************Setup*****************************//

void OLED::intdisplay()
{
    u8g2.begin(); // Start the Library code for the OLED
} // end void intdisplay
//*****************************************Functions**************************//
void OLED::OLEDdraw(int currenttimer, String RelayString)
{
    DateTime now = rtc.now();
    // Sending current time to OLED
    u8g2.clearBuffer();              // clear the internal memory
    u8g2.setFlipMode(1);             // Flips display 180 (1) = True
    u8g2.setFont(u8g2_font_6x12_te); // choose a suitable font
    u8g2.drawStr(0, 7, "Time:");
    u8g2.setCursor(32, 7);       // set cursor location
    u8g2.print(now.hour(), DEC); // print at current cursor location
    u8g2.setCursor(45, 7);
    u8g2.print(':');
    u8g2.setCursor(54, 7);
    u8g2.print(now.minute(), DEC);
    u8g2.setCursor(70, 7);
    u8g2.print(':');
    u8g2.setCursor(78, 7);
    u8g2.print(now.second(), DEC);

    // Sending current Date to OLED
    u8g2.setCursor(0, 20);
    u8g2.print("Date:");
    u8g2.setCursor(30, 20);
    u8g2.print(now.month(), DEC);
    u8g2.setCursor(40, 20);
    u8g2.print('/');
    u8g2.setCursor(50, 20);
    u8g2.print(now.day(), DEC);
    u8g2.setCursor(63, 20);
    u8g2.print('/');
    u8g2.setCursor(73, 20);
    u8g2.print(now.year(), DEC);

    // Displaying Timer information to OLED
    u8g2.drawStr(0, 35, "Relay State:");
    u8g2.setCursor(72, 35);
    u8g2.print(RelayString);
    u8g2.drawStr(0, 50, "Runing Timer(s):");
    u8g2.setCursor(0, 60);
    u8g2.print(currenttimer); // print at current cursor location
    u8g2.sendBuffer();        // transfer internal memory to the display
} // end void OLEDdraw

void OLEDflag() // Switch Flag
{
    while (digitalRead(0) == HIGH && digitalRead(1) == LOW)
    {
        OLED OLED1;
        Potentiometer Potentiometer1; // why should I use a different Object here ? is it because it is a saporate .cpp file?
        OLED1.clocktimerset(Potentiometer1.getpot1(), Potentiometer1.getpot2());
    }
} // end void OLEDflag

void SendValuesflag() // Button Flag
{
    struct timeralarmpara tap; // declare a new variable named tap
    while (digitalRead(1) == HIGH && digitalRead(0) == HIGH)
    {
        OLED OLED2;
        Potentiometer Potentiometer2;
        OLED2.sendvaluestimer(tap, Potentiometer2.getpot1(), Potentiometer2.getpot2());
        break;
    }
    Serial.print("I am tap.timer :");
    Serial.print(tap.timer);
    Serial.println();
    Serial.print("I am tap.clock: ");
    Serial.print(tap.clockset);
    Serial.println();
} // end void SendValuesflag

void OLED::clocktimerset(int potvalue1, int potvalue2)
{
    u8g2.clearBuffer();                 // clear the internal memory
    u8g2.setFont(u8g2_font_helvB12_te); // choose a suitable font
    u8g2.clearBuffer();                 // clears current display
    u8g2.drawStr(0, 20, "Timer:");
    u8g2.drawStr(75, 20, "Hours");
    u8g2.setCursor(53, 20); // set cursor location
    u8g2.print(potvalue1);
    u8g2.drawStr(0, 40, "Timer Alarm:");
    u8g2.drawStr(22, 58, "- Start Hour");
    u8g2.setCursor(0, 58);
    u8g2.print(potvalue2);
    u8g2.sendBuffer();
} //end void clocktimerset

// struct timeralarmpara &Timervalues (maps tap to Timervalues)
void OLED::sendvaluestimer(struct timeralarmpara &Timervalues, int potvalue1, int potvalue2)
{
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB12_te);
    u8g2.drawStr(35, 25, "Vaules");
    u8g2.drawStr(35, 45, "Saved!");
    u8g2.sendBuffer();

    Timervalues.timer = (potvalue1); // setting timer to  hour length in sec
    Timervalues.clockset = potvalue2;

    Serial.print("New timer Length: ");
    Serial.print(Timervalues.timer);
    Serial.println();
    Serial.print("New clock start alarm: ");
    Serial.print(Timervalues.clockset);
    Serial.println();
    delay(500);
} // ending sendvaluestimer

void alarm_now()
{
    rtc.writeSqwPinMode(DS3231_OFF); // sets clock pin to become an interrupt
    rtc.clearAlarm(1);
    rtc.disableAlarm(1);
    DateTime alarm1(2019, 4, 28, 14, 0, 0); // find out the code for this.
    rtc.setAlarm1(alarm1, DS3231_A1_Hour);
    pinMode(24, OUTPUT);
    digitalWrite(24, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(15000);           // wait for a second
    digitalWrite(24, LOW);  // turn the LED off by making the voltage LOW
    delay(1000);
    rtc.clearAlarm(1);
}
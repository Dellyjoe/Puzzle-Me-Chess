
class LED
{
private:
    int index = 0; 
public:
    void init_LED();
    void LED_on_off(int LEDarry[]);

//******************************************LEDS***************************/
    int LED1[7] = {OUTPUT, INPUT, OUTPUT, INPUT, INPUT, 1 , 3};
    int LED2[7] = {INPUT, OUTPUT, OUTPUT, INPUT, INPUT, 2 , 3};
    int LED3[7] = {OUTPUT, INPUT, INPUT, OUTPUT, INPUT, 1 , 4};
    int LED4[7] = {INPUT, OUTPUT, INPUT, OUTPUT, INPUT, 2 , 4};
    int LED5[7] = {OUTPUT, INPUT, INPUT, INPUT, OUTPUT, 1, 5};
    int LED6[7] = {INPUT, OUTPUT, INPUT, INPUT, OUTPUT, 2 , 5};
    int LEDclear[7] = {INPUT, INPUT, INPUT, INPUT, INPUT, 0 , 0};
}; // end Class LED
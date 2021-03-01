
class LED
{
private:
    int index = 0; 
public:
    void turn_on();
    void turn_off();
    void init_LED();
    void charlie(int LEDarry[]);

//******************************************LEDS***************************//
    int LEDA1[3] = {HIGH, LOW ,-1};
    int LEDA2[3] = {LOW, HIGH, -1};
    int LEDA3[3] = {LOW, -1, HIGH};
    int LEDB1[3] = {HIGH, -1, LOW};
    int LEDB2[3] = {-1, HIGH, LOW};
    int LEDB3[3] = {-1, LOW, HIGH};
    int LEDclear[3] = {-1,-1, -1}; //clears all LEDS
}; // end Class LED
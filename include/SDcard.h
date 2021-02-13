#include <Arduino.h>
#include <SD.h>  // SD card library 
#include <SPI.h> // SD card library 

class SDcard
{
private:
public: 
    void int_SD();
    void open();
    void mapp();
    void print();
    void close();
}; // end Class SDcard
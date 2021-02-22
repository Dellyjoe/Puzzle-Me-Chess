#include <Arduino.h>
#include <SD.h>  // SD card library 
#include <SPI.h> // SD card library 

class SDcard
{
private:
public: 
    void int_SD();
    void print_SD_info();
    void openfile();
    void mapp();
    void printfiles();
    void close();

    // figure out how to pass a spring to use close() and open() as a mobuler funtion
}; // end Class SDcard
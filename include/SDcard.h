#include <Arduino.h>
#include <SD.h>  // SD card library 
#include <SPI.h> // SD card library 

class SDcard
{
private:
public: 
    void print_SD_info();
    void int_SD();
    void openfile();
    void mapp();
    void print();
    void printDirectory(File dir, int numTabs);
    void close();
}; // end Class SDcard
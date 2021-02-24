#include <Arduino.h>
#include <SD.h>  // SD card library
#include <SPI.h> // SD card library

class SDcard
{
private:

   
   //{"1015704.CSV" ,"561534.CSV", "1036958.CSV"};
   // char mapp_arry [] [];
    
public:
    void int_SD();
    void print_SD_info();
    void openfile();
    void mapp();
    void printfiles();
    void close();
    const char* str_puzzle_name[12] = {"1015704.CSV","561534.CSV","1036958.CSV"};
    

    // figure out how to pass a spring to use close() and open() as a mobuler funtion
}; // end Class SDcard
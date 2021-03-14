#include <Arduino.h>
#include <SD.h>  // SD card library
#include <SPI.h> // SD card library

class SDcard
{
private:
    const char* str_puzzle_name[12] = {"1015704.CSV","561534.CSV","1036958.CSV"};
    int filename_index;

public:
    void int_SD();
    void print_SD_info();
    void open_file(int indexer);
    void mapp();
    void print_directory();
    void close();   
    size_t readField(File* file, char* str, size_t size, char* delim);
    void readchesspuzzle();
    // figure out how to pass a spring to use close() and open() as a mobuler funtion
}; // end Class SDcard
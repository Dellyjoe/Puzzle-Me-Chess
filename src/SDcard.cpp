#include <Arduino.h>
#include <SDcard.h>

//******************************************Declare****************************//
Sd2Card card;
SdVolume volume;
SdFile root;
#define CS_PIN BUILTIN_SDCARD

// 5 X 4 array
#define ROW_DIM 5
#define COL_DIM 4

#define errorHalt(msg)          \
    {                           \
        Serial.println(F(msg)); \
        while (1)               \
            ;                   \
    }
//******************************************Setup******************************//
void SDcard::int_SD()
{
    while (!Serial)
        ;
    if (!SD.begin(CS_PIN))
    {
        Serial.println("initialization failed. Things to check:");
        Serial.println("1. is a card inserted?");
        Serial.println("2. is your wiring correct?");
        Serial.println("3. did you change the chipSelect pin to match your shield or module?");
        Serial.println("Note: press reset or reopen this serial monitor after fixing your issue!");
        while (true)
            ;
    }
    Serial.println("initialization of SD card = done.");
} // end of int_SD

//*****************************************Functions***************************//
void SDcard::print_SD_info()
{
    // we'll use the initialization code from the utility libraries
    // since we're just testing if the card is working!
    if (!card.init(SPI_HALF_SPEED, CS_PIN))
    {
        Serial.println("initialization failed. Things to check:");
        Serial.println("* is a card inserted?");
        Serial.println("* is your wiring correct?");
        Serial.println("* did you change the chipSelect pin to match your shield or module?");
        return;
    }
    else
    {
        Serial.println("Wiring is correct and a card is present.");
    }

    // print the type of card
    Serial.print("\nCard type: ");
    switch (card.type())
    {
    case SD_CARD_TYPE_SD1:
        Serial.println("SD1");
        break;
    case SD_CARD_TYPE_SD2:
        Serial.println("SD2");
        break;
    case SD_CARD_TYPE_SDHC:
        Serial.println("SDHC");
        break;
    default:
        Serial.println("Unknown");
    }

    // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
    if (!volume.init(card))
    {
        Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
        return;
    }

    // print the type and size of the first FAT-type volume
    uint32_t volumesize;
    Serial.print("\nVolume type is FAT");
    Serial.println(volume.fatType(), DEC);
    Serial.println();

    volumesize = volume.blocksPerCluster(); // clusters are collections of blocks
    volumesize *= volume.clusterCount();    // we'll have a lot of clusters
    if (volumesize < 8388608ul)
    {
        Serial.print("Volume size (bytes): ");
        Serial.println(volumesize * 512); // SD card blocks are always 512 bytes
    }
    Serial.print("Volume size (Kbytes): ");
    volumesize /= 2;
    Serial.println(volumesize);
    Serial.print("Volume size (Mbytes): ");
    volumesize /= 1024;
    Serial.println(volumesize);

} // end print_SD_info

void SDcard::open_file(int indexer)
{
    filename_index = indexer;

    if (!SD.begin(CS_PIN))
    {
        while (true)
            ;
    }
    File dataFile = SD.open(str_puzzle_name[filename_index]); //opening File T015704.csv

    // if the file is available, write to it:

    if (dataFile)
    {
        while (dataFile.available())
        {
            Serial.write(dataFile.read());
        }
        dataFile.close();
    }

    // if the file isn't open, pop up an error:

    else
    {
        Serial.println("error opening file");
    }

} // end openfile

void SDcard::print_directory()
{
    // we'll use the initialization code from the utility libraries
    // since we're just testing if the card is working!
    if (!card.init(SPI_HALF_SPEED, CS_PIN))
    {
        Serial.println("initialization failed. Things to check:");
        Serial.println("* is a card inserted?");
        Serial.println("* is your wiring correct?");
        Serial.println("* did you change the chipSelect pin to match your shield or module?");
        return;
    }
    else
    {
        Serial.println("Wiring is correct and a card is present.");
    }

    if (!volume.init(card))
    {
        Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
        return;
    }

    //print the type and size of the first FAT-type volume
    // Serial.println("\nFiles found on the card (name, date and size in bytes): ");
    // root.openRoot(volume);

    // list all files in the card with date and size
    root.ls(LS_R | LS_DATE | LS_SIZE);
    root.close();
} // end print_directory()

size_t SDcard::readField(File *file, char *str, size_t size, char *delim)
{
    char ch;
    size_t n = 0;
    while ((n + 1) < size && file->read(&ch, 1) == 1)
    {
        // Delete CR.
        if (ch == '\r')
        {
            continue;
        }
        str[n++] = ch;
        if (strchr(delim, ch))
        {
            break;
        }
    }
    str[n] = '\0';
    return n;
}

void SDcard::readchesspuzzle()
{
    File file;
    // Initialize the SD.
    if (!SD.begin(CS_PIN))
    {
        errorHalt("begin failed");
    }
    // Create or open the file.
    file = SD.open("12READNUM.TXT", FILE_WRITE);
    if (!file)
    {
        errorHalt("open failed");
    }
    // Rewind file so test data is not appended.
    file.seek(0);

    // Write test data.
    file.print(F(
        "11,12,13,14\r\n"
        "21,22,23,24\r\n"
        "31,32,33,34\r\n"
        "41,42,43,44\r\n"
        "51,52,53,54" // Allow missing endl at eof.
        ));

    // Rewind the file for read.
    file.seek(0);

    // Array for data.
    int array[ROW_DIM][COL_DIM];
    int i = 0;    // First array index.
    int j = 0;    // Second array index
    size_t n;     // Length of returned field with delimiter.
    char str[20]; // Must hold longest field with delimiter and zero byte.
    char *ptr;    // Test for valid field.

    // Read the file and store the data.

    for (i = 0; i < ROW_DIM; i++)
    {
        for (j = 0; j < COL_DIM; j++)
        {
            n = readField(&file, str, sizeof(str), ",\n");
            if (n == 0)
            {
                errorHalt("Too few lines");
            }
            array[i][j] = strtol(str, &ptr, 10);
            if (ptr == str)
            {
                errorHalt("bad number");
            }
            if (j < (COL_DIM - 1) && str[n - 1] != ',')
            {
                errorHalt("line with too few fields");
            }
        }
        // Allow missing endl at eof.
        if (str[n - 1] != '\n' && file.available())
        {
            errorHalt("missing endl");
        }
    }

    // Print the array.
    for (i = 0; i < ROW_DIM; i++)
    {
        for (j = 0; j < COL_DIM; j++)
        {
            if (j)
            {
                Serial.print(' ');
            }
            Serial.print(array[i][j]);
        }
        Serial.println();
    }
    Serial.println("Done");
    file.close();
}
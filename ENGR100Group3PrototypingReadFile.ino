#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"
#include <SPI.h>
#include <SD.h>

File myFile;
bool loopRunning = false;
Adafruit_AM2320 am2320 = Adafruit_AM2320();
const int chipSelect = 4;
int x = 0;
int deletefile = 1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

while (!Serial){ ;
}

{
   Serial.print("Initializing SD card..."); //initialize sd card
  if (!SD.begin(4)) {
    Serial.println("SD card initialization failed. Please Check if SD Card is inserted.");
    while (1);
  }
  Serial.println("SD card initialization complete.");

 myFile = SD.open("initdata.txt");
  if (myFile) {
    Serial.println("initdata.txt:");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening initdata.txt");
      }
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}

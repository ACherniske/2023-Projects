#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"
#include <SPI.h>
#include <SD.h>

File myFile;
bool loopRunning = false;
Adafruit_AM2320 am2320 = Adafruit_AM2320();
const int chipSelect = 4;
int x = 0;
int deletefile = 0;

void setup() {

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

if (deletefile == 1){
 Serial.println("Removing Previous File");
      SD.remove("initdata.txt");
  } else {
  Serial.println("Keeping Previous Data");
}
      
  Serial.println("Starting AM2320 Baseline Test...");
    am2320.begin();
    
    Serial.print("Temp: "); Serial.println(am2320.readTemperature()); //Serial Print Temperature
    Serial.print("Hum: "); Serial.println(am2320.readHumidity()); //Serial Print Humidity
      delay(2000);
    Serial.print("Temp: "); Serial.println(am2320.readTemperature()); //Serial Print Temperature
    Serial.print("Hum: "); Serial.println(am2320.readHumidity()); //Serial Print Humidity
      delay(2000);
    Serial.print("Temp: "); Serial.println(am2320.readTemperature()); //Serial Print Temperature
    Serial.print("Hum: "); Serial.println(am2320.readHumidity()); //Serial Print Humidity
      delay(2000);

    Serial.println("Sensor Test Complete");
    
  myFile = SD.open("initdata.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to initdata.txt...");
    myFile.println("SD Write and Read Test Success");
    myFile.println("Begin Data");
    // close the file:
    myFile.close();
    Serial.println("complete.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening initdata.txt");
  }

  // re-open the file for reading:
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
void loop(){
  // put your main code here, to run repeatedly:
 myFile = SD.open("initdata.txt", FILE_WRITE);
   if (myFile) {
   Serial.print("Temp: "); Serial.println(am2320.readTemperature()); //Serial Print Temperature
   Serial.print("Hum: "); Serial.println(am2320.readHumidity()); //Serial Print Humidity
   myFile.print("Min "); myFile.print(x+1); myFile.print(": "); myFile.print("Temp: "); myFile.print(am2320.readTemperature()); myFile.print("Humi: ");myFile.println(am2320.readHumidity()); //File Print Data
   myFile.close();
   x++;
   delay(60000);
  } else {
    Serial.print("File Error");
  }
}

#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"
#include <SPI.h>
#include <SD.h>

File myFile;
Adafruit_AM2320 am2320 = Adafruit_AM2320();
const int chipSelect = 4; //pin 4 for SD Shield
int x = 0; //Starting Value for counter
int deletefile = 0; //0=do not delete; 1=delete


void setup() {

//Serial Start
  Serial.begin(9600);
  while (!Serial){ ;
    }

//SD Initialization
  {
    Serial.print("Initializing SD card..."); //initialize SD Card
  if (!SD.begin(4)) {
    Serial.println("SD card initialization failed. Please Check if SD Card is inserted."); //Initialization Failed
    while (1);
    }
    Serial.println("SD card initialization complete."); //Initialization Success

//Delete File
    if (deletefile == 1){
 Serial.println("Removing Previous File"); //File Clear
      SD.remove("initdata.txt");
    } else {
  Serial.println("Keeping Previous Data"); //File Keep
    }

//Temperature Sensor Test
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

//Write Test
  myFile = SD.open("initdata.txt", FILE_WRITE);

  //if the file opened okay, write to it:
    if (myFile) {
  Serial.print("Writing to initdata.txt...");
    myFile.println("SD Write and Read Test Success");
    myFile.println("Begin Data");
    //close the file:
    myFile.close();
  Serial.println("complete.");
      } else {

  //if the file didn't open, print an error:
  Serial.println("error opening initdata.txt");
    }

//Read Test
  myFile = SD.open("initdata.txt");
  if (myFile) {
    Serial.println("initdata.txt:");

//read from the file until there's nothing else in it:
  while (myFile.available()) {
    Serial.write(myFile.read());
    }
  //close the file:
    myFile.close();
    } else {
  //if the file didn't open, print an error:
    Serial.println("error opening initdata.txt");
    }
  }
}
void loop() {
//Data Recording
  myFile = SD.open("initdata.txt", FILE_WRITE); //Open File
     if (myFile) {
       Serial.print("Temp: "); Serial.println(am2320.readTemperature()); //Serial Print Temperature
       Serial.print("Hum: "); Serial.println(am2320.readHumidity()); //Serial Print Humidity
       myFile.print("Min "); myFile.print(x+1); myFile.print(": "); myFile.print("Temp: "); myFile.print(am2320.readTemperature()); myFile.print("Humi: ");myFile.println(am2320.readHumidity()); //File Print Data
       myFile.close();
       x++;
       delay(60000);
      } else {
      Serial.print("File Error"); //Can Not Save
  }
}

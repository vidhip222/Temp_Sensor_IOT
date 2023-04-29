// we used Arduino Nano 33 BLE
// written in Arduino
// installed Arduino AVR Board and Arduino Mbed OS Nano Boards

// we imported DHT and liquid crystal library
#include "DHT.h"
// importing DHT library
#define Type DHT11
// ^ varible type DTH11 to store temperature data
#include <LiquidCrystal_I2C.h>

//size of lcd and which character on board to display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// sense pin variable 
int sensePin = 2;

//creating varible of type DHT and the parameters are  sensepin and tupe
DHT HT (sensePin, Type);
float humidity;
float tempC;
float tempF;

//units of mini seconds so 500 milisecond 
int setTime = 500;
int dt = 1000;


void setup() {
  // put your setup code here, to run once:

  // starts the output 9600 is bandwidth
  Serial.begin(9600);
  //starts up temperature sensor
  HT.begin();
  //give some delay
  delay(setTime);
  //initiialzes lcd
  lcd.init();
  // clears screen
  lcd.clear();
  lcd.backlight();

  // set the cursor in 3rd coloum 0 row
  lcd.setCursor (3,0);
  lcd.print("Temperature");

  lcd.setCursor(0,1);
  lcd.print("Sensor!");
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC=HT.readTemperature();
  tempF=HT.readTemperature(true);

  lcd.setCursor(0,0);
  lcd.print("Temp F= ");
  lcd.print(tempF);
  lcd.setCursor(0,1);
  lcd.print("Humidity= ");
  lcd.print(humidity);
  lcd.print(" %");
  delay(500);
  lcd.clear();  

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("% Temperature ");
  Serial.print(tempC);
  Serial.print(" C ");
  Serial.print(tempF);
  Serial.print(" F ");
  
  }


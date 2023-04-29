// we used Arduino Nano 33 BLE
// written in Arduino

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





int sensor = 0; // store the current sensor value
int piezoPin = 11;
int pinRed = 13;
int pinGreen = 12;
int minValue = 600;

#include <Wire.h>
#include <LiquidCrystalTr_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup() {
  Serial.begin(9600); // open serial
  pinMode(pinRed, OUTPUT); // configure digital pin pinRed as an output
  pinMode(pinGreen, OUTPUT); // configure digital pin pinGreen as an output
  pinMode(piezoPin, OUTPUT); // configure digital pin as buzzer

  // initialize the LCD
  lcd.begin(); // start serial connection

  // Turn on the blacklight and print a message.
  lcd.backlight(); // turn on lcd backlight
}

void loop() {

  // write temperatue data
  int chk = DHT.read11(DHT11_PIN); // read dht data from dht pin

  lcd.home(); // go to lcd home
  lcd.clear();
  
  lcd.print("C:");
  lcd.print(DHT.temperature);
  
  lcd.print(" %:");
  lcd.print(DHT.humidity);

  // get water level data
  sensor = analogRead(A0); // read and save value from PR

  if (sensor < minValue) { // If it is low water...
    digitalWrite(pinRed, LOW); //turn green LED off
    digitalWrite(pinGreen, HIGH); // turn red LED on
    tone(piezoPin, 1000, 500); // play buzzer
    lcd.setCursor(0, 1);
    lcd.print("Motor suyu az!!!");
  }

  else { // If it's dark...
    digitalWrite(pinRed, HIGH); // Turn red LED off
    digitalWrite(pinGreen, LOW); // Turn green LED on
  }
  
  delay(3000); // don't spam the computer!
}

int sensor = 0; // store the current sensor value
int piezoPin = 11;
int pinRed = 13;
int pinGreen = 12;
int minValue = 600;

void setup() {
  pinMode(pinRed, OUTPUT); // configure digital pin pinRed as an output
  pinMode(pinGreen, OUTPUT); // configure digital pin pinGreen as an output
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  sensor = analogRead(A0); // read and save value from PR

  if (sensor < minValue) { // If it is low water...
    digitalWrite(pinRed, LOW); //turn green LED off
    digitalWrite(pinGreen, HIGH); // turn red LED on
    tone(piezoPin, 1000, 500);
  }

  else { // If it's dark...
    digitalWrite(pinRed, HIGH); // Turn red LED off
    digitalWrite(pinGreen, LOW); // Turn green LED on
  }
  delay(1000); // don't spam the computer!
}

/*
  Created by: Michael Bruneau
  Created on: May 2025

  This Arduino Uno program a 1/2 Adder
*/

// Variables & Constants
const int PAUSE_TIME = 1000;
const int PAUSE_TIME_FOR_SETUP = 5000;
const int PIN_12 = 12;
const int PIN_10 = 10;
int voltageCounterB = -1;
int voltageCounterA = -1;
int VOLTAGE[] = {0, 5, 0};



void setup() {
  pinMode(PIN_12, OUTPUT);
  pinMode(PIN_10, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
  
  // welcome text
  Serial.println("Welcome user!! This program is a 1/2 adder.");
  
  // pauses for 5 second
  delay(PAUSE_TIME_FOR_SETUP);
}

void loop() {
  for (int voltageCounterB = -1; voltageCounterB <= 1; voltageCounterB++) {
    digitalWrite(PIN_12, voltageCounterB);

    for (int voltageCounterA = -1; voltageCounterA <= 1; voltageCounterA++) {
      digitalWrite(PIN_12, voltageCounterA);

      if (voltageCounterA < 1) {
        delay(PAUSE_TIME);
      }
    }
  }
}
  
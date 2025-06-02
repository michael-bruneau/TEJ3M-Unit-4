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
int VOLTAGE[] = {0, 5};



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
  for (int voltageCounterB = 0; voltageCounterB < 2; voltageCounterB++) {
    digitalWrite(PIN_12, VOLTAGE[voltageCounterB]);

    for (int voltageCounterA = 0; voltageCounterA < 2; voltageCounterA++) {
      digitalWrite(PIN_10, VOLTAGE[voltageCounterA]);
      
      Serial.println(voltageCounterA);
      Serial.println(" + ");
      Serial.println(voltageCounterB);

      delay(PAUSE_TIME);
      
    }
  }
}

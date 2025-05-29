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
const int ONE = 5;
const int ZERO = 0;
int pinCounter = -1;
int voltageCounter = -1;
int listIndex = 0;
int loopCounter = -1;
int PINS[] = {PIN_10, PIN_12};
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
    for (int pinCounter = -1; pinCounter < 2; pinCounter++) {
        for (int voltageCounter = -1; voltageCounter < 2; voltageCounter++) {
            // set pins
            digitalWrite(PINS[pinCounter], VOLTAGE[voltageCounter]);
            delay(PAUSE_TIME);
        }           
    }
}

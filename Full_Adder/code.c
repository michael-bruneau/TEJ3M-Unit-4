/*
  Created by: Michael Bruneau
  Created on: May 2025

  This Arduino Uno program a Full Adder
*/

// Variables & Constants
const int PAUSE_TIME = 2000;
const int PAUSE_TIME_FOR_SETUP = 5000;
const int PIN_12 = 12;
const int PIN_10 = 10;
const int PIN_9 = 9;
int voltageCounterB = -1;
int voltageCounterA = -1;
int voltageCounterCin = -1;
int VOLTAGE[] = {0, 5};

void setup() {
    pinMode(PIN_12, OUTPUT);
    pinMode(PIN_10, OUTPUT);
    pinMode(PIN_9, OUTPUT);
    Serial.begin(9600); // Starts the serial communication
  
    // welcome text
    Serial.println("Welcome user!! This program is a full adder.");
  
    // pauses for 5 second
    delay(PAUSE_TIME_FOR_SETUP);
}

void loop() {
    for (int voltageCounterCin = 0; voltageCounterCin < 2; voltageCounterCin++) {
        digitalWrite(PIN_9, VOLTAGE[voltageCounterCin]);

        for (int voltageCounterB = 0; voltageCounterB < 2; voltageCounterB++) {
            digitalWrite(PIN_12, VOLTAGE[voltageCounterB]);

            for (int voltageCounterA = 0; voltageCounterA < 2; voltageCounterA++) {
                digitalWrite(PIN_10, VOLTAGE[voltageCounterA]);

                Serial.print(voltageCounterA);
                Serial.print(" + ");
                Serial.print(voltageCounterB);
                Serial.print(" + ");
                Serial.print(voltageCounterCin);
                Serial.println("\n");
                
                delay(PAUSE_TIME);
                
            }
        }
    }   
}

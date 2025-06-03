/*
  Created by: Michael Bruneau
  Created on: May 2025

  This Arduino Uno program a 2 bit Adder/Subtractor
*/

// Variables & Constants
const int PAUSE_TIME = 1000;
const int PAUSE_TIME_FOR_SETUP = 5000;
const int PIN_13 = 13;
const int PIN_9 = 9;
const int PIN_8 = 8;
const int PIN_3 = 3;
const int PIN_2 = 2;
int voltageCounterB2 =  -1;
int voltageCounterB1 = -1;
int voltageCounterA2 = -1;
int voltageCounterA1 = -1;
int VOLTAGE[] = {0, 5};



void setup() {
  pinMode(PIN_9, OUTPUT);
  pinMode(PIN_8, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
  
  // welcome text
  Serial.println("Welcome user!! This program is a 2 bit adder/subtractor")
  
  // pauses for 5 second
  delay(PAUSE_TIME_FOR_SETUP);
}

void loop() {
    for (int voltageCounterSubtraction = 0; voltageCounterSubtraction < 2; voltageCounterSubtraction++) {
        digitalWrite(PIN_13, VOLTAGE[voltageCounterSubtraction]);

        for (int voltageCounterB2 = 0; voltageCounterB2 < 2; voltageCounterB2++) {
            digitalWrite(PIN_9, VOLTAGE[voltageCounterB2]);

            for (int voltageCounterB1 = 0; voltageCounterB1 < 2; voltageCounterB1++) {
                digitalWrite(PIN_8, VOLTAGE[voltageCounterB1]);

                for (int voltageCounterA2 = 0; voltageCounterA2 < 2; voltageCounterA2++) {
                    digitalWrite(PIN_3, VOLTAGE[voltageCounterA2]);

                    for (int voltageCounterA1 = 0; voltageCounterA1 < 2; voltageCounterA1++) {
                        digitalWrite(PIN_2, VOLTAGE[voltageCounterA1]);
                        
                        Serial.print(voltageCounterB2);
                        Serial.print(voltageCounterB1);
                        if (voltageCounterSubtraction == 1) {
                            Serial.print(" - ");
                        } else {
                            Serial.print(" + ");
                        }
                        Serial.print(voltageCounterA2);
                        Serial.print(voltageCounterA1);
                        Serial.println("\n");
                        delay(PAUSE_TIME);
                    }
                }
            }      
        }
    }
}

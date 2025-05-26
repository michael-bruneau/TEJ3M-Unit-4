/*
  Created by: Michael Bruneau
  Created on: May 2025

  This Arduino Uno program asks User for inputs for half bit adder
*/

// Variables & Constants
const int PAUSE_TIME = 1000;
const int PAUSE_TIME_FOR_SETUP = 5000;
const int PIN_12 = 12;
const int PIN_10 = 10; 
const int ONE = 5;
const int ZERO = 0;
int textDiplayCount = 0;
int userInputA = 0;
int userInputB = 0;
int decimalChecker = 0; // If decimal checker equals 4 or greater user inputed a decimal
int passChecker = -1; // Pass counter must equal one to be valid number for A and two for B
int userInputChecker = 0;
int failChecker = 0;

void setup() {
  pinMode(PIN_12, OUTPUT);
  pinMode(PIN_10, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
  
  // welcome text
  Serial.println("Welcome user!! This program is a 1/2 adder user interface.");
  
  // pauses for 5 second
  delay(PAUSE_TIME_FOR_SETUP);
}

void loop() {
    // Prompts User to select a values
    if (textDiplayCount == 0){
  	    Serial.print("\n");
  	    Serial.println("Please input the A value in the equation A + B \nnote A must integer between 1 and 0");
    
        textDiplayCount += 1;
    }
  
    decimalChecker += 1;
  
    // Read only if user has made a input
    if (Serial.available() > 0) {
  	
        //Gets user input
  	    userInputA = Serial.parseInt();
    
        decimalChecker += 1;
        userInputChecker = 1;
    
        // checks if user input was valid number
        if ((userInputA < 2) && (userInputA > -1)) {
            passChecker += 1; 
        } else {
  	        failChecker = 1;
        }
    
        // checks if number was decimal
        if (decimalChecker < 4) {
            passChecker += 1;
        } else {
            passChecker = 5;
            failChecker = 1;
        }
    }
 
    if (decimalChecker >= 3) {
  	    if ((passChecker == 1) && (failChecker == 0)) {
            // Resets loop variables 
  	        decimalChecker = -1;
            passChecker = 0;
            textDiplayCount = 0;
            userInputChecker = 0;
      
        while(passChecker >= 0) {
            if (textDiplayCount == 0) {
                Serial.print("\n");
                Serial.println("Please input the B value in the equation A ");
                Serial.print(userInputA);
                Serial.print(" + B \nnote B must integer between 1 and 0");
                textDiplayCount += 1;
            }

            decimalChecker += 1;
  
            // Read only if user has made a input
            if (Serial.available() > 0) {
  	
                //Gets user input
  	            userInputB = Serial.parseInt();
    
                decimalChecker += 1;
                userInputChecker = 1;
    
                // checks if user input was valid number
                if ((userInputA < 2) && (userInputA > -1)) {
                    passChecker += 1; 
                } else {
  	                failChecker = 1;
                }
    
                // checks if number was decimal
                if (decimalChecker < 4) {
                    passChecker += 1;
                } else {
                    passChecker = 5;
                    failChecker = 1;
                }
            }

            if (decimalChecker >= 3) {
  	            if ((passChecker == 2) && (failChecker == 0)) {
                    if (userInputA == 1) {
                        digitalWrite(PIN_10, ONE);
                        delay(PAUSE_TIME);
                    }

                    if (userInputA == 0) {
                        digitalWrite(PIN_10, ZERO);
                        delay(PAUSE_TIME);
                    }

                    if (userInputB == 1) {
                        digitalWrite(PIN_12, ONE);
                        delay(PAUSE_TIME);
                    }

                    if (userInputB == 0) {
                        digitalWrite(PIN_12, ZERO);
                        delay(PAUSE_TIME);
                    }
                    
                    while(passChecker >= 0) {
                        if (textDiplayCount == 1) {
                            Serial.print("\n");
                            Serial.println("\nthe equation you have selected is ");
                            Serial.print(userInputA);
                            Serial.print(" + ");
                            Serial.print(userInputB);
                            Serial.print(" = ");
                            Serial.print(userInputA + userInputB);
                            textDiplayCount += 1;
                            
                            Serial.print("\n");
                            Serial.print("\nWhen you are ready type any letter in the serial monitor to start a new calculation.");
                        }

                        if (Serial.available() > 0) {
                            // Resets loop 
  	                        decimalChecker = 0;
                            passChecker = -1;
                            textDiplayCount = 0;
                            userInputChecker = 0;
                            digitalWrite(PIN_10, LOW);
                            digitalWrite(PIN_12, LOW);
                            delay(PAUSE_TIME)
                        }
                    }
                } else if (failChecker == 1) {
                    Serial.print("\n");
                    Serial.println("Somthing went wrong. Your input was invalid please try again.");
                    // Resets loop variables if user input was invalid
  	                decimalChecker = 0;
                    passChecker = 0;
                    textDiplayCount = 0;
                    userInputChecker = 0;
                }
            }	
            // resets decimal checker if user ddin't make an input
            if (userInputChecker == 0) {
                decimalChecker = 0;
            }
            
        }
        } else if (failChecker == 1) {
            Serial.print("\n");
            Serial.println("Somthing went wrong. Your input was invalid please try again.");
            // Resets loop variables if user input was invalid
  	        decimalChecker = 0;
            passChecker = -1;
            textDiplayCount = 0;
            userInputChecker = 0;
        }
    }	
  
    // resets decimal checker if user ddin't make an input
    if (userInputChecker == 0) {
        decimalChecker = 0;
    }
}

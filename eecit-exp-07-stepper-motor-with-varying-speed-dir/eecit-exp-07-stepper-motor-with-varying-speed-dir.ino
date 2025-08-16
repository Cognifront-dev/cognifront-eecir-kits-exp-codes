// © 2025, Cognifront. Member of The IoT Kits Family.

//Experiment 7: Stepper Motor Control via Microcontroller

// Include the Stepper motor library
#include <Stepper.h>

// Define the number of steps per revolution for the stepper motor
// For a 28BYJ-48 stepper, it's typically 2048 steps per revolution (with gear reduction)
const int stepsPerRevolution = 2048;  

// Create a Stepper object named myStepper
// Connected to digital pins 8, 10, 9, 11 (sequence matters!)
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Start serial communication for debugging and monitoring
  Serial.begin(9600);
  Serial.println("Stepper Motor Speed Test"); // Initial message
}

void loop() {
  // Rotate clockwise (CW) at increasing speeds
  for (int spd = 5; spd <= 20; spd += 5) {
    Serial.print("Rotating CW at ");
    Serial.print(spd);
    Serial.println(" RPM");

    myStepper.setSpeed(spd);                        // Set stepper speed in RPM
    myStepper.step(stepsPerRevolution / 2);         // Rotate 1/2 revolution in CW direction
    delay(500);                                     // Short pause between speed changes
  }

  // Rotate counterclockwise (CCW) at decreasing speeds
  for (int spd = 20; spd >= 5; spd -= 5) {
    Serial.print("Rotating CCW at ");
    Serial.print(spd);
    Serial.println(" RPM");

    myStepper.setSpeed(spd);                        // Set stepper speed in RPM
    myStepper.step(-stepsPerRevolution / 2);        // Rotate 1/2 revolution in CCW direction
    delay(500);                                     // Short pause between speed changes
  }
}
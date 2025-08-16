//// © 2025, Cognifront. Member of The IoT Kits Family.

//Experiment 3: Interfacing Potentiometer for Position Control Simulation 

// Define the analog pin connected to the potentiometer
const int Pot = A0;  

// Include the Servo library to control servo motors
#include <Servo.h>     

// Create a Servo object to control a servo motor
Servo myservo;        

void setup() {
  pinMode(Pot, INPUT);       // Set potentiometer pin as input (optional, analogRead does this automatically)
  myservo.attach(8);         // Attach the servo signal wire to digital pin 8
}

void loop() {
  // Read the potentiometer value (0 to 1023 from ADC)
  int potVal = analogRead(Pot);           
  
  // Map potentiometer range (0–1023) to servo range (0–180 degrees)
  int angle = map(potVal, 0, 1023, 0, 180);  

  // Set the servo to the calculated angle
  myservo.write(angle);  
  
  // Short delay to allow the servo to move smoothly
  delay(10);          
}
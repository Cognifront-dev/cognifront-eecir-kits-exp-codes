// © 2025, Cognifront. Member of The IoT Kits Family.

// Experiment 5: Controlling DC Motor Using Transistor Driver Circuit
// with Serial Monitor output for potentiometer and motor speed

// Define analog input pin connected to the potentiometer
const int Pot = A0;

// Define motor control pins
const int motorA1 = 5;   // Motor driver input A1 (direction control)
const int motorA2 = 6;   // Motor driver input A2 (direction control)
const int enableA = 9;   // Motor driver enable pin (PWM speed control)

void setup() {
  // Start Serial communication for debugging and monitoring
  Serial.begin(9600);

  // Configure potentiometer pin as input (optional for analogRead)
  pinMode(Pot, INPUT);

  // Configure motor control pins as outputs
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(enableA, OUTPUT);
}

void loop() {
  // Read potentiometer value (range 0–1023 from ADC)
  int potVal = analogRead(Pot);           
  
  // Map potentiometer range to motor speed range (0–255 for PWM)
  int speed = map(potVal, 0, 1023, 0, 255);  

  // Set motor direction: A1 HIGH, A2 LOW → rotate in one direction
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);

  // Control motor speed using PWM signal on enable pin
  analogWrite(enableA, speed);     

  // Display potentiometer value and motor speed on Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potVal);
  Serial.print("  |  Motor Speed (PWM): ");
  Serial.println(speed);

  // Small delay for readability in Serial Monitor
  delay(200);          
}
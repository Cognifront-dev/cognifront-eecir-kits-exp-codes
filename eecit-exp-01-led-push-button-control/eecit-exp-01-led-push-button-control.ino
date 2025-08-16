// © 2025, Cognifront. Member of The IoT Kits Family.

// Experiment 1: Introduction to Arduino and Digital I/O Control

// Define push button input pins
int push1Pin = 5;
int push2Pin = 4;
int push3Pin = 2;
int push4Pin = 3;

// Variables to store button states
int push1Value;
int push2Value;
int push3Value;
int push4Value;

// Define LED output pins
int ledPin1 = 7;
int ledPin2 = 8;
int ledPin3 = 9;
int ledPin4 = 10;

void setup() {
  // Start serial communication at 9600 baud for debugging
  Serial.begin(9600);

  // Set push button pins as inputs
  pinMode(push1Pin, INPUT);
  pinMode(push2Pin, INPUT);
  pinMode(push3Pin, INPUT);
  pinMode(push4Pin, INPUT);

  // Set LED pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  // Read the state of each push button (HIGH = pressed, LOW = not pressed)
  push1Value = digitalRead(push1Pin);
  push2Value = digitalRead(push2Pin);
  push3Value = digitalRead(push3Pin);
  push4Value = digitalRead(push4Pin);

  // Check which button is pressed and turn ON the corresponding LED
  // Only one LED will turn ON at a time because of the else-if structure
  if(push1Value == HIGH) {
    digitalWrite(ledPin1, HIGH); // Turn ON LED1 if button1 is pressed
  }
  else if(push2Value == HIGH) {
    digitalWrite(ledPin2, HIGH); // Turn ON LED2 if button2 is pressed
  }
  else if(push3Value == HIGH) {
    digitalWrite(ledPin3, HIGH); // Turn ON LED3 if button3 is pressed
  }
  else if(push4Value == HIGH) {
    digitalWrite(ledPin4, HIGH); // Turn ON LED4 if button4 is pressed
  }
  else {
    // If no button is pressed, turn OFF all LEDs
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  } 
}

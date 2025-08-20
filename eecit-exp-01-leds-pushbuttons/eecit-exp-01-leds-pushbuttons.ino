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

  Serial.println("System Initialized: Monitoring Push Buttons and LEDs...");
}

void loop() {
  // Read the state of each push button (HIGH = pressed, LOW = not pressed)
  push1Value = digitalRead(push1Pin);
  push2Value = digitalRead(push2Pin);
  push3Value = digitalRead(push3Pin);
  push4Value = digitalRead(push4Pin);

  // Determine LED states and print to Serial Monitor
  if(push1Value == HIGH) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    Serial.println("Button1 PRESSED → LED1 ON");
  }
  else if(push2Value == HIGH) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    Serial.println("Button2 PRESSED → LED2 ON");
  }
  else if(push3Value == HIGH) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    Serial.println("Button3 PRESSED → LED3 ON");
  }
  else if(push4Value == HIGH) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
    Serial.println("Button4 PRESSED → LED4 ON");
  }
  else {
    // If no button is pressed, turn OFF all LEDs
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    Serial.println("No button pressed → All LEDs OFF");
  }

  // Print raw pushbutton states for debugging
  Serial.print("Buttons: ");
  Serial.print(push1Value);
  Serial.print(" ");
  Serial.print(push2Value);
  Serial.print(" ");
  Serial.print(push3Value);
  Serial.print(" ");
  Serial.println(push4Value);

  delay(500); // Small delay for better readability in Serial Monitor
}
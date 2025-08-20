// © 2025, Cognifront. Member of The IoT Kits Family.

//Experiment 4: Interfacing IR or Ultrasonic Sensor for Distance Measurement 

// Include required libraries for I2C communication and LCD display
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD at I2C address 0x27 with 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);  

// Note: Arduino UNO connections for I2C:
// SDA -> A4
// SCL -> A5

// Define pins for HC-SR04 ultrasonic sensor
const int trigPin = 4;   // Trigger pin to send ultrasonic pulses
const int echoPin = 6;   // Echo pin to receive reflected pulses

void setup() {
  // Set pin modes for ultrasonic sensor
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   

  Serial.begin(9600);        // Start serial communication for debugging (9600 baud)

  lcd.init();                // Initialize LCD
  lcd.backlight();           // Turn on LCD backlight
}

void loop() {
  // Ensure trigger pin is low for at least 2 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond HIGH pulse to trigger the ultrasonic burst
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time (in microseconds) for the echo to return
  // Timeout set to 30ms (30000 µs) to avoid hanging if no echo is received
  long duration = pulseIn(echoPin, HIGH, 30000);

  lcd.clear();  // Clear previous content on LCD before writing new data

  if (duration == 0) {
    // If no echo is detected within the timeout period
    Serial.println("No echo detected (timeout)");

    lcd.setCursor(0, 0);        // First line of LCD
    lcd.print("No echo detected");
    lcd.setCursor(0, 1);        // Second line of LCD
    lcd.print("(timeout)");
  } else {
    // Convert echo time to distance
    // Speed of sound ~343 m/s → 0.0343 cm/µs
    // Divide by 2 since the signal travels to the object and back
    float distance = duration * 0.0343 / 2.0;

    // Print distance to Serial Monitor
    Serial.print("Distance in cm: ");
    Serial.println(distance, 2); // Print with 2 decimal places

    // Display distance on LCD
    lcd.setCursor(0, 0);        
    lcd.print("Distance: ");
    lcd.print(distance, 1);     // Print with 1 decimal place
    lcd.print("CM");

    lcd.setCursor(0, 1);
    lcd.print("HC-SR04 Sensor");
  }

  delay(500);  // Wait 500ms before the next measurement
}
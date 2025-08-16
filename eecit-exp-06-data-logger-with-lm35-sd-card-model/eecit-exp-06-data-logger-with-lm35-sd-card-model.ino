// © 2025, Cognifront. Member of The IoT Kits Family.

//Experiment 6: Data Logging Using Arduino and Excel (Serial Communication)

// Include libraries to use SD card (uses SPI interface internally)
#include <SD.h>
#include <SPI.h>

// Define chip select pin for SD card module
const int chipSelect = 10;

// Define analog pin for LM35 temperature sensor
const int lm35Pin = A0;

/*
   SD Card wiring reference for Arduino UNO:
   -----------------------------------------
   | SD Card Pin  | Connect To (UNO) |
   | ------------ | ---------------- |
   | GND          | GND              |
   | VCC (5V)     | 5V               |
   | CS           | D10              |
   | MOSI         | D11              |
   | MISO         | D12              |
   | SCK          | D13              |
*/

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging

  // Initialize SD card module
  if (!SD.begin(chipSelect)) {        // Check if SD card is detected and can be initialized
    Serial.println("SD init failed!"); // If initialization fails, print error message
    while (1);                         // Stop program execution
  }
  Serial.println("SD init done.");     // Confirm SD initialization
}

void loop() {
  // Read LM35 sensor output (0–1023)
  int adcValue = analogRead(lm35Pin);
  
  // Convert ADC value to temperature in Celsius
  // LM35 gives 10 mV per °C → 5V/1024 = ~4.88 mV per ADC step
  // temperature (°C) = (ADC value * 5.0V * 100) / 1024
  float temperatureC = (adcValue * 5.0 * 100.0) / 1024.0;

  // Open (or create) "data.csv" file in write mode (append data)
  File dataFile = SD.open("data.csv", FILE_WRITE);
  
  if (dataFile) {
    // Write timestamp (in seconds since power-up)
    dataFile.print(millis() / 1000); 
    dataFile.print(",");             // Separate values with comma
    
    // Write temperature data
    dataFile.println(temperatureC);
    
    // Close file to save data properly
    dataFile.close();                

    Serial.println("Data saved.");    // Confirm data written to SD
  } else {
    Serial.println("Error opening file!"); // If file could not be opened
  }
  
  delay(1000); // Wait 1 second before next reading
}
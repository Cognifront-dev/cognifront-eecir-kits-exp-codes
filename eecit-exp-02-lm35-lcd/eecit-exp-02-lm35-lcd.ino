// © 2025, Cognifront. Member of The IoT Kits Family.

// Experiment 2: Analog Sensor Interfacing (Temperature Sensor -LM35)

// Define the analog input pin for LM35 temperature sensor
const int lm35_pin = A1;  

// Include required libraries for I2C communication and LCD
#include <Wire.h>                
#include <LiquidCrystal_I2C.h>    

// Initialize LCD at I2C address 0x27 with 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);  

// Note: Arduino UNO connections for I2C:
// SDA -> A4
// SCL -> A5

void setup() {
  Serial.begin(9600);    // Start serial communication for debugging (9600 baud rate)
  lcd.init();            // Initialize the LCD
  lcd.backlight();       // Turn on the LCD backlight
}

void loop() {
  int temp_adc_val;      // Variable to store raw ADC reading from LM35
  float temp_val;        // Variable to store calculated temperature value in °C

  // Read analog value from LM35 temperature sensor
  temp_adc_val = analogRead(lm35_pin);

  // Convert ADC value (0–1023) to millivolts:
  // Each ADC step = 5V/1024 ≈ 4.88 mV
  temp_val = (temp_adc_val * 4.88);   // Convert to mV

  // LM35 provides 10mV per °C → convert mV to °C
  temp_val = (temp_val / 10);        

  // Print temperature value to Serial Monitor
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.println(" *C");

  // Clear previous content on LCD before printing new data
  lcd.clear();

  // Display temperature on first line of LCD
  lcd.setCursor(0, 0);               // Set cursor to column 0, row 0
  lcd.print("Temp: ");               // Print label
  lcd.print(temp_val, 1);            // Print temperature with 1 decimal place
  lcd.print((char)223);              // Print degree (°) symbol
  lcd.print("C");                    // Print "C" for Celsius

  // Display sensor name on second line of LCD
  lcd.setCursor(0, 1);               
  lcd.print("LM35 Sensor");          

  // Wait 2 seconds before next reading
  delay(2000);                       
}
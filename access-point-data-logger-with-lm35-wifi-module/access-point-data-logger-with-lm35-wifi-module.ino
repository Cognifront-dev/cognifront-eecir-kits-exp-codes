// © 2025, Cognifront. Member of The IoT Kits Family.

#include <SoftwareSerial.h>

SoftwareSerial espSerial(2, 3); // RX, TX for ESP-01
#define LM35_PIN A0             // LM35 connected to A0

void sendCommand(String cmd, int delayTime) {
  espSerial.println(cmd);
  delay(delayTime);
  while (espSerial.available()) {
    Serial.write(espSerial.read());
  }
}

void setup() {
  Serial.begin(9600);
  espSerial.begin(115200);

  pinMode(LM35_PIN, INPUT);

  Serial.println("Configuring ESP-01 as Access Point...");

  sendCommand("AT", 2000);
  sendCommand("AT+CWMODE=2", 2000); // AP Mode
  sendCommand("AT+CWSAP=\"ESP01S_AP\",\"12345678\",5,3", 4000); // SSID, PASS
  sendCommand("AT+CIPMUX=1", 2000);
  sendCommand("AT+CIPSERVER=1,80", 2000);
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(LM35_PIN);	/* Read Temperature */
  temp_val = (temp_adc_val * 4.88);
  if (espSerial.available()) {
    String request = "";
    while (espSerial.available()) {
      char c = espSerial.read();
      request += c;
    }

    if (request.indexOf("GET") != -1) {
      String html = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
      html += "<!DOCTYPE html><html><head><meta http-equiv='refresh' content='5'><title>LM35 Temp</title>";
      html += "</head><body>";
      html += "<h1>LM35 Temperature Monitor</h1>";
      html += "<p>Current Temp: <b>" + String(temp_val) + " °C</b></p>";
      html += "</body></html>";

      int len = html.length();

      espSerial.println("AT+CIPSEND=0," + String(len));
      delay(100);
      espSerial.print(html);
      delay(500);
      espSerial.println("AT+CIPCLOSE=0");
    }
  }
}

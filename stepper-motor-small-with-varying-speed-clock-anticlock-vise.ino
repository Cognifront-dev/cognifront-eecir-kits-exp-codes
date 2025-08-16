#include <Stepper.h>

const int stepsPerRevolution = 2048;  
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper Motor Speed Test");
}

void loop() {
  for (int spd = 5; spd <= 20; spd += 5) {
    Serial.print("Rotating CW at ");
    Serial.print(spd);
    Serial.println(" RPM");

    myStepper.setSpeed(spd);
    myStepper.step(stepsPerRevolution / 2);
    delay(500);
  }

  for (int spd = 20; spd >= 5; spd -= 5) {
    Serial.print("Rotating CCW at ");
    Serial.print(spd);
    Serial.println(" RPM");

    myStepper.setSpeed(spd);
    myStepper.step(-stepsPerRevolution / 2);
    delay(500);
  }
}

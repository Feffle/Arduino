// Code by Isaac Stevens
// February 28th, 2022
// Contributors: None
// Intended for EGR 103

#include <Stepper.h>
const int stepsPerRevolution = 2052; // Actually 513 steps/rev
int rotate = 0;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 myStepper.setSpeed(10);
}

void loop() { 
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    rotate = Serial.parseInt();

    myStepper.step(rotate);

// Returns the value to 0 before it reloops
    rotate = 0;
  }
}

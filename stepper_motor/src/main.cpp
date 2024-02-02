#include <Arduino.h>
#include <AccelStepper.h>

#define motorPin1 8
#define motorPin2 9
#define motorPin3 10
#define motorPin4 11

#define MotorInterfaceType 8

AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);
void setup() {
  stepper.setMaxSpeed(1000);
}

void loop() {
  stepper.setCurrentPosition(0);

  while(stepper.currentPosition() != 4096) {
    stepper.setSpeed(500);
    stepper.runSpeed();
  }
  delay(1000);

  while(stepper.currentPosition() != -4096) {
    stepper.setSpeed(-200);
    stepper.runSpeed();
  }
  delay(1000);

  while(stepper.currentPosition() != -8192) {
    stepper.setSpeed(-200);
    stepper.runSpeed();
  }
  delay(1000);
}
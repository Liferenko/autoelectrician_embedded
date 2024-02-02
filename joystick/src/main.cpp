#include <Arduino.h>

int pinX = A1;
int pinY = A0;
int digitalPushButtonPin = 2;

int pinNorth = 9;
int pinSouth = 3;
int pinWest  = 6;
int pinEast  = 5;

int xVal = 0;
int yVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(digitalPushButtonPin, INPUT);

  pinMode(pinNorth, OUTPUT);
  pinMode(pinSouth, OUTPUT);
  pinMode(pinWest, OUTPUT);
  pinMode(pinEast, OUTPUT);
}

void show_coordinates() {
  xVal = analogRead(pinX);
  yVal = analogRead(pinY);

  Serial.print("{ ");
  Serial.print("X:");
  Serial.print(xVal);
  Serial.print(", ");
  Serial.print("Y:");
  Serial.print(yVal);
  Serial.println(" }");
}

void blink(int xVal, int yVal) {
  if (xVal < 100) {
    digitalWrite(pinNorth, HIGH);
  } else {
    digitalWrite(pinNorth, LOW);
  }

  if (xVal > 900) {
    digitalWrite(pinSouth, HIGH);
  } else {
    digitalWrite(pinSouth, LOW);
  }

  if (yVal > 1000) {
    digitalWrite(pinWest, HIGH);
  } else {
    digitalWrite(pinWest, LOW);
  }

  if (yVal < 100) {
    digitalWrite(pinEast, HIGH);
  } else {
    digitalWrite(pinEast, LOW);
  }
}

void loop() {
  show_coordinates();
  blink(xVal, yVal);

  delay(200);
}
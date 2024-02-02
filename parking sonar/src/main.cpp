#include <Arduino.h>

///////////////////////// VARS
int buttonPin = A2;
int photoresistorPin = A3;

int sensorRead;
int distance;
int current_pin;

//refactor - make a struct or an KV
int ledRedHigh = 11;
int ledRedLow = 10;

int ledYellowHigh = 9;
int ledYellowMid = 8;
int ledYellowLow = 7;
  
int ledGreenHigh = 6;
int ledGreenMid = 5;
int ledGreenLow = 4;

int delayTime = 200;
///////////////////////// / VARS

// put function declarations here:
int myFunction(int, int);

void setup() {
  pinMode(ledRedHigh, OUTPUT);
  pinMode(ledRedLow, OUTPUT);
  pinMode(ledYellowHigh, OUTPUT);
  pinMode(ledYellowMid, OUTPUT);
  pinMode(ledYellowLow, OUTPUT);
  pinMode(ledGreenHigh, OUTPUT);
  pinMode(ledGreenMid, OUTPUT);

  pinMode(photoresistorPin, INPUT);
  Serial.begin(9600);
}

void blink_led(int ledAddress) {
	analogWrite(ledAddress, 255);
  	delay(30);
  	analogWrite(ledAddress, 0);
    delay(10);
}

void led_meter(int sensorRead) {
    if (630 < sensorRead && sensorRead <= 700) {
      blink_led(ledRedHigh);
    }
    if (500 < sensorRead && sensorRead <= 630) {
      blink_led(ledRedLow);
    }

    else if(450 < sensorRead && sensorRead <= 500) {
      blink_led(ledYellowHigh);
    }
    else if(400 < sensorRead && sensorRead <= 450) {
      blink_led(ledYellowMid);
    }
    else if(300 < sensorRead && sensorRead <= 400) {
      blink_led(ledYellowLow);
    } 

    else if(200 < sensorRead && sensorRead <= 300) {
      blink_led(ledGreenHigh);
    }   
    else if(50 < sensorRead && sensorRead <= 200) {
      blink_led(ledGreenMid);
    } 
    else if(0 < sensorRead && sensorRead <= 50) {
      blink_led(ledGreenLow);
    } 
    else {
      blink_led(ledGreenLow);
    }
}

void loop() {
  current_pin = photoresistorPin;

  sensorRead = analogRead(current_pin); // to store sensor's value
  // PWM - pause with modulation

  distance = sensorRead;
  Serial.print("Parking distance = ");
  Serial.println(distance);

  led_meter(distance);
 }
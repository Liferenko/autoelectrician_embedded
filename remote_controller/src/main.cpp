#include <Arduino.h>
#include <IRremote.h>

#define DELAY_AFTER_SEND 2000
#define DELAY_AFTER_LOOP 5000
#define IR_RECEIVE_PIN 7

int button = 0;

int mapCodeToButton(unsigned long code) {
  if ((code & 0x0000FFFF) == 0x0000BF00) {
    code >>= 16;
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF;
    }
  }
  return -1;
}

int readInfrared() {
  int result = -1;

  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    result = mapCodeToButton(code);

    Serial.print("----------- ");
    Serial.print("Received code: ");
    Serial.print(code);
    Serial.println(" ============");
    Serial.println(result, HEX);
    Serial.println(" ============");

    IrReceiver.resume();
  }

  return result;
}

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  printActiveIRProtocols(&Serial);
}

void loop() {
  button = readInfrared();
  if (button >= 0) {
    Serial.print("Button ");
    Serial.print(button);
    Serial.print(" pressed.");
    delay(DELAY_AFTER_SEND);
  }
}
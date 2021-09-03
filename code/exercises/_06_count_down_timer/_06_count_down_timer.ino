#include<SevenSegment.h>

SevenSegment sevenSegment = SevenSegment();

volatile uint8_t count;
volatile uint16_t prevMillis = 0;
volatile uint16_t resultMillis = 0;

const uint8_t interruptPin0 = 0;
const uint8_t interruptPin1 = 1;

volatile uint8_t startStatus = false;


void interrupt0StatusChange() {
  count++;
}

void interrupt1StatusChange() {
  startStatus = true;
}

void setup() {
  sevenSegment.setSegmentPin(11, 12, 13, 14, 15, 16, 17, 18);
  sevenSegment.setDigitPin(7, 8, 10);

  attachInterrupt(interruptPin0, interrupt0StatusChange, HIGH);
  attachInterrupt(interruptPin1, interrupt1StatusChange, HIGH);
}


void loop() {
  sevenSegment.show(count);

  if (startStatus == true) {
    resultMillis = millis() - prevMillis;
    if ( resultMillis >= 1000) {
      prevMillis = millis();
      count--;
    }

    if (count <= 0) {
      startStatus = false;
    }
  }
}



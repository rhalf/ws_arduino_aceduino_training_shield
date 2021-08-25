uint8_t LEDS[] = {11, 12, 13, 14, 15, 16, 17, 18};

void setup() {
  // put your setup code here, to run once:                      
  for (uint8_t value = 0; value < 8; value++) {
    pinMode(LEDS[value], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:                            
  for (uint8_t count = 0; count < 7; count++) {
    uint8_t value = 1 << count;
    show(value);
    delay(20);
  }
  for (uint8_t count = 0; count < 7; count++) {
    uint8_t value = 1 << (7 - count);
    show(value);
    delay(50);
  }
}

void show(uint8_t value) {
  for (uint8_t index = 0; index < 8; index++)
    digitalWrite(LEDS[index], bitRead(value, index));
}


const uint8_t LEDS[] = {11, 12, 13, 14, 15, 16, 17, 18};
uint8_t count = 0;

void setup() {
  // put your setup code here, to run once:                    
  for (uint8_t i = 0; i < sizeof(LEDS); i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:                            
  show(count);
  count++;
  delay(100);
}

void show(uint8_t v) {
  for (uint8_t i = 0; i < 8; i++)
    digitalWrite(LEDS[i], bitRead(v, i));
}


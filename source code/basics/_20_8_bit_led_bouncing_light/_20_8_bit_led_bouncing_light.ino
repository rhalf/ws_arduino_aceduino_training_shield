uint8_t LEDS[] = {11, 12, 13, 14, 15, 16, 17, 18};
void setup() {
  // put your setup code here, to run once:                      
  for (uint8_t v = 0; v < 8; v++) 
    pinMode(LEDS[v], OUTPUT);
}
void loop() {
  for (uint8_t c = 0; c < 7; c++) {
    uint8_t v = 1 << c;
    show(v);
  }
  for (uint8_t c = 0; c < 7; c++) {
    uint8_t v = 1 << (7 - c);
    show(v);
  }
}
void show(uint8_t v) {
  for (uint8_t i = 0; i < 8; i++) {
    digitalWrite(LEDS[i], bitRead(v, i));
    delay(2);
  }
}


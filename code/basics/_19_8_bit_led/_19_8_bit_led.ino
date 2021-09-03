const uint8_t LEDS[] = {11, 12, 13, 14, 15, 16, 17, 18};
void setup() {
  // put your setup code here, to run once:                  
  for (uint8_t v = 0; v < 8; v++) {
    pinMode(LEDS[v], OUTPUT);
    digitalWrite(LEDS[v], HIGH);
  }
}
void loop() {
  // put your main code here, to run repeatedly:                          
}


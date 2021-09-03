const uint8_t LEDS[8] = { 11, 12, 13, 14, 15, 16, 17, 18 };
const uint8_t NUMBERS[10] = 
  { 0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
const uint8_t DIGIT1 = 7, DIGIT2 = 8, DIGIT3 = 10;
uint16_t count = 0, dDelay = 5;
uint64_t pMillis = 0;

void setup() {
  // put your setup code here, to run once:                          
  for (uint8_t count = 0; count < sizeof(LEDS); count++) {
    pinMode(LEDS[count], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:                                
  setDigits(count);

  if (millis() - pMillis >= 100) {
    pMillis = millis();
    count++;
  }

  if (count > 999) {
    count = 0;
  }
}

void setDigits(uint16_t value) {
  uint8_t s1 = value % 10;
  value = value / 10;
  uint8_t s2 = value % 10;
  value = value / 10;
  uint8_t s3 = value % 10;
  digitalWrite(DIGIT3, LOW);
  digitalWrite(DIGIT2, LOW);
  digitalWrite(DIGIT1, HIGH);
  show(s1);
  delay(dDelay);
  digitalWrite(DIGIT3, LOW);
  digitalWrite(DIGIT2, HIGH);
  digitalWrite(DIGIT1, LOW);
  show(s2);
  delay(dDelay);
  digitalWrite(DIGIT3, HIGH);
  digitalWrite(DIGIT2, LOW);
  digitalWrite(DIGIT1, LOW);
  show(s3);
  delay(dDelay);
}

void show(uint8_t value) {
  for (uint8_t index = 0; index < 8; index++)
    if (bitRead(NUMBERS[value], index)) 
      digitalWrite(LEDS[index], HIGH);
    else
      digitalWrite(LEDS[index], LOW);
}

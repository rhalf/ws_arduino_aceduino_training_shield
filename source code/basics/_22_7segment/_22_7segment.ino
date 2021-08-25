const uint8_t LEDS[8] = { 11, 12, 13, 14, 15, 16, 17, 18 };
const uint8_t NUMBERS[10] = { 0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
const uint8_t DIGIT1 = 7, DIGIT2 = 8, DIGIT3 = 10;
uint8_t count;

void setup() {
  // put your setup code here, to run once:                        
  for (uint8_t count = 0; count < 8; count++) {
    pinMode(LEDS[count], OUTPUT);
  }
  digitalWrite(DIGIT1, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:                              
  show(count);
  delay(500);
  count++;
  if (count > 9) {
    count = 0;
  }
}

void show(uint8_t value) {
  for (uint8_t index = 0; index < 8; index++)
    if (bitRead(NUMBERS[value], index)) 
      digitalWrite(LEDS[index], HIGH);
    else
      digitalWrite(LEDS[index], LOW);
}

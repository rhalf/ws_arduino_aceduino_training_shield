const uint8_t LEDS[8] = { 11, 12, 13, 14, 15, 16, 17, 18 };
const uint8_t NUMBERS[10] = 
  { 0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
const uint8_t D1 = 7, D2 = 8, D3 = 10;
uint16_t c = 0, dDelay = 5, cDelay = 10;
uint32_t pMillis = 0;

void setup() {
  // put your setup code here, to run once:                          
  for (uint8_t i = 0; i < sizeof(LEDS); i++)
    pinMode(LEDS[i], OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:                                
  setDigits(c);
  if (millis() - pMillis >= cDelay) {
    pMillis = millis();
    c++;
  }
  if (c > 999) c = 0;
}
void setDigits(uint16_t v) {
  uint8_t s1 = v % 10;
  v = v / 10;
  uint8_t s2 = v % 10;
  v = v / 10;
  uint8_t s3 = v % 10;
  digitalWrite(D3, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, HIGH);
  show(s1);
  delay(dDelay);
  digitalWrite(D3, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D1, LOW);
  show(s2);
  delay(dDelay);
  digitalWrite(D3, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW);
  show(s3);
  delay(dDelay);
}
void show(uint8_t v) {
  for (uint8_t i = 0; i < 8; i++)
    if (bitRead(NUMBERS[v], i)) 
      digitalWrite(LEDS[i], HIGH);
    else
      digitalWrite(LEDS[i], LOW);
}
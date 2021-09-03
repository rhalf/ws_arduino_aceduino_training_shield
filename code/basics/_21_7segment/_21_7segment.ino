const uint8_t LEDS[8] = {11, 12, 13, 14, 15, 16, 17, 18};
const uint8_t NUMBERS[10] = 
  {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
const uint8_t D1 = 7, D2 = 8, D3 = 10;
uint16_t c = 0, cDelay = 500;

void setup() {
  // put your setup code here, to run once:                        
  for (uint8_t i = 0; i < 8; i++)
    pinMode(LEDS[i], OUTPUT);

  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:                              
  show(c);
  delay(cDelay);
  c++;
}
void show(uint8_t v) {
  for (uint8_t i = 0; i < 8; i++)
    if (bitRead(NUMBERS[v], i)) 
      digitalWrite(LEDS[i], HIGH);
    else
      digitalWrite(LEDS[i], LOW);
}
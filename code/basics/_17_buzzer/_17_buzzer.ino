//pin on which to generate the tone
const uint8_t PIN = 4;
//frequency in hertz, duration in milliseconds
uint16_t freq = 440, dura = 1000;
void setup() {
  // put your setup code here, to run once:                              
  pinMode(PIN, OUTPUT);
  tone(PIN, freq, dura);
  delay(dura);
  noTone(PIN);
}
void loop() {
  // put your main code here, to run repeatedly:                      
}




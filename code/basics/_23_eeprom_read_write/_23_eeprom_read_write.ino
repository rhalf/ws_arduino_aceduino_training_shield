#include <EEPROM.h>
const uint8_t NUMBERS[5] = { 1, 2, 3, 4, 5};
void setup() {
  // put your setup code here, to run once:                            
  Serial.begin(9600);
  for (uint8_t i = 0; i < sizeof(NUMBERS); i++)
    EEPROM.write(i, NUMBERS[i]);
  for (uint8_t i = 0; i < sizeof(NUMBERS); i++)
    Serial.print(EEPROM.read(i));
}
void loop() {
  // put your main code here, to run repeatedly: 
}

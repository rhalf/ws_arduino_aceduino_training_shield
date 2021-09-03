#include <EEPROM.h>
const char NAME[20] = "rhalf wendel caacbay";
void setup() {
  // put your setup code here, to run once:                            
  Serial.begin(9600);
  for (uint8_t i = 0; i < sizeof(NAME); i++)
    EEPROM.write(i, (uint8_t) NAME[i]);
  for (uint8_t i = 0; i < sizeof(NAME); i++)
    Serial.print((char)EEPROM.read(i));
}
void loop() {
  // put your main code here, to run repeatedly: 
}

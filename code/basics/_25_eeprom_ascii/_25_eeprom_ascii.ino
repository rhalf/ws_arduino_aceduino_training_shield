#include <EEPROM.h>

const char NAME[20] = "rhalf wendel caacbay";

void setup() {
  // put your setup code here, to run once:                            
  Serial.begin(9600);

  for (uint8_t index = 0; index < 20; index++)
    EEPROM.write(index, (uint8_t) NAME[index]);
  
  for (uint8_t index = 0; index < 20; index++)
    Serial.print((char)EEPROM.read(index));
}

void loop() {
  // put your main code here, to run repeatedly: 
}

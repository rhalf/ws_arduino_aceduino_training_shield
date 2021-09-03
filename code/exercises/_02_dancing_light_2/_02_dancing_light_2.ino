uint8_t ledArray[8] = {
  11,12,13,14,15,16,17,18};
uint16_t delay_master = 100;

void setup()
{
  for (int i=0; i<8; i++)
  {
    pinMode(ledArray[i], OUTPUT);
  }
}

void ledArray_blink()
{
  for (int j = 8; j>=0;j--){
    for (int i=0; i<j; i++)
    {
      digitalWrite(ledArray[i], HIGH);
      delay(delay_master);
      digitalWrite(ledArray[i], LOW);
    } 
    digitalWrite(ledArray[j],HIGH);
  }
}

void loop()
{
  ledArray_blink();
}






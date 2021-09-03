int led[] = {11,12,13,14,15,16,17,18};
int count=0;
int button1 = 2;
int button2 = 3;
int digit1 = 10;
int digit2 = 8;
int digit3 = 7;
int buzzer = 4;
int red = 5;
int green = 6;
long prevCount=0;
boolean isBuzzerActive = false;


void setup() {
  for (int count=0;count<=10; count++) {
    pinMode(led[count],OUTPUT);
  }
  pinMode(button1,OUTPUT);
  pinMode(button2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  digitalWrite(digit3,HIGH);
  showSeg(count);
}

void loop() {
  if(digitalRead(button1)==HIGH && count<9) {
    count++;
    showSeg(count);
    while(digitalRead(button1)==HIGH) {
      delay(50);
    }
  }
  if(digitalRead(button2)==HIGH && count>0) {
    count--;
    showSeg(count);
    isBuzzerActive = false;
    while(digitalRead(button2)==HIGH) {
      delay(50);
    }
  }
  if(count>=9) {
    if (millis()-prevCount>=1000) {
      prevCount = millis();
      isBuzzerActive = !isBuzzerActive;
    }
  } 
  if(count< 9) {
    digitalWrite(green,HIGH);
  }
  else {
    digitalWrite(green,LOW);
  }

  if(isBuzzerActive){
    tone(buzzer,440);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  } 
  else {
    noTone(buzzer);
    digitalWrite(red,LOW);
  }



}

void showSeg(int val)
{
  switch (val)
  {
  case 0:
    digitalWrite(led[0],HIGH); //a
    digitalWrite(led[1],HIGH); //b
    digitalWrite(led[2],HIGH); //c
    digitalWrite(led[3],HIGH); //d
    digitalWrite(led[4],HIGH); //e
    digitalWrite(led[5],HIGH); //f
    digitalWrite(led[6],LOW);  //g
    digitalWrite(led[7],LOW);  //h
    break;
  case 1:
    digitalWrite(led[0],LOW);  //a
    digitalWrite(led[1],HIGH); //b
    digitalWrite(led[2],HIGH); //c
    digitalWrite(led[3],LOW);  //d
    digitalWrite(led[4],LOW);  //e
    digitalWrite(led[5],LOW);  //f
    digitalWrite(led[6],LOW);  //g
    digitalWrite(led[7],LOW);  //h
    break;
  case 2:
    digitalWrite(led[0],HIGH); //a
    digitalWrite(led[1],HIGH); //b
    digitalWrite(led[2],LOW);  //c
    digitalWrite(led[3],HIGH); //d
    digitalWrite(led[4],HIGH); //e
    digitalWrite(led[5],LOW);  //f
    digitalWrite(led[6],HIGH); //g
    digitalWrite(led[7],LOW);  //h
    break;
  case 3:
    digitalWrite(led[0],HIGH); //a
    digitalWrite(led[1],HIGH); //b
    digitalWrite(led[2],HIGH);  //c
    digitalWrite(led[3],HIGH); //d
    digitalWrite(led[4],LOW); //e
    digitalWrite(led[5],LOW);  //f
    digitalWrite(led[6],HIGH); //g
    digitalWrite(led[7],LOW);  //h
    break;
  case 4:
    digitalWrite(led[0],LOW); //a
    digitalWrite(led[1],HIGH); //b
    digitalWrite(led[2],HIGH);  //c
    digitalWrite(led[3],LOW); //d
    digitalWrite(led[4],LOW); //e
    digitalWrite(led[5],HIGH);  //f
    digitalWrite(led[6],HIGH); //g
    digitalWrite(led[7],LOW);  //h
    break;
  case 5:
    digitalWrite(led[0],HIGH); //a
    digitalWrite(led[1],LOW); //b
    digitalWrite(led[2],HIGH);  //c
    digitalWrite(led[3],HIGH); //d
    digitalWrite(led[4],LOW); //e
    digitalWrite(led[5],HIGH);  //f
    digitalWrite(led[6],HIGH); //g
    digitalWrite(led[7],LOW);  //h
    break;
  case 6:
    digitalWrite(led[0],HIGH); //a
    digitalWrite(led[1],LOW); //b
    digitalWrite(led[2],HIGH);  //c
    digitalWrite(led[3],HIGH); //d
    digitalWrite(led[4],HIGH); //e
    digitalWrite(led[5],HIGH);  //f
    digitalWrite(led[6],HIGH); //g
    digitalWrite(led[7],LOW);  //h
    break;
  case 7:
    digitalWrite(led[0],HIGH); //a
    digitalWrite(led[1],HIGH); //b
    digitalWrite(led[2],HIGH);  //c
    digitalWrite(led[3],LOW); //d
    digitalWrite(led[4],LOW); //e
    digitalWrite(led[5],LOW);  //f
    digitalWrite(led[6],LOW); //g
    digitalWrite(led[7],LOW);  //h
    break;
  case 8:
    digitalWrite(led[0],HIGH); //a
    digitalWrite(led[1],HIGH); //b
    digitalWrite(led[2],HIGH);  //c
    digitalWrite(led[3],HIGH); //d
    digitalWrite(led[4],HIGH); //e
    digitalWrite(led[5],HIGH);  //f
    digitalWrite(led[6],HIGH); //g
    digitalWrite(led[7],LOW);  //h
    break;
  case 9:
    digitalWrite(led[0],HIGH); //a
    digitalWrite(led[1],HIGH); //b
    digitalWrite(led[2],HIGH);  //c
    digitalWrite(led[3],HIGH); //d
    digitalWrite(led[4],LOW); //e
    digitalWrite(led[5],HIGH);  //f
    digitalWrite(led[6],HIGH); //g
    digitalWrite(led[7],LOW);  //h
    break;
  }	
}







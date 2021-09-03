int led[11] = {11,12,13,14,15,16,17,18};

int red = 5;
int green = 6;

int button1 = 2;

boolean isActivated = false; 
int digit3 = 7;

void setup() {
  for (int count=0;count<=10; count++) {
    pinMode(led[count],OUTPUT);
  }
  digitalWrite(digit3,HIGH);
  
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(button1,INPUT);
}

void loop() {
  if (digitalRead(button1)==HIGH) {
    isActivated = true;
  }
  if (isActivated) {
    analogWrite(red,255);
    analogWrite(green,0);
    for(int i =9; i>=0; i--) {
      showSeg(i);
      delay(1000);
    }
    
    analogWrite(red,0);
    analogWrite(green,255);
    for(int i =9; i>=0; i--) {
      showSeg(i);
      delay(1000);
    }
    
    analogWrite(red,255);
    analogWrite(green,100);
      for(int i=3; i>=0; i--) {
      showSeg(i);
      delay(1000);
    }
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


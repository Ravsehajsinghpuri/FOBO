#define LS 0      // left sensor
#define RS 1      // right sensor
#define LM1 2       // left motor
#define LM2 3       // left motor
#define RM1 4       // right motor
#define RM2 5       // right motor
int Rpienable = 7;
int personpin = 6;

int programstate = 0;
int personstate =0 ;
int sensL=0;
int sensR=0;
//Sensor Connection
void setup() {
 pinMode(LS, INPUT);
 pinMode(RS, INPUT);
 pinMode(LM1, OUTPUT);
 pinMode(LM2, OUTPUT); 
 pinMode(RM1, OUTPUT);
 pinMode(RM2, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(Rpienable, INPUT);
 pinMode(personpin, INPUT);
 delay(2000);
analogWrite (10,5);  
analogWrite (9,5); 
delay(2000);
}

void loop() {
  delay(20);
programstate = digitalRead(Rpienable);
personstate = digitalRead(personpin);
sensL=digitalRead(LS) ;
sensR=digitalRead(RS);
if(sensL==0 && sensR==0 && programstate==1 && personstate==0 )     // Move Forward
  {
    analogWrite (10,150);  
    analogWrite (9,150); 
    digitalWrite(LM1,1); digitalWrite(LM2,0); digitalWrite(RM1, 1); digitalWrite(RM2, 0); delay(20);
    digitalWrite(LM1,0); digitalWrite(LM2,0); digitalWrite(RM1, 0); digitalWrite(RM2, 0); delay(6);
  }
  
  if(sensL==1 && sensR==0 && programstate==1 && personstate==0)     // Turn right
  {
    analogWrite (10,230);  
    analogWrite (9,230);
    digitalWrite(LM1, 0);digitalWrite(LM2, 1);digitalWrite(RM1, 1); digitalWrite(RM2, 0);    delay(30);
  }
  if(sensL==0 && sensR==1 && programstate==1 && personstate==0)     // turn left
  {
    analogWrite (10,230);  
    analogWrite (9,230);
    digitalWrite(LM1,1); digitalWrite(LM2,0); digitalWrite(RM1, 0); digitalWrite(RM2, 1); delay(30);
  }
  if(sensL==1 && sensR==1 && programstate==1 && personstate==0)     // stop
  {
    analogWrite (10,10);  
    analogWrite (9,10);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    delay(10);
  }

    if(programstate==0 || personstate==1)     // stop
  {
    analogWrite (10,20);  
    analogWrite (9,20);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  
  }
}/////////////




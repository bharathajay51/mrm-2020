int trigleft = 4;
int echoleft = 5;
int trigright = 2;
int echoright = 3;
int leftfwd=10;
int rightfwd=8;
int leftbkw=11;
int rightbkw=9;
float ultrasonic(int,int);
volatile float distleft;
volatile float distright;
void setup() 
{
  pinMode(trigleft, OUTPUT);
  
  pinMode(trigright, OUTPUT);
  pinMode(leftfwd, OUTPUT);
   pinMode(leftbkw, OUTPUT);
  pinMode(rightfwd, OUTPUT);
   pinMode(rightbkw, OUTPUT);
  pinMode(echoleft, INPUT);
  pinMode(echoright,INPUT);
  Serial.begin(9600);
}
void loop()
{
  distleft=ultrasonic(trigleft,echoleft);
  
  distright=ultrasonic(trigright, echoright);
  
  
  if(distleft>20 && distright>20)
  {
    digitalWrite(leftfwd,HIGH);
    digitalWrite(rightfwd,HIGH); 
    digitalWrite(leftbkw,LOW);
    digitalWrite(rightbkw,LOW); 
    Serial.print("going foward");
  }
  if(distleft<20 && distright<20)
  {
    if(distleft>distright)
    {
     digitalWrite(leftfwd,LOW);
    digitalWrite(rightfwd,HIGH); 
    digitalWrite(leftbkw,HIGH);
    digitalWrite(rightbkw,LOW); 
    Serial.print("going left");
    }
    if(distright>distleft)
    { digitalWrite(leftfwd,HIGH);
    digitalWrite(rightfwd,LOW); 
    digitalWrite(leftbkw,LOW);
    digitalWrite(rightbkw,HIGH); 
     Serial.print("going right");
   }
  if(distright==distleft)
  {
    digitalWrite(leftfwd,LOW);
    digitalWrite(rightfwd,LOW); 
    digitalWrite(leftbkw,HIGH);
    digitalWrite(rightbkw,HIGH);
    Serial.print("going back");
   }
  }
  
   if(distleft<20 && distright>20) 
     { digitalWrite(leftfwd,HIGH);
    digitalWrite(rightfwd,LOW); 
    digitalWrite(leftbkw,LOW);
    digitalWrite(rightbkw,HIGH); 
    Serial.print("going right"); 
    }
    if(distleft>20 && distright<20)
    {
      digitalWrite(leftfwd,LOW);
    digitalWrite(rightfwd,HIGH); 
    digitalWrite(leftbkw,HIGH);
    digitalWrite(rightbkw,LOW);
   Serial.print("going left");
    }
}




}

float ultrasonic(int trig, int echo)
{ float dist;
  unsigned long t2=0,t1=0,t=0;
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  while(digitalRead(echo)==LOW)
  {}
  t1=micros();
  
  while(digitalRead(echo)==HIGH)
  {}
    t2= micros();
    t=t2-t1;
    dist=t*0.0343/2;
    return dist;
    Serial.println(dist);
}
    
  

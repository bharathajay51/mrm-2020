
int trig=3;
int echo =2;
void setup()
{ pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}



void loop() 
{
 float dist;
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
    Serial.println(dist);
}

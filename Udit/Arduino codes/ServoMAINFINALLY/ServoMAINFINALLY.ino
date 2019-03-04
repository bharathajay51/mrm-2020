boolean condition = true;
int Ser = 12;
int angle;
boolean flag=1;
void ServoRun(int)
{ int t, c;
  t = map(angle, 0, 180, 650, 2500);
  c = 2500 - t;
  digitalWrite(Ser, HIGH);
  delayMicroseconds(t);
  digitalWrite(Ser, LOW);
  delayMicroseconds(c);
}
void setup()
{
  pinMode(Ser, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop()
{
  while(flag==1)
  {
    for (angle =93; angle <= 153; angle++)
    {
      ServoRun(angle);
      Serial.println(angle);
      if(angle==153)
      {flag=0;}
      delay(15);
    }
  }
}
   
  
  
  /*for(angle=160; angle>95;angle--)
    {
    ServoRun(angle);
    Serial.println(angle);
    delay(15);*/
    

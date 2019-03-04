int n,first,second,sum;
void setup()
{
  pinMode(9,OUTPUT);
}

void loop() 
{
  first=0;
  second=1;
  while( first<250)
  {
    analogWrite(9,first);
    delay(100);
    sum=first+second;
    first=second;
  }

}

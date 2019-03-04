 int LEDar[]={4,3};
 int i;
 int counter=0;
 
 void setup() 
 
{
  for(i=0;i<8;i++)
     pinMode(LEDar[i], OUTPUT);
}

void loop() 
{ for(counter=0; counter<=7; counter++)
    {for( i=0; i<2; i++)
    
  {  if (bitRead(counter, i)==1)
    digitalWrite(LEDar[i],HIGH);
 if (bitRead(counter, i)==0)
  digitalWrite(LEDar[i],LOW);
 }
  delay(1000);
}
}

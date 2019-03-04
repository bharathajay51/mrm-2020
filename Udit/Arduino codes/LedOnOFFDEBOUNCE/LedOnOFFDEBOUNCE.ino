int Led=3;
int Button=2;
boolean LastButton=LOW;
boolean currentButton=LOW;
boolean LedState=0;
void setup()
{
  pinMode(Button, INPUT);
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
  
 // put your setup code here, to run once:

}

boolean debounce(boolean Last)
{ boolean current=digitalRead(Button);
  if ( Last!=current)
   { 
    delay(5);
    current=digitalRead(Button);
   }
   return current;
}

void loop() 
{  currentButton= debounce(LastButton);
  if(LastButton==LOW && currentButton==HIGH)
     {
      LedState=!LedState;
       }

    LastButton=currentButton;

   digitalWrite(Led,LedState);
  Serial.println(currentButton);
}
   
  // put your main code here, to run repeatedly:

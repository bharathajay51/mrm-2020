int trig = 9;
int echo = 10;
int EchoState = 0;
float dist;
float t;
int LEDar[] = {3, 4, 5};
int condition = 1;
int i;
int ButtonLevel(int, int);
int but1 = 7;
int but2 = 8;
boolean but1S = LOW;
boolean but2S = LOW;
int counter = 0;
int l;
boolean LastButton = LOW;


int ButtonLevel(int ButtonState , int Button)
{ int counter;

  ButtonState = digitalRead(Button);
  if (ButtonState == HIGH && LastButton == LOW)
  { counter++;
    LastButton == HIGH;
    return counter;
  }
}

void setup()

{
  for (i = 0; i < 3; i++)
    pinMode(LEDar[i], OUTPUT);
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  but1S = digitalRead(but1);
  but2S = digitalRead(but2);
  while ( condition = 1 && but2S == LOW)
  {
    int ButtonLevel(int but1S, int but1);
    switch (counter)
    {
      case 1: {
          digitalWrite(LEDar[0], LOW);
          digitalWrite(LEDar[1], LOW);
          digitalWrite(LEDar[2], HIGH);
          break;
        }
      case 2:
        digitalWrite(LEDar[0], LOW);
        digitalWrite(LEDar[1], HIGH);
        digitalWrite(LEDar[2], LOW);
        break;

      case 3: {
          digitalWrite(LEDar[0], LOW);
          digitalWrite(LEDar[1], HIGH);
          digitalWrite(LEDar[2], HIGH);
          break;
        }
      case 4: {
          digitalWrite(LEDar[0], HIGH);
          digitalWrite(LEDar[1], LOW);
          digitalWrite(LEDar[2], HIGH);
          break;
        }
      case 5: {
          digitalWrite(LEDar[0], HIGH);
          digitalWrite(LEDar[1], LOW);
          digitalWrite(LEDar[2], HIGH);
          break;
        }
      case 6: {
          digitalWrite(LEDar[0], HIGH);
          digitalWrite(LEDar[1], HIGH);
          digitalWrite(LEDar[2], LOW);
          break;
        }
      case 7: {
          digitalWrite(LEDar[0], HIGH);
          digitalWrite(LEDar[1], HIGH);
          digitalWrite(LEDar[2], HIGH);
          break;
        }

    }
  }
  condition = 0;
  if (condition = 0)
  {

    digitalWrite(trig, LOW);

    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    t = pulseIn(echo, HIGH);
    dist = t * 343 * 0.0001 / 2;
    Serial.println(dist);
    delay(500);
    l =  map(dist, 3, 120, 0, 7);
    switch (l)
    {
      case 1: {
          digitalWrite(LEDar[0], LOW);
          digitalWrite(LEDar[1], LOW);
          digitalWrite(LEDar[2], HIGH);
          break;
        }
      case 2: {
          digitalWrite(LEDar[0], LOW);
          digitalWrite(LEDar[1], HIGH);
          digitalWrite(LEDar[2], LOW);
          break;
        }
      case 3: {
          digitalWrite(LEDar[0], LOW);
          digitalWrite(LEDar[1], HIGH);
          digitalWrite(LEDar[2], HIGH);
          break;
        }
      case 4: {
          digitalWrite(LEDar[0], HIGH);
          digitalWrite(LEDar[1], LOW);
          digitalWrite(LEDar[2], HIGH);
          break;
        }
      case 5: {
          digitalWrite(LEDar[0], HIGH);
          digitalWrite(LEDar[1], LOW);
          digitalWrite(LEDar[2], HIGH);
          break;
        }
      case 6: {
          digitalWrite(LEDar[0], HIGH);
          digitalWrite(LEDar[1], HIGH);
          digitalWrite(LEDar[2], LOW);
          break;
        }
      case 7: {
          digitalWrite(LEDar[0], HIGH);
          digitalWrite(LEDar[1], HIGH);
          digitalWrite(LEDar[2], HIGH);
          break;
          if (but2S == HIGH)
            condition = 1;
        }

    }
  }


}

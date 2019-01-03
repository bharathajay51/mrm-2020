int LedL = 5;
int LedR = 6;
int LedRevL = 4;
int LedRevR = 7;
int joy1 = A1;
int joy2 = A0;
int joylevel1;
int joylevel2;
int joylevelFirst;
int joylevelSecond;
int k1;
int k2;
int X;
int Y;
int g=0;


boolean flag = 1;
void setup()
{ Serial.begin(9600);
  pinMode(LedL, OUTPUT);
  pinMode(LedR, OUTPUT);
  pinMode(LedRevL, OUTPUT);
  pinMode(LedRevR, OUTPUT);
  pinMode(joy1, INPUT);
  pinMode(joy2, INPUT);
  //pinMode(joy1,INPUT_PULLUP);
  //pinMode(joy2, INPUT_PULLUP);
}

void loop()

{
  while (flag == 1)
  { 
    
      joylevelFirst = analogRead(joy1) - 512;
      joylevelSecond = analogRead(joy2) - 512;
      flag = 0;
    
  }
  joylevel1 = analogRead(joy1);
  joylevel2 = analogRead(joy2);
  //Serial.println(joylevel1);
  k1 = joylevel1 - 512 - joylevelFirst;
  k2 = joylevel2 - 512 - joylevelSecond;
  X = -(k1 / 2);
  if (X > 255)
  {
    X = 255;
  }
  Serial.print("X val: "); Serial.println(X);
  Y = k2 / 2;
  if (Y > 255)
  {
    Y = 255;
  }
  Serial.print("Y val: "); Serial.println(Y);
  if (X >= 0 && Y >= 0)
  {
    int level = X - Y;
    if (level == 0)
    { analogWrite(LedL, abs(X));
      analogWrite(LedR, g);
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, LOW);
      Serial.println(X);
      Serial.println(g);
    }
    if (level > 0)
    {
      analogWrite(LedL, abs(X));
      analogWrite(LedR, abs(X-Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, HIGH);
      Serial.println(X);
      Serial.println(X-Y);
    }
    if (level < 0)
    {
      analogWrite(LedL, abs(X));
      analogWrite(LedR, abs(X-Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, LOW);
      Serial.println(X);
      Serial.println(X-Y);
    }
  }
  if (X <= 0 && Y >= 0)
  {
    int level = X + Y;
    if (level == 0)
    { analogWrite(LedL, 0);
      analogWrite(LedR, abs(Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, LOW);
      Serial.println(g);
      Serial.println(Y);
    }
    if (level > 0)
    {
      analogWrite(LedL, abs(Y+X));
      analogWrite(LedR, abs(Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, LOW);
      Serial.println(Y+X);
      Serial.println(Y);
    }
    if (level < 0)
    {
      analogWrite(LedL, abs(X+Y));
      analogWrite(LedR, abs(X));
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, LOW);
      Serial.println(X+Y);
      Serial.println(X);
    }
  }
  if (X < 0 && Y < 0)
  {
    int level = X - Y;
    if (level == 0)
    { analogWrite(LedL, abs(X));
      analogWrite(LedR, 0);
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, LOW);
      Serial.println(X);
      Serial.println(g);
    }
    if (level > 0)
    {
      analogWrite(LedL, abs(X-Y));
      analogWrite(LedR, abs(Y));
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, HIGH);
      Serial.println(X-Y);
      Serial.println(Y);
    }
    if (level < 0)
    {
      analogWrite(LedL, abs(X-Y));
      analogWrite(LedR, abs(X));
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, LOW);
      Serial.println(X-Y);
      Serial.println(X);
    }
  }

  if (X > 0 && Y < 0)
  {
    int level = X + Y;
    if (level == 0)
    { analogWrite(LedL, 0);
      analogWrite(LedR, abs(Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, HIGH);
      Serial.println(g);
      Serial.println(Y);
    }
    if (level > 0)
    {
      analogWrite(LedL, abs(X));
      analogWrite(LedR, abs(X-Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, HIGH);
      Serial.println(X);
      Serial.println(X-Y);
      
    }
    if (level < 0)
    {
      analogWrite(LedL, abs(Y));
      analogWrite(LedR, abs(X-Y));
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, HIGH);
      Serial.println(Y);
      Serial.println(X-Y);
    }
  }

  delay(200);
}

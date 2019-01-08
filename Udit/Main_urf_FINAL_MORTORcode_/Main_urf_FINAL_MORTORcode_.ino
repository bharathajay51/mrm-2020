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
int g = 0;
int l = 0;
int r = 0;

int Display(int, int);




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

  joylevel1 = analogRead(joy1);
  joylevel2 = analogRead(joy2);
  //Serial.println(joylevel1);
  k1 = joylevel1 - 512;
  k2 = joylevel2 - 512;


  X = (k1 / 2);


  Y = (k2 / 2);


  if (X < 10 && X > -10)
  {
    X = 0;
  }
  if (Y < 10 && Y > -10)
  {
    Y = 0;
  }
  X = constrain(X, -255, 255);
  Y = constrain(Y, -255, 255);
  //  Serial.print("X val: "); Serial.print( X); Serial.print("                 ");  Serial.print("Y val: "); Serial.print( Y); Serial.print("\n");

  if (X >= 0 && Y >= 0)
  {
    int level = X - Y;
    if (level == 0)
    {
      analogWrite(LedL, abs(X));
      analogWrite(LedR, g);
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, LOW);
      l = X;
      r = g;
      Display(l, r);
    }
    if (level > 0)
    {
      analogWrite(LedL, abs(X));
      analogWrite(LedR, abs(X - Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, HIGH);
      l = X;
      r = -(X - Y);
      Display(l, r);


    }
    if (level < 0)
    {
      analogWrite(LedL, abs(Y));
      analogWrite(LedR, abs(X - Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, LOW);
      l = Y;
      r = -(X - Y);
      Display(l, r);

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
      l = 0;
      r = (Y);
      Display(l, r);
    }
    if (level > 0)
    {
      analogWrite(LedL, abs(Y + X));
      analogWrite(LedR, abs(Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, LOW);
      l = (Y + X);
      r = Y;
      Display(l, r);

    }
    if (level < 0)
    {
      analogWrite(LedL, abs(X + Y));
      analogWrite(LedR, abs(X));
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, LOW);
      l = X + Y;
      r = -X;
      Display(l, r);
    }
  }
  if (X >= 0 && Y <= 0)
  {
    int level = X + Y;
    if (level == 0)
    { analogWrite(LedL, 0);
      analogWrite(LedR, abs(Y));
      digitalWrite(LedRevL, LOW);
      digitalWrite(LedRevR, HIGH);
      l = 0;
      r = Y;
      Display(l, r);
    }
    if (level > 0)
    {
      analogWrite(LedL, abs(X + Y));
      analogWrite(LedR, abs(X));
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, HIGH);
      Serial.println("L");
      l = (X + Y);
      r = -(X);
      Display(l, r);

    }
    if (level < 0)
    {
      analogWrite(LedL, abs(X + Y));
      analogWrite(LedR, abs(Y));
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, HIGH);
      l = X + Y;
      r = Y;
      Display(l, r);
    }
  }
  
  if (X <= 0 && Y <=0)
  {
    int level = X - Y;
    if (level == 0)
    { analogWrite(LedL, abs(X));
      analogWrite(LedR, 0);
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, LOW);
      l = X;
      r = 0;
      Display(l, r);
    }
    if (level > 0)
    {    
         
      analogWrite(LedL, abs(Y));
      analogWrite(LedR, abs(X - Y));
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, HIGH);
      l = Y;
      r = -(X - Y);
      
      Display(l, r);
    }
    if (level < 0)
    {
      analogWrite(LedL, abs(X));
      analogWrite(LedR, abs(X - Y));
      digitalWrite(LedRevL, HIGH);
      digitalWrite(LedRevR, LOW);
      l = X;
      r = -(X - Y);
   
      Display(l, r);
     
    }
  }



  delay(100);



}
int Display(int l, int r)
{
 // l = constrain(l, -255, 255);
 // r = constrain(r, -255, 255);
  Serial.print("L: "); Serial.print(l); Serial.print("             "); Serial.print("R: "); Serial.print((r)); Serial.print("\n");
  return(0);
}

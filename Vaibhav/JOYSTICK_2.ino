int enA = 6;
int left1_fwd = 2;
int left1_bkwd = 3;
int enB = 9;
int right1_fwd = 4;
int right1_bkwd = 5;
int enC = 10;
int left2_fwd = 7;
int left2_bkwd = 8;
int enD = 11;
int right2_fwd = 12;
int right2_bkwd = 13;
void setup()
{
pinMode(enA,OUTPUT);
pinMode(left1_fwd,OUTPUT);
pinMode(left1_bkwd,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(right1_fwd,OUTPUT);
pinMode(right1_bkwd,OUTPUT);
pinMode(enC,OUTPUT);
pinMode(left2_fwd,OUTPUT);
pinMode(left2_bkwd,OUTPUT);
pinMode(enD,OUTPUT);
pinMode(right2_fwd,OUTPUT);
pinMode(right2_bkwd,OUTPUT);
Serial.begin(9600);
}

int xAxis = analogRead(A0);
int yAxis = analogRead(A1);
int motorSpeedA = 0;
int motorSpeedB = 0;
int motorSpeedC = 0;
int motorSpeedD = 0;

int x1 = map(xAxis,512,1023,0,255);
int x2 = map(xAxis,512,0,0,255);
int y1 = map(yAxis,512,1023,0,255);
int y2 = map(yAxis,512,0,0,255);


void my_func()
{
  if(yAxis == 512 and xAxis == 512)
  {
    motorSpeedA = 0;
    motorSpeedB = 0;
    motorSpeedC = 0;
    motorSpeedD = 0;
  }
  else if(yAxis < 512)
  {
    if(yAxis < xAxis and xAxis < 512)
    {
      motorSpeedA = y2;
      motorSpeedC = y2;
      leftBackward();
      motorSpeedB = x2 - y2;
      motorSpeedD = x2 - y2;
      rightBackward();
    }
    else if(yAxis < 1023 - xAxis and xAxis > 512)
    {
      motorSpeedA = x1 - y2;
      motorSpeedC = x1 - y2;
      leftBackward();
      motorSpeedB = y2;
      motorSpeedD = y2;
      rightBackward();
    }
   else if(yAxis > xAxis and xAxis < 512)
   {
      motorSpeedA = x2 - y2;
      motorSpeedC = x2 - y2;
      leftBackward();
      motorSpeedB = x2 + y2;
      motorSpeedD = x2 + y2;
      rightForward();
   }
   else if(yAxis > 1023 - xAxis and xAxis > 512)
   {
      motorSpeedA = x1 + y2;
      motorSpeedC = x1 + y2;
      leftForward();
      motorSpeedB = x1 - y2;
      motorSpeedD = x1 - y2; 
      rightBackward();
   }
  }

  else if(yAxis > 512)
  {
    if(yAxis > xAxis and xAxis > 512)
    {
      motorSpeedA = y1;
      motorSpeedC = y1;
      leftForward();
      motorSpeedB = x1 - y1;
      motorSpeedD = x1 - y1;
      rightForward();
    }
    else if(yAxis < xAxis and xAxis > 512)
     {
      motorSpeedA = x1 + y1;
      motorSpeedC = x1 + y1;
      leftForward();
      motorSpeedB = x1 - y1;
      motorSpeedD = x1 - y1;
      rightBackward();
     }
    else if(yAxis > 1023 - xAxis and xAxis < 512)
    {
      motorSpeedA = x2 - y1;
      motorSpeedC = x2 - y1;
      leftForward();
      motorSpeedB = y1;
      motorSpeedD = y1;
      rightForward();
    }
    else if(yAxis < 1023 - xAxis and xAxis < 512)
    {
      motorSpeedA = x2 - y1;
      motorSpeedC = x2 - y1;
      leftBackward();
      motorSpeedB = x2 + y1;
      motorSpeedD = x2 + y1;
      rightForward();
    }
  }
}

void leftForward()
{
  digitalWrite(left1_fwd,HIGH);
  digitalWrite(left2_fwd,HIGH);
  digitalWrite(left1_bkwd,LOW);
  digitalWrite(left2_bkwd,LOW);
  digitalWrite(right1_fwd,LOW);
  digitalWrite(right2_fwd,LOW);
  digitalWrite(right1_bkwd,LOW);
  digitalWrite(right2_bkwd,LOW);
}

void leftBackward()
{
  digitalWrite(left1_fwd,LOW);
  digitalWrite(left2_fwd,LOW);
  digitalWrite(left1_bkwd,HIGH);
  digitalWrite(left2_bkwd,HIGH);
  digitalWrite(right1_fwd,LOW);
  digitalWrite(right2_fwd,LOW);
  digitalWrite(right1_bkwd,LOW);
  digitalWrite(right2_bkwd,LOW);
}

void rightForward()
{
  digitalWrite(left1_fwd,LOW);
  digitalWrite(left2_fwd,LOW);
  digitalWrite(left1_bkwd,LOW);
  digitalWrite(left2_bkwd,LOW);
  digitalWrite(right1_fwd,HIGH);
  digitalWrite(right2_fwd,HIGH);
  digitalWrite(right1_bkwd,LOW);
  digitalWrite(right2_bkwd,LOW);
}

void rightBackward()
{
  digitalWrite(left1_fwd,LOW);
  digitalWrite(left2_fwd,LOW);
  digitalWrite(left1_bkwd,LOW);
  digitalWrite(left2_bkwd,LOW);
  digitalWrite(right1_fwd,LOW);
  digitalWrite(right2_fwd,LOW);
  digitalWrite(right1_bkwd,HIGH);
  digitalWrite(right2_bkwd,HIGH);
}

void loop()
{
  my_func();
  analogWrite(enA,motorSpeedA);
  Serial.println("L :");
  Serial.print(motorSpeedA);
  analogWrite(enB,motorSpeedB);
  Serial.println("R :");
  Serial.print(motorSpeedB);
  analogWrite(enC,motorSpeedC);
  analogWrite(enD,motorSpeedD);
}


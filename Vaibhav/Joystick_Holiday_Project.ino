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

void setup() {
  // put your setup code here, to run once:
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
}

void loop() {
int xAxis = analogRead(A0);
int yAxis = analogRead(A1);

int motorSpeedA = 0;
int motorSpeedB = 0;
int motorSpeedC = 0;
int motorSpeedD = 0;
int spA = 0;
int spB = 0;
int spC = 0;
int spD = 0;

int leftForward(int S_A,int S_C)
{
  digitalWrite(left1_fwd,HIGH);
  digitalWrite(left2_fwd,HIGH);
  S_A = map(yAxis,512,1023,0,255);
  S_C = map(yAxis,512,1023,0,255);
}
int leftBackward(int S_A,int S_C)
{
  digitalWrite(left1_bkwd,HIGH);
  digitalWrite(left2_bkwd,HIGH);
  S_A = map(yAxis,512,0,0,255);
  S_C = map(yAxis,512,0,0,255);
}
int rightForward(int S_B,int S_D)
{
  digitalWrite(right1_fwd,HIGH);
  digitalWrite(right2_fwd,HIGH);
 S_B = map(yAxis,512,1023,0,255);
 S_D = map(yAxis,512,1023,0,255);
}
int rightBackward(int S_B,int S_D)
{
  digitalWrite(right1_bkwd,HIGH);
  digitalWrite(right2_bkwd,HIGH);
  S_B = map(yAxis,512,0,0,255);
  S_D = map(yAxis,512,0,0,255);
}

//FIRST OCTANT
if(xAxis > 0 and xAxis < 512 and yAxis > 1023 - xAxis and yAxis > 512 and yAxis < 1023)
{
  leftForward(motorSpeedA,motorSpeedC);
  rightForward(motorSpeedB,motorSpeedD);   
}

//SECOND OCTANT 
else if(xAxis > 0 and xAxis < 512 and yAxis < 1023 - xAxis and yAxis > 512 and yAxis < 1023)
{
  leftForward(motorSpeedA,motorSpeedC);
  spA = map(xAxis,512,0,0,255);
  spC = map(xAxis,512,0,0,255);
  motorSpeedA = motorSpeedA + spA;
  motorSpeedC = motorSpeedC + spC;
  rightBackward(motorSpeedB,motorSpeedD);
  spB = map(xAxis,512,0,0,255);
  spD = map(xAxis,512,0,0,255);
  motorSpeedB = motorSpeedB - spB;
  motorSpeedD = motorSpeedD - spD;
}
//THIRD OCTANT
else if(xAxis > 0 and xAxis < 512 and yAxis > xAxis and yAxis < 512 and yAxis > 0)
{
  leftForward(motorSpeedA,motorSpeedC);
  spA = map(xAxis,512,0,0,255);
  spC = map(xAxis,512,0,0,255);
  motorSpeedA = motorSpeedA + spA;
  motorSpeedC = motorSpeedC + spC;
  rightBackward(motorSpeedB,motorSpeedD);
  spB = map(xAxis,512,0,0,255);
  spD = map(xAxis,512,0,0,255);
  motorSpeedB = motorSpeedB - spB;
  motorSpeedD = motorSpeedD - spD;
}
//FOURTH OCTANT
else if(xAxis > 0 and xAxis < 512 and yAxis < xAxis and yAxis < 512 and yAxis > 0)
{
  leftBackward(motorSpeedA,motorSpeedC);
  rightBackward(motorSpeedB,motorSpeedD);
}
//FIFTH OCTANT
else if(xAxis > 512 and xAxis < 1023 and yAxis < 1023 - xAxis and yAxis < 512 and yAxis > 0)
{
  leftBackward(motorSpeedA,motorSpeedC);
  rightBackward(motorSpeedB,motorSpeedD);
}
//SIXTH OCTANT
else if(xAxis > 512 and xAxis < 1023 and yAxis > 1023 - xAxis and yAxis < 512 and yAxis > 0)
{
  leftBackward(motorSpeedA,motorSpeedC); //
  spA = map(xAxis,512,1023,0,255);
  spC = map(xAxis,512,1023,0,255);
  motorSpeedA = motorSpeedA - spA;
  motorSpeedC = motorSpeedC - spC;
  rightForward(motorSpeedB,motorSpeedD);
  spB = map(xAxis,512,1023,0,255);
  spD = map(xAxis,512,1023,0,255);
  motorSpeedB = motorSpeedB + spB;
  motorSpeedD = motorSpeedD + spD;
}
//SEVENTH OCTANT
else if(xAxis > 512 and xAxis < 1023 and yAxis < xAxis and yAxis > 512 and yAxis < 1023)
{
  leftBackward(motorSpeedA,motorSpeedC); 
  spA = map(xAxis,512,1023,0,255);
  spC = map(xAxis,512,1023,0,255);
  motorSpeedA = motorSpeedA - spA;
  motorSpeedC = motorSpeedC - spC;
  rightForward(motorSpeedB,motorSpeedD);
  spB = map(xAxis,512,1023,0,255);
  spD = map(xAxis,512,1023,0,255);
  motorSpeedB = motorSpeedB + spB;
  motorSpeedD = motorSpeedD + spD;
}
//EIGHTH OCTANT
else if(xAxis > 512 and xAxis < 1023 and yAxis > xAxis and yAxis > 512 and yAxis < 1023)
{
  leftForward(motorSpeedA,motorSpeedC);
  rightForward(motorSpeedB,motorSpeedD);
}
else if(xAxis == 512 and yAxis == 512)
{
  motorSpeedA = 0;
  motorSpeedB = 0;
  motorSpeedC = 0;
  motorSpeedD = 0;
}
/*
void leftForward(int S_A,int S_C)
{
  digitalWrite(left1_fwd,HIGH);
  digitalWrite(left2_fwd,HIGH);
  S_A = map(yAxis,512,1023,0,255);
  S_C = map(yAxis,512,1023,0,255);
}
void leftBackward(int S_A,int S_C)
{
  digitalWrite(left1_bkwd,HIGH);
  digitalWrite(left2_bkwd,HIGH);
  S_A = map(yAxis,512,0,0,255);
  S_C = map(yAxis,512,0,0,255);
}
void rightForward(int S_B,int S_D)
{
  digitalWrite(right1_fwd,HIGH);
  digitalWrite(right2_fwd,HIGH);
 S_B = map(yAxis,512,1023,0,255);
 S_D = map(yAxis,512,1023,0,255);
}
void rightBackward(int S_B,int S_D)
{
  digitalWrite(right1_bkwd,HIGH);
  digitalWrite(right2_bkwd,HIGH);
  S_B = map(yAxis,512,0,0,255);
  S_D = map(yAxis,512,0,0,255);
}
*/
analogWrite(enA,motorSpeedA);
analogWrite(enB,motorSpeedB);
analogWrite(enC,motorSpeedC);
analogWrite(enD,motorSpeedD);
}

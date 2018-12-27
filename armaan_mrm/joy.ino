int y=A0;
int x=A1;
int lfrwd=13,lbcwd=12,rfrwd=2,rbcwd=1;
int pwmr=5,pwml=6;
int speedleft,speedright;
int xaxis,yaxis;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(lfrwd,OUTPUT);
pinMode(lbcwd,OUTPUT);
pinMode(rfrwd,OUTPUT);
pinMode(lbcwd,OUTPUT);
pinMode(lbcwd,OUTPUT);
pinMode(pwmr,OUTPUT);
pinMode(pwml,OUTPUT);
}
//return octant
int oct(int x1,int y1)
{if(x1==511 && y1==511)
  return 0;
  if((x1=>511 && x1<=1023)&&(y1>=0 && y1<=511))
  {if(y1>(-x1+1023))
    return 1;
   else
  return 2;}

  
   
}

void loop() {
// put your main code here, to run repeatedly:
xaxis=analogRead(x);
yaxis=analogRead(y);

int r=oct(xaxis,yaxis);
Serial.println(r);
Serial.print("X:");
Serial.println(xaxis);
Serial.print("Y:");
Serial.println(yaxis);

}

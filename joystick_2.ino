int pot1=A1;
int pot2=A2;
int x,y=0;
int a=0;
boolean mlf,mrf,mlb,mrb=0;
int lf=4;
int rf=5;
int lb=2;
int rb=3;
int xd1,yd1,xd2,yd2=0;
int pwml,pwmr=0;
int rp=9;
int lp=10;

void setup() {
  // put your setup code here, to run once:
pinMode(pot1,INPUT);
pinMode(pot2,INPUT);
pinMode(lf,OUTPUT);
pinMode(rf,OUTPUT);
pinMode(lb,OUTPUT);
pinMode(rb,OUTPUT);
pinMode(rp,OUTPUT);
pinMode(lp,OUTPUT);
Serial.begin(9600);
}
void potread()
{
  x=analogRead(pot1);
  y=analogRead(pot2);
  y=1023-y;
}
int joystick()
{
  if ((x<525 && x>505 ) && (y<525 && y>505))
  {
    mlf=0;
    mrf=0;
    mlb=0;
    mrb=0;
    return 0;
  }
  else if (y>=511)
  {
    if (x>=y && x>=511)
    {
      mlf=1;
      mrf=0;
      mlb=0;
      mrb=1;
      return 1;
    }
    else if (y>=x && x>=511)
    {
      mlf=1;
      mrf=1;
      mlb=0;
      mrb=0;
      return 2;
    }
    else if ( 1023-x<y && x<=511)
    {
      mlf=1;
      mrf=1;
      mlb=0;
      mrb=0;
      return 3;
    }
    else if (1023-x>=y && x<=511)
    {
      mlf=0;
      mrf=1;
      mlb=1;
      mrb=0;
      return 4;
    }
  }
  else if (y<511)
  {
    if (x<=y && x<=511)
    {
      mlf=0;
      mrf=1;
      mlb=1;
      mrb=0;
      return 5;
    }
    else if (y<=x && x<=511)
    {
      mlf=0;
      mrf=0;
      mlb=1;
      mrb=1;
      return 6;
    }
    else if (1023-x>=y && x>=511)
    {
      mlf=0;
      mrf=0;
      mlb=1;
      mrb=1;
      return 7;
    }
    else if (1023-x<y && x>=511)
    {
      mlf=1;
      mrf=0;
      mlb=0;
      mrb=1;
      return 8;
    }
  }
}
int mod(int n)
{
  if (n<0)
  {
    n=-n;
  }
  return n;
}
void pwmconv()
{
  xd1=map(x,511,1023,0,255);
  xd2=map(x,511,0,0,255);
  yd1=map(y,511,1023,0,255);
  yd2=map(y,511,0,0,255);
  
  
  if (a==0)
  {
    pwml=0;
    pwmr=0;
  }
  else if(a==1)
  {
    pwml=xd1;
    pwmr=mod(xd1-yd1);
  }
  else if(a==2)
  {
   pwml=yd1;
   pwmr=mod(yd1-xd1);
  }
  else if(a==3)
  {
    pwml=mod(yd1-xd2);
    pwmr=yd1;
  }
  else if(a==4)
  {
   pwml=mod(xd2-yd1);
   pwmr=xd2;
  }
  else if(a==5)
  {
    pwml=xd2;
    pwmr=mod(yd2-xd2);
  }
  else if(a==6)
  {
   pwml=yd2;
   pwmr=mod(xd2-yd2);
  }
  else if(a==7)
  {
    pwml=mod(yd2-xd1);
    pwmr=yd2;
  }
  else if(a==8)
  {
   pwml=mod(xd1-yd2);
   pwmr=xd1;
  }
  
}
void drive()
{
  digitalWrite(lf,mlf);
  digitalWrite(rf,mrf);
  digitalWrite(lb,mlb);
  digitalWrite(rb,mrb);
  analogWrite(rp,pwmr);
  analogWrite(lp,pwml);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  potread();
  a=joystick();
  pwmconv();
  drive();

  Serial.print("a ");
  Serial.println(a);
  
  Serial.print("pwmr ");
  Serial.println(pwmr);

  Serial.print("pwml ");
  Serial.println(pwml);
 
  
}

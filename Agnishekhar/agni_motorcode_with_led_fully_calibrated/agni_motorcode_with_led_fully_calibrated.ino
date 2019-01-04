//A0 is X axis 
//A5 is Y axis
#define xaxis A0
#define yaxis A5
int xv,yv;

int zeroradlower=485,zeroradupper=505,deadlower=470,deadupper=520,xmid=517,dirleft,dirright,lm,rm;


void setup() 
{
  pinMode(xaxis,INPUT);//not necessary just for readability
  pinMode(yaxis,INPUT);//not necessary
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  Serial.begin(9600);

}

void loop() 
{
  xv=analogRead(xaxis);
  yv=analogRead(yaxis);
Serial.print("X axis =");
Serial.print(xv);
Serial.print("      Y axis =");
Serial.println(yv);


if(yv>deadlower&&yv<deadupper)
{
  if(yv>zeroradlower&&yv<zeroradupper)//in zone 4
  {
    //do zero radius turn

    if(xv<=xmid)
    {
      lm=map(xv,0,xmid,255,0);
      rm=map(xv,0,xmid,255,0);
      dirleft=0;//back
      dirright=1;//front
    }
    else
    {
      lm=map(xv,xmid,1023,0,255);
      rm=map(xv,xmid,1023,0,255);
      dirleft=1;//forward
      dirright=0;//backward
    }
  }
  else
  {
    //is in zone 3 or 5 so do nothing
  }
}
else
{
  //in zones 1 ,2 ,6 ,7

  if(yv>deadupper)//move forward as in zones 1 and 2
  {
    dirleft=1;
    dirright=1;//forward both
    
    if(xv<xmid)//to the left
    {
      rm=map(yv,deadupper,1023,0,255);
      lm=map(xv,0,xmid,0,rm);
      
    }
    else
    {
      lm=map(yv,deadupper,1023,0,255);
      int x=xv-xmid;if(x<0){x=0;}
      rm=map(x,0,1023-xmid,lm,0);
    }
  }
  if(yv<deadlower)//move back as in zones 6 and 7
  {
    //dir=0;//back both
    dirleft=0;
    dirright=0;

    if(xv<xmid)//joystick is back left so rover is back right motion
    {
      lm=map(yv,0,deadlower,255,0);
      rm=map(xv,0,xmid,0,lm);
    }
    else//joystick is back right so rover is back left motion
    {
      rm=map(yv,0,deadlower,255,0);
      int x=xv-xmid;if(x<0){x=0;}
      lm=map(x,0,1023-xmid,rm,0);
    }
    
  }
}

Serial.print("dirleft   ");
Serial.print(dirleft);
Serial.print("  ");
Serial.print(lm);
Serial.print("   dirright  ");
Serial.print(dirright);
Serial.print("    ");
Serial.println(rm);

if(dirleft==1)
{
  analogWrite(11,lm);
  analogWrite(10,0);
}
else
{
  analogWrite(10,lm);
  analogWrite(11,0);
}

if(dirright==1)
{
  analogWrite(6,rm);
  analogWrite(5,0);
}
else
{
  analogWrite(5,rm);
  analogWrite(6,0);
}


//delay(600);
  
}

/*
 * Parthivi Choubey
 * Motor code.
 */

 int x,y;
 int a,b;
 int q;
 int lpwm,rpwm;

int octant(int p, int q)
{
  int c=0;
  if(p==0 && q==0) c=0;
  else if(p>=0 && q<=0)
  {
    if(p+q>0) c=1;
    else c=2;
  }
  else if(p<=0 && q<=0)
  {
    if(p-q>0) c=3;
    else c=4;
  }
  else if(p<=0 && q>=0)
  {
    if(p+q>0) c=6;
    else c=5;
  }
  else if(p>=0 && q>=0)
  {
    if(p-q>0) c=8;
    else c=7;
  }
  return c;
}

void direction(int z)
{
  if(z==5) z=8;
  else if(z==8) z=5;
  
  if(z==0) Serial.print("Left:0 \t Right:0\t");
  else if(z==1 || z==5) Serial.print("Left:F \t Right:B\t");
  else if(z==2 || z==3) Serial.print("Left:F \t Right:F\t");
  else if(z==4 || z==8) Serial.print("Left:B \t Right:F\t");
  else if(z==6 || z==7) Serial.print("Left:B \t Right:B\t");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
/*
  x=analogRead(A0);
  y=analogRead(A1);
  Serial.print(x);
  Serial.println(y);
*/
  x = (analogRead(A0))-512; //x-axis = A0
  y = (analogRead(A1))-512; //y-axis = A1

  a=abs(x);
  b=abs(y);
  if(a<10) x=0;
  if(b<10) y=0;

  q = octant(x,y);
  direction(q);

  a = abs(x+y);
  b = abs(x-y);
  if(a>512) a=512;
  if(b>512) b=512;
  
  rpwm=map(a,0,512,0,255);
  lpwm=map(b,0,512,0,255);
  
  Serial.print("Lpwm=");
  Serial.print(lpwm);
  Serial.print("\t Rpwm=");
  Serial.println(rpwm);
}

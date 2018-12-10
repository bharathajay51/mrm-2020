int sw = 12;
int x = A1;
int y = A0;
int left_fwd = 11;
int left_back = 10;
int right_fwd = 6;
int right_back = 5;
int left_rear_fwd = 11, left_rear_back = 10, right_rear_fwd = 6, right_rear_back = 5;         //extra line for four wheeled bot
int X_read, Y_read;
int x_12, y_12;
int x_34, y_34;
int x_56, y_56;
int x_78, y_78;

void setup() {
  // put your setup code here, to run once:
pinMode(sw, INPUT);
digitalWrite(sw, HIGH);
Serial.begin(9600);
pinMode(left_fwd,OUTPUT);
pinMode(left_back,OUTPUT);
pinMode(right_fwd,OUTPUT);
pinMode(right_back,OUTPUT);
pinMode(left_rear_fwd,OUTPUT);            //extra line for four wheeled bot
pinMode(left_rear_back,OUTPUT);           //extra line for four wheeled bot
pinMode(right_rear_fwd,OUTPUT);           //extra line for four wheeled bot
pinMode(right_rear_back,OUTPUT);          //extra line for four wheeled bot
}

void loop() {
  // put your main code here, to run repeatedly:
X_read = analogRead(x);
Y_read = analogRead(y);
  
  
  while((X_read<524||X_read>500)&&(Y_read<524||Y_read>500))
  {
     analogWrite(left_fwd , 0);      
     analogWrite(right_fwd , 0);
     analogWrite(left_back , 0);      
     analogWrite(right_back , 0);

     analogWrite(left_rear_fwd , 0);      //extra line for four wheeled bot
     analogWrite(right_rear_fwd , 0);     //extra line for four wheeled bot
     analogWrite(left_rear_back , 0);     //extra line for four wheeled bot
     analogWrite(right_rear_back , 0);    //extra line for four wheeled bot
     
     X_read = analogRead(x);
     Y_read = analogRead(y);
  }

Serial.print("X_read: ");
Serial.println(X_read);
Serial.print("Y_read: ");
Serial.println(Y_read);

if ((X_read+Y_read)<=1023&&X_read<=512&&Y_read>=512)
  oct1();

if ((X_read+Y_read)>=1023&&X_read<=512&&Y_read>=512)
  oct2();

if ((X_read-Y_read)<=0&&X_read>=512&&Y_read>=512)
  oct3();

if ((X_read-Y_read)>=0&&X_read>=512&&Y_read>=512)
  oct4();
  
if ((X_read+Y_read)>=1023&&X_read>=512&&Y_read<=512)
  oct5();

if ((X_read+Y_read)<=1023&&X_read>=512&&Y_read<=512)
  oct6();

if ((X_read-Y_read)>=0&&X_read<=512&&Y_read<=512)
  oct7();

if ((X_read-Y_read)<=0&&X_read<=512&&Y_read<=512)
  oct8();
  
}

void oct1()
{
  x_12 = map(X_read,512,0,0,255);
  y_12 = map(Y_read,512,1023,0,255);
  
  analogWrite(left_fwd , x_12);              //lf
  analogWrite(right_back , x_12-y_12);              //rb
  
  analogWrite(left_rear_fwd , x_12);              //extra line for four wheeled bot
  analogWrite(right_rear_back , x_12-y_12);              //extra line for four wheeled bot
}

void oct2()
{
  x_12 = map(X_read,512,0,0,255);
  y_12 = map(Y_read,512,1023,0,255);
  
  analogWrite(left_fwd , y_12);              //lf
  analogWrite(right_fwd , y_12-x_12);             //rf
  
  analogWrite(left_rear_fwd , y_12);              //extra line for four wheeled bot
  analogWrite(right_rear_fwd , y_12-x_12);             //extra line for four wheeled bot
}

void oct3()
{
  x_34 = map(X_read,512,1023,0,255);
  y_34 = map(Y_read,512,1023,0,255);
  
  analogWrite(left_fwd , y_34-x_34);               //lf
  analogWrite(right_fwd , y_34);              //rf
  
  analogWrite(left_rear_fwd , y_34-x_34);               //extra line for four wheeled bot
  analogWrite(right_rear_fwd , y_34);              //extra line for four wheeled bot
}

void oct4()
{
  x_34 = map(X_read,512,1023,0,255);
  y_34 = map(Y_read,512,1023,0,255);
  
  analogWrite(left_back , x_34-y_34 );                //lb
  analogWrite(right_fwd , x_34);              //rf

  analogWrite(left_rear_back , x_34-y_34 );                //extra line for four wheeled bot
  analogWrite(right_rear_fwd , x_34);              //extra line for four wheeled bot
}

void oct5()
{
  x_56 = map(X_read,512,1023,0,255);
  y_56 = map(Y_read,512,0,0,255);
  
  analogWrite(left_back , x_56);                //lb
  analogWrite(right_fwd , x_56-y_56);            //rf

  analogWrite(left_rear_back , x_56);                //extra line for four wheeled bot
  analogWrite(right_rear_fwd , x_56-y_56);           //extra line for four wheeled bot
}

void oct6()
{
  x_56 = map(X_read,512,1023,0,255);
  y_56 = map(Y_read,512,0,0,255);
  
  analogWrite(left_back , y_56);                //lb
  analogWrite(right_back , y_56-x_56);            //rb

  analogWrite(left_rear_back , y_56);                //extra line for four wheeled bot
  analogWrite(right_rear_back , y_56-x_56);         //extra line for four wheeled bot
}

void oct7()
{
  x_78 = map(X_read,512,0,0,255);
  y_78 = map(Y_read,512,0,0,255);
  
  analogWrite(left_back , y_78-x_78);                //lb
  analogWrite(right_back , y_78);            //rb

  analogWrite(left_rear_back , y_78-x_78);                //extra line for four wheeled bot
  analogWrite(right_rear_back , y_78);            //extra line for four wheeled bot
}

void oct8()
{
  x_78 = map(X_read,512,0,0,255);
  y_78 = map(Y_read,512,0,0,255);
  
  analogWrite(left_fwd , x_78-y_78);                //lf
  analogWrite(right_back , x_78);            //rb

  analogWrite(left_rear_fwd , x_78-y_78);               //extra line for four wheeled bot
  analogWrite(right_rear_back , x_78);            //extra line for four wheeled bot
}

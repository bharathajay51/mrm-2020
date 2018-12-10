//Abhiraj Tiwari
int xpin = A0;
int ypin = A1;

int mle = 10; 
int mlf = 8;  
int mlb = 9;  

int mre = 5;
int mrf = 3;
int mrb = 4;


void setup() {
  //Serial.begin(9600);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);

  pinMode(mle, OUTPUT);
  pinMode(mlf, OUTPUT);
  pinMode(mlb, OUTPUT);

  pinMode(mre, OUTPUT);
  pinMode(mrf, OUTPUT);
  pinMode(mrb, OUTPUT);
}

void move_motors (int l, int r, boolean ldir, boolean rdir) {
  digitalWrite(mlf, ldir);
  digitalWrite(mlb, !ldir);
  digitalWrite(mrf, rdir);
  digitalWrite(mrb, !rdir);
  analogWrite(mle, l);
  analogWrite(mre, r);
}

void loop() {
  int x = analogRead(xpin) - 508; //508 and 516 are correction terms for *MY* joystick. It does not center at 512, 512
  int y = analogRead(ypin) - 516; //so that the origin of the joystick is in the center
  //map the above values from -255 to 255 (and inverted for y, idk why but the joystick behaves this way)
  x = constrain(map(x, -512, 512, -255, 255), -255, 255);
  y = constrain(map(y, -512, 512, 255, -255), -255, 255); //doing these brings the value of joystick to the same scale as pwm
  //Serial.print(x); Serial.print('\t'); Serial.print(y); Serial.print('\n');
  int lpwm = constrain((x+y), -255, 255); //After taking 8 points (one on each axis and 4 on x=y and y=x line), by observation the value for left pwm is sum, and difference for right, 
                                                //checked for a few points in between to confirm
  int rpwm = constrain((y-x), -255, 255); //constrain because value exceed 255 after adding or subtracting
  boolean rd = (rpwm>0 ? HIGH : LOW);
  boolean ld = (lpwm>0 ? HIGH : LOW); // direction is forward if true and backward if false
  lpwm = abs(lpwm);
  rpwm = abs(rpwm); //pwm can't be negative
  move_motors(lpwm, rpwm, ld, rd);

  //tested on LEDs, seems fine
}

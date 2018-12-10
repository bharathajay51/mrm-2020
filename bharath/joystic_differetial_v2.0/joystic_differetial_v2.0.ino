const byte pot_Y = A0; //Analog Jostick Y axis
const byte pot_X = A1; //Analog Jostick X axis

const byte left_forward = 3; //(left motor forward)
const byte left_reverse = 4;  //(left motor reverse)
const byte right_forward = 5;  //(right motor forward)
const byte right_reverse = 6;  //(right motor reverse)

const byte left_enable = 9;
const byte right_enable = 10;

int throttle,steering = 0;

int left_motor, left_output = 0;
int right_motor, right_output = 0;

int deadZone = 10;
 
void setup()
{
  Serial.begin(9600);
  pinMode(left_forward, OUTPUT);
  pinMode(left_reverse, OUTPUT);
  pinMode(right_forward, OUTPUT);
  pinMode(right_reverse, OUTPUT);  
  pinMode(left_enable,OUTPUT);
  pinMode(right_enable,OUTPUT);
}

void loop()
{
  throttle = (512-(analogRead(pot_Y)))/2;
  steering = -(512-(analogRead(pot_X)))/2;

  left_motor = throttle+steering;
  right_motor = throttle-steering;

  mixer(left_motor,right_motor);

  //*************** LEFT MOTOR ***************//

  if(abs(left_output)>deadZone)
  {

    if (left_output > 0)
    {
      // left motor is going forward.
      digitalWrite(left_reverse,0);
      digitalWrite(left_forward,1);
      analogWrite(left_enable,abs(left_output));            
    }
    else 
    {
      // left motor is going backwards.
      digitalWrite(left_forward,0);
      digitalWrite(left_reverse,1);
      analogWrite(left_enable,abs(left_output));  
    }
  }  
  else 
  {
    //left motor is in deadzone(stop the motor)
    digitalWrite(left_forward,0);
    digitalWrite(left_reverse,0);
  } 

//**************** RIGHT MOTOR *****************// 

  if(abs(right_output)>deadZone)
  {

    if (right_output > 0)
    {
      // right motor forward
      digitalWrite(right_reverse,0);
      digitalWrite(right_forward,1);
      analogWrite(right_enable,abs(right_output));            
    }
    else 
    {
      // right motor reverse
      digitalWrite(right_forward,0);
      digitalWrite(right_reverse,1);
      analogWrite(right_enable,abs(right_output));
    }
  }  
  else 
  {
  // right motor in dead zone (stop)
  analogWrite(right_forward,0);
  analogWrite(right_reverse,0);
  } 
  Serial.println("");
  delay(10);

}

void mixer (int left_init , int right_init)
{
  float L_scale,R_scale,max_scale;

  L_scale = left_init/255.0;
  L_scale = abs(L_scale);
  R_scale = right_init/255.0;
  R_scale = abs(R_scale);

  max_scale = max(L_scale,R_scale);
  max_scale = max(1,max_scale);

  left_output = constrain(left_init/max_scale,-255,255);
  right_output = constrain(right_init/max_scale,-255,255);

  Serial.println("L_Final:"); Serial.print(left_output);
  Serial.print(", R_Final:"); Serial.print(right_output);
}

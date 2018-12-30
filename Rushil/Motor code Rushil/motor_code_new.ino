/* 
 *  code checks out on serial monitor.
 *  getting right values for rpwm,valx,val,lpwm 
 *  code works for LEDs
 */
int jx = A0;
int jy = A1;
bool rf = 0;
bool rb = 0;
bool lf = 0;
bool lb = 0;
float rpwm = 0;
float lpwm = 0;
int LED[6] = {6,8,9,10,11,12};// 
float N = 0;
float valx = 0;
float valy = 0;
bool dirx = 0;
bool diry = 0;
void input()
{ 
  valx = analogRead(jx);
  valy = analogRead(jy);
  
  valx = ((valx-512)/512)*100;
  valy = ((valy-512)/512)*100;
  Serial.println(valx);
  Serial.println(valy);
 
 
}
void process()
{ float turn_eff = 0;
  N = valy;
  turn_eff = abs(valx);
  
  if(valx>0)
  { Serial.println("hi positive");
    rpwm = N - turn_eff;
    lpwm = N + turn_eff;
    if(rpwm<0)
    {
      rf = 0;
      rb = 1;
    }
    else if(rpwm>0)
    {
      rf = 1;
      rb = 0;
    }
    if(lpwm<0)
    {
      lf = 0;
      lb = 1;
    }
    else if(lpwm>0)
    {
      lf = 1;
      lb = 0;
    }
  }
  else if(valx<0)
  { Serial.println("hi negative");
    rpwm = N + turn_eff;
    lpwm = N - turn_eff;
    
    if(rpwm<0)
    {
      rf = 0;
      rb = 1;
    }
    else if(rpwm>0)
    {
      rf = 1;
      rb = 0;
    }
    if(lpwm<0)
    {
      lf = 0;
      lb = 1;
    }
    else if(lpwm>0)
    {
      lf = 1;
      lb = 0;
    }
  
    
  }
  else if(valx == 0)
  { Serial.println("hi");
    rpwm = N ;
    lpwm = N ;
    if(rpwm<0)
    {
      rf = 0;
      rb = 1;
    }
    else if(rpwm>0)
    {
      rf = 1;
      rb = 0;
    }
    if(lpwm<0)
    {
      lf = 0;
      lb = 1;
    }
    else if(lpwm>0)
    {
      lf = 1;
      lb = 0;
    }
  } 
    Serial.println(lpwm);
    Serial.println(lf);
    Serial.println(lb);
    Serial.println(rpwm);
    Serial.println(rf);
    Serial.println(rb);
    rpwm = abs(rpwm);
    lpwm = abs(lpwm);
    
    rpwm = map(rpwm,0,100,0,255);
    lpwm = map(lpwm,0,100,0,255);
    
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(jx,INPUT);
  pinMode(jy,INPUT);
  for(int i = 0;i<4;i++)
  {
    pinMode(LED[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  float a,b;
  input();
  
  process();
  
  digitalWrite(LED[3],lf);//10
  digitalWrite(LED[5],lb);//12
  digitalWrite(LED[0],rf);//6
  digitalWrite(LED[1],rb);//8
  analogWrite(LED[2],lpwm);//9
  analogWrite(LED[4],rpwm);//11
 
  delay(5);
}

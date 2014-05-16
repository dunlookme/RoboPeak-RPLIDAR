const int DesiredRPM=300;  // Setting Desired RPM Here.
const int MotorPWMPin=14;
int inByte = 0;         // incoming serial byte
String inData = "";

unsigned char Data_status=0;
unsigned char Data_4deg_index=0;
unsigned char Data_loop_index=0;
unsigned char SpeedRPHhighbyte=0; // 
unsigned char SpeedRPHLowbyte=0;

int SpeedRPH=0;
const unsigned char PWM4dutyMax=255;
const unsigned char PWM4dutyMin=100;
unsigned char PWM4duty=PWM4dutyMin;  // have to set a default value make motor start spining

void setup() {
  Serial.begin(115200);

  pinMode(MotorPWMPin, OUTPUT); 

  // Pick your magic number and drive your motor , 178 is 178/255*5V=3.49V
  analogWrite(MotorPWMPin, PWM4duty );  
}

void loop() {
  inData = "";
  String message = "";
  String message2 = "";
  
  if (Serial.available() > 0) {
    int h=Serial.available();    
    // if you are getting escape -characters try h--; here
     
    for (int i=0;i<h;i++){
      inData += (char)Serial.read();
    }
  }
  
  message = message + "RPM: " + PWM4duty;
  message2 = message2 + " Data: " + inData;
  
  Serial.println(message);
  Serial.println(message2);
  
  SpeedControl ( DesiredRPM );
}

void SpeedControl ( int RPMinput){
/*
  if (Data_4deg_index%30==0) {  // I only do 3 updat I feel it is good enough for now
    if (SpeedRPH<RPMinput*60){
      if (PWM4duty<PWM4dutyMax){
        PWM4duty++; // limit the max PWM make sure it don't overflow and make LDS stop working
      }
    } 
    if (SpeedRPH>RPMinput*60){
      if(PWM4duty>PWM4dutyMin){
        PWM4duty--;  //Have to limit the lowest pwm keep motor running
      }
    }
  }
*/
  PWM4duty = PWM4dutyMax;
  analogWrite(MotorPWMPin, PWM4duty ); // update value
}

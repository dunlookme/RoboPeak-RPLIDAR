String inData;

void setup(){
  Serial.begin(115200);
}

void loop(){
  inData="";
  if (Serial.available() > 0) {
    int h=Serial.available();    
    // if you are getting escape -characters try h--; here
     
    for (int i=0;i<h;i++){
      inData += (char)Serial.read();
    }

  // if you are getting escape -characters try Serial.read(); here
  }
  //print it out
  Serial.println(inData);
}

/*
Enter value between -100 and 100 to control the motor...
And Select No Line Ending
*/
#define R_pwm PA1
#define L_pwm PA2

#define resolution 255

int speedVal = 255;

void mControl(int val) {
 
  // Determine direction
  if (val < 0) {
    // Motor backward
    analogWrite(R_pwm, 0);
    delay(10);  //OCD delay because IBT2 will fry if both pwm pins are high simultaneously
    analogWrite(L_pwm, -val);
  } else {
    // Motor forward
    analogWrite(L_pwm, 0);
    delay(10);  //OCD delay because IBT2 will fry if both pwm pins are high simultaneously
    analogWrite(R_pwm, val);
  } 
}

void setup() {
  pinMode(L_pwm, OUTPUT);
  pinMode(R_pwm, OUTPUT);

  Serial.begin(115200);

  Serial.println("Enter value between -100 and 100 to control the motor...");
  Serial.println("And Select No Line Ending");

  delay(4000);
}

void loop() {
  if(Serial.available())
  {
    Serial.println("got data from serial");
    speedVal = Serial.parseInt();
    
    speedVal = constrain(speedVal, -100, 100);
    speedVal = map(speedVal, -100, 100, -resolution, resolution);  
  }
  
  mControl(speedVal);

  Serial.println(speedVal);
  delay(1000);
}

/*
Enter value between 1000 and 2000 to control the motor...
And Select No Line Ending
*/

#include "Motor.h"

#define LPWM PA1
#define RPWM PA2


int speedVal = 1900;

Motor wheel(LPWM,RPWM);

void setup() {
  Serial.begin(57600);

  Serial.println("Enter value between 1000 and 2000 to control the motor...");
  Serial.println("And Select No Line Ending");

  delay(4000);
}

void loop() {
  if(Serial.available())
  {
    Serial.println("got data from serial");
    speedVal = Serial.parseInt();
    
    speedVal = constrain(speedVal, 1000, 2000);
    // speedVal = map(speedVal, -100, 100, -resolution, resolution);  
  }
  
  wheel.rotate(speedVal);

  Serial.println(speedVal);
  delay(1000);
}

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int val = 1500;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
}


void loop() {
  if(Serial.available())
    val = Serial.parseInt();
  myservo.writeMicroseconds(val);
  delay(15);                           // waits for the servo to get there
}

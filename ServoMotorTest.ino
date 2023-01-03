#include <Servo.h>  // include the servo library

Servo myservo;  // create a servo object

void setup() {
  myservo.attach(9);  // attach the servo to pin 9
  Serial.begin(115200);  // start the serial communication

  Serial.println("Enter value between 0 and 180 to control the servo motor...");
  Serial.println("And Select No Line Ending")
}

void loop() {
  int angle;  // variable to store the angle

  if (Serial.available() > 0) 
  {  // check if there is data available from the serial port
     Serial.println("got data from serial");
    angle = Serial.parseInt();  // read the angle from the serial port

    myservo.write(angle);  // set the servo position
  }

  Serial.println(angle);
  delay(1000);
}
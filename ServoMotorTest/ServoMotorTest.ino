#include <Servo.h>  // include the servo library
#define servoPin 2 //this is the pin to connect to servo signal wire

Servo myservo;  // create a servo object

void setup() {
  myservo.attach(servoPin);     // attach the servo to pin 9
  Serial.begin(115200);  // start the serial communication

  Serial.println("Enter value between 1000 and 2000 to control the servo motor...");
  Serial.println("And Select No Line Ending");
}

void loop() {
  int value;  // variable to store the angle

  if (Serial.available() > 0) {  // check if there is data available from the serial port
    Serial.println("got data from serial");
    int x = Serial.parseInt();  // read the angle from the serial port
    Serial.print("data read: ");
    Serial.println(x);

    if (x >= 100 and x <= 2900)
      value = x;
  }
  myservo.writeMicroseconds(value);  // set the servo position
  
  Serial.println(value);
  delay(100);
}
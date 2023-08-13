#include <Wire.h>
HardwareSerial Serial(PA10, PA9); // PA10-RX PIN, PA9 - TX PIN
 
const int VS_A = PB0;  // Pin connected to Voltage Sensor 
const int VS_C = PB1;  // Pin connected to Voltage Sensor 

void setup() {
  Serial.begin(9600);  // Initialize the serial monitor
}

void loop() {
 
  float voltage_sensor_A = analogRead(VS_A) ; 

 
  float voltage_sensor_C = analogRead(VS_C) ; 

 
  Serial.print("Voltage 1: ");
  Serial.println(voltage_sensor_A);
  

  Serial.print("Voltage 2: ");
  Serial.println(voltage_sensor_C);
  

  delay(1000);  
}

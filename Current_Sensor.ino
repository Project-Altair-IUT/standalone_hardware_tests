#include <Wire.h>
HardwareSerial Serial(PA10, PA9); // PA10-RX PIN, PA9 - TX PIN

const int CSW_1 = PA0;  
const int CSW_2 = PA1;  
const int CSW_3 = PA2;  
const int CSW_4 = PA3;
const int CSA_1 = PA4; 
const int CSA_2 = PA5;
const int CSC_1 = PA6; 

void setup() {
  Serial.begin(9600);  // Initialize the serial monitor
}

void loop() {
  
  float current_W1 = analogRead(CSW_1) * (3.3 / 4095.0);  

  float current_W2 = analogRead(CSW_2) * (3.3 / 4095.0);  

  float current_W3 = analogRead(CSW_3) * (3.3 / 4095.0);  

  float current_W4 = analogRead(CSW_4) * (3.3 / 4095.0);  

  float current_A1 = analogRead(CSA_1) * (3.3 / 4095.0); 

  float current_A2 = analogRead(CSA_2) * (3.3 / 4095.0); 

  float current_C1 = analogRead(CSC_1) * (3.3 / 4095.0); 

  
  Serial.println("Current Wheel_1: ");
  Serial.println(CSW_1);
  

  Serial.println("Current Wheel_2: ");
  Serial.println(CSW_2);
  

  Serial.println("Current Wheel_3: ");
  Serial.println(CSW_3);
  

  Serial.println("Current Wheel_4: ");
  Serial.println(CSW_4);

  Serial.println("Current Arm_1: ");
  Serial.println(CSA_1);

  Serial.println("Current Arm_2: ");
  Serial.println(CSA_2);

  Serial.println("Current Collector_1: ");
  Serial.println(CSC_1);
  

  delay(1000); 
}

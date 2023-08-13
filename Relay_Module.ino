#include <Wire.h>

// Pin Definitions
const int DIGI_Wheel = PB4;         
const int DIGI_Arm = PB3;            
const int DIGI_Collection = PA15;    

// Relay Class
class Relay {
  private:
    int pin;
  
  public:
    Relay(int pin) : pin(pin) {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);  
    }
  
    void turnOn() {
      digitalWrite(pin, HIGH); 
    }
  
    void turnOff() {
      digitalWrite(pin, LOW);  
    }
};

// Relay Objects
Relay wheelRelay(DIGI_Wheel);
Relay armRelay(DIGI_Arm);
Relay collectionRelay(DIGI_Collection);

void setup() {
  
}

void loop() {
  
 
  wheelRelay.turnOn();
  delay(1000);  
  

  wheelRelay.turnOff();
  delay(1000);  
  
  
  armRelay.turnOn();
  delay(1000);  
  
 
  armRelay.turnOff();
  delay(1000);  
  

  collectionRelay.turnOn();
  delay(1000);  
  
  
  collectionRelay.turnOff();
  delay(1000);  
}

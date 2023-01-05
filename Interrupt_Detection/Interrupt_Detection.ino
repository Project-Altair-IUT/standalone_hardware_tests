const int buttonPin = 2; // pin where the button is connected

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // set pin as input, with internal pull-up resistor enabled
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, FALLING); 
}

void loop() {
  
    // Main code will be here

}

void handleInterrupt() {
  // this function will run every time the button is pressed, due to the interrupt
  
}
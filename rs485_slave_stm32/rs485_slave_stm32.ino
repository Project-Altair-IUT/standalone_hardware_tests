#define LED       PC13
#define SLAVE_EN1  PB4
#define SLAVE_EN2  PB3


HardwareSerial Serial3(USART3);

void setup() {
  pinMode(LED , OUTPUT);                        // Declare LED pin as output
  pinMode(SLAVE_EN1 , OUTPUT);                   // Declare Enable pin as output
  pinMode(SLAVE_EN2 , OUTPUT);                   // Declare Enable pin as output

  Serial.begin(9600);   
  Serial3.begin(9600);                  // set serial communication baudrate 
  digitalWrite(SLAVE_EN1 , LOW);                 // Make Enable pin low
  digitalWrite(SLAVE_EN2 , LOW);                 // Make Enable pin low
  
                                                // Receiving mode ON 
}

void loop() {
  while(Serial3.available())                     // If serial data is available then enter into while loop
  {
    char ch = Serial3.read();
    Serial.println(ch);
    if(ch == 'A')                    // if available data is A
    {
      digitalWrite(LED , !digitalRead(LED));    // LED Blink
    }
  }
  // Serial.println("comms closed");
}
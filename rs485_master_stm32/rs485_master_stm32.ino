#define LED       PC13    // Declare LED pin
#define MASTER_EN   PB12   // connected to RS485 Enable pin

HardwareSerial Serial3(USART3);

void setup() {
  pinMode(LED , OUTPUT);            // Declare LED pin as output
  pinMode(MASTER_EN , OUTPUT);      // Declare Enable pin as output
  Serial.begin(9600);               // set serial communication baudrate 
  Serial3.begin(9600);               // set serial communication baudrate 
  digitalWrite(MASTER_EN , LOW);    // Make Enable pin low
                                    // Receiving mode ON 
}
int ch = 11111111;
void loop() {
  ch += 1;
  digitalWrite(MASTER_EN , HIGH);     // Make Enable pin high to send Data
  delay(5);                           // required minimum delay of 5ms
  Serial3.println(ch);                // Send character A serially
  Serial.println(ch);                // Send character A serially
  Serial3.flush();        
  
  
               // wait for transmission of data
  delay(2);
  digitalWrite(MASTER_EN , LOW);      // Receiving mode ON
}
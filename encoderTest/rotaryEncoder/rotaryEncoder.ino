/*this code will show the rpm detected by the bi directional rotary encoder
 * no code is given for driving motor, only for handling encoder input and 
 * it will show rpm on the serial monitor
 */
// Rotary Encoder Module connections
const int PinDT=3;    // DATA signal of encoder to pin 2 of arduino
const int PinCLK=2;    // CLOCK signal of encoder to pin 4 of arduino
//if you are confused which one is DT, which one is CLK, they are interchangeable
// but will just result in opposite direction of reading


// Store previous Pins state
int PreviousCLK;   
int PreviousDATA;

unsigned long currentMillis;
unsigned long prevMillis;

int counter=0; // Store current counter value
int prevcounter = 0;

static int oldClock = -1; // Initialize to an impossible value.
bool clockVal;
bool dataVal;
float rpm=0;

void setup() {
  // Put current pins state in variables
//  PreviousCLK=digitalRead(PinCLK);
//  PreviousDATA=digitalRead(PinDT);

  Serial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(PinDT), check_rotary, FALLING);

}
void loop() {
//  check_rotary();
currentMillis = millis();
if((currentMillis - prevMillis) == 1000)
{
  rpm = 1.50*(counter - prevcounter);
 
  Serial.println(rpm);

  prevMillis = currentMillis;
  prevcounter = counter;
}


}


// Check if Rotary Encoder was moved
void check_rotary() {
          oldClock = -1; // Initialize to an impossible value.
          clockVal = digitalRead(PinCLK);
          dataVal = digitalRead(PinDT);
          if(clockVal == oldClock) return; // was a bounce. Don't count this.
          if(clockVal ^ dataVal) {
                  // clockwise move
                  counter++;
          } else {
               // counterclockwise move
              counter--;
           }
            oldClock = clockVal; // store clock state for debounce check.
}
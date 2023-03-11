const int encoder_a = PA3;
const int encoder_b = PA4;
double encoder_pulse_countera = 0;
double tim_a = 0;
bool starta = 1;
double encoder_pulse_counterb = 0;
long direction = 1;
float prev_mils = 0;


void setup() {
    Serial.begin(9600);
    pinMode(encoder_a, INPUT_PULLUP);
    pinMode(encoder_b, INPUT_PULLUP);

    attachInterrupt(encoder_a, encoderPinChangeA, CHANGE);
    //attachInterrupt(encoder_b, encoderPinChangeB, CHANGE);
}

void loop(){
     // Not sure, encoder not specified
     double spd = (encoder_pulse_countera)/(20*tim_a*10e-6);
    Serial.println(spd* direction);
   tim_a = 0;
   prev_mils = 0;
   encoder_pulse_countera =0;// Clear variable just before counting again 
   starta = 1;
    delay(1000);
}


void encoderPinChangeA(){
    if(!starta){tim_a += (millis()- prev_mils);
    }
    starta = false;
    encoder_pulse_countera +=1;
    prev_mils = millis();
    direction = digitalRead(encoder_a) == digitalRead(encoder_b) ? -1 : 1;
}

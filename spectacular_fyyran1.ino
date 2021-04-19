int pinOne  = 2;
int pinTwo = 3;
int pinThree = 4;
#define TIEMPO 150

void leds(int RLed, int GLed, int BLed){
   shiftOut(pinOne, pinThree, LSBFIRST, BLed);
   shiftOut(pinOne, pinThree, LSBFIRST, GLed);
   shiftOut(pinOne, pinThree, LSBFIRST, RLed);
   digitalWrite(pinTwo, HIGH);
   digitalWrite(pinTwo, LOW);
}

void setup(){
   pinMode(pinOne, OUTPUT);
   pinMode(pinTwo, OUTPUT);
   pinMode(pinThree, OUTPUT);
}

void loop(){
   leds(128,0,0); delay(TIEMPO);
   leds(64,0,0);  delay(TIEMPO);
   leds(32,0,0);  delay(TIEMPO);
   leds(16,0,0);  delay(TIEMPO);
   leds(8,0,0);   delay(TIEMPO);
   leds(4,0,0);   delay(TIEMPO);
   leds(2,0,0);   delay(TIEMPO);
   leds(1,0,0);   delay(TIEMPO);
   leds(0,128,0); delay(TIEMPO);
   leds(0,64,0);  delay(TIEMPO);
   leds(0,32,0);  delay(TIEMPO);
   leds(0,16,0);  delay(TIEMPO);
   leds(0,8,0);   delay(TIEMPO);
   leds(0,4,0);   delay(TIEMPO);
   leds(0,2,0);   delay(TIEMPO);
   leds(0,1,0);   delay(TIEMPO);
   leds(0,0,128); delay(TIEMPO);
   leds(0,0,64);  delay(TIEMPO);
   leds(0,0,32);  delay(TIEMPO);
   leds(0,0,16);  delay(TIEMPO);
   leds(0,0,8);   delay(TIEMPO);
   leds(0,0,4);   delay(TIEMPO);
   leds(0,0,2);   delay(TIEMPO);
   leds(0,0,1);   delay(TIEMPO);
}
/*
//Use Hardware-Debounced Switch to Control Interrupt
//Button pins
const int BUTTON_INT =2; //Interrupt 0 (pin 2 on the Uno) 
const int RED =11; //Red LED on pin 11
const int GREEN =10; //Green LED on pin 10
const int BLUE =9; //Blue LED on pin 9

unsigned long timeC=0;
unsigned long timeP=0;
const long th=10;

//Volatile variables can change inside interrupts 
volatile int selectedLED = RED;

void setup() {
  pinMode (RED, OUTPUT); 
  pinMode (GREEN, OUTPUT); 
  pinMode (BLUE, OUTPUT);
  pinMode (BUTTON_INT,INPUT_PULLUP);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  //The pin is inverted, so we want to look at the rising edge
  attachInterrupt(digitalPinToInterrupt(2), swap, RISING); 
}

void swap() {
  timeC = millis();
  if(timeC-timeP > th) { 
    analogWrite(selectedLED, 255); //Turn off the current LED
    
    if (selectedLED == GREEN) selectedLED = RED;
    else if (selectedLED == RED) selectedLED = BLUE;
    else if (selectedLED == BLUE) selectedLED = GREEN;
  }
  timeP = timeC;
}

void loop() {
for (int i = 0; i<256; i++) {
analogWrite(selectedLED, i);
delay(10); }

for (int i = 255; i>= 0; i--) { 
  analogWrite(selectedLED, i); 
  delay(10);
  } 
}

*/

//Using Timer Interrupts with the Arduino 
#include <TimerOne.h>
const int RED =11; //Red LED on pin 11
const int GREEN =10; //Green LED on pin 10
const int BLUE =9; //Blue LED on pin 9
const int POT =6;
volatile int tmp=0;

int count=0;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Timer1.initialize(20000); //Set a timer of length 1000000 microseconds (1 second) 
  Timer1.attachInterrupt(blinky); //Runs "blinky" on each timer interrupt
}

void loop() {
  Serial.println(count);

//  Timer1.setPeriod(Num);
}
//Timer interrupt function 
void blinky()
{
  digitalWrite(tmp,HIGH);
  count++;
  if(count%8==0) tmp=RED; //Toggle LED State 
  else if(count%4==0) tmp=GREEN;
  else if(count%2==0) tmp=BLUE;

  digitalWrite(tmp, LOW);
}//Using Timer Interrupts with the Arduino

/*
const int RLED=11;
const int GLED=10;
const int BLED=9;
const int BUTTON=2;

const int LIGHT=0;
int ledMode=1;

boolean lastButton = LOW;
boolean currentButton = LOW;

const int MIN_LIGHT=200;
const int MAX_LIGHT=900;
int val = 0;


void setup() {
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(BUTTON, INPUT);
  
  Serial.begin(9600);

}

boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);
  if (last != current)  {
    delay(5); //wait 5ms
    current = digitalRead(BUTTON);
  }
  return current;
}

void setMode(int mode, int val)
{

  if (mode == 1) {
    analogWrite(RLED, val); digitalWrite(GLED, HIGH); digitalWrite(BLED, HIGH);
  }

  else if (mode == 2)
  {
    digitalWrite(RLED, HIGH); analogWrite(GLED, val); digitalWrite(BLED, HIGH);
  }

  else if (mode == 3) {
    digitalWrite(RLED, HIGH); digitalWrite(GLED, HIGH); analogWrite(BLED, val);
  }
}

void loop() {
  val = analogRead(LIGHT);
  Serial.println(val);
  val = map(val, 20, 150, 255, 0);
  val = constrain(val, 0, 255);ㅗㅗ
  
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH){
      ledMode++;
      }
  lastButton = currentButton;

  if (ledMode == 4) ledMode = 1;
  setMode(ledMode,val);
}
*/

#include "pitches.h" //Header file with pitch definitions 

const int BUTTON[5]={3,4,5,6,7};
const int SPEAKER=9; //Speaker Pin
//Note Array 
int notes[] = {
NOTE_A4, NOTE_E3, NOTE_A4, 0,
NOTE_A4, NOTE_E3, NOTE_A4, 0,
NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E3, NOTE_A4, 0
};
//The Duration of each note (in ms) 
int times[] = {
250, 250, 250, 250,
250, 250, 250, 250,
125, 125, 125, 125, 125, 125, 125, 125, 250, 250, 250, 250
};

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON[0],INPUT_PULLUP);
  pinMode(BUTTON[1],INPUT_PULLUP);
  pinMode(BUTTON[2],INPUT_PULLUP);
  pinMode(BUTTON[3],INPUT_PULLUP);
  pinMode(BUTTON[4],INPUT_PULLUP);

}
void loop() {
while(!digitalRead(BUTTON[4])) tone(SPEAKER, NOTE_C4);
while(!digitalRead(BUTTON[3])) tone(SPEAKER, NOTE_D4);
while(!digitalRead(BUTTON[2])) tone(SPEAKER, NOTE_E4);
while(!digitalRead(BUTTON[1])) tone(SPEAKER, NOTE_G4);
while(!digitalRead(BUTTON[0])) tone(SPEAKER, NOTE_A4);
//Stop playing if all buttons have been released
Serial.println(analogRead(9));
Serial.println(1.23456,4);

noTone(SPEAKER);
}

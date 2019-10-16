const int RLED=9;
const int GLED=10;
const int BLED=11;
const int BUTTON=2;
int j=9;

boolean lastButton=LOW;
boolean currentButton=LOW;
int ledOn=0;


void setup() {
  pinMode(RLED,OUTPUT);
  pinMode(GLED,OUTPUT);
  pinMode(BLED,OUTPUT);
  pinMode(BUTTON,INPUT);
}

boolean debounce(boolean last){
  boolean current = digitalRead(BUTTON); 
  if (last != current){
    delay(5);
    current = digitalRead(BUTTON);
    }
  return current;
}

void loop() {
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) ledOn += 1;
  lastButton = currentButton; 
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, LOW);

  /*
  if(ledOn==0) digitalWrite(RLED, HIGH);
  if(ledOn==1) digitalWrite(GLED, HIGH);
  if(ledOn==2) digitalWrite(BLED, HIGH);
  if(ledOn==3) digitalWrite(BLED, LOW);
  if(ledOn==4) digitalWrite(GLED, LOW);
  if(ledOn==5) digitalWrite(RLED, LOW);
  if(ledOn==6) ledOn=0;*/
}

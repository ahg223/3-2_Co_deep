
const int RLED=9;
const int GLED=10;
const int BLED=11;
const int POT=0;

int val=0;

void setup() {
  pinMode(RLED,OUTPUT);
  pinMode(GLED,OUTPUT);
  pinMode(BLED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val=analogRead(POT);
  Serial.println(val);
  if (val>700){
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);  
  }  
  else if (val>400){
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);  
  }  
  else {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);  
  }
}

const int POT=0;
int val =0;

const int BLED=9;
const int GLED=10;
const int RLED=11;


void setup() {
  Serial.begin(9600);
  pinMode(BLED,OUTPUT);
  pinMode(GLED,OUTPUT);
  pinMode(RLED,OUTPUT);
  
}

void loop() {
  int temp=0;
  val=analogRead(POT);
  temp=val*254/1023;
  val=temp;
  digitalWrite(RLED,LOW);
  Serial.println(val);
  delay(500);

}

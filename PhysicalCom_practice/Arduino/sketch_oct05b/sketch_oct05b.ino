const int BLED=9; 
const int GLED=10; 
const int RLED=11; 
const int TEMP=0;
const int POT=1;

const int LOWER_BOUND=160;
const int UPPER_BOUND=162;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode (BLED, OUTPUT); //Set Blue LED as Output 
  pinMode (GLED, OUTPUT); //Set Green LED as Output 
  pinMode (RLED, OUTPUT); //Set Red LED as Output
}

void loop() {
  int temp1, temp2=0;

  delay(500);
  val=analogRead(TEMP);
  temp1=analogRead(POT);  
  temp2=(float)temp1*255/1024;
  Serial.println(temp1);
  Serial.println(temp2);
  Serial.println(val);
  Serial.println("\n");
  

  
  if(val <LOWER_BOUND) {
    analogWrite(RLED, HIGH); 
    analogWrite(GLED, HIGH); 
    analogWrite(BLED, temp2);
  }
  else if(val >UPPER_BOUND) {
    analogWrite(RLED, temp2); 
    analogWrite(GLED, HIGH); 
    analogWrite(BLED, HIGH);
  } 
  else {
    analogWrite(RLED, HIGH); 
    analogWrite(GLED, temp2); 
    analogWrite(BLED, HIGH);
  } 
  
}

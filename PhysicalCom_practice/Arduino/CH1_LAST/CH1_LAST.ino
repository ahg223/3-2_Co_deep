const int RLED=9;
const int GLED=10;
const int BLED=11;
const int BUTTON[3]={2,3,4};
int j=9;

boolean lastButton[3]={LOW,};
boolean currentButton[3]={LOW,};
int state[3]={0,};


void setup() {
  Serial.begin(9600);
  pinMode(RLED,OUTPUT);
  pinMode(GLED,OUTPUT);
  pinMode(BLED,OUTPUT);
  pinMode(BUTTON[0],INPUT);
  pinMode(BUTTON[1],INPUT);
  pinMode(BUTTON[2],INPUT);
}

boolean debounce(boolean last,int i){
  boolean current = digitalRead(BUTTON[i]); 
  if (last != current){
    delay(5);
    current = digitalRead(BUTTON[i]);
    }
  return current;
}

void loop() {
  for(int i=0; 3>i;i++){
    currentButton[i] = debounce(lastButton[i],i);
    if (lastButton[i] == LOW && currentButton[i] == HIGH) state[i]=1;
    lastButton[i] = currentButton[i]; 
  }

  if(state[0]==1){
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);    
    state[0]=0;
  }
  
  else if(state[1]==1){
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);    
    state[1]=0;
  }
  
  else if(state[2]==1){
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);    
    state[2]=0;
  }
  Serial.println(state[0]);
  Serial.println(state[1]);
  Serial.println(state[2]);
  Serial.print("#####\n");
  delay(20);
}

const int BLED=9;
const int GLED=10;
const int RLED=11;
const int BBUTTON=2;
const int GBUTTON=3;
const int RBUTTON=4;
 
boolean lastButton[3] = {HIGH;
boolean currentButton[3] = HIGH;
int ledMode = 0;

void setup()
{
  pinMode(BLED,OUTPUT);
  pinMode(GLED,OUTPUT);
  pinMode(RLED,OUTPUT);
  pinMode(RBUTTON,INPUT);
  pinMode(GBUTTON,INPUT);
  pinMode(BBUTTON,INPUT);
}

void debounce()
{
  boolean BCur1=digitalRead(BBUTTON);
  boolean GCur1=digitalRead(GBUTTON);
  boolean RCur1=digitalRead(RBUTTON);

  delay(5);
  boolean BCur2=digitalRead(BBUTTON);
  boolean GCur2=digitalRead(GBUTTON);
  boolean RCur2=digitalRead(RBUTTON);

  if(lastButton[0] != BCur1) currentButton[0]=BCur2;
  if(lastButton[1] != GCur1) currentButton[1]=GCur2;
  if(lastButton[2] != RCur1) currentButton[2]=RCur2;
  
}

void setMode(int mode)
{
  if(mode==0)
  {
    digitalWrite(RLED,HIGH);
    digitalWrite(GLED,HIGH);
    digitalWrite(BLED,HIGH);
  }

  else if(mode==1)
  {
    digitalWrite(RLED,LOW);
    digitalWrite(GLED,HIGH);
    digitalWrite(BLED,HIGH);
  }
  else if(mode==2)
  {
    digitalWrite(RLED,HIGH);
    digitalWrite(GLED,LOW);
    digitalWrite(BLED,HIGH);
  }
  else if(mode==3)
  {
    digitalWrite(RLED,HIGH);
    digitalWrite(GLED,HIGH);
    digitalWrite(BLED,LOW);
  }
  else
  {
    mode=0;
  }
}

void loop()
{

  debounce();
  if(lastButton[0]==HIGH && currentButton[0]==LOW){
    ledMode=1;
  }
  if(lastButton[1]==HIGH && currentButton[1]==LOW){
    ledMode=2;
  }
  if(lastButton[2]==HIGH && currentButton[2]==LOW){
    ledMode=3;
  }
  else{
    ledMode=0;
  }
  for(int i=0;i<3;i++){
    lastButton[i]=currentButton[i];
  }
  setMode(ledMode);
}

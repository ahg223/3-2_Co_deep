//Define LED pins 
const int RED1 =11; 
const int GREEN1 =10; 
const int BLUE1 =9;

const int RED2 =3; 
const int GREEN2 =5; 
const int BLUE2 =6;

const int POT=0;

//Variables for RGB levels 
int Num=-1;
int mode=-1;
char Char=0;
int rval1 = 255;
int gval1 = 255;
int bval1 = 255;
int rval2 = 255;
int gval2 = 255;
int bval2 = 255;

void setup() {
  Serial.begin(9600); //9600 baud
  
  //Set pins as outputs 
  pinMode(RED1, OUTPUT); 
  pinMode(GREEN1, OUTPUT); 
  pinMode(BLUE1, OUTPUT);
  pinMode(RED2, OUTPUT); 
  pinMode(GREEN2, OUTPUT); 
  pinMode(BLUE2, OUTPUT);

  analogWrite(RED1, 255); 
  analogWrite(GREEN1, 255); 
  analogWrite(BLUE1, 255);  
  analogWrite(RED2, 255); 
  analogWrite(GREEN2, 255); 
  analogWrite(BLUE2, 255);
      
}

void loop() {
//  Serial.println(analogRead(POT));
  
  int output=map(analogRead(POT),0,913,0,255);
  if (output>245) output=255;
//  output+=28;
  while(Serial.available()>0){
    Serial.print("Input Command: ");
    Num= Serial.parseInt();
    Serial.print(Num);
    Serial.print("\n");
    
    while (Num > 0){
      Char='0';
      mode=Serial.parseInt();
      while(Char<'A' || Char>'Z') Char=Serial.read();
      
      Serial.print(Char);
      Serial.print("\n");
      
      if (mode==1 && Char == 'R') rval1 = output;       
      if (mode==1 && Char == 'G') gval1 = output;       
      if (mode==1 && Char == 'B') bval1 = output;  
      if (mode==2 && Char == 'R') rval2 = output;       
      if (mode==2 && Char == 'G') gval2 = output;       
      if (mode==2 && Char == 'B') bval2 = output;  
      Num--;     
    Serial.print(rval1);
    Serial.print(", ");
    Serial.print(gval1);
    Serial.print(", ");
    Serial.print(bval1);
    Serial.print("\n");   
    Serial.print(rval2);
    Serial.print(", ");
    Serial.print(gval2);
    Serial.print(", ");
    Serial.print(bval2);
    Serial.print("\n");
    Serial.print("\n");
    } 

    Serial.print(output);
    analogWrite(RED1, bval1); 
    analogWrite(GREEN1, gval1); 
    analogWrite(BLUE1, rval1);
    analogWrite(RED2, rval2); 
    analogWrite(GREEN2, gval2); 
    analogWrite(BLUE2, bval2);
      
  }
  
}

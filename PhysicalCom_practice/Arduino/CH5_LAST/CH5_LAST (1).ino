

#include <LiquidCrystal.h>
byte p20[8]={ B00000, B00000, B00000, B10000, B11000, B11100, B11110, B11111, };
byte p40[8]={ B00000, B00000, B00000, B00001, B00011, B00111, B01111, B11111, };
byte p60[8]={ B11111, B11110, B11100, B11000, B10000, B00000, B00000, B00000, }; 
byte p80[8]={ B11111, B01111, B00111, B00011, B00001, B00000, B00000, B00000, }; 
byte p21[8]={ B00000, B00000, B10000, B11000, B11100, B11110, B11111, B11111,  };
byte p41[8]={ B00000, B00000, B00001, B00011, B00111, B01111, B11111, B01111, };
byte p61[8]={ B11111, B11110, B11100, B11000, B10000, B00000, B00000, B00000, }; 
byte p81[8]={ B11111, B01111, B00111, B00011, B00001, B00000, B00000, B00000, }; 
byte p22[8]={ B00000, B00000, B00000, B10000, B11000, B11100, B11110, B11111, };
byte p42[8]={ B00000, B00000, B00000, B00001, B00011, B00111, B01111, B11111, };
byte p62[8]={ B11111, B11110, B11100, B11000, B10000, B00000, B00000, B00000, }; 
byte p82[8]={ B11111, B01111, B00111, B00011, B00001, B00000, B00000, B00000, }; 
byte p23[8]={ B00000, B00000, B00000, B10000, B11000, B11100, B11110, B11111, };
byte p43[8]={ B00000, B00000, B00000, B00001, B00011, B00111, B01111, B11111, };
byte p63[8]={ B11111, B11110, B11100, B11000, B10000, B00000, B00000, B00000, }; 
byte p83[8]={ B11111, B01111, B00111, B00011, B00001, B00000, B00000, B00000, }; 


boolean lastButton[3]={LOW,};
boolean currentButton[3]={LOW,};
int state[3]={7,0,0};

const int BUTTON[3]={9,10,11};

const int ROW = 16;
const int COL = 2;
int time = 0;
int i = 0; // 문자열을 한칸씩 옆으로 이동시키는 용도
LiquidCrystal lcd(2,3,4,5,6,7);
void setup() {
  pinMode(BUTTON[0],INPUT_PULLUP);
  pinMode(BUTTON[1],INPUT_PULLUP);
  pinMode(BUTTON[2],INPUT_PULLUP);
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.createChar(1, p20); //Make progress characters 
  lcd.createChar(0, p40);  
  lcd.createChar(3, p60); //Make progress characters 
  lcd.createChar(2, p80);
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
    if (lastButton[i] == LOW && currentButton[i] == HIGH) state[i]+=1;
    lastButton[i] = currentButton[i]; 
  }
  
  int j=0;
  lcd.clear();
  int val=state[0]-state[1];
  int val2=val+1;
  if (val>15) val=val%16;
  if (-1>val) val=val+15;
  if (val2>15) val2=val2%16;
  if (-1>val2) val2=val2+15;
  
    lcd.setCursor(val,0);
    lcd.write(j);
    j=1;
    lcd.setCursor(val2,0);
    lcd.write(j);
    j=2;
    lcd.setCursor(val,1);
    lcd.write(j);
    j=3;
    lcd.setCursor(val2,1);
    lcd.write(j);
  

}

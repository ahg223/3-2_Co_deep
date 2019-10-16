
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
byte p20[8]={ B10000, B10000, B10000, B10000, B10000, B10000, B10000, B10000, };

byte p40[8]={ B11000, B11000, B11000, B11000, B11000, B11000, B11000, B11000, }; 
byte p60[8]={ B11100, B11100, B11100, B11100, B11100, B11100, B11100, B11100, };

byte p80[8]={ B11110, B11110, B11110, B11110, B11110, B11110, B11110, B11110, }; 
byte p100[8]={ B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111, };

void setup() { 
lcd.begin(16, 2); //Set up the LCDs number of columns and rows 

lcd.createChar(0, p20); //Make progress characters 
lcd.createChar(1, p40); 
lcd.createChar(2, p60); 
lcd.createChar(3, p80); 
lcd.createChar(4, p100); } 
void loop() { D 
lcd.setCursor(0,1); //Move cursor to second line 
lcd.print(" "); //Clear the line each time it reaches the end with 16 " " (spaces) 
for (int i = 0; i<16; i++) { //Iterate through each character on the second line 
  for (int j=0; j<5; j++) { //Iterate through each progress value for each character 
    lcd.setCursor(i, 1); //Move the cursor to this location 
    lcd.write(j); //Update progress bar 
    delay(100); //Wait 
  } 
}
lcd.clear();
}

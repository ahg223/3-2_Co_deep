#include <LiquidCrystal.h> //Include the library code:
#include <string.h>

int time = 0; //Start the time at 0

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Initialize the library with the numbers of the interface pins
char SKKU[5]="SKKU";

void setup() {
  lcd.begin(16, 2); //Set up the LCD's number of columns and rows:
}

void loop() {

    lcd.clear();

    lcd.setCursor(time%16,(time/16)%2);
    lcd.print(SKKU[0]);
    lcd.setCursor((time+1)%16,((time+1)/16)%2);
    lcd.print(SKKU[1]);
    lcd.setCursor((time+2)%16,((time+2)/16)%2);
    lcd.print(SKKU[2]);
    lcd.setCursor((time+3)%16,((time+3)/16)%2);
    lcd.print(SKKU[3]);
    delay(1000); //Wait 1 second
    
    time++; //Increment the time 
}

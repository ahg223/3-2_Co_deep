//Processing Sketch to Read Value and Change Color on the Screen
//Import and initialize serial port library
import processing.serial.*;
Serial port;
float brightness = 0; //For holding value from pot
PImage img;
void setup() {
  size(640,256); //Window size
  img=loadImage("hsv.jpg");
  port = new Serial(this, "/dev/cu.usbmodem142101", 9600); //Set up serial 
  port.bufferUntil('\n'); //Set up port to read until newline
}
void draw() {
  background(0,0,brightness); //Updates the window 
  image(img,0,0);
}
void serialEvent (Serial port) {
  brightness = float(port.readStringUntil('\n')); //Gets val 
}
void mousePressed() {
  color c = get(mouseX, mouseY); //Get the RGB color where mouse was pressed 
  String colors = int(red(c))+","+int(green(c))+","+int(blue(c))+"\n"; //extract values 
  print(colors); //Print colors for debugging
  port.write(colors); //Send values to Arduino
}

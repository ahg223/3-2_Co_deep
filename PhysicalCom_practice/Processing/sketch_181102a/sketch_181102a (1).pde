import processing.serial.*; //Import serial library 
PImage img; //Image object
Serial port; //Serial port object

void setup(){
  size(640,256); //Size of HSV image
  img = loadImage("hsv.jpg"); //Load in background image 
  port = new Serial(this, "/dev/cu.usbmodem143201", 9600); //Open serial port
}

void draw() {
  background(0); //Black background 
  image(img,0,0); //Overlay image
}

void mousePressed() {
  color c = get(mouseX, mouseY); //Get the RGB color where mouse was pressed 
  String colors = int(red(255-c))+","+int(green(255-c))+","+int(blue(255-c))+"\n"; //extract values 
  print(colors); //Print colors for debugging
  port.write(colors); //Send values to Arduino
}

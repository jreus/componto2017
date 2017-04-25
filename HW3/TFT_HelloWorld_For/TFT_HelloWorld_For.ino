/*
 * Hello World for the Arduino TFT Screen 
 * This program prints "Hello World" repeatedly, top to bottom, left to right, across the screen.
 * 
 * Algorithm:
 * 
 * 1. do repeatedly
 *    1. choose a random text color
 *    2. Start with x and y equal to 0
 *    3. while y is within the bounds of the screen
 *        1. if y is an even step, write "Hello" to the screen at (0,y)
 *        2. if y is an odd step, write "World" to the screen at (screenWidth/2, y)
 *        3. increase y by some number of pixels
 * 
 * See this link for the TFT library reference page:
 * https://www.arduino.cc/en/Reference/TFTLibrary
 *  
 *  This example code is in the public domain. 
 *  Created 15 March 2017 by Jonathan Reus
 */

#include <arduino.h>
#include <TFT.h>      // Arduino LCD library
#include <SPI.h>      // SPI library

// TFT pin definitions for the Uno
#define LCD_CS   10
#define DC   9
#define RESET  8

int main() {
  init();

  TFT myscreen = TFT(LCD_CS, DC, RESET);  // create the variable representing the screen, this is boilerplate code
  
  // initialize the screen
  myscreen.begin();
  myscreen.background(0, 0, 0);   // make the background black
  myscreen.setTextSize(2);
  
  int ypos=0;
  while(true) {

    myscreen.stroke(random(0,255), random(0,255), random(0,255));

    for(ypos = 0; ypos < myscreen.height(); ypos += 10) {
      if(ypos / 10 % 2 == 0) {
        myscreen.text("Hello", 0, ypos);
      } else {
        myscreen.text("World", myscreen.width() / 2, ypos);        
      }      
    }

    /*
    ypos = 0;
    while(ypos < myscreen.height()) {
      if(ypos / 10 % 2 == 0) {
        myscreen.text("Hello", 0, ypos);
      } else {
        myscreen.text("World", myscreen.width() / 2, ypos);        
      }
      ypos += 10;
    }
    */
  }
  
  return 0;
}

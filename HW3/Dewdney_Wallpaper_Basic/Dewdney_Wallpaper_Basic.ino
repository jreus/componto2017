/*
 * A C implementation of the wallpaper algorithm from 
 * chapter 1 of The New Turing Omnibus, by Alexander Dewdney
 *  
 *  Algorithm:
 *  inputs: cornX, cornY values for the bottom left corner of the square
 *             a side length for the square
 *  outputs: draws a wallpaper patterned square to the screen
 *  1. for every combination of values, i & j from 1 to 100 
 *     1. calculate x = cornX + i * (side / 100) 
 *     2. calculate y = cornY + j * (side / 100)
 *     3. calculate c = x^2 + y^2
 *     4. if c is even, draw a pixel at x, y
 *  
 *  
 *  This example code is in the public domain. 
 *  Created 15 March 2017 by Jonathan Reus
 *  
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

  TFT myscreen = TFT(LCD_CS, DC, RESET);
  
  myscreen.begin();
  myscreen.background(0, 0, 0);

  Serial.begin(9600);
  Serial.setTimeout(10000);

  float x, y, side_fraction;
  int cornX, cornY, side, c;
  
  Serial.println("\n Hello");
  Serial.print("Please enter a value for corner X: "); 
  cornX = Serial.parseInt(); Serial.println(cornX);
  Serial.print("and a value for corner Y: ");
  cornY = Serial.parseInt(); Serial.println(cornY);
  delay(1000);
  Serial.print("Now enter a length for the side: ");
  side = Serial.parseInt(); Serial.println(side);
  delay(1000);
  
  side_fraction = side / 100.0; // by default, C tries to cast to the more forgiving type 

  // do the drawing algorithm
  for(int i=1; i <= 100; i++) {
    for(int j=1; j <= 100; j++) {
       x = cornX + i * side_fraction; // order of operations promises we get a float result here, why?
       y = cornY + j * side_fraction;
       c = (int)(x*x + y*y);
       
       if(c % 2 == 0) {
          myscreen.stroke(255, 255, 255);   // white dot
       } else {
          myscreen.stroke(0, 0, 0);   // black dot
       }
       myscreen.point(x, y);       // draw the point
    }
  }

  return 0;
}

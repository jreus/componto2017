/*
 * A Visual Implementation of the Insertion Sort algorithm
 * 
 * INSERTION SORT ALGORITHM
 * 1. for each element from position 1 to the end of the array
 *    1. pick out the value at this position call it key
 *    2. for each element, e to the left of key, until the beginning of the array
 *       1. if e is bigger than key, shift it to the right and examine the next slot to the left
 *       2. if e is less than key, keep e where it is, and insert key where you are 
 *    
 * PSEUDOCODE ALGORITHM
 * 1. for each i, from position 1 to the end of the array
 *    1. let key = the element at i, e(i)
 *    2. for each j, from position i-1 to 0
 *       1. if e(j) > key, put the value e(j) in position j+1
 *       2. if key > e(j), put key in position j+1 and exit loop 1.2. 
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

  TFT myscreen = TFT(LCD_CS, DC, RESET);  // create the object representing the screen (like declaring a variable)
  
  // initialize the screen
  myscreen.begin();
  myscreen.background(0, 0, 0);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  
  byte r[160], g[160], b[160];
  byte linesize;

  // initialize the Red/Green/Blue values to random numbers from 0 to 255
  for(byte i = 0; i < 160; i++) {
    r[i] = random(0, 255);
    g[i] = random(0, 255);
    b[i] = random(0, 255);
  }

  // Draw the unsorted array
  for(int xpos = 0; xpos < 160; xpos++) {
    myscreen.stroke(r[xpos], g[xpos], b[xpos]);
    linesize = map(r[xpos], 0, 255, 0, 127);
    myscreen.line(xpos, 128 - linesize, xpos, 128);
  }

  delay(2000);

  // Do the sorting algorithm
  int key_r, key_g, key_b;
  int i, j;
  for(i = 1; i < 160; i++) {
    key_r = r[i];
    key_g = g[i];
    key_b = b[i];
     
    // shift elements right until the insertion point is found for key
    j = i - 1;
    while(j >= 0 && key_r < r[j]) {
          // shift right
          r[j+1] = r[j];
          g[j+1] = g[j];
          b[j+1] = b[j];
          j--; // check the next element to the left
        }
        
        // insert key where j left off
        r[j+1] = key_r;
        g[j+1] = key_g;
        b[j+1] = key_b;
    }

  // Clear the screen and draw the array again
  myscreen.background(0, 0, 0);
  for(int xpos = 0; xpos < 160; xpos++) {
    myscreen.stroke(r[xpos], g[xpos], b[xpos]);
    linesize = map(r[xpos], 0, 255, 0, 127);
    myscreen.line(xpos, 128 - linesize, xpos, 128);
  }

  return 0;
}
